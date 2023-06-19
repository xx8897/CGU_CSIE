#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include <ctime>
#include<iostream>
#pragma clang diagnostic ignored "-Winvalid-source-encoding"

using namespace std;

#define LEN sizeof(Poly)

typedef struct term{
	float coef;		//«Y¼Æ 
	int expn;		//«ü¼Æ 
	struct term *next;
}Poly,*Link;
int LocateElem(Link p, Link s, Link &q); 
void CreatePolyn(Link &p,int m);	//«Ø¥ß¦h¶µ¦¡ 
void PrintPolyn(Link p);			//¦C¦L¦h¶µ¦¡¡]ªí¥Ü¡^			
int cmp(Link a, Link b);

Link Reverse(Link p);				//°f¸m¦h¶µ¦¡ 
Link MultiplyPolyn(Link A,Link B);	//¦h¶µ¦¡¬Û­¼ 
void Calculate(Link p,float x);		//¦h¶µ¦¡¨D­È 

int main()
{
	Link P1,P2,P3;	//¦h¶µ¦¡ 
	int L1,L2;		//¦h¶µ¦¡ªø«× 
	clock_t start = 0, end = 0;
	float total_time = 0.0;

	printf("½Ð¿é¤J²Ä¤@­Ó¦h¶µ¦¡ªº¶µ¼Æ¡G");
	scanf("%d",&L1);
	CreatePolyn(P1,L1);
    printf("²Ä¤@­Ó¦h¶µ¦¡¬°¡G");
	printf("P1(X)=");
	PrintPolyn(P1);
	printf("½Ð¿é¤J²Ä¤G­Ó¦h¶µ¦¡ªº¶µ¼Æ¡G");
	scanf("%d",&L2);
	CreatePolyn(P2,L2);
    printf("²Ä¤G­Ó¦h¶µ¦¡¬°¡G");
	printf("P2(X)=");
	PrintPolyn(P2); 
	printf("\n");
	
	
	printf("¨â­Ó¤@¤¸¦h¶µ¦¡¬Û­¼¡G   ");
	printf("P1(X)*P2(X)=");
	


	start = clock();
	P3=MultiplyPolyn(P1, P2);
	PrintPolyn(P3);
	end = clock();
	total_time = ((float)(end - start)) / CLOCKS_PER_SEC; // ªð¦^­È¬O clock_t «¬§Oªº CPU ®É¶¡¡A¦]¬° CPU ªº®É¶¡¬°¾ã¼Æ¡A©Ò¥H­n±j¨îÂà«¬¦¨ float¡A¦A°£¥H CLOCKS_PER_SEC ¥i±o¨ì¬í­È;

	cout << "¬Û­¼Á`¦@ªá¶O"<<total_time<<"¬í\n";



	return 0;
}

int LocateElem(Link p, Link s, Link &q)
{
/*¹M¾ú³sµ²¦ê¦Cp¡A¨C¤@­Óµ²ÂI»Ps¤ñ¸û«ü¼Æ¡A
­Y¬Û¦P,q«ü¦V¬Û¦P«ü¼Æ¶µªºµ²ÂI¡Aªð¦^1¡A
­Y¤£¬Û¦P¡A®Ú¾Ús©Ò«ü«ü¼Æ¤j¤p¦b³sµ²¦ê¦Cp¤¤ªº¦ì¸m¨Ó½T©wqªº«ü¦Vµ²ÂI¡Aªð¦^0 
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
/*«Ø¥ß±aÀYµ²ÂIªº³sµ²¦ê¦C(¦h¶µ¦¡) 
¥BµL½×«ö¤°»ò¶¶§Ç¿é¤J¡A©Î¬O¦³¬Û¦P«ü¼Æ¶µ
³Ì²×¦b¦h¶µ¦¡¤¤m¬O¤É¾­¶¶§Ç¡I 
*/
{
	Link s,q;
	int i;
	p=(Link)malloc(LEN);
	p->next=NULL;
	for(i=0;i<m;i++)
	{
		s=(Link)malloc(LEN);
		printf("¿é¤J«Y¼Æ©M«ü¼Æ¡]¥HªÅ®æ¹j¶}¡^:");
		scanf("%f %d", &s->coef, &s->expn);
		if(!LocateElem(p, s, q)){	//­Y¨S¦³¬Û¦P«ü¼Æ¶µ¡A«hÃì¤J 
			s->next = q->next;
			q->next = s;
		}else{						//­Y¦³¬Û¦P«ü¼Æ¶µ¡A«h«Y¼Æ¬Û¥[						
			q->coef+=s->coef;
		}
	}
}

void PrintPolyn(Link k)
//¦C¦LÅã¥Ü¦h¶µ¦¡ 
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
				//­Y¤U¤@¶µ«Y¼Æ¬°¥¿¡A«h¦C¦L'+',§_«h¤£¦C¦L 
	}
	printf("\n");
    Reverse(k);
}

