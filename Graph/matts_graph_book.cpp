#include<iostream>
#include<cstring>
using namespace std;

struct Graph
{
    int V,E;
    int **adj;
};
int mx=0;
struct Graph *matrix()
{
        int u,v;
        struct Graph *g = new Graph();
        cin >> g->V;
        cin>> g->E;
        g->adj = new int*[g->V];
        for(int i=0;i < g->V; i++)
            g->adj[i] = new int[g->V];
        for(int i=0;i<g->V;i++) {
            for(int j=0; j<g->V;j++)
                g->adj[i][j] =0;
        }
        for(int i=0;i<g->E;i++) {
            cin>> u >> v;
            g->adj[u][v] = 1;
            g->adj[v][u] = 1;
        }

        return g;

}

void remove(struct Graph *g,int k)
{
    for(int i=0; i<g->V;i++) {
        if(g->adj[i][k] == 1) {
            g->adj[i][k] =0;
            g->adj[k][i] =0;
        }

    }
}

void dfsUtil(struct Graph *g,int src,int vit[])
{
    vit[src] = 1;
    for(int i=0;i<g->V;i++) {
        if(g->adj[src][i] && vit[i]==0) {

            dfsUtil(g,i,vit);
        }

    }

}
void dfs(struct Graph *g,int k)
{
    int flag;
    int cnt=0;
    int vit[g->V];
    memset(vit,0,sizeof(vit));

    for(int i=0;i<g->V;i++) {
            if(vit[i] == 0 && i!=k) {
                cnt++;
                dfsUtil(g,i,vit);
            }
    }
 //   cout<<cnt;
    if(cnt == 1)
        cout<<"Connected"<<endl;
    else
        cout<<"Not Connected"<<endl;

}
int main()
{
    int k;
    struct Graph *g;
    g= matrix();
    cin >>k;
    remove(g,k);
    dfs(g,k);
 //   cout<<mx;

    return 0;

}

/*
4
3
3 0
0 1
1 2
2
*/
