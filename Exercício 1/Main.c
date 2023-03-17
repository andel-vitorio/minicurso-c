/**
 * Exercício de Programação 1
 * 
 * Criação:         16 mar 2023
 * Atualização:     16 mar 2023
 * Compiladores:    [Windows SO]  Microsoft (R) C/C++ Optimizing Compiler Versão 19.35.32215 para x86
 * 
 * Descrição:       Resolução do primeiro exercício de programação do minicurso de C, ministrado pelo 
 * 									professor André Cavalcante.
 * 
 * @author Andevaldo Vitório
 * @version 1.0, 2023-03-16
 *                  
*/

#include <stdio.h>
#include <math.h>


/// @brief Esta função limpa o buffer de entrada
inline static void clearBuffer() { while ( getchar() != '\n' ) {} }

/**
 * Esta função obtém o valor inteiro da equação do somatório para um 
 * determinado valor de i.
 * 
 * @param i Parâmetro da equação
 * @return Um valor inteiro resultante.
*/
inline static int getValue(int i) { return (int) pow(2.0 * i + 1.0, 2.0); };

/**
 * Esta função salva o limite superior do somatório a partir
 * de um valor digitado pelo usuário caso este seja válido.
 * 
 * @return Status da operação. Caso o valor seja válido, é retornado o valor inteiro 1.
 * 				 Caso contrário, é retornado um valor inteiro diferente de 1.
*/
int setUpperBound(int *upperBound) { return scanf_s("%d", upperBound, sizeof(upperBound)); }


/** 
 * Esta função calcula o valor de somatório.
 * 
 * @param[in] lowerBound Limite inferior do somatório
 * @param[in] upperBound Limite superior do somatório
 * 
 * @return O valor inteiro resultante do somatório.
*/
int summation(const int* lowerBound, const int* upperBound) {
	int ans = 0;

	for ( int i = *lowerBound; i <= *upperBound; ++i )
		ans += getValue(i);

	return ans;
}

int main (void) {
	int lowerBound = 0; /// @brief Representa o limite inferior do somatório
  int upperBound = 0; /// @brief Representa o limite superior do somatório

	printf("Informe o valor do limite superior do somatorio: ");
	int status = setUpperBound(&upperBound);
	
	while ( status != 1 ) {
		printf("ERROR: Valor invalido!\n\nInforme novamente o limite superior do somatorio: ");
		clearBuffer();
		status = setUpperBound(&upperBound);
	}

	int ans = summation(&lowerBound, &upperBound);
	printf("O valor do somatorio e: %d\n", ans);

	return 0;
}