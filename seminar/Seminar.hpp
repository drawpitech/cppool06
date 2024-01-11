/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** Seminar
*/

#ifndef PPOOL06_SEMINAR_HPP
#define PPOOL06_SEMINAR_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Assistant.hpp"
#include "Dean.hpp"
#include "Student.hpp"

struct Seminar {
  public:
    void run();
    void addAssistant(Assistant *assistant);
    void addDean(Dean *dean);
    void addStudent(Student *student);

  private:
    Dean *dean = nullptr;
    std::vector<Assistant *> assistants;
    std::vector<Student *> students;

    static void log(const std::string &text) { std::cout << text << "\n"; }
    static void display(const std::string &text) {
        Seminar::log("Seminar: " + text);
    }
    void logContent();
    void checkTime() const {
        this->dean->timeCheck();
        for (const auto &assistant : this->assistants)
            assistant->timeCheck();
    }
    size_t teachStudents(size_t assistant);
};

#endif /* PPOOL06_SEMINAR_HPP */
