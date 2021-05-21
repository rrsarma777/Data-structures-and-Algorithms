#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

int size(){
    int cnt = 0;
    Node* th = head;
    while(th != NULL){
        ++cnt;
        th = th->next;
    }
    return cnt;
}

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

void deleteAtPos(int pos){
    if(pos < 0 || pos >= size()) return;
    if(pos == 0) head = head->next;
    else{
        Node* th = head;
        while(--pos) th = th->next;
        Node* tmp = th->next;
        th->next = th->next->next;
        free(tmp);
    }
}

void revPrintSll(Node* head){
    if(head == NULL) {
        cout << "null";
        return;
    }
    revPrintSll(head->next);
    cout << "->" << head->data;
}

main(){
    insert(10);
    insert(45);
    insert(35);
    insert(34);
    insert(01);


    Node* tmp = head;
    revPrintSll(tmp);
}