/*
** EPITECH PROJECT, 2024
** ppool06
** File description:
** MyCat
*/

#include <fstream>
#include <iostream>

bool open_file(const std::string &filename) {
    std::string buf;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "MyCat: " << filename << ": No such file or directory\n";
        return false;
    }

    while (getline(file, buf))
        std::cout << buf << '\n';
    file.close();
    return true;
}

void get_stdin() {
    std::string buf;
    while (getline(std::cin, buf))
        std::cout << buf << '\n';
}

auto main(int argc, char **argv) -> int {
    if (argc == 1) {
        get_stdin();
        return 0;
    }
    bool res = true;
    for (int i = 1; i < argc; i++)
        res = res && open_file(argv[i]);
    return (res) ? 0 : 84;
}
