#include <stdio.h>
#include <stdlib.h>

#define LENGTH 50
void print_array(int* ,int );
void shift_element(int *,int );
void insertion_sort(int *, int );


void print_array(int *arr,int len){
    for (int i = 0; i < len-1; i++)
    {
        printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+len-1));
    
}

void shift_element(int *arr,int i){

    int j=0;
    while(j<i){
        *(arr+i-j)= *(arr+i-j-1);
        j++;
    }
 
}


void insertion_sort(int *arr, int len){

    int check,j;
    for(int i=1; i<len;i++){
        check=*(arr+i);
        j=i-1;
        while(j>=0 && check< *(arr+j)){
            
            *(arr+j+1)=*(arr+j);
            j--;

        }
        *(arr+j+1)=check;
    }
}


int main(){

    int arr[LENGTH];
    for (int i = 0; i < LENGTH; ++i) {
        scanf("%d",(arr+i));
    }
    insertion_sort(arr,LENGTH);
    print_array(arr,LENGTH);
    return 0;
}