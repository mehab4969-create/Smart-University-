#include "User.h"
#include <iostream>

User::User() : id(0), name(""), password("") {}

User::User(int id, const std::string& name, const std::string& password)
    : id(id), name(name), password(password) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }
bool User::checkPassword(const std::string& pass) const { return password == pass; }

void User::setId(int newId) { id = newId; }
void User::setName(const std::string& newName) { name = newName; }
void User::setPassword(const std::string& newPass) { password = newPass; }

void User::display() const {
    std::cout << "ID: " << id << " | Name: " << name << std::endl;
}
