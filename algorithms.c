#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define n 10
void quicksort(int*,int,int);
int partition(int*,int,int);

void mergesort(int*,int,int);
void merge(int*,int,int,int,int);

void printArray(int *  , int );

main (){
        int low,high,pin[n],i;

        srand(time(NULL));
        printf("Initial array\n");
        for(i=0;i<n;i++){
                pin[i]=rand()%50;
                printf("%d \n",pin[i]);
            }

        low=pin[0];
        high=pin[n-1];

        quicksort(pin,low,high);
        mergesort(pin,0,n-1);
        printArray(pin,n-1);

}

void quicksort(int *pin,int low,int high){
        int pi ;
        if (low<high){
                pi=partition(pin,low,high);
                quichsort(pin,low,pi-1);
                quichsort(pin,pi+1,high);
        }
}

int partition(int *pin , int low , int high ){
        int pivot ,i , tmp,j;
        pivot=pin[high];
        i=(low-1);
        for( j=low ; j <=high-1 ; j++){
                if (pin[j]<=pivot){
                        i++;
                        tmp=pin[j];
                        pin[j]=pin[i];
                        pin[i]=tmp;
                }
        }
        tmp=pin[i+1];
        pin[i+1]=pin[high];
        pin[high]=tmp;
        return (i+1);
}

void mergesort(int *pin,int i ,int j){
        int mid ;
        if (i<j){
                mid= (i+j)/2 ;
                mergesort(pin,i,mid);
                mergesort(pin,mid+1,j);
                sort(pin,i,mid,mid+1,j);
        }
}

void merge(int *pin , int i1,int i2,int j1,int j2){
        int tmp[n];
        int i,j,k ;
        i=i1;
        j=i2;
        k=0;
        while(j<=j1 && i<=j2){
                if(pin[i]<=pin[j])
                        tmp[k++]=pin[i++];
                else
                        tmp[k++]=pin[j++];
        }
        while (j<=j1)
                tmp[k++]=pin[i++];
        while (i<=j2)
                tmp[k++]=pin[j++];
        for(i=i1,j=0;i<=j2;i++,j++)
                pin[i]=tmp[j];
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
