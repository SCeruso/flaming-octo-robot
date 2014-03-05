#pragma once
class StopCriterion
{
private:
	int iteration_;
	int max_;
public:
	StopCriterion();
	~StopCriterion();
	virtual bool stop();
	void iterationIncrease();
	void set_max(int);
	int get_max();
	void iterationReset();
};

