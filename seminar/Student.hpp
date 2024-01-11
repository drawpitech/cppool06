/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** Student
*/

#ifndef PPOOL06_STUDENT_HPP
#define PPOOL06_STUDENT_HPP

#include <iostream>

struct Student {
  public:
    explicit Student(std::string name);
    ~Student();

    bool learn(std::string subject);
    void drink(std::string drink);

    std::string get_name() const { return this->name; }

  private:
    void display(const std::string &text) const {
        std::cout << "Student " << this->name << ": " << text << "\n";
    }
    const std::string name;
    int energy = 100;
};

#endif /* PPOOL06_STUDENT_HPP */
