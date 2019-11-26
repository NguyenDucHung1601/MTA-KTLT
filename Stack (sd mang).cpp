#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10 // so ngan lon nhat co the cua Stack

// CAU TRUC DU LIEU CUA STACK
struct Stack{ // kieu cac truc Stack
	int a[MAXSIZE+1]; // mang a luu cac ptu cua stack, ptu a[0] khong dung toi
	int top;  		  // bien "top" de nho dinh cua stack, gtri cua top cung la so ptu cua stack
}s; // s: bien cau truc 

// 	NGUYEN MAU CAC HAM
void Push(int n); // them 1 ptu vao dinh stack
int Pop();       // lay ra ptu o dinh stack
int Peek(); 	  // xem gtri ptu o dinh stack
void Display();   // hien thi stack
bool IsEmpty();	  // ktra stack rong
bool IsFull(); 	  // ktra stack day
void MakeEmpty(); // lam rong stack

// Ham main
int main(){
	int choice, value;
	s.top=0; // khoi tao stack rong (ban dau dinh stack bang 0)
	printf("-- PROGRAM: STACK (use Array) _ NguyenDucHung --\n");
	printf("\nPlease choose task for the Stack:");
	printf("\n  1. Push     5. IsEmpty");
	printf("\n  2. Pop      6. IsFull");
	printf("\n  3. Peek     7. MakeEmpty");
	printf("\n  4. Display  0. Exit");
	
	tt: printf("\nYou choose: "); 	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf(" - New element: value = ");
			scanf("%d",&value);
			Push(value);
			break;
		case 2:
			if(s.top==0)	printf("   Stack is empty, cannot Pop\n");
		 	else	printf("   Removed element %d\n",Pop());
			break;
		case 3:
			printf("   Elemet at top: %d\n",Peek());
			break;
		case 4:
			Display();
			break;
		case 5:
			if(IsEmpty()==true)		printf("   Stack is empty\n");
			else	printf("   Stack is not empty\n");
			break;
		case 6:
			if(IsFull()==true)		printf("   Stack is full\n");
			else	printf("   Stack is not full\n");
			break;
		case 7:
			if(s.top==0) 	printf("   Stack is empty before\n");
			else{
				MakeEmpty();
				Display();
			}
			break;
		case 0:
			printf("   Task finished! Do you want to continue the program? (1.Yes / 2.No): ");
			scanf("%d",&choice);
			if(choice==1){
				system("cls"); // xoa man hinh
				return main(); // thoat khoi switch, TH lai chuong trinh
			}
			else  	return 0;
		default:
			printf("   Error choice! Choice again!\n");
			break;	
	}
	goto tt;
}

// DINH NGHIA CAC HAM
void Push(int value){
	if(s.top==MAXSIZE) 	printf("   Stack is full, cannot Push.\n");
	if(s.top<MAXSIZE){
		s.top++;	      // dinh stack tang them 1
		s.a[s.top]=value; // gtri cua dinh stack
	}
}

int Pop(){
	if(s.top==0)	return 0;
	else{
		int n = s.a[s.top];
		s.top--;        // dinh stack giam di 1
		return n;	
	}
}

int Peek(){
	return s.a[s.top];
}

void Display(){
		printf("   STACK: ");
		for(int i=s.top; i>=1; i--) 	printf(" %d |",s.a[i]);
		printf("\n");
}

bool IsEmpty(){
	if(s.top==0) 	return true;
	else 			return false;
}

bool IsFull(){
	if(s.top==MAXSIZE) 	return true;
	else 				return false;
}

void MakeEmpty(){
	while(s.top>0){ // TH Pop cho den khi top=0
		Pop();
	}
}
