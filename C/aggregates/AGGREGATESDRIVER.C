#include <stdio.h>
#include "AGGREGATES.H"
#include "AGGREGATES.C"

int main()
{
    float (*functions[5])(float[], int) = {&min,&max,&sum,&avg,&pseudo_avg};

    int const F_SIZE = 5;
    int const SIZE_ONE = 5;
    int const SIZE_TWO = 10;

    float a_one[SIZE_ONE] = {2, 6, 4, 3, 18};
    float a_two[SIZE_TWO] = {6, 12, 75, 32, 5, 21, 27, 33, 21, 15};

    for(int i = 0; i < F_SIZE; i++){

        if(i == 0)
            printf("5 Element Array Min: ");
        else if(i == 1)
            printf("5 Element Array Max: ");
        else if(i == 2)
            printf("5 Element Array Sum: ");
        else if(i == 3)
            printf("5 Element Array Average: ");
        else{
            printf("5 Element Array Pseudo Average: ");
        }

        printf("%.2f\n", functions[i](a_one,SIZE_ONE));

        if(i == 0)
            printf("10 Element Array Min: ");
        else if(i == 1)
            printf("10 Element Array Max: ");
        else if(i == 2)
            printf("10 Element Array Sum: ");
        else if(i == 3)
            printf("10 Element Array Average: ");
        else{
            printf("10 Element Array Pseudo Average: ");
        }

        printf("%.2f\n\n", functions[i](a_two,SIZE_TWO));
        
    }
    return 0;
}
