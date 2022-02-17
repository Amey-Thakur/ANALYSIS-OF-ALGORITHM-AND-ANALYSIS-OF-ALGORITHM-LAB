			//Exp No. 2: IMPLEMENTATION OF BINARY SEARCH.//

//Name: AMEY MAHENDRA THAKUR//


#include<stdio.h>
int main()
{
    int a[50],no,i,s,low,high,index;
    printf("\tBINARY SEARCH:\t\n");
    
    printf("\nENTER NUMBER OF ELEMENTS TO BE ENTERED: \n");
    scanf("%d",&no);
    
    printf("\nEnter %d elements: \n", no);
    for(i=0;i<no;i++)
      scanf("%d",&a[i]);
      
    printf("\nENTER THE KEY ELEMENT TO BE SEARCHED: \n");
    scanf("%d",&s);
    
    low=0;
    high=no-1;
    index=binary_search(a,s,low,high); 		//function call
    if(index==-1)
    printf("\nELEMENT NOT FOUND!\n");
    else
    printf("\nTHE ELEMENT IS FOUND AT THE LOCATION %d\n", index+1);
    
return 0;
}

int binary_search(int a[],int s,int l,int h)		//function for binary search
{
	int mid;
	mid=(l + h)/2;
	if(l<=h)
	{
		if(s==a[mid])
			return mid;
		else if(s<mid)
			return binary_search(a,s,l,mid-1);		//function recursion
		else
			return binary_search(a,s,mid+1,h);		//function recursion
	}
	else
	return -1;
}

      
