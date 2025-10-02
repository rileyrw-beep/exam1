#include "Student.hpp"
#include <vector>
#include <string>

Student::Student() {
    id = 0;
}

Student::Student(const std::string& n, const int& i) {
    this->name = n;
    this->id = i;

}


void Student::addScore(int score) {
    this->scores.push_back(score);
}
//returns average of all scores, or 0.0 if none
double Student::average() const {
    double average = 0;
    for (int score : scores) {
        average += score;
    }
    size_t size = scores.size();
    double newSize = static_cast<double>(size);
    average /= newSize;
    return average;
}
const std::string& Student::getName() const {
    return this->name;
}

int Student::getId() const {
    return id;
}

std::vector<int>* Student::getScores() {
    return &scores;
}

void Student::setId(const int& new_id) {
    this->id = new_id;
}
void Student::setName(const std::string& new_name) {
    this->name = new_name;
}

