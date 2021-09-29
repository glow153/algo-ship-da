#include <stdio.h>
#define mod (1000000007)
long long basicMat[4] = { 1, 1, 1, 0 };
long long calcMat[4];
long long* mul(long long mat1[4], long long mat2[4]){
	long long newMat[4];
	newMat[0] = (mat1[0] * mat2[0] + mat1[1] * mat2[2]) % mod;
	newMat[1] = (mat1[0] * mat2[1] + mat1[1] * mat2[3]) % mod;
	newMat[2] = (mat1[2] * mat2[0] + mat1[3] * mat2[2]) % mod;
	newMat[3] = (mat1[2] * mat2[1] + mat1[3] * mat2[3]) % mod;
	for (int i = 0; i < 4; i++)
		calcMat[i] = newMat[i];
	return calcMat;
}
long long* fib(long long n){
	if (n == 1)
		return basicMat;
	long long* mat = fib(n / 2);
	mat = mul(mat, mat);
	if (n % 2 == 1)
		mat = mul(mat, basicMat);
	return mat;
}
long long fibonacci(long long n){
	long long* mat = fib(n);
	return mat[1];
}
int main(){
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", fibonacci(n));
}
