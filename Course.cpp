#include "Course.h"
#include <iostream>

Course::Course() : id(0), code(""), name(""), doctorId(0) {}

Course::Course(int id, const std::string& code, const std::string& name, int doctorId)
    : id(id), code(code), name(name), doctorId(doctorId) {}

int Course::getId() const { return id; }
std::string Course::getCode() const { return code; }
std::string Course::getName() const { return name; }
int Course::getDoctorId() const { return doctorId; }

void Course::setCode(const std::string& newCode) { code = newCode; }
void Course::setName(const std::string& newName) { name = newName; }
void Course::setDoctorId(int newDoctorId) { doctorId = newDoctorId; }

void Course::addLecture(const Lecture& lecture) { lectures.push_back(lecture); }

Lecture* Course::findLecture(int lectureId) {
    for (auto& l : lectures) {
        if (l.getId() == lectureId) return &l;
    }
    return nullptr;
}

const std::vector<Lecture>& Course::getLectures() const { return lectures; }

void Course::display() const {
    std::cout << "[Course] ID: " << id << " | " << code << " - " << name
              << " | Doctor ID: " << doctorId
              << " | Lectures: " << lectures.size() << std::endl;
}
