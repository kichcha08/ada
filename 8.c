#include<stdio.h>
int x[10],w[10],d,count=0;
void subset(int cs,int k,int r){
int i;
x[k]=1;
if(cs+w[k]==d){
printf("\n\nSubset %d\n",++count);
for(i=0;i<=k;i++)if(x[i]==1)printf("%d\t",w[i]);
}
else if(cs+w[k]+w[k+1]<=d)
subset(cs+w[k],k+1,r-w[k]);
if(cs+r-w[k]>=d&&cs+w[k]<=d){
x[k]=0;
subset(cs,k+1,r-w[k]);
}
}
void main(){
int i,n,sum=0;
printf("Enter the no.ofelements:");
scanf("%d",&n);
printf("\nEnter the elements in ascending order:\n");
for(i=0;i<n;i++)scanf("%d",&w[i]);
printf("\nEnter the sum:");
scanf("%d",&d);
for(i=0;i<n;i++)sum+=w[i];
if(sum<d){printf("No solution\n");return;}
subset(0,0,sum);
if(count==0)printf("No solution\n");
}
