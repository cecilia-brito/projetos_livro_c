#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char gNomeCadastro[50];

int main(int argc, char *argv[])
{
    int iEscolhaUsuario=0;
    int iRetornoCadastro=0;
    int iRetornoVerificarCurso=0;
    int iRetornoCursoCadastro=0;
    int iRetornoConsultaTodosCursos=0;


    //iRetornoCadastro=TesteCadastro();
    //printf("%d\n",iRetornoCadastro);


    printf("\nOPCOES: [1] Cadastra usuario\n ");
    printf(" [2] Lista todos cadastrados\n");
    printf(" [3] Procura usuario\n");
    scanf("%d",&iEscolhaUsuario);


    switch (iEscolhaUsuario ){

        case 1:

        /*iRetornoVerificarCurso = VerificarCurso();

        if (iRetornoVerificarCurso == 69) {
        printf("\nCurso ja existe!\n");
        getch();
        } else {
        */
        iRetornoCursoCadastro=TesteCadastro();


        if (iRetornoCursoCadastro == 800) {

        printf("\nNUMERO INVALIDA!!\n");
        getch();

        } else if (iRetornoCursoCadastro == 1) {
        printf("\nCadastro realizado com sucesso!!!\n");
        getch();
        } else {
        printf("retorno erro na funcao");
        }

        //}

        break;
        /*

        iRetornoCursoCadastro=TesteCadastro();


        if (iRetornoCursoCadastro == 800) {

        printf("\nNUMERO INVALIDA!!\n");
        getch();

        } else if (iRetornoCursoCadastro == 1) {
        printf("\nCadastro realizado com sucesso!!!\n");
        getch();
        } else {
        printf("retorno erro na funcao");
        }
        break;*/

        case 2:

        iRetornoConsultaTodosCursos=ListarTodosCursos();
        getch();
        break;

        case 3:

        iRetornoVerificarCurso=VerificarCurso();

        if (iRetornoVerificarCurso != 69) {
        printf("\nCurso nao existe!!\n");
        getch();
        } else {
        printf("\nCurso existe\n");
        getch();
        }
        break;



        default:
        printf ("\nOCORREU ERRO!\n");

        system("PAUSE");
        return (1);

        }










        system("PAUSE");
        return 0;
        }


    // FUNCOES QUE ESTOU TESTANDO!!!!

    //Funcao CursoCadastro
    // Objetivo:
    // Função genérica para realizar cadastro
    // Entrada:
    // Nenhuma
    // Retorno:
    // Nenhum

    int TesteCadastro(void) {

    char nomeCadastro[50];
    int codCadastro = 0;
    int conf = 1;
    FILE *arquivo;
    int result=0;


    printf("\nDigite o Nome do cadastro: \n");
    scanf("%s",&nomeCadastro);
    //fgets(nomeCadastro,50,stdin);

    //result=VerificarCurso(nomeCadastro);

    if (result == 69) {
    printf("\nEXISTE!!!\n");
    }

    printf("\nDigite o codigo de cadastro: [10 a 99] \n");
    scanf("%d",&codCadastro);

    if (codCadastro < 10 || codCadastro > 99) {
    printf("\nCODIGO INVALIDO!! - CODIGO DEVE SER ENTRE 10 e 99\n");
    getch();
    } else {


    arquivo = fopen("teste.txt","a+t");

    if(arquivo != NULL) {

    fprintf(arquivo, "%d %s\n",codCadastro,nomeCadastro);

    //fprintf(arquivo, "%s",nomeCadastro);
    //fprintf(arquivo, "%d\n", idadeCadastro);
    //fprintf(arquivo, "\n");

    fclose (arquivo);

    return (conf);
    }

    }

    }

    //Funcao ListarTodosCursos
    // Objetivo:
    // Listar todos os cursos cadastrados
    // Entrada:
    // Nenhuma
    // Retorno:
    // Nenhum

    int ListarTodosCursos(void) {

    FILE *arquivo;
    char Linha[100];
    char *result;
    int i;



    // Abre um arquivo TEXTO para LEITURA
    arquivo = fopen("teste.txt", "rt");

    if (arquivo == NULL) // Se houve erro na abertura
    {
    printf("Problemas na abertura do arquivo\n");
    return;
    }
    printf("\n[Linha no arquivo] - [CODIGO] [NOME]\n\n");
    i = 1;
    while (!feof(arquivo))
    {
    // Lê uma linha (inclusive com o '\n')
    result = fgets(Linha, 100, arquivo); // o 'fgets' lê até 99 caracteres ou até o '\n'


    if (result) // Se foi possível ler

    printf(" %d - %s",i,Linha);
    i++;
    }
    fclose(arquivo);
    }

    //Funcao VerificarCurso
    // Objetivo:
    // Listar determinado cursos cadastrados
    // Entrada:
    // Nenhuma
    // Retorno:
    // Retorna INTEIRO confirmando ou nao o cadastro
    //
    // Implementacao:
    // Implementar a string recebida, Ex: digite apenas 1 caracter existente no arquivo, depois digite uma palavra nao existente no arquivo.


    int VerificarCurso () {

    int conf=69;


    char nomeCurso[50];
    char linha[50];

    char nomeCadastro[50];


    FILE *arquivo;


    arquivo = fopen("teste.txt","r");
    if (!arquivo) {
    exit(1);
    } else {
    printf("\nDigite o NomeDoCurso: \n");
    scanf("%s",&nomeCurso);
    //fgets(nomeCurso,sizeof(nomeCurso),stdin); //lê uma string do teclado
    //nomeCurso[strlen(nomeCurso)-1]=nomeCurso[strlen(nomeCurso)]; //retira o \n lido pelo fgets

    while (fgets(linha,sizeof(linha),arquivo)!=NULL) //lê linha a linha do arquivo



    if (strstr(linha,nomeCurso)!=NULL) { //Verifica se uma string existe dentro de outra
    fclose(arquivo);
    return conf; //Retorna a confirmacao do curso;
    }

    }

}
