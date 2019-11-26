#include<stdio.h>
#include<stdlib.h>

// cau truc DS lien ket kep
typedef struct Integeral{
	int Value;
	struct Integeral *next;
	struct Integeral *previous;
}Node;
Node *first, *last;

// Nguyen mau cac ham
void creatData(int a[], int n); 		        // tao random data luu vao mang a;
void writeData(char *fileName, int a[], int n); // ghi random data vao gile input
void readData(char *fileNamem, int a[], int n); // doc random data tu file inpt
void display();             					// hien thi DS
void insertHead(int value); 					// 1. them node dau DS
void insertTail(int value); 					// 2. them node cuoi DS
void insertPosition(int position, int value);  	// 3. them 1 node vao vtri bat ki trong DS
void deleteHead(); 								// 4. xoa node dau DS
void deleteTail(); 								// 5. xoa node cuoi DS
void deletePosition(int position);				// 6. xoa node tai vtri bat ki trong DS
void deleteValue(int value);					// 7. xoa node co gtri bat ki trong DS
void deleteSameValue(); 						// 8. xoa cac phan tu trung nhau (chi de lai 1 phan tu cho moi gia tri)
bool isEmpty();									// 9. ktra DS rong
void makeEmpty(); 								// 10. lam rong DS
int length(); 									// 11. tinh do dai DS

// ham main
int main(){
	first=NULL;
	last=NULL;
	int n, choice, value, position;
	printf("--- Exercise 4: DOUBLE LINKED LIST _ NguyenDucHung ---\n\n");
	printf("\nLength of first Double linked list: ");
	scanf("%d",&n);
	int a[n];
	creatData(a,n);
	writeData("input4.txt",a,n);
	readData("input4.txt",a,n);
	// xuat ket qua ra file output
	FILE *fout;
	fout = fopen("output4.txt","a");
	//
	printf("\n\nPlease choose task with the Doule linked list:");
	printf("\n  1. Insert Head         7. Delete Value");
	printf("\n  2. Insert Tail         8. Delete Same Value");
	printf("\n  3. Insert Position     9. Is Empty");
	printf("\n  4. Delete Head         10. Make Empty");
	printf("\n  5. Delete Tail         11. Length");
	printf("\n  6. Delete Position     00. Exit"); 	
	tt: printf("\nYou choose: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf(" - Insert Head: value = ");
			scanf("%d",&value);
			insertHead(value);
			display();
			fprintf(fout, "\nDouble linked list: ");
			for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
			break;
		case 2:
			printf(" - Insert Tail: value = ");
			scanf("%d",&value);
			insertTail(value);
			display();
			fprintf(fout, "\nDouble linked list: ");
			for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
			break;
		case 3:
			printf(" - Insert Position: position = ");
			scanf("%d",&position);
			if(position>length()+1 || position<1){
				printf("   Position is not valid\n");
				fprintf(fout, "\nPosition is not valid");
			}
			else{
				printf("                    value = ");
				scanf("%d",&value);
				insertPosition(position,value);
				display();
				fprintf(fout, "\nDouble linked list: ");
				for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
			}
			break;
		case 4:
			if(first==NULL && last==NULL){
				printf("   Double linked list is empty, cannot delete.\n");
				fprintf(fout, "\nDouble linked list is empty, cannot delete.");
			}
			else{
				deleteHead();
				display();
				fprintf(fout, "\nDouble linked list: ");
				for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
			}
			break;
		case 5:
			if(first==NULL && last==NULL){
				printf("   Double linked list is empty, cannot delete.\n");
				fprintf(fout, "\nDouble linked list is empty, cannot delete.");
			}
			else{
				deleteTail();
				display();
				fprintf(fout, "\nDouble linked list: ");
				for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
			}
			break;
		case 6:
			if(first==NULL && last==NULL){
				printf("   Double linked list is empty, cannot delete.\n");
				fprintf(fout, "\nDouble linked list is empty, cannot delete.");
			}
			else{
				printf(" - Delete Position: position = ");
				scanf("%d",&position);
				if(position >length() || position<1){
					printf("   Position is not valid\n");
					fprintf(fout, "\nPosition is not valid");
				}
				else{
					deletePosition(position);
					display();
					fprintf(fout, "\nDouble linked list: ");
					for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
				}
			}
			break;
		case 7:
			if(first==NULL && last==NULL){
				printf("   Double linked list is empty, cannot delete.\n");
				fprintf(fout, "\nDouble linked list is empty, cannot delete.");
			}
			else{
				printf(" - Delete Value: value = ");
				scanf("%d",&value);
				deleteValue(value);
				display();
				fprintf(fout, "\nDouble linked list: ");
				for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
			}
			break;
		case 8:
			deleteSameValue();
			display();
			fprintf(fout, "\nDouble linked list: ");
			for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
			break;
		case 9:
			if(isEmpty()==true){
				printf("   Double linked list is empty\n");
				fprintf(fout, "\nDouble linked list is empty");
			}
			else{
				printf("   Double linked list is not empty\n");
				fprintf(fout, "\nDouble linked list is not empty");
			}
			break;
		case 10:
			if(first==NULL && last==NULL){
				printf("   Double linked list is empty before\n");
				fprintf(fout, "\nDouble linked list is empty before");
			}
			else{
				makeEmpty();
				display();
				fprintf(fout, "\nDouble linked list: ");
				for(Node *p=first; p!=NULL; p=p->next) 		fprintf(fout,"%d  ",p->Value);
			}
			break;
		case 11:
			printf("   Length of Double linked list now: %d\n",length());
			fprintf(fout, "\nLength of Double linked list now: %d\n",length());
			break;
		default: // nhap sai! nhap lai!
			printf("   Error choose! Please choose again!");
			goto tt;
		case 0: // ket thuc phien lam viec
			printf("   Task has been finished. Do you want to countinue the progame? (1.Yes / 2.No)  You choose: ");
			scanf("%d",&choice);
			if(choice==1){
				system("cls");
				return main();
			}
			else{
				fclose(fout);
				printf("\n   Thank you for using the program\n");
				return 0;
			}
	}
	goto tt;
	
}

