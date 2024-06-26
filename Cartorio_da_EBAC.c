#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidas das strings

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	//inicio cria��o de vari�veis/strings (conjunto de vari�veis) 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/strings (conjunto de vari�veis)
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio 
	scanf("%s", cpf); //%s refere-se a salvar uma string/armazenar cpf
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); // cria o arquivo/ o w � de write (escrever)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //a virgula serve para separar as informa��es 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio 
	scanf("%s",nome); //%s refere-se a salvar uma string/armazenar nome
	
	file = fopen(arquivo, "a"); //cria o arquivo // a letra "A" serve para atualizar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo // a letra "A" serve para atualizar
	fprintf(file,","); //a virgula serve para separar as informa��es
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio 
	scanf("%s", sobrenome ); //%s refere-se a salvar uma string/armazenar sobrenome
	
	file = fopen(arquivo, "a"); //cria o arquivo // a letra "A" serve para atualizar 
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo // a letra "A" serve para atualizar
	fprintf(file,","); //a virgula serve para separar as informa��es
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usuario 
	scanf("%s",cargo); //%s refere-se a salvar uma string/armazenar o cargo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system ("pause"); //Encerra a opera��o
	
}
	
int consulta() //fun��o responsavel por consultar os usuarios no sistema 
{
	setlocale (LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//inicio cria��o de vari�veis/strings (conjunto de vari�veis) 
	char cpf [40];
	char conteudo [200];
	//final da cria��o de vari�veis/strings (conjunto de vari�veis) 
	
	printf("Digite o cpf a ser consultado: \n"); //Coleando informa��es do usuario 
	scanf("%s", cpf); //%s refere-se a salvar uma string/no caso consultar o cpf

	FILE *file; //Cria arquivo 
	file = fopen (cpf, "r"); //Cria o arquivo/ o r � de read (ler)
	
	if(file == NULL) //Caso o arquivo n�o tenha dados//n�o encontrou o cpf 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n"); //informa��o dada ao usu�rio 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //La�o de repeti��o // para de fazer a busca caso um caractere seja nulo  
	{
		printf("Essas s�o as informa��es do usu�rio: \n"); //informa��o dada ao usu�rio 	
		printf("%s", conteudo); //Salva conteudo da vari�vel // "S" de string
		printf("\n\n"); //Quebra de linha 
	}
	system("pause"); //Encerra a opera��o
}	

int deletar() //Fun��o responsavel por deletar informa��es
{
	//Inicio cria��o de vari�veis/strings (conjunto de vari�veis)
	char cpf [40];
	//Final da cria��o de vari�veis/strings (conjunto de vari�veis)
	
	printf("Digite o usuario a ser deletado: \n"); //Colet	ando informa��es do usuario
	scanf("%s",cpf); //%s refere-se a salvar uma string/no caso consultar o cpf
	
	remove (cpf); //Fun��o responsavel por deletar o arquivo 
	
	FILE *file; //Cria o arquivo
	file = fopen (cpf,"r"); //Cria o arquivo/ o r � de read (ler)
	
	if (file == NULL) //Caso n�o encontre o arquivo por ser nulo 
	{
		printf("O usuario n�o se encontra no sistema! \n"); //Informa��o dada ao usuario 
		system("pause"); //Encerra opera��o
	}
	
}
	
int main() //Fun��o responsavel pelo menu
{
	int opcao=0; //Definindo vari�veis 
	int laco=1; // Responsavel por criar um loop
	
	for(laco=1;laco=1;) //Responsavel por inicializar as variaveis 
	{
		
		system("cls"); //Usado para limpar a tela // tamb�m usado para instru��o
		
		setlocale(LC_ALL, "Portuguese"); //Difinindo a linguagem 
	
		printf("#### Cart�rio da EBAC ####\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do meunu
	
		scanf("%d", &opcao); //Armazenando escolha do usu�rio 
	
		system("cls"); //responsavel por limpar a tela  
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1: //Serve como um substituto do if
			registro(); //Chamada de fun��es 
			break; //Serve para encerar um loop
			
			case 2: //Serve como um substituto do if
			consulta(); //chamada de fun��es
			break; //serve para encerar um loop
			
			case 3: //Serve como um substituto do if
			deletar(); //chamada de fun��es
			break; //Serve para encerar um loop
			
			default: //Serve como interface padr�o do menu
			printf("Essa op��o n�o est� disponinivel!"); //Informa��o dada ao usuario
			system("pause"); //Encerra opera��o 
			break; //Serve para encerar um loop
				
		}
	
	}
}
