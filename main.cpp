#include "Random.h"
#include "Data.h"

#include <iostream>
#include <limits>

//Game Settings
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

//ask user to input the bet amount
void bet(Data& data){

}

//update game
void draw(Data& data) {}

void chooseDiff(Data& data) {
    int choose{};

    while (true) {
        std::cout << "Choose your difficulty with 1 - 3\n";
        std::cout << "1 - Easy\n2 - Medium\n3 - Hard\n";
        std::cout << "Your input: ";
        std::cin >> choose;

        if (!std::cin) {
            std::cout << "Invalid input, try again.\n\n";

            Settings::clearBuffer();
            continue;
        }

        if (choose < 1 || choose > 3) {
            std::cout << "Number was out of bounder, chooose between 1-3.\n\n";

            Settings::clearBuffer();
            continue;
        }

        break;
    }

    switch (choose) {
        case Settings::easy  :      data.setMoney(2000); break;
        case Settings::medium:      data.setMoney(1000); break;
        case Settings::hard  :      data.setMoney(500) ; break;
    }

    
    std::cout << "\nHere is your starting money, good luck!\n";
    data.printMoney();
}

//initial game 
void initGame() {
    std::cout << "------------------------------------------------------\n";
    std::cout << "-------      CASINO NUMBER GUESSING GAME       -------\n";
    std::cout << "------------------------------------------------------\n\n";

    std::cout << "Game Rule: \n- You bet amount and guess the number, if correct then you get your amount multiply by 10.\n";
    std::cout << "- You lose when you don't have any money left.\n\n";

}

int main() {
    Data data{};

    initGame();
    chooseDiff(data);

    while (data.getMoney()) {
        draw(data);
        bet(data);
    }
    //std::cout << data.getNum();
}