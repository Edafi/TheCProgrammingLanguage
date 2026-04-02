#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union U_test{
	int ival;
	float fval;
	char *sval;
};

typedef struct point {
	double x;
	double y;
} Point;

typedef struct flags {
	unsigned int is_keyword : 1;
	unsigned int is_extern : 1;
	unsigned int is_static : 1;
	unsigned int is_tested : 32;
} BitFlags;

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
	BitFlags bitFlag = {0};
	printf("size in bytes is %d\n", sizeof(bitFlag));
}
