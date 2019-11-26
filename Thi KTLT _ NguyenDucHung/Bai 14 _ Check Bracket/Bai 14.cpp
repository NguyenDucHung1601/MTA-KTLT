#include<stdio.h>
#include<malloc.h>
#include<string.h>

// CAU TRUC DU LIEU
typedef struct Stack{
	int data;
	struct Stack *next;
}Node;
Node *top;

// NGUYEN MAU CAC HAM
bool isEmpty();			// ktra stack rong
void Push(int value);   // them ptu vao dinh stack
int Pop(); 			 	// lay ra ptu dinh stack
bool checkBracket(char expression[100]); // ktra cac dau ngoac

// Ham main
int main(){
	int choice;
	char expression[100];
	printf("-- Exercise 14: CHECK BRACKET _ NguyenDucHung --\n\n");
	// xuat Ket qua ra file output
	FILE *fout = fopen("output14.txt","a");
	//
tt:	printf("\n - Enter the expression: ");
	fflush(stdin);
	gets(expression); // nhap bieu thuc
	fprintf(fout, "\n\n- Expression: "); //
	for(int i=0; i<strlen(expression); i++) 	fprintf(fout, "%c", expression[i]); //
	if(strlen(expression)==0){ // neu bieu thuc rong (do dai expression = 0) thi ket thuc chuong trinh
		printf("\n   Thank you for using the program!\n");
		fclose(fout); //
		return 0; 
	}
	else{ // nguoc lai, bieu thuc khong rong, goi ham checkBracket de ktra
		if(checkBracket(expression)==true){
			printf(" - Result: TRUE\n");
			fprintf(fout, "\n- Result: TRUE"); //
		}else{
			printf(" - Result: FALSE\n");
			fprintf(fout, "\n- Result: FALSE"); //
		}
	}
	goto tt;
}

// DINH NGHIA CAC HAM

bool isEmpty(){
	if(top==NULL) 	return true;
	else 			return false;
}

void Push(int value){
	Node *p = (Node *)malloc(sizeof(Node));
	p->data=value;
	p->next=top;
	top=p;
}

int Pop(){
	if(isEmpty()==false){
		Node *temp=top;
		int value=top->data;
		top=top->next;
		free(temp);
		return value;
	}
	else 	printf("   Empty Stack\n");
}

bool checkBracket(char expression[100]){ 
	top=NULL; // khoi tao stack rong
	int count=0;
	for(int i=0; i<strlen(expression); i++){
		if(expression[i]=='('  ||  expression[i]=='['  ||  expression[i]=='{'){  // doc bieu thuc, bat gap 1 dau ngoac MO nao do thi Push no vao stack
			Push(expression[i]);
		}
// Ktra cap ngoac tron ()		
		else if(expression[i]==')'){ // doc bieu thuc, neu bat gap 1 dau ngoac DONG ) thi ktra stack:
			if(isEmpty()==true){  // neu stack rong (chua co dau ngoac MO nao truoc do) --> bieu thuc sai 
				return false;
			}
			else{
				if(Pop() != '('){ // neu stack k rong, Pop ptu dau tien ra, neu k phai ngoac MO ( --> bieu thuc sai
					return false;
				}
			}
		}
// Ktra cap ngoac vuong []		
		else if(expression[i]==']'){ // doc bieu thuc, neu bat gap 1 dau ngaoc DONG ] thi ktra stack
			if(isEmpty()==true){ // neu stack rong (chua co dau ngoac MO nao truoc do) --> bieu thuc sai
				return false;
			}
			else{
				if(Pop() != '['){ // neu stack k rong, Pop ptu dau tien ra, neu k phai ngoac MO [ --> bieu thuc sai
					return false;
				}
			}
		}
// Ktra cap ngoac nhon {}		
		else if(expression[i] == '}'){ // doc bieu thuc, neu bat gap 1 dau ngoac DONG { thi ktra stack
			if(isEmpty()==true){ // neu stack rong (chua co dau ngoac MO nao truoc do) --> bieu thuc sai
				return false;
			}
			else{
				if(Pop() != '{'){ // stack khong rong, Pop ptu dau tien ra, neu k phai ngoac MO { --> bieu thuc sai
					return false;
				}
			}
		}
	}
	if(isEmpty()==true){ // Sau khi da doc het bieu thuc, neu stack rong (tat ca cac ngoac da "co doi"), khong con sot lai ngoac nao --> bieu thuc dung
		return true;
	}else{ // nguoc lai, neu van con sot lai ngoac nao "khong co doi" --> bieu thuc sai
		return false;
	}
}



