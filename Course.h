#pragma once
#include "Lecture.h"
#include <string>
#include <vector>

class Course {
private:
    int id;
    std::string code;
    std::string name;
    int doctorId;                  // the doctor who teaches this course
    std::vector<Lecture> lectures;

public:
    Course();
    Course(int id, const std::string& code, const std::string& name, int doctorId);

    int getId() const;
    std::string getCode() const;
    std::string getName() const;
    int getDoctorId() const;

    void setCode(const std::string& newCode);
    void setName(const std::string& newName);
    void setDoctorId(int newDoctorId);

    void addLecture(const Lecture& lecture);
    Lecture* findLecture(int lectureId);
    const std::vector<Lecture>& getLectures() const;

    void display() const;
};
