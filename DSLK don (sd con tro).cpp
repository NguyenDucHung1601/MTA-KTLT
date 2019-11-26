#include<stdio.h>
#include<stdlib.h>

// CAU TRUC DU LIEU SIMPLE LINKED LIST
typedef struct Integeral{
	int Value;
	struct Integeral *next;
}Node;
Node *first, *last;

// NGUYEN MAU CAC HAM
void creatList(); 							  // nhap Ds
void display();								  // hien thi Ds
void insertHead(int value);					  // 1. them 1 ptu dau Ds
void insertTail(int value);					  // 2. them 1 ptu cuoi Ds
void insertPosition(int position, int value);  // 3. them ptu tai 1 vtri trong Ds
void deleteHead(); 							  // 4. xoa 1 ptu dau Ds
void deleteTail();							  // 5. xoa 1 ptu cuoi Ds
void deletePosition(int posotion); 			  // 6. xoa ptu tai 1 vtri trong Ds
void deleteValue(int value);				  // 7. xoa ptu co gtri xac dinh trong Ds
void deleteSameValue(); 					  // 8. xoa cac ptu trung nhau (chi de lai 1 ptu voi moi gtri)
void makeEmpty(); 							  // 9. lam rong Ds
bool isEmpty(); 							  // 10. ktra Ds rong
int length(); 								  // 11. tinh do dai Ds (so nut hien tai cua Ds)
void seekPosition(int value); 				  // 12. tim kiem vtri cua ptu trong Ds
void sortAscending(); 						  // 13. sap xep Ds tang dan
void sortDescending(); 					 	  // 14. sap xep Ds giam dan
void reverseList();							  // 15. dao nguoc Ds
void swap(int &a, int &b);					  // dao gtri a va b

// Ham main
int main(){
	first=last=NULL; // khoi tao Ds rong
	int choice, value, position;
		
	printf("-- PROGRAM: SIMPLE LINKED LIST _ NguyenDucHung --\n\n");
	creatList(); // nhap Ds ban dau
	
	printf("\n\nPlease choose task for the Simple Linked list:");
	printf("\n  1. Insert Head            9. Is Empty");
	printf("\n  2. Insert Tail            10. Make Empty");
	printf("\n  3. Insert Position        11. Length");
	printf("\n  4. Delete Head            12. Seek Position");
	printf("\n  5. Delete Tail            13. Sort Asending");
	printf("\n  6. Delete Position        14. Sort Desending");
	printf("\n  7. Delete Value           15. Reverse");
	printf("\n  8. Delete Same Value      00. Exit\n");
tt:	printf("\nYou choose: "); 	scanf("%d",&choice);
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
			printf(" - Insert: position = ");
			scanf("%d",&position);
			if(position>length()+1 || position<1) 	printf("   Position is not valid\n");
			else{
				printf("           value = ");
				scanf("%d",&value);
				insertPosition(position,value);
				display();
			}
			break;
		case 4:
			if(first==NULL)		printf("   Simple Linked list is empty, cannot delete\n");
			else{
				deleteHead();
				display();
			}
			break;
		case 5:
			if(first==NULL)		printf("   Simple Linked list is empty, cannot delete\n");
			else{
				deleteTail();
				display();
			}
			break;
		case 6:
			if(first==NULL){
				printf("   Simple Linked list is empty, cannot delete\n");
				break;
			}
			printf(" - Delete: position = ");
			scanf("%d",&position);
			if(position>length() || position<1)		printf("   Position is not valid\n");
			else{
				deletePosition(position);
				display();
			}
			break;
		case 7:
			if(first==NULL)		printf("   Simple Linked list is empty, cannot delete\n");
			else{
				printf(" - Delete: value = ");
				scanf("%d",&value);
				deleteValue(value);
			}
			break;
		case 8:
			deleteSameValue();
			display();
			break;
		case 9:
			if(isEmpty()==true)		printf("   Simple Linked list is empty\n");
			else		printf("   Simple Linked list is not empty\n");
			break;
		case 10:
			if(first==NULL)		printf("   Simple Linked list is empty before\n");
			else{
				makeEmpty();
				display();
			}
			break;
		case 11:
			printf("   Length of Simple Linked list now: %d\n",length());
			break;
		case 12:
			printf(" - Seek: value = ");
			scanf("%d",&value);
			seekPosition(value);
			break;
		case 13:
			printf(" - Ascending: ");
			sortAscending();
			display();
			break;
		case 14:
			printf(" - Descending: ");
			sortDescending();
			display();
			break;
		case 15:
			reverseList();
			break;
		default:
			printf("   Error choice, please choose again!\n");
			break;
		case 0:
			printf("   Task finished. Do you want to continue the program? (1.Yes / 2.No): ");
			scanf("%d",&choice);
			if(choice==1){
				system("cls");
				return main();
			}
			else{
				printf("\n  -- Thank you for unsing the program!\n --");
				return 0;
			}
	}
	goto tt;
}

