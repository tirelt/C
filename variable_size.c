#include <stdio.h>
#include <stdlib.h>

int sum(int* arr, int size){
    int ret = 0;
    for(int i = 0; i< size; ++i){
        ret += arr[i];
    }
    return ret;
}

int main(){   
    int number;
    printf("Enter an number of arguments: ");  
    scanf("%d", &number);
    int* arr = (int*)malloc(sizeof(int)*number);
    if (arr == NULL){
        printf("Memory allocation failed!\n");
        return -1;
    }
    for(int i = 0; i < number; ++i){
        printf("Enter argument %d: ",i+1);   
        scanf("%d", &arr[i]);
    } 
    int s = sum(arr,number);
    printf("The sum of the arguments is %d", s);    
    free(arr);
    return 0;
}