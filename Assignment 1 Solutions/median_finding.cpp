#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

int main()
{
	int A[500],B[500],sizeA,sizeB,i,A1,A2,B1,B2;	
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
	
	printf("Enter size of array B  in ascending order: ");
	scanf("%d",&sizeB);
	
	if(sizeB <= 0 || sizeB > 500)
	{
		printf("Invalid Size. Enter a positive integer from 1 to 500.");
		exit(0);
	}
	
	for(i=0;i<sizeB;i++)
	{
		printf("Enter %d-th element: ",i+1);
		scanf("%d",&B[i]);
	}
	
	for(i=0;i<sizeB-1;i++)
	{
		if(B[i] > B[i+1])
		{
			printf("The input array should be in ascending order.");
			exit(0);
		}
	}
	
	int startA = 0;
	int endA = sizeA;
	
	int partitionA = (startA + endA)/2;
	int partitionB = ((sizeA + sizeB + 1)/2) - partitionA;
	
	if(partitionA-1 < 0)
		A1 = INT_MIN;
	else
		A1 = A[partitionA-1];
		
	if(partitionA >= sizeA)
		A2 = INT_MAX;
	else
		A2 = A[partitionA];
		
	if(partitionB-1 < 0)
		B1 = INT_MIN;
	else
		B1 = B[partitionB-1];
		
	if(partitionB >= sizeB)
		B2 = INT_MAX;
	else
		B2 = B[partitionB];
	
	while(true)
	{
		printf("start=%d	end=%d partitionA=%d	A1=%d	A2=%d	partitionB=%d	B1=%d	B2=%d\n",startA,endA,partitionA,A1,A2,partitionB,B1,B2);
		if(A1<=B2 && B1<=A2)
		{
			if(((sizeA + sizeB)%2) != 0)
			{
				median = (A1 >= B1)? A1 : B1;
			}
			else
			{
				median = (float)(((A1 >= B1)? A1 : B1) + ((A2 <= B2)? A2 : B2))/2;
			}
			break;
		}
		else if(A1 > B2)
		{
			endA = partitionA-1;
			
			partitionA = (startA + endA)/2;
			partitionB = ((sizeA + sizeB + 1)/2) - partitionA;
			
			if(partitionA-1 < 0)
				A1 = INT_MIN;
			else
				A1 = A[partitionA-1];
				
			if(partitionA >= sizeA)
				A2 = INT_MAX;
			else
				A2 = A[partitionA];
				
			if(partitionB-1 < 0)
				B1 = INT_MIN;
			else
				B1 = B[partitionB-1];
				
			if(partitionB >= sizeB)
				B2 = INT_MAX;
			else
				B2 = B[partitionB];
		}
		else
		{
			startA = partitionA+1;
			
			partitionA = (startA + endA)/2;
			partitionB = ((sizeA + sizeB + 1)/2) - partitionA;
			
			if(partitionA-1 < 0)
				A1 = INT_MIN;
			else
				A1 = A[partitionA-1];
				
			if(partitionA >= sizeA)
				A2 = INT_MAX;
			else
				A2 = A[partitionA];
				
			if(partitionB-1 < 0)
				B1 = INT_MIN;
			else
				B1 = B[partitionB-1];
				
			if(partitionB >= sizeB)
				B2 = INT_MAX;
			else
				B2 = B[partitionB];
		}
	}
	
	printf("Median = %0.2f",median);
	
	return 0;
}
