#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    
	MPI_Init(NULL, NULL);
	int world_rank,world_size;

	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int n;
	if(world_rank == 0)
	{
		printf("(Master process %d)Enter a value\n",world_rank);
		scanf("%d",&n);
		MPI_Send(&n,1,MPI_INT,1,0,MPI_COMM_WORLD);
	}
	else if(world_rank == 1)
	{
		MPI_Recv(&n,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("(Slave process %d)Received number %d from process 0\n",world_rank,n);
	}
	MPI_Finalize();
}
		
