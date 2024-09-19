#include "Random.h"
#include "Data.h"
#include "Settings.h"

#include <iostream>
#include <limits>

//Game Settings

//update game
void draw(Data& data) {
    data.setBet();

    data.guess();

    if (data.getGuess() == data.getNum()) {
        std::cout << "You guessed the correct number! Here's your money.\n";
        data.setMoney(data.getMoney() * 10);
        data.printMoney();
    }
    else {
        std::cout << "The correct number was: " << data.getNum() << '\n';
        data.setMoney(data.getMoney() - data.getBet());
        data.printMoney();
    }
}

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
    }

    std::cout << "Game Over! You don't have any more money.";
    //std::cout << data.getNum();
}