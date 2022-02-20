#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
int main() 
{ 
	double x; 
	x = sqrt(8.0); 
	// printf("Square root of 8.0 is %f\n", x);
	printf("Square root of 8.0 is %f", x);
	write(STDOUT_FILENO, "Hello World\n", 12);
	_exit(0);
}