int cmp(Link a, Link b)
//¤ñ¸û¨âµ²ÂI«ü¼Æ¤j¤p¡A®Ú¾Ú±¡ªpªð¦^¤£¦P­È 
{
	if (a->expn<b->expn) return  -1;
	else if(a->expn == b->expn) return  0;
	else return 1;
}



Link Reverse(Link p)
/*¥ÎÀY´¡ªk°f¸m³sµ²¦ê¦C¡A
¨Ï¦h¶µ¦¡¥Ñ­°¾­ÅÜ¦¨¤É¾­¶¶§Ç
©Î¨Ï¦h¶µ¦¡¥Ñ¤É¾­ÅÜ¦¨­°¾­¶¶§Ç
*/ 
{
	Link head=p; 
	Link q1,q2;
    q2=head->next;
    head->next=NULL;//Â_¶}ÀYµ²ÂI»P²Ä¤@­Óµ²ÂI 
    while(q2)
    {
        q1=q2;      
        q2=q2->next; 
		q1->next=head->next; //ÀY´¡ 
		head->next=q1;  
    }      
    return head;//ªð¦^³sµ²¦ê¦C°f¸m«áªºÀYµ²ÂI 
}
Link MultiplyPolyn(Link A,Link B)
/*¨â­Ó¦h¶µ¦¡¬Û­¼±o¤@­Ó·s¦h¶µ¦¡¡A¨Ã¥Bªð¦^·s¦h¶µ¦¡ªºÀYµ²ÂIªº«ü¼Ð
	¬Û­¼«e¡AA¡AB¨â­Ó¦h¶µ¦¡§¡¬O¤É¾­±Æ§Ç 
	¬Û­¼®É¡AA¬°­°¾­±Æ§Ç¡AB¬°¤É¾­±Æ§Ç  
*/
{
  Link pa,pb,pc,s,head;
  int k,maxExpn,minExpn;
  float coef;
  
  head=(Link)malloc(LEN);//ÀYµ²ÂI 
  head->next=NULL;
  
  if(A->next!=NULL&&B->next!=NULL){
  	minExpn=A->next->expn+B->next->expn; //minExpn¬°¨â­Ó¦h¶µ¦¡¤¤«ü¼Æ©Mªº³Ì¤p­È 
 	A=Reverse(A);//±NA­°¾­±Æ¦C 
	B=Reverse(B);//±NB­°¾­±Æ¦C 
  	maxExpn=A->next->expn+B->next->expn; //maxExpn¬°¨â­Ó¦h¶µ¦¡¤¤«ü¼Æ©Mªº³Ì¤j­È
  }
  else{
	  	return head;
  }       
   pc=head;
   B=Reverse(B);//±NB¤É¾­±Æ¦C 
   
   for(k = maxExpn;k>=minExpn;k--){ //¦h¶µ¦¡ªº­¼¿n«ü¼Æ½d³ò¬°¡GminExpn~maxExpn
   		//®Ú¾Ú¨â¶µªº«ü¼Æ©M¨Ï¨C¤@¦¸°j°ém±o¨ì·s¦h¶µ¦¡¤¤¤@¶µ  
   		pa = A->next;
   		while(pa !=NULL&&pa->expn>k){  //§ä¨ìpaªº¦ì¸m 
		   	pa = pa->next;
		   }
   		pb = B->next;
   		while(pb!=NULL&&pa!=NULL&&pa->expn+pb->expn<k){//¦pªG«ü¼Æ©M©M¤p©ók¡Apb«á²¾µ²ÂI 
		   	pb = pb->next;
		   }
		coef=0.0;
		while(pa!=NULL&&pb!=NULL){
			if(pa->expn+pb->expn==k){ //¦pªG«ü¼Æ©Mµ¥©ók,«Y¼Æ©M²Ö¥[¡A¥Bpa¡Apb§¡«á²¾µ²ÂI 
				coef+=pa->coef*pb->coef;
                pa=pa->next;
                pb=pb->next;
			}
			else if(pa->expn+pb->expn>k){//¦pªG«ü¼Æ©M¤j©ók¡Apb«á²¾µ²ÂI
				pa = pa->next;
			}
			else{//¦pªG«ü¼Æ©M©M¤p©ók¡Apb«á²¾µ²ÂI
					pb = pb->next;
			}	
		}
		if(coef!=0.0){
		//¦pªG«Y¼Æ©M¤£¬°0¡A«h¥Í¦¨·sµ²ÂI¡A±N«Y¼Æ©M«ü¼Æ½áµ¹·sµ²ÂI«á´¡¤J¨ì·s¦h¶µ¦¡¤¤ 
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
   return head;	//ªð¦^·s¦h¶µ¦¡ªºÀYµ²ÂI 
}



