#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void StructT(int a[6][6],int price[5],int use[5])
{
    for(int i=0;i<5;i++){
        for(int j=i;j<5;j++){
            int b=j-i;
            switch(b)
            {
            case 0:
                a[i][j+1]=price[i]+use[0];
                break;
            case 1:
                a[i][j+1]=price[i]+use[0]+use[1];
                break;
            case 2:
                a[i][j+1]=price[i]+use[0]+use[1]+use[2];
                break;
            case 3:
                a[i][j+1]=price[i]+use[0]+use[1]+use[2]+use[3];
                break;
            case 4:
                a[i][j+1]=price[i]+use[0]+use[1]+use[2]+use[3]+use[4];
                break;
            }

        }
    }
}
void Floyd(int a[6][6],int c[6][6],int p[6][6],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=a[i][j];
            p[i][j]=-1;
        }
    }
    for(int k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if((c[i][k]!=0)&&(c[k][j]!=0)){
                    if(c[i][k]+c[k][j]<c[i][j]){
                        c[i][j]=c[i][k]+c[k][j];
                        p[i][j]=k;
                    }
                }
            }
        }
    }
}
void Print(int c[6][6], int p[6][6],int i,int j)
{
    i--;
    j--;
    stack<int> s;
    cout<<"总费用为："<<endl;
    cout<<c[i][j]<<endl;
    while(p[i][j]!=-1){
            j=p[i][j];
            if(j!=-1)
            s.push(j+1);
        }
    cout<<"只需在这些年买入新设备即可："<<endl;
    cout<<"1 ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    int price[5],use[5],a[6][6]={0},c[6][6],p[6][6];
    cout << "请输入1-5年购买设备的费用" << endl;
    for(int i=0;i<5;i++)
        cin>>price[i];
    cout<<"请输入设备使用期间每年的维护费用"<<endl;
    for(int i=0;i<5;i++)
        cin>>use[i];
    StructT(a,price,use);
    Floyd(a,c,p,6);
    Print(c,p,1,6);
    return 0;
}