// DINH NGHIA CAC HAM
void creatList(){
	int value;
	printf("Creat a Simple linked list. Enter in turn element, enter \"0\" to finish.\n");
	for(int i=1;;i++){
		printf("   - element (%d): ",i);
		scanf("%d",&value);
		if(value==0){
			display();
			break;
		}
		insertTail(value);
	}
}

void display(){
	printf("   Simple linked list: ");
	for(Node *p=first; p!=NULL; p=p->next)	printf("%d   ",p->Value);
	printf("\n");
}

void insertHead(int value){
	Node *p=(Node *)malloc(sizeof(Node));
	p->Value=value;
	p->next=first;
	first=p;	
}

void insertTail(int value){
	Node *p=(Node *)malloc(sizeof(Node));
	p->Value=value;
	p->next=NULL;
	if(first==NULL)		first=p;
	else 	last->next=p;
	last=p;
}

void insertPosition(int position, int value){
 	if(position==1) 			insertHead(value); // TH them 1 ptu dau Ds
 	else{
 		Node *t=first;
	 	for(int i=1; i<position-1; i++) 	t=t->next;
	 	Node *p=(Node *)malloc(sizeof(Node));
	 	p->Value=value;
	 	p->next=t->next;
	 	t->next=p;
	 }
}

void deleteHead(){
		Node *temp=first;
		first=first->next;
		free(temp);
}

void deleteTail(){
	if(first==last)	deleteHead(); // TH Ds chi co 1 ptu
	
	else{ // TH Ds co nhieu hon 1 ptu
		Node *p=first;
		for(int i=1; i<length()-1; i++)		p=p->next;
		Node *temp=last;
		last=p;
		p->next=NULL;
		free(temp);		
	}
}

void deletePosition(int position){
	if(position==1) 			deleteHead();  // TH xoa ptu dau Ds
	else{	// TH xoa ptu khong phai dau Ds
		Node *p=first;
		for(int i=1; i<position-1; i++) 	p=p->next;
		Node *temp=p->next;
		p->next=(p->next)->next;
		free(temp);
	}
}

void deleteValue(int value){
	int count=0;
	for(Node *p=first; p!=NULL; p=p->next){
		if(p->Value==value) 	count++;
	}
	if(count==0)	printf("   Element %d is not exist\n",value);
	else{
		for(int i=count; i>0; i--){
			if(first->Value==value)		deleteHead();
			else{
				Node *p1=first;
				Node *p2=p1->next;
				while(p2!=NULL && p2->Value!=value){
					p1=p2;
					p2=p2->next;
				}
				if(p2!=NULL){
					p1->next=p2->next;
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
		if(count>1){
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
					free(p2);
				}
			}
			count=0; // dat lai count=0 de ktra ptu tiep theo trong Ds
		}
	}
}

void makeEmpty(){
	while(first!=NULL){
		deleteHead();
	}
}

bool isEmpty(){
	if(first==NULL) 	return true;
	else 				return false;
}
int length(){
	int length=0;
	for(Node *p=first; p!=NULL; p=p->next)	length++;
	return length;
}

void seekPosition(int value){
	int count=0, position=0;
	for(Node *p=first; p!=NULL; p=p->next){
		if(p->Value==value)	count++;
	}
	if(count==0) 	printf("   Elelmet %d is not exist",value);
	if(count==1) 	printf("   Element %d is found at 1 position: ",value);
	if(count>1) 	printf("   Elemnnt %d is found at %d positions: ",value,count);
	for(Node *p=first; p!=NULL; p=p->next){
		position++;
		if(p->Value==value) 	printf("%d   ",position);
	}
	printf("\n");
}

void swap(int &a, int &b){
	int temp = b;
	b = a;
	a = temp;	
}

void sortAscending(){
	int temp;
	for(Node *i=first; i!=NULL; i=i->next){
		for(Node *j=i->next; j!=NULL; j=j->next){
			if(i->Value > j->Value)		swap(i->Value, j->Value);
		}
	}
}

void sortDescending(){
	int temp;
	for(Node *i=first; i!=NULL; i=i->next){
		for(Node *j=i->next; j!=NULL; j=j->next){
			if(i->Value < j->Value)		swap(i->Value, j->Value);
		}
	}
}

void reverseList(){
	int a[length()]; // mang a co so ptu bang so ptu cua DS
	int n=length();; // bien dem so ptu cua mang a
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

//void reverseList(){  // cach 2
//	int a[length()]; // mang a co so ptu bang so ptu cua Ds, luu gtri cac ptu cua Ds
//	Node *p=first;
//	for(int i=length()-1; i>=0; i--){ // luu tai mang a (tu cuoi mang ve dau mang) gtri cac ptu tu dau Ds
//		a[i]=p->Value;
//		p=p->next;
//	}
////	for(int i=0; i<length(); i++) 	printf("%d   ",a[i]); 		// in ra mang a
//	int i=0;
//	for(p=first; p!=NULL; p=p->next){ // dat lai gtri cac ptu cua Ds, lay trong mang a ra ---> Ds da bi dao nguoc
//		p->Value=a[i];
//		i++;
//	}
//}


