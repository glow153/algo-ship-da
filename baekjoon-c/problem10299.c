#include <stdio.h>
#include <stdlib.h>
int getExp(const char* src, int startIdx){
	char num[100]={0};
	int i = startIdx, endIdx;
	int exp;
	while(1){
		if(!('0' <= src[i] && src[i] <= '9')){
			endIdx = i;
			break;
		}
		i++;
	}
	for(int j=0;j<=endIdx-startIdx+1;j++)
		num[j] = src[startIdx+j];
	exp = atoi(num);
	if(exp==0)
		return 1;
	else
		return exp;
}
double getMoleWeit(const char* form){
	const double O = 15.9994;
	const double C = 12.011;
	const double H = 1.00794;
	const double S = 32.066;
	const double N = 14.00674;
	double weight = 0.0;
	for(int i=0;form[i]!=0;i++){
		switch(form[i]){
		case 'O':
			weight += O*getExp(form,i+1);
			break;
		case 'C':
			weight += C*getExp(form,i+1);
			break;
		case 'H':
			weight += H*getExp(form,i+1);
			break;
		case 'S':
			weight += S*getExp(form,i+1);
			break;
		case 'N':
			weight += N*getExp(form,i+1);
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			break;
		default:
			return -1;
		}
	}
	return weight;
}
int main(void){
	int input;
	scanf("%d",&input);
	for(int i=0;i<input;i++){
		double weight;
		char form[101]={0};
		scanf("%s",form);
		weight = getMoleWeit(form);
		if((int)weight==-1)
			printf("Invalid formula\n");
		else
			printf("%.4lf\n",weight);
	}
	return 0;
}