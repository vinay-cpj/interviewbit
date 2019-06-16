int Solution::trap(const vector<int> &A) {
      int n= A.size();
        if(n<3) return 0;
        vector<int> lh(n,0);
        vector<int> rh(n,0);
        lh[0]=-1;
        rh[n-1]=-1;
        for(int i=1;i<n;i++)
            lh[i]=max(lh[i-1],A[i-1]);
        for(int i=n-2;i>0;i--)
            rh[i]=max(rh[i+1],A[i+1]);
        int res=0;
        int buf=0;
        for(int i=1;i<n-1;i++)
        {
           buf = min(lh[i],rh[i]);
           if(buf-A[i]>=0)  res+=(buf-A[i]);
        }
        return res;
}
