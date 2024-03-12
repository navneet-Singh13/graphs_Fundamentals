class Solution {
public:
    bool DFS(int s,vector<bool> &visited,vector<bool> &dfsVisited,vector<vector<int>> &graph){
        visited[s]=true;
        dfsVisited[s]=true;

        vector<int> data=graph[s];
        for(auto x:data){
            if(!visited[x]){
                if(DFS(x,visited,dfsVisited,graph)){
                    return true;
                }
            }
            else if(visited[x]&&dfsVisited[x]){
                return true;
            }
        }
        dfsVisited[s]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      vector<int> ans;
      
      int n=graph.size();
      vector<bool> visited(n,false),dfsVisited(n,false);
      vector<bool> present_cycle(n,false);

      for(int i=0;i<n;i++)
      {
          if(!visited[i]){
              DFS(i,visited,dfsVisited,graph);
          }
      }
      for(int i=0;i<n;i++){
          if(!dfsVisited[i]){
              ans.push_back(i);
          }
      }
      return ans;
    }
};