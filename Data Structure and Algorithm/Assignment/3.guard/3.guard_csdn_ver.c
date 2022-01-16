// #include<stdio.h>
// int dp[1000005],x[1000005],ans[1000005];
// int main()
//  {
//      int n,m,k,max;
//        int  i,j;
//      while(~scanf("%d%d",&n,&m))
//      {
//               k=0;
//               ans[0]=0;dp[0]=0;
//            for(i=1;i<=n;i++)
//            {
//                 scanf("%d",&x[i]);
//                 if(i<=m)
//                   {
//                      ans[k]+=x[i];
//                      dp[k]+=i*x[i];
//                      max=dp[k];
//                   }
//                  else
//                    {
//                        k++;
//                        ans[k]=ans[k-1]-x[i-m]+x[i];
//                        dp[k]=dp[k-1]-ans[k-1]+x[i]*m;
//                       if(max<dp[k])
//                           max=dp[k];
//                    }
//            }
 
//             printf("%d\n",max);
//      }
//      return 0;
//  }