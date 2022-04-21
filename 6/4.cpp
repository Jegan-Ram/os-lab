#include <bits/stdc++.h>
using namespace std;
#define count 0
int track[3][100];
void recursivePart(int pages[]){
    int st, len;
    cout << "Enter the index of the starting block and its length: ";
    cin >> st >> len;
    int k = len;
    if (pages[st] == 0){
        for (int j = st; j < (st + k); j++){
            if (pages[j] == 0){
                pages[j] = 1;
                track[count][j]=1;
                cout << j << "------>" << pages[j] << endl;
            }
            else {
                cout << "The block "<< j << " is already allocated" << endl;
                k++;
                track[count][j]=0;
            }
        }
    }
    else
        cout <<"The block " << st << " is already allocated" << endl;
    cout << "Do you want to enter more files?" << endl;
    cout << "Enter 1 for Yes, Enter 0 for No: ";
    int c;
    cin >> c;
    if (c==1)
        recursivePart(pages);
    else
        exit(0);
    return;
}
int main(){
    int pages[100], p, a,nn;
    for (int i = 0; i < 100; i++)
        pages[i] = 0;
    cout << "Enter the number of blocks already allocated: ";
    cin >> p;
    cout << "Enter the blocks already allocated: ";
    for (int i = 0; i < p; i++){
        cin >> a;
        pages[a] = 1;
    }
    recursivePart(pages);
    count++; 
    cout<<"Select option to see allocation for each process: 1.Factorial\n2.Calculate\n3.Interest";
    cin>>nn;
    switch(nn){
    case 1:
      for(int i=0;i<100;i++){
         cout<<track[0][i];
    }
      break; 
    case 2:
      for(int i=0;i<100;i++){
         cout<<track[1][i];
    }
    break; 
    case 3:
      for(int i=0;i<100;i++){
         cout<<track[2][i];
    }
    break; }
    return 0;
}
