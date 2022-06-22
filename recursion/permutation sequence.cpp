//method 1(not use this in interview)
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        int x;
        k--;
        while(k--){
            next_permutation(v.begin(),v.end());
        }
        string s="";
        for(int i=0;i<n;i++){
            s+=(v[i]+'0');
        }
        return s;
    }
};
//m2
class Solution {
public:
    string getPermutation(int n, int k) {
        string temp="";
        int fact=1;
        for(int i=1;i<n;i++){//we need fact of n-1 only -> 4*(3*2*1)
            temp+=i+'0';
            fact*=i;
        }
        temp+=n+'0';
        string ans="";k-=1;//(0-based indexing)
        while(1){
            ans+=temp[k/fact];
            temp.erase(temp.begin()+k/fact);
            if(temp.size()==0)break;            
            k%=fact;
            fact/=temp.size();
        }
        return ans;
    }
};
