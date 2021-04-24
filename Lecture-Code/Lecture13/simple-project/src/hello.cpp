#include <iostream>
#include "console.h"
using namespace std;


struct ListNode{
    int data;
    ListNode* next;
};

/* Incorrect way: duplicate of pointer created.
void addFront(ListNode* front, int value){

    ListNode* temp = new ListNode(value);

    temp->text = front;
    front = temp;
}
*/

void addFront(ListNode*& list, int value){
    // instantiating a new struct.
    ListNode* temp = new ListNode();

    // set value for the node.
    temp->data = value;

    // the temp node will point to the first node of the previous list.
    temp->next = list;

    // we are modifying the pointer to point at the first node(temp).
    list = temp;
}

void addBack(ListNode*& front, int value){
    ListNode* current = front;

    // check for null pointer
    if(front == nullptr){
        front = new ListNode();
        front->data = value;
    } else{
        // this for loop points at the last node of the list
        for(;current->next != nullptr;current = current->next);

        // insantiate new node that will be the last node.
        ListNode* temp = new ListNode();
        temp->data = value;
        temp->next = nullptr;

        // set the last node to be the temp ListNode;
        current->next = temp;
    }

    /* The previous expression is equivalent to
    while (list->next != nullptr){
        list = list->next;
    }
    */


}

void printList(ListNode* front){
    while(front != nullptr){
        cout << front->data << endl;
        front = front->next;
    }
}


int main() {
    ListNode* front = nullptr;
    //addFront(front, 9);
    //addFront(front, 17);
    //addFront(front, -3);
    //addFront(front, 42);

    addBack(front, 20);
    printList(front);

    return 0;
}
