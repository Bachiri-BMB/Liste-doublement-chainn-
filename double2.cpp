#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
typedef struct liste{
    int val;
    struct  liste  *suiv;
    struct  liste  *prev;
}liste;
void ajouterdebut( liste *tete,int a){
    liste *nouveau;
    nouveau=(liste*)malloc(sizeof(liste));
    nouveau->suiv=NULL;///machi dariri ibdaw n NULL
    nouveau->prev=NULL;///machi dariri ibdaw n NULL
    nouveau->val=a;
    nouveau->suiv=tete;
    if (tete!=NULL){
        nouveau->prev=tete;
        
}
    return nouveau;
}
liste*ajouterenfin(liste*tete,int a){
    liste *temp,*nouveau;
    nouveau=(liste*)malloc(sizeof(liste));
    nouveau->suiv=nouveau->prev=NULL;
    nouveau->val=a;
    if(tete==NULL){tete=nouveau;}
    else{
	
  	
        temp=tete;
        while(temp->suiv!=NULL){
        	     temp=temp->suiv;
        	 }
            nouveau->prev=temp;
            temp->suiv=nouveau ;
            temp=nouveau;


}
  return tete;
}
int min(liste*tete){

	int m=tete->val;
	tete=tete->suiv;	
	while(tete->suiv!=NULL){
		if(tete->val<m){
            m=tete->val;

        }		
	   	tete=tete->suiv;
	
	}
	return m;
}
liste* supprimeraudebut(liste*tete){
	liste*tmp;
	tmp=tete;
	if(tete!=NULL){
		tete=tete->suiv;
		
			free(tmp);
			

	}
	return tete;
	}



int max(liste*tete){
	int M=tete->val;
	tete=tete->suiv;
	while(tete->suiv!=NULL){
		
		if(tete->val>M){
			M=tete->val;

		}
			tete=tete->suiv;

	}
	return M;
}
void afficher( liste *tete){
	liste*tmp;
	tmp=tete;
	while(tmp!=NULL){
		printf("%d->",tmp->val);
		tmp=tmp->suiv;
	}

}
liste *triee(liste*tete){
	int pr;
	liste*tmp=tete;
	liste*p;
	for(tmp=tete;tmp->suiv!=NULL;tmp=tmp->suiv){
		for(p=tmp->suiv;p!=NULL;p=p->suiv){
			if(p->val <tmp->val){
				pr=p->val;
				p->val=tmp->val;
				tmp->val=pr;
			}
		}
	}
	return tete;
}
liste*ajouteraumilieu(liste*tete,int e,int v){
	liste*tmp,*b;
	if(tete!=NULL){
		tmp=tete;
		while(tmp->val!=v && tmp->suiv!=NULL){
			tmp=tmp->suiv;
		}
		if(tmp->val==v){
			b=(liste*)malloc(sizeof(liste));
			b->val=e;
			b->suiv=tmp->prev;
			b=tmp;
			if(tmp->suiv!=NULL){
				tmp->suiv->prev==b;;
				tmp->prev=b;
			}
			
		}
		
	}
	return tete;
}
int main (){
	liste*li=NULL;
	int i,nb,n,v,e,choix;
	printf("donnez le nombre element de la liste :");
	scanf("%d",&nb);
	for(i=0;i<nb;i++){
		scanf("%d",&n);
	    li=	ajouterenfin(li,n);
	}
	
	afficher(li);
	printf("donnez 1 pour ajouter debut ");
	scanf("%d",&choix);
    switch(choix){
    	case 1:
    		ajouterdebut(li,5);
    		break;
	}
   printf("\n le nombre le plus petit est  : %d   ");  
   min(li);
   	printf("\n le nombre le plus grand est   : %d   ");  
   max(li); 
   printf("\n triee \n ");
   li=triee(li);
   afficher(li);
   printf("\n la supprimation au debut \n ");
   li=supprimeraudebut(li);
   afficher(li);



  

}
