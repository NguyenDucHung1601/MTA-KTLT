#include<stdio.h>
#include<stdlib.h>

typedef struct List{ // Cau truc du lieu Danh sach
	int Value;
	struct List *next;
}Node;
Node *first, *last;

typedef struct Stack{ // Cau truc du lieu Stack
	int data;
	struct Stack *next;
}stack;
stack *top;

// NGUYEN MAU CAC HAM
void creatData(int a[], int n);					 // tao random data luu vao mang a
void writeData(char *fileName, int a[], int n);  // ghi random data vao file input
void readData(char *fileName, int a[], int n);   // doc random data tu file input 
int Append(int value); 	// them ptu vao cuoi Ds
int Push(int value);    // them ptu vao dinh Stack
int Pop();              // lay ra ptu o dinh Stack
bool isStackEmpty();    // ktra Stack rong
void display();         // hien thi Ds
void reverse();         // dao nguoc Ds

// Ham main
int main(){
	first = last = NULL; // khoi tao Ds rong
	top = NULL; // khoi tao Stack rong
	int n, choice;
	printf("-- Exercise 13: REVERSE LIST _ NguyenDucHung --\n\n");
	printf(" - Number of List element : ");
	scanf("%d",&n);
	int a[n];
	creatData(a,n);
	writeData("input13.txt",a,n);
	readData("input13.txt",a,n);
	// ghi ket qua ra file output
	FILE *fout;
	fout = fopen("output13.txt", "a");
	// 
	printf("\n\n - Reverse List           : ");
	fprintf(fout, "\n\n- First List   : ");
	for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout, "%d   ",p->Value); // ghi Ds ban dau ra file output
	
	reverse();
	display();
	
	fprintf(fout, "\n- Reverse List : ");
	for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout, "%d   ",p->Value); // ghi Ds sau khi da dao nguoc ra file output
	
	printf("\n\nDo you want to continue the program? (1.Yes / 2.No): ");
	scanf("%d",&choice);
	if(choice==1){
		system("cls");
		return main();
	}
	else{
		fclose(fout);
		printf("\n   Thank you for using the program!");
		return 0;
	}
	
}

// DINH NGHIA CAC HAM
void creatData(int a[], int n){
	for(int i=0; i<n; i++)	a[i]=rand()%100+1;
}

void writeData(char *fileName, int a[], int n){
	FILE *fw;
	fw = fopen(fileName,"w");
	fprintf(fw,"First List: length = %d\n",n);
	for(int i=0; i<n; i++) 		fprintf(fw, "%d   ",a[i]);
	fclose(fw);
}

void readData(char *fileName, int a[], int n){
	FILE *fr;
	fr = fopen(fileName,"r");
	printf("\n - First list             : ");
	for(int i=0; i<n; i++){
		fscanf(fr, "%d   ", &a[i]);
		Append(a[i]);
	}
	fclose(fr);
	display();
}

int Append(int value){
	Node *p = (Node *)malloc(sizeof(Node));
	p->Value=value;
	p->next=NULL;
	if(first==NULL && last==NULL) 	first=p;
	else 	last->next=p;
	last=p;
}

int Push(int value){
	stack *p = (stack *)malloc(sizeof(stack));
	p->data=value;
	p->next=top;
	top=p;
}

int Pop(){
	int n;
	n = top->data;
	stack *temp = top;
	top=top->next;
	free(temp);
	return n;
}

bool isStackEmpty(){
	if(top==NULL) 	return true;
	else return false;
}

void display(){
	for(Node *p=first; p!=NULL; p=p->next) 	printf("%d   ",p->Value);
}

void reverse(){
	for(Node *p=first; p!=NULL; p=p->next){
		Push(p->Value);
	}
	first=last=NULL; // khoi tao lai Ds rong
	while(isStackEmpty()==false){ // Pop tu Stack dua vao Ds den khi het Stack  ---> Ds dao nguoc
		Append(Pop());
	}
}


