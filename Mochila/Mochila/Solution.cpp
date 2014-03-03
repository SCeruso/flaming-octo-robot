#include "Solution.h"


Solution:: Solution() : score_(NON_EVALUATED){}

Solution:: ~Solution(){}

double Solution:: get_score(void) { return score_; }

void Solution::set_score(double score) { score_ = score; }
