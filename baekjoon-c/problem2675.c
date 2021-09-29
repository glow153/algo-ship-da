#include <stdio.h>
int main(void){
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;t++){
		int n;
		char str[21];
		scanf("%d %s",&n, str);
		for(int i=0;str[i]!=0;i++)
			for(int j=0;j<n;j++)
				printf("%c",str[i]);
		putchar('\n');
	}
	return 0;
}