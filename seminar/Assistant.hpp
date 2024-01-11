/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** Assistant
*/

#ifndef PPOOL06_ASSISTANT_HPP
#define PPOOL06_ASSISTANT_HPP

#include <iostream>
#include <string>

#include "Student.hpp"

struct Assistant {
  public:
    Assistant(unsigned long id);
    ~Assistant();

    void giveDrink(Student *student, std::string drink);
    std::string readDrink(std::string student);
    void helpStudent(Student *student);
    void timeCheck();

  private:
    const unsigned long id;
    bool isBusy = false;

    void display(const std::string &text) const {
        std::cout << "Assistant " << this->id << ": " << text
                  << " *sip coffee*\n";
    }
};

#endif /* PPOOL06_ASSISTANT_HPP */
