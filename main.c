#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//Interface
#define PRETO 0
#define AZUL  1
#define VERDE 2
#define VERDEAGUA 3
#define VERMELHO  4
#define ROXO    5
#define AMARELO 6
#define BRANCO  7
#define CINZA   8
#define AZULCLARO  9
#define VERDECLARO 10
#define VERDEAGUACLARO 11
#define VERMELHOCLARO  12
#define LILAS 13
#define AMARELOCLARO 14
#define BRANCOBR 15

//Declaração de funções
void inicial();
void carregando();
void menu_inicial();
void data();
void hora();
void menu_adm();
void cadastrar_cl();
void alug_filmes();
int valida_cpf();
void cadastrado();
void criar_conta();
void conta();
void lista_cl();
void cadastrar_filme();
void login_adm();
void lista_filmes();
void erro_arquivo();
void mensagem();
void info_adm();
void info_filme();
void info_cl();
void opcao_inv();
void ranking();
void devol();
void alugados();
void alugar();
void exclui_filme();
void pesquisar_filme();
void lista_filmes();
void exclui_cl();
void pesquisar_cl();

void textbackground (int COLOR){ /*Altera o plano de fundo em determinado local*/
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (COLOR << 4));
}

void textcolor (int COLOR){ /*Altera a cor da fonte*/
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hl,&bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes|=COLOR);
}

void gotoxy (int x, int y){ /*Posiciona o texto em coordenadas X e Y*/
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hora(){ /*Função para informar o horário que está no computador*/
    printf("HORA: ");
    system("time/t");
}

void data(){ /*Função para informar a data que está no computador*/
    printf("DATA: ");
    system("date/t");
}

void bordag(){ /*Função para desenhar borda ao redor da tela*/
    int cont;

    for(cont=-111; cont<0; cont++){
        gotoxy(113+cont,1);
        printf("%c", 220);
        gotoxy(113+cont,31);
        printf("%c", 223);
    }

    for(cont=0;cont<29; cont++){
        gotoxy(2,2+cont);
        printf("%c", 219);
        gotoxy(112,1+cont+1);
        printf("%c", 219);
    }
}

void opcao_inv(){ /*Função para caso a opção for inválida*/
    system("cls");

    textcolor(VERMELHOCLARO);
    bordag();
    gotoxy(52,6);
    printf("___   ___ ");
    gotoxy(52,7);
    printf("\\  \\ /  / ");
    gotoxy(52,8);
    printf(" \\  V  /  ");
    gotoxy(52,9);
    printf("  >   <   ");
    gotoxy(52,10);
    printf(" /  .  \\  ");
    gotoxy(52,11);
    printf("/__/ \\__\\ ");
    gotoxy(42,17);
    printf("Op%c%co inv%clida! Tente novamente.", 135, 198, 160);

    textcolor(BRANCOBR);
    gotoxy(38,20);
    printf("                                             ");

    gotoxy(38,20);
    getchar();
}

void erro_arquivo(){ /*Função para mensagem de erro no arquivo*/
    system("cls");

    printf("Erro na abertura do arquivo!\n");
    printf("Verifique se voc%c j%c efetuou algum cadastro.\n", 136, 160);

    system("pause");
}

void cadastrado(){ /*Função que imprime na tela a mensagem "CADASTRADO" piscando colorido*/
    int cont;

    system("cls");

    for(cont=0;cont<30;cont++){
        textcolor(VERDEAGUACLARO);
        gotoxy(43+cont,11);
        printf("%c", 223);
        gotoxy(41+cont+2,16);
        printf("%c", 223);
        gotoxy(73,16);
        printf("%c", 223);
        if(cont<5){
            textcolor(VERDEAGUA);
            gotoxy(43,11+cont);
            printf("%c", 219);
            gotoxy(73,11+cont);
            printf("%c", 219);
            gotoxy(48,13);
            printf("%cC A D A S T R A D O%c", 175, 174);
        }
    }

    for(cont=0;cont<5;cont++){
        textcolor(ROXO);
        bordag();
        gotoxy(48,13);
        printf("%cC A D A S T R A D O%c", 175, 174);

        textcolor(VERMELHOCLARO);
        bordag();
        gotoxy(48,13);
        printf("%cC A D A S T R A D O%c", 175, 174);

        textcolor(VERDEAGUACLARO);
        bordag();
        gotoxy(48,13);
        printf("%cC A D A S T R A D O%c", 175, 174);

        textcolor(LILAS);
        bordag();
        gotoxy(48,13);
        printf("%cC A D A S T R A D O%c", 175, 174);

        textcolor(VERDECLARO);
        bordag();
        gotoxy(48,13);
        printf("%cC A D A S T R A D O%c", 175, 174);

        textcolor(AZULCLARO);
        bordag();
        gotoxy(48,13);
        printf("%cC A D A S T R A D O%c", 175, 174);
    }

    system("cls");
}

int valida_cpf(char CPF[12]){ /*Função para validar o CPF*/
    int i, SOMA=0;
    int ICPF[12];
    int DIGIT1=0;
    int DIGIT2=0;
    int RESTO=0;

    for(i=0; i<11; i++){
        ICPF[i]=CPF[i]-48; //Converte o CPF de char para int
    }

    for(i=0; i<9; i++){
        SOMA=SOMA+(ICPF[i]*(10-i)); //Os números convertidos para inteiro são somados e multiplicados
    }

    RESTO=SOMA%11; //Obtenção do resto

    if(RESTO<2){
        DIGIT1=0; //Gera o 1 digito verificador
    }
    else{
        DIGIT1=11-RESTO; //Gera o 1 digito verificador
    }

//DÍGITO2
    RESTO=0;
    SOMA=0;

    for(i=0; i<10; i++){
        if(i==9){
            SOMA=SOMA+DIGIT1*2; //É utilizado no nono dígito
        }else
            SOMA=SOMA+(ICPF[i]*(11-i)); //Soma e multiplicação dos 10 primeiros termos

    }

    RESTO=SOMA%11;

    if(RESTO<2){
        DIGIT2=0; //Gera o último dígito verificador
    }
    else{
        DIGIT2=11-RESTO; //Gera o último dígito verificador
    }

    if(DIGIT1==ICPF[9]&&DIGIT2==ICPF[10]){
        return 0; //Retorna 0 caso o CPF seja válido
    }
    else
        return 1; //Retorna 1 caso o CPF seja inválido
}

typedef struct conta_adm{
    char nome[50];
    char user[30];
    char senha[30];
}administrador;

typedef struct conta_cliente{
    char nome[50];
    char cpf[12];
    char nasc[12];
    char tel[12];
    char email[50];
    char rua[30];
    char bairro[30];
    char num[6];
}cliente;

typedef struct dat_filme{
    char nome[50];
    char genero[30];
    char direcao[50];
    char data[12];
    float preco;
    char situ[12];
    char dtali[12];
    char dtalv[12];
    char clal[50];
    int rank;
}filme;

void bubbleSort(filme array[], int n){
    int i, j;

    for(i=0; i<n; i++){
        int flag = 0;
        for(j=0; j<n-i-1; j++){
            if(array[j].rank<array[j+1].rank){
                flag = 1;
                filme temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }

        if(!flag){
            return;
        }
    }
}

void ranking(){ /*Função que exibe o ranking dos filmes alugados*/
    filme* ranke;
    filme rec;
    int c=0, i;

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "rb+"); //Abre arquivo para ler os dados dos filmes cadastrados

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        menu_inicial();
    }

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){
        c=c+1;
    }

    ranke=(struct dat_filme*)calloc(c,sizeof(struct dat_filme));
    rewind(dados_filme);
    int p=0;

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){
        ranke[p]=rec;
        p=p+1;
    }

    bubbleSort(ranke,p);

    for (i=0;i<c;i++){
        printf("%d %s\n",i+1,ranke[i].nome);
    }

    getch();
    menu_inicial();
}

