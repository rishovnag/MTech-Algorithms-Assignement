#include <stdio.h>
#include <stdlib.h>

int count;

int partition(int arr[], int low, int high)
{
	int pivot,i,j,temp;
	pivot = arr[high];
    i = (low - 1); 
  
    for (j = low; j <= high-1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;   
        }  
    }
	temp = arr[high];
	arr[high] = arr[i+1];
	arr[i+1] = temp;  
	 
    return (i+1); 
}

int random_partition(int arr[], int low, int high)
{
	int n,i,temp;
	n = high - low + 1;
	i = low + (rand()%n);
	temp = arr[high];
	arr[high] = arr[i];
	arr[i] = temp;
	
	return partition(arr, low, high);
}

int random_select(int arr[], int low, int high, int k)
{
	int p,i;
	count = count + 1;
	if (low == high)
    {
    	return arr[low];
    }
    
	p = random_partition(arr, low, high);
	i = p - low + 1;
	
	if(k == (i))
	{
		return arr[p];
	}
	else if(k<i)
	{
        return random_select(arr, low, p - 1, k);
    }
    else
    {
        return random_select(arr, p+1, high, k-(i)); 
    }
}

int main()
{
	int *A,*count_1,*count_2,*count_3,*count_4,quartile3,quartile1,quartile2,sizeA,i,median,k,j;
	
	FILE *fptr;
	
	count_1 = (int*) malloc(1000*sizeof(int));
	count_2 = (int*) malloc(1000*sizeof(int));
	count_3 = (int*) malloc(1000*sizeof(int));
	
	fptr = fopen("varying__kth_element_1.txt", "w");
	if(fptr == NULL)
	{
		printf("Error!");
	    exit(1);
	}
	
	for(sizeA=100;sizeA<=600000;sizeA+=100)
	{
		for(j=0;j<1000;j++)
		{
			A = (int*) malloc(sizeA*sizeof(int));
			srand(rand());
			for(i=0;i<sizeA;i++)
			{
				A[i] = rand();
			}
		
			k = (sizeA+1)/4;
			count = 0;
			quartile1 = random_select(A,0,sizeA-1,k);
			count_1[j]=count;
			printf("\nIteration: %d-%d		1st Quartile: %d, k: %d",sizeA,(j+1),quartile1,k);
		
			k = (sizeA+1)/2;
			count = 0;
			quartile2 = random_select(A,0,sizeA-1,k);
			count_2[j]=count;
			printf("		2nd Quartile: %d, k: %d",quartile2,k);
		
			k = (3*(sizeA+1))/4;
			count = 0;
			quartile3 = random_select(A,0,sizeA-1,k);
			count_3[j]=count;
			printf("		3rd Quartile: %d, k: %d",quartile3,k);
		}
		
		count=0;
		for(i=0;i<1000;i++)
		{
			count=count+count_1[i];
		}
		count=count/1000;
		fprintf(fptr,"%d	%d",sizeA,count);
		
		count=0;
		for(i=0;i<1000;i++)
		{
			count=count+count_2[i];
		}
		count=count/1000;
		fprintf(fptr,"	%d",count);
		
		count=0;
		for(i=0;i<1000;i++)
		{
			count=count+count_3[i];
		}
		count=count/1000;
		fprintf(fptr,"	%d\n",count);
	}
	
	fclose(fptr);
	
	return 0;
}
