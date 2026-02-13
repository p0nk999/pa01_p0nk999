// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"


using namespace std;


Card translate(string line){
  if(line.empty())return Card(0,0);

  //find space in the line

  size_t spacePos=line.find(' ');

  //skip bad lines
  if(spacePos==string::npos){
    return Card(0,0);
  }

  string suitStr=line.substr(0,spacePos);
  string valStr=line.substr(spacePos+1);

  if (valStr.empty()){
    return Card(0,0);
  }
  int value=0;
  if(valStr=="k") {
      value=13;
  }
  else if(valStr=="q") {
      value=12;
  }
  else if(valStr=="j") {
      value=11;
  }
  else if(valStr=="a") {
      value=1;
  }
  else {
    value=stoi(valStr);
  }
  int suit=0;
  if(suitStr=="c")suit =1;
  else if (suitStr=="d")suit =2;
  else if (suitStr=="s")suit =3;
  else if (suitStr=="h")suit =4;

  return Card(suit,value);

}


int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  set<Card> aliceCards;
  set<Card> bobCards;



  //read alice
  while (getline (cardFile1, line) && (line.length() > 0)){
    Card newCard=translate(line);
    if (newCard.getSuit()!=0){
      aliceCards.insert(newCard);
    }

  }
  cardFile1.close();


  //read bob
  while (getline (cardFile2, line) && (line.length() > 0)){
    Card newCard=translate(line);
    if (newCard.getSuit()!=0){
      bobCards.insert(newCard);
    }

  }
  cardFile2.close();
  
  //implemenet the game

  //loop for the game
  bool matchFound=true;
  while(matchFound){
    //makesure matchfound turns false when conditions are not met
    matchFound=false;

    //alice round
    for(auto it= aliceCards.begin(); it!=aliceCards.end();++it){
      if(bobCards.count(*it)){
        cout<<"Alice picked matching card "<<*it<<endl;
        bobCards.erase(*it);
        aliceCards.erase(*it);
        matchFound=true;
        break;
      }
    }

    //bob round
    for (auto it= bobCards.rbegin();it!=bobCards.rend();++it){
      if(aliceCards.count(*it)){
        cout<<"Bob picked matching card "<<*it<<endl;
        aliceCards.erase(*it);
        bobCards.erase(*it);
        matchFound=true;
        break;
      }
    }

  }


  cout<<endl;
  cout<<"Alice's cards:"<<endl;
  for (const auto&card:aliceCards){
    cout<<card<<endl;
  }

  cout<<endl;
  cout<<"Bob's cards:"<<endl;
  for(const auto&card:bobCards){
    cout<<card<<endl;
  }
  
  return 0;
}
