#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void printSll(Node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << '\n';
}

int size(){
    int cnt = 0;
    Node* th = head;
    while(th != NULL){
        ++cnt;
        th = th->next;
    }
    return cnt;
}

main(){
    Node *a, *b, *c, *d;
    a = new Node();
    b = new Node();
    c = new Node();
    d = new Node();

    a->data = 10;
    b->data = 20;
    c->data = 30;
    d->data = 40;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    printSll(a);   
}
