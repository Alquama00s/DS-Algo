#include <iostream>
using namespace std;
struct node {
    int _data;
    struct node *next;
};
struct stack {
    node *start = NULL, *end = NULL;
    int size = 0;
    void push(int data) {
        node *temp = (node *)malloc(sizeof(node));
        temp->_data = data;
        temp->next = NULL;
        if (start == NULL) {
            start = temp;
            end = start;
            size++;
        } else {
            temp->next=start;
            start=temp;
            size++;
        }
    }
    int top(){
        return start->_data;
    }
    int pop(){
        int a=top();
        node *n=start;
        start=start->next;
        free(n);
        return a;
    }
   /* void print() {
        node *p1 = start;
        if (p1 == NULL) {
            cout << "Empty List";
            return;
        }
        while (p1 != end) {
            cout << p1->_data << " ";
            p1 = p1->next;
        }
        cout << end->_data << "\n";
    }*/
};
int main() {
    stack s;
    for (size_t i = 0; i < 10; i++)
    {
        s.push(i+1);
    }
    cout<<s.top()<<"\n";
    s.pop();
    cout<<s.top()<<"\n";
    //s.print();
    return 0;
}