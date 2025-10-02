#include "Student.hpp"
#include <vector>
#include <string>

Student::Student() {
    id = 0;
}

Student::Student(std::string name, int id) {
    this->name = name;
    this->id = id;

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
    average /= scores.size();
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

void Student::setId(int& id) {
    this->id = id;
}
void Student::setName(std::string& name) {
    this->name = name;
}

