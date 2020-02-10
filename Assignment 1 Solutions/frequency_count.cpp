#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[500],sizeA,i,start,end,mid,number,count=0,position;	
	float median;
	
	printf("Enter size of array A: ");
	scanf("%d",&sizeA);
	
	if(sizeA <= 0 || sizeA > 500)
	{
		printf("Invalid Size. Enter a positive integer from 1 to 500.");
		exit(0);
	}
	
	printf("Enter elements of array A in ascending order: \n");
	for(i=0;i<sizeA;i++)
	{
		printf("Enter %d-th element: ",i+1);
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<sizeA-1;i++)
	{
		if(A[i] > A[i+1])
		{
			printf("The input array should be in ascending order.");
			exit(0);
		}
	}
	
	printf("Enter the element to be searched: ");
	scanf("%d",&number);
	
	start = 0;
	end = sizeA-1;
	
	while(start <= end)
	{
		mid=(start+end)/2;
		
		if(A[mid] == number)
		{
			count = 1;
			break;
		}
		else if(number < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	
	position = mid;
	while(A[position-1] == number)
	{
		count++;
		position--;
	}
	
	position = mid;
	while(A[position+1] == number)
	{
		count++;
		position++;
	}
	
	printf("Frequency of %d is: %d",number,count);
	
	return 0;
}
