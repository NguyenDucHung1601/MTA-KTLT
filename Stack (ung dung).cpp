#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
	int Data;
	char character;
	struct Stack *next;
}Node;
Node *top;

void Push(int data);
int Pop();
void display();

int main(){ // CHUYEN DOI 1 SO TU HE 10 SANG HE 2
	top=NULL;
	int choice, value,div;	
	printf("-- PROGRAM: SOME ALGORITHM USE STACK _ Nguyen Duc Hung --\n\n");
	printf("\nPlease choose task:");
	printf("\n  1. DEC -> BIN");
	printf("\n  2. DEC -> HEX");
	printf("\n  3. Reverse Array");
	printf("\n  4. Reverse Chain");
	printf("\nYou choose: ");
	scanf("%d",&choice);
	// DEC -> BIN
	if(choice==1){
		printf("\n  - Enter number (DEC) : ");
		scanf("%d",&value);
		div=value;
		while(div>0){
		Push(div%2);
		div=int(div/2);
		}
		printf("  - Number (BIN)       : ");
		display(); // doc stack tu dinh xuong day --> hien thi ra man hinh dang nhi phan cua so vua chuyen
	}
	
	// DEC -> HEX
	if(choice==2){
		printf("\n  - Enter number (DEC) : ");
		scanf("%d",&value);
		div=value;
		while(div>0){
			Push(div%16);
			div=int(div/16);
		}
		printf("  - Number (HEX)       : ");
		for(Node *p=top; p!=NULL; p=p->next){
			if(p->Data >=0 && p->Data<=9)	printf("%d",p->Data);
			else{
				if(p->Data==10)			printf("A");
				else if(p->Data==11)	printf("B");
				else if(p->Data==12)	printf("C");
				else if(p->Data==13)	printf("D");
				else if(p->Data==14)	printf("E");
				else 					printf("F");
			}
		}
		printf("\n");
	}
	
	// REVERSE ARRAY
	if(choice==3){
		int n;
		printf(" - The number of array element: ");
		scanf("%d",&n);
		int a[n]; // mang 1 chieu x voi n ptu
		for(int i=0; i<n; i++){
			printf("    a[%d]= ",i+1);
			scanf("%d",&a[i]);
			Push(a[i]); // duyet mang tu dau den cuoi, lan luot lay cac ptu cua mang cho vao stack
		}
		printf(" - First array   : ");
		for(int i=0; i<n; i++){
			printf("%d   ",a[i]);
		}
		printf("\n - Reverse array : ");
		for(int i=0; i<n; i++){
			a[i]=Pop();
			printf("%d   ",a[i]);
		}
		printf("\n");
	}
	
	// REVERSE CHAIN
	if(choice==4){
		char character[50]; // mang character luu chuoi ki tu
		printf(" - Enter chain character   :  ");
		fflush(stdin);
		gets(character);
		for(int i=0; i<strlen(character); i++){
		Push(character[i]);   // lan luot day cac ki tu trong chuoi vao Stack
		}
		printf(" - Reverse chain character :  ");
		for(int i=strlen(character); i>0; i--){ 
		printf("%c",Pop()); // lan luot Pop tung ki tu tu Stack, in ra man hinh --> chuoi dao nguoc
		}
		printf("\n");
	}	
	
	// FINISH
	printf("\nDo you want to continue the program? (1. Yes / 2. No): ");			
	scanf("%d",&choice);
	if(choice==1){
		system("cls");
		return main();
	}
	else{
		printf("\nThank you for using the program!\n");
		return 0;
	}
}

void Push(int data){
	Node *p=(Node *)malloc(sizeof(Node));
	p->Data=data;
	p->next=top;
	top=p;
}

int Pop(){
	int n = top->Data;
	Node *temp=top;
	top=top->next;
	free(top);
	return n;
}
void display(){
	for(Node *p=top; p!=NULL; p=p->next)	printf("%d",p->Data);
	printf("\n");
}

