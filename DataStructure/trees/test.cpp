#include<iostream>
using namespace std;
struct node {  // right>=parent>left
    int value;
    node *right, *left;
};
node **give(node *&a){
    return &a;
}
int main(){
    node *root;
    root=(node*)malloc(sizeof(node));
    root->left=NULL;
    root->right=NULL;
    root->value=1;
    node ** a=give(root->left);
    *a=(node*)malloc(sizeof(node));
    (*a)->value=10;
    cout<<root->value<<" "<<root->left->value;
    return 0;
}