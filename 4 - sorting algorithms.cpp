#include<windows.h>
#include<locale.h> 
#include<stdlib.h>
#include<stdio.h> 
#include<time.h> 

#define TAM 10000

//Cria um vetor com 100 valores aleatórios 
void CriarVetor(int v1[]){	
int i = 0; 
srand(time(NULL)); 
	for(i=0; i<TAM; i++){
	v1[i] = rand(); 
	}	
}

//Copia os valores do vetor1 para o vetor2
void CopiarVetor(int v1[], int v2[]){
int i = 0; 
	for(i=0; i<TAM; i++){
	v2[i] = v1[i]; 	
	}	
}	

//Ordenar usando bubble sort
void bubblesort(int tam, int v2[]){
int i,j;
	for (i=tam-1; i>=1; i--) {
		for (j=0; j<i; j++) {
			if (v2[j]>v2[j+1]) {
				int temp = v2[j];
				v2[j] = v2[j+1];
				v2[j+1] = temp;
			}
		}
	}			
} 

//Ordenar usando selection sort
void selectionsort(int v2[], int tam) {
int i, j, min, aux;	
	for (i = 0; i < (tam-1); i++) {
		min = i;
		for (j = (i+1); j < tam; j++) {
			if(v2[j] < v2[min])
				min = j;
		}
		if (i != min) {
			aux = v2[i];
			v2[i] = v2[min];
			v2[min] = aux;
		}
	}
}

//Ordenar usando insertion sort
void insertionsort(int v2[], int tam){ 	
	int i, j, key;
	for (i = 1; i < tam; i++) {
		key = v2[i];
		j = i - 1;
		while (j >= 0 && v2[j] > key) {
			v2[j + 1] = v2[j];
			j = j - 1;
		}
		v2[j + 1] = key;
	}
}

//Ordenar usando shell sort
void shellsort(int v2[], int tam) {
int i, j, valor;
	int h = 1;
	while(h < tam) {
		h = 3*h+1;
	}
	while (h > 0) {
		for(i = h; i < tam; i++) {
			valor = v2[i];
			j = i;
			while (j > h-1 && valor <= v2[j - h]) {
				v2[j] = v2[j - h];
				j = j - h;
			}
			v2[j] = valor;
		}
		h = h/3;
	}
}

//Ordenar usando heap sort
void heapsort(int tam, int v2[]) {	
	int i = tam / 2, pai, filho, t;
	while(true) {
		if (i > 0) {
			i--;
			t = v2[i];
		} else {
			tam--;
			if (tam <= 0) return;
			t = v2[tam];
			v2[tam] = v2[0];
		}
		pai = i;
		filho = i * 2 + 1;
		while (filho < tam) {
			if ((filho + 1 < tam) && (v2[filho + 1] > v2[filho]))
				filho++;
			if (v2[filho] > t) {
				v2[pai] = v2[filho];
				pai = filho;
				filho = pai * 2 + 1;
			} else {
				break;
			}
		}
		v2[pai] = t;
	}
	
}

//Primeira parte do merge sort
void merge(int vetor[], int comeco, int meio, int fim) {
	int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
	int *vetAux;
	vetAux = (int*)malloc(tam * sizeof(int));
	
	while(com1 <= meio && com2 <= fim){
		if(vetor[com1] < vetor[com2]) {
			vetAux[comAux] = vetor[com1];
			com1++;
		} else {
			vetAux[comAux] = vetor[com2];
			com2++;
		}
		comAux++;
	}
	
	while(com1 <= meio){ //Caso ainda haja elementos na primeira metade
		vetAux[comAux] = vetor[com1];
		comAux++;
		com1++;
	}
	
	while(com2 <= fim) { //Caso ainda haja elementos na segunda metade
		vetAux[comAux] = vetor[com2];
		comAux++;
		com2++;
	}
	
	for(comAux = comeco; comAux <= fim; comAux++){ //Move os elementos de volta para o vetor original
		vetor[comAux] = vetAux[comAux-comeco];
	}
	free(vetAux);
}

//Segunda parte do merge sort
void mergesort(int vetor[], int comeco, int fim){
	if (comeco < fim) {
		int meio = (fim+comeco)/2;
	mergesort(vetor, comeco, meio);
	mergesort(vetor, meio+1, fim);
	merge(vetor, comeco, meio, fim);
	}
}

