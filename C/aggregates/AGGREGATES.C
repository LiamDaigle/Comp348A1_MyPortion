#include "AGGREGATES.H"
#include <stdio.h>
#include <stdlib.h>

float min(float list[], int SIZE){
    if(list == NULL || SIZE <= 0){
        printf("FATAL ERROR in line %i", __LINE__);
        exit(0);
    }
    float min = list[0];
    for(int i = 1; i < SIZE; i++){
        if(list[i] < min){
            min = list[i];
        }
    }
        return min;
    }

float max(float list[], int SIZE){
    if(list == NULL || SIZE <= 0){
        printf("FATAL ERROR in line %i", __LINE__);
        exit(0);
    }
    float max = list[0];
    for(int i = 1; i < SIZE; i++){
        if(list[i] > max){
            max = list[i];
        }
    }
        return max;
}

float sum(float list[], int SIZE){
    if(list == NULL || SIZE <= 0){
        printf("FATAL ERROR in line %i", __LINE__);
        exit(0);
    }
        float sum = 0;
        for(int i = 0; i < SIZE; i++){
            sum += list[i];
        }

        return sum;    
}

float avg(float list[], int SIZE){

    if(list == NULL || SIZE <= 0){
        printf("FATAL ERROR in line %i", __LINE__);
        exit(0);
    }
    
    float sumValue = sum(list, SIZE);
    float average = sumValue / SIZE;

    return average;
}

float pseudo_avg(float list[], int SIZE){

    if(list == NULL || SIZE <= 0){
        printf("FATAL ERROR in line %i", __LINE__);
        exit(0);
    }
    
    float min_max = min(list, SIZE) + max(list, SIZE);
    float pseudo_average = min_max / 2;

    return pseudo_average;
}