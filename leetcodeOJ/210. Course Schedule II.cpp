class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> re, ans;
        unordered_set<int> visited;
        vector<bool> flag(numCourses, false);
        for(int i = 0; i < numCourses; ++i)
            if(!flag[i])
                if(DFS(graph, visited, i, flag, ans))
                    return re;
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto item : prerequisites){
            graph[item.second].insert(item.first);
        }
        
        return graph;
    }
    
    bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag, vector<int>& ans)
    {
        flag[b] = true;
        visited.insert(b);
        for(auto it = matrix[b].begin(); it != matrix[b].end(); ++it)
            if(visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag, ans))
                return true;
        if(find(ans.begin(), ans.end(), b) == ans.end())
            ans.push_back(b);
        visited.erase(b);
        return false;
    }
    
};