#include <iostream> 
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> matrix; // matriz de adjacência
    int numEdge;                // número de arestas
    vector<int> mark;           // vetor de marcação
    int qtdVertex;


public:

    Graph* createGraph(int n) {

    Graph* graph = new Graph;
    graph -> matrix = vector<vector<int>>(n, vector<int>(n, 0));
    graph -> mark = vector<int>(n, 0);
    graph -> numEdge = 0;
    graph -> qtdVertex = n;

    return graph;
}

    int first(Graph* graph, int v) {
        for (int i = 0; i <= graph -> qtdVertex - 1; i++) {
            if (graph -> matrix[v][i] != 0) {
                return i;
            }
        }
        return graph -> qtdVertex;
    }

    int next(Graph* graph, int v, int w) {
        for (int i = w + 1; i <= graph -> qtdVertex - 1; i++) {
            if (graph -> matrix[v][i]) {
                return i;
            }
        }
        return graph -> qtdVertex;
    }

    void setEdge(Graph* graph, int i, int j, int weight) {
        if (weight == 0) {
            return;
        }
        if (graph -> matrix[i][j] == 0) {
            numEdge++;
            graph -> matrix[i][j] = weight;
        }
    }

    void deleteEdge(Graph* graph, int i, int j) {
        if (graph -> matrix[i][j] != 0) {
            numEdge--;
            graph -> matrix[i][j] = 0;
        }
    }





};