#include<iostream>
using namespace std;
int matrix[10][6];

void sort(int num, int matrix[][6])
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (matrix[j][1] > matrix[j + 1][1]) {
				for (int k = 0; k < 5; k++) {
					swap(matrix[j][k], matrix[j + 1][k]);
				}
			}
		}
	}
}
void function(int num, int matrix[][6])
{
	int temp, val=0;
    for(int i=0;i<num;i++){
        matrix[i][4]+=val;
        val+=matrix[i][2];
        matrix[i][5]+=val;
    }
     
}

int main()
{
	int num, temp;
    float wait=0.0,turn=0.0;

	cout << "Enter number of Process: ";
	cin >> num;
	for (int i = 0; i < num; i++) {
		cout << "Enter Process Id: ";
		cin >> matrix[i][0];
  		cout << "Enter Arrival Time: ";
		cin >> matrix[i][1];
		cout << "Enter Burst Time: ";
		cin >> matrix[i][2];
	}
	cout << "Process ID\tArrival Time\tBurst Time\n";
	for (int i = 0; i < num; i++) {
		cout << matrix[i][0] << "\t\t" << matrix[i][1] << "\t\t"<< matrix[i][2] << "\n";
	}

	sort(num, matrix);
	function(num, matrix);
    
	cout <<endl<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
	for (int i = 0; i < num; i++) {
		cout << matrix[i][0] << "\t\t" << matrix[i][1] << "\t\t"<< matrix[i][2] << "\t\t" << matrix[i][4] << "\t\t"<< matrix[i][5] << "\n";
        wait+=matrix[i][4];
        turn+=matrix[i][5];   
	}

    cout<<"Average waiting time ="<<wait/num<<endl;
    cout<<"Average turnaround time ="<<turn/num<<endl;
	return 0;
}
