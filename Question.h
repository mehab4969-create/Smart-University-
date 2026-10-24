#pragma once
#include <string>
#include <vector>

// Multiple-choice question
class Question {
private:
    int id;
    std::string text;
    std::vector<std::string> options;
    int correctIndex;             // index of the right option (0-based)

public:
    Question();
    Question(int id, const std::string& text,
             const std::vector<std::string>& options, int correctIndex);

    int getId() const;
    std::string getText() const;
    const std::vector<std::string>& getOptions() const;

    void setText(const std::string& newText);

    bool isCorrect(int choice) const;   // choice is 0-based
    void display() const;
};
