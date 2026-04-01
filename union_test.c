#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union U_test{
	int ival;
	float fval;
	char *sval;
};

typedef struct point{
	double x;
	double y;
} Point;

int main(){
	union U_test un;
	un.sval = strdup("Hello world");
	printf("%s\n", un);
	//free(un.sval);				// Does free()
	un.ival = 10;
	//printf("%s\n", un.sval);		// We can use only freeshly assigment variable in union
	//								// This would not work
	printf("%d\n", un);
	Point dot1 = {12.5, -5.85};
	printf("Point cords: x = %f, y = %f\n", dot1.x, dot1.y);
}
