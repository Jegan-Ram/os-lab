#include<bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				break;
			}
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

void bestFit(int blockSize[], int m, int processSize[], int n)
{
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));

	for (int i=0; i<n; i++)
	{
		int bestIdx = -1;
		for (int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (bestIdx == -1)
					bestIdx = j;
				else if (blockSize[bestIdx] > blockSize[j])
					bestIdx = j;
			}
		}
		if (bestIdx != -1)
		{
			allocation[i] = bestIdx;
			blockSize[bestIdx] -= processSize[i];
		}
	}
	
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

void worstFit(int blockSize[], int m, int processSize[], int n)
{
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));
	for (int i=0; i<n; i++)
	{
		int wstIdx = -1;
		for (int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (wstIdx == -1)
					wstIdx = j;
				else if (blockSize[wstIdx] < blockSize[j])
					wstIdx = j;
			}
		}
		if (wstIdx != -1)
		{
			allocation[i] = wstIdx;
			blockSize[wstIdx] -= processSize[i];
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

int main()
{
	int blockSize[] = {100, 450, 250, 300, 600};
	int processSize[] = {212, 317, 172, 426};
	int m = sizeof(blockSize)/sizeof(blockSize[0]);
	int n = sizeof(processSize)/sizeof(processSize[0]);
	int ch;
	cout<<"1.Best Fit\n2.Worst Fit\n3.First Fit\n";
	cin>>ch;
	switch(ch){
	case 1:
	cout<<endl<<"Best Fit: "<<endl;
	bestFit(blockSize, m, processSize, n);
	break;
	
	case 2:
        cout<<endl<<"Worst Fit: "<<endl;
	worstFit(blockSize, m, processSize, n);
	break;
	
	case 3:
	cout<<endl<<"First Fit: "<<endl;
	firstFit(blockSize, m, processSize, n);
        break;
        
        default:
        cout<<"Wrong Input!!!!";
}
	return 0 ;
}
