#include "Doctor.h"
#include <iostream>
#include <algorithm>

Doctor::Doctor() : User(), department("") {}

Doctor::Doctor(int id, const std::string& name, const std::string& password,
               const std::string& department)
    : User(id, name, password), department(department) {}

std::string Doctor::getDepartment() const { return department; }
void Doctor::setDepartment(const std::string& newDepartment) { department = newDepartment; }

void Doctor::assignCourse(int courseId) {
    if (std::find(courseIds.begin(), courseIds.end(), courseId) == courseIds.end()) {
        courseIds.push_back(courseId);
    }
}

const std::vector<int>& Doctor::getCourseIds() const { return courseIds; }

void Doctor::display() const {
    std::cout << "[Doctor] ID: " << id << " | Name: " << name
              << " | Department: " << department
              << " | Courses: " << courseIds.size() << std::endl;
}