//Ordenar usando quick sort
void quicksort(int vetor[], int inicio, int final){
	int i, j, pivo, aux;
	i = inicio;
	j = final-1;
	pivo = vetor[(inicio + final) / 2];
	while(i <= j){
		
		while(vetor[i] < pivo && i < final){
			i++;
		}
		while(vetor[j] > pivo && j > inicio){
		j--;
		}
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
	quicksort(vetor, inicio, j+1);
	if(i < final)
	quicksort(vetor, i, final);
}

//Para ordenar os tempos do cronômetro
void ordenar(double v2[], int tam){
int i,j;
	for (i=tam-1; i>=1; i--) {
		for (j=0; j<i; j++) {
			if (v2[j]>v2[j+1]) {
				double temp = v2[j];
				v2[j] = v2[j+1];
				v2[j+1] = temp;
			}
		}
	}			
} 

//Função principal
int main(void){
setlocale(LC_ALL, "Portuguese"); 
int vetor1[TAM], vetor2[TAM]; 
int tam = TAM, k, escolha, contador = 0;  
double ordem[7], ordem2[7], aux[7]; 
 
do{
printf("1 - Criar um vetor\n"); 
printf("2 - Copiar/Restaurar conteúdo para outro vetor\n");
printf("3 - Mostrar itens do vetor\n");

printf("\n4 - Ordenação com bubble sort\n"); 
printf("5 - Ordenação com selection sort\n"); 
printf("6 - Ordenação com insertion sort\n"); 
printf("7 - Ordenação com shell sort\n"); 
printf("8 - Ordenação com heap sort\n"); 
printf("9 - Ordenação com merge sort\n"); 
printf("10 - Ordenação com quick sort\n"); 

printf("\n11 - Ordenar tempo dos 7 algoritmos de ordenação\n");

printf("\n0 - Sair do programa\n"); 
printf("\nSua escolha: "); 
scanf("%d", &escolha); 
switch(escolha){
///////////////////////////////////////////////////////////////////////////////////////////////////	
	case 1:
		CriarVetor(vetor1);  
		system("cls");
	break; 
///////////////////////////////////////////////////////////////////////////////////////////////////		
	case 2:
		CopiarVetor(vetor1, vetor2); 	
		system("cls");
	break;  
///////////////////////////////////////////////////////////////////////////////////////////////////		
	case 3:
			for(k=0; k<TAM; k++){
			printf("%d ", vetor2[k]);
			contador++;  	
			}	
			printf("\n\nQuantidade de valores: %d\n\n", contador); 
			contador = 0; 
			system("pause");
			system("cls");
	break; 
///////////////////////////////////////////////////////////////////////////////////////////////////		
	case 4:{ 
		clock_t start1, end1;
		start1 = clock();
		
	bubblesort(tam, vetor2);
	
		end1 = clock();
		double duration1 = ((double)end1 - start1)/CLOCKS_PER_SEC;
		printf("Tempo que levou para ordenar usando ordenação bubble sort: %f segundos\n", duration1);
		ordem[0] = duration1; 
		CopiarVetor(vetor1, vetor2);  
	system("pause"); 
	system("cls");
	}break;
///////////////////////////////////////////////////////////////////////////////////////////////////		
	case 5:{
		clock_t start2, end2;
		start2 = clock();
		 
    selectionsort(vetor2, tam); 
    
    	end2 = clock();
		double duration2 = ((double)end2 - start2)/CLOCKS_PER_SEC;
		printf("Tempo que levou para ordenar usando ordenação  selection sort: %f segundos\n", duration2);
		ordem[1] = duration2;
		CopiarVetor(vetor1, vetor2);  
    system("pause"); 
	system("cls");
	}break;
///////////////////////////////////////////////////////////////////////////////////////////////////	
	case 6:{ 
		clock_t start3, end3;
		start3 = clock();
		
	insertionsort(vetor2, tam);
		
		end3 = clock();
		double duration3 = ((double)end3 - start3)/CLOCKS_PER_SEC;
		printf("Tempo que levou para ordenar usando ordenação insertion sort: %f segundos\n", duration3);
		ordem[2] = duration3; 
		CopiarVetor(vetor1, vetor2); 	
	system("pause"); 
	system("cls");
	}break;
///////////////////////////////////////////////////////////////////////////////////////////////////	
	case 7:{ 
		clock_t start4, end4;
		start4 = clock();
		
	shellsort(vetor2, tam);
	
		end4 = clock();
		double duration4 = ((double)end4 - start4)/CLOCKS_PER_SEC;
		printf("Tempo que levou para ordenar usando ordenação shell sort: %f segundos\n", duration4);
		ordem[3] = duration4; 
		CopiarVetor(vetor1, vetor2); 	 
	system("pause"); 
	system("cls");
	}break;
///////////////////////////////////////////////////////////////////////////////////////////////////		
	case 8:{
		clock_t start5, end5;
		start5 = clock(); 
	
	heapsort(tam, vetor2); 
			 
		end5 = clock();
		double duration5 = ((double)end5 - start5)/CLOCKS_PER_SEC;
		printf("Tempo que levou para ordenar usando ordenação heap sort: %f segundos\n", duration5);
		ordem[4] = duration5; 		 
		CopiarVetor(vetor1, vetor2); 	  
	system("pause"); 	
	system("cls");
	}break;
///////////////////////////////////////////////////////////////////////////////////////////////////		
	case 9:{
		clock_t start6, end6;
		start6 = clock(); 
	
	mergesort(vetor2, 0, TAM); 
		
		end6 = clock();
		double duration6 = ((double)end6 - start6)/CLOCKS_PER_SEC;
		printf("Tempo que levou para ordenar usando ordenação merge sort: %f segundos\n", duration6);
		ordem[5] = duration6;  	
		CopiarVetor(vetor1, vetor2); 	
	system("pause"); 
	system("cls");
	}break;
///////////////////////////////////////////////////////////////////////////////////////////////////	
	case 10:{
	
		clock_t start7, end7;
		start7 = clock(); 
	
	quicksort(vetor2, 0, TAM); 
	    
		end7 = clock();
		double duration7 = ((double)end7 - start7)/CLOCKS_PER_SEC;
		printf("Tempo que levou para ordenar usando ordenação quick sort: %f segundos\n", duration7);
		ordem[6] = duration7;   	
	system("pause"); 
	system("cls");
	}break;
///////////////////////////////////////////////////////////////////////////////////////////////////	
	case 11: 
 	int j;
 	
 		for(j=0; j<7; j++){
		aux[j] = ordem[j]; 	
		}
 	
		for(j=0; j<7; j++){
 			ordem2[j] = ordem[j]; 	
		}
			
	ordenar(ordem, 7);	 
				
	for(j=0; j<7; j++){
 	printf("%dº lugar: = %f segundos ", j+1, ordem[j]); 	
 	
 		if(ordem[j] == ordem2[0]){
 			printf("- (bubble sort)\n");	
		}
		else if(ordem[j] ==  ordem2[1]){
 			printf("- (selection sort)\n");	
		}
		else if(ordem[j] ==  ordem2[2]){
 			printf("- (insertion sort)\n");	
		}
		else if(ordem[j] ==  ordem2[3]){
 			printf("- (shell sort)\n");	
		}
		else if(ordem[j] ==  ordem2[4]){
 			printf("- (heap sort)\n");	
		}
		else if(ordem[j] ==  ordem2[5]){
 			printf("- (merge sort)\n");	
		}
		else if(ordem[j] ==  ordem2[6]){
 			printf("- (quick sort)\n");	
		} 
	}
	
	for(j=0; j<7; j++){
	ordem2[j] == 0; 	
	}
	
	for(j=0; j<7; j++){
	ordem[j] = aux[j]; 	
	}
	printf("\n"); 	
	
	system("pause"); 
	system("cls");
	break; 	
///////////////////////////////////////////////////////////////////////////////////////////////////		
	case 0: 
		printf("\nFIM DO PROGRAMA\n");
		return 0; 
	break; 
	
	default: 
		printf("\nESCOLHA INVÁLIDA\n"); 
		system("pause"); 
		system("cls"); 			
}
	
}while(escolha != 0);

}	
	



	
	
	
	
	
	
	
	
	
	
