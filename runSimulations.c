#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#include <limits.h>
#include "runOneSimulation.h"

int main(int argc, char* argv[]){
    double rLeft;
    double rRight;
    double tLeft;
    double tRight;

    if(argc < 5 || argc > 5){
        printf("Please input *exactly* 4 command line arguments.\n");
        exit(0);
    }
    else{
        rLeft = atof(argv[1]);
        rRight = atof(argv[2]);
        tLeft = atof(argv[3]);
        tRight = atof(argv[4]);
    }

    srand(time(NULL));

    int i; 
    int leftCount = 0; 
    int rightCount = 0; 
    int clearLeft = 0; 
    int clearRight = 0; 

    for(i = 0; i < 100; ++i){
        int *p = runOneSimulation(rLeft, rRight, tLeft, tRight);
        leftCount += *(p+0); 
        rightCount += *(p+1);
        clearLeft += *(p+2);
        clearRight += *(p+3);
        free(p);        
    }

    
    printf("\nParameter values:\n");
    printf("\tFrom left:\n");
    printf("\t\ttraffic arrival rate:\t%.6f\n", rLeft);
    printf("\t\ttraffic light period:\t%.6f\n", tLeft);
    printf("\tFrom right:\n");
    printf("\t\ttraffic arrival rate:\t%.6f\n", rRight);
    printf("\t\ttraffic light period:\t%.6f\n", tRight);
    printf("Results (averaged over 100 runs):\n");
    printf("\tFrom left:\n");
    printf("\t\tnumber of vehicles:\t%.6f\n", (double) leftCount/100);
    printf("\t\taverage waiting time:\t%.6f\n", (clearRight+tRight)/100);
    printf("\t\tmaximum waiting time:\t%.6f\n", tRight);
    printf("\t\tclearance time:      \t%.6f\n", (double) clearLeft/100);
    printf("\tFrom right:\n");
    printf("\t\tnumber of vehicles:\t%.6f\n", (double) rightCount/100);
    printf("\t\taverage waiting time:\t%.6f\n", (clearLeft+tLeft)/100);
    printf("\t\tmaximum waiting time:\t%.6f\n", tLeft);
    printf("\t\tclearance time:      \t%.6f\n\n", (double) clearRight/100);

    return 0;
}
