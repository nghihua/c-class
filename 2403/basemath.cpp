#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <vector>

using namespace std;

class BaseMath {
public:
	BaseMath() {}
	bool isEven(int number) {
		if ((number%2)==0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int factorial(int n) {
		if (n == 1) {
			return 1;
		}
		else {
			return n*factorial(n-1);
		}
	}
};

class AdvancedMath : public BaseMath {
public:
	AdvancedMath() {}
	double estimateEulerNumber(int numLoops) {
		if(numLoops == 1) {
			return (1.0/factorial(numLoops) + 1);
		}
		else {
			return (1.0/factorial(numLoops)) + estimateEulerNumber(numLoops-1);
		}
	}
};

int main() {
	AdvancedMath o;
	cout<<o.isEven(2)<<endl;
	cout<<o.estimateEulerNumber(10)<<endl;
	return 0;
}
