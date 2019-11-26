#include<stdio.h>
#include<stdlib.h>

// CAU TRUC DU LIEU DOUBLE LINKED LIST
typedef struct Integeral{
	int Value;
	struct Integeral *next;
	struct Integeral *previous;
}Node;
Node *first, *last;

// NGUYEN MAU CAC HAM
void creatData(int a[], int n);                   // tao random data luu vao mang a
void writeData(char *fileName, int a[], int n );  // ghi data vao file input
void readData(char *fileName, int a[], int n);    // doc data tu file input --> DSLK
void display();				 // hien thi Ds
int insertTail(int value);	 // them 1 ptu cuoi Ds
void deleteSameValue(); 	 // xoa cac ptu trung nhau (chi de lai 1 ptu voi moi gtri)
void sortAscending(); 		 // sap xep Ds tang dan

// Ham main
int main(){
	first=last=NULL; // khoi tao Ds rong
	int n, choice;
			
	printf("-- Exercise 8: DELETE SAME (in Ascending Double linked list) _ NguyenDucHung --\n\n");
	printf(" - Number of List element : ");
	scanf("%d",&n);
	int a[n];
	creatData(a,n);
	writeData("input8.txt",a,n);
	readData("input8.txt",a,n);
	deleteSameValue();
	printf(" - List after delete same : ");
	display();
	
	// ghi ket qua ra file output
	FILE *fout;
	fout = fopen("output8.txt","a");
	fprintf(fout,"Result: ");
	for(Node *p=first; p!=NULL; p=p->next) 	fprintf(fout, "%d  ",p->Value);
	fprintf(fout,"\n");
	fclose(fout);
	
	printf("\nDo you want to continue the program? (1.Yes / 2.No): ");
	scanf("%d",&choice);
	if(choice==1){
		system("cls");
		return main();
	}
	else{
		printf("\n   Thank you for using the program!");
		return 0;
	}
}

// DINH NGHIA CAC HAM
void creatData(int a[], int n){
	for(int i=0; i<n; i++){
		a[i] = rand()%100+1;  // gtri ngau nhien trong doan 1->10
	}
}

void writeData(char *fileName, int a[], int n ){
	FILE *fw;
	fw = fopen(fileName,"w");
	fprintf(fw, "Double linked list:\n");
	for(int i=0; i<n; i++)		fprintf(fw,"%d  ",a[i]);
	fclose(fw);
}

void readData(char *fileName, int a[], int n){
	FILE *fr;
	fr = fopen(fileName,"r");
	for(int i=0; i<n; i++){
		fscanf(fr,"%d  ",&a[i]); // doc tung ptu cua mang a
		insertTail(a[i]); // them ptu vua doc vao Dslk
	}
	sortAscending(); // sap xep Dslk theo thu tu khong giam
	printf("\n - Double linked list     : ");
	display(); // in Dslk ra man hinh
	printf("\n");
	fclose(fr);
}

void display(){
	for(Node *p=first; p!=NULL; p=p->next)	printf("%d   ",p->Value);
	printf("\n");
}

int insertTail(int value){
	Node *p=(Node *)malloc(sizeof(Node));
	p->Value=value;
	p->next=NULL;
	if(first==NULL && last==NULL)	first=p;
	else 	last->next=p;
	last=p;
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

void sortAscending(){
	int temp;
	for(Node *i=first; i!=NULL; i=i->next){
		for(Node *j=i->next; j!=NULL; j=j->next){
			if(i->Value > j->Value){
				temp=j->Value;
				j->Value=i->Value;
				i->Value=temp;
			}
		}
	}
}

