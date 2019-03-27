#include <iostream>
#include <fstream>
#include "DelCheck.h"

using namespace std;

DelCheck::DelCheck(string file)
{
    filepath = file;
    this->gs = new GenStack<char>();
}

DelCheck::~DelCheck()
{
    filepath = "";
    delete this->gs;
}

void DelCheck::check()
{
    int line_num = 1;
    int leng = 0;
    string line = "";
    GenStack<int>* error = new GenStack<int>();

    ifstream code(filepath); //open file with code for checking

    //iterate through given file
    while(getline(code, line))
    {
        int leng = line.length();
        for(int i = 0; i<leng; i++)
        {
            //push each open delimeter {,[,(
            if(line[i] == '{' || line[i] == '[' || line[i] == '(')
            {
                gs->push(line[i]);
                error->push(line_num);
                continue;
            }

            //when a close delimeter is found
            //use peak to check if the opener on top matches the closer
            //if it does...pop
            //if it doesn't print where (line) the error is and exit
            if(line[i] == '}')
            {
                if(gs->peak() == '[')
                {
                    cout<<"Missing ']' on line: "<<error->peak()<<endl;
                    exit(1);
                }
                if(gs->peak() == '(')
                {
                    cout<<"Missing ')' on line: "<<error->peak()<<endl;
                    exit(1);
                }
                else
                {
                    gs->pop();
                }
            }

            if(line[i] == ']')
            {
                if(gs->peak() == '{')
                {
                    cout<<"Missing '}' on line: "<<error->peak()<<endl;
                    exit(1);
                }
                if(gs->peak() == '(')
                {
                    cout<<"Missing ')' on line: "<<error->peak()<<endl;
                    exit(1);
                }
                else
                {
                    gs->pop();
                }
            }

            if(line[i] == ')')
            {
                if(gs->peak() == '[')
                {
                    cout<<"Missing ']' on line: "<<error->peak()<<endl;
                    exit(1);
                }
                if(gs->peak() == '{')
                {
                    cout<<"Missing '}' on line: "<<error->peak()<<endl;
                    exit(1);
                }
                else
                {
                    gs->pop();
                }
            }

        }
        line_num++; //increment line count
    }

    code.close();

    if(!gs->isEmpty())
    {
        if(gs->peak() == '{')
        {
            cout<<"Missing '}' at end of file."<<endl;
            exit(1);
        }

        if(gs->peak() == '[')
        {
            cout<<"Missing ']' at end of file."<<endl;
            exit(1);
        }

        if(gs->peak() == '(')
        {
            cout<<"Missing ')' at end of file."<<endl;
            exit(1);
        }

    }

    cout<<"No delimeter errors were found."<<endl;
}
