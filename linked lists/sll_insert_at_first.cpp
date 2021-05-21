#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void printSll(){
    Node* th = head;
    while(th != NULL){
        cout << th->data << "->";
        th = th->next;
    }
    cout << "null" << '\n';
}

void insert(int ele){
    Node* tmp = new Node();
    tmp->data = ele;
    if(head == NULL) head = tmp;
    else {
        Node* th = head;
        while(th->next != NULL) th = th->next;
        th->next = tmp;
    }
}

main(){
    Node* head = NULL;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(55);

    printSll();
}