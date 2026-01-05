#ifndef DYNAMIC_ARRAY_
#define DYNAMIC_ARRAY_

#define CAPACITY 20
#define MINSPACE 3                                                                                  // Я думаю, что 2 или 3 достаточно, так как на конце массива чаров будет \n и \0,
                                                                                                    // но \n входит в длину строки, поэтому он считается. Остается одина свободная ячейка.
#define DELTACAPACITY 5                                                                            // Не знаю сколько добавлять ячеек памяти к новому массиву. Не хочу слишком много,
                                                                                                    // пустого пространства, а слишком мало, чтобы не занимать такты.

char* checkStringCapacity (char string[], int *ptrCapacity, int length);
int readLine(char **ptrString, int *ptrCapacity);
void outputString(char inputString[]);
char* makeDynamicArray_char(int capacity, int typeSize);
char* changeCapacityDynamicArray_char(char *ptr, int capacity, int typeSize);

double* checkArrayCapacity_double (double array[], int *ptrCapacity, int length);
double* makeDynamicArray_double(int capacity, int typeSize);
double* changeCapacityDynamicArray_double(double *ptr, int capacity, int typeSize);

#endif