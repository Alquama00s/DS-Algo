// C++ program to use priority_queue to implement min heap
#include <bits/stdc++.h>
using namespace std;
 
// Driver code
int main ()
{
    // Creates a min heap
    //5, 7, 9, 1, 3, 10, 8, 4
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(5);
    pq.push(7);
    pq.push(9);
    pq.push(1);
    pq.push(3);
    pq.push(10);
    pq.push(8);
    pq.push(4);
 
    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
 
    return 0;
}