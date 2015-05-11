#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct produto{
        char descricao[40];
        int codigo;
        double preco;
        int quantidade;
}produtos;


produtos *alocarPrd(produtos *pr,int quant){
	
				pr = (produtos*)calloc(quant,sizeof(produtos));
			if(!pr){

				printf("Nao e possivel alocar memoria !!");	
			}
			
			return pr;
		
}












void preenche(produtos *pr,int quant){
int i;
 int continuar=1;
			for(i=0;i<quant;i++){
		
		do{
		
		printf("\n Informe a descriçao do produto [max 40 carcteres]: ");
        fflush(stdin);
		scanf("%s", &pr[i].descricao);
}while( pr[i].descricao==NULL);
	
	do{
		printf("\nInforme o codigo do produto: ");
			printf("\t -- 0 a 50 --\n");
		fflush(stdin);
		scanf("%d", &pr[i].codigo);}
while(!((pr[i].codigo>0)&&(pr[i].codigo<50)));

		do{
		
		printf("\nInforme o preco do produto: ");
			printf("\t -- POSITIVO OU NULO --\n");
		fflush(stdin);
		scanf("%lf", &pr[i].preco);
		}while(pr[i].preco<0);
		do{
		printf("\nInforme a quantidade em estoque: ");
		printf("\t -- POSITIVO OU NULO --\n");
		fflush(stdin);
		scanf("%d", &pr[i].quantidade);
		
		}while(pr[i].quantidade<0);

	/*
		   printf("GOSTARIA DE COLOCAR MAIS PRODUTOS?");
               do{
			   
			    printf("\n\t0 - NAO\n\t1 - SIM");
                scanf("%i", &continuar);
           }while((continuar!=1 )&&(continuar!=0));


if(i!=quant){
         
			    if(continuar == 1) {
                        continue;
                        }
                else break;
                }	*/
}

	
	}
	
void ValidarEstoque(produtos *pr,int quant){
			int i;	
					printf("\n\n\t ----- Lista de produtos em Falta : ----- \n");

		for(i=0;i<quant;i++) {
	
			if(pr[i].quantidade ==0){
					printf("\tTipo : %s\n", pr[i].descricao);
		printf("\tCodigo do produto : %i\n", pr[i].codigo);
		printf("\tPreco do produto : R$%.2lf\n", pr[i].preco);
		printf("\tQuantidade de produtos : %i\n", pr[i].quantidade);
		printf("\n");
				
			}
	
		}

}


	
void listarProdutos(produtos *pr,int quant){
	int i;	
	
		printf("\n\n\t ----- Lista de produtos Cadastrados : ----- \n");

	for(i=0;i<quant;i++) {
	
		printf("\tTipo : %s\n", pr[i].descricao);
		printf("\tCodigo do produto : %d\n", pr[i].codigo);
		printf("\tPreco do produto : R$%.2lf\n", pr[i].preco);
		printf("\tQuantidade de produtos : %d\n", pr[i].quantidade);
		printf("\n");
	}	
}





int main(){
         produtos *produto;
		int quant;
		
		
		do{
			printf("\nInformar o numero de produtos a ser cadastrado :");
			printf("\nFavor informar numero positivo maior que 0:");
			scanf("%d",&quant);
		}while(quant<=0);
		
		produto =alocarPrd(produto,quant);
		preenche(produto,quant);
		ValidarEstoque(produto,quant);
		listarProdutos(produto,quant);
		




	

		


	

system("pause");
return 0;

}

