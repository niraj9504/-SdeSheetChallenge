#include<bits/stdc++.h>
using namespace std; 
// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job &a,Job &b){
        if(a.profit!=b.profit)return a.profit>b.profit;
        return a.dead<b.dead;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int cnt=0,sum=0;
        int maxi=0;
        for(int i=0;i<n;i++)maxi=max(maxi,arr[i].dead);
        vector<int> v(maxi+1,-1);
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(v[j]==-1){
                    v[j]=i;
                    cnt++;
                    sum+=arr[i].profit;
                    break;
                }
            }
        }
        return {cnt,sum};
    } 
};
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
