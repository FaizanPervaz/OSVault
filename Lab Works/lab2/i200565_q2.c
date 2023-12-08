#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int a,b,c,d,e,f;
	int r1,r2,r3,r;
	printf("Enter a :\n");
	 scanf("%d", &a);
	printf("Enter b :\n");
	 scanf("%d", &b);
	printf("Enter c :\n");
	 scanf("%d", &c);
	printf("Enter d :\n");
	 scanf("%d", &d);
	printf("Enter e :\n");
	 scanf("%d", &e);
	printf("Enter f :\n");
	 scanf("%d", &f);
	 
	 pid_t child1 = fork();
	 
	 if(child1==0)
	 {
	 	r1 = a*b;
	 	
	 	printf("Child 1 PID %d\n",child1);
	 }
 	else
 	{
	 	pid_t child2 = fork();
	 	
	 	if(child2==0)
	 	{
	 		r2 = c/d;
	 		
	 		printf("Child 2 PID %d\n",child2);
	 	}
 		else
 		{
	 		pid_t child3 = fork();
	 		
	 		if(child3==0)
	 		{
	 			r3 = e-f;
	 			printf("Child 3 PID %d\n",child3);
	 			
	 			r = r1+r2+r3;
	 			printf("Result : %d\n", r);		
	 		}
	 		else
	 		{
	 			 printf("Parent PID %d\n", child3);
	 		}
	 		
 		}
	 }
	 
	
return 0;
}
