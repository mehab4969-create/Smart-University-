#include "SystemManager.h"
#include <iostream>

// ======================= Students =======================
bool SystemManager::addStudent(const Student& s) {
    if (findStudent(s.getId()) != nullptr) return false;
    students.push_back(s);
    return true;
}

bool SystemManager::deleteStudent(int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            return true;
        }
    }
    return false;
}

Student* SystemManager::findStudent(int id) {
    for (auto& s : students) {
        if (s.getId() == id) return &s;
    }
    return nullptr;
}

bool SystemManager::editStudent(int id, const std::string& newName, int newLevel) {
    Student* s = findStudent(id);
    if (s == nullptr) return false;
    s->setName(newName);
    s->setLevel(newLevel);
    return true;
}

void SystemManager::showStudents() const {
    if (students.empty()) { std::cout << "No students yet.\n"; return; }
    for (const auto& s : students) s.display();
}

// ======================= Doctors =======================
bool SystemManager::addDoctor(const Doctor& d) {
    if (findDoctor(d.getId()) != nullptr) return false;
    doctors.push_back(d);
    return true;
}

bool SystemManager::deleteDoctor(int id) {
    for (size_t i = 0; i < doctors.size(); i++) {
        if (doctors[i].getId() == id) {
            doctors.erase(doctors.begin() + i);
            return true;
        }
    }
    return false;
}

Doctor* SystemManager::findDoctor(int id) {
    for (auto& d : doctors) {
        if (d.getId() == id) return &d;
    }
    return nullptr;
}

bool SystemManager::editDoctor(int id, const std::string& newName, const std::string& newDepartment) {
    Doctor* d = findDoctor(id);
    if (d == nullptr) return false;
    d->setName(newName);
    d->setDepartment(newDepartment);
    return true;
}

void SystemManager::showDoctors() const {
    if (doctors.empty()) { std::cout << "No doctors yet.\n"; return; }
    for (const auto& d : doctors) d.display();
}

// ======================= Courses =======================
bool SystemManager::addCourse(const Course& c) {
    if (findCourse(c.getId()) != nullptr) return false;
    courses.push_back(c);
    return true;
}

bool SystemManager::deleteCourse(int id) {
    for (size_t i = 0; i < courses.size(); i++) {
        if (courses[i].getId() == id) {
            courses.erase(courses.begin() + i);
            return true;
        }
    }
    return false;
}

Course* SystemManager::findCourse(int id) {
    for (auto& c : courses) {
        if (c.getId() == id) return &c;
    }
    return nullptr;
}

bool SystemManager::editCourse(int id, const std::string& newName, const std::string& newCode) {
    Course* c = findCourse(id);
    if (c == nullptr) return false;
    c->setName(newName);
    c->setCode(newCode);
    return true;
}

void SystemManager::showCourses() const {
    if (courses.empty()) { std::cout << "No courses yet.\n"; return; }
    for (const auto& c : courses) {
        c.display();
        for (const auto& l : c.getLectures()) l.display();
    }
}

// ======================= Sample data =======================
void SystemManager::loadSampleData() {
    addDoctor(Doctor(1, "Dr. Ahmed", "1234", "Computer Science"));
    addDoctor(Doctor(2, "Dr. Mona", "1234", "Mathematics"));

    addStudent(Student(101, "Ali", "pass1", 1));
    addStudent(Student(102, "Sara", "pass2", 2));
    addStudent(Student(103, "Omar", "pass3", 1));

    Course c1(1, "CS101", "Programming 1", 1);
    Lecture l1(1, "Introduction to C++");
    l1.addQuestion(Question(1, "Which symbol ends a statement in C++?",
                            {"Colon", "Semicolon", "Comma", "Dot"}, 1));
    c1.addLecture(l1);
    addCourse(c1);

    addCourse(Course(2, "MA101", "Calculus 1", 2));

    // link data together
    findDoctor(1)->assignCourse(1);
    findDoctor(2)->assignCourse(2);
    findStudent(101)->enroll(1);
    findStudent(102)->enroll(1);
    findStudent(102)->enroll(2);

    std::cout << "Sample data loaded.\n";
}
