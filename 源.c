#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int CharCount(char* Path)
{    //计算字符个数

    FILE* file = fopen(Path, "r");
    //assert(file != NULL);    //若文件不存在则报错

    char code;
    int count = 0;

    while ((code = fgetc(file)) != EOF)     //读取字符直到结束
        count += ((code != ' ') && (code != '\n') && (code != '\t'));    //判断是否是字符    

    fclose(file);

    return count;
}

int WordCount(char* Path)
{    //计算单词个数

    FILE* file = fopen(Path, "r");
    /* assert(file != NULL);*/

    char word;
    int is_word = 0;    //用于记录字符是否处于单词中
    int count = 0;

    while ((word = fgetc(file)) != EOF) {
        if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) {    //判断是否是字母            
            count += (is_word == 0);
            is_word = 1;    //记录单词状态
        }
        else
            is_word = 0;    //记录不处于单词状态
    }
    fclose(file);

    return count;
}


int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-c") == 0)
    {
        printf("字符数:%d", CharCount(argv[2]));

    }
    if (strcmp(argv[1], "-w") == 0)
    {
        printf("单词数:%d", WordCount(argv[2]));

    }
}






