class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //BFS traversal
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;//rooten index
        int days=0,t=0,cnt=0;//t=total oranges,cnt=total oranges put into queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)t++;
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};//for adj x-y direction
        
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
                int x=q.front().first,y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];//new x and y (adj)
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1)continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty())days++;
        }
        return cnt==t?days:-1;
    }
};
