#include <stdio.h>

int main(void)
{
	int count = 0;
	char str[1000000];
	fgets(str, 1000000, stdin);

	for(int i=0;i<1000000;i++)
	{
		if(str[i] == '\0')
			break;
		else if(str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\0')){
			printf("%c\n",str[i]);
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}