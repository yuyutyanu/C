#include <stdio.h>
#include <sys/types.h>  // fork
#include <unistd.h>     // fork
#include <stdlib.h>

int main(){

   pid_t pid;
   char buf[256];
   int pp[2];
   int qq[2];
   char a[256],b[256];
   // (1)パイプの作成
   pipe(pp);
   pipe(qq);

   pid = fork(); // (2)子プロセスの生成


    /*
    * 子プロセスから親プロセスへのデータ通信
    */
   if(pid == 0){
        printf("a:");
        fgets(buf,50,stdin);
        write(pp[1], buf, 256);
        printf("b:");
        fgets(buf,50,stdin);
        write(pp[1], buf, 256);
        close(pp[1]);

   }else{
       read(pp[0], a, 256);
       read(pp[0], b, 256);

       printf("sum : %d\n", atoi(a)+atoi(b));
       close(pp[0]);
   }

    /*
    *　親プロセスから子プロセスへのデータ通信
    */
   if(pid==0){
        printf("child:");
        read(qq[0],buf,256);
        printf("%s",buf);
   }else{
     printf("parent:");
     fgets(buf,50,stdin);
     write(qq[1],buf,256);
   }

    return 0 ;
}