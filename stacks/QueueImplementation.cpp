#include <iostream>
#include <stack>
using namespace std;

struct Queue{
    stack<int> stk1, stk2;
    int r = -1;

    void enque(int data){
        stk1.push(data);
        r = data;
    }

    int deque(){
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int data = stk2.top();
        stk2.pop();
        return data;
    }

    int front(){
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }

    int rear(){
       return r;
    }

    int length(){
        return stk1.size() + stk2.size();
    } 
};

int main(){
    Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    cout << q.deque() << '\n';
    cout << q.deque() << '\n';
    cout << q.deque() << '\n';
}
