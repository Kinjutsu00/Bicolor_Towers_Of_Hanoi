#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // per lo sleep di prova
#include <stdbool.h>



int main(int argc, char *argv[]) {
	
	int k=0, risp=1, i;
	
	typedef struct disco{
		int dimension;
		char color;
		struct disco *next;
	}disco;

	disco *prima, *p, *seconda, *s, *appoggio, *supp;
	int num_totale=0;
	FILE *fPtr;
	fPtr = fopen("output_c.txt", "a");
	
/////////////////////////////////////////////////////algo///////////////////////////////////////////////////////////////
	
	
void mossa(disco *primo, disco *secondo){
	char a, b;
	num_totale++;
	if(primo->color=='A'){a='A';}
	else{
		if(primo->color=='B'){a='B';}
		else{
			if(primo->color=='C'){a='C';}
			else{printf("errore");}
		}
	}
	
	if(secondo->color=='A'){b='A';}
	else{
		if(secondo->color=='B'){b='B';}
		else{
			if(secondo->color=='C'){b='C';}
			else{printf("errore");}
		}
	}
	
	printf("Sposta da %c a %c \n", a, b);
	fprintf(fPtr, "%c,%c\n", a,b);
}

void pprint(disco *primo, disco *secondo, disco *supporto){
		printf("-----------------------------------------------------\n");
			printf("|||   Prima \t");
			disco *x, *y, *z, *a, *b, *c;
			if(primo->color=='A'){a=primo;}
			else{
				if(secondo->color=='A'){a=secondo;}
				else{
					if(supporto->color=='A'){a=supporto;}
					else{printf("errore");}
				}
			}
			for(x = a; x!=NULL; x = x->next){
				printf("%d-%c", x->dimension, x->color);//sleep(1);
				printf("\t");
			}
			printf("\n|||\n");
//
			printf("|||   Secoda \t");
			if(primo->color=='B'){b=primo;}
			else{
				if(secondo->color=='B'){b=secondo;}
				else{
					if(supporto->color=='B'){b=supporto;}
					else{printf("errore");}
				}
			}

			for(y = b; y!=NULL; y=y->next){
				printf("%d-%c", y->dimension, y->color);//sleep(1);
				printf("\t");
			}
			printf("\n|||\n");
//
			printf("|||   Appoggio \t");
			if(primo->color=='C'){c=primo;}
			else{
				if(secondo->color=='C'){c=secondo;}
				else{
					if(supporto->color=='C'){c=supporto;}
					else{printf("errore");}
				}
			}
			for(z = c; z!=NULL; z=z->next){
				printf("%d-%c", z->dimension, z->color);//sleep(1);
				printf("\t");
			}
			printf("\n");
printf("-----------------------------------------------------\n\n");
			
	}
	
void hanoi(int k, disco *primo, disco *secondo, disco *supporto){
	//printf("\n entro hanoi \n");
		disco *prims, *a, *secs;
		prims=NULL;
		a=NULL;
		secs=NULL;
		if(k==1){
			for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
			for(secs=secondo; secs->next!=NULL; secs=secs->next){}
			//printf("passo base\n");
			//SE sono uguali ne sposto 2, cosi risparmio.
			if(prims->dimension == a->dimension && prims->color != a->color){
				//move A to B
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
				for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
				for(secs=secondo; secs->next!=NULL; secs=secs->next){}
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			//	printf("ne muovo 2\n");
				
			}
			else{//ne muovo solo 1
				//move A to B
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			}
			
			//printf("fine hanoi 1\n");
		}
		//normale
		else{
		//	printf("passo normale\n");
			hanoi(k-1, primo, supporto, secondo);
			for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
			for(secs=secondo; secs->next!=NULL; secs=secs->next){}
/////////////////////////////////////////
			if(prims->dimension == a->dimension && prims->color != a->color){
				//move A to B
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
				for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
				for(secs=secondo; secs->next!=NULL; secs=secs->next){}
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
				
			}
			else{//ne muovo solo 1
				//move A to B
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			}
///////////////////////////////////////
	//		printf("scambio\n");
			hanoi(k-1, supporto, secondo, primo);
		}
		
}

void hanoi2(int k, disco *primo, disco *secondo, disco *supporto){
//	printf("  entro hanoi 2\n");
	disco *secs, *a, *prims;
	secs=NULL;
	a=NULL;
	prims=NULL;
	if(k==1){
//		printf("passo base\n");
		//Sposta A a B
			for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
			for(secs=secondo; secs->next!=NULL; secs=secs->next){}
			if(prims->color!=0 && a!=NULL){
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			}
	
		//Sposta A a B
			for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
			for(secs=secondo; secs->next!=NULL; secs=secs->next){}
			if(prims->color!=0 && a!=NULL){
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			}
	}
	else{
//		printf("passo normale\n");
		hanoi2(k-1, primo, supporto, secondo);
		//Sposta A a B
			for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
			for(secs=secondo; secs->next!=NULL; secs=secs->next){}
			if(prims->color!=0 && a!=NULL){
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			}
		//Sposta A a B
			for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
			for(secs=secondo; secs->next!=NULL; secs=secs->next){}
			if(prims->color!=0 && a!=NULL){
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			}
		hanoi2(k-1, supporto, secondo, primo);
	}
}


void splitta(int k, disco *primo, disco *secondo, disco *supporto){
	disco *secs, *a, *prims;
	a=NULL;
	secs=NULL;
	prims=NULL;
//	printf("\n ..........................................................entro splitta \n");
		if(k==1){
//			printf("passo base\n");
			//sposta da A a B
			for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
			for(secs=secondo; secs->next!=NULL; secs=secs->next){}
			if(prims->color!=0 && a!=NULL){
				mossa(primo, secondo);
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			}
			
			//passo base
			//FAI BELLA PRINT
		}
		else{//	printf("passo normale\n");
				hanoi2(k-1, primo, supporto, secondo);
				//sposta da A a B;
				for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
				for(secs=secondo; secs->next!=NULL; secs=secs->next){}
				if(prims->color!=0 && a!=NULL){
					mossa(primo, secondo);
					secs->next = prims;
					a->next = NULL;
					pprint(primo, secondo, supporto);
				}
				hanoi2(k-1, supporto, primo, secondo);
				splitta(k-1, primo, secondo, supporto);
		}
}

void hanoi_bicolore(int i, int k, disco *primo, disco *secondo, disco *supporto){
	//passo base
	
	//printf("\n entro hanoi bocolore \n");
			if(k==i/2){
		//		printf("...........................................prima di risolvi\n");
				p=prima->next;
				s=seconda->next;
			//check base
			//vermanete prima torre
				if(p!=NULL && p->color=='r'){//se blu va bene ,altrimenti swappa tutto;
					printf("1");
						hanoi2(k, prima, supporto, seconda);//perche se la base non va bene, faccio una sorta di travaso
			//			printf("travaso\n");
						hanoi2(k, supporto, seconda, prima);
						splitta(k, seconda, prima, supporto);
				}
				else{
					if(p!=NULL){
				//		printf("2");
						splitta(k, prima, seconda, supporto);
					}
				}
			
				if(s!=NULL && s->color=='b'){
				//	printf("3");
					hanoi2(k, seconda, supporto, prima); //travaso
				//	printf("travaso\n");
					hanoi2(k, supporto, prima, seconda);
					splitta(k, prima, seconda, supporto);
				}
				else{
					if(s!=NULL){
				//		printf("4");
						splitta(k, seconda, prima, supporto);
					}
				}
			}//passo
			else{
				hanoi(k+1, secondo, primo, supporto);
				hanoi_bicolore(i, k+1, secondo, primo, supporto);	
			}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//CONTROLLO: K>0 E CHE K SIA PARI
	do{
		printf("Quanti disci userai? \n");
		scanf("%d", &k);
		if(k == 0){
				printf("Non puoi mettere zero disci!\n");
		}
		else{
				if(k%2 != 0){
						printf("Devi mettere un ugule numero di disci blu e disci rossi!\n");
				}
				else{
					risp=0;
				}
		}
	} while(risp == 1);
	//CREO BASI TORRI ALETERNATE
	prima = (disco *) malloc(sizeof(disco)); p=prima;
	prima->dimension=0; prima->color='A'; prima->next=NULL;
	seconda = (disco *) malloc(sizeof(disco)); s=seconda;
	seconda->dimension=0; seconda->color='B'; seconda->next=NULL;
	appoggio = (disco *) malloc(sizeof(disco));
	appoggio->dimension=0; appoggio->color='C'; appoggio->next=NULL;
	printf("Basi, create\n");
	//CREO TORRI ALTERNATE
	for(i=0; i<(k)/2; i++){
		//PRIMA
		supp = (disco *) malloc(sizeof(disco));
		supp->dimension=k-i-(k/2); 
		if(i%2==0){
			supp->color='r';
		}
		else{
			supp->color='b';
		} 
		supp->next=NULL;
		for(p=prima; p->next!=NULL; p=p->next){}
		p->next=supp;
		supp=NULL;
		//SECONDA
		supp = (disco *) malloc(sizeof(disco));
		supp->dimension=k-i-(k/2); 
		if(i%2==0){
			supp->color='b';
		}
		else{
			supp->color='r';
		} 
		for(s=seconda; s->next!=NULL; s=s->next){}
		supp->next=NULL;
		s->next=supp;
	}
	i=k;
	k=0;
	p=prima->next;
	s=seconda->next;
	printf("\n INIZIO \n\n");
	pprint(prima, seconda, appoggio);
	hanoi_bicolore(i, k, seconda, prima, appoggio);
	printf("\n\n");
	printf("NUMERO TOTALE DI MOSSE ESEGUITE: %d", num_totale);
	
}



