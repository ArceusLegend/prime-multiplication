#include<stdio.h>

int checkPrime(int a){ //checks if a is a prime
	int i, c, temp;
	c=0;
	
	for(i=1; i<=a; i++){
		temp=a%i;
		if(temp==0){
			c++;
		}
	}
	return c;
}

void fillPrime(int p[50]){ //fills p with all primes between 1 and 100
	int i, r, temp;
	r=0;
	
	for(i=2; i<100; i++){
		temp=checkPrime(i);
		if(temp==2){
			p[r]=i;
			r++;
		}	
	}
}

int main(){
	int i, p[50], x, temp;
	
	printf("Enter a number between 1 and 100: ");
	scanf("%d", &x);
	while(x<1 || x>100){ //check if x is within bounds
		printf("Invalid input. Please enter a number between 1 and 100: ");
		scanf("%d", &x);
	}
	
	fillPrime(p);
	i=0;
	
	printf("%d can be written as the multiplication of: ", x);
	do{
		do{
			temp=x%p[i];
			if(temp==0){
				printf("%d\n", p[i]);
				x=x/p[i];
			}
		}while(temp==0);
		i++;
	}while(x!=1);
}