void devol(){ /*Função para devolução de filmes*/
    filme rec;
    filme devo;

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "rb+"); //Abre arquivo para ler os dados dos filmes cadastrados

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        alugados();
    }

    printf("Insira o nome do filme para devolu%c%co: ", 135, 198);
    gets(devo.nome);
    fflush(stdin);
    rewind(dados_filme);

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){ //Lendo os dados do cadastro dos filmes do arquivo binário
        if(strcmp(devo.nome, rec.nome)==0){
            devo=rec;
            char nulo[12] = {"\0"};
            strcpy(devo.clal,nulo);

            char nulo1[12] = {"\0"};
            strcpy(devo.dtali,nulo1);

            char nulo2[12] = {"\0"};
            strcpy(devo.dtalv,nulo2);

            char inicial[12]={"Disponivel"};
            strcpy(devo.situ, inicial);

            fseek(dados_filme,-sizeof(filme),SEEK_CUR);
            fwrite(&devo,sizeof(filme), 1, dados_filme);
            fclose(dados_filme);
            printf("Filme devolvido\n");

            getch();
            alug_filmes();
        }
    }

    printf("Filme n%co cadastrado!\n", 198);
    printf("Pressione qualquer tecla para retornar a lista de filmes alugados.\n");

    getch();
    system("cls");
    alugados();
}

void alugados(){
    filme rec;
    int opcao;
    char aluguel[12]={"Alugado\0"};

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "rb+"); //Abre arquivo para ler os dados dos filmes cadastrados

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        alug_filmes();
    }

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){ //Lendo os dados do cadastro dos filmes do arquivo binário
        if(strcmp(aluguel, rec.situ)==0){
            printf("--------------------------------\n");
            printf("Nome: %s\n", rec.nome);
            printf("G%cnero: %s\n", 136, rec.genero);
            printf("Dire%c%co: %s\n", 135, 198, rec.direcao);
            printf("Lan%camento: %s\n", 135, rec.data);
            printf("Pre%co: %.2f\n", 135, rec.preco);
            printf("Situa%c%co: %s\n", 135, 198, rec.situ);
            printf("Cliente: %s\n", rec.clal);
            printf("Alugado: %s\n", rec.dtali);
            printf("Retorno: %s\n", rec.dtalv);
            printf("--------------------------------\n");
        }
    }

    fclose(dados_filme);
    printf("1- Devolu%c%co de filmes\n", 135, 198);
    printf("0- Voltar\n");
    printf("Op%c%co desejada: ",135,198);
    scanf("%d", &opcao);
    fflush(stdin);

    switch(opcao){
        case 1:
            devol();
            break;
        case 0:
            alug_filmes();
            break;
        default:
            opcao_inv();
            system("cls");
            alugados();
    }
}

void alugar(){
    filme rec;
    filme alug;

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "rb+"); //Abre arquivo para ler os dados dos filmes cadastrados

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        alug_filmes();
    }

    char inicial[12]={"Disponivel"};

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){ //Lendo os dados do cadastro dos filmes do arquivo binário
        if(strcmp(inicial, rec.situ)==0){
            printf("--------------------------------\n");
            printf("Nome: %s\n", rec.nome);
            printf("G%cnero: %s\n", 136, rec.genero);
            printf("Dire%c%co: %s\n", 135, 198, rec.direcao);
            printf("Lan%camento: %s\n", 135, rec.data);
            printf("Pre%co: %.2f\n", 135, rec.preco);
            printf("--------------------------------\n");
        }
    }

    printf("Digite o nome do filme para alugar: ");
    gets(alug.nome); //Recebe o nome que o usuário digitou para alugar um filme
    fflush(stdin);
    rewind(dados_filme); //Reposiciona o ponteiro pro início do arquivo

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){ //Lendo os dados do cadastro dos filmes do arquivo binário
        if(strcmp(alug.nome, rec.nome)==0){
            alug=rec;
            printf("Digite a data de retorno: ");
            gets(alug.dtalv);
            fflush(stdin);
            printf("Digite o nome do cliente para alugar: ");
            gets(alug.clal);
            fflush(stdin);

            char aluguel[12]={"Alugado"};
            strcpy(alug.situ, aluguel);

            char data[12]=__DATE__;
            strcpy(alug.dtali, data);

            alug.rank=rec.rank+1;
            fseek(dados_filme,-sizeof(filme),SEEK_CUR);
            fwrite(&alug,sizeof(filme), 1, dados_filme);
            fclose(dados_filme);

            printf("\n\nFilme alugado com sucesso!");
            getch();
            alug_filmes();
        }
    }

    fclose(dados_filme);
    printf("Filme n%co cadastrado!\n", 198);
    printf("Pressione qualquer tecla para retornar a lista de filmes.");

    getch();
    alug_filmes();
}

void exclui_filme(){ /*Função para excluir um filme*/
    filme rec;
    filme excluir;

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "rb+"); //Abre arquivo para ler os dados dos administradores cadastrados

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        lista_filmes();
    }

    FILE *aux_filme;
    aux_filme=fopen("movies_aux.bin", "wb+"); //Abre arquivo para ler os dados dos filmes cadastrados

    if(aux_filme==NULL){
        fclose(aux_filme);
        erro_arquivo();
        menu_inicial();
    }

    textcolor(VERDEAGUA);
    bordag();

    textcolor(BRANCOBR);
    gotoxy(25,7);
    printf("Insira o nome do filme para excluir: ");
    gets(excluir.nome);
    fflush(stdin);

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){
        if(strcmp(excluir.nome, rec.nome)!=0){
            fwrite(&rec,sizeof(filme), 1, aux_filme);
        }
    }

    fclose(dados_filme);
    fclose(aux_filme);
    remove("movies.bin");
    system("ren movies_aux.bin movies.bin");
    gotoxy(30,15);
    printf("Pressione qualquer tecla para retornar a lista de filmes.\n");

    getch();
    lista_filmes();
}

void pesquisar_filme(){ /*Função para pesquisar um filme*/
    filme rec;
    filme procurado;

    system("cls");

    textcolor(VERDEAGUA);
    bordag();

    textcolor(BRANCOBR);
    gotoxy(27,9);
    printf("Digite o nome do filme para procurar informa%c%ces do cadastro: ", 135, 228);
    gets(procurado.nome); //Recebe o nome que o usuário digitou para pesquisar um filme
    fflush(stdin);

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "rb"); //Abre arquivo para ler os dados dos filmes cadastrados

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        lista_filmes();
    }

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){ //Lendo os dados do cadastro dos filmes do arquivo binário
        if(strcmp(procurado.nome, rec.nome)==0){
            gotoxy(27,11);
            printf("--------------------------------");
            gotoxy(29,12);
            printf("Nome: %s", rec.nome);
            gotoxy(29,13);
            printf("G%cnero: %s", 136, rec.genero);
            gotoxy(29,14);
            printf("Dire%c%co: %s", 135, 198, rec.direcao);
            gotoxy(29,15);
            printf("Lan%camento: %s", 135, rec.data);
            gotoxy(29,16);
            printf("Pre%co: %.2f", 135, rec.preco);
            gotoxy(29,17);
            printf("Situa%c%co: %s", 135, 198, rec.situ);
            gotoxy(27,18);
            printf("--------------------------------");
            fclose(dados_filme);
            gotoxy(35,21);
            printf("Pressione qualquer tecla para retornar a lista de filmes.");
            getch();
            lista_filmes();
        }
    }

    gotoxy(45,15);
    printf("Filme n%co cadastrado!\n", 198);
    fclose(dados_filme);

    gotoxy(25,20);
    printf("Pressione qualquer tecla para retornar a lista de filmes.");

    getch();
    lista_filmes();
}

