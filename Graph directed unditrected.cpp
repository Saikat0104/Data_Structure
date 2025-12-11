#include<iostream>
using namespace std;

struct Graph {
    int **mat;
    int v;

    int Vertices(int vNumber) {
        v = vNumber;
        mat = new int*[v];
        for (int i = 0; i < v; ++i) {
            mat[i] = new int[v];
            for (int j = 0; j < v; j++) {
                mat[i][j] = 0;
            }
        }
    }

    void show() {
        cout << " ";
        for (int i = 0; i < v; i++) {
            cout << (char)(65 + i) << "\t";
        }
        cout << endl;

        for (int i = 0; i < v; i++) {
            cout << (char)(65 + i) << "\t";
            for (int j = 0; j < v; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void DirectedEdge(int s, int d, int w) {
        mat[s][d] = w;
    }

    void unDirectedEdge(int s, int d, int w) {
        mat[s][d] = w;
        mat[d][s] = w;
    }
};

int main() {
    Graph graph;
    graph.Vertices(5);
    graph.DirectedEdge(0, 2, 21);
    graph.DirectedEdge(1, 2, 13);
    graph.DirectedEdge(1, 3, 6);
    graph.DirectedEdge(4, 0, 11);

    graph.unDirectedEdge(0, 1, 0);

    graph.show();

    return 0;
}
