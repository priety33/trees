/*Find the apples from the end and check where you come from, then, let the start point of edge true(as an apple). 
Finally, count the number of edge you need to go through and it cost 2 seconds for each edge(back and forth).*/

/* n-ary tree
 test-case
 8
[[0,1],[1,2],[2,3],[1,4],[2,5],[2,6],[4,7]]
[true,true,false,true,false,true,true,false]
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int cnt = 0;
        for(int i=edges.size()-1; i>=0; i--){
            if(hasApple[edges[i][1]]){
                cnt++;
                hasApple[edges[i][0]] = true;
            } 
        }
        return cnt*2;
    }
};
