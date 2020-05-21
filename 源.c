#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int CharCount(char* Path)
{    //�����ַ�����

    FILE* file = fopen(Path, "r");
    //assert(file != NULL);    //���ļ��������򱨴�

    char code;
    int count = 0;

    while ((code = fgetc(file)) != EOF)     //��ȡ�ַ�ֱ������
        count += ((code != ' ') && (code != '\n') && (code != '\t'));    //�ж��Ƿ����ַ�    

    fclose(file);

    return count;
}

int WordCount(char* Path)
{    //���㵥�ʸ���

    FILE* file = fopen(Path, "r");
    /* assert(file != NULL);*/

    char word;
    int is_word = 0;    //���ڼ�¼�ַ��Ƿ��ڵ�����
    int count = 0;

    while ((word = fgetc(file)) != EOF) {
        if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) {    //�ж��Ƿ�����ĸ            
            count += (is_word == 0);
            is_word = 1;    //��¼����״̬
        }
        else
            is_word = 0;    //��¼�����ڵ���״̬
    }
    fclose(file);

    return count;
}


int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-c") == 0)
    {
        printf("�ַ���:%d", CharCount(argv[2]));

    }
    if (strcmp(argv[1], "-w") == 0)
    {
        printf("������:%d", WordCount(argv[2]));

    }
}






