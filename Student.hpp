#pragma once
#include <string>
#include <vector>

class Student {
    std::string name;
    int id;
    std::vector<int> scores;
public:
    void addScore(int score);
    void setId(const int& new_id);
    void setName(const std::string& new_name);
    //returns average of all scores, or 0.0 if none
    double average() const;
    const std::string& getName() const;
    int getId() const;
    Student();
    Student(const std::string& name, const int& id);
    std::vector<int>* getScores();



};