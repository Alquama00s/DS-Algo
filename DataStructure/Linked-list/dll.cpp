#include <iostream>
using namespace std;
struct node {
    int _data;
    struct node *next, *prev;
};
struct linkedList {
    node *start = NULL, *end = NULL;
    int size = 0;
    linkedList() {}
    linkedList(int data) {
        start = (node *)malloc(sizeof(node));
        start->_data = data;
        start->next = NULL;
        start->prev = NULL;
        end = start;
        size++;
    }
    void append(int data) {
        node *temp = (node *)malloc(sizeof(node));
        temp->_data = data;
        temp->next = NULL;
        if (start == NULL) {
            temp->prev = NULL;
            start = temp;
            end = start;
            size++;
        } else {
            temp->prev = end;
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
            n->prev=NULL;
            start=n;
            return;
        }
        if (index >= size / 2) {
            node *pt = start;
            for (size_t i = 0; i < index - 1; i++) {
                pt = pt->next;
            }
            node *n = (node *)malloc(sizeof(node));
            n->_data = data;
            n->next = pt->next;
            n->prev = pt;
            pt->next = n;
            pt = n->next;
            pt->prev = n;
            size++;
            return;
        } else {
            node *pt = end;
            for (size_t i = size - 1; i >= index - 1; i--) {
                pt = pt->prev;
            }
            node *n = (node *)malloc(sizeof(node));
            n->_data = data;
            n->next = pt->next;
            n->prev = pt;
            pt->next = n;
            pt = n->next;
            pt->prev = n;
            size++;
        }
    }
    void remove(int index) {
        if (index > size - 1) {
            cout << "error: size is" << size << "\n";
            return;
        }
        if(index==0){
            node *n=start;
            start=start->next;
            free(n);
            return;
        }
        if(index==size-1){
            node *n=end;
            end=end->prev;
            end->next=NULL;
            free(n);
            size--;
            return;
        }
        if (index > size / 2) {
            node *pt = start;
            for (size_t i = 0; i < index - 1; i++) {
                pt = pt->next;
            }
            node *n = pt->next;
            pt->next = n->next;
            free(n);
            n = pt->next;
            n->prev = pt;
            size--;
            return;
        } else {
            node *pt = end;
            for (size_t i = size - 1; i >= index - 1; i--) {
                pt = pt->prev;
            }
            node *n = pt->next;
            pt->next = n->next;
            free(n);
                n = pt->next;
                n->prev = pt;
            size--;
        }
    }
    void print(int reverse = 0) {
        if (reverse == 0) {
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
        } else {
            node *p1 = end;
            if (p1 == NULL) {
                cout << "Empty List";
                return;
            }
            while (p1 != start) {
                cout << p1->_data << " ";
                p1 = p1->prev;
            }
            cout << start->_data << "\n";
        }
    }
};
int main() {
    linkedList l;
    for (size_t i = 0; i < 10; i++) {
        l.append(i + 1);
    }
    l.print();//question: 11.c
    //question a:
    l.insert(11,5); //insertion at random pos
    l.print();//question: 11.c
    l.insert(11,0); //insertion at random begining
    l.print();//question: 11.c
    l.insert(11,l.size-1); //insertion at random end
    l.print();//question: 11.c
    //question 11.b
    l.remove(5);//removal at random pos
    l.print();//question: 11.c
    l.remove(0);//removal at random begining
    l.print();//question: 11.c
    l.remove(l.size-1);//removal at random end
    l.print();//question: 11.c
    return 0;
}