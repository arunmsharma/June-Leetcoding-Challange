//problem link:- https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        if(!n){
            return;
        }
        int m=board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j);
            }
            if(board[n-1][j]=='O'){
                dfs(board,n-1,j);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>&board,int x,int y){
        if(x>=0 and x<board.size() and y>=0 and y<board[0].size() and board[x][y]=='O'){
            board[x][y]='A';
            dfs(board,x,y+1);
            dfs(board,x,y-1);
            dfs(board,x+1,y);
            dfs(board,x-1,y);
        }
    }
};
