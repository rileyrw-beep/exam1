#pragma once
#include "Student.hpp"
#include <string>
#include <iostream>
#include <array>

class StudentDatabase {
    std::array<Student*, 100>* students;
public:
    StudentDatabase();
    StudentDatabase(const StudentDatabase& other);
    StudentDatabase(StudentDatabase&& other) noexcept;
    StudentDatabase& operator=(const StudentDatabase& other);
    StudentDatabase& operator=(StudentDatabase&& other) noexcept;
    ~StudentDatabase();

    // deep copies the student into the database.
    void addStudent(const Student& s);
    //→ returns pointer to student or nullptr.
    Student* findById(int id);
    //→ saves students to a file.
    void saveToFile(const std::string& filename);
    //→ loads students back.
    void loadFromFile(const std::string& filename);


};
