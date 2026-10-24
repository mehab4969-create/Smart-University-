#pragma once
#include "Question.h"
#include <string>
#include <vector>

class Lecture {
private:
    int id;
    std::string title;
    std::vector<Question> questions;

public:
    Lecture();
    Lecture(int id, const std::string& title);

    int getId() const;
    std::string getTitle() const;
    void setTitle(const std::string& newTitle);

    void addQuestion(const Question& q);
    const std::vector<Question>& getQuestions() const;

    void display() const;
};
