//n queen problem //placing 8 queens in N*N
#include<iostream>
using namespace std;
int collides(int* a,int row)//returns 0 if no collision ,1 if collision
{
    int res=0;
    if(row==1)
        res= 0;
    else
    {
        int queen_place=a[row];

        for(int i=1;i<=row-1;++i)
        {
            if(a[i]==queen_place||queen_place==(a[i]+(row-i))||queen_place==(a[i]-(row-i)))
            {
                res=1;
                break;
            }

        }
    }
    return res;
}

int calculate_util(int*a,int n,int row,int &count)
{
    for(int i=1;i<=n;++i)
    {
            a[row]=i;
            if(!collides(a,row))
            {
                if(row<n)
                calculate_util(a,n,row+1,count);
                else
                {

                    count++;
                }
            }



    }
}
int calculate(int n)
{
    int a[n];
    int count=0;
    calculate_util(a,n,1,count);
    cout<<count;
}


int main()
{

    calculate(12);
}
