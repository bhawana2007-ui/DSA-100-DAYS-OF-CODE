#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// Sort by position descending
int cmp(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed) {

    Car cars[positionSize];

    // Step 1: compute time for each car
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: sort by position descending
    qsort(cars, positionSize, sizeof(Car), cmp);

    // Step 3: count fleets
    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        // new fleet found
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
        // else: joins previous fleet (do nothing)
    }

    return fleets;
}