void info_filme(){ /*Função para alterar informações de um filme*/
    filme rec;
    filme procurado;
    int cont;

    textcolor(VERDEAGUA);
    bordag();

    textcolor(BRANCOBR);
    gotoxy(27,9);
    printf("Digite o nome do filme para alterar informa%c%ces do cadastro: ", 135, 228);
    gets(procurado.nome); //Recebe o nome que o usuário digitou para alterar informações do cadastro do filme
    fflush(stdin);

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "rb+"); //Abre arquivo para ler os dados dos filmes cadastrados

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        lista_filmes();
    }

    while(fread(&rec, sizeof(filme), 1, dados_filme)==1){ //Lendo os dados do cadastro dos filmes do arquivo binário
        if(strcmp(procurado.nome, rec.nome)==0){
          gotoxy(25,11);
          printf("--------------------------------");
          gotoxy(27,12);
          printf("Nome: %s", rec.nome);
          gotoxy(27,13);
          printf("G%cnero: %s", 136, rec.genero);
          gotoxy(27,14);
          printf("Dire%c%co: %s", 135, 198, rec.direcao);
          gotoxy(27,15);
          printf("Lan%camento: %s", 135, rec.data);
          gotoxy(27,16);
          printf("Pre%co: %.2f", 135, rec.preco);
          gotoxy(27,17);
          printf("Situa%c%co: %s", 135, 198, rec.situ);
          gotoxy(25,18);
          printf("--------------------------------");

          gotoxy(35,20);
          system("pause");
          system("cls");

          textcolor(BRANCO);
          gotoxy(5,2);  data();
          gotoxy(95,2);  hora();

          textcolor(BRANCOBR);
          gotoxy(48,3);  printf(".:A L T E R A R:.");

          textcolor(BRANCO);
          bordag();

          for(cont=0;cont<3;cont++){
              gotoxy(25,2+cont);    printf("%c", 219);
              gotoxy(87,2+cont);    printf("%c", 219);
          }

          for(cont=0;cont<83;cont++){
              if(cont<25){
                  gotoxy(15,4+cont);  printf("%c", 219);
                  gotoxy(97,4+cont);  printf("%c", 219);
              }
              if(cont<81){
                gotoxy(16+cont,4);  printf("%c", 223);
              }
              gotoxy(15+cont,29);  printf("%c", 223);
          }

          textcolor(BRANCOBR);
          gotoxy(18,7);
          printf("Preencha os campos a seguir fazendo as altera%c%ces desejadas.", 135, 228);
          gotoxy(18,9);
          printf("Nome: ");
          gets(rec.nome);
          fflush(stdin);
          gotoxy(18,11);
          printf("G%cnero: ", 136);
          gets(rec.genero);
          fflush(stdin);
          gotoxy(18,13);
          printf("Dire%c%co: ", 135, 198);
          gets(rec.direcao);
          fflush(stdin);
          gotoxy(18,15);
          printf("Lan%camento: ", 135);
          gets(rec.data);
          fflush(stdin);
          gotoxy(18,17);
          printf("Pre%co: ", 135);
          scanf("%f", &rec.preco);
          fflush(stdin);
          fseek(dados_filme,-sizeof(filme),SEEK_CUR);
          fwrite(&rec,sizeof(filme), 1, dados_filme); //Escrevendo os dados que foram alterados no arquivo
          fclose(dados_filme); //Fecha o arquivo
          gotoxy(30,20);
          printf("Informa%c%ces alteradas com sucesso!", 135, 228);
          getch();
          lista_filmes();
        }
    }

    textcolor(VERMELHOCLARO);
    gotoxy(35,15);
    printf("Filme n%co cadastrado", 228);

    getch();
    lista_filmes();
}

void lista_filmes(){ /*Função para listar todos os filmes os filmes cadastrados*/
    filme rec;
    int opcao;

    system("cls");

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "rb+"); //Abre arquivo para ler os dados dos dados_filme cadastrados

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        alug_filmes();
    }

    textcolor(BRANCOBR);
    while((fread(&rec, sizeof(filme), 1, dados_filme)==1)){ //Lendo os dados do cadastro do filme do arquivo binário
        printf("Nome: %s\n", rec.nome);
        printf("G%cnero: %s\n", 136, rec.genero);
        printf("Dire%c%co: %s\n", 135, 198, rec.direcao);
        printf("Lan%camento: %s\n", 135, rec.data);
        printf("Situa%c%co: %s\n", 135, 198, rec.situ);
        printf("Alugado: %d\n", rec.rank);
        printf("--------------------------------\n");
    }

    fclose(dados_filme); //Fecha o arquivo
    textcolor(VERDEAGUACLARO);
    printf("1- Alterar informa%c%ces do filme\n",135,228);
    printf("2- Pesquisar filme\n");
    printf("3- Excluir filme\n");
    printf("0- Voltar\n");
    printf("Op%c%co desejada: ",135,198);
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");

    switch(opcao){
        case 1:
            info_filme();
            break;
        case 2:
            pesquisar_filme();
            break;
        case 3:
            exclui_filme();
            break;
        case 0:
            alug_filmes();
            break;
        default :
            opcao_inv();
            lista_filmes();
    }
}

void cadastrar_filme(){ /*Função para cadastrar os filmes*/
    filme rec;
    int cont;

    FILE *dados_filme;
    dados_filme=fopen("movies.bin", "ab"); //Abre arquivo para cadastrar filme

    if(dados_filme==NULL){
        fclose(dados_filme);
        erro_arquivo();
        alug_filmes();
    }

    textcolor(BRANCO);
    gotoxy(5,2);  data();
    gotoxy(95,2);  hora();

    textcolor(BRANCOBR);
    gotoxy(48,3);  printf(".:C A D A S T R O:.");

    textcolor(ROXO);
    bordag();

    for(cont=0;cont<3;cont++){
        gotoxy(25,2+cont);    printf("%c", 219);
        gotoxy(87,2+cont);    printf("%c", 219);
    }

    for(cont=0;cont<83;cont++){
        if(cont<25){
            gotoxy(15,4+cont);  printf("%c", 219);
            gotoxy(97,4+cont);  printf("%c", 219);
        }
        if(cont<81){
            gotoxy(16+cont,4);  printf("%c", 223);
        }
        gotoxy(15+cont,29);  printf("%c", 223);
    }
    gotoxy(18,7);
    printf("Nome: ");
    gets(rec.nome);
    fflush(stdin);
    gotoxy(18,9);
    printf("G%cnero: ", 136);
    gets(rec.genero);
    fflush(stdin);
    gotoxy(18,11);
    printf("Dire%c%co: ", 135, 198);
    gets(rec.direcao);
    fflush(stdin);
    gotoxy(18,13);
    printf("Lan%camento: ", 135);
    gets(rec.data);
    fflush(stdin);
    gotoxy(18,15);
    printf("Pre%co: ", 135);
    scanf("%f", &rec.preco);
    fflush(stdin);
    char inicial[12]={"Disponivel"};
    strcpy(rec.situ, inicial); //Copia a string-origem para a string-destino
    char dt[12]={'\0'};
    strcpy(rec.dtali, dt); //Copia a string-origem para a string-destino
    char dv[12]={'\0'};
    strcpy(rec.dtalv, dv); //Copia a string-origem para a string-destino
    char cl[50]={'\0'};
    strcpy(rec.clal, cl); //Copia a string-origem para a string-destino
    rec.rank=0;
    fwrite(&rec, sizeof(filme), 1, dados_filme); //Escrevendo os dados do cadastro do filme no arquivo binário

    fclose(dados_filme); //Fecha o arquivo
}

void alug_filmes(){ /*Menu de aluguel de filmes*/
    int opcao, cont, cont1;

    system("cls");

    textcolor(VERDEAGUA);
    bordag();

    for(cont1=0; cont1<29; cont1++){
        for(cont=0; cont<35; cont++){
            gotoxy(78+cont,2+cont1);printf("%c", 219);
        }
    }

    textcolor(BRANCOBR);
    gotoxy(20,4);
    printf(" _____  ____  _      ___ ___    ___  _____");
    gotoxy(20,5);
    printf("|     ||    || |    |   |   |  /  _]/ ___/");
    gotoxy(20,6);
    printf("|   __| |  | | |    | _   _ | /  [_(   \\_ ");
    gotoxy(20,7);
    printf("|  |_   |  | | |___ |  \\_/  ||    _]\\__  |");
    gotoxy(20,8);
    printf("|   _]  |  | |     ||   |   ||   [_ /  \\ |");
    gotoxy(20,9);
    printf("|  |    |  | |     ||   |   ||     |\\    |");
    gotoxy(20,10);
    printf("|__|   |____||_____||___|___||_____| \\___|");
    gotoxy(16,14);
    printf("-NdssssssssssssssssssssssssssssssssssssssssdN-");
    gotoxy(16,15);
    printf("+M:                                        :M+");
    gotoxy(16,16);
    printf("+M:                                        :M+");
    gotoxy(16,17);
    printf("+M:                                        :M+");
    gotoxy(16,18);
    printf("+M:         ``````````````````````         :M+");
    gotoxy(16,19);
    printf("+M:      /dNdmMMmddddddddddddmMMmdmd/      :M+");
    gotoxy(16,20);
    printf("+M:     +M+   -Nd            dN-   +M+     :M+");
    gotoxy(16,21);
    printf("+M:     oM:   `mm            mm`   :Mo     :M+");
    gotoxy(16,22);
    printf("+M:      oNdyhNMhyyyyyyyyyyyydMNhydNo      :M+");
    gotoxy(16,23);
    printf("+M:        .----------------------.        :M+");
    gotoxy(16,24);
    printf("+M:       ``````````````````````````       :M+");
    gotoxy(16,25);
    printf("+M:     `mNddddddddddddddddddddddddNm`     :M+");
    gotoxy(16,26);
    printf("+M:     hM-                        -Mh     :M+");
    gotoxy(16,27);
    printf("+M:    +M/                          +M+    :M+");
    gotoxy(16,28);
    printf("-NdsssyMNssssssssssssssssssssssssssssNMssssdN-");

    textbackground(VERDEAGUA);
    textcolor(BRANCOBR);
    gotoxy(89,11);printf("|O P %c %c E S|", 128, 229);
    gotoxy(80,16);printf("   1- Alugar filme            ");
    gotoxy(80,18);printf("   2- Lista de filmes         ");
    gotoxy(80,20);printf("   3- Lista de filmes alugados");
    gotoxy(80,22);printf("   4- Cadastrar filme         ");
    gotoxy(80,24);printf("   0- Voltar");

    textcolor(BRANCOBR);
    gotoxy(93,28);  printf("%c(   )%c", 175, 174);
    gotoxy(96,28);  scanf("%d", &opcao);
    fflush(stdin);
    textbackground(PRETO);
    system("cls");

    switch(opcao){
        case 1:
            alugar();
            break;
        case 2:
            lista_filmes();
            break;
        case 3:
            alugados();
            break;
        case 4:
            cadastrar_filme();
            cadastrado();
            alug_filmes();
            break;
        case 0:
            menu_adm();
            break;
        default :
            opcao_inv();
            alug_filmes();
    }
}

