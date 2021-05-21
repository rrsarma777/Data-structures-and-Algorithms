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

void printSll(){
    Node* th = head;
    while(th != NULL){
        cout << th->data << "->";
        th = th->next;
    }
    cout << "null" << '\n';
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

main(){
    Node* head = NULL;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(55);

    insertAtPos(10, 3);
    insertAtPos(11, 0);
    insertAtPos(1, 5);

    printSll();  
}