/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** StupidUnitConverter
*/

#include <iomanip>
#include <iostream>
#include <sstream>

auto celcuis_to_fahrenheit(double celcuis) -> double {
    return celcuis * 9.0 / 5.0 + 32;
}

auto fahrenheit_to_celcuis(double fahrenheit) -> double {
    return 5.0 / 9.0 * (fahrenheit - 32);
}

auto nice_output(double value, const std::string &unit) -> void {
    std::cout << std::setw(16) << std::right << std::fixed
              << std::setprecision(3) << value << std::setw(16) << std::right
              << unit << '\n';
}

auto handle_line(const std::string &buf) -> bool {
    std::istringstream str(buf);
    std::string value;
    std::string unit;

    str >> value >> unit;
    double val = std::stod(value);

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

auto main() -> int {
    bool res = true;
    std::string buf;

    while (getline(std::cin, buf))
        res |= handle_line(buf);
    return (res) ? 0 : 84;
}
