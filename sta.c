//Atharv Nishikant Bhole
//FY23I002

#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<ctype.h>
#define size 30

int stack[size];
int top = -1;
void push(float e);
float pop();
int isFull();
int isEmpty();
void main(){
	char postfix[30];
	float r;
	char c;
	int i = 0;
	float op1, op2;
	char opr; 
	printf("enter the number in postfix form\n");
	
	while (  (c = getchar()) != '$'){
		postfix[i] = c;
		i++;
	}
	for (int j = 0 ; j < i ; j++){
		if (isdigit (postfix[j]) ){
		push(postfix[j] - '0');
		}
		else{
		opr = postfix[j];
		op2 = pop();
		op1 = pop();
		//printf("%f", op2);
		//printf("%f", op1);
		
		if (opr == '+'){
		r = op1 + op2;
		//printf("%f", r);
		}
		else if (opr == '-'){
		r = op1 - op2;
		}
		else if (opr == '*'){
		r = op1 * op2;
		}
		else if (opr == '/'){
		r = op1 / op2;
		}
		
		push (r);
		}
		
	}
	//printf("%f", r);
	printf("%f", pop());
	printf("\n");
return;
}

void push (float element){
	if (top == size -1){
		printf("STACK FULL");
		return;
	}
	else {
	stack[++top] = element ; 
	}
	return;
}

float pop(){
	float element = LONG_MIN;
	if (top == -1){
		return element;
	}
	element = stack[top];
	top--;
	return element;
}

int isFull(){
	return top == size - 1;
}

int isEmpty(){
	return top == -1;
}










