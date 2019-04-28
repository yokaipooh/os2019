#include <stdio.h>
#include <unistd.h>
int main (){
	int pid1,pid2;
	printf("main before fork()\n");
	pid1= fork();
if(pid1==0){
printf("i am child after fork(), launching ps -ef\n");
char *args[] ={ "/tmp/ps","-ef", NULL};
if (execvp("/tmp/ps", args)<0){
printf ("can not execute ps -ef ");
}
}
else
{
	waitpid(pid1,NULL,0);
printf("this parent after fork, child is %d \n Create a new child\n",pid1);
pid2=fork();
if (pid2 ==0){
printf(" this is the 2nd child\n now run free -h\n");
char* args[] = { "/tmp/free","-h",NULL};
if (execvp ("/tmp/free", args)<0){
printf("can not execute free -h");
}
}
else{
printf("this is parent after 2 fork ,2nd is %d\n ALL DONE.",pid2);
waitpid(pid2,NULL,0);
}
}
return 0;
}





