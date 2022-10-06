#include <iostream>
#include "Students.h"

int main() {
    Students a;
    a.create(234, "John");
    a.create(235, "James");
    a.create(236, "Raphael");
    a.create(237, "Ferry");
    a.create(238, "Martin");
    a.display();
    
    a.insert_at_pos(238, "Harry", 3);
    a.display();
    a.delete_at_pos(0);    
    a.display();
}
