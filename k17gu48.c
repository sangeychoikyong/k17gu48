#include<stdio.h>

int main()
{
	int count,i,n,time;
	int remaining,f=0,t_quantum =6;
	int wt=0,tat=0;
	int at[10],bt[10],rt[10]; 
	printf("Enter the total number of processes:\n");
	scanf("%d",&n);
	remaining = n;
	for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process  %d :\n",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  }
  printf("\n\nProcess\t\t|Turn Around Time\t|Waiting Time\n\n");
  
  for(time=0,count=0;remaining!=0;) 
  { 
    if(rt[count]<=t_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      f=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=t_quantum; 
      time+=t_quantum; 
    } 
    if(rt[count]==0 && f==1) 
    { 
      remaining--; 
      printf("P[%d]\t|\t%d\t\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wt +=time-at[count]-bt[count]; 
      tat +=time-at[count]; 
      f=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  }
  
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n); 
  printf("Average Turnaround Time = %f",tat*1.0/n); 
  
  return 0;
  
}
