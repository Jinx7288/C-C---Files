#include<iostream>
#include<algorithm>
#include<set>
#include<functional>
#include<vector>
int n;
typedef struct score
{
    int index;
    int data[110];
    bool operator==(const score &b)const{
        for (int i = 0; i < n; i++)
        {
            if(data[i]!=b.data[i])
                return false;
        }
        return true;
    }
}Score;
Score scs[100];
int main()
{
	for (int i = 0; i < 10; i++)
	{
		
	}
	
}