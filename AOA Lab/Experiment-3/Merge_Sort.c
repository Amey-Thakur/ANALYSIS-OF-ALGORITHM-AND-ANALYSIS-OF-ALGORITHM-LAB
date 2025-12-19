			//Exp No. 3: IMPLEMENTATION OF MERGE SORT.//

//Name: AMEY MAHENDRA THAKUR//


int main() 
{ 
	int arr[50],i,n;
	printf("\n\tMERGE SORT\t\n\nEnter the range of no: ");
	scanf("%d",&n);
	printf("\nEnter the no: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
		}
	int size = n; 
	printf("\nGiven array is \n"); 
	printArray(arr, size); 
	divide(arr, 0, size - 1); 
	printf("\nSorted array is \n"); 
	printArray(arr, size); 
	return 0; 
} 
void printArray(int A[], int size) 	//PRINT FUNCTION
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 
void divide(int arr[], int l, int h) 	//DIVIDE FUNCTION
{ 
	if (l < h) 
	{ 
		int m = l+(h-l)/2; 
		divide(arr, l, m); 		//DIVIDE FUNCTION CALL
		divide(arr, m+1, h); 	//DIVIDE FUNCTION CALL
		merge(arr, l, m, h); 	//MERGE FUNCTION CALL
	} 
} 
void merge(int arr[], int l, int m, int h) 		//MERGE FUNCTION
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = h - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	i = 0; 
	j = 0;  
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
