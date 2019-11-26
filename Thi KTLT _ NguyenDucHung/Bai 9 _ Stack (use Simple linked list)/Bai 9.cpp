#include<stdio.h>
#include<stdlib.h>

// CAU TRUC DU LIEU STACK SD DSLK DON
typedef struct Stack{
	int Value;         // truong "Value" luu gtri cua ptu trong stack
	struct Stack *next; // con tro "next" tro ptu tiep theo
}stack;
stack *top, *bottom;  // con tro "top", "bottom" tro ptu o dinh stack
// NGUYEN MAU CAC HAM

void creatData(int a[], int n);   				// tao random data luu vao file input
void writeData(char *fileName, int a[], int n); // ghi data vao file input
void readData(char *fileName, int a[], int n);  // doc data tu file input --> stack ban dau (full) 
int Append(int value);	 					    // them ptu vao cuoi DSLK

void Push(int value); // them 1 ptu vao dinh stack
int Pop();			 			  // lay ra ptu o dinh stack
int Peek(); 		     	      // ktra gtri ptu dinh stack
bool IsEmpty(); 	    	      // ktra stack rong
bool IsFull(int maxsize); 	      // ktra stack day
void MakeEmpty(); 	              // lam rong stack
int Length(); 					  // tinh do dai cua stack hien tai
void Display(); 				  // hien thi Ds

// Ham main
int main(){
	top=NULL; // khoi tao Stack rong
	printf("-- Exercise 9: STACK (use Simple linked list) _ NguyenDucHung --\n");
	int choice,value,maxsize;
	
	printf("\nMax size of Stack: "); 	scanf("%d",&maxsize);
	int a[maxsize];
	creatData(a,maxsize);
	writeData("input9.txt",a,maxsize);
	readData("input9.txt",a,maxsize);
	
	// ghi ket qua ra file output
	FILE *out;
	out = fopen("output9.txt", "a");
	//
	printf("\nPlease choose task for Stack:");
	printf("\n  1. Push       5. IsFull");
	printf("\n  2. Pop        6. MakeEmpty");
	printf("\n  3. Peek       7. Length");
	printf("\n  4. IsEmpty    8. Exit");
	tt: printf("\nYou choose: "); 	scanf("%d",&choice);
	switch(choice){
		case 1:
			if(Length()==maxsize){
				printf("   Stack is full, cannot Push\n");
				fprintf(out, "\nStack is full, cannot Push");
			}
			else{
				printf(" - New element: value = ");
				scanf("%d",&value);
				Push(value);
				Display();
				fprintf(out,"\nSTACK: ");
				for(stack *p=top; p!=NULL; p=p->next)	fprintf(out, " %d |", p->Value);
			}
			break;
		case 2:
			if(Length()==0){
				printf("   Stack is empty, cannot Pop\n");
				fprintf(out, "\nStack is empty, cannot Pop");
			}
			else{
				int n = Pop();
				fprintf(out, "\nRemoved element %d",n);
				printf("   Removed element %d\n",n);
				Display();
				fprintf(out, "\nSTACK: ");
				for(stack *p=top; p!=NULL; p=p->next)	fprintf(out, " %d |", p->Value);
			}
			break;
		case 3:
			if(top==NULL){
				printf("   Stack is empty, top element is not exist.\n");
				fprintf(out, "\nStack is empty, top element is not exist.");
			}
			else{
				printf("   Top element: %d\n",Peek());
				fprintf(out, "\nTop element: %d",Peek());
			}
			break;			
		case 4:
			if(IsEmpty()==true){
				printf("   Stack is empty\n");
				fprintf(out,"\nStack is empty");
			}
			else{
				printf("   Stack is not empty\n");
				fprintf(out,"\nStack is not empty");
			}
			break;
		case 5:
			if(IsFull(maxsize)==true){
				printf("   Stack is full\n");
				fprintf(out, "\nStack is full");
			}
			else{
				printf("   Stack is not full\n");
				fprintf(out, "\nStack is not full");
			}
			break;
		case 6:
			if(top==NULL){
				printf("   Stack is empty before\n");
				fprintf(out, "\nStack is empty before");
			}	
			else{
				MakeEmpty();
				Display();
				fprintf(out, "\nSTACK: ");
				for(stack *p=top; p!=NULL; p=p->next)	fprintf(out, " %d |", p->Value);
			}
			break;
		case 7:
			printf("   Length of Stack now: %d\n",Length());
			int n;
			fprintf(out, "\nLength of Stack now: %d",Length());
			break;
		default:
			printf("   Error choice! Please choice again!\n");
			break;
		case 0:
			printf("   Task finished! Do you want to continue the program? (1.Yes / 2.No): ");		scanf("%d",&choice);
			if(choice==1){
				system("cls"); // xoa man hinh
				return main(); // TH lai chuonng trinh
			}
			else{
				fclose(out);
				printf("   Thank you for using the program!\n");
				return 0;
			}
	}
	goto tt;
}

// DINH NGHIA CAC HAM
void creatData(int a[], int n){
	for(int i=0; i<n; i++){
		a[i] = rand()%100; // gtri ngau nhien chay tu 0 -> 99
	}
}

void writeData(char *fileName, int a[], int n){
		FILE *fw;
		fw = fopen(fileName, "w");
		fprintf(fw, "STACK: maxsize = %d\n", n);
		for(int i=0; i<n; i++){
			fprintf(fw, " %d |", a[i]);
		}
		fclose(fw);
}

void readData(char *fileName, int a[], int n){
	FILE *fr;
	fr = fopen(fileName, "r");
	fscanf(fr, "%d\n", &n);
	printf("\nSTACK: ");
	for(int i=0; i<n; i++){
		fscanf(fr, " %d |", &a[i]);
		printf(" %d |", a[i]); // in ra man hinh ptu vua doc dc
		Append(a[i]); // them ptu vua doc dc vao DSLK
	}
	printf("\n");
	fclose(fr);
}

int Append(int value){
	stack *p=(stack *)malloc(sizeof(stack));
	p->Value=value;
	p->next=NULL;
	if(top==NULL)	top=p;
	else bottom->next=p;
	bottom=p;
}

int Length(){
	int L=0;
	for(stack *p=top; p!=NULL; p=p->next) 	L++;
	return L;
}
void Push(int value){
	stack *p = (Stack *)malloc(sizeof(Stack));
	p->Value=value;
	p->next=top;
	top=p;
}

int Pop(){
	int n;
	n=top->Value;
	stack *temp;
	temp = top;
	top=top->next;
	free(temp);
	return n;
}

int Peek(){
	int n;
	n=top->Value;
	return n;
}

void Display(){
	printf("   STACK: ");
	for(stack *p=top; p!=NULL; p=p->next) 	printf("%d | ",p->Value); 	printf("\n");
}

bool IsEmpty(){
	if(top==NULL)	return true;
	else			return false;
}

bool IsFull(int maxsize){
	if(Length()==maxsize)	return true;
	else					return false;
}

void MakeEmpty(){
	while(top!=NULL)	Pop();
}