// DINH NGHIA CAC HAM
void creatData(int a[], int n){
	for(int i=0; i<n; i++) 		a[i]=rand()%10+1;
}

void writeData(char *fileName, int a[], int n){
	FILE *fw;
	fw = fopen(fileName, "w");
	fprintf(fw, "Double linked list:\n");
	for(int i=0; i<n; i++) 		fprintf(fw, "%d  ", a[i]);   // ghi lan luot tung ptu vao file input
	fclose(fw);
}

void readData(char *fileNamem, int a[], int n){
	FILE *fr;
	fr = fopen(fileNamem, "r");
	printf("\nDouble linked list: ");
	for(int i=0; i<n; i++){
		fscanf(fr, "%d  ", &a[i]);  // doc tung ptu cua mang a
		insertTail(a[i]); // them ptu vua doc vao DSLK
		printf("%d  ",a[i]); // in ptu vua them ra man hinh
	}
}

void display(){
	printf("   Double linked list: ");
	for(Node *p=first; p!=NULL; p=p->next) 		printf("%d   ",p->Value);
	printf("\n");
}

void insertHead(int value){
	Node *p = (Node *)malloc(sizeof(Node));
	p->Value=value;
	p->next=first;
	p->previous=NULL;
	first=p;
}

void insertTail(int value){
	Node *p = (Node *)malloc(sizeof(Node));
	p->Value=value;
	if(first==NULL && last==NULL){ // TH DS rong
		p->next=NULL;
		p->previous=NULL;
		first=last=p;
	}
	else{ // TH DS khong rong
		last->next=p;
		p->next=NULL;
		p->previous=last;
		last=p;
	}
}

void insertPosition(int position, int value){
	if(position==1) 				insertHead(value);
	else if(position==length()+1) 	insertTail(value);
	else{
		Node *p=first;
		for(int i=1; i<position-1; i++) 	p=p->next; // p tro den ptu tai vtri (position-1)
		Node *n=(Node *)malloc(sizeof(Node));
		n->Value=value;
		n->next=p->next;
		n->previous=p;
		p->next=n;
	}
}

