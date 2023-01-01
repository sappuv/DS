#include <iostream.h>
#include <string.h>
#include <conio.h>
class Graph
{
    char Vnames[10][10];
    int cost[10][10], no;

public:
    Graph();
    void creat_graph();
    void display();
    int Position(char[]);
    void prims();
};
Graph::Graph()
{
    no = 0;
    for (int i = 0; i < 10; i++)
	for (int j = 0; j < 10; j++)
	{
	    if (i == j)

		cost[i][j] = 0;

	    else

		cost[i][j] = 999;
	}
}
void Graph::creat_graph()
{
    char ans, Start[10], End[10];
    int wt, i, j;
    cout << "Enter number of departments: ";
    cin >> no;
    cout << "\nEnter department names: ";
    for (i = 0; i < no; i++)
	cin >> Vnames[i];
    do
    {
	cout << "\nEnter Start and end departments for edge: ";
	cin >> Start >> End;
	cout << "Enter weight: ";
	cin >> wt;
	i = Position(Start);
	j = Position(End);
	cost[j][i] = cost[i][j] = wt;
	cout << "\nMore Edges? (Y/N):  ";
	cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
void Graph::display()
{
    int i, j;
    cout << "\nAdjecancy Matrix\n\t";
    for (i = 0; i < no; i++)

	cout << "\t" << Vnames[i];

    for (i = 0; i < no; i++)

    {
	cout << "\n\t" << Vnames[i];
	for (j = 0; j < no; j++)
	    cout << "\t" << cost[i][j];
    }
}
int Graph::Position(char S[10])
{
    int i;
    for (i = 0; i < 10; i++)
	if (strcmp(Vnames[i], S) == 0)
	    break;
    return i;
}

void Graph::prims()
{
    int c = 1, b, i, j, x, y, min_cost = 0, min, v[10] = {0};
    char start[10] = "\0";
    cout << "\nfrom which Department you want to start: ";
    cin >> start;
    b = Position(start);

    v[b] = 1;
    cout << "\nDept1\tDept2\tDistance";
    while (c < no)

    {
	min = 999;
	for (i = 0; i < no; i++)
	{
	    if (v[i])
	    {
		for (j = 0; j < no; j++)
		{
		    if (cost[i][j] < min && v[j] == 0)
		    {
			min = cost[i][j];
			x = i;
			y = j;
		    }
		}
	    }
	}

	cout << "\n"
	     << Vnames[x] << "\t" << Vnames[y] << "\t" << min;
	min_cost += min;
	cost[x][y] = cost[y][x] = 999;
	v[y] = 1;
	c++;
    }
    cout << "\nMinimum Total cost: " << min_cost<< endl;
}

int main()
{
    clrscr();
    Graph G;
    G.creat_graph();
    G.prims();
    G.display();
    getch();
}