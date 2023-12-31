#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include <ctime>
#include<iostream>
#pragma clang diagnostic ignored "-Winvalid-source-encoding"

using namespace std;

#define LEN sizeof(Poly)

typedef struct term{
	float coef;		//係數 
	int expn;		//指數 
	struct term *next;
}Poly,*Link;
int LocateElem(Link p, Link s, Link &q); 
void CreatePolyn(Link &p,int m);	//建立多項式 
void PrintPolyn(Link p);			//列印多項式（表示）			
int cmp(Link a, Link b);

Link Reverse(Link p);				//逆置多項式 
Link MultiplyPolyn(Link A,Link B);	//多項式相乘 
void Calculate(Link p,float x);		//多項式求值 

int main()
{
	Link P1,P2,P3;	//多項式 
	int L1,L2;		//多項式長度 
	clock_t start = 0, end = 0;
	float total_time = 0.0;

	printf("請輸入第一個多項式的項數：");
	scanf("%d",&L1);
	CreatePolyn(P1,L1);
    printf("第一個多項式為：");
	printf("P1(X)=");
	PrintPolyn(P1);
	printf("請輸入第二個多項式的項數：");
	scanf("%d",&L2);
	CreatePolyn(P2,L2);
    printf("第二個多項式為：");
	printf("P2(X)=");
	PrintPolyn(P2); 
	printf("\n");
	
	
	printf("兩個一元多項式相乘：   ");
	printf("P1(X)*P2(X)=");
	


	start = clock();
	P3=MultiplyPolyn(P1, P2);
	PrintPolyn(P3);
	end = clock();
	total_time = ((float)(end - start)) / CLOCKS_PER_SEC; // 返回值是 clock_t 型別的 CPU 時間，因為 CPU 的時間為整數，所以要強制轉型成 float，再除以 CLOCKS_PER_SEC 可得到秒值;

	cout << "相乘總共花費"<<total_time<<"秒\n";



	return 0;
}

int LocateElem(Link p, Link s, Link &q)
{
/*遍歷連結串列p，每一個結點與s比較指數，
若相同,q指向相同指數項的結點，返回1，
若不相同，根據s所指指數大小在連結串列p中的位置來確定q的指向結點，返回0 
*/ 
	Link p1 = p->next;
	Link p2 = p;
	while(p1){
		if(s->expn > p1->expn){
			p1 = p1->next;
			p2 = p2->next;
		}else if(s->expn == p1->expn){
			q = p1; 
			return 1;
		}else{
			q = p2;
			return 0;
		}
	}
	if(!p1){
		q = p2;
		return 0;
	}
}

void CreatePolyn(Link &p,int m) 
/*建立帶頭結點的連結串列(多項式) 
且無論按什麼順序輸入，或是有相同指數項
最終在多項式中�m是升冪順序！ 
*/
{
	Link s,q;
	int i;
	p=(Link)malloc(LEN);
	p->next=NULL;
	for(i=0;i<m;i++)
	{
		s=(Link)malloc(LEN);
		printf("輸入係數和指數（以空格隔開）:");
		scanf("%f %d", &s->coef, &s->expn);
		if(!LocateElem(p, s, q)){	//若沒有相同指數項，則鏈入 
			s->next = q->next;
			q->next = s;
		}else{						//若有相同指數項，則係數相加						
			q->coef+=s->coef;
		}
	}
}

void PrintPolyn(Link k)
//列印顯示多項式 
{
    Link p = k;
    Reverse(k);
    Link s;
	s = p->next;
	while(s)
	{
	        printf(" %.2f X^%d", s->coef, s->expn);
            s = s->next;
            if(s!=NULL)  
                if(s->coef>=0) printf(" +");
				//若下一項係數為正，則列印'+',否則不列印 
	}
	printf("\n");
    Reverse(k);
}

int cmp(Link a, Link b)
//比較兩結點指數大小，根據情況返回不同值 
{
	if (a->expn<b->expn) return  -1;
	else if(a->expn == b->expn) return  0;
	else return 1;
}



Link Reverse(Link p)
/*用頭插法逆置連結串列，
使多項式由降冪變成升冪順序
或使多項式由升冪變成降冪順序
*/ 
{
	Link head=p; 
	Link q1,q2;
    q2=head->next;
    head->next=NULL;//斷開頭結點與第一個結點 
    while(q2)
    {
        q1=q2;      
        q2=q2->next; 
		q1->next=head->next; //頭插 
		head->next=q1;  
    }      
    return head;//返回連結串列逆置後的頭結點 
}
Link MultiplyPolyn(Link A,Link B)
/*兩個多項式相乘得一個新多項式，並且返回新多項式的頭結點的指標
	相乘前，A，B兩個多項式均是升冪排序 
	相乘時，A為降冪排序，B為升冪排序  
*/
{
  Link pa,pb,pc,s,head;
  int k,maxExpn,minExpn;
  float coef;
  
  head=(Link)malloc(LEN);//頭結點 
  head->next=NULL;
  
  if(A->next!=NULL&&B->next!=NULL){
  	minExpn=A->next->expn+B->next->expn; //minExpn為兩個多項式中指數和的最小值 
 	A=Reverse(A);//將A降冪排列 
	B=Reverse(B);//將B降冪排列 
  	maxExpn=A->next->expn+B->next->expn; //maxExpn為兩個多項式中指數和的最大值
  }
  else{
	  	return head;
  }       
   pc=head;
   B=Reverse(B);//將B升冪排列 
   
   for(k = maxExpn;k>=minExpn;k--){ //多項式的乘積指數範圍為：minExpn~maxExpn
   		//根據兩項的指數和使每一次迴圈�m得到新多項式中一項  
   		pa = A->next;
   		while(pa !=NULL&&pa->expn>k){  //找到pa的位置 
		   	pa = pa->next;
		   }
   		pb = B->next;
   		while(pb!=NULL&&pa!=NULL&&pa->expn+pb->expn<k){//如果指數和和小於k，pb後移結點 
		   	pb = pb->next;
		   }
		coef=0.0;
		while(pa!=NULL&&pb!=NULL){
			if(pa->expn+pb->expn==k){ //如果指數和等於k,係數和累加，且pa，pb均後移結點 
				coef+=pa->coef*pb->coef;
                pa=pa->next;
                pb=pb->next;
			}
			else if(pa->expn+pb->expn>k){//如果指數和大於k，pb後移結點
				pa = pa->next;
			}
			else{//如果指數和和小於k，pb後移結點
					pb = pb->next;
			}	
		}
		if(coef!=0.0){
		//如果係數和不為0，則生成新結點，將係數和指數賦給新結點後插入到新多項式中 
			s=(Link)malloc(LEN);
            s->coef=coef;
            s->expn=k;
            s->next=pc->next;
            pc->next=s;
            pc=s;
		}
   }
   B = Reverse(B);
   head=Reverse(head);
   return head;	//返回新多項式的頭結點 
}



