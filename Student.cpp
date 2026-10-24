#include "Student.h"
#include <iostream>
#include <algorithm>

Student::Student() : User(), level(1) {}

Student::Student(int id, const std::string& name, const std::string& password, int level)
    : User(id, name, password), level(level) {}

int Student::getLevel() const { return level; }
void Student::setLevel(int newLevel) { level = newLevel; }

void Student::enroll(int courseId) {
    // do not enroll twice in the same course
    if (std::find(courseIds.begin(), courseIds.end(), courseId) == courseIds.end()) {
        courseIds.push_back(courseId);
    }
}

const std::vector<int>& Student::getCourseIds() const { return courseIds; }

void Student::display() const {
    std::cout << "[Student] ID: " << id << " | Name: " << name
              << " | Level: " << level
              << " | Courses: " << courseIds.size() << std::endl;
}