void exclui_cl(){ /*Função para excluir o cadastro de um cliente*/
    cliente c;
    cliente excluir;

    FILE *dados_client;
    dados_client=fopen("client.bin", "rb+"); //Abre arquivo para ler os dados dos clientes cadastrados

    if(dados_client==NULL){
        fclose(dados_client);
        erro_arquivo();
        lista_cl();
    }

    FILE *aux_client;
    aux_client=fopen("client_aux.bin", "wb+"); //Abre arquivo auxiliar

    if(aux_client==NULL){
        fclose(aux_client);
        erro_arquivo();
        lista_cl();
    }

    textcolor(BRANCO);
    bordag();

    textcolor(VERDEAGUACLARO);
    gotoxy(30,7);
    printf("Insira o CPF do cliente para excluir: ");
    gets(excluir.cpf);
    fflush(stdin);

    while(fread(&c, sizeof(cliente), 1, dados_client)==1){
        if(strcmp(excluir.cpf, c.cpf)!=0){
            fwrite(&c,sizeof(cliente), 1, aux_client);
        }
    }

    fclose(dados_client);
    fclose(aux_client);
    remove("client.bin");
    system("ren client_aux.bin client.bin");
    gotoxy(25,15);
    printf("Pressione qualquer tecla para retornar a lista de clientes.\n");

    getch();
    lista_cl();
}

void pesquisar_cl(){ /*Função para pesquisar os clientes*/
    cliente c;
    cliente procurado;

    system("cls");

    textcolor(BRANCO);
    bordag();

    textcolor(VERDEAGUACLARO);
    gotoxy(25,7);
    printf("Digite o nome para procurar informa%c%ces do cadastro: ", 135, 228);
    gets(procurado.nome); //Recebe o nome que o usuário digitou para pesquisar cliente
    fflush(stdin);

    FILE *dados_client;
    dados_client=fopen("client.bin", "rb"); //Abre arquivo para ler os dados dos clientes cadastrados

    if(dados_client==NULL){
        fclose(dados_client);
        erro_arquivo();
        lista_cl();
    }

    while(fread(&c, sizeof(cliente), 1, dados_client)==1){ //Lendo os dados do cadastro dos clientes do arquivo binário
        if(strcmp(procurado.nome, c.nome)==0){ //Verifica se o nome digitado foi cadastrado
            gotoxy(25,10);
            printf("--------------------------------");
            gotoxy(27,11);
            printf("Nome: %s", c.nome);
            gotoxy(27,12);
            printf("CPF: %s", c.cpf);
            gotoxy(27,13);
            printf("Data de nascimento: %s", c.nasc);
            gotoxy(27,14);
            printf("Telefone: %s", c.tel);
            gotoxy(27,15);
            printf("Email: %s", c.email);
            gotoxy(27,16);
            printf("Rua: %s", c.rua);
            gotoxy(27,17);
            printf("Bairro: %s", c.bairro);
            gotoxy(27,18);
            printf("N%cmero da casa: %s", 163, c.num);
            gotoxy(25,19);
            printf("--------------------------------");
            fclose(dados_client);
            gotoxy(35,21);
            printf("Pressione qualquer tecla para retornar a lista de clientes.");
            getch();
            lista_cl();
        }
    }

    gotoxy(40,14);
    printf("Cliente n%co cadastrado!", 198);
    fclose(dados_client);
    gotoxy(25,20);
    printf("Pressione qualquer tecla para retornar a lista de clientes.");

    getch();
    lista_cl();
}

void info_cl(){  /*Função para alterar as informações do cliente*/
    cliente c;
    cliente procurado;

    system("cls");

    textcolor(BRANCO);
    bordag();

    textcolor(VERDEAGUACLARO);
    gotoxy(25,7);
    printf("Digite o nome para alterar informa%c%ces do cadastro: ", 135, 228);
    gets(procurado.nome); //Recebe o nome que o usuário digitou para alterar informações do cadastro do cliente
    fflush(stdin);

    FILE *dados_client;
    dados_client=fopen("client.bin", "rb+"); //Abre arquivo para ler os dados dos clientes cadastrados

    if(dados_client==NULL){
        fclose(dados_client);
        erro_arquivo();
        lista_cl();
    }

    while(fread(&c, sizeof(cliente), 1, dados_client)==1){ //Lendo os dados do cadastro dos clientes do arquivo binário
        int cont;

        if(strcmp(procurado.nome, c.nome)==0){ //Verifica se o nome digitado foi cadastrado
            gotoxy(25,10);
            printf("--------------------------------");
            gotoxy(27,11);
            printf("Nome: %s", c.nome);
            gotoxy(27,12);
            printf("CPF: %s\n", c.cpf);
            gotoxy(27,13);
            printf("Data de nascimento(DD/MM/AAAA): %s", c.nasc);
            gotoxy(27,14);
            printf("Telefone: %s", c.tel);
            gotoxy(27,15);
            printf("Email: %s", c.email);
            gotoxy(27,16);
            printf("Rua: %s", c.rua);
            gotoxy(27,17);
            printf("Bairro: %s", c.bairro);
            gotoxy(27,18);
            printf("N%cmero da casa: %s", 163, c.num);
            gotoxy(25,19);
            printf("--------------------------------");

            gotoxy(30,22);
            system("pause");
            system("cls");

            textcolor(BRANCO);
            gotoxy(5,2);  data();
            gotoxy(95,2);  hora();

            textcolor(BRANCOBR);
            gotoxy(50,3);  printf(".:A L T E R A R:.");

            textcolor(VERDEAGUA);
            bordag();

            for(cont=0;cont<3;cont++){
                gotoxy(25,2+cont);    printf("%c", 219);
                gotoxy(87,2+cont);    printf("%c", 219);
            }

            for(cont=0;cont<83;cont++){
                if(cont<25){
                    gotoxy(15,4+cont);  printf("%c", 219);
                    gotoxy(97,4+cont);  printf("%c", 219);
                }
                if(cont<81){
                    gotoxy(16+cont,4);  printf("%c", 223);
                }
                gotoxy(15+cont,29);  printf("%c", 223);
            }

            textcolor(VERDEAGUACLARO);
            gotoxy(18,7);
            printf("Preencha os campos a seguir fazendo as altera%c%ces desejadas.", 135, 228);
            gotoxy(18,9);
            printf("Nome: ");
            gets(c.nome);
            fflush(stdin);
            volta:
            textcolor(VERDEAGUACLARO);
            gotoxy(18,11);
            printf("CPF: ");
            gets(c.cpf);
            fflush(stdin);

            int resposta=valida_cpf(c.cpf); //Recebe a informação se o CPF é válido ou inválido

            if(resposta==0){
                textcolor(VERDECLARO);
                gotoxy(20,12);
                printf("<<CPF v%clido>>  ", 160); //Mensagem caso o CPF seja válido
            }

            if(resposta==1){
                textcolor(VERMELHOCLARO);
                gotoxy(23,11);
                printf("                 ");
                gotoxy(20,12);
                printf("<<CPF inv%clido>>", 160);
                goto volta;
            }else{
                textcolor(VERDEAGUACLARO);
                gotoxy(18,14);
                printf("Data de nascimento(DD/MM/AAAA): ");
                gets(c.nasc);
                fflush(stdin);
                gotoxy(18,16);
                printf("Telefone: ");
                gets(c.tel);
                fflush(stdin);
                gotoxy(18,18);
                printf("Email: ");
                gets(c.email);
                fflush(stdin);
                gotoxy(18,20);
                printf("Rua: ");
                gets(c.rua);
                fflush(stdin);
                gotoxy(18,22);
                printf("Bairro: ");
                gets(c.bairro);
                fflush(stdin);
                gotoxy(18,24);
                printf("N%cmero da casa: ", 163);
                gets(c.num);
                fflush(stdin);
                fseek(dados_client,-sizeof(cliente),SEEK_CUR); //Posiciona em um registro de arquivo
                fwrite(&c,sizeof(cliente), 1, dados_client); //Escrevendo os dados que foram alterados no arquivo
                fclose(dados_client); //Fecha o arquivo
                gotoxy(28,26);
                printf("Informa%c%ces alteradas com sucesso!", 135, 228);
                getch();
                lista_cl();
            }
        }
    }

    gotoxy(40,15);
    printf("Cliente n%co cadastrado!", 198);

    getchar();
    lista_cl();
}

