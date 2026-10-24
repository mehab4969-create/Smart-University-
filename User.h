#pragma once
#include <string>

// Base class for everyone who uses the system
class User {
protected:
    int id;
    std::string name;
    std::string password;

public:
    User();
    User(int id, const std::string& name, const std::string& password);
    virtual ~User() = default;

    // Getters
    int getId() const;
    std::string getName() const;
    bool checkPassword(const std::string& pass) const;

    // Setters
    void setId(int newId);
    void setName(const std::string& newName);
    void setPassword(const std::string& newPass);

    virtual void display() const;
};
