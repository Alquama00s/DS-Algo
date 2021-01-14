#include <iostream>
using namespace std;
struct node {
    int _data;
    struct node *next;
};
struct linkedList {
    node *start = NULL, *end = NULL;
    int size = 0;
    linkedList() {}
    linkedList(int data) {
        start = (node *)malloc(sizeof(node));
        start->_data = data;
        start->next = NULL;
        end = start;
        size++;
    }
    void append(int data) {
        node *temp = (node *)malloc(sizeof(node));
        temp->_data = data;
        temp->next = NULL;
        if (start == NULL) {
            start = temp;
            end = start;
            size++;
        } else {
            end->next = temp;
            end = temp;
            size++;
        }
    }
    void insert(int data, int index) {
        if (index > size - 1) {
            cout << "error: size is" << size << "\n";
            return;
        }
        if(index==size-1){
            append(data);
            return;
        }
        if(index==0){
            node *n = (node *)malloc(sizeof(node));
            n->_data = data;
            n->next=start;
            start=n;
            return;
        }
        node *pt = start;
        for (size_t i = 0; i < index-1; i++) {
            pt = pt->next;
        }
        node *n = (node *)malloc(sizeof(node));
        n->_data = data;
        n->next = pt->next;
        pt->next = n;
        size++;
    }
    void remove(int index) {
        if (index > size - 1) {
            cout << "error: size is" << size << "\n";
            return;
        }
        if(index==0){
            node *n=start;
            start=start->next;
            return;
        }
        node *pt = start;
        for (size_t i = 0; i < index-1; i++) {
            pt = pt->next;
        }
        node *n=pt->next;
        pt->next=n->next;
        if(index==size-1){
            end=pt;
        }
        free(n);
        size--;
    }
    void print() {
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
    }
};
int main() {
    linkedList l;
    for (size_t i = 0; i < 10; i++)
    {
        l.append(i+1);
    }
    l.print();//question: 10.c
    //question a:
    l.insert(11,5); //insertion at random pos
    l.print();//question: 10.c
    l.insert(11,0); //insertion at random begining
    l.print();//question: 10.c
    l.insert(11,l.size-1); //insertion at random end
    l.print();//question: 10.c
    //question 10.b
    l.remove(5);//removal at random pos
    l.print();//question: 10.c
    l.remove(0);//removal at random begining
    l.print();//question: 10.c
    l.remove(l.size-1);//removal at random end
    l.print();//question: 10.c
    return 0;
}