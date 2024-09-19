#ifndef DATA_H
#define DATA_H

#include "Random.h"
#include "Settings.h"

#include <iostream>

//Game Data
class Data{
private:
    int m_num{Random::get(1,10)};
    int m_money{};
    int m_bet{};
    int m_guess{};

public:
    int getNum() const{return m_num;}
    int getMoney() const{return m_money;}
    int getBet() const{return m_bet;}
    int getGuess() const{return m_guess;}

    void setMoney(int money) {m_money = money;}

    //Data declaration here
    void printMoney() const;
    void setBet();
    void guess();
};

void Data::printMoney() const{
    std::cout << "$" << m_money << '\n';
}

//get user input to set the amount to bet
void Data::setBet() {
    int amount{};

    //validating userinput
    while (true || amount != -1) {
        std::cout << "\nEnter -1 to exit the game.";
        std::cout << "\nInput the amount to bet : ";
        std::cin >> amount;

        if (amount > m_money) {
            std::cout << "You don't have enough money!\n";
            std::cout << "Your current money: ";
            printMoney();

            Settings::clearBuffer(); 
            continue;
        }

        if (!std::cin) {
            std::cout << "Invalid input, try again.\n";

            Settings::clearBuffer();
            continue;
        }

        if (amount <= 0 ) {
            std::cout << "Are you serious betting negative amount!?\n";

            Settings::clearBuffer();
            continue;
        }

        m_bet = amount;
        break;
    }
}

void Data::guess() {
    int guess{};

    while (true) {
        std::cout << "Enter the number 1-10 that you want to guess: ";
        std::cin >> guess;

        if (!std::cin) {
            std::cout << "Invalid input, try again.\n\n";

            Settings::clearBuffer();
            continue;
        }

        if (guess < 1 || guess > 10) {
            std::cout << "You are guessing out of range, guess the number in between 1-10.\n\n";

            Settings::clearBuffer();
            continue;
        }

        break;
    }

    m_guess  = guess;
}
#endif