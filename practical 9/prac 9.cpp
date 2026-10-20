#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int n;



void DFS(int building) {

    cout << building << " ";
    visited[building] = 1;

    for (int i = 0; i < n; i++) {

        if (graph[building][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int start) {

    int Queue[10];

    int Front = 0;
    int Rear = 0;

    Queue[Rear] = start;
    Rear++;

    visited[start] = 1;

    while (Front < Rear) {

        int building = Queue[Front];
        Front++;

        cout << building << " ";

        for (int i = 0; i < n; i++) {

            if (graph[building][i] == 1 && visited[i] == 0) {

                Queue[Rear] = i;
                Rear++;

                visited[i] = 1;
            }
        }
    }
}


int main() {

    int edges;
    int start;

    cout << "Enter number of buildings: ";
    cin >> n;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter the roads:\n";

    for (int i = 0; i < edges; i++) {

        int a, b;

        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    cout << "Enter starting building: ";
    cin >> start;



    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "DFS: ";
    DFS(start);
    cout << endl;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "BFS: ";
    BFS(start);
    cout << endl;


    return 0;
}
