#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int val = 10;
    char * valchar = itoa(val);
    string chaine = string(valchar);

    return 0; 
}