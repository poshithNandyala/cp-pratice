class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int sum=0,n=a.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
             sum+=a[i];
             mx=max(mx,sum);
             if(sum<0){
                sum=0;
             }
        }
        return mx;
    }

};