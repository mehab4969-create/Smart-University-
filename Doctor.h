#pragma once
#include "User.h"
#include <vector>

// Doctor inherits from User
class Doctor : public User {
private:
    std::string department;
    std::vector<int> courseIds;   // courses the doctor teaches

public:
    Doctor();
    Doctor(int id, const std::string& name, const std::string& password,
           const std::string& department);

    std::string getDepartment() const;
    void setDepartment(const std::string& newDepartment);

    void assignCourse(int courseId);
    const std::vector<int>& getCourseIds() const;

    void display() const override;
};
