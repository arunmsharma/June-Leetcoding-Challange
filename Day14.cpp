int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<vector<int>>> adjList(101);
        
        for(auto f : flights) {
            int from = f[0];
            int to = f[1];
            int cost = f[2];
            adjList[from].push_back({to, cost, 0});
        }
        
        
        queue<vector<int>> q;
        
        q.push({src, 0, -1});
        //Note : if {A, B} are two directly connected cities, then number of stops b/w them is Zero,
        //so for convenience i'm assuming number of stops b/w A and A as -1
        
     int minCost = INT_MAX;   //this keeps track of minimum cost
    
        
     while(!q.empty()) {
            vector<int> curStation = q.front(); q.pop();
         
            int curCity = curStation[0];
            int curCost = curStation[1];
            int curK = curStation[2];      //this is the number of stops seen so far from source to current city
         
            if(curCity == dst) {
              minCost = min(minCost, curCost);
              continue;  
            }
             
         
            for(auto p : adjList[curCity]) {
                if(curK+1 <= k and curCost + p[1] < minCost)
                q.push({p[0], p[1] + curCost, curK+1});
            } 
         
     }   
        
     return minCost==INT_MAX?-1:minCost;   
    }
	

