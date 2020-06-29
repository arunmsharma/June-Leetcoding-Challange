class Solution {
private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> outgoing;
    
    void hierholzer(const string& curr, vector<string>& itinerary) {
        while (outgoing[curr] > 0) {
            hierholzer(graph[curr][--outgoing[curr]], itinerary);
        }
        
        itinerary.push_back(curr);
    }
    
public:
    vector<string> findItinerary(const vector<vector<string>>& tickets) {
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
            ++outgoing[ticket[0]];
        }
        
        // Ensure smallest lexical eulerian path is found
        for (auto& kv : graph) {
            sort(kv.second.begin(), kv.second.end(), greater<string>());
        }
        
        vector<string> itinerary;
        hierholzer("JFK", itinerary);
        
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
};
