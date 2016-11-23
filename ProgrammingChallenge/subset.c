//
//  subset.c
//  ProgrammingChallenge
//
//  Created by Hyunhan Kim on 2016. 11. 18..
//  Copyright © 2016년 Hyunhan Kim. All rights reserved.
//

#include <stdio.h>

#define MAXCANDIDATES 4

typedef enum {false, true} bool;
bool finished = false;

typedef struct data {
    char data;
    bool isSol;
} data;


void backtrack(data a[], int k, int data);
bool isASolution(data a[], int k, int input);
int constructCandidates(data a[], int k, int input, data c[], int* ncandidates);
int processSolution(data a[], int k);
void genSubsets(int n);


int main(int argc, const char * argv[]) {
    // insert code here...
    
    genSubsets(3);
    
    
    return 0;
}


void backtrack(data a[], int k, int input)
{
    data c[MAXCANDIDATES];
    int ncandidates;
    int i;
    
    if (isASolution(a, k, input)) {
        processSolution(a, k);
    }
    else {
        k = k+1;
        constructCandidates(a, k, input, c, &ncandidates);
        for(i = 0; i < ncandidates; i++) {
            a[k].isSol = c[i].isSol;
            backtrack(a, k, input);
            if (finished) return;
        }
    }
}

bool isASolution(data a[], int k, int n)
{
    return (k == n) ;
}

int constructCandidates(data a[], int k, int input, data c[], int *ncandidates)
{
    c[0].isSol = true;
    c[1].isSol = false;
    *ncandidates = 2;
    
    return 0;
}

int processSolution(data a[], int k)
{
    int i;
    
    printf("{");
    for(i = 1; i <= k; i++) {
        if (a[i].isSol == true) printf(" %c", a[i].data);
    }
    printf(" } \n");
    
    return 0;
}

void genSubsets(int n)
{
    data a[4];
    a[0].data = ' ';
    a[1].data = 'a';
    a[2].data = 'b';
    a[3].data = 'c';
    
    backtrack(a, 0, n);
}