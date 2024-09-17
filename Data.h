#ifndef DATA_H
#define DATA_H

#include "Random.h"

#include <iostream>

//Game Data
class Data{
private:
    int m_num{Random::get(1,10)};
    int m_money{};

public:
    int getNum() const{return m_num;}
    int getMoney() const{return m_money;}

    void setMoney(int money) {m_money = money;}

    //Data declaration here
    void printMoney() const;
};

void Data::printMoney() const{
    std::cout << "$" << m_money << '\n';
}

#endif