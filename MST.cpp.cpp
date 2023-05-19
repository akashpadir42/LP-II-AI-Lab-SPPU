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
int no;
void display();
void edge_v1_v2(int, int, int);
void Prims();
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
void graph :: Prims()
{
node *p;
int m, min_wt=0;
int v, v1, v2, wt;
int i,j;
int visited[10], vertex[10];

//Initialization
for(i=0; i<no; i++)
{
visited[i]=0; //identify whether vertex visited
vertex[i]=-1; //visited vertex inserted
}
vertex[0] = 0;
visited[0] = 1;
cout<<"\nMinimum Spanning Tree with minimum cost is\n";
cout<<head[0]->data;
for(i = 0; i<no-1; i++) //No. of vertices to visit
{

m = 9999; //set max value to find minimum cost
for(j=0; j<=i;j++) //check all edges of vistited vertex
{
v = vertex[j]; //get element from set of vertex
p = head[v]; //get header node

p = p->next;

while(p) //if p != NULL
{
if(visited[p->data] == 0)//identify whether vertex visited
{
wt = p->weight;
if(m > wt)
{
m = wt;
v1 = v;
v2 = p->data;
}
}
p = p->next;
}
}
cout<<" "<<head[v2]->data;
min_wt += m;
vertex[j] = v2;

visited[v2] = 1;
}
cout<<"\n Minimum cost is "<<min_wt<<endl;
cout<<endl;
}
int main()
{
graph g;
int i, v1, v2, w;
char ch;

cout<<"\n Enter the number of vertices in graph:";
cin>>g.no;

for(i = 0; i<g.no; i++)
g.head[i] = NULL;

cout<<"\n Now you have to enter vertices of an edge"
<<"\n The vertices label as 0 to "<<g.no-1<<endl;

do{
cout<<"\n Enter edge & weight(V1, V2, W)";
cin>>v1>>v2>>w;

g.edge_v1_v2(v1, v2, w);
g.edge_v1_v2(v2, v1, w);

cout<<"\n Do u want more edge(y/n)";
cin>>ch;
}while(ch == 'y');

cout<<"\n The adjacency list of the graph is \n";
g.display();
g.Prims();
return 0;
}