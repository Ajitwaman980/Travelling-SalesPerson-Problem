#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int V = 4;//matrix

int travellingSalesmanProblem(int graph[V][V], int starting_city ) {
    vector<int> vertices;
    for (int i = 0; i < V; i++) {
        if (i != starting_city ) {
            cout<<i<<" ";
            vertices.push_back(i);
        }
    }

    int minPath = INT_MAX;
    vector<int> bestPath;

    do {
        int currentPathWeight = 0;
        int k = starting_city;
        vector<int> currentPath;

        currentPath.push_back(k);

        for (int i = 0; i < vertices.size(); i++) {
            currentPathWeight =currentPathWeight+ graph[k][vertices[i]];
            k = vertices[i];
            currentPath.push_back(k);
        }
        currentPathWeight =currentPathWeight+ graph[k][starting_city];

        currentPath.push_back(starting_city);

        cout << "Distance: " << currentPathWeight << " | Path: ";
        for (int i=0  ;i<currentPath.size();i++) {
            cout << i << "-->";
        }
        cout << endl;

        if (currentPathWeight < minPath) {
            minPath = currentPathWeight;
            bestPath = currentPath;
        }

    } while (next_permutation(vertices.begin(), vertices.end()));

    cout<<"Best path is :[";
    for(int i = 0; i <bestPath.size(); i++){
        cout<<bestPath[i]<< ' ';
    }
   cout << "] Minimum Distance: " << minPath << endl;

    return minPath;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int starting_city = 0; 
    // cout<<endl;
travellingSalesmanProblem(graph, starting_city) ;

    return 0;
}
