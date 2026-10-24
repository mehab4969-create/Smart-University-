#pragma once
#include "Student.h"
#include "Doctor.h"
#include "Course.h"
#include <vector>

// Core functions of the system: Add / Delete / Search / Edit
class SystemManager {
private:
    std::vector<Student> students;
    std::vector<Doctor> doctors;
    std::vector<Course> courses;

public:
    // ---- Students ----
    bool addStudent(const Student& s);          // false if the ID already exists
    bool deleteStudent(int id);
    Student* findStudent(int id);
    bool editStudent(int id, const std::string& newName, int newLevel);
    void showStudents() const;

    // ---- Doctors ----
    bool addDoctor(const Doctor& d);
    bool deleteDoctor(int id);
    Doctor* findDoctor(int id);
    bool editDoctor(int id, const std::string& newName, const std::string& newDepartment);
    void showDoctors() const;

    // ---- Courses ----
    bool addCourse(const Course& c);
    bool deleteCourse(int id);
    Course* findCourse(int id);
    bool editCourse(int id, const std::string& newName, const std::string& newCode);
    void showCourses() const;

    // Sample data to test the system quickly
    void loadSampleData();
};
