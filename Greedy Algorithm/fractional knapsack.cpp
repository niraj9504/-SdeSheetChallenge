// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item &a,Item &b){
        double x=(double)a.value/a.weight;
        double y=(double)b.value/b.weight;
        return x>y;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double ans=0.0;int i=0;
        while(W>=0 && i<n){
            if(W>arr[i].weight){
                W-=arr[i].weight;
                ans+=arr[i].value;
            }
            else{
                ans+=((double)arr[i].value/arr[i].weight)*(double)W;
                break;
            }
            i++;
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
