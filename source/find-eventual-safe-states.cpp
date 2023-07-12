class Solution {
public:
    void checkTerminal(vector<int>& isTerminal,
                       vector<vector<int>>& graph, int node, vector<int>& visited)
    {
        if(visited[node]){
            isTerminal[node] = 0;
            return;
        }

        bool flag = 1;

        visited[node] = 1;

        for(int i=0; i<graph.at(node).size(); i++){
            if(isTerminal[graph.at(node).at(i)] == -1)
                checkTerminal(isTerminal, graph, graph.at(node).at(i), visited);
            flag &= isTerminal[graph.at(node).at(i)];   
        }
    
        visited[node] = 0;

        isTerminal[node] = flag;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> isTerminal(graph.size(), -1);
        vector<int> output;

        for(int i = 0; i<graph.size(); i++){
            vector<int> visited(graph.size(), 0);
            checkTerminal(isTerminal, graph, i, visited);
        }

        for(int i=0;i<isTerminal.size();i++){
            if(isTerminal[i]) output.push_back(i);
        }

        return output;
    }
};
