#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main () 
{
	int i,j,k,Min=9999,I_count[10]={0,2,5,1,3,0,0,0,2,1},I_accumulation[10]={0};
	for(j=9;j>=0;j--)
		{
			if(I_count[j]!=0)
			{
				for(k=j;k>=0;k--)
				{
					if(I_count[k] != 0)
						I_accumulation[j] = I_accumulation[j] + I_count[k];
				}
			}
			if(I_accumulation[j] != 0 && I_accumulation[j] < Min)
				Min = I_accumulation[j];			
		}
	for(i=0;i<10;i++)
		cout<<I_count[i]<<endl;
	cout<<endl<<endl;
	for(i=0;i<10;i++)
		cout<<I_accumulation[i]<<endl;
	
	system("pause");
	return 0;
} 
