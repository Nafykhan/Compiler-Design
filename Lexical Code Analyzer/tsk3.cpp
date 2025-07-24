#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    cout<<"Enter a line: ";
    getline(cin, a);
    if (a.length()>=2&&a[0]=='/'&&a[1]=='/')
    {
        cout<< "Single-line comment" << endl;
    }
    else if(a.length()>=4 && a.substr(0,2)=="/*"&&a.substr(a.length()-2)=="*/")
    {
        cout << "Multi-line comment" << endl;
    }
    else
    {
        cout<< "not a comment" << endl;
    }

    return 0;
}
