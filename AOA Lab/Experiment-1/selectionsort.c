			//Exp No. 1: IMPLEMENTATION OF SELECTION SORT.//

//Name: AMEY MAHENDRA THAKUR//

#include<stdio.h>
int main()
{
   int i, j, count, temp, num[25];
   printf("\tSELECTION SORT:\t\n");
   printf("\nENTER NUMBER OF ELEMENTS TO BE ENTERED: \n");
   scanf("%d",&count);

   printf("\nEnter %d elements: \n", count);

   for(i=0;i<count;i++)			// loop for storing the input numbers in array
      {
		  scanf("%d",&num[i]);
	  }
 
   for(i=0;i<count;i++)			// Logic of selection sort algorithm
   {			   
      for(j=i+1;j<count;j++)
      {
         if(num[i]>num[j])
         {
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
         }
      }
   }

   printf("\nSORTED LIST USING SELECTION SORT IS: \n");
   
   for(i=0;i<count;i++)			// loop for printing the sorted list
	{
		printf(" %d",num[i]);
	}
     
   return 0;
}
