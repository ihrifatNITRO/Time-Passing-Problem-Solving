/* By the name of ALLAH */
/// Topological sort is only valid for directed graph.
/// This directed graph must be a tree.
/// Here, we have to sort/visit the graph in a way
/// where every parent nodes will be on the front of
/// the sorted list/vector before their child nodes.
/// We will use dfs to do this process.
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

#define Max 300000
vector<int>g[Max];
int vis[Max];
/// Declaring a vector to store elements
vector<int>A;

void dfs(int u)
{
   vis[u] = 1;
   for(auto v : g[u]){
      if(vis[v] == 1){continue;}
      if(vis[v] == 0){
         dfs(v);
      }
   }
   /// If all the above code finished to execute then,
   /// we will store all the elements on vector A.
   A.push_back(u);
}

// Inputs :
// node = 5 , edge = 4
// 1 2
// 3 2
// 2 4
// 2 5

int main()
{
   int node,edge;
   cin >> node >> edge; // Taking inputs of nodes and edges number

   for(int i=0;i<edge;i++){ // Taking inputs of the connections of nodes
      int a,b;
      cin >> a >> b;
      g[a].push_back(b); // As it is a directed graph
   }

   for(int i=1;i<=node;i++){
      if(vis[i] == 0){
         dfs(i);
      }
   }

   // After dfs our list will look like this :
   // 4 , 5 , 2 , 1 , 3

   reverse(A.begin() , A.end()); // Now, we are reversing the vector.

   for(auto i : A){    // Printing the vector.
      cout << i << " ";
   }

   // Our topological sorted vector will look like this :
   // 3 , 1 , 2 , 5 , 4

   return 0;
}
