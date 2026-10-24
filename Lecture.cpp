#include "Lecture.h"
#include <iostream>

Lecture::Lecture() : id(0), title("") {}

Lecture::Lecture(int id, const std::string& title) : id(id), title(title) {}

int Lecture::getId() const { return id; }
std::string Lecture::getTitle() const { return title; }
void Lecture::setTitle(const std::string& newTitle) { title = newTitle; }

void Lecture::addQuestion(const Question& q) { questions.push_back(q); }
const std::vector<Question>& Lecture::getQuestions() const { return questions; }

void Lecture::display() const {
    std::cout << "  Lecture " << id << ": " << title
              << " (" << questions.size() << " questions)" << std::endl;
}
