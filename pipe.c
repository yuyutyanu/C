#include <stdio.h>
#include <sys/types.h>  // fork
#include <unistd.h>     // fork

int main(){

   pid_t pid;
   char buf[256];
   int pp[2];

   // (1)パイプの作成
   pipe(pp);

   pid = fork(); // (2)子プロセスの生成

   if(pid == 0){
        printf("child:");
        fgets(buf,50,stdin);
        write(pp[1], buf, 256); // (4)パイプへの書き込み
        close(pp[1]);
   }else{
       read(pp[0], buf, 256); // (4)パイプから読み込み
       printf("parent : %s", buf);
       close(pp[0]);
   }

    return 0 ;
}