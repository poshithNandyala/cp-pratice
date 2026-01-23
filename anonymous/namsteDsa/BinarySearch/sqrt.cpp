class Solution {
public:
    int mySqrt(int n) {
        if(!n) return n;
       int lo=1,hi=n;
       int ans=n;
       while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid <=n/mid){ //no overflow
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
       }  
       return ans;
    }
};