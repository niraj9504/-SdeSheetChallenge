long long multiply(long long m,long long n,int limit){
	    long long ans=1;
	    for(int i=1;i<=n && ans<=limit;i++){
	        ans*=m;
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{   
	    long long l=1,h=m;
	    while(l<=h){
	        long long mid=(l+h)/2;
	        long long x=multiply(mid,n,m);
	        if(x==m){
	            return mid;
	        }
	        else if(x>m){
	            h=mid-1;
	        }
	        else{
	            l=mid+1;
	        }
	        //cout<<"ans="<<x<<" "<<"h="<<h<<" "<<"l="<<l<<" mid="<<mid<<"\n";
	    }
	    return -1;
	}  
