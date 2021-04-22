#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

void print(ListNode* node){
    while(node != nullptr){
        cout << node->data << endl;
        node = node->next;
    }
}

int main() {

    // Two ways to declare an object
    // (1) non-pointer;
    /* Date d1;
     * d1.month = 7;
     * d1.day = 13;
     *
     * (2) pointer;
     * Date* d2 = new Date();
     * d2->month = 7;
     * d2->day = 13;
     *
     * Arrow is a shorthand for: (*d2).month
     *
     * For #2, if you use it within a function, d2 is not "thrown away"
     */

    ListNode* front = new ListNode();
    front->data = 42;
    front->next = new ListNode();
    front->next->data = 32;

    print(front);
    print(front);

    /*
    ListNode* tempNode = front;

    while(tempNode != nullptr){
        cout << tempNode->data << endl;
        tempNode = tempNode->next;
    }
    */

    return 0;
}

