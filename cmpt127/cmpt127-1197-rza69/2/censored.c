#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
char word[128];
int index = 0;
int c = getchar();
int found = 0;

while (c != EOF){
    if ((c>='A' && c<='Z') || (c>='a' && c<='z') || c == '\''){
        if ( index+1 < sizeof(word) ) {
          word[index] = (char)c;
          index++;
        }
        word[index] = '\0';
    }
    else{ 
        if (index > 0){
            found = 0;
            for (int i=1;i<argc;i++){
                if (strcmp(word,argv[i]) == 0){
                    printf("CENSORED");
                    found = 1;
                    break;
                }
            }
            if (found != 1){
                printf("%s",word);
            }

        }
        word[0] = '\0';
        index = 0;
        printf("%c",(char)c);
    }
    c = getchar();
  }
}
