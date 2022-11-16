#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <limits.h>
#include "queue.h"


int probablility(double p)
{
    double x = (double)rand() / RAND_MAX;
    int n =  x > p;
    if (n)
    {
        return 1; 
    }
    else
    {
        return 0;
    }

}


int * runOneSimulation(double rLeft, double rRight, double tLeft, double tRight)
{
    queue *right; 
    queue *left; 
    
    left = malloc(sizeof(queue));
    right = malloc(sizeof(queue));
    
    initialize(left);
    initialize(right);
    
    int iteration = 0; 
    int leftGreen = 0; 
    int rightGreen = 0; 
    int countIteration = 0; 
    int leftCount = 0; 
    int rightCount = 0; 


    while(iteration < 500){
        leftGreen = 0; 
        rightGreen = 1; 
        
        if(!leftGreen){
            while(countIteration < tLeft){
                if(probablility(rLeft) == 1){
                    enqueue(left, 1);
                    ++leftCount;
                }
                if(probablility(rRight) == 1){
                    enqueue(right , 1);
                    ++rightCount; 
                }
                dequeue(left);
                ++countIteration;
            }
        }

        iteration += countIteration;
        countIteration = 0; 

        if(iteration>=500){
            break;
        }

        leftGreen = 1; 
        rightGreen = 0; 
        if(!rightGreen){
            while(countIteration < tRight){
                if(probablility(rLeft) == 1){
                    enqueue(left, 1);
                    ++leftCount; 
                }
                if(probablility(rRight) == 1){
                    enqueue(right, 1);
                    ++rightCount; 
                }
                dequeue(right);
                ++countIteration;

            }
        }

        iteration += countIteration;
        countIteration = 0; 
    }

    int clearLeft = 0; 
    int clearRight = 0; 

    while(left->count > 0){
        dequeue(left);
        ++clearLeft; 
    }
    while(right->count > 0){
        dequeue(right);
        ++clearRight; 
    }

    int *nums = malloc(4);
    nums[0] = leftCount;
    nums[1] = rightCount;
    nums[2] = clearLeft;
    nums[3] = clearRight;


    free(left);
    free(right);
    return nums; 
}



