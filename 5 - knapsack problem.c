#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Retorna o máximo valoresor que pode ser colocado na mochila
int valor_maximo(int a, int b) {
    return (a > b) ? a : b;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Algoritmo usando força bruta (recursivo)
int forca_bruta(int capacidade, int pesos[], int valores[], int n) {

    if (n == 0 || capacidade == 0)
        return 0;


    if (pesos[n - 1] > capacidade)
        return forca_bruta(capacidade, pesos, valores, n - 1);

    return valor_maximo(valores[n - 1] + forca_bruta(capacidade - pesos[n - 1], pesos, valores, n - 1),
               forca_bruta(capacidade, pesos, valores, n - 1));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Algoritmo usando método guloso
int algoritmo_guloso(int pesos[], int valores[], int n, int capacidade) {
    float razoes[n]; // Armazena pesos e valores
    for (int i = 0; i < n; i++) {
        razoes[i] = (float)valores[i] / pesos[i];
    }

	//Ordena pesos e valores
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (razoes[j] < razoes[j + 1]) {
                float tempRazao = razoes[j];
                razoes[j] = razoes[j + 1];
                razoes[j + 1] = tempRazao;

                int tempPeso = pesos[j];
                pesos[j] = pesos[j + 1];
                pesos[j + 1] = tempPeso;

                int tempValor = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = tempValor;
            }
        }
    }

    int valorTotal = 0;
    int pesoAtual = 0; 

    for (int i = 0; i < n; i++) {
        // Se o objeto cabe inteiro na mochila, adiciona o valor total
        if (pesoAtual + pesos[i] <= capacidade) {
            valorTotal += valores[i];
            pesoAtual += pesos[i];
        }
        // Caso contrário, calcula a fração do objeto que cabe na mochila
        else {
            float fracao = (float)(capacidade - pesoAtual) / pesos[i];
            valorTotal += fracao * valores[i];
            break; // Como a mochila está cheia, não é possível adicionar mais objetos
        }
    }

    return valorTotal;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Algoritmo usando programação dinâmica
int programacao_dinamica(int capacidade, int pesos[], int valores[])
{
   int i, j;
   int matriz[20+1][capacidade+1];

   for (i = 0; i <= 20; i++)
   {
       for (j = 0; j <= capacidade; j++)
       {
           if (i==0 || j==0)
               matriz[i][j] = 0;
           else if (pesos[i-1] <= j)
                 matriz[i][j] = valor_maximo(valores[i-1] + matriz[i-1][j-pesos[i-1]],  matriz[i-1][j]);
           else
                 matriz[i][j] =  matriz[i-1][j];
       }
   }
   return matriz[20][capacidade];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
setlocale(LC_ALL, "Portuguese"); 
//Capacidade da mochila informada pelo usuário
int capacidade; 
//Lista de valores das caixas
int valores[] = {7, 9, 4, 12, 10, 2, 13, 1, 7, 8, 11, 13, 6, 4, 10, 1, 6, 2, 7, 8};
//Lista dos pesos das caixas
int pesos[] = {200, 250, 450, 100, 300, 200, 400, 100, 50, 350, 250, 450, 50, 400, 100, 350, 200, 300, 200, 150};

int k;   
int escolha;   
  
while(escolha < 4){
 
	printf("\nQual algoritmo você irá escolher?\n\n"); 
	printf("1 - FORÇA BRUTA\n");  
	printf("2 - GULOSO\n");  
	printf("3 - DINÂMICO\n"); 
	printf("\nSua escolha: "); 
	scanf("%d", &escolha);
		
	switch(escolha){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  		
	case 1:{
		printf("\nInforme a capacidade da mochila: ");
		scanf("%d", &capacidade);
    	printf("\nValor da mochila = %d", forca_bruta(capacidade, pesos, valores, 20));
    	
    	printf("\n\n"); 
    	
    	for(k=0; k<20; k++){
    	printf("Caixa%d - Peso: %d - Valor: %d \n", k+1, pesos[k], valores[k]); 	
		}
	system("pause"); 
	system("cls"); 	
	}break;     	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 2:{ 
		printf("\nInforme a capacidade da mochila: ");
		scanf("%d", &capacidade); 
		int valorTotal = algoritmo_guloso(pesos, valores, 20, capacidade);
		printf("\nValor total na mochila: %d\n", valorTotal);
		    	
    	printf("\n\n"); 
    	
    	for(k=0; k<20; k++){
    	printf("Caixa%d - Peso: %d - Valor: %d \n", k+1, pesos[k], valores[k]); 	
		}
	system("pause"); 
	system("cls"); 	
	}break;     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	case 3:{
		printf("\nInforme a capacidade da mochila: ");
		int capacidade;
		scanf("%d", &capacidade);
    	printf("\nValor da mochila = %d", programacao_dinamica(capacidade, pesos, valores));
    	    	
    	printf("\n\n"); 
    	
    	for(k=0; k<20; k++){
    	printf("Caixa%d - Peso: %d - Valor: %d \n", k+1, pesos[k], valores[k]); 	
		}
	system("pause"); 
	system("cls"); 	
	}break;     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	default:
		printf("\nOpção inválida\n"); 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////		    
	}
	
}
return 0;
}
