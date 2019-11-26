#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
	int Value;
	struct Stack *next;
}Node;
Node *top;

int Push(int value);
void display();

int main(){ // CHUYEN DOI 1 SO TU HE 10 SANG HE 2
	top=NULL;
	int value,div,mod,choice;
		
	printf("-- Exercise 11: DEC -> BIN (use Stack) _ Nguyen Duc Hung --\n");
	printf("\n  - Enter number (DEC) : ");
	scanf("%d",&value);
	div=value;
	while(div>0){
		Push(div%2);
		div=int(div/2);
	}
	printf("  - Number (BIN)       : ");
	display(); // hien thi ra man hinh dang nhi phan cua so vua chuyen
	// xuat ket qua ra file output
	FILE *fout;
	fout = fopen("output11.txt", "a");
	fprintf(fout,"\n%5d -> ",value);
	for(Node *p=top; p!=NULL; p=p->next)	fprintf(fout,"%d",p->Value);
	fclose(fout);
	
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

int Push(int value){
	Node *p=(Node *)malloc(sizeof(Node));
	p->Value=value;
	p->next=top;
	top=p;
}

void display(){
	for(Node *p=top; p!=NULL; p=p->next)	printf("%d",p->Value);
	printf("\n");
}

