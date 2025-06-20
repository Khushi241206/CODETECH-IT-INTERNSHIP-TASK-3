#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10]={"auto","break","case","const","contiue","char","if","int",
"do","else","default","goto","float","for","double","enum","return","long","short","signed",
"register","sizeof","struct","static","switch","unsigned","void","typedef","while",
"union","volatile"};

int isKeyword(char *word){
    for(int i=0; i<32; i++){
        if(strcmp(keywords[i],word)==0)
        return 1;
    }
    return 0;
}

int isOperator(char ch){
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='>'||ch=='<'||
    ch=='%'||ch=='&'||ch=='|'||ch=='!');
}

void analyzeFile(const char *filename){
    FILE *fp=fopen(filename,"r");
    if(!fp){
        printf("Cannot open file!\n");
        return;
    }
    char ch, word[50];
    int index=0;
    while((ch=fgetc(fp))!=EOF){
        if(isalpha(ch)||ch=='_'){
            word[index++]=ch;
        } else if(isdigit(ch)){
            if(index>0){
                word[index++]=ch;
            } else{
                if(index!=0){
                    word[index]='\0';
                    if(isKeyword(word))
                    printf("[Keyword]:%s\n",word);
                    else
                    printf("[Identifier]:%s\n",word);
                    index=0;
                }
                if(isOperator(ch)){
                    printf("[Operator]:%c\n",ch);
                }
                
            }
        }
        }
        fclose(fp);
     }
     
int main() {
    char filename[100];
    printf("Enter the filename to analyze:");
    scanf("%s",filename);
    analyzeFile(filename);
    return 0;
}
