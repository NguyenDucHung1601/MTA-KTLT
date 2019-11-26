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
void creatList(); 			    				// tao DS ban dau
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
void seekPosition(int value); 					// 12. tim vtri phan tu co gia tri k trong DS
void sortAscending(); 							// 13. Sap xep DS theo thu tu tang dan
void sortDescending(); 							// 14. Sap xep DS theo thu tu giam dan
void reverse();	            					// 15. dao nguoc DS
void swap(int &a, int &b);						// dao gtri a va b

// ham main
int main(){
	first=NULL;
	last=NULL;
	int choice, value, position;
	printf("--- PROGRAM: DOUBLE LINKED LIST _ NguyenDucHung ---\n\n");
	creatList();
	printf("\nPlease choose task with the Doule linked list:");
	printf("\n  1. Insert Head         9. Is Empty");
	printf("\n  2. Insert Tail         10. Make Empty");
	printf("\n  3. Insert Position     11. Length");
	printf("\n  4. Delete Head         12. Seek Position");
	printf("\n  5. Delete Tail         13. Sort Ascending");
	printf("\n  6. Delete Position     14. Sort Descending"); 	
	printf("\n  7. Delete Value        15. Reverse");
	printf("\n  8. Delete Same Value   00. Exit\n");
	tt: printf("\nYou choose: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf(" - Insert Head: value = ");
			scanf("%d",&value);
			insertHead(value);
			display();
			break;
		case 2:
			printf(" - Insert Tail: value = ");
			scanf("%d",&value);
			insertTail(value);
			display();
			break;
		case 3:
			printf(" - Insert Position: position = ");
			scanf("%d",&position);
			if(position>length()+1 || position<1)		printf("   Position is not valid\n");
			else{
				printf("                    value = ");
				scanf("%d",&value);
				insertPosition(position,value);
				display();
			}
			break;
		case 4:
			if(first==NULL && last==NULL) 	printf("   Double linked list is empty, cannot delete.\n");
			else{
				deleteHead();
				display();
			}
			break;
		case 5:
			if(first==NULL) 	printf("   Double linked list is empty, cannot delete.\n");
			else{
				deleteTail();
				display();
			}
			break;
		case 6:
			if(first==NULL)		printf("   Double linked list is empty, cannot delete.\n");
			else{
				printf(" - Delete Position: position = ");
				scanf("%d",&position);
				if(position >length() || position<1) 	printf("   Position is not valid\n");
				else{
				deletePosition(position);
				display();
				}
			}
			break;
		case 7:
			if(first==NULL) 	printf("   Double linked list is empty, cannot delete.\n");
			else{
				printf(" - Delete Value: value = ");
				scanf("%d",&value);
				deleteValue(value);
			}
			break;
		case 8:
			deleteSameValue();
			display();
			break;
		case 9:
			if(isEmpty()==true)		printf("   Double linked list is empty\n");
			else					printf("   Double linked list is not empty\n");
			break;
		case 10:
			if(first==NULL) 	printf("   Double linked list is empty before\n");
			else{
				makeEmpty();
				display();
			}
			break;
		case 11:
			printf("   Length of Double linked list now: %d\n",length());
			break;
		case 12:
			printf(" - Seek Position: value = ");
			scanf("%d",&value);
			seekPosition(value);
			break;
		case 13:
			printf(" - Ascending:");
			sortAscending();
			display();
			break;
		case 14:
			printf(" - Descending:");
			sortDescending();
			display();
			break;
		case 15:	
			reverse();
			break;														
		default: // nhap sai! nhap lai!
			printf("   Error choose! Please choose again!");
			goto tt;
		case 0: // ket thuc phien lam viec
			printf("   Task finished. Do you want to countinue the progame? (1.Yes / 2.No): ");
			scanf("%d",&choice);
			if(choice==1){
				system("cls");
				return main();
			}
			else	return 0;
	}
	goto tt;
	
}

// DINH NGHIA CAC HAM

