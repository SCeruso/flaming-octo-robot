#include "Mochila.h"
#include "Matrix.h"
#include "DP_Method.h"
#include "AGS_Method.h"
#include <math.h>
// Resolución del problema de la mochila 0-1


int main(int argc, char** argv)
{
	DP_Method metod;
	Knapsack_Problem problem;

	problem.read(cin);
	metod.setProblem(problem);
	metod.runSearch();
	
	AGS_Method metod2;

	
	metod2.setProblem(problem);
	metod2.runSearch();
	
	
	system("pause");
}
