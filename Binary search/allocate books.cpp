

bool isPossible(vector<int> a,int mid,int students){
    int cnt=0;
    int sum=0;
    for(int i=0;i<a.size();i++){
        if(sum+a[i]>mid){
            cnt++;
            sum=a[i];
            if(sum>mid)return false;
        }
        else{
            sum+=a[i];
        }
    }
    if(cnt<students)return true;
    return false;
}
int Solution::books(vector<int> &a, int b) {
    int n=a.size();
    if(n<b)return -1;
    if(n==b)return *max_element(a.begin(),a.end());
    int low=a[0],high=0;
    for(auto it:a)high+=it;
    
    while(low<=high){
        int mid=(low+high)>>1;
        if(isPossible(a,mid,b)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
