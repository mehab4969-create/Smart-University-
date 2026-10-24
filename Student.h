#pragma once
#include "User.h"
#include <vector>

// Student inherits from User
class Student : public User {
private:
    int level;                    // academic year (1, 2, 3, 4)
    std::vector<int> courseIds;   // courses the student is enrolled in

public:
    Student();
    Student(int id, const std::string& name, const std::string& password, int level);

    int getLevel() const;
    void setLevel(int newLevel);

    void enroll(int courseId);
    const std::vector<int>& getCourseIds() const;

    void display() const override;
};
