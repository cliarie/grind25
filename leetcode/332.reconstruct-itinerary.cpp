class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> routes;
    void dfs(string airport){
        while (graph[airport].size()){
            auto next = *(graph[airport].begin()); // multiset must erase only one element, not all elements of the value
            graph[airport].erase(graph[airport].begin());
            dfs(next);
        }
        routes.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // try arbitrary path until cannot find, then that is the end, keep doing
        for (auto v : tickets){
            graph[v[0]].insert(v[1]);
        }
        dfs("JFK");
        reverse(routes.begin(), routes.end());
        return routes;
    }
};
