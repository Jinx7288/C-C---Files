#include<stdio.h>
int N,M;
#define Max 1000001
long long xi[Max];

long long getmax(){
 int w=1,sum=0,rear = M+1;
 long long max=0,res=0;
 while(w<=M){
  res = max += w*xi[w];
  sum += xi[w];
  w++;
 }
 for(int i = 1;i<N-M+1;i++){
  res = res - sum + xi[rear]*M;
  if(res > max) max = res;
  sum = sum - xi[i] + xi[rear]; 
  rear++; 
 }
 return max;
}

int main(){
 scanf("%d %d",&N,&M);
 for(int i=1;i<=N;i++){
  scanf("%lld",&xi[i]);
 }
 printf("%lld\n",getmax());
 return 0;
}