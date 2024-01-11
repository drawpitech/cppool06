/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** Assistant
*/

#include <fstream>

#include "Assistant.hpp"

Assistant::Assistant(unsigned long id) : id(id) {
    this->display("'morning everyone");
}

Assistant::~Assistant() { this->display("see you tomorrow at 9.00"); }

void Assistant::giveDrink(Student *student, std::string drink) {
    if (student == nullptr)
        return;
    this->display("drink this, " + student->get_name());
    student->drink(std::move(drink));
}

std::string Assistant::readDrink(std::string student) {
    std::string filename(student + ".drink");
    std::ifstream file(filename);

    if (!file)
        return "";

    std::string drink;
    getline(file, drink);
    file.close();

    this->display(student + " needs a " + drink);
    std::remove(filename.c_str());
    return drink;
}

void Assistant::helpStudent(Student *student) {
    if (student == nullptr)
        return;
    std::string drink = this->readDrink(student->get_name());
    if (drink.empty()) {
        this->display(student->get_name() + " seems fine");
        return;
    }
    student->drink(drink);
}

void Assistant::timeCheck() {
    if (this->isBusy) {
        this->display("Enough teaching for today");
        this->isBusy = false;
        return;
    }
    this->display("Time to teach some serious business");
    this->isBusy = true;
}
