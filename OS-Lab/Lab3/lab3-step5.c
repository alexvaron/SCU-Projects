//Alex Varon
//Lab 3 - Step 5
//10/7/2020
//This program implements a producer-consumer message communication

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

int main()
{
	int fds[2]; 
	char input[100]; 
	char buff[100]; 
	int count; 
	int i; 
 	
	printf("Enter a message to communicate \n");
    	scanf("%[^\n]", input);


	int n = 0;
	for(i=0; i<100; i++)
	{
		if(input[i] == ' ') n++;
        if(input[i+1] == '\0')
		{
			n++;
			break; 
		}
	}
	pipe(fds);   

  	//write to the pipe
  	if(fork() == 0) 
	{
		close(fds[0]);
        printf("Producer process \n");
   		for(i=0; i<1; i++)
   		{   
        		write(fds[1],&input[i],strlen(&input[i]));
    		}
		exit(0);
	}

  	//consumer reads
	else if(fork() == 0) 
	{
  		close(fds[1]); 
  	    	printf("Consumer process \n");
    		
    		while((count=read(fds[0],buff,100))>0)
    		{
        		for(i=0; i<count; i++)
        		{
            			write(1, buff+i, 1);
        			write(1, "", 1); 
			}
        		printf("\n");
    		}
		exit(0);
	}

	else
	{
  		close(fds[0]); 
		close(fds[1]);
		wait(0);
  		wait(0);
	}
  	return 0;
}
