#include <bits/stdc++.h>
using namespace std;

int x; // Used to track deepest node in the tree 

// Sets maxCount as maximum distance from node. 
void dfshelper(int node, bool visited[], int count, int &maxcount, list<int>* adj)
{
    visited[node]=true;
    count++;
    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            if(count>=maxcount)
            {
                maxcount=count;
                x=i;
            }
            dfshelper(i, visited, count, maxcount, adj);
        }
    }
}

void dfs( int n, int node, int &maxcount, list<int>* adj)
{
    bool visited[n+1];
    for(int i=1;i<=n;i++) visited[i]=false; //no nodes have been visited, from this particular node
    int count=0; //count of nodes reachable from this node

    dfshelper(node, visited, count+1, maxcount, adj);// Increment count by 1 for visited node 
}

int diameter(int n, list<int>* adj)
{
    int maxcount=0;

    /* DFS from a random node-1, and then see 
    farthest node X from it*/
    dfs(n, 1, maxcount, adj);

    /* DFS from X and check the farthest node 
    from it */
    dfs(n, x, maxcount, adj);

    return maxcount;
}

int main() {
    
    int n = 5; 
  
    /* Constructed tree is 
         1 
        / \ 
        2    3 
       / \ 
      4   5 */
    list<int>* adj = new list<int>[n + 1]; 
  
    /*create undirected edges */
    adj[1].push_back(2); 
    adj[2].push_back(1); 
    adj[1].push_back(3); 
    adj[3].push_back(1); 
    adj[2].push_back(4); 
    adj[4].push_back(2); 
    adj[2].push_back(5); 
    adj[5].push_back(2); 
  
  
    /* maxCount will have diameter of tree */
    cout << "Diameter of the given tree is "
        << diameter(n, adj) << endl; 
    return 0; 
}
