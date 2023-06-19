#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include <ctime>
#include<iostream>
#pragma clang diagnostic ignored "-Winvalid-source-encoding"

using namespace std;

#define LEN sizeof(Poly)

typedef struct term{
	float coef;		//�Y�� 
	int expn;		//���� 
	struct term *next;
}Poly,*Link;
int LocateElem(Link p, Link s, Link &q); 
void CreatePolyn(Link &p,int m);	//�إߦh���� 
void PrintPolyn(Link p);			//�C�L�h�����]��ܡ^			
int cmp(Link a, Link b);

Link Reverse(Link p);				//�f�m�h���� 
Link MultiplyPolyn(Link A,Link B);	//�h�����ۭ� 
void Calculate(Link p,float x);		//�h�����D�� 

int main()
{
	Link P1,P2,P3;	//�h���� 
	int L1,L2;		//�h�������� 
	clock_t start = 0, end = 0;
	float total_time = 0.0;

	printf("�п�J�Ĥ@�Ӧh���������ơG");
	scanf("%d",&L1);
	CreatePolyn(P1,L1);
    printf("�Ĥ@�Ӧh�������G");
	printf("P1(X)=");
	PrintPolyn(P1);
	printf("�п�J�ĤG�Ӧh���������ơG");
	scanf("%d",&L2);
	CreatePolyn(P2,L2);
    printf("�ĤG�Ӧh�������G");
	printf("P2(X)=");
	PrintPolyn(P2); 
	printf("\n");
	
	
	printf("��Ӥ@���h�����ۭ��G   ");
	printf("P1(X)*P2(X)=");
	


	start = clock();
	P3=MultiplyPolyn(P1, P2);
	PrintPolyn(P3);
	end = clock();
	total_time = ((float)(end - start)) / CLOCKS_PER_SEC; // ��^�ȬO clock_t ���O�� CPU �ɶ��A�]�� CPU ���ɶ�����ơA�ҥH�n�j���૬�� float�A�A���H CLOCKS_PER_SEC �i�o����;

	cout << "�ۭ��`�@��O"<<total_time<<"��\n";



	return 0;
}

int LocateElem(Link p, Link s, Link &q)
{
/*�M���s����Cp�A�C�@�ӵ��I�Ps������ơA
�Y�ۦP,q���V�ۦP���ƶ������I�A��^1�A
�Y���ۦP�A�ھ�s�ҫ����Ƥj�p�b�s����Cp������m�ӽT�wq�����V���I�A��^0 
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
/*�إ߱a�Y���I���s����C(�h����) 
�B�L�׫����򶶧ǿ�J�A�άO���ۦP���ƶ�
�̲צb�h�������m�O�ɾ����ǡI 
*/
{
	Link s,q;
	int i;
	p=(Link)malloc(LEN);
	p->next=NULL;
	for(i=0;i<m;i++)
	{
		s=(Link)malloc(LEN);
		printf("��J�Y�ƩM���ơ]�H�Ů�j�}�^:");
		scanf("%f %d", &s->coef, &s->expn);
		if(!LocateElem(p, s, q)){	//�Y�S���ۦP���ƶ��A�h��J 
			s->next = q->next;
			q->next = s;
		}else{						//�Y���ۦP���ƶ��A�h�Y�Ƭۥ[						
			q->coef+=s->coef;
		}
	}
}

void PrintPolyn(Link k)
//�C�L��ܦh���� 
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
				//�Y�U�@���Y�Ƭ����A�h�C�L'+',�_�h���C�L 
	}
	printf("\n");
    Reverse(k);
}

int cmp(Link a, Link b)
//����⵲�I���Ƥj�p�A�ھڱ��p��^���P�� 
{
	if (a->expn<b->expn) return  -1;
	else if(a->expn == b->expn) return  0;
	else return 1;
}



Link Reverse(Link p)
/*���Y���k�f�m�s����C�A
�Ϧh�����ѭ����ܦ��ɾ�����
�ΨϦh�����Ѥɾ��ܦ���������
*/ 
{
	Link head=p; 
	Link q1,q2;
    q2=head->next;
    head->next=NULL;//�_�}�Y���I�P�Ĥ@�ӵ��I 
    while(q2)
    {
        q1=q2;      
        q2=q2->next; 
		q1->next=head->next; //�Y�� 
		head->next=q1;  
    }      
    return head;//��^�s����C�f�m�᪺�Y���I 
}
Link MultiplyPolyn(Link A,Link B)
/*��Ӧh�����ۭ��o�@�ӷs�h�����A�åB��^�s�h�������Y���I������
	�ۭ��e�AA�AB��Ӧh�������O�ɾ��Ƨ� 
	�ۭ��ɡAA�������ƧǡAB���ɾ��Ƨ�  
*/
{
  Link pa,pb,pc,s,head;
  int k,maxExpn,minExpn;
  float coef;
  
  head=(Link)malloc(LEN);//�Y���I 
  head->next=NULL;
  
  if(A->next!=NULL&&B->next!=NULL){
  	minExpn=A->next->expn+B->next->expn; //minExpn����Ӧh���������ƩM���̤p�� 
 	A=Reverse(A);//�NA�����ƦC 
	B=Reverse(B);//�NB�����ƦC 
  	maxExpn=A->next->expn+B->next->expn; //maxExpn����Ӧh���������ƩM���̤j��
  }
  else{
	  	return head;
  }       
   pc=head;
   B=Reverse(B);//�NB�ɾ��ƦC 
   
   for(k = maxExpn;k>=minExpn;k--){ //�h���������n���ƽd�򬰡GminExpn~maxExpn
   		//�ھڨⶵ�����ƩM�ϨC�@���j��m�o��s�h�������@��  
   		pa = A->next;
   		while(pa !=NULL&&pa->expn>k){  //���pa����m 
		   	pa = pa->next;
		   }
   		pb = B->next;
   		while(pb!=NULL&&pa!=NULL&&pa->expn+pb->expn<k){//�p�G���ƩM�M�p��k�Apb�Ჾ���I 
		   	pb = pb->next;
		   }
		coef=0.0;
		while(pa!=NULL&&pb!=NULL){
			if(pa->expn+pb->expn==k){ //�p�G���ƩM����k,�Y�ƩM�֥[�A�Bpa�Apb���Ჾ���I 
				coef+=pa->coef*pb->coef;
                pa=pa->next;
                pb=pb->next;
			}
			else if(pa->expn+pb->expn>k){//�p�G���ƩM�j��k�Apb�Ჾ���I
				pa = pa->next;
			}
			else{//�p�G���ƩM�M�p��k�Apb�Ჾ���I
					pb = pb->next;
			}	
		}
		if(coef!=0.0){
		//�p�G�Y�ƩM����0�A�h�ͦ��s���I�A�N�Y�ƩM���ƽᵹ�s���I�ᴡ�J��s�h������ 
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
   return head;	//��^�s�h�������Y���I 
}



