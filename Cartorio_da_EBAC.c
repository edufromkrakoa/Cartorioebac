#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidas das strings

int registro() // função responsável por cadastrar os usuários no sistema 
{
	//inicio criação de variáveis/strings (conjunto de variáveis) 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/strings (conjunto de variáveis)
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário 
	scanf("%s", cpf); //%s refere-se a salvar uma string/armazenar cpf
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); // cria o arquivo/ o w é de write (escrever)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //a virgula serve para separar as informações 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário 
	scanf("%s",nome); //%s refere-se a salvar uma string/armazenar nome
	
	file = fopen(arquivo, "a"); //cria o arquivo // a letra "A" serve para atualizar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo // a letra "A" serve para atualizar
	fprintf(file,","); //a virgula serve para separar as informações
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário 
	scanf("%s", sobrenome ); //%s refere-se a salvar uma string/armazenar sobrenome
	
	file = fopen(arquivo, "a"); //cria o arquivo // a letra "A" serve para atualizar 
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo // a letra "A" serve para atualizar
	fprintf(file,","); //a virgula serve para separar as informações
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuario 
	scanf("%s",cargo); //%s refere-se a salvar uma string/armazenar o cargo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system ("pause"); //Encerra a operação
	
}
	
int consulta() //função responsavel por consultar os usuarios no sistema 
{
	setlocale (LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//inicio criação de variáveis/strings (conjunto de variáveis) 
	char cpf [40];
	char conteudo [200];
	//final da criação de variáveis/strings (conjunto de variáveis) 
	
	printf("Digite o cpf a ser consultado: \n"); //Coleando informações do usuario 
	scanf("%s", cpf); //%s refere-se a salvar uma string/no caso consultar o cpf

	FILE *file; //Cria arquivo 
	file = fopen (cpf, "r"); //Cria o arquivo/ o r é de read (ler)
	
	if(file == NULL) //Caso o arquivo não tenha dados//não encontrou o cpf 
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n"); //informação dada ao usuário 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Laço de repetição // para de fazer a busca caso um caractere seja nulo  
	{
		printf("Essas são as informações do usuário: \n"); //informação dada ao usuário 	
		printf("%s", conteudo); //Salva conteudo da variável // "S" de string
		printf("\n\n"); //Quebra de linha 
	}
	system("pause"); //Encerra a operação
}	

int deletar() //Função responsavel por deletar informações
{
	//Inicio criação de variáveis/strings (conjunto de variáveis)
	char cpf [40];
	//Final da criação de variáveis/strings (conjunto de variáveis)
	
	printf("Digite o usuario a ser deletado: \n"); //Colet	ando informações do usuario
	scanf("%s",cpf); //%s refere-se a salvar uma string/no caso consultar o cpf
	
	remove (cpf); //Função responsavel por deletar o arquivo 
	
	FILE *file; //Cria o arquivo
	file = fopen (cpf,"r"); //Cria o arquivo/ o r é de read (ler)
	
	if (file == NULL) //Caso não encontre o arquivo por ser nulo 
	{
		printf("O usuario não se encontra no sistema! \n"); //Informação dada ao usuario 
		system("pause"); //Encerra operação
	}
	
}
	
int main() //Função responsavel pelo menu
{
	int opcao=0; //Definindo variáveis 
	int laco=1; // Responsavel por criar um loop
	
	for(laco=1;laco=1;) //Responsavel por inicializar as variaveis 
	{
		
		system("cls"); //Usado para limpar a tela // também usado para instrução
		
		setlocale(LC_ALL, "Portuguese"); //Difinindo a linguagem 
	
		printf("#### Cartório da EBAC ####\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do meunu
	
		scanf("%d", &opcao); //Armazenando escolha do usuário 
	
		system("cls"); //responsavel por limpar a tela  
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1: //Serve como um substituto do if
			registro(); //Chamada de funções 
			break; //Serve para encerar um loop
			
			case 2: //Serve como um substituto do if
			consulta(); //chamada de funções
			break; //serve para encerar um loop
			
			case 3: //Serve como um substituto do if
			deletar(); //chamada de funções
			break; //Serve para encerar um loop
			
			default: //Serve como interface padrão do menu
			printf("Essa opção não está disponinivel!"); //Informação dada ao usuario
			system("pause"); //Encerra operação 
			break; //Serve para encerar um loop
				
		}
	
	}
}
