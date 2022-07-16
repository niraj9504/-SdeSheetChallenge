#include<bits/stdc++.h>
void sortedinsert(stack<int> &st,int x){
    if(st.empty() || st.top()<x && !st.empty()){
        st.push(x);
        return;
    }
    int n=st.top();
    st.pop();
    sortedinsert(st,x);
    st.push(n);
}
void sortStack(stack<int> &st)
{
	if(st.empty())return;
    int x=st.top();
    st.pop();
    sortStack(st);
    sortedinsert(st,x);
}
