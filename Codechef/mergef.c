#include<stdio.h>
#include<time.h>
//long long count=0;
void Merge(int n, float array[n], int s , int mid, int e)
{
	float temp[n];
	int i=s;
	int j=mid+1;
	int k=s;
	while(i<=mid && j<=e)
	{
//		count = count+2;
		if(array[i]<array[j])
		{
//			count++;
			temp[k] = array[i];
			k++;
			i++;
		}
		else
		{
			
			temp[k] = array[j];
			k++;
			j++;
		} 	
	}
	while(i<=mid)
	{
//		count++;
		temp[k] = array[i];
		k++;
		i++;
	}
	while(j<=e)
	{
//		count++;
		temp[k] = array[j];
		k++;
		j++;
	}
	for(i=s;i<=e;i++)
	{
		array[i] = temp[i];
	}
}
void Msort( int n ,float array[n], int s, int e)
{	
	if(s==e)
	{
//		count++;
		return;
	}
	int mid = (s+e)/2;
	Msort(n,array,s,mid);
	Msort(n,array,mid+1,e);
	Merge(n,array,s,mid,e);
}
int main()
{
	
	int n= 100000;double sum=0;
	float array[n];
	int p,u,repeat=1000;float d;
	for(u=1;u<=repeat;u++)
	{
		for(p=0;p<n;p++)
		{
			d = (float)(rand()%n)/(float)n;
		
			array[p] = d;
		}
		int i;
		clock_t tStart = clock();	
		Msort(n,array,0,n-1);
		double temp= (double)(clock() - tStart)/CLOCKS_PER_SEC;
		sum = sum+temp; 
	//	printf("sum = %lf\n",sum);
	//	 printf("Execution Time: %lfs\n", temp);
	}
	
   
    printf("Average Time: %lf\n",((double)sum)/((double)repeat));
 //   printf("number of comparisons: %lld\n",count);
   //  printf("Average comparisons: %lf\n",(double)count/(double)repeat);
 return 0;
}
