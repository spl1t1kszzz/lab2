#include <stdio.h>
#include <string.h>
#include "functions.h"

int main() {
    int d[256];
    char template[100];
    char source[100];
    FILE *in = fopen("in.txt", "r");
    FILE *out = fopen("out.txt", "w");
    fgets(template, 100, in);
    fgets(source, 100, in);
    int sourceLen = (int) strlen(source);
    int templateLen = (int) strlen(template)-1;
    if(sourceLen == 0 || templateLen == 0)
        fprintf(out, "%d", 0);
    for (int i = 0; i < 256; i++) {
        d[i] = templateLen;
    }
    for (int i = 0; i < templateLen - 1; i++)
        d[(unsigned char)template[i]] = templateLen - i - 1;
    int i = templateLen - 1;
    int j = i;
    int k;
    while (j >= 0 && i < sourceLen) {
        j = templateLen - 1;
        k = i;
        while (j >= 1 && source[k] == template[j]) {
            fprintf(out,"%d ", k + 1);
            j--;
            k--;
        }
        fprintf(out,"%d ", k + 1);
        i +=d[(unsigned char )source[i]];
    }
    return 0;
}