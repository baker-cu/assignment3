#include <iostream>
#include "DelCheck.cpp"

using namespace std;

int main()
{
    string file;
    cout<<"Enter the filepath for the code you would like to check: "<<endl;
    cin>>file;

    DelCheck* syn_checker = new DelCheck(file);
    syn_checker->check();

    return 0;
}
