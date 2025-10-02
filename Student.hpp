#include <string>
#include <vector>

class Student {
    std::string name;
    int id;
    std::vector<int> scores;
public:
    void addScore(int score);
    void setId(int& id);
    void setName(std::string& name);
    //returns average of all scores, or 0.0 if none
    double average() const;
    const std::string& getName() const;
    int getId() const;
    Student();
    Student(std::string name, int id);
    std::vector<int>* getScores();



};