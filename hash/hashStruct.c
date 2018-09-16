#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    struct node *b1, *b0;
    int key, letter, count, sumCount;
    float freq;
} tree;

//void link()

void buildHash(tree *h){
    printf("size of list: %d\n", sizeof(h));
    printf("counts of c: %d\n", h[2].count);
    /*int low = 0, low2 = 1;
    for(int i = 0; i<26; i++){
        if (h[i].sumCount != -1){
            if (h[i].sumCount < h[low].sumCount){
                low2 = low;
            }
        }
    }*/
}

void main(){
    char *fileName = "./input3";
    char buff[1024];
    int alph[256], letterCount, totalLetters = 0;
    float frequ[26];
    tree hashTree[26];
    memset(alph,0,sizeof(int)*256);
    memset(hashTree, 0, sizeof(tree)*26);
    FILE *f;

    f = fopen(fileName, "r");

    while (fgets(buff,sizeof(buff),f) && !feof(f)){
        for(letterCount = 0; buff[letterCount+1]; letterCount++){
            if (buff[letterCount] >= 'a' && buff[letterCount] <= 'z') {
                //alph[buff[letterCount]]++;
                hashTree[buff[letterCount]-'a'].count++;
                hashTree[buff[letterCount]-'a'].sumCount++;
            }
            //printf("%c %d\n", buff[letterCount], alph[buff[letterCount]]);
        }
        totalLetters += letterCount;
        //printf("%d\t%d\t%c\t%s", totalLetters, letterCount, buff[1], buff);
    }
    for(int i = 'a'; i <= 'z'; i++){
        hashTree[i-'a'].letter = i;
        //frequ[i-'a'] = ((float)alph[i])/((float)totalLetters);
        hashTree[i-'a'].freq = ((float)hashTree[i-'a'].count)/((float)totalLetters);
        //printf("%c %d\t%f\n%c %d\t%f\n", i, alph[i], frequ[i-'a'], hashTree[i-'a'].letter, hashTree[i-'a'].count, hashTree[i-'a'].freq);
        printf("%c\t%d\t%f\n", hashTree[i-'a'].letter, hashTree[i-'a'].count, hashTree[i-'a'].freq);
    }
    //printf("totalLetters: %d\n", totalLetters);
    buildHash(hashTree);

}