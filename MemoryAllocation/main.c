//
//  main.c
//  MemoryAllocation
//
//  Created by Omar Gudino on 10/20/13.
//  Copyright (c) 2013 Omar Gudino. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BOOL_FMT(bool_expr) "%s\n", (bool_expr) ? "true" : "false"

bool memoryBlocks[40];
int indexNextFit = 0;
int firstCategory[40];
int secondCategory[40];

int main(int argc, const char * argv[])
{
    //llenar un poco los bloques
    for (int i = 7; i<8; i++) {
        memoryBlocks[i] = true;
    }
    
    for (int i = 13; i<19; i++) {
        memoryBlocks[i] = true;
    }
    
    for (int i = 29; i<30; i++) {
        memoryBlocks[i] = true;
    }
    
    for (int i = 0; i<=40; i++) {
        printf("memoryBlocks[%d] = ", i);
        printf(BOOL_FMT(memoryBlocks[i]));
        
    }
    //Choose your method
    
    //worst fit
    //printf("%d\n", worstFit(memoryBlocks, 40, 6));
    
    //bestFit
    //printf("%d\n", bestFit(memoryBlocks, 40, 6));
    
    //firstFit
    //printf("%d\n", firstFit(memoryBlocks, 40, 7));
    
    //nextFit
    //printf("%d\n", nextFit(memoryBlocks, 40, 6));
    //printf("%d\n", nextFit(memoryBlocks, 40, 6));
    //printf("%d\n", nextFit(memoryBlocks, 40, 6));
    
    //quickFit
    //printf("%d\n", quickFit(memoryBlocks, 40, 4));
    //printf("%d\n", quickFit(memoryBlocks, 40, 9));
    //printf("%d\n", quickFit(memoryBlocks, 40, 11));
    

    for (int i = 0; i<=40; i++) {
        printf("memoryBlocks[%d] = ", i);
        printf(BOOL_FMT(memoryBlocks[i]));
        
    }
    
    return 0;
}

int worstFit(bool array[], int arraySize,  int sizeOfGivenBlock)
{
    int i = 0;
    int currentBestBlock = 0;
    int possibleBestBlock = 0;
    int startingIndex = 0;
    
    while (i <= arraySize) {
        int counter = 0;
        while (array[i] == false && i <= arraySize) {
            counter++;
            i++;
            possibleBestBlock = counter;
        }
        
        if (possibleBestBlock > currentBestBlock) {
            currentBestBlock = possibleBestBlock;
            startingIndex = i - counter;
        }
        
        
        i++;
    }
    
    for (int j = 0; j < sizeOfGivenBlock; j++) {
        array[startingIndex+j] = true;
    }
    
    return currentBestBlock;
    
}

int bestFit(bool array[], int arraySize, int sizeOfGivenBlock)
{
    int i = 0;
    int currentBestBlock = arraySize;
    int possibleBestBlock = 0;
    int startingIndex = 0;
    
    while (i <= arraySize) {
        int counter = 0;
        while (array[i] == false && i <= arraySize) {
            counter++;
            i++;
            possibleBestBlock = counter;
        }
        
        if (possibleBestBlock < currentBestBlock) {
            currentBestBlock = possibleBestBlock;
            startingIndex = i - counter;
        }
        
        
        i++;
    }
    
    for (int j = 0; j < sizeOfGivenBlock; j++) {
        array[startingIndex+j] = true;
    }
    
    return currentBestBlock;
}

int firstFit(bool array[], int arraySize,  int sizeOfGivenBlock)
{
    int i = 0;
    int currentBestBlock = 0;
    int possibleBestBlock = 0;
    int startingIndex = 0;
    
    while (i <= arraySize && currentBestBlock < sizeOfGivenBlock) {
        int counter = 0;
        while (array[i] == false && i <= arraySize) {
            counter++;
            i++;
            possibleBestBlock = counter;
        }
        
        if (possibleBestBlock > currentBestBlock) {
            currentBestBlock = possibleBestBlock;
            startingIndex = i - counter;
        }
        i++;
    }
    
    for (int j = 0; j < sizeOfGivenBlock; j++) {
        array[startingIndex+j] = true;
    }
    
    return currentBestBlock;
    
}

int nextFit(bool array[], int arraySize,  int sizeOfGivenBlock)
{
    int i = 0;
    int currentBestBlock = 0;
    int possibleBestBlock = 0;
    int startingIndex = 0;
    
    while (i <= arraySize && currentBestBlock < sizeOfGivenBlock) {
        int counter = 0;
        while (array[i] == false && i <= arraySize) {
            counter++;
            i++;
            possibleBestBlock = counter;
        }
        
        if (possibleBestBlock > currentBestBlock) {
            currentBestBlock = possibleBestBlock;
            startingIndex = i - counter;
        }
        i++;
    }
    
    for (int j = 0; j < sizeOfGivenBlock; j++) {
        array[startingIndex+j] = true;
        indexNextFit = startingIndex + j;
    }
    
    return currentBestBlock;
    
}

int quickFit(bool array[], int arraySize, int sizeOfGivenBlock)
{
    
    int i = 0;
    int j = 0;
    int possibleBestBlock = 0;
    int startingIndex = 0;
    int counterBlocks = 0;
    int arrayOfIndex[arraySize];
    
    while (i <= arraySize) {
        int counter = 0;
        while (array[i] == false && i <= arraySize) {
            counter++;
            i++;
            possibleBestBlock = counter;
        }
        
        if (possibleBestBlock <= 20 && possibleBestBlock > 0) {
            firstCategory[counterBlocks] = possibleBestBlock;
            startingIndex = i - counter;
            arrayOfIndex[counterBlocks] = startingIndex;
            counterBlocks++;
        }
        
        else if (possibleBestBlock > 20 && possibleBestBlock <= 40) {
            secondCategory[counterBlocks] = possibleBestBlock;
            startingIndex = i - counter;
            arrayOfIndex[counterBlocks] = startingIndex;
            counterBlocks++;
        }
        i++;
        possibleBestBlock = 0;
    }
    
    if (sizeOfGivenBlock <= 20) {
        for (i = 0; i<=40; i++) {
            if (firstCategory[i] >= sizeOfGivenBlock) {
                for (j = 0; j < sizeOfGivenBlock; j++) {
                    int position = arrayOfIndex[i] + j;
                    array[position] = true;
                }
                return j;
            }
        }
        
    } else if (sizeOfGivenBlock > 20 && sizeOfGivenBlock <= 40) {
        for (i = 0; i<=40; i++) {
            if (secondCategory[i] >= sizeOfGivenBlock) {
                for (j = 0; j < sizeOfGivenBlock; j++) {
                    array[arrayOfIndex[i]+j] = true;
                }
                return j;
            }
        }
    }
    return 0;
}