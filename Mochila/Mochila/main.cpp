#include "Mochila.h"
#include "Matrix.h"
#include "DP_Method.h"
#include "AGS_Method.h"
#include "TS_Method.h"
#include "SS_Method.h"
#include <math.h>
// Resolución del problema de la mochila 0-1


int main(int argc, char** argv)
{
	DP_Method metod;
	Knapsack_Problem problem;
	TS_Method metod3;
	SS_Method metod4;
	Knapsack_Solution sol1, sol2, r;
	Bit_set dummy;

	problem.read(cin);
	metod.setProblem(problem);
	metod.runSearch();
	/*
	AGS_Method metod2;

	
	metod2.setProblem(problem);
	metod2.runSearch();*/
//	for (int i = 0; i < problem.get_n(); i++)
	//	cout << problem.elemento(i).v << ", " << problem.elemento(i).w << endl;
	metod3.setProblem(problem);
	metod3.setTabu(2);
	metod3.set_holgura(9);
	metod3.runSearch();

	metod4.setProblem(problem);


	metod4.initialize();

	metod4.runSearch();
	system("pause");
}