void lista_cl(){/*Função que exibe a lista completa de todos os clientes cadastrados*/
    cliente c;
    int opcao;

    FILE *dados_client;
    dados_client=fopen("client.bin", "rb"); //Abre arquivo para ler os dados dos clientes cadastrados

    if(dados_client==NULL){
        fclose(dados_client);
        erro_arquivo();
        menu_adm();
    }

    system("cls");
    textcolor(VERDEAGUACLARO);
    while(fread(&c, sizeof(cliente), 1, dados_client)==1){
        printf("Nome: %s\n", c.nome);
        printf("CPF: %s\n", c.cpf);
        printf("Data de nascimento(DD/MM/AAAA): %s \n", c.nasc);
        printf("Telefone: %s\n", c.tel);
        printf("Email: %s\n", c.email);
        printf("Rua: %s\n", c.rua);
        printf("Bairro: %s\n", c.bairro);
        printf("N%cmero da casa: %s\n", 163, c.num);
        printf("--------------------------------\n");
    }

    fclose(dados_client); //Fecha o arquivo

    textcolor(BRANCOBR);
    printf("1- Alterar informa%c%ces do cliente\n",135,228);
    printf("2- Pesquisar cliente\n");
    printf("3- Excluir cliente\n");
    printf("0- Voltar\n");
    printf("Op%c%co desejada: ",135,198);
    scanf("%d", &opcao);
    fflush(stdin);

    system("cls");

    switch(opcao){
        case 1:
            info_cl();
            break;
        case 2:
            pesquisar_cl();
            break;
        case 3:
            exclui_cl();
            break;
        case 0:
            menu_adm();
            break;
        default :
            opcao_inv();
            lista_cl();
    }
}

void cadastrar_cl(){ /*Cadastra os clientes*/
    int resposta=0, cont;
    cliente c;

    FILE *cadaclient;
    cadaclient=fopen("client.bin", "ab"); //Abre arquivo para cadastrar clientes

    if(cadaclient==NULL){
        fclose(cadaclient);
        erro_arquivo();
        menu_adm();
    }

    textcolor(BRANCO);
    gotoxy(5,2);  data();
    gotoxy(95,2);  hora();

    textcolor(BRANCOBR);
    gotoxy(48,3);  printf(".:C A D A S T R O:.");
    gotoxy(38,30);  printf("Venha se juntar a n%cs, se cadastrando!", 162);

    textcolor(ROXO);
    bordag();

    for(cont=0;cont<3;cont++){
        gotoxy(25,2+cont);    printf("%c", 219);
        gotoxy(87,2+cont);    printf("%c", 219);
    }

    for(cont=0;cont<83;cont++){
        if(cont<25){
            gotoxy(15,4+cont);  printf("%c", 219);
            gotoxy(97,4+cont);  printf("%c", 219);
        }
        if(cont<81){
            gotoxy(16+cont,4);  printf("%c", 223);
        }
        gotoxy(15+cont,29);  printf("%c", 223);
    }

    textcolor(LILAS);
    gotoxy(18,7);  printf("Nome: ");
    gets(c.nome);
    fflush(stdin);
    volta:

    textcolor(LILAS);
    gotoxy(18,9);  printf("CPF: ");
    gets(c.cpf);
    fflush(stdin);

    resposta=valida_cpf(c.cpf); //Recebe a informação se o CPF é válido ou inválido

    if(resposta==1){
        gotoxy(20,10);  textcolor(VERMELHOCLARO);  printf("<<CPF inv%clido>>", 160); //Mensagem caso o CPF seja inválido
        gotoxy(23,9);  printf("             ");
        goto volta;
    }else{
        textcolor(VERDECLARO);
        gotoxy(20,10);  printf("<<CPF v%clido>>  ", 160); //Mensagem caso o CPF seja válido
    }

    textcolor(LILAS);
    gotoxy(18,12);  printf("Data de nascimento(DD/MM/AAAA): ");
    gets(c.nasc);
    fflush(stdin);
    gotoxy(18,14);  printf("Telefone: ");
    gets(c.tel);
    fflush(stdin);
    gotoxy(18,16);  printf("Email: ");
    gets(c.email);
    fflush(stdin);
    gotoxy(18,18);  printf("Rua: ");
    gets(c.rua);
    fflush(stdin);
    gotoxy(18,20);  printf("Bairro: ");
    gets(c.bairro);
    fflush(stdin);
    gotoxy(18,22);  printf("N%cmero da casa: ", 163);
    gets(c.num);
    fflush(stdin);
    fwrite(&c, sizeof(cliente), 1, cadaclient); //Escrevendo os dados do cadastro do cliente no arquivo binário

    fclose(cadaclient); //Fecha o arquivo

    system("cls");
    cadastrado();
    menu_adm();
}

