//m1 O(n) time and space
class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        int n=s.size();
        stack<string> st;
        string word="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(word.size())  //*****
                st.push(word);
                word="";
            }
            else{
                word+=s[i];
            }
        }
        string ans="";
        while(st.size()!=1){
            ans+=st.top()+" ";
            st.pop();
        }
        ans+=st.top();
        return ans;
    }
};

//m2 space can be optimised to O(1)
class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=s.size()-1;
        string ans="",temp="";
        while(l<=r){
            char ch=s[l];
            if(ch!=' '){
                temp+=ch;
            }
            else {
                if(temp.size()){ ///******
                    if(ans!="")ans=temp+" "+ans;
                    else ans=temp;
                }
                temp="";
            }
            l++;
        }
        if(temp!=""){
            if(ans!="")ans=temp+" "+ans;
            else ans=temp;
        }
        return ans;
    }
};
