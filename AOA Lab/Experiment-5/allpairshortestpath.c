			//Exp No. 5: IMPLEMENTATION OF ALL PAIR SHORTEST PATH.//

//Name: AMEY MAHENDRA THAKUR//


#include<stdio.h>

int min(int a, int b)	//FUNCTION FOR FINDING MINIMUM NUMBER.
{
	if (a<b)
	{
		return a;
	}
	return b;	
}
	
void shortest (int m[20][20], int n)
{
	int a[10][20][20],i,j,k;
	
	for(i = 1; i<=n; i++)		//LOOP FOR STORING THE FIRST MATRIX.
	{
		for(j = 1;j<=n;j++)
		{
			a[0][i][j] = m[i][j];
			}
		}
		
	for (k=1; k<=n; k++)		//LOOP FOR CALCULATING THE FINAL MATRIXES.
	{
		for(i = 1; i<=n; i++)
	{
		for(j = 1;j<=n;j++)
		{
			a[k][i][j] = min((a[k-1][i][j]),(a[k-1][i][k] + a[k-1][k][j]));
			}
		}
		}
	for (k=0; k<=n; k++)			//PRINTING THE OUTPUT.
	{
		printf("\nA(%d):\n",k);
		for(i = 1; i<=n; i++)
	{
		for(j = 1;j<=n;j++)
		{
			printf("%d\t", a[k][i][j]);
			}
			printf("\n");
		}
		}
	}

int main()
{
	int m[20][20],i,j,n;
	printf("\nENTER NO. OF VERTICES: \n");
	scanf("%d", &n);
	printf("\nENTER THE MATRIX: \n");
	for(i = 1; i<=n; i++)		//LOOP FOR TAKING THE FIRST INPUT AS THE FIRST MATRIX.
	{
		for(j = 1;j<=n;j++)
		{
			printf("\nm[%d][%d]: ", i,j);
			scanf("%d", &m[i][j]);
			}
		}
	shortest(m, n);
	return 0;
		}
	
/*OUTPUT:

ENTER NO. OF VERTICES:
3

ENTER THE MATRIX:

m[1][1]: 0

m[1][2]: 4

m[1][3]: 11

m[2][1]: 6

m[2][2]: 0

m[2][3]: 2

m[3][1]: 3

m[3][2]: 999

m[3][3]: 0

A(0):
0       4       11
6       0       2
3       999     0

A(1):
0       4       11
6       0       2
3       7       0

A(2):
0       4       6
6       0       2
3       7       0

A(3):
0       4       6
5       0       2
3       7       0	
*/
