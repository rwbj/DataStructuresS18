#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    char *fileName = "./input3";
    char buff[1024];
    int alph[256], letterCount, totalLetters = 0;
    double frequ[26];
    memset(alph,0,sizeof(int)*256);
    FILE *f;

    f = fopen(fileName, "r");

    while (fgets(buff,sizeof(buff),f) && !feof(f)){
        for(letterCount = 0; buff[letterCount+1]; letterCount++){
            if (buff[letterCount]>0 && buff[letterCount]<256) {
                alph[buff[letterCount]]++;
            }
            //printf("%c %d\n", buff[letterCount], alph[buff[letterCount]]);
        }
        totalLetters += letterCount;
        //printf("%d\t%d\t%c\t%s", totalLetters, letterCount, buff[1], buff);
    }
    for(int i = 'a'; i <= 'z'; i++){
        frequ[i-'a'] = ((double)alph[i])/((double)totalLetters);
        printf("%c %d\t%f\n", i, alph[i], frequ[i-'a']);
    }
    //printf("totalLetters: %d\n", totalLetters);
}