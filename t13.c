#include <stdio.h>
#define TAM 80000

int primosrelativos(int vet[], int contro){
	int i,j, y, z, controle;
	
	for(i=0;i<contro;i++){
		y=1;
		z=i+1;
		if(z==contro){
			z=0;
		} //Verifica se terminou o for

		//(vetor02[i]<vetor02[z])?controle=vetor02[i]:controle=vetor02[z];
		if(vet[i] < vet[z]){
			controle = vet[i];
		}else{
			controle = vet[z];
		}

		if(controle < 0){
			controle *= -1;
		}
		//(controle<0)?controle = controle * -1:controle= controle * 1;

		for(j=2;j<=controle;j++){			
			if(((vet[i]%j)==0)&&((vet[z]%j)==0)){				
				y++;				
			}		
		}
		(y==1)?printf("%i e %i: PRIMOS RELATIVOS\n",vet[i],vet[z]):0;
	}
}

int triangulares(int vet[], int i){
	int j, aux = 0;

	// for(j=1;j<vet[i];j++){
	// 	//aux = (j*(j+1))/2;
	// 	//aux = ((j * j) + j) / 2;
	// }


for(j = 1 ; j*(j+1)*(j+2)<=vet[i]; j++){
    if(j*(j+1)*(j+2)==vet[i]){
        aux = 1;
    }
}




	return aux;	
}

int main(){
	int vet[TAM], n, t, aux;
	int i, j, y;
	int par=0, impar=0;

	while (t<=0){
	   	printf("# Digite um número positivo:\n");
	   	if (scanf("%d",&t)==0){
	      	printf("ERRO. DIGITE NOVAMENTE\n");
	      	while(fgetc(stdin)!='\n');
	      	continue;   
	   }	   
	}

	for(i=0;i<t;i++){ 
		//printf("LE VALORES: ");  			//LÊ VALORES
		scanf("%i",&vet[i]); //leitura
		((vet[i]%2)==0)?par++:impar++; //contagem de par e impares
	}

	for(i=0;i<t;i++){	//PASSA OS IMPARES PARA AS ULTIMAS POSIÇÕES -------======== função enviar as variaveris ṕar e impar
			j=i+1;
			y=i;
			if((vet[i] % 2) != 0){
			    for(;j<t;j++){			    	
			    	if((vet[j]%2)!=0){	
			    		continue;
			    	}
				    aux = vet[y];
				    vet[y] = vet[j];
				    vet[j] = aux;
				    y = j;   
				}  
			}       			
	}	
	for(i=0;i<par;i++){			//ORDENA OS PARES
		j=i+1;
		for(;j<par;j++){
			if(vet[i] > vet[j]){
	            aux = vet[i];
	            vet[i] = vet[j];
	            vet[j] = aux;
	        }
		}
	}
	impar +=par;	
	for(i=par;i<impar;i++){			//ORDENA OS IMPARES
		j=i+1;
		for(;j<impar;j++){
			//if((vet[i] % 2)!=0){
				if(vet[j] > vet[i]){
		            aux = vet[i];
		            vet[i] = vet[j];
		            vet[j] = aux;
		        }
		    //}    
		}
	}

	primosrelativos(vet,t);

	for(i=0;i<t;i++){
		aux = triangulares(vet,i);
		printf("aux == %i\n",aux);
	}

printf("\n");
for(i=0;i<t;i++){  //for pares
		printf("%i  |",vet[i]);
	}
printf("PAR[%i] || IMPAR[%i]\n",par,impar);


}