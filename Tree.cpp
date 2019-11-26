#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5 // co con lon nhat cua 1 node

// CAU TRUC DU LIEU
typedef struct Tree{
	int key;
	char name[30];
	struct Tree *c[max+1];
}Node;
Node *root; // goc cua cay

// NGUYEN MAU CAC HAM
void insertNode(int k); // chen node vao cay
void widthPrint();  	// duyet cay theo chieu rong
void preOrder(Node *a); // duyet cay Tien thu tu
void inOrder(Node *a);  // duyet cay Trung thu tu
void postOrder(Node *a);// duyet cay Hau thu tu
Node *search(int k);    // tim 1 khoa trong cay (tra ve con tro tim dc, neu khong tim duoc thi tra ve NULL)

// Ham main
int main(){
	int choice, k; // lua chon, key
	Node *temp; // con tro trung gian
	root=NULL; // khoi tao cay rong (chua co goc)

	printf("-- PROGRAM: TREE _ NguyeDucHung --\n\n");
	printf("\nPlease choose task for Tree:");
	printf("\n  1. Insert Node     4. PreOrder");
	printf("\n  2. Width Print     5. InOrder");
	printf("\n  3. Search Key      6. PostOrder");
	printf("\n  0. Exit");
tt:	printf("\nYou choose: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf(" - Key         : ");
			scanf("%d",&k);
			insertNode(k);
			break;
		case 2:
			if(root==NULL)	break;
			else{
				widthPrint();
				break;
			}
		case 3:
			printf(" - Search: key = ");
			scanf("%d",&k);
			temp=search(k);
			if(temp!=NULL)		printf("   Node found: %d. %s\n", temp->key, temp->name);
			else 				printf("   Node not found\n");
			break;
		case 4:
			preOrder(root);
			break;
		case 5:
			inOrder(root);
			break;
		case 6:
			postOrder(root);
			break;
		default:
			printf("   Error choice, please choose again!\n");
			break;
		case 0:
			printf("   Task finished. Do you want continue the program? (1.Yes / 2.No):");
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
void insertNode(int k){
	Node *p, *r;
	int parentkey, child_i, i; // khoa cau cha, con thu may, bien chay
	if(p=search(k)){ // neu tim dc khoa k trong cay
		printf("   Key %d is exist before, use another key\n",k);
		return;
	}
	// neu khong tim dc -> tao node moi "r"
	r = (Node *)malloc(sizeof(Node));
	r->key=k;
	printf(" - Name        : ");
	fflush(stdin); // lam sach vung dem
	gets(r->name); // nhap ten
	for(int i=1; i<=max; i++) 	r->c[i]=NULL; // r moi tao ra, chua co con, cho cac con cua no bang NULL
	if(root==NULL){ // TH cay chua co goc --> r se la goc cay
		root=r;
		return;
	} 
	else{  // TH cay da co goc roi
		printf(" - Parent key  : "); // key cua Cha no?
		scanf("%d",&parentkey);
		printf(" - Child (1..5): "); // no la con thu may cua Cha no?
		scanf("%d",&child_i);
		p=search(parentkey); // tim xem co parentkey trong cay khong
		if(p==NULL){ // neu parentkey khong tom tai, thi xoa p, ket thuc
			printf("     Parent %d is not exist, child is not valid\n", parentkey);
			return;
		}
		else{ // nguoc lai, parentkey ton tai
			printf("   Parent: %3d. %s\n",p->key, p->name);
			printf("   Child : %3d. %s\n",r->key, r->name);
		}
		p->c[child_i]=r; // con moi cua q la r
	}
	
}

void widthPrint(){ // sd Queue vong tron
	Node *p, *r, *h[100]; // con tro, con tro, mang con tro
	int i, front, back, count; // bien chay, vtri dau Queue, vtri cuoi Queue, so ptu Queue
	h[1]=root;
	front=back=count=1;
	while(count>0){
		p=h[front];
		printf("  %3d: (", p->key); // in ra key
		for(i=1; i<=max; i++){ // xet den cac con cua no
			r=p->c[i];
			if(r!=NULL){ // neu khong rong thi in ra key
				printf("%3d - ", r->key);
				back++;
				h[back]=r; // cho con moi ra sau Queue
				count++;
			}
			else 	printf("___ - "); // neu rong
		}
		printf(")\n");
		h[front]=NULL; // huy ptu dau Queue
		front++;
		count--;
	}	
}

void preOrder(Node *a){
	if(a!=NULL){
		printf("  %3d. %s\n", a->key, a->name);
		for(int i=1; i<=max; i++){
			preOrder(a->c[i]);
		}
	}
}

void inOrder(Node *a){
	if(a!=NULL){
		inOrder(a->c[1]);
		printf("  %3d. %s\n", a->key, a->name);
		for(int i=2; i<=max; i++){
			inOrder(a->c[i]);
		}
	}
}

void postOrder(Node *a){
	if(a!=NULL){
		for(int i=1; i<=max; i++){
			postOrder(a->c[i]);
		}
		printf("  %3d. %s\n",a->key, a->name);
	}
}

Node *search(int k){ // sd Queue vong tron
	Node *p, *r, *h[100]; // con tro, con tro, mang con tro(gom toi da 100 ptu)
	int i, front, back, count; // bien chay, vtri dau Queue, vtri cuoi Queue, so ptu Queue
	if(root==NULL)	   return NULL; // TH cay rong --> tra ve NULL
	h[1]=root; 
	front=back=count=1;
	while(count>0){
		p=h[front]; // lay p la ptu dau tien cua Queue
		if(p->key==k) 	return p; // p co key trung key can tim --> tra ve p
		for(i=1; i<=max; i++){ // neu khong, xet den cac con cua no
			r=p->c[i];
			if(r!=NULL){
				if(r->key==k) 	return r; // neu con co key trung key can tim --> tra ve r
				back++;
				h[back]=r; // dua con ra cuoi Queue
				count++;
			}
		}
		h[front]=NULL; // xoa ptu dau Queue
		front++;
		count--;
		/*  --> Moi lan xet 1 ptu*, dien tat ca cac con cua no vao duoi Queue roi xoa no khoi dau Queue */
	}
	return NULL; // khong tim thay key --> tra ve False
}