void menu_adm(){ /*Menu do administrador*/
    int opcao, cont;

    system("cls");

    textcolor(BRANCOBR);
    gotoxy(6,4);
    printf("A");
    gotoxy(6,6);
    printf("D");
    gotoxy(6,8);
    printf("M");
    gotoxy(6,10);
    printf("I");
    gotoxy(6,12);
    printf("N");
    gotoxy(6,14);
    printf("I");
    gotoxy(6,16);
    printf("S");
    gotoxy(6,18);
    printf("T");
    gotoxy(6,20);
    printf("R");
    gotoxy(6,22);
    printf("A");
    gotoxy(6,24);
    printf("D");
    gotoxy(6,26);
    printf("O");
    gotoxy(6,28);
    printf("R");

    textcolor(BRANCO);
    gotoxy(95,3);  data();
    gotoxy(97,4);  hora();

    textcolor(VERDEAGUA);
    bordag();

    for(cont=0; cont<102; cont++){
        textcolor(VERDEAGUA);
        gotoxy(10+cont,20);    printf("%c", 220);
        gotoxy(10+cont,23);    printf("%c", 220);
        gotoxy(10+cont,26);    printf("%c", 220);
        gotoxy(10+cont,29);    printf("%c", 220);
        textcolor(VERDEAGUA);
        gotoxy(10+cont,30);    printf("%c", 219);
        if(cont==97){
            textcolor(VERDEAGUA);
            gotoxy(97,30);      printf("%c", 219);
            gotoxy(107,30);      printf("%c", 219);
        }
        if(cont<29){
        gotoxy(10,2+cont);      printf("%c", 219);
        }
    }

    textcolor(BRANCOBR);
    gotoxy(58,6);
    printf("     /\\     \n");
    gotoxy(58,7);
    printf("    //\\\\   \n");
    gotoxy(58,8);
    printf("    \\ //    \n");
    gotoxy(58,9);
    printf("     \\/       ");
    gotoxy(12,22);

    textcolor(VERDEAGUA);
    printf("1- Cadastrar cliente");
    gotoxy(12,25);
    printf("2- Lista de clientes");
    gotoxy(12,28);
    printf("3- Aluguel de filmes");

    textcolor(BRANCOBR);
    textbackground(VERDEAGUA);
    gotoxy(98,30);  printf("0- Voltar");

    textbackground(PRETO);
    textcolor(BRANCOBR);
    gotoxy(60,13);  printf("%c(   )%c", 175, 174);

    textcolor(VERDEAGUACLARO);
    gotoxy(63,13);  scanf("%d", &opcao);
    fflush(stdin);

    textcolor(VERDEAGUACLARO);
    for(cont=0;cont<150;cont++){
        textcolor(VERDEAGUACLARO);
        gotoxy(58,5);  printf("    . : ..      ");
        gotoxy(58,6);  printf(" . . /\\:.    \n");
        gotoxy(58,7);  printf(". .://\\\\   \n");
        gotoxy(58,8);  printf("   .\\ //..   \n");
        gotoxy(58,9);  printf("  . :\\/..  .   ");
        gotoxy(58,10);  printf(" : .  . .  .   ");

        textcolor(AZULCLARO);
        gotoxy(58,5);  printf("    . : ..      ");
        gotoxy(58,6);  printf(" . . /\\:.    \n");
        gotoxy(58,7);  printf(". .://\\\\   \n");
        gotoxy(58,8);  printf("   .\\ //..   \n");
        gotoxy(58,9);  printf("  . :\\/..  .   ");
        gotoxy(58,10);  printf("   .   .   .   ");

        textcolor(VERDECLARO);
        gotoxy(58,6);  printf("     /\\     \n");
        gotoxy(58,7);  printf("    //\\\\   \n");
        gotoxy(58,8);  printf("    \\ //    \n");
        gotoxy(58,9);  printf("     \\/       ");

        textcolor(VERMELHO);
        gotoxy(58,5);  printf("    . : ..      ");
        gotoxy(58,6);  printf(" . . /\\:.    \n");
        gotoxy(58,7);  printf(". .://\\\\   \n");
        gotoxy(58,8);  printf("   .\\ //..   \n");
        gotoxy(58,9);  printf("  . :\\/..  .   ");
        gotoxy(58,10);  printf(" : .  ..  .   ");

        textcolor(LILAS);
        gotoxy(58,5);  printf("    . : ..      ");
        gotoxy(58,6);  printf(" . . /\\:.    \n");
        gotoxy(58,7);  printf(". .://\\\\   \n");
        gotoxy(58,8);  printf("   .\\ //..   \n");
        gotoxy(58,9);  printf("  . :\\/..  .   ");
        gotoxy(58,10);  printf(" : .  ...:    ");

        textcolor(BRANCOBR);
        gotoxy(58,5);  printf("               ");
        gotoxy(58,6);  printf("     /\\     \n");
        gotoxy(58,7);  printf("    //\\\\   \n");
        gotoxy(58,8);  printf("    \\ //    \n");
        gotoxy(58,9);  printf("     \\/       ");
        gotoxy(58,10);  printf("               ");
    }

    system("cls");
    switch(opcao){
        case 1:
            cadastrar_cl();
            break;
        case 2:
            lista_cl();
            break;
        case 3:
            alug_filmes();
            break;
        case 0:
            for(cont=0;cont<1000;cont++){
                textcolor(VERDEAGUACLARO);
                gotoxy(53,15);          printf("SAINDO.  ");
                gotoxy(53,15);          printf("SAINDO.. ");
                gotoxy(53,15);          printf("SAINDO...");
            }
            menu_inicial();
            break;
        default :
            opcao_inv();
            getch();
            menu_adm();
    }

    system("cls");
}

void info_adm(){ /*Função para alterar informações do cadastro do administrador*/
    administrador adm;
    administrador procurado;
    int cont;

    textcolor(BRANCO);
    bordag();

    textcolor(VERDEAGUACLARO);
    gotoxy(25,7);
    printf("Digite o nome para alterar informa%c%ces do cadastro: ", 135, 228);
    gets(procurado.nome); //Recebe o nome que o usuário digitou para alterar informações do cadastro do administrador
    fflush(stdin);

    FILE *dados_adm;
    dados_adm=fopen("admin.bin", "rb+"); //Abre arquivo para ler os dados dos administradores cadastrados

    if(dados_adm==NULL){
        fclose(dados_adm);
        erro_arquivo();
        menu_inicial();
    }

    while(fread(&adm, sizeof(administrador), 1, dados_adm)==1){ //Lendo os dados do cadastro dos administradores do arquivo binário
        if(strcmp(procurado.nome, adm.nome)==0){ //Verifica se o nome digitado foi cadastrado
            gotoxy(25,9);
            printf("--------------------------------");
            gotoxy(27,10);
            printf("Nome: %s", adm.nome);
            gotoxy(27,11);
            printf("Usu%crio: %s", 160, adm.user);
            gotoxy(27,12);
            printf("Senha: %s", adm.senha);
            gotoxy(25,13);
            printf("--------------------------------");
            gotoxy(35,17);
            system("pause");
            system("cls");

            textcolor(BRANCO);
            gotoxy(5,2);  data();
            gotoxy(95,2);  hora();

            textcolor(BRANCOBR);
            gotoxy(48,3);  printf(".:A L T E R A R:.");

            textcolor(BRANCO);
            bordag();

            for(cont=0;cont<3;cont++){
                gotoxy(25,2+cont);    printf("%c", 219);
                gotoxy(87,2+cont);    printf("%c", 219);
            }

            for(cont=0;cont<83;cont++){
                if(cont<25){
                    gotoxy(15,4+cont);  printf("%c", 219);
                    gotoxy(97,4+cont);  printf("%c", 219);
                }
                if(cont<81){
                    gotoxy(16+cont,4);  printf("%c", 223);
                }
                gotoxy(15+cont,29);  printf("%c", 223);
            }

            textcolor(BRANCOBR);
            gotoxy(18,7);
            printf("Preencha os campos a seguir fazendo as altera%c%ces desejadas.", 135, 228);
            gotoxy(18,9);
            printf("Nome: ");
            gets(adm.nome);
            fflush(stdin);
            gotoxy(18,11);
            printf("Usu%crio: ", 160);
            gets(adm.user);
            fflush(stdin);
            gotoxy(18,13);
            printf("Senha: ");
            gets(adm.senha);
            fflush(stdin);
            fseek(dados_adm,-sizeof(administrador),SEEK_CUR);
            fwrite(&adm,sizeof(adm), 1, dados_adm); //Escrevendo os dados que foram alterados no arquivo
            fclose(dados_adm); //Fecha o arquivo
            gotoxy(25,15);
            printf("Informa%c%ces alteradas com sucesso!", 135, 228);
            getch();
            menu_inicial();
        }
    }

    textcolor(VERMELHOCLARO);
    gotoxy(40,15);
    printf("Administrador n%co cadastrado!", 198);

    getchar();
    menu_inicial();
}

