#include "StudentDatabase.hpp"
#include <fstream>

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
    for (size_t i = 0; i < other.students->size(); i++) {
        other.students->at(i) = nullptr;
    }
    other.students = nullptr;
}

StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other) {
    if (this == &other) {
        return *this;
    }
    std::array<Student*, 100>* temp = new std::array<Student*, 100>;
    for (int i = 0; i < students->size(); i++) {
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
    for (size_t i = 0; i < other.students->size(); i++) {
        other.students->at(i) = nullptr;
    }
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
    for (size_t i = 0; i < students->size(); i++) {
        file << students->at(i)->getId() << " ";
        file << students->at(i)->getName() << " ";
        for (size_t k = 0; k < students->size(); k++) {
            file << students->at(i)->getScores()->at(k) << " ";
        }
    }
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
                file >> scores.at(count);
            }
            catch (std::invalid_argument& e) {
                ids.push_back(scores.back());
                scores.pop_back();
            }
            count++;
        }
        addStudent(*s);
    }
}
