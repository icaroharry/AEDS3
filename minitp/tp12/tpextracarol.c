#include <stdio.h>	// fopen, fclose, fgets, feof
#include <stdlib.h>	// malloc, free, exit, qsort
#include <string.h>	// strtok, strcmp, strcpy
#include <math.h> //pow, sqrt

void ImprimeVetor (int *Paineis, int num_paineis){
	int i=0;
	for (i=0; i<num_paineis; i++){
		printf("[%d]", Paineis[i]);
	}
	printf("\n");
}


int BuscaMaiorPeso (int *Caminhoes, int num_caminhoes){
	int i=0;
	int peso_max=0;
	peso_max = Caminhoes[0];
	for(i=1; i<num_caminhoes; i++){
		if (peso_max < Caminhoes[i]){
			peso_max = Caminhoes[i];
		}
	}
	return peso_max;
}


void InicializaSoma (int *Soma, int num_caminhoes){
	int i=0;
	for (i=0; i<num_caminhoes; i++){
		Soma[i]=0;
	}
}

int BuscaMenorSoma (int *Soma, int num_caminhoes){
	int i=0;
	int soma=0;
	soma = 0;
	for(i=1; i<num_caminhoes; i++){
		if (Soma[soma] > Soma[i] && Soma[i]!=0){
			soma = i;
		}
	}
	return soma;
}


void main (){
	int i=0, j=0;
	int num_testes=0;
	int num_paineis=0, num_caminhoes=0, frete=0;
	int peso=0, peso_max=0;
	int indice_soma=0;
	int *Paineis;
	int *Caminhoes, *Posicao, *Soma;
	int **Matriz;


	scanf ("%d", &num_testes);
	for (i=0; i<num_testes; i++){
		scanf ("%d %d %d", &num_paineis, &num_caminhoes, &frete);

		Paineis = (int*)calloc(num_paineis, sizeof(int));

		for (j=0; j<num_paineis; j++){
			scanf ("%d", &Paineis[j]);
		}

		Caminhoes = (int*)calloc(num_caminhoes+1, sizeof(int));
		Posicao = (int*)calloc(num_caminhoes, sizeof(int));
		Soma = (int*)calloc(num_caminhoes, sizeof(int));


		if (num_caminhoes < num_paineis){
			for (j=0; j<num_caminhoes+1; j++){
				Caminhoes[j] = Paineis[j];
			}
			for (j=0; j<num_caminhoes; j++){
				Posicao[j] = j+1;
			}
/*
			printf("PAINEIS:");
			ImprimeVetor (Paineis, num_paineis);
			printf("CAMINHOES:");
			ImprimeVetor (Caminhoes, num_caminhoes+1);
			printf("POSICAO:");
			ImprimeVetor (Posicao, num_caminhoes);
*/

			int indice=num_caminhoes+1;
			while (indice <= num_paineis){
				for (j=0; j<num_caminhoes; j++){
					Soma[j] = Caminhoes[j] + Paineis[Posicao[j]];
				}

				//printf("SOMA:");
				//ImprimeVetor (Soma, num_caminhoes);

				indice_soma = BuscaMenorSoma (Soma, num_caminhoes);
				//printf("INDICE SOMA: %d\n", indice_soma);

				Caminhoes[indice_soma] = Caminhoes[indice_soma] + Paineis[Posicao[indice_soma]];
				Caminhoes[indice_soma+1] = Caminhoes[indice_soma+1] - Paineis[Posicao[indice_soma]];

				Posicao[indice_soma]++;

				if (Caminhoes[indice_soma+1] == 0){
					for (j=indice_soma+1; j<num_caminhoes; j++){
						Caminhoes[j] = Caminhoes[j+1];
					}
					for (j=indice_soma+1; j<num_caminhoes-1; j++){
						Posicao[j] = Posicao[j+1];
					}

					Caminhoes[num_caminhoes] = Paineis[indice];
					Posicao[num_caminhoes-1] = indice;
					indice++;
				}


				if (Caminhoes[num_caminhoes] == 0){
					if (indice < num_paineis){
						Caminhoes[num_caminhoes] = Paineis[indice];
						indice++;
					}

					else {
						break;
					}
				}
/*
				printf("PAINEIS:");
				ImprimeVetor (Paineis, num_paineis);
				printf("CAMINHOES:");
				ImprimeVetor (Caminhoes, num_caminhoes+1);
				printf("POSICAO:");
				ImprimeVetor (Posicao, num_caminhoes);
*/
			}

		}

		else {
			for (j=0; j<num_caminhoes; j++){
				if (j<num_paineis){
					Caminhoes[j] = Paineis[j];
					Posicao[j] = j+1;
				}
				else {
					Caminhoes[j] = 0;
					Posicao[j] = 0;
				}
			}
		}

		peso_max = BuscaMaiorPeso(Caminhoes, num_caminhoes);
	    frete = (num_caminhoes * peso_max) * frete;

	    printf("%d $%d\n", peso_max, frete);

	    free (Paineis);
	    free (Caminhoes);
	    free (Soma);
	    free (Posicao);
	}
}
