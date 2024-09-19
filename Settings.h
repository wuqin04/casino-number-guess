#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <limits>

namespace Settings{
    enum Difficulty: int{
        easy = 1,
        medium = 2,
        hard = 3,

        max_diff
    };

    void clearBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

#endif