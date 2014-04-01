#pragma once
#pragma once
#include <vector>
using namespace std;

class Celda
{
private:
	vector<int> cell_;
public:
	Celda();
	~Celda();
	int& block(int);
	int get_size();
	void set_size(int);
};

