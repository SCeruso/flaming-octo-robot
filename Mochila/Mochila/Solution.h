#pragma once


#define NON_EVALUATED -1


class Solution
{
private:
	double score_;
public:
	Solution();
	~Solution();
	double get_score(void);
	void set_score(double);
};

