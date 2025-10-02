#include "StudentDatabase.hpp"
#include <fstream>
#include <iostream>

StudentDatabase::StudentDatabase() {
    students = new std::array<Student*, 100>;
}

StudentDatabase::StudentDatabase(const StudentDatabase& other) {
    students = new std::array<Student*, 100>;
    for (size_t i = 0; i < other.students->size(); i++) {
        Student* s = new Student(*other.students->at(i));
        students->at(i) = s;
    }
}

StudentDatabase::StudentDatabase(StudentDatabase&& other) noexcept {
    students = other.students;
    other.students = nullptr;
}

StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other) {
    if (this == &other) {
        return *this;
    }
    std::array<Student*, 100>* temp = new std::array<Student*, 100>;
    for (size_t i = 0; i < students->size(); i++) {
        delete students->at(i);

    }
    delete[] students;
    for (size_t i = 0; i < other.students->size(); i++) {
        Student* s = new Student(*other.students->at(i));
        temp->at(i) = s;
    }
    students = temp;
    return *this;
}

StudentDatabase& StudentDatabase::operator=(StudentDatabase&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < students->size(); i++) {
        delete students->at(i);

    }
    delete[] students;

    students = other.students;

    other.students = nullptr;

    return *this;
}

StudentDatabase::~StudentDatabase() {
    for (size_t i = 0; i < students->size(); i++) {
        delete students->at(i);
    }
    delete[] students;
}

void StudentDatabase::addStudent(const Student& s) {
    for (size_t i = 0; i < students->size(); i++) {
        if (students->at(i) == nullptr) {
            students->at(i) = new Student(s);
            return;
        }
    }
}

Student* StudentDatabase::findById(int id) {
    for (size_t i = 0; i < students->size(); i++) {
        if (students->at(i)->getId()==id) {
            return students->at(i);
        }
    }
    return nullptr;
}

void StudentDatabase::saveToFile(const std::string& filename) {

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
    }
    for (size_t i = 0; i < students->size(); i++) {
        if (students->at(i)==nullptr) {
            break;
        }
        file << students->at(i)->getId() << " ";
        file << students->at(i)->getName() << " ";
        for (size_t k = 0; k < students->at(i)->getScores().size(); k++) {
            file << students->at(i)->getScores().at(k) << " ";
        }
    }
    file.close();

}

void StudentDatabase::loadFromFile(const std::string &filename) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
    }

    int firstID = 0;
    file >> firstID;
    std::vector<int> ids;
    ids.push_back(firstID);
    while (!file.eof()) {
        Student* s = new Student();
        s->setId(ids.back());

        std::string name = "";
        file >> name;
        s->setName(name);

        std::vector<int> scores;
        size_t count = 0;
        while (true) {
            try {
                int x = 0;
                file >> x;
                scores.push_back(x);

            }
            catch (std::invalid_argument& e) {
                ids.push_back(scores.back());
                scores.pop_back();
            }
            count++;
        }
        for (size_t i = 0; i < scores.size(); i++) {
            s->addScore(scores[i]);
        }
        addStudent(*s);
    }
    file.close();

}



int main() {
    std::cout << "this is working" << std::endl;
    const std::string& fileName = "page.txt";
    StudentDatabase* db = new StudentDatabase();
    Student* s = new Student();
    s->setId(1);
    s->setName("John");
    s->addScore(80);
    s->addScore(100);
    s->addScore(40);
    db->addStudent(*s);

    Student* jack = new Student();
    jack->setId(7);
    jack->setName("Jack");
    jack->addScore(20);
    jack->addScore(400);
    jack->addScore(90);
    db->addStudent(*jack);

    db->saveToFile(fileName);
    StudentDatabase* highIQ = new StudentDatabase();
    highIQ->loadFromFile(fileName);
}
