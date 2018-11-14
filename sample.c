#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include"mpi.h"

int N;
double mu;
double sigma;
double *sample;

double randn(double mu,double sigma);
void sampler(double *sample, double mu,double sigma, int N);

int main(int argc, char *argv[])
{
  int rank,size;
  MPI_Init (&argc, &argv);
/* get current process rank */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
/* get number of processes */
  MPI_Comm_size (MPI_COMM_WORLD, &size);
  N=atoi(argv[1]);
  mu=atof(argv[2]);
  sigma=atof(argv[3]);

  /*sample=malloc(N*sizeof(float));
  sampler(sample,mu,sigma,N);*/

  FILE *gauss;
  gauss=fopen("sample.dat","w");
  int i;
  float val;
  for (i = 0; i < N/size; ++i)
  {
    val=randn(mu,sigma);
    fprintf(gauss, "%lf\n",val);  /*,sample[i]);*/
  }
  MPI_Finalize();
  return 0;
}
void sampler(double *sample, double mu,double sigma, int N)
{
  double *gauss;
  int i;
  *gauss=*sample;
  for (i = 0; i < N; ++i)
  {
    gauss[i]=randn(mu,sigma);
  }
  *sample=*gauss;
}

double randn (double mu, double sigma)
{
  double U1, U2, W, mult;
  static double X1, X2;
  static int call = 0;
 
  if (call == 1)
    {
      call = !call;
      return (mu + sigma * (double) X2);
    }
 
  do
    {
      U1 = -1 + ((double) rand() / RAND_MAX) * 2;
      U2 = -1 + ((double) rand() / RAND_MAX) * 2;
      W = pow(U1, 2) + pow(U2, 2);
    }
  while (W >= 1 || W == 0);
 
  mult = sqrt((-2 * log(W)) / W);
  X1 = U1 * mult;
  X2 = U2 * mult;
 
  call = !call;
 
  return (mu + sigma * (double) X1);
}
