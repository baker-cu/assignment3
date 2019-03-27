#ifndef DEL_CHECK_H
#define DEL_CHECK_H

#include <iostream>
#include "GenStack.h"

using namespace std;

class DelCheck
{
    public:
        DelCheck(string file);
        ~DelCheck();

        void check();

    private:
        string filepath;
        GenStack<char>* gs;

};

#endif
