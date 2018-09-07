#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    
	MPI_Init(NULL, NULL);
	int w_rank,w_size;

	MPI_Comm_rank(MPI_COMM_WORLD, &w_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &w_size);

	int n;
	if(w_rank == 0)
	{
		
		printf("Enter a value\n");
		scanf("%d",&n);
		
	}
	
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(w_rank != 0)
	{
		printf("Value received by process %d is %d\n",w_rank,n);
	}
	MPI_Finalize();
}
		
