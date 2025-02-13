#include<stdio.h>
int fibo(int);
int main(){
	int num;
	printf("enter the value: ");
	scanf("%d",&num);
	printf("The fibonacci series at the %d is %d.",num,fibo(num));
	printf("the fibonacci numbers upto %d term are: ",num);
	printf("\n");
	int i;
	for(i=0;i<=num;i++){
		printf("%d\n",fibo(i));
	}
	
	return 0;
}
int fibo(int n){
	if(n==0)
	 return 0;
	else if(n==1 || n==2)
	 return 1;
	else
	 return fibo(n-1)+fibo(n-2);
	
}
