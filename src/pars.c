#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int pars_test_name(const char name[])
{
    char circle[7];
    int i = 0;
    while (i != 6) {
        circle[i] = name[i];
        ++i;
    }
    circle[i] = '\0';
    if (strcmp(circle, "circle") == 0)
        return 1;
    else
        return -1;
}

int pars(char const name[], float a[])
{
    char ch[10];
    int i = 0, j = 0, k = 0, m = 0;
    while (1) {
        if (pars_test_name(name) == 1) {
            while (name[i] != '\0') {
                if (isdigit(name[i])) {
                    if (name[i + 1] == '.' || isdigit(name[i + 1]) != 0
                        || name[i - 1] == '-') {
                        if (name[i - 1] == '-')
                            --i;
                        while (name[i] != ')' && name[i] != ' '
                               && name[i] != ',') {
                            ch[m] = name[i];
                            ++m;
                            ++i;
                            ch[m] = '\0';
                        }
                        a[j] = atof(ch);
                        ++j;
                        m = 0;
                        for (int t = 0; t < 10; ++t) {
                            ch[t] = '\0';
                        }
                    } else {
                        ch[k] = name[i];
                        a[j] = atof(ch);
                        ++j;
                        k = 0;
                    }
                }
                ++i;
            }
            if (name[i] == '\0')
                break;
        } else
            return -1;
    }
    return 1;
}