void deleteHead(){
	Node *temp=first;
	if(first==last) 	first=last=NULL;  // khi DS chi co 1 ptu
	else{ // khi DS co nhieu hon 1 ptu
		first=first->next;
		first->previous = NULL;
	}
	free(temp);
}

void deleteTail(){
	Node *temp=last;
	if(first==last) 	first=last=NULL;
	else{
		last=last->previous;
		last->next=NULL;
	}
	free(temp);
}

void deletePosition(int position){
	if(position==1)				 	deleteHead();
	else if(position==length())		deleteTail();
	else{
		Node *p=first;
		for(int i=1; i<position-1; i++)	p=p->next;  // p tro den ptu tai vtri (position-1)
		Node *temp;
		temp=p->next;
		((p->next)->next)->previous=p;
		p->next=(p->next)->next;
		free(temp);
	}
}

void deleteValue(int value){
	int count=0;
	for(Node *p=first; p!=NULL; p=p->next){
		if(p->Value==value) 	count++; // dem so node co gtri value trong DS
	}
	if(count==0) 	printf("   Element %d is not exist\n",value);
	else{
		for(int i=count; i>0; i--){
			if(first->Value==value) 		deleteHead(); // Th1: __ xoa node dau DS 
			else if(last->Value==value)		deleteTail(); // Th2: __ xoa node cuoi DS
			else{ // Th3: ___ xoa node giua DS
				Node *p1, *p2;
				p1=first;
				p2=p1->next;
				while(p2!=NULL && p2->Value!=value){
					p1=p2;
					p2=p2->next;
				}
				if(p2!=NULL){
					Node *temp=p2;
					p1->next=p2->next;
					p2=p2->next;
					p2->previous=p1;
					free(temp);
				}
			}
		}
	}	
}

void deleteSameValue(){
	int value,count=0;
	Node *p, *q, *p1, *p2;
	for(p=first; p!=NULL; p=p->next){ // xet lan luot tung ptu trong Ds de ktra
 		value=p->Value;
		for(q=first; q!=NULL; q=q->next){ // dem so ptu co gtri = "value"
			if(q->Value==value) 	count++;
		}
		if(count>1){ // neu co tu 2 ptu tro len co gtri trung nhau
			for(q=first; q!=NULL; q=q->next){ // duyet tu dau Ds, tim ptu dau tien co gtri = "value", tim thay thi break khoi vong for
				if(q->Value==value)		break;
			}
			for(int i=count; i>1; i--){ // duyet tu ptu dau tien co gtri = "value", tim thay ptu nao nua co gtri bang = "value" thi xoa di, den khi count=1 thi dung lai
				p1=q;
				p2=q->next;
				while(p2!=NULL && p2->Value!=value){ // khi "chua het Ds" va "chua tim thay"
					p1=p2;
					p2=p2->next;
				}
				if(p2!=NULL){ // khi da tim thay ptu tiep theo co gtri = "value" sau ptu dau tien co gri = "value"
					p1->next=p2->next;  
					if(last==p2) 	last=p1;   // neu p2 la ptu cuoi DS thi p2->next=NULL nen p1->next=NULL, p1 se tro thanh ptu cuoi cung cua DS, cap nhat lai last=p1
					else 			(p2->next)->previous=p1; // nguoc lai, p2 khong phai ptu cuoi DS, (p2->next)->previous=p1 cung la (p1->next)->previous=p1
					free(p2); // xoa p2 di
				}
			}
			count=0; // dat lai count=0 de ktra ptu tiep theo trong Ds
		}
	}
}





bool isEmpty(){
	if(first==NULL) 	return true;
	else			 	return false;
}

void makeEmpty(){
	while(first!=NULL){
		deleteHead();
	}
}

int length(){
	int L=0;
	for(Node *p=first; p!=NULL; p=p->next)	L++;
	return L;
}


