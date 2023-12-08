#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	int n1,n2;
	int even;
	printf("Enter the First Number\n");
	 scanf("%d", &n1);
	printf("Enter the Second Number\n");
	 scanf("%d", &n2);

	pid_t child_pid=fork();
	
	if(child_pid==0)
	{
		int max_num;
		if(n1>n2)
		{
			max_num=n1;
		}
		else if(n2>n1)
		{
			max_num=n2;
		}
		else
		{
			max_num=n1=n2;
		}
		printf("Max No : %d", max_num);
		printf("\n");
		printf("Child process PID %d\n",child_pid);
		exit(0);
	}
	else
	{
		wait(NULL);
		
		pid_t even_pid = fork();
		
		if(even_pid==0)
		{
			if(n1%2==0)
			{
				even = n1;
				printf("Even No : %d\n", even);
			}
			else if(n2%2==0)
			{
				even = n2;
				printf("Even No : %d\n", even);
			}
			else
			{
				printf("No Even Num Found");
				wait(NULL);
			}
			printf("Even process PID %d\n",even_pid);
			
		}
		
		printf("Child process PID %d\n",child_pid);
	}

return 0;	
}
