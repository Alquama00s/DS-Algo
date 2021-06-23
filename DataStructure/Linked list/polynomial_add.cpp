#include <iostream>
using namespace std;
struct poly
{
    int c; //coefficient
    int p; //power
    struct poly *next;
};
struct expression
{

    poly *start = NULL, *end = NULL;
    expression() {}
    expression(int coe, int pow)
    {
        start = (poly *)malloc(sizeof(poly));
        start->c = coe;
        start->p = pow;
        start->next=NULL;
        end = start;
    }
    void append(int coe, int pow)
    {
        poly *temp = (poly *)malloc(sizeof(poly));
        temp->c = coe;
        temp->p = pow;
        temp->next=NULL;
        if (start == NULL)
        {
            start = temp;
            end = start;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
    }
    void print()
    {
        poly *p1 = start;
        if(p1==NULL){
            cout<<"Null";
            return;
        }
        while (p1 != end)
        {
            cout << p1->c << "exp(x," << p1->p << ") +";
            p1 = p1->next;
        }
        cout<<end->c<< "exp(x," <<end->p<< ")\n";
    }
};
expression add(expression e1, expression e2)
{
    poly *p1, *p2;
    expression e;
    p1 = e1.start;
    p2 = e2.start;
    while (p1 != NULL && p2 != NULL)
    { 
        if (p1->p == p2->p)
        {
            e.append(p1->c + p2->c, p1->p);
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            if (p1->p > p2->p)
            {
                e.append(p1->c, p1->p);
                    p1 = p1->next;
            }
            else
            {
                e.append(p2->c, p2->p);
                p2 = p2->next;
            }
        }
        if (p1 == NULL && p2 == NULL)
        {
            return e;
        }
        else
        {
            if (p1 == NULL)
            {
                e.end->next = p2;
                e.end = e2.end;
                return e;
            }
            if (p2 == NULL)
            {
                e.end->next = p1;
                e.end = e1.end;
                return e;
            }
        }
    }
    return e;
}
int main()
{
    expression e1,e2,e3;
    e1.append(10, 4);
    e1.append(3, 2);
    e1.append(4,3);
    e1.append(1,0);
    e2.append(2,3);
    e2.append(1,4);
    e2.append(4,2);
    e1.print();
    e2.print();
    e3=add(e1,e2);
    e3.print();
    return 0;
}