// calculates integral using trapezoidal sum (for reference see Readme)
#include <iostream>

/*
 * @param: x position
 * @return: y value at x position
 */
float f(float x) {
	// enter your function here: e.g. x*x*x for x^3
	return ((x*x*x*x)-3*(x*x)+2);
}

/*
 * calculates (oriented) area between graph of function f and x-axis
 * @param1: lower bound
 * @param2: upper bound
 * @param3: how many intervals (the more the better)
 */
float trapezoidal_sum(int lower_bound, int upper_bount, int nr_intervals) {
	float length_of_interval = (float)(upper_bount - lower_bound) / (float)nr_intervals;
	
	// Debugging:
	std::cout << "Lower_bound: " << lower_bound << std::endl;
	std::cout << "Upper_bound: " << upper_bount << std::endl;
	std::cout << "Nr. intervals: " << nr_intervals << std::endl;
	std::cout << "Length of interval: " << length_of_interval << std::endl;

	float area = 0.0;
	//y_1 -> y_n-1
	for (int cur_interval = 1; cur_interval < nr_intervals; cur_interval++) {
		float cur_x_pos = (float)lower_bound + (float)(length_of_interval * cur_interval);
		area = area + 2 * f(cur_x_pos);
	}
	// add y_0 and y_n and multiply by 0.5 (see formula for the area of a trapezoid)
	area = area + f(lower_bound) + f(upper_bount);
	area = area * 0.5 * length_of_interval;

	std::cout << std::endl << "---SUM---" << std::endl;
	return area;
}
int main() {	
	std::cout << trapezoidal_sum(-2, 5, 100) << std::endl;	
}