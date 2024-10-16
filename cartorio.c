#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação de espaço de memoria 
#include <locale.h> //biblioteca de alocaçoes de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

 int registro()
{
 	char arquivo[40]; 
 	char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	//final da criação de variaveis/strings!
 	printf("Digite o cpf a ser cadastrado!: ");
 	scanf("%s", cpf); //% refere-se a strings
 	
 	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
 	
 	FILE *file; //cria o arquivo
 	file = fopen(arquivo, "w"); //cria o arquivo o "w" significa escrever
 	fprintf(file, cpf); //salva o valor da variavel
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); // salva o arquivo com saparacao de informações por virgula!
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("digite o nome a ser cadastrado!: ");
 	scanf("%s",nome);
 	
 	file = fopen (arquivo, "a");
 	fprintf(file,nome);
 	fclose(file);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("digite o sobrenome a ser cadastrado!: ");
 	scanf("%s", sobrenome);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,sobrenome);
 	fclose(file);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("digite o cargo a ser cadastrado!: ");
 	scanf("%s", cargo);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,cargo);
 	fclose(file);
 	
 	system("pause"); //função de pausar o sistema.
}
 
 int consulta()
{
    
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
	char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado!: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL) 
    {
    	printf("Não foi possivel abrir o arquivo, não localisado!\n");
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
    system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}



 int main ()
 {
 	int opcao=0; //Definindo variaveis
 	int laco=1;
 	
 	for(laco=1;laco=1;)
 	{
	 
	 system ("cls"); //Responsavel por limpar a tela
	 
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

 		printf("### Cartorio da EBAC ###\n\n"); //Inicio do menu
 		printf("Escolha a opção desejada no menu\n\n");
 		printf("\t1 - Registrar nomes\n");
 		printf("\t2 - Consultar nomes\n");
 		printf("\t3 - Deletar nomes\n\n");
 		printf("\t4 - Sair do sistema\n\n");
 		printf("opcão: "); 
 	
    scanf("%d", &opcao); //Armazenando a escolha do usuário
 	
 	system("cls"); //Responsavel por lilimpar a tela
 	
 	switch (opcao) //Inicio da seleção do menu
 	{
 		case 1:
 		registro(); //Chamada de funções
		break;
		
		case 2: 
		consulta();
		break;
		
		case 3:	
		deletar();
	    break;
	    
	    case 4:
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0;
	    break;
	    
	    default:
	    printf("Essa opcão não esta disponivel!\n");
	    system("pause");
		break;	 //Fim da seleção
	    
	}
 	
	}
}
 
