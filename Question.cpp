#include "Question.h"
#include <iostream>

Question::Question() : id(0), text(""), correctIndex(0) {}

Question::Question(int id, const std::string& text,
                   const std::vector<std::string>& options, int correctIndex)
    : id(id), text(text), options(options), correctIndex(correctIndex) {}

int Question::getId() const { return id; }
std::string Question::getText() const { return text; }
const std::vector<std::string>& Question::getOptions() const { return options; }

void Question::setText(const std::string& newText) { text = newText; }

bool Question::isCorrect(int choice) const { return choice == correctIndex; }

void Question::display() const {
    std::cout << "Q" << id << ": " << text << std::endl;
    for (size_t i = 0; i < options.size(); i++) {
        std::cout << "   " << (i + 1) << ") " << options[i] << std::endl;
    }
}
