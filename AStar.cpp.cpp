#include<iostream>
#include<stdlib.h>

using namespace std;

#define Max 999

class graph
{
struct node //create structure of node
{
int data;
int weight;
node *next;
};
public:
node *head[20];

int Heuristic[20], no, fn, gn;
void display();
void edge_v1_v2(int, int, int);
void Astar(int , int);
};

void graph :: edge_v1_v2(int v1, int v2, int w)
{
node *n, *f, *h;

//creating link from v1 to v2
h = new node;
h->data = v1;
h->next = NULL;

n = new node; //allocate memory for new node
n->data = v2; //assign vertex
n->weight = w;
n->next = NULL; //next link will be NULL

f = head[v1]; //head vertex is v1

if(f == NULL)
{

h->next = n;
head[v1] = h;
}
else
{
while(f->next)
f = f->next;
f->next = n;
}

}

void graph :: display()
{
int i;
node *f;
for(i = 0 ; i < no; i++)
{
cout<<endl;
f = head[i];
while(f)
{
cout<<"\t"<<f->data;
f = f->next;

}
}
}
void graph :: Astar(int src, int goal){
node *f;
gn = 0;
f = head[src];
cout<<"\n Shortest Path is :";
cout<<src<<"\t";
while(src != goal){
f = head[src];
f = f->next;
fn = Max;
while(f){
if(fn > (gn + f->weight + Heuristic[f->data])){
gn = gn + f->weight;
fn = gn + Heuristic[f->data];
src = f->data;
}
f = f->next;
}
cout<<src<<"\t";
}
}

int main()
{
graph g;
int i, v1, v2, w;
char ch;

cout<<"\n Enter the number of vertices in graph:";
cin>>g.no;
cout<<"\n Enter the heuristic value of each vertex:";
for(i = 0; i<g.no; i++)
{
g.head[i] = NULL;
cout<<"\n Heuristic["<<i<<"]=";
cin>>g.Heuristic[i];
}

cout<<"\n Now you have to enter vertices of an edge"
<<"\n The vertices label as 0 to "<<g.no-1<<endl;

do{
cout<<"\n Enter edge & weight(V1, V2, W)";
cin>>v1>>v2>>w;

g.edge_v1_v2(v1, v2, w);

//g.edge_v2_v1(v1, v2);

cout<<"\n Do u want more edge(y/n)";
cin>>ch;
}while(ch == 'y');

cout<<"\n The adjacency list of the graph is \n";
g.display();
g.Astar(0,5);
return 0;
}