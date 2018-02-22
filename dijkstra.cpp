#include <iostream>

using namespace std;

int a[100][100];

int v[100];

int spt[100]={0};

int n;

int pick()

{

int i=0;

int mini=0;

while(spt[mini]!=0)

mini++;

for(i=0;i<n;i++)

if(spt[i]==0 && v[i]<v[mini])

mini=i;

return mini;

}

void compute()

{

int i=pick();

spt[i]=1;

int j;

for(j=0;j<n;j++)

if(a[i][j]!=0 && v[j]>(a[i][j]+v[i]))

v[j]=a[i][j]+v[i];

return;

}

int main()

{

int start;

cout<<”Enter the Dimension :”;

cin>>n;

int i,j;

cout<<”Enter the values in the matrix”;

for(i=0;i<n;i++)

for(j=0;j<n;j++)

cin>>a[i][j];

cout<<”Enter the starting node”;

cin>>start;

for(i=0;i<n;i++)

v[i]=INT_MAX;

v[start]=0;

for(i=0;i<n;i++)

compute();

cout<<endl<<”shortest_path_from_start_node_is”<<endl;

for(i=0;i<n;i++)

cout<<v[i]<<endl;

return 0;

}
