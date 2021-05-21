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

void insertAtPos(int data, int pos){
    if(pos < 0 && pos > size()) return;
    Node *th = head, *ele = new Node();
    ele->data = data;
    if(pos == 0 && head == NULL) head = ele;
    else if(pos == 0) {
        ele->next = head;
        head = ele;
    }
    else { 
        while(--pos) th = th->next;
        ele->next = th->next;
        th->next = ele;
    }
}

void delete_end(){
    if(head == NULL || head->next == NULL) head = NULL;
    else{
        Node* th = head;
        while(th->next->next != NULL) th = th->next;
        th->next = NULL;
    }
}

main(){
    insert(10);
    insert(45);
    insert(35);
    insert(34);
    insert(01);

    delete_end();
    delete_end();

    printSll();
}