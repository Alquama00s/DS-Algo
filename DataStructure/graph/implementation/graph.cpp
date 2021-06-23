#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
struct matrix_graph {
   private:
    int node;
    bool bidirectional = true, changed = false;
    vector<vector<int>> mat;
    void Routine_dfs(int a, vector<bool> &vis, vector<int> &res) {
        vis[a - 1] = true;
        res.push_back(a);
        int n = mat[a - 1].size();
        for (size_t i = 0; i < n; i++) {
            if (i != a - 1 && vis[i] == false && mat[a - 1][i] == 1) {
                Routine_dfs(i + 1, vis, res);
            }
        }
    }
    void Routine_bfs(vector<int> a, vector<bool> &vis, vector<int> &res) {
        vector<int> child;
        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; i < node; j++) {
                if (j != a[i] - 1 && vis[j - 1] == false &&
                    mat[a[i] - 1][j] == 1) {
                    vis[j] = true;
                    res.push_back(j + 1);
                    child.push_back(j + 1);
                }
            }
            Routine_bfs(child, vis, res);
            child.clear();
        }
    }

   public:
    matrix_graph(int n) {
        node = n;
        mat = vector<vector<int>>(n, vector<int>(n, 0));
        for (size_t i = 0; i < node; i++) {
            mat[i][i] = 1;
        }
    }
    void isBidirectional(bool a) {
        if (a == bidirectional) {
            return;
        }
        if (!changed) {
            bidirectional = a;
        } else {
            cout << "error : clear your graph to change this \n";
        }
    }
    void print() {
        for (size_t i = 0; i < node; i++) {
            for (size_t j = 0; j < node; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void add(int a, int b) {
        if (a > node || b > node) {
            cout << "error out of range\n";
            return;
        }
        changed = true;
        mat[a - 1][b - 1] = 1;
        if (bidirectional) {
            mat[b - 1][a - 1] = 1;
        }
    }
    void clear() {
        mat = vector<vector<int>>(node, vector<int>(node, 0));
        for (size_t i = 0; i < node; i++) {
            mat[i][i] = 1;
        }
        changed = false;
        bidirectional = true;
    }

    vector<int> DFS(int a = 1) {
        vector<int> res;
        vector<bool> visits(node, false);
        Routine_dfs(a, visits, res);
        return res;
    }
    vector<int> BFS(int a = 1) {
        vector<int> res;
        vector<int> v_a;
        vector<bool> visits(node, false);
        v_a.push_back(a);
        visits[a - 1] = true;
        res.push_back(a);
        Routine_bfs(v_a, visits, res);
        return res;
    }
};
int main() {
    matrix_graph g(4);
    // g.isBidirectional(false);
    g.add(1, 2);
    g.add(1, 3);
    g.add(3, 4);
    g.add(2, 3);
    g.print();
    print(g.BFS(3));
}
