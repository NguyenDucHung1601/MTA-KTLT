#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
	int Data;
	struct Stack *next;
}Node;
Node *top; // con tro "top" tro toi ptu o dinh stack

// NGUYEN MAU CAC HAM
void Push(int data);
int Pop();
bool isEmpty();

int main(){
	top=NULL; // khoi tao stack rong
	char character[50]; // mang character luu chuoi ki tu
	int choice;
	printf("-- Exercise 12: REVERSE CHAIN CHARACTER _ NguyenDucHung --\n\n");
tt:	printf(" - Enter chain character   :  ");
	fflush(stdin);
	gets(character);
	if(strlen(character)==0){  // neu chuoi rong (do dai chuoi = 0)thi ket thuc chuong trinh
		printf("\n   Thank you for using the program!");
		exit(0);
	}
	// xuat ket qua ra file output
	FILE *fout;
	fout = fopen("output12.txt", "a");
	fprintf(fout, "\nResult: ");
	//
	int n = strlen(character); // n = do dai chuoi ki tu luu trong character
	for(int i=0; i<n; i++){
		Push(character[i]);   // lan luot day cac ki tu trong chuoi vao Stack
		fprintf(fout,"%c",character[i]); // ghi tung ki tu vua duoc Push ra file output
	}
	fprintf(fout, "  --->  ");
	printf(" - Reverse chain character :  ");
	while(isEmpty()==false){ 
		int c = Pop();
		printf("%c", c); // lan luot Pop tung ki tu tu Stack, in ra man hinh --> chuoi dao nguoc
		fprintf(fout, "%c",c); // ghi tung ki tu vua duoc Pop ra file output
	}
	printf("\n\n");
	fclose(fout);
	goto tt;
}

// DINH NGHIA CAC HAM
void Push(int data){
	Node *p = (Node *)malloc(sizeof(Node));
	p->Data=data;
	p->next=top;
	top=p;
}

int Pop(){
	if(isEmpty()==false){
		int data;
		data=top->Data;
		Node *temp=top;
		top=top->next;
		free(temp);
		return data;	
	}
	else 	printf("   Stack is empty, cannot Pop.");
}

bool isEmpty(){
	if(top==NULL)	return true;
	else 			return false;
}
