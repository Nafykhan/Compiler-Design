#include <iostream>
using namespace std;
int main()
{
    string a;
    char operators[100];
    int opCount=0;


    cout<<"Give an expression: ";
    cin >> a;
     for (int i=0;i<a.length();i++)
     {
         char ch=a[i];
         if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=')
         {
             if(opCount<100)
             {
                 operators[opCount]=ch;
                 opCount++;
             }
         }

     }

    if(opCount>0)
    {
        for(int i = 0; i < opCount; i++)
        {
            cout << "operator" << i + 1 << "= " << operators[i] << endl;
        }
    }
    else {
        cout << "No arithmetic operator found." << endl;
    }


    return 0;
}
