#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
    return (*(int*)a > *(int*)b)  - (*(int*)a < *(int*)b );
//    return ( *(int*)a - *(int*)b );
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int numofelements,i;
    scanf("%d",&numofelements);
    int *arr = malloc(numofelements* sizeof *arr);
    int freq=1;
    int curfreq=0;
    int curnum;
    if (!arr) return -1;
    for (i=0; i<numofelements;i++) {
        scanf("%d",&arr[i]);
    }
    float mean=0;
    float median=0;
    int mode = 0;
    for (i=0; i<numofelements;i++) {
        mean += arr[i];
    }
    mean /= numofelements;
    
    qsort(arr, numofelements, sizeof(int), cmpfunc);
/*    for (i=0; i<numofelements;i++) { //print the array
        printf("%d ",arr[i]);
    }*/
    
    median = arr[(int)floor((numofelements/2.0)+0.5)-1] + arr[(int)floor((numofelements)/2.0 +1.0)-1] ;
    median /= 2;
    
    mode = arr[0];
    curnum = arr[0];
    for (i=1; i<numofelements;i++) {
        if(mode == arr[i]) { curfreq++; freq++; continue;}
        if(curnum == arr[i]) {curfreq++;}
        else {curnum = arr[i]; curfreq = 1;}
        if(curfreq > freq) { freq = curfreq; mode = curnum;}
    }
    printf("\n%.1f\n",mean);
    printf("%.1f\n",median);
    printf("%d",mode);
//
    return 0;
}
