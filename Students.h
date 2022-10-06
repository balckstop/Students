#ifndef _STUDENTS_H_
#define _STUDENTS_H_
#include <string>

class Students {
    private:
    struct Node {
        int ID;
        std::string name;
        Node *next;
        Node *prev;
    };
    Node *head, *tail;
    
    public:
    Students() { head = 0; tail = 0; }
    ~Students() {}
    
    void create(int ID, std::string name);
    void display();
    void insert_at_pos(int ID, std::string name, int pos);
    int count();
    void delete_at_pos(int pos);
    void reverse();
};

#endif