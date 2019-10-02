#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	double x1,y1,x2,y2;
	double final;
	cin >> x1 >> y1 >>x2 >> y2;
	
	final = pow((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1),1/2.0);
	printf("%.4lf\n",final);
}
