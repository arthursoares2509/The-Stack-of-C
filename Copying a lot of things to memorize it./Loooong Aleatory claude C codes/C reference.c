#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define DEBUG 1

#if DEBUG
    #define LOG(msg) printf("DEBUG: %s\n", msg)
#else
    #define LOG(msg)
#endif

enum Color { RED, GREEN, BLUE}
enum Status { OK = 200, NOT_FOUND = 404, SERVER_ERROR = 500};

typedef unsigned int uint;
typedef struct Point Point;

struct Point {
    double x;
    double y;
};

struct Person {
    char name [50];
    int age;
    struct Point location;
}

Union Data{
    int i;
    float f;
    chat str[20];
}

int add(int a, int b);
int factorial(int n);
void swap(int *a, int *b);
void print_array(const int *arr, int size);
int *create_array(int size);
struct Point make_point(double x, double y);
int compare_ints(const void *a, const void *b);
int apply(int (*func)(int, int), int a, int b);

int main(void) {

    int a = 10;
    unsigned int b = 
}
