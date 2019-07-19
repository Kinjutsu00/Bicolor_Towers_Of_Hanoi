#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	
	int k=0, risp=1, i;
	
	typedef struct disco{
		int dimension;
		char color;
		struct disco *next;
	}disco;

	disco *prima, *p, *seconda, *s, *appoggio, *supp, *primo, *secondo, *supporto;
	int num_totale=0;
	//funzione di print
	void pprint(disco *primo, disco *secondo, disco *supporto){
		num_totale++;
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
			printf("|||   Appogi \t");
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
	
	FILE *fp; 
	fp=fopen("input.txt", "r");
	if(fp==NULL){
	printf(" errore di apertura \n");
	}
	

	
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
	primo=prima;
	secondo=seconda;
	supporto=appoggio;
	pprint(primo, secondo, supporto);
	//ho creato le torri ora devo solo fare la move
	disco *secs, *a, *prims;
	a=NULL;
	secs=NULL;
	prims=NULL;

	char v, f;

	while(!feof(fp)){
		fscanf(fp, "%c,%c\n", &v, &f);
		printf("1: ");
		printf("%c", v);
		printf("\n");
		printf("2: ");
		printf("%c", f);
		printf("\n");
		printf("\n");
		printf("\n");
		if(v=='A' && f=='B'){ //sposto da A a B
		
			for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
			for(secs=secondo; secs->next!=NULL; secs=secs->next){}
			if(prims->dimension!=0 && a!=NULL){
				secs->next = prims;
				a->next = NULL;
				pprint(primo, secondo, supporto);
			}
			else{printf("errore atomico sposta da A a B");}
			
		}
		else{
			if(v=='A' && f=='C'){ //sposto da A a C
			
				for(prims=primo; prims->next!=NULL; prims=prims->next){a=prims;}
				for(secs=appoggio; secs->next!=NULL; secs=secs->next){}
				if(prims->dimension!=0 && a!=NULL){
					secs->next = prims;
					a->next = NULL;
					pprint(primo, secondo, supporto);
				}
				else{printf("errore atomico sposta da A a C");}
				
			}
			else{
				if(v=='B' && f=='A'){ //Sposta da B ad A
					for(prims=secondo; prims->next!=NULL; prims=prims->next){a=prims;}
					for(secs=primo; secs->next!=NULL; secs=secs->next){}
					if(prims->dimension!=0 && a!=NULL){
						secs->next = prims;
						a->next = NULL;
						pprint(primo, secondo, supporto);
					}
					else{printf("errore atomico sposta da B a A");}
				}
				else{
					if(v=='B' && f=='C'){ //Sposta da B ad C
						
						for(prims=secondo; prims->next!=NULL; prims=prims->next){a=prims;}
						for(secs=appoggio; secs->next!=NULL; secs=secs->next){}
						if(prims->dimension!=0 && a!=NULL){
							secs->next = prims;
							a->next = NULL;
							pprint(primo, secondo, supporto);
						}
						else{printf("errore atomico sposta da B a C");}
						
					}
					else{
						if(v=='C' && f=='A'){ //Sposta da C ad A
							
							for(prims=appoggio; prims->next!=NULL; prims=prims->next){a=prims;}
							for(secs=primo; secs->next!=NULL; secs=secs->next){}
							if(prims->dimension!=0 && a!=NULL){
								secs->next = prims;
								a->next = NULL;
								pprint(primo, secondo, supporto);
							}
							else{printf("errore atomico sposta da C a A");}
							
						}
						else{
							if(v=='C' && f=='B'){ //Sposta da C ad B
							
								for(prims=appoggio; prims->next!=NULL; prims=prims->next){a=prims;}
								for(secs=secondo; secs->next!=NULL; secs=secs->next){}
								if(prims->dimension!=0 && a!=NULL){
									secs->next = prims;
									a->next = NULL;
									pprint(primo, secondo, supporto);
								}
								else{printf("errore atomico sposta da C a B");}
							
							}
							else{
								printf("errore fondo");
							}
						}	
					}
				}
					
			}
		}
	}


printf("\n\n");
	printf("NUMERO TOTALE DI MOSSE ESEGUITE: %d", num_totale);
}
