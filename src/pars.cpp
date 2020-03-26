#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>


void pars(char name[], float a[]) 
{
    char ch[10];
    int i = 0, j = 0, k = 0, m = 0;
    while (name[i] != '\0') {
        if (isdigit(name[i])) {
            if (name[i + 1] == '.' || isdigit(name[i + 1]) != 0) {
                while (name[i] != ')' && name[i] != ' ' && name[i] != ',') {
                    ch[m] = name[i];
                    ++m;
                    ++i;
                    ch[m] = '\0';
                }
                a[j] = atof(ch);
                ++j;
                m = 0;
                ch[1] = '\0';
                ch[2] = '\0';
                ch[3] = '\0';
                ch[4] = '\0';
                ch[5] = '\0';
                ch[6] = '\0';
                ch[7] = '\0';
                ch[8] = '\0';
                ch[9] = '\0';
            } else {
                ch[k] = name[i];
                a[j] = atof(ch);
                ++j;
                k = 0;
            }
        }
        ++i;
    }
}