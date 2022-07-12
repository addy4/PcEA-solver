#include "functions.h"
 
int main(int argc, char **argv) {

	int i, lastimprovement=0;
	int imp=0;
	int reinit_count=0;
	clock_t start, test;

	double TIMEOUT, elapsed_time=0, gBestTime=0;
	int rseed;
	int MAX_IMPROVE=MAX_IMPROVE_LIMIT;

	gBestFitness = INF; // initialize
	gBestViolations=INF;
	totalDemand=0;
	solcount=0;
	
	start = clock();
	
	// Read and process arguments
	rseed = (int) atoi(argv[4]);;
	
	readData(argv[1]);

	TIMEOUT = atof(argv[3]);//(double) warehouses;//(double) 10*sqrt(warehouses);//

	srand(rseed);
	initpop();

	for (i=0;;i++){
		imp=0;
		imp = ealoop();

		if (imp==1) lastimprovement = i;
		
		if (i-lastimprovement > MAX_IMPROVE) {
			reinit_count++;
			reinit();
			lastimprovement = i;
		}
		
		test = clock();
		elapsed_time = ((double) (test - start)) / CLOCKS_PER_SEC;
		if (imp) gBestTime = elapsed_time;
		if (elapsed_time > TIMEOUT) break;
	}
	
	printSol(argv[2],gBestTime);
	
	free (sol1);
	free(fcapacities);
	free(demand);
	free(capacities);
	free(fixedcosts);
	free(goods);
	free(supplycosts);
	free(incompatiblepairs);
	free(gBestSolution);

 return 0;
}

