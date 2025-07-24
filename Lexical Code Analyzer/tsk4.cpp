#include <iostream>
using namespace std;
int main()
{
     string a;
    int flag=1;

    cout<<"enter input: ";
    cin>>a;
    string keywords[] = {"int", "float", "double", "bool"};

    for (const string& keyword : keywords) {
        if (a == keyword) {
            flag = 0;
            break;
        }
    }

    char ch=a[0];
    if (!((ch>='A'&&ch<='Z')||(ch >= 'a' && ch <= 'z')|| ch=='_' ))
    {
        flag=0;
    }
    else
    {
        for(int i=1;i<a.length();i++)
        {
            char c=a[i];
            if(!((ch>='A'&&ch<='Z')||(ch >= 'a' && ch <= 'z')||(c >= '0' && c <= '9')|| ch=='_' ))
            flag=0;
            break;
        }

    }

    if(flag==1)
    {
        cout<<"Valid Identifire";
    }
    else
    {
        cout<<"Invalid Identifire";
    }


 return 0;
}
