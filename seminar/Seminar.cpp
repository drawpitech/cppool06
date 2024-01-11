/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** Seminar
*/

#include <algorithm>
#include <string>

#include "Assistant.hpp"
#include "Seminar.hpp"

void Seminar::run() {
    if (this->students.empty() || this->dean == nullptr ||
        this->assistants.empty()) {
        Seminar::display("A C++ seminar needs at least one Dean of Studies, "
                         "one Assistant and one Student.");
        return;
    }
    Seminar::display("Begining 6th day of seminar.");
    this->logContent();
    this->checkTime();

    size_t assistant = 0;
    for (size_t i = 0; i < 5; i++)
        assistant = this->teachStudents(assistant);

    this->checkTime();
}

size_t Seminar::teachStudents(size_t assistant) {
    for (auto &student : this->students) {
        this->dean->teachStudent(student, "I'm learning C++!");
        this->assistants.at(assistant)->helpStudent(student);
        assistant = (assistant + 1) % this->assistants.size();
    }
    return assistant;
}

void Seminar::logContent() {
    Seminar::log("Dean of Studies: " + this->dean->get_name());
    std::string disp_a =
        "Teaching assistants: " + std::to_string(this->assistants[0]->get_id());
    for (size_t i = 1; i < this->assistants.size(); i++)
        disp_a += ", " + std::to_string(this->assistants.at(i)->get_id());
    Seminar::log(disp_a);
    std::string disp_s = "Students: " + this->students[0]->get_name();
    for (size_t i = 1; i < this->students.size(); i++) {
        disp_s += ", " + this->students.at(i)->get_name();
    }
    Seminar::log(disp_s);
}

void Seminar::addStudent(Student *student) {
    if (student == nullptr)
        return;

    if (std::find(this->students.begin(), this->students.end(), student) !=
        this->students.end()) {
        Seminar::display("Student " + student->get_name() +
                         " is already registered.");
        return;
    }

    if (this->students.size() == 5) {
        Seminar::display("There is only room for five Students.");
        return;
    }
    Seminar::display("Student " + student->get_name() + " joined the seminar.");
    this->students.push_back(student);
}

void Seminar::addDean(Dean *dean) {
    if (dean == nullptr)
        return;
    if (this->dean == nullptr) {
        this->dean = dean;
        Seminar::display("Dean " + dean->get_name() + " is here.");
        return;
    }
    Seminar::display("There can only be one Dean of Studies.");
}

void Seminar::addAssistant(Assistant *assistant) {
    if (assistant == nullptr)
        return;

    if (std::find(this->assistants.begin(), this->assistants.end(),
                  assistant) != this->assistants.end()) {
        Seminar::display("Assistant " + std::to_string(assistant->get_id()) +
                         " is already registered.");
        return;
    }

    if (this->assistants.size() == 2) {
        Seminar::display("There is only room for two Teaching Assistants.");
        return;
    }

    this->assistants.push_back(assistant);
    Seminar::display("Assistant " + std::to_string(assistant->get_id()) +
                     " joined the pedagogical team.");
}
