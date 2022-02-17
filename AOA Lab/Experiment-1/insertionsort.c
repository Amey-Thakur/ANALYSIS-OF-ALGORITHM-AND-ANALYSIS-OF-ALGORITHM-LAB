			//Exp No. 1: IMPLEMENTATION OF INSERTION SORT.//

//Name: AMEY MAHENDRA THAKUR//


#include<stdio.h>
int main()
{
   int i, j, count, temp, num[25];
   printf("\tINSERTION SORT:\t\n");
   printf("\nENTER NUMBER OF ELEMENTS TO BE ENTERED: \n");
   scanf("%d",&count);

   printf("\nEnter %d elements: \n", count);
      
   for(i=0;i<count;i++)			   // loop for storing the input numbers in array
      {
		  scanf("%d",&num[i]);
	  }

   for(i=1;i<count;i++)			   // Logic of insertion sort algorithm
   {
      temp=num[i];
      j=i-1;
      
      while((temp<num[j])&&(j>=0))
      {
         num[j+1]=num[j];
         j=j-1;
      }
      
      num[j+1]=temp;
   }

   printf("\nSORTED LIST USING SELECTION SORT IS: \n");			// loop for printing the sorted list
   
   for(i=0;i<count;i++)
	{
		printf(" %d",num[i]);
	}

   return 0;
}