void menu_inicial(){ /*Menu inicial (primeiro menu do sistema) que abriga todas os demais menus*/
    system("cls");

    int opcao, cont;

    textcolor(BRANCO);
    gotoxy(8,5);
    data();
    gotoxy(10,6);
    hora();

    textcolor(BRANCOBR);
    for(cont=0; cont<111; cont++){
        if(cont<29){
            gotoxy(30,2+cont);  printf("%c", 220);
            if(cont<28){
                gotoxy(2+cont,10);  printf("%c", 220);
                if(cont<21){
                    gotoxy(5,11+cont);  printf("%c", 219);
                }
            }
        }
    }

    textcolor(VERDEAGUACLARO);
    gotoxy(4,17);
    printf("[1] OP%c%cES", 128, 229);
    gotoxy(4,19);
    printf("[2] ALTERAR CADASTRO");
    gotoxy(4,21);
    printf("[3] RANKING DOS FILMES");
    gotoxy(4,23);
    printf("[0] SAIR");

    textcolor(BRANCOBR);
    bordag();

    textcolor(BRANCOBR);
    gotoxy(63,26);
    printf("Como %c bom poder assistir", 130);
    gotoxy(67,27);
    printf("E um filme alugar!");

    for(cont=0;cont<150;cont++){
        textcolor(VERDEAGUACLARO);
        gotoxy(69,3);  printf("    . : ..      ");
        gotoxy(69,4);  printf(" . . /\\:.    \n");
        gotoxy(69,5);  printf(". .://\\\\   \n");
        gotoxy(69,6);  printf("   .\\ //..   \n");
        gotoxy(69,7);  printf("  . :\\/..  .   ");
        gotoxy(69,8);  printf(" : .  . .  .   ");
        gotoxy(62,10);  printf("++M||O||N||S||T||R||I||X++");

        textcolor(AZULCLARO);
        gotoxy(69,3);  printf("    . : ..      ");
        gotoxy(69,4);  printf(" . . /\\:.    \n");
        gotoxy(69,5);  printf(". .://\\\\   \n");
        gotoxy(69,6);  printf("   .\\ //..   \n");
        gotoxy(69,7);  printf("  . :\\/..  .   ");
        gotoxy(69,8);  printf("   .   .   .   ");
        gotoxy(62,10);  printf("<<M__O__N__S__T__R__I__X<<");

        textcolor(VERDECLARO);
        gotoxy(69,4);  printf("     /\\     \n");
        gotoxy(69,5);  printf("    //\\\\   \n");
        gotoxy(69,6);  printf("    \\ //    \n");
        gotoxy(69,7);  printf("     \\/       ");
        gotoxy(62,10);  printf(">>M--O--N--S--T--R--I--X>>");

        textcolor(VERMELHO);
        gotoxy(69,3);  printf("    . : ..      ");
        gotoxy(69,4);  printf(" . . /\\:.    \n");
        gotoxy(69,5);  printf(". .://\\\\   \n");
        gotoxy(69,6);  printf("   .\\ //..   \n");
        gotoxy(69,7);  printf("  . :\\/..  .   ");
        gotoxy(69,8);  printf(" : .  ..  .   ");
        gotoxy(62,10);  printf(">>M  O  N  S  T  R  I  X>>");

        textcolor(LILAS);
        gotoxy(69,3);  printf("    . : ..      ");
        gotoxy(69,4);  printf(" . . /\\:.    \n");
        gotoxy(69,5);  printf(". .://\\\\   \n");
        gotoxy(69,6);  printf("   .\\ //..   \n");
        gotoxy(69,7);  printf("  . :\\/..  .   ");
        gotoxy(69,8);  printf(" : .  ...:    ");
        gotoxy(62,10);  printf(">>M__O__N__S__T__R__I__X>>");

        textcolor(BRANCOBR);
        gotoxy(69,3);  printf("               ");
        gotoxy(69,4);  printf("     /\\     \n");
        gotoxy(69,5);  printf("    //\\\\   \n");
        gotoxy(69,6);  printf("    \\ //    \n");
        gotoxy(69,7);  printf("     \\/       ");
        gotoxy(69,8);  printf("               ");
        gotoxy(62,10);  printf("<<M  O  N  S  T  R  I  X>>");
    }

    for(cont=0;cont<81;cont++){
        textcolor(BRANCOBR);
        gotoxy(31+cont,10);  printf("%c", 220);
    }

    gotoxy(72,20);  printf("(   )");

    textcolor(BRANCOBR);
    gotoxy(62,10);
    printf(".:M  O  N  S  T  R  I  X:.");

    textcolor(VERDEAGUA);
    gotoxy(74,20);
    scanf("%d", &opcao);
    fflush(stdin);

    textcolor(VERDECLARO);
    system("cls");
    switch(opcao){
        case 1:
            menu_adm();
            break;
        case 2:
            info_adm();
            break;
        case 3:
            ranking();
            break;
        case 0:
            conta();
            break;
        default:
            opcao_inv();
            menu_inicial();
    }
}

void login_adm(){ /*Login para ter acesso ao sistema da locadora*/
    administrador adm;
    administrador logando;

    FILE *dados_adm;
    dados_adm=fopen("admin.bin", "rb"); //Abre arquivo para ler o cadastro dos administradores

    if(dados_adm==NULL){
        fclose(dados_adm);
        erro_arquivo();
        conta();
    }

    textcolor(LILAS);
    bordag();

    textcolor(BRANCOBR);
    gotoxy(17,5);
    printf(".:L O G I N:.");
    gotoxy(8,16);
    printf(">>Usu%crio: ", 160);
    fflush(stdin);
    gets(logando.user);
    gotoxy(8,18);
    printf(">>Senha: ");
    fflush(stdin);
    gets(logando.senha);

    while(fread(&adm, sizeof(administrador), 1, dados_adm)==1){ //Lê todos os cadastros dos administradores
        if((strcmp(logando.user, adm.user)==0)&&(strcmp(logando.senha, adm.senha)==0)){ //Verifica se o usuário e a senha correspondem a algum cadastro
            fclose(dados_adm);
            menu_inicial();
        }
    }

    if((strcmp(logando.user, adm.user)!=0)||(strcmp(logando.senha, adm.senha)!=0)){ //Verifica se o usuário e a senha estão incorretos
        textcolor(VERMELHOCLARO);
        gotoxy(12,20);printf("Usu%crio ou senha incorretos", 160);
        getch();
    }

    fclose(dados_adm); //Fecha o arquivo
    conta();
}

void criar_conta(administrador adm){ /*Função para criar uma conta para ter acesso a todo o sistema da locadora*/
    int cont1, cont;

    FILE *dados_adm;
    dados_adm=fopen("admin.bin", "ab"); //Abre arquivo para cadastrar administrador

    if(dados_adm==NULL){
        fclose(dados_adm);
        erro_arquivo();
        conta();
    }

    textcolor(BRANCOBR);
    gotoxy(84,5);
    printf(".:CONTA:.");
    gotoxy(72,12);
    printf(">>Nome: ");
    fflush(stdin);
    gets(adm.nome);
    gotoxy(72,14);
    printf(">>Usu%crio: ", 160);
    fflush(stdin);
    gets(adm.user);
    gotoxy(72,16);
    printf(">>Senha: ");
    fflush(stdin);
    gets(adm.senha);

    fwrite(&adm, sizeof(struct conta_adm),1,dados_adm); //Escreve no arquivo binário as informações digitadas pelo usuário
    fclose(dados_adm); //Fecha o arquivo

    system("cls");

    textcolor(ROXO);
    for(cont1=0;cont1<29;cont1++){
        for(cont=0;cont<69;cont++){
            gotoxy(43+cont,2+cont1);printf("%c", 219);
        }
        Sleep(15);
    }
    login_adm();
}

void conta(){ /*Função para escolher fazer login ou se cadastrar*/

    system("cls"); //Limpa a tela após vir da última função

    administrador adm;
    int opcao, cont, cont1;

    textcolor(LILAS);
    bordag();

    textcolor(ROXO);
    for(cont=0; cont<29; cont++){
        if(cont<20){
            gotoxy(46+cont,22);printf("%c", 223);
            gotoxy(46+cont,25);printf("%c", 223);
        }
        textcolor(ROXO);
        gotoxy(45,2+cont);printf("%c", 223);
        gotoxy(65,2+cont);printf("%c", 223);
    }

    textcolor(LILAS);
    gotoxy(53,23);
    printf(">   <");
    gotoxy(47,10);
    printf("<[1] FAZER LOGIN");
    gotoxy(48,14);
    printf("CRIAR CONTA [2]>");
    gotoxy(55,23);
    scanf("%d", &opcao);
    fflush(stdin);

    textcolor(ROXO);
    switch(opcao){
        case 1:
            for(cont1=0;cont1<29;cont1++){
                for(cont=0;cont<69;cont++){
                    gotoxy(43+cont,2+cont1);printf("%c", 219);
                }
                Sleep(15);
            }
            login_adm();
            break;
        case 2:
            for(cont1=0;cont1<29;cont1++){
                for(cont=0;cont<65;cont++){
                    gotoxy(3+cont,2+cont1);printf("%c", 219);
                }
                Sleep(15);
            }
            criar_conta(adm);
            break;
        default:
            opcao_inv();
            conta();
  }

  system("cls");
}

