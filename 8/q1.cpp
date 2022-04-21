#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
using namespace std;

int main(){
int pid=fork();
if(pid==0){
cout<<"Child Process"<<endl;
int n;
cin >> n;
cout << "String : ";
char s[n];
        	for(int i=0;i<n;i++){
        		cin>>s[i];
        	}
        	int shm_id = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
        	char *shared_memory = (char *)shmat(shm_id, NULL, 0);
        	strcpy(shared_memory, s);
		
	}
	else{
		wait(0);
		cout<<"Parent Process"<<endl;
		int shm_id = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
        	char *shared_memory = (char *)shmat(shm_id, NULL, 0);
        	int vowels=0;
        	for (int i = 0; i < strlen(shared_memory); i++){
        		if(shared_memory[i]=='a' || shared_memory[i]=='e' || shared_memory[i]=='i' ||shared_memory[i]=='o' || shared_memory[i]=='u' ){
        			vowels++;
        		}	
        	}
        	cout << "No.of Vowels:" << vowels << endl;
        	
	}

	
	return 0;
}
