#include <stdio.h>


int main(){
    char buf[20];
     //enterで\n
     //必ず末尾に\0（終端文字）がはいる
    fgets(buf,10,stdin);

    printf("%s",buf);


    return 0 ;
}