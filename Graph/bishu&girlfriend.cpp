#include<iostream>
#include<cstring>
using namespace std;

struct Graph
{
    int V,E;
    int **adj;
};
struct Queue
{
    int rear,front,size;
    unsigned capacity;
    int *arr;

};

struct Queue *createQueue(unsigned capacity)
{
        struct Queue* q = new Queue();
        q->capacity =capacity;
        q->front =q->size =0;
        q->rear =q->capacity -1;
        q->arr =new int[100*q->capacity];
        return q;
}

int isempty(struct Queue *q)
{
    return (q->size ==0);
}
int isfull(struct Queue *q)
{
    return (q->size == q->capacity);
}

void enqueue(struct Queue *q,int data)
{
    if(isfull(q))
        return;
    q->rear = (q->rear + 1)%q->capacity;
    q->arr[q->rear] = data;
    q->size++;

}

int dequeue(struct Queue *q)
{
    if(isempty(q))
        return -32767;
    int item = q->arr[q->front];
    q->front = (q->front +1)%q->capacity;
    q->size--;
    return item;
}
struct Graph *matrix()
{
        int u,v;
        struct Graph *g = new Graph();
        cin >> g->V;
        g->E = g->V -1;
        g->adj = new int*[10000*g->V];
        for(int i=0;i < g->V; i++)
            g->adj[i] = new int[10000*g->V];
        for(int i=0;i<g->V;i++) {
            for(int j=0; j<g->V;j++)
                g->adj[i][j] =0;
        }
        for(int i=0;i<g->E;i++) {
            cin>> u >> v;
            g->adj[u-1][v-1] = 1;
            g->adj[v-1][u-1] = 1;
        }

        return g;

}
void bfs(struct Graph *g,struct Queue *q,int src,int *gh)
{
    int visit[g->V];
    memset(visit,0,sizeof(visit));
    int val=0;
    int ind =g->V-1;
    int mx=-1;
    visit[src] =1;
    enqueue(q,src);

    while(!isempty(q)) {

        int u = dequeue(q);
  //      val++;
  //      cout<<u<<" ";
        for(int v=0; v <g->V;v++) {
            if(g->adj[u][v] && visit[v]==0) {
                visit[v]=1;
                enqueue(q,v);

 //               cout<<val<<" ";
 //               cout<<"hello";
                if(gh[v] && ind > v) {
             //           mx=val;
                        ind =v;

                }
            }
        }
    }

    cout<<ind+1;
}
void printmatrix(struct Graph *g)
{
    for(int i=0;i<g->V;i++) {
        for(int j=0;j<g->V;j++) {
            cout<<g->adj[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    struct Graph *g = matrix();
    struct Queue *q =createQueue(10000);
    int qg,q1;
    int gh[g->V];
    memset(gh,0,sizeof(gh));

    cin >>qg;
    for(int i=0;i<qg;i++) {
        cin >>q1;
        gh[q1-1] =1;
    }
 //   printmatrix(g);
    bfs(g,q,0,gh);

    return 0;
}
