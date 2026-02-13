// card.h
// Author: Fengxun Li
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H


#include <iostream>
#include <string>
using namespace std;

class Card{
public:
    // s for suit and v for value
    //ill set 1clubs 2diamonds 3spades 4hearts
    //v is in range 1-13 representing a to k. constructor first
    Card(int s=0, int v=0);

    //getterss

    int getSuit() const;
    int getValue() const;

    //comparisons
    bool operator<(const Card& other)const;
    bool operator>(const Card& other)const;
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other)const;

    


private:
    int s;
    int v;

};

//output function

ostream& operator<<(ostream& os, const Card&c);


#endif
