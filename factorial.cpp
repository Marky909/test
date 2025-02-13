#include<stdio.h>
long long int factorial(int);
int main(){
	 int num;
	printf("enter the number for calculation of factorial: ");
	scanf("%d",&num);
	
	printf("the factorial of %d is %lld",num,factorial(num));
	return 0;
}
long long int factorial(int n){
	if(n==0){
		return 1;
	}
	else
	 return n*factorial(n-1);
}
