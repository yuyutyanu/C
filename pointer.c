#include<stdio.h>

void swap(int *a,int *b){
      int tmp = *a;
      *a = *b;
      *b = tmp;
}

int main(int argc, char *argv[]){

    int a = 5;
    int b = 10;
    printf("before\n");
    printf("\ta:%d\n\tb:%d\n",a,b);

    swap(&a,&b);
    printf("after\n");
    printf("\ta:%d\n\tb:%d\n",a,b);

}