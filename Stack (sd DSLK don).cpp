#include<stdio.h>
#include<stdlib.h>

// CAU TRUC DU LIEU STACK SD DSLK DON
typedef struct Stack{
	int Value;         // truong "Value" luu gtri cua ptu trong stack
	struct Stack *next; // con tro "next" tro ptu tiep theo
}stack;
stack *top;  // con tro "top" tro ptu o dinh stack

// NGUYEN MAU CAC HAM
void Push(int value); // them 1 ptu vao dinh stack
int Pop();			 			  // lay ra ptu o dinh stack
int Peek(); 		     	      // ktra gtri ptu dinh stack
void Display(); 	    	      // hien thi stack
bool IsEmpty(); 	    	      // ktra stack rong
bool IsFull(int maxsize); 	      // ktra stack day
void MakeEmpty(); 	              // lam rong stack
int Length(); 					  // tinh do dai cua stack hien tai

// Ham main
int main(){
	top=NULL; // khoi tao stack rong
	printf("-- PROGRAM: STACK (use Simple linked list) _ NguyenDucHung --\n\n");
	int choice,value,maxsize;
	printf("\nMax size of Stack: "); 	scanf("%d",&maxsize);
	printf("Please choose task for Stack:");
	printf("\n  1. Push       5. IsEmpty");
	printf("\n  2. Pop        6. IsFull");
	printf("\n  3. Peek       7. MakeEmpty");
	printf("\n  4. Display    8. Length");
	printf("\n  0. Exit");
	tt: printf("\nYou choose: "); 
	scanf("%d",&choice);
	switch(choice){
		case 1:
			if(Length()==maxsize)	printf("   Stack is full, cannot Push\n");
			else{
				printf(" - New element: value = ");
				scanf("%d",&value);
				Push(value);
			}
			break;
		case 2:
			if(top==NULL)		printf("   Stack is empty, cannot Pop\n");
			else				printf("   Removed element %d\n",Pop());
			break;
		case 3:
			if(top==NULL)	printf("   Stack is empty, top element is not exist.\n");
			else printf("   Top element: %d\n",Peek());
			break;			
		case 4:
			Display();
			break;
		case 5:
			if(IsEmpty()==true)		printf("   Stack is empty\n");
			else					printf("   Stack is not empty\n");
			break;
		case 6:
			if(IsFull(maxsize)==true)	printf("   Stack is full\n");
			else						printf("   Stack is not full\n");
			break;
		case 7:
			if(top==NULL)	printf("   Stack is empty before\n");
			else{
				MakeEmpty();
				Display();
			}
			break;
		case 8:
			printf("   Length of Stack now: %d\n",Length());
			break;
		default:
			printf("   Error choice! Please choose again!\n");
			break;
		case 0:
			printf("   Task finished! Do you want to continue the program? (1.Yes / 2.No): ");
			scanf("%d",&choice);
			if(choice==1){
				system("cls"); 
				return main(); 
			}
			else{
				printf("\n   Thank you for using the program!\n");
				return 0;
			}
	}
	goto tt;
}

// DINH NGHIA CAC HAM
void Push(int value){
	stack *p = (Stack *)malloc(sizeof(Stack));
	p->Value=value;
	p->next=top;
	top=p;
}

int Pop(){
	int n = top->Value;
	stack *temp	= top;
	top=top->next;
	free(temp);
	return n;
}

int Peek(){
	return top->Value;
}

void Display(){
	printf("   STACK: ");
	for(stack *p=top; p!=NULL; p=p->next) 	printf("%d | ",p->Value); 	printf("\n");
}

bool IsEmpty(){
	if(top==NULL) 	return true;
	else 			return false;
}

bool IsFull(int maxsize){
	if(Length()==maxsize) 	return true;
	else 					return false;	
}

void MakeEmpty(){
	while(top!=NULL)	Pop();
}

int Length(){
	int L=0;
	for(stack *p=top; p!=NULL; p=p->next) 	L++;
	return L;
}

