#include<iostream>
using namespace std;
int main()
{
    string a;
    int flag=1;

    cout<<"enter input: ";
    cin>>a;
    for(int i=0;i<a.length();i++)
    {
        int asciiValue = (int)a[i];
        if(asciiValue<48 || asciiValue>57)
        {
            flag=0;
            break;
        }
    }
    if(flag==1&&a.length()>0)
    {
        cout<<"Numeric Constant "<<endl;
    }
    else
    {
        cout<<" Not Numeric "<<endl;
    }



 return 0;
}
