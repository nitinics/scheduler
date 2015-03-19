#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int size=3; //Default value
int sizebinary;

void print_binmatrix(int arra[size][sizebinary])
{
	int i,j;
	for(i=0;i<size;i++) {
		for(j=0;j<sizebinary;j++) {
			printf("%d ", arra[i][j]);
			
		}
		printf("\n");
	}
	printf("\nConstructing a code with the following property \n[n, k, d] = [n, (d-1), d]\n");
	printf("\nn = %d, k = %d , d = %d, duty_cycle = %f %% \n", j, i-1, size, ((float)(i-1)/j) * 100);
	printf("\nWhere, n = length of each codeword, k = number of wakeup in a codeword, d = number of codewords, duty cycle = k / n \n");

}

void print_matrix(int arr[size][size])
{
	int i,j;
	for(i=0;i<size;i++) {
		for(j=0;j<size;j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void print_binary_code(int matrix[size][size])
{
	int m,n;
	int p,q;
	int value;
	int x,y;
	int lowtriangle[size][size];
	int binmat[size][sizebinary];

	for(p=0;p<size;p++) {
		for(q=0;q<sizebinary;q++) {
			binmat[p][q]=0;	
		}
	}

	q=0;
	p=0;
	//printf("Extracting the lower triangular matrix, and separating the positions.\n");
	for(n=0; n<size; n++) {
		for(m=0; m<size; m++) {
				//value = matrix[m][n];
				if(m<=n) {
					value = 0;
				}else {
					value = 1;
				}
				lowtriangle[m][n] = value;
				if(value==1) {
					//printf("m %d :p %d, n %d :q %d \t", m,p,n,q);
					//printf("%d,%d  ", m+1,n+1);
					x = m;
					y = n;
					binmat[m][q]=value;
					binmat[n][q]=value;
					q++;
				}
				
		}
	}
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	print_binmatrix(binmat);
	

}
 

int main (int argc, char *argv[])
{	
	if (argc != 2)
	{
		printf("Usage: %s number_of_codewords \n", argv[0] );
	}
	else
	{
		size = atoi(argv[1]);
		sizebinary = ((size-1)*size)/2 ;
		
		//printf("------------------------------------------------------------------------\n");
		//printf("Constructing an Square Matrix of %d x %d \n", size, size);

		int a,b;
		int mat[size][size];

		for(a=0; a<size; a++) {
			for(b=0; b<size; b++) {
				mat[a][b] = (a+1)*10 + (b+1);
			}
		}

		//print_matrix(mat);
		//printf("------------------------------------------------------------------------\n");
		print_binary_code(mat);
		printf("---------------------------------------------------------------------------------------------------------------------------\n");
		return 0;
	}
}	

