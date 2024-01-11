/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** Dean
*/

#include <fstream>
#include <utility>
#include <vector>

#include "Dean.hpp"

Dean::Dean(std::string name) : name(std::move(name)) {
    this->display("I'm Dean " + this->name + "! How do you do, fellow kids?");
}

Dean::~Dean() { this->display("Time to go home."); }

void Dean::teachStudent(Student *student, std::string lesson) {
    if (student == nullptr)
        return;
    if (!student->learn(std::move(lesson)))
        this->display("All work and no play makes " + student->get_name() +
                      " a dull student .");

    std::vector<std::string> drinks = {
        "Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs",
    };
    std::ofstream student_file(student->get_name() + ".drink");
    student_file << drinks[std::rand() % 5] << "\n";
    student_file.close();
}

void Dean::timeCheck() {
    if (this->isBusy) {
        this->isBusy = false;
        this->display("Don't forget to close the windows when you leave.");
        return;
    }
    this->isBusy = true;
    this->display("Where is everyone ?");
}