void creatList(){
	printf("Creat a Double linked list. Enter in turn element, enter \"0\" to finish.\n");
	int value;
	for(int i=1;; i++){
		printf("   - element (%d): ",i);
		scanf("%d",&value);
		if(value==0){ // neu nhap 0, DS ket thuc, in ra DS
			display();
			break;
		}
		insertTail(value);
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
	if(first==NULL){ // TH DS rong
		p->next=NULL;
		p->previous=NULL;
		first=last=p;
	}
	else{ // TH DS khong rong
		p->previous=NULL;
		p->next=first;
		first->previous=p;
		first=p;
	}
}

void insertTail(int value){
	Node *p = (Node *)malloc(sizeof(Node));
	p->Value=value;
	if(first==NULL){
		p->next=NULL;
		p->previous=NULL;
		first=last=p;
	}
	else{
		last->next=p;
		p->next=NULL;
		p->previous=last;
		last=p;
	}
}

void insertPosition(int position, int value){
	if(position==1) 	insertHead(value);
	else{
		Node *p=first;
		for(int i=1; i<position-1; i++) 	p=p->next;
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
		for(int i=1; i<position-1; i++)	p=p->next;
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
				p2=first->next;
				while(p2!=NULL && p2->Value!=value){
					p1=p2;
					p2=p2->next;
				}
				if(p2!=NULL){
					p1->next=p2->next;
					(p2->next)->previous=p1;
					free(p2);
				}
			}
		}
		display();
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
					if(last==p2) 	last=p1; 
					else 	(p->next)->previous=p1;	
					free(p2);
				}
			}
			count=0; // dat lai count=0 de ktra ptu tiep theo trong Ds
		}
	}
}

bool isEmpty(){
	if(first==NULL) 	return true;
	else				return false;
}

void makeEmpty(){
	while(first!=NULL){
		deleteHead();
	}
}

int length(){
	int length=0;
	for(Node *p=first; p!=NULL; p=p->next)	length++;
	return length;
}

void seekPosition(int value){
	int count=0;
	for(Node *p=first; p!=NULL; p=p->next){
		if(p->Value==value)		count++; // dem so ptu co gtri value trong DS
	}
	if(count==0) 	printf("   Element %d is not exist\n",value);
	else{
		int position=1;
		if(count==1) 	printf("   Element %d is found at %d positon: ",value,count);
		if(count>1) 	printf("   Element %d is found at %d postions: ",value,count);
		for(Node *p=first; p!=NULL; p=p->next){
			if(p->Value==value)		printf("%d   ",position);
			position++;
		}
		printf("\n");		
	}
}

void swap(int &a, int &b){
	int temp = b;
	b = a;
	a = temp;
}

void sortAscending(){
	int tempValue;
	for(Node *p1=first; p1!=NULL; p1=p1->next){
		for(Node *p2=p1->next; p2!=NULL; p2=p2->next){
			if(p1->Value > p2->Value)	swap(p1->Value, p2->Value);
		}
	}
}

void sortDescending(){
	int tempValue;
	for(Node *p1=first; p1!=NULL; p1=p1->next){
		for(Node *p2=p1->next; p2!=NULL; p2=p2->next){
			if(p1->Value < p2->Value)	swap(p1->Value, p2->Value);
		}
	}
}

void reverse(){
	int a[length()]; // mang a co so ptu bang so ptu cau DS
	int n=length();
	printf(" - Old Double linked list:        ");
	Node *p=first;
	for(int i=0; i<length(); i++){  // luu cac ptu cua DS voo mang a, in ra mang a (DS ban dau)
		a[i]=p->Value;
		printf("%d   ",a[i]);
		p=p->next;
	}
	makeEmpty(); // lam rong DS de tao DS moi
	for(int i=0; i<n; i++){ // lan luot them vao dau DS cac ptu cua mang a --> (DS ban dau bi dao nguoc)
		insertHead(a[i]);
	}
	printf("\n - Reverse:");
	display();
}

//void reverse(){
//	int a[length()]; // mang a co so ptu bang so ptu cua Ds, luu gtri cac ptu cua Ds
//	Node *p=first;
//	for(int i=length()-1; i>=0; i--){ // luu tai mang a (tu cuoi mang ve dau mang) gtri cac ptu tu dau Ds
//		a[i]=p->Value;
//		p=p->next;
//	}
//	for(int i=0; i<length(); i++) 	printf("%d   ",a[i]); 		// in ra mang a
////	int i=0;
////	for(p=first; p!=NULL; p=p->next){ // dat lai gtri cac ptu cua Ds, lay trong mang a ra ---> Ds da bi dao nguoc
////		p->Value=a[i];
////		i++;
////	}
//}
