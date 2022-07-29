class Solution {
public:
    int myAtoi(string s) {
        int sign=1,ans=0,i=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            sign=1;
            i++;
        }
        while(s[i]>='0' and s[i]<='9'){
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 and s[i]-'0'>7)){
                if(sign==1){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }
            ans=ans*10+(s[i++]-'0');
        }
        return sign*ans;
    }
};
