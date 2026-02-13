// card_list.cpp
// Author: Fengxun Li
// Implementation of the classes defined in card_list.h

#include "card_list.h"
#include <iostream>

using namespace std;

//constructor definition
CardList::CardList(){
    root=nullptr;
}

//destructor
//helper
void CardList::deleteTree(CardList::Node*n){
    if (n==nullptr){
        return;
    }
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
    
}

CardList::~CardList(){
    deleteTree(root);

}

//bst operations
//insert
void CardList::insert(Card c){
    //if empty create root
    if(root==nullptr){
        root =new Node(c);
        return;
    }

    //find insertion point
    Node* curr=root;
    Node* prev=nullptr;
    while (curr!=nullptr){
        prev=curr;
        if (c<curr->data){
            curr=curr->left;
        }
        else if (c>curr->data){
            curr=curr->right;

        }
        //duplicated
        else{
            return;
        }

    }

    //insert into the point
    Node* newNode=new Node(c);
    newNode->parent=prev;
    if(c<prev->data){
        prev->left=newNode;
    }
    else{
        prev->right=newNode;
    }


}


//contains

bool CardList::contains(Card c)const{
    Node*curr=root;
    while (curr!=nullptr){
        if(c==curr->data) return true;
        if(c<curr->data)curr=curr->left;
        else curr=curr->right;
    }
    return false;
}





//iterator
//constructor
CardList::iterator::iterator(CardList::Node*n){
    current=n;
}

//dereference
const Card&CardList::iterator::operator*()const{
    return current->data;
}

//equals
bool CardList::iterator::operator==(const iterator& other)const{
    return current ==other.current;
}

bool CardList::iterator::operator!=(const iterator&other)const{
    return current !=other.current;
}


//increment
CardList::iterator&CardList::iterator::operator++(){
    if(current==nullptr)return *this;
    //if right child, right then left
    if (current->right!=nullptr){
        current=current->right;
        while (current->left!=nullptr){
            current =current->left;
        }
    }
    //no right child
    else{
        Node* p =current->parent;
        while(p!=nullptr&&current==p->right){
            current=p;
            p =p->parent;
        }
        current=p;
    }

    return *this;
}

//decrement
CardList::iterator& CardList::iterator::operator--(){
    if (current==nullptr) return *this;
    //if left child, left then right
    if (current->left!=nullptr){
        current=current->left;
        while (current->right!=nullptr){
            current =current->right;
        }
    }
    //no left child
    else{
        Node* p =current->parent;
        while(p!=nullptr&&current==p->left){
            current=p;
            p =p->parent;
        }
        current=p;
    }

    return *this;
}


//iterator generator
CardList::iterator CardList::begin() {
    Node* curr=root;
    if(curr!=nullptr) {
        while(curr->left != nullptr) {
            curr=curr->left;
        }
    }
    return iterator(curr);
}

CardList::iterator CardList::end() {
    return iterator(nullptr);
}

CardList::iterator CardList::rbegin() {
    Node* curr = root;
    if(curr!= nullptr) {
        while(curr->right !=nullptr) {
            curr=curr->right;
        }
    }
    return iterator(curr);
}

CardList::iterator CardList::rend() {
    return iterator(nullptr);
}

//remove
//helper to find minimum value node in a subtree
CardList::Node* CardList::getMinNode(CardList::Node* n) {
    while(n->left!=nullptr) n= n->left;
    return n;
}

void CardList::remove(Card c) {
    if(root==nullptr) return;

    //find the node to delete
    Node* curr=root;
    while(curr!= nullptr) {
        if (c==curr->data) break; // found
        if (c <curr->data)curr =curr->left;
        else curr=curr->right;
    }

    if(curr==nullptr) return; // mot found

    //2Children
    if(curr->left!=nullptr&&curr->right!=nullptr) {
        
        Node*successor=getMinNode(curr->right);
        
        curr->data=successor->data;
        curr=successor;
    }

    //at most one child
    Node*child=(curr->left!=nullptr) ? curr->left : curr->right;

    //link
    if(curr==root) {
        root=child;
        if(child!= nullptr)child->parent=nullptr;
    } else {
        if(curr==curr->parent->left) {
            curr->parent->left=child;
        } else {
            curr->parent->right=child;
        }
        if(child!= nullptr) child->parent=curr->parent;
    }

    delete curr;
}