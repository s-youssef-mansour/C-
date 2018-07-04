#include<iostream>
#include <bits/stdc++.h>

using namespace std;

#define neig(u, e, v) for(int e = head[u], v ; v = to[e], ~e ; e = nxt[e])

const int N=10000,M=20000;

int head[N], nxt[M], to[M], ne, n, depth, maxi, node;

void init(){
    memset(head,-1,n*sizeof head[0]);
    ne = 0;
}
void addEdge(int u, int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}
void addBiEdge(int a, int b){
    addEdge(a, b);
    addEdge(b,a);
}

void DFS(int u, int pe){
    depth++;
    if (depth>maxi){
        maxi = depth;
        node = u;
    }
    neig(u,e,v){
        if (e==pe) continue;
        DFS(v,e^1);
    }
    depth--;
}

int main(){
    cin>>n;
    init();
    int a,b;
    for (int i = 0;i<n-1;++i){
        cin>>a>>b;
        addBiEdge(a-1,b-1);
    }
    depth = -1;
    DFS(0,-1);
    depth = -1;
    DFS(node,-1);
    cout<<maxi;
}
