/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** StupidUnitConverter
*/

#include <iomanip>
#include <iostream>
#include <sstream>

double celcuis_to_fahrenheit(double celcuis) {
    return celcuis * 9.0 / 5.0 + 32;
}

double fahrenheit_to_celcuis(double fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32);
}

void nice_output(double value, const std::string &unit) {
    std::cout << std::setw(16) << std::right << std::fixed
              << std::setprecision(3) << value << std::setw(16) << std::right
              << unit << '\n';
}

bool handle_line(const std::string &buf) {
    std::istringstream str(buf);
    std::string unit;
    double val = 0;

    str >> val >> unit;

    if (unit == "Celsius") {
        nice_output(celcuis_to_fahrenheit(val), "Fahrenheit");
        return true;
    }
    if (unit == "Fahrenheit") {
        nice_output(fahrenheit_to_celcuis(val), "Celsius");
        return true;
    }
    std::cerr << "Invalid unit\n";
    return false;
}

int main() {
    bool res = true;
    std::string buf;

    while (getline(std::cin, buf))
        res |= handle_line(buf);
    return (res) ? 0 : 84;
}
