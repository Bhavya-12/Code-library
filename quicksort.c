#include<stdio.h>
#include<stdlib.h>
void swap(int a[],int i,int j)
{
	int temp = a[i];
	a[i] =a[j];
	a[j]=temp;
}
int divide(int a[],int n,int l,int h)
{
	int pivot = a[l],i=l,j=h;
	while(i<j)
	{
      while(a[i]<=pivot)
	   i++;
	  while(a[j]>pivot)
	   j--; 
	  if(i<j)swap(a,i,j);
	}
	swap(a,l,j);
	return j;
}
void display(int a[],int n)
{
  for(int i =0;i<n;i++)
   printf("%d ",a[i]);
  printf("\n"); 
}
void quicksort(int a[],int n,int l,int h)
{
	   
		  int i=0;
		  if(l<h)
		  {
			int pivot = divide(a,n,l,h);
			quicksort(a,n,l,pivot-1);
	    	quicksort(a,n,pivot+1,h);
		  }
	   
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before quick sort ----\n");
	display(a,n);
	quicksort(a,n,0,n-1);
	printf("After quiuck sort ----\n");
	display(a,n);
	return 0;
}
