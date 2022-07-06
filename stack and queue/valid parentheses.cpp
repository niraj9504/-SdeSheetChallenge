class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[')st.push(it);
            else{
                if(st.empty())return false;
                else{
                    char c=st.top();
                    if((it==')' && c=='(') || (it=='}' && c=='{') || (it==']' && c=='[')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return st.size()==0;
    }
};
