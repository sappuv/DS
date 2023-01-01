#include <iostream.h>
#include <conio.h>
#define INT_MAX 2147483647


int miniDist(int distance[], int visited[]) {
  int minimum = INT_MAX, ind;
  for (int k = 0; k < 6; k++) {
    if (visited[k] == 0 && distance[k] <= minimum) {
      minimum = distance[k];
      ind = k;
    }
  }
  return ind;
}


void DijkstraAlgo(int graph[6][6], int src) {

  int distance[6];
  int visited[6];
  for (int i = 0; i < 6; i++) {
    distance[i] = INT_MAX;
    visited[i] = 0;
  }

  distance[src] = 0;

  for (int l = 0; l < 6; l++) {

    int m = miniDist(distance, visited);

    visited[m] = 1;
   for (int k = 0; k < 6; k++) {
      if (visited[k] == 0 && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k]) {
	distance[k] = distance[m] + graph[m][k];
      }
    }
  }

  cout << "Vertex\t\tDistance from source vertex" << endl;
  for (int o = 0; o < 6; o++) {
    char str = 65 + o;
    cout << str << "\t\t\t" << distance[o] << endl;
  }
}

int main() {
clrscr();

  int graph[6][6] = {{0, 1, 2, 0, 0, 0},
		     {1, 0, 0, 5, 1, 0},
		     {2, 0, 0, 2, 3, 0},
		     {0, 5, 2, 0, 2, 2},
		     {0, 1, 3, 2, 0, 1},
		     {0, 0, 0, 2, 1, 0}};

  DijkstraAlgo(graph, 0);
  getch();
  return 0;
}
