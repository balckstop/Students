#include <iostream>
#include "Students.h"

void Students::create(int ID, std::string name) {
    Node *newnode;
    newnode = new Node();
    newnode -> ID = ID;
    newnode -> name = name;
    if (head == 0) {
        tail = head = newnode;
        newnode -> next = newnode;
        newnode -> prev = newnode;
    } else {
        newnode -> next = head;
        newnode -> prev = tail;
        tail -> next = newnode;
        tail = newnode;
        head -> prev = newnode;
    }
    
}

void Students::display() {
    Node *temp;
    temp = head;
    if (head == 0) { std::cout << "List is empty" << std::endl; }
    std::cout << "=====================================" << std::endl;
    while (temp != tail) {
        std::cout << temp -> ID << " | " << temp -> name << std::endl;
        temp = temp -> next;
    }
    std::cout << temp -> ID << " | " << temp -> name << std::endl;
    std::cout << "=====================================" << std::endl;    
}

int Students::count() {
    Node *temp;
    temp = head;
    int num{};
    while (temp != tail ) {
        num++;
        temp = temp -> next;
    }
    num++;
    return num;
}

void Students::insert_at_pos(int ID, std::string name, int pos) {
    int total = count();
    if (pos <= 0 || pos > total) { std::cout << "Invalid position" << std::endl; }
    else {
        Node *newnode;
        newnode = new Node();
        newnode -> ID = ID;
        newnode -> name = name;
        
        if (head == 0) {
            head = tail = newnode;
            newnode -> prev = newnode;
            newnode -> next = newnode;
        } else {
            if (pos == 1 || pos == total) {
                newnode -> prev = tail;
                newnode -> next = head;
                head -> prev = newnode;
                tail -> next = newnode;
                if (pos == 1) { head = newnode; }
                else { tail = newnode; }
            } else {
                int i{1};
                Node *temp;
                temp = head;
                while (i < pos) { temp = temp -> next; i++; }
                newnode -> prev = temp -> prev;
                newnode -> next = temp;
                temp -> prev -> next = newnode;
                temp -> prev = newnode;
            }
        }    
    }
}

void Students::delete_at_pos(int pos) {
    int total = count();
    if (pos <= 0 || pos > total) { std::cout << "Invalid position" << std::endl; }
    else {
        if (head == 0) { std::cout << "List is empty" << std::endl; }
        else {
            Node *temp;
            if (pos == 1) {
                temp = head;
                head = temp -> next;
                head -> prev = tail;
                tail -> next = head;
            } else if (pos == total) {
                temp = tail;
                tail -> prev -> next = head;
                head -> prev = temp -> prev;
                tail = temp -> prev;
            } else {
                int i{1};
                temp = head;
                while (i < pos) { temp = temp -> next; i++; }        
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
            }
            delete temp;
        }    
    }
}

void Students::reverse() {
    Node *temp;
    Node *prevNode;
    temp = head;
    while (temp != tail) {
        prevNode = temp -> prev;
        temp -> prev = temp -> next;
        temp -> next = prevNode;
        temp = temp -> prev;
    }
    prevNode = temp -> prev;
    temp -> prev = temp -> next;
    temp -> next = prevNode;
    prevNode = tail;
    tail = head;
    head = prevNode;
}