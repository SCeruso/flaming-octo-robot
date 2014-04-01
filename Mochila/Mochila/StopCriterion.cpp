#include "StopCriterion.h"


StopCriterion::StopCriterion() : iteration_(0), max_(500)
{
}


StopCriterion::~StopCriterion()
{
}

bool StopCriterion::stop() { return iteration_ < max_ ? false : true; }

void StopCriterion::iterationIncrease() { iteration_++; }

void StopCriterion::set_max(int m) {
	max_ = m;
}
int StopCriterion::get_max(){
	return max_;
}

void StopCriterion::iterationReset() { iteration_ = 0; }
int StopCriterion::getIteration(){ return iteration_; }