void carregando(){ /*Função que imprime na tela a palavra "CARREGANDO"*/
    int e;

    system("cls");

    for (e = 10; e < 14; e++){ //Faz com que mude de cor
        int i, x =55, y = 4;
        int aux = y;
        textcolor(e);
        for (i = 0; i < 10; i++){ //Linha esquerda superior
            gotoxy(x,y);
            printf("/");
            x--;
            y++;
            Sleep(10);
        }

        for (i = 0; i < 10; i++){ //Linha direita superior
            gotoxy(x+11,aux);
            printf("%c",92);
            x++;
            aux++;
            Sleep(10);
        }

        for (i = 0; i < 10; i++){ //linha esquerda inferior
            gotoxy(x-9,y);
            printf("%c",92);
            x++;
            y++;
            Sleep(10);
        }

        for (i = 0; i < 10; i++){ //linha direita inferior
            gotoxy(x,aux);
            printf("/");
            x--;
            aux++;
            Sleep(10);
        }

        for (i = 0; i < 10; i++){
            gotoxy(x-11,aux+1);
            printf(" C A R R E G A N D O.  ");
            gotoxy(110,28);
        }

        for (i = 0; i < 10; i++){
            gotoxy(x-11,aux+1);
            printf(" C A R R E G A N D O.. ");
            gotoxy(110,28);
        }

        for (i = 0; i < 10; i++){
            gotoxy(x-11,aux+1);
            printf(" C A R R E G A N D O...");
            gotoxy(110,28);
        }

    }
    conta();
}

void mensagem(){ /*Mensagem que explica a intenção do sistema MONSTRIX*/
    int i, cont;

    char recado[]={ "Você pode achar que um sistema de locadora física de filmes é inútil" };
    char recado1[]={ "devido o seu desuso, porém, ainda existem unidades espalhadas pelo"};
    char recado2[]={ "mundo. O objetivo desse sistema é contribuir para a qualidade do"};
    char recado3[]={ "atendimento fornecido por essas locadoras, auxiliando no armazenamento"};
    char recado4[]={ "das informações de maneira organizada e de fácil acesso."};

    for(i=0; recado[i]!='\0'; i++){
        cont+=1;
        switch(recado[i]){
            case 'ê':
                printf("%c", 136);
                Sleep(50);
                break;
            case 'í':
                printf("%c", 161);
                Sleep(50);
                break;
            case 'é':
                printf("%c", 130);
                Sleep(50);
                break;
            case 'ú':
                printf("%c", 163);
                Sleep(50);
                break;
            case 'ç':
                printf("%c", 135);
                Sleep(50);
                break;
            case 'õ':
                printf("%c", 228);
                Sleep(50);
                break;
            case 'á':
                printf("%c", 160);
                Sleep(50);
                break;
            default:
                gotoxy(25+cont,10);
                printf("%c", recado[i]);
                Sleep(50);
                break;
        }
    }
    cont=0;

    for(i=0; recado1[i]!='\0'; i++){
        cont+=1;
        switch(recado1[i]){
            case 'ê':
                printf("%c", 136);
                Sleep(50);
                break;
            case 'í':
                printf("%c", 161);
                Sleep(50);
                break;
            case 'é':
                printf("%c", 130);
                Sleep(50);
                break;
            case 'ú':
                printf("%c", 163);
                Sleep(50);
                break;
            case 'ç':
                printf("%c", 135);
                Sleep(50);
                break;
            case 'õ':
                printf("%c", 228);
                Sleep(50);
                break;
            case 'á':
                printf("%c", 160);
                Sleep(50);
                break;
            default:
                gotoxy(25+cont,11);
                printf("%c", recado1[i]);
                Sleep(50);
                break;
        }
    }

    cont=0;

    for(i=0; recado2[i]!='\0'; i++){
        cont+=1;
        switch(recado2[i]){
            case 'ê':
                printf("%c", 136);
                Sleep(50);
                break;
            case 'í':
                printf("%c", 161);
                Sleep(50);
                break;
            case 'é':
                printf("%c", 130);
                Sleep(50);
                break;
            case 'ú':
                printf("%c", 163);
                Sleep(50);
                break;
            case 'ç':
                printf("%c", 135);
                Sleep(50);
                break;
            case 'õ':
                printf("%c", 228);
                Sleep(50);
                break;
            case 'á':
                printf("%c", 160);
                Sleep(50);
                break;
            default:
                gotoxy(26+cont,12);
                printf("%c", recado2[i]);
                Sleep(50);
                break;
        }
    }

    cont=0;

    for(i=0; recado3[i]!='\0'; i++){
        cont+=1;
        switch(recado3[i]){
            case 'ê':
                printf("%c", 136);
                Sleep(50);
                break;
            case 'í':
                printf("%c", 161);
                Sleep(50);
                break;
            case 'é':
                printf("%c", 130);
                Sleep(50);
                break;
            case 'ú':
                printf("%c", 163);
                Sleep(50);
                break;
            case 'ç':
                printf("%c", 135);
                Sleep(50);
                break;
            case 'õ':
                printf("%c", 228);
                Sleep(50);
                break;
            case 'á':
                printf("%c", 160);
                Sleep(50);
                break;
            default:
                gotoxy(22+cont,13);
                printf("%c", recado3[i]);
                Sleep(50);
                break;
        }
    }

    cont=0;

    for(i=0; recado4[i]!='\0'; i++){
        cont+=1;
        switch(recado4[i]){
            case 'ê':
                printf("%c", 136);
                Sleep(50);
                break;
            case 'í':
                printf("%c", 161);
                Sleep(50);
                break;
            case 'é':
                printf("%c", 130);
                Sleep(50);
                break;
            case 'ú':
                printf("%c", 163);
                Sleep(50);
                break;
            case 'ç':
                printf("%c", 135);
                Sleep(50);
                break;
            case 'õ':
                printf("%c", 228);
                Sleep(50);
                break;
            case 'á':
                printf("%c", 160);
                Sleep(50);
                break;
            default:
                gotoxy(30+cont,14);
                printf("%c", recado4[i]);
                Sleep(50);
                break;
        }
    }

    getch();
    carregando();
}

void inicial(){ /*Função utilizada para fazer a entrada do programa (1° Interface)*/
    int e, cont = 0;

    for (e = 0; e < 12; e++){ //Faz com que mude de cor

        int i, x = 25, y = 2;
        int aux = y;

        textcolor(e);
        for (i = 0; i < 10; i++){ //Linha esquerda superior
            gotoxy(x,y);printf("/");
            x--;
            y++;
        }

        for (i = 0; i < 10; i++){ //Linha direita superior
            gotoxy(x+11,aux);printf("%c",92);
            x++;
            aux++;
        }

        for (i = 0; i < 10; i++){ //linha esquerda inferior
            gotoxy(x-9,y);printf("%c",92);
            x++;
            y++;
        }

        for (i = 0; i < 10; i++){ //linha direita inferior
            gotoxy(x,aux);printf("/");
            x--;
            aux++;
        }

        gotoxy(32,17);
        printf(" ");
        gotoxy(31,16);
        printf(" ");
        gotoxy(23,9);
        printf(" __   __  _______  __    _  _______  _______  ______    ___   __   __ ");
        gotoxy(23,10);
        printf("|  |_|  ||       ||  |  | ||       ||       ||    _ |  |   | |  |_|  |");
        gotoxy(23,11);
        printf("|       ||   _   ||   |_| ||  _____||_     _||   | ||  |   | |       |");
        gotoxy(23,12);
        printf("|       ||  | |  ||       || |_____   |   |  |   |_||_ |   | |       |");
        gotoxy(23,13);
        printf("|       ||  |_|  ||  _    ||_____  |  |   |  |    __  ||   |  |     | ");
        gotoxy(23,14);
        printf("| ||_|| ||       || | |   | _____| |  |   |  |   |  | ||   | |   _   |");
        gotoxy(23,15);
        printf("|_|   |_||_______||_|  |__||_______|  |___|  |___|  |_||___| |__| |__|");

        textcolor(BRANCOBR);
        gotoxy(32,17);
        printf("O   M E L H O R   D O   C I N E M A   N A   S U A   C A S A");
        Sleep(90); //Impressão aos poucos
    }

    textcolor(LILAS);
    for(cont=0; cont<113; cont++){ //Linha carregando abaixo de MONSTRIX
        Sleep(10);
        gotoxy(1+cont,25);printf("_");
    }

    textcolor(BRANCOBR);
    gotoxy(38,26);
    system("pause"); //Trava a tela até que alguma tecla seja pressionada

    system("cls");

    textcolor(ROXO);
    bordag();

    textcolor(BRANCOBR);
    gotoxy(25,10);
    mensagem();
}

int main(){
    system ("color 0F"); //Altera a cor da fonte e do plano de fundo
    inicial();
    return 0;
}
