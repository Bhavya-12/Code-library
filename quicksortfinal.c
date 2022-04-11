#include<stdio.h>
#include<stdlib.h>
void display(int array[],int n)
{
  for(int i =0;i<n;i++)
   printf("%d ",array[i]);
  printf("\n"); 
}
void swap(int array[],int i,int j,int n)
{
	int temp = array[i];
	array[i] =array[j];
	array[j]=temp;
//	printf("-----------------\n%d %d\nArray is : ",array[i],array[j]);
//	display1(array,n);

}
int divide(int array[],int n,int l,int h)
{
	int pivot = array[l],i=l,j=h;
	while(i<j)
	{
      while(array[i]<=pivot && i<h)
	   i++;
	  while(array[j]>pivot)
	   j--; 
	  if(i<j)swap(array,i,j,n);
	}
	swap(array,l,j,n);
	return j; 
}
void quick(int array[],int n,int l,int h)
{
	   
		 // int i=0;
		
		  if(l<h)
		  {
			int pivot = divide(array,n,l,h);
		//	printf("pivot = %d\n i =  %d\nj =  %d\n",array[pivot],array[l],array[h]);
			quick(array,n,l,pivot-1);
	    	quick(array,n,pivot+1,h);
		  }
	   
}

int main()
{
	int n;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before quick sort ----\n");
	display(a,n);
	quick(a,n,0,n-1);
	printf("After quiuck sort ----\n");
	display(a,n);
	return 0;
}
