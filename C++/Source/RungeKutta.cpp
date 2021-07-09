#include <iostream>
#include <vector>
#include <cmath>

double f(double x, double y) {
	return 3 * pow(x, 2) * y;
};


double k1(double x, double y, double h) {
	return f(x, y);
}


double k2(double x, double y, double h) {
	return f(x + h / 2, y + h / 2 * k1(x, y, h));
}


double k3(double x, double y, double h) {
	return f(x + h / 2, y + h / 2 * k2(x, y, h));
}


double k4(double x, double y, double h) {
	return f(x + h, y + h * k3(x, y, h));
}


double T4(double x, double y, double h) {
	return (k1(x, y, h) + 2 * k2(x, y, h) + 2 * k3(x, y, h) + k4(x, y, h)) / 6;
}


int main() {
	// ============================================
	// Only hange parameters below this line

	double x0 = 1; // initial condition x
	double y0 = 2; // initial condiditon y

	double xn = 10; // x stopping point
	int numSteps = 100; // number of steps to take

	// Only change parameters above this line
	// ============================================

	double h = (xn - x0) / numSteps; // step size

	std::vector<double> yArray; 
	std::vector<double> xArray;

	yArray.push_back(y0);
	xArray.push_back(x0);

	for(int i = 0; i < numSteps+1; i++) {
		yArray.push_back(
			yArray[i] + h * T4(xArray[i], yArray[i], h)
		);

		xArray.push_back(
			xArray[i] + h
		);
		std::cout << "x: " << xArray[i] << " " << "y: " << yArray[i] << std::endl;
	}
	
}