/*  NASA Space Apps Challenge 2021
    AirSecure: Path Optimizer
    Developed by: Nahvin Muthusamy  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// number of points is initialized with variable POINTS (can be modified according to problem space) <=================
#define POINTS 4

// vector minPoints stores the sequence of points with miminum distance
vector<int> minPoints;

// variable minDistance stores the minimum distance
int minDistance;

void shortestPath(int graph[][POINTS])
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    
    for (int i = 0; i < POINTS; i++)
        if (i != 0)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
        vector<int> points;
        points.push_back(0);
        int current_pathweight = 0;

        int k = 0;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            
            k = vertex[i];
            points.push_back(k);
        }
        current_pathweight += graph[k][0];

        // update minimum
        min_path = min(min_path, current_pathweight);
        if (min_path == current_pathweight) {
            points.push_back(0);
            minPoints = points;
        }
        points.clear();
    } while (
        next_permutation(vertex.begin(), vertex.end()));

    minDistance = min_path;
}

// Main Code
int main()
{
    // matrix representation of distance between points (can be modified according to problem space) <=================
    int graph[][POINTS] = { { 0, 32, 55, 27 },
                          { 32, 0, 33, 66 },
                          { 55, 33, 0, 13 },
                          { 27, 66, 13, 0 } };
    int count = 0;
    shortestPath(graph);
    // display shortest path
    cout << "Shortest path: ";
    for (auto i : minPoints) {
        cout << i;
        if( count++ < POINTS)
            cout << " - ";
    }
    // display minimum distance
    cout << "\nDistance: " << minDistance << endl;
    return 0;
}