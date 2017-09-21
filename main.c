#include <stdio.h>
#include <stdlib.h>

typedef struct {
int matricula;
char nome[30];
int idade;
struct Aluno *proximo;
struct Aluno *anterior;
}Aluno;
int callFunction(char *string, char letra);
int funcao01RecusivaCauda(char *string, char letra,int soma);
int funcao01Recursiva(char *string, char letra);


int main(void) {
	setbuf(stdout,NULL);
	fflush(stdin);
	char string[50];
	gets(string);
	//printf("%d", callFunction(string, 'a'));
	printf("%d",funcao01Recursiva(string,'b'));
	return 0;
}

Aluno* inserir(Aluno *lista){
	Aluno *novo;
	novo = (Aluno*) malloc(sizeof(Aluno));
	novo->proximo = NULL;
	novo->anterior = NULL;
	printf("Digite a matricula: ");
	scanf("%d", novo->matricula);
	printf("Digite o nome: ");
	gets(novo->nome);

	printf("Digite a idade: ");
	scanf("%d", novo->idade);

	novo->proximo = lista;
	lista->anterior = novo;
	return novo;

}
int callFunction(char *string, char letra){
	return funcao01RecusivaCauda(string,letra, 0);
}

int funcao01RecusivaCauda(char *string, char letra,int soma){
	if(*string == '\0'){
		return soma;
	}

	if(*string == letra){
		return funcao01RecusivaCauda(++string, letra, soma+1);
	}else{
		return funcao01RecusivaCauda(++string, letra,soma);
	}
}

int funcao01Recursiva(char *string, char letra){
	if(*string == '\0'){
		return 0;
	}
	if(*string == letra){
		return 1 + funcao01Recursiva(++string, letra);
	}else{
		return  funcao01Recursiva(++string, letra);
	}
}



