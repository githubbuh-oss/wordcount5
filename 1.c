#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[80];
	int i, num = 0;
	gets(a);
	for (i = 0; a[i] != '\0'; i++) //这里应该检百查到串尾,字符串结束度符是'\0'
	{
		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) //如果是知字母，则一直找到非字母（道分隔符版:符号，空格等）
		{
			do {
				i++;
			} while ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'));
			//记录一个单词权
			num++;
		}
	}
	printf("%d\n", num);
	return 0;
}