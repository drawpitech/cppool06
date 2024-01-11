/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** Dean
*/

#ifndef PPOOL06_DEAN_HPP
#define PPOOL06_DEAN_HPP

#include <iostream>
#include <string>

#include "Student.hpp"

struct Dean {
  public:
    Dean(std::string name);
    ~Dean();

    void teachStudent(Student *student, std::string lesson);
    void timeCheck();
    std::string get_name() const { return this->name; }

  private:
    const std::string name;
    bool isBusy = false;
    void display(const std::string &text) const {
        std::cout << "Dean " << name << ": " << text << "\n";
    }
};

#endif /* PPOOL06_DEAN_HPP */
