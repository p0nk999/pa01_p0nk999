// card_list.h
// Author: Fengxun Li
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include <iostream>
#include "card.h"

using namespace std;

class CardList{
private:
    struct Node{
        Card data;
        Node* left;
        Node* right;
        Node* parent;
        //constructor to create a node
        Node(Card c){
            data=c;
            left=nullptr;
            right=nullptr;
            parent=nullptr;
        }
    };
    Node*root;

    void deleteTree(Node*n);
    Node* getMinNode(Node* n);

public:
    //constructor
    CardList();
    //.destructor
    ~CardList();



    //bst oprations
    void insert(Card c);
    void remove(Card c);
    bool contains(Card c)const;

    //define iterator
    class iterator{
    public:
        //constructor
        iterator(Node*n=nullptr);

        //dereference
        const Card&operator*()const;

        //equals
        bool operator ==(const iterator& other)const;
        bool operator!=(const iterator &other) const;

        //increment
        iterator&operator++();

        //decrement
        iterator&operator--();

    private:
        //pointer pointin to current node
        Node*current;


    };

    //generate iterators
    iterator begin();
    iterator end();
    iterator rbegin();
    iterator rend();

};




#endif
