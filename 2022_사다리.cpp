#include <iostream>
#include <math.h>

using namespace std;

double x, y, c;

double binary(double start, double end) {
	double mid;

	while(start <= end) {
		mid = (start + end) / 2;
        
		double x_for_c = mid * (1.0 - c / sqrt(x * x - mid * mid));
		double y_for_c = c * mid / sqrt(y * y - mid * mid);
        
		if (x_for_c >= y_for_c)start = mid + 0.000001;
		else end = mid - 0.000001;
	}
	return start;
}

int main() {

	cin >> x >> y >> c;
	
	if (x > y) printf("%.3f", binary(1.0, y));
	else printf("%.3f", binary(1.0, x));
    
	return 0;
}