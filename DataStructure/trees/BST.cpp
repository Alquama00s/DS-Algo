#include <iostream>
#include <queue>
using namespace std;
struct node {  // right>=parent>left
    int value;
    node *right, *left;
};
class tree {
    void print2DUtil(node *n, int space) {
        // Base case
        if (n == NULL) {
            return;
        }

        // Increase distance between levels
        space += 10;

        // Process right child first
        print2DUtil(n->right, space);

        // Print current node after space
        // count
        cout << endl;
        for (int i = 10; i < space; i++) cout << " ";
        cout << n->value << "\n";

        // Process left child
        print2DUtil(n->left, space);
    }
    node **_find(int a, node *&l) {
        if (l == NULL) {
            return &l;
        } else if (a >= l->value) {
            return _find(a, l->right);
        } else {
            return _find(a, l->left);
        }
    }

   public:
    node *root;
    tree() { root = NULL; }
    node *newNode(int val) {
        node *a = (node *)malloc(sizeof(node));
        a->value = val;
        a->right = NULL;
        a->left = NULL;
        return a;
    }
    node *find(int a, node *l, node *prev) {
        if(prev->value==a){
            return prev;
        }
        if (l == NULL) {
            return prev;
        } else if (a >= l->value) {
            return find(a, l->right, l);
        } else {
            return find(a, l->left, l);
        }
    }
    node *findMin(node *val) {
        node *ptr = val;
        while (ptr->left != NULL) {
            ptr = ptr->left;
        }
        return ptr;
    }
    node *findParent(int data, node *pt) {
        if (pt == NULL) {
            return pt;
        }
        if (data == pt->left->value || data == pt->right->value) {
            return pt;
        }
        if (data > pt->value) {
            return findParent(data, pt->right);
        } else {
            return findParent(data, pt->left);
        }
    }
    node *findParent(node *add,node *point){
        node *par=point;
        if(par==NULL){
            return par;
        }
        if(par->left==add || par->right==add){
            return par;
        }else if(add->value>par->value){
            return findParent(add,point->right);
        }else{
            return findParent(add,point->left);
        }
    }
    void remove(int data,node *point) {
        node *pt = find(data, point, point);
        if (pt->value == data) {
            node *par = findParent(pt->value,root);
            if (pt->left == NULL && pt->right == NULL) {
                if (data > par->value) {
                    par->right = NULL;
                } else {
                    par->left = NULL;
                }
                free(pt);
                return;
            }else if(pt->left == NULL){
                if (data > par->value) {
                    par->right = pt->right;
                } else {
                    par->left = pt->right;
                }
                free(pt);
                return;
            }else if(pt->right == NULL){
                if (data > par->value) {
                    par->right = pt->left;
                } else {
                    par->left = pt->left;
                }
                free(pt);
                return;
            }else{
                node *rep=findMin(pt->right);
                pt->value=rep->value;
                node *rep_par=findParent(rep,root);
                rep_par->right = rep->right;
                free(pt);
                return;
            }
        }
    }
    void insert(int val) {
        node **n = _find(val, root);
        *n = (node *)malloc(sizeof(node));
        (*n)->value = val;
        (*n)->right = NULL;
        (*n)->left = NULL;
    }
    void preOrder(node *val) {
        if (val == NULL) {
            return;
        }
        cout << val->value << " ";
        preOrder(val->left);
        preOrder(val->right);
    }
    void postOrder(node *val) {
        if (val == NULL) {
            return;
        }
        postOrder(val->left);
        postOrder(val->right);
        cout << val->value << " ";
    }
    void inOrder(node *val) {
        if (val == NULL) {
            return;
        }
        inOrder(val->left);
        cout << val->value << " ";
        inOrder(val->right);
    }
    void levelOrder(node *val) {
        if (val == NULL) {
            return;
        }
        queue<node *> s;
        s.push(val);
        node *temp;
        while (!s.empty()) {
            temp = s.front();
            s.pop();
            cout << temp->value << " ";
            if (temp->left) s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }
    }
    void print() {
        print2DUtil(root, 0);
        cout << "--------------------------------------------------------------"
                "-----\n";
    }
};
int main() {
    tree t;
    node *pt;
    int a[] = {1,11,2,5,16,31};
    for (size_t i = 0; i < 7; i++) {
        t.insert(a[i]);
    }
    t.print();
    // pt=t.findMin(t.root->right);
    // cout<<pt->value<<" min \n";
    // pt=t.find(8,t.root,t.root);
    // cout<<pt->value<<" find operation\n";
    // t.print();
    // t.insert(9);
    // t.print();
    // t.preOrder(t.root);
    // cout<<"\n";
    // t.postOrder(t.root);
    // cout<<"\n";
    t.inOrder(t.root);
    cout<<"\n";
    // t.levelOrder(t.root);
    // cout<<"\n";
    //  t.remove(3,t.root);
    // t.print();
    return 0;
}