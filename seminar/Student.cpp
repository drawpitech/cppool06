/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** Student
*/

#include "Student.hpp"

Student::Student(std::string name) : name(std::move(name)) {
    this->display("I'm ready to learn C++.");
}

Student::~Student() {
    this->display("Wow, much learning today, very smart, such C++.");
}

bool Student::learn(std::string subject) {

    if (this->energy >= 42) {
        this->energy = std::max(this->energy - 42, 0);
        this->display(subject);
        return true;
    }

    std::string text(subject);
    size_t index = std::string::npos;
    while (true) {
        index = text.find("C++");
        if (index == std::string::npos)
            break;
        text.replace(index, 3, "shit");
    }

    this->display(text);
    return false;
}

void Student::drink(std::string drink) {
    if (drink == "Red Bull") {
        this->energy = std::min(this->energy + 32, 100);
        this->display("Red Bull gives you wings!");
        return;
    }
    if (drink == "Monster") {
        this->energy = std::min(this->energy + 64, 100);
        this->display("Unleash The Beast!");
        return;
    }
    this->display("ah, yes... enslaved moisture.");
}
