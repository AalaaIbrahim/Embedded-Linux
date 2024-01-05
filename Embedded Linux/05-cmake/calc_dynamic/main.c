#include <stdio.h>
#include <calculator.h>

void main(void)
{
	float a=5, b=2;
	
	printf("%.1f + %.1f = %.1f\n", a, b, add(a,b));
	printf("%.1f - %.1f = %.1f\n", a, b, sub(a,b));
	printf("%.1f x %.1f = %.1f\n", a, b, mul(a,b));
	printf("%.1f / %.1f = %.1f\n", a, b, div(a,b));
	printf("%.1f %% %.1f = %.1f\n", a, b, mod(a,b));
}
