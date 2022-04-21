#include<stdio.h>
#include<unistd.h>

int main() {
   int pipefds[2];
   int returnstatus;
   int pid;
   char writemessages[20];
   printf("Enter the message to be written to the pipe: ");
   fgets(writemessages, 20, stdin);
   char readmessage[20];
   returnstatus = pipe(pipefds);
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   pid = fork();
   
   // Child process
   if (pid == 0) {
	   printf("Child Process - Writing to pipe -  %s\n", writemessages);
      write(pipefds[1], writemessages, sizeof(writemessages));
   } else { //Parent process

   	  read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Parent Process - Reading from pipe -  %s\n", readmessage);
      
		int c = 0, count = 0;
		while (readmessage[c] != '\0') {
			if (readmessage[c] == 'a' || readmessage[c] == 'A' || readmessage[c] == 'e'
			 || readmessage[c] == 'E' || readmessage[c] == 'i' || readmessage[c] == 'I' 
			 || readmessage[c] =='o' || readmessage[c]=='O' 
			 || readmessage[c] == 'u' || readmessage[c] == 'U')
			count++;
			c++;
		}

		printf("Number of vowels in the string: %d\n", count);
   }
   return 0;
}