// card.cpp
// Author: Fengxun Li
// Implementation of the classes defined in card.h

#include "card.h"
#include <iostream>
#include <string>
using namespace std;

//definition for constrctor
Card::Card(int suit, int value){
    s=suit;
    v=value;
}

//definition for getters
int Card::getSuit() const{
    return s;
}

int Card::getValue()const{
    return v;
}

//definition for comparisons
//first check for suit then check for valuess

//< 
bool Card::operator<(const Card& other)const{
    if (s!=other.s){
        return s<other.s;
    }
    return v<other.v;
}

//>
bool Card::operator>(const Card& other)const{
    if (s!=other.s){
        return s>other.s;
    }
    return v>other.v;
}

//check if suit and value both equal
//=
bool Card::operator==(const Card& other)const{
    return (s==other.s)&&(v==other.v);
}

//!=
bool Card::operator!=(const Card&other)const{
    return !(*this==other);
}



//output operator so that printing can be eaiser
ostream &operator <<(ostream& os, const Card&c){
    
    if (c.getSuit()==1) os<<"c";
    else if (c.getSuit()==2) os<<"d";
    else if(c.getSuit()==3)os<<"s";
    else if(c.getSuit()==4)os<<"h";

    os<<" ";


    if(c.getValue()==1) os<<"a";
    else if(c.getValue()==11) os<<"j";
    else if(c.getValue()==12) os<<"q";
    else if(c.getValue()==13) os<<"k";
    else os<<c.getValue();



    
    return os;


}