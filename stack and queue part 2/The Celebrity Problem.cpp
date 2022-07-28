//m1 TLE
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	vector<int> adj[n];//0 to n-1
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(knows(i,j))adj[i].push_back(j);
            if(knows(j,i))adj[j].push_back(i);
        }
    }
    vector<int> indegree(n,0),outdegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
            outdegree[i]++;
        }
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==n-1 && outdegree[i]==0)return i;
    }
    return -1;
}

//m2 (runs on codestudio but will fail when more than 1 id have indegree ==n-1)
int findCelebrity(int n) {
 	int id=0;
    for(int i=1;i<n;i++){
        if(knows(id,i))id=i;
    }
    for(int i=0;i<n;i++){
        if(i!=id && (knows(id,i) || knows(i,id)==0))return -1;
    }
    return id;
}

//m3 stack
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<bits/stdc++.h>
int findCelebrity(int n) {
 	stack<int> st;
    for(int i=0;i<n;i++)st.push(i);
    while(st.size()>1){
        int a=st.top();st.pop();
        int b=st.top();st.pop();
        if(knows(a,b))st.push(b);//finding id of celeb
        else st.push(a);
    }
    int id=st.top();
    for(int i=0;i<n;i++){
        if(knows(id,i))return -1;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(knows(i,id))cnt++;
    }
    return cnt==n-1?id:-1;
}
