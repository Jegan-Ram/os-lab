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
        	cout << "Enter Integers : ";
        	int array[n];
        	for(int i=0;i<n;i++){
        		cin>>array[i];
        	}
        	int shm_id = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
        	int *shared_memory = (int *)shmat(shm_id, NULL, 0);
        	for(int i=0;i<n;i++){
        	shared_memory[i]=array[i];
        	}
	}
	else{
		wait(0);
		cout<<"Parent Process"<<endl;
		int shm_id = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
        	int *shared_memory = (int *)shmat(shm_id, NULL, 0);
        	int sum=0;
        	for (int i = 0; i < 5; i++){
        		sum+=shared_memory[i];
        	}
        	cout << "Sum of Integers:" << sum << endl;
        	
	}

	
	return 0;
}
