#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include "LP_Grupo43.h"


ESTACIONAMENTO reserva[NCARROSRES];
ESTACIONAMENTO carro[NCARROS];


void limparEcra(){
    /**
     * esta função consiste em dar vários new lines de modo a limpar o ecrã
     */
    for(int i=0;i<100;i++)//função for q conta de 0 a 99
        printf("\n");
}


void iniciaParque1(int parque1[DIM] [DIM]){
    /**
     * esta função inicia o parque a 0, ou seja, inicia todos os lugares como disponíveis
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     */
    int i,j;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            parque1[i][j]=0;//inicia todas as coordenadas a 0          
}

void iniciaParque2(int parque2[DIM] [DIM]){
    /**
     * esta função inicia o parque a 0, ou seja, inicia todos os lugares como disponíveis
     * @param parque1 a função recebe a variavel parque2 que se refere ao piso 1 do parque de estacionamento
     */
    int i,j;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            parque2[i][j]=0;//inicia todas as coordenadas a 0             
}

void iniciaParque(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * esta função serve para juntar os dois pisos do parque de estacionamento
     * @param parque1 a função recebe a variavel parque2 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 1 do parque de estacionamento
     */
    iniciaParque1(parque1);//reencaminha para o iniciaparque1 para inicializar o piso 1
    iniciaParque2(parque2);//reencaminha para o iniciaparque2 para inicializar o piso 2
}

void mostraParque1(int parque1 [DIM][DIM]){
    /**
     * esta função consiste em printar no ecrã o piso 1 de forma esquemática
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     */
    int i,j;
    printf("Piso 1:\n");
     for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++)
            printf("%d  ",parque1[i][j]);//printa no ecrã todos os lugares do piso 1
        printf("\n");
     }
}

void mostraParque2(int parque2 [DIM][DIM]){
    /**
     * esta função consiste em printar no ecrã o piso 2 de forma esquemática
     * @param parque1 a função recebe a variavel parque2 que se refere ao piso 1 do parque de estacionamento
     */
    int i,j;
    printf("Piso 2:\n");
     for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++)
            printf("%d  ",parque2[i][j]);//printa no ecrã todos os lugares do piso 2
        printf("\n");
     }
}

void mostraParque(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * esta função serve para juntar os dois pisos do parque de estacionamento de forma a printar no ecrã 
     * com a respetiva legenda
     * @param parque1 a função recebe a variavel parque2 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 1 do parque de estacionamento
     */ 
    puts("\t\t\t********************************************");
    puts("\t\t\t\t\t  Legenda");
    puts("\t\t\t\t0 - Livre");
    puts("\t\t\t\t1 - Ocupado");
    puts("\t\t\t\t2 - Inexistente");
    puts("\t\t\t\t3 - Reservado");
    puts("\t\t\t********************************************");
    mostraParque1(parque1);//invoca o primeiro piso printando
    for(int x=0; x<DIM-2 ; x++)
        printf("-");
    for(int x=0; x<DIM ; x++)
        printf("--");
    //faz a separação com hifens corretamente de acordo com a dimensão escolhida do piso
    printf("\n");
    mostraParque2(parque2);//invoca o segundo piso printando
}
void tirarCarro1(int parque1 [DIM][DIM],int *total){
    int i;
    do{
        printf("Em que lugar estava estacionado ?\n");
        scanf("%d",&carro[*total].x);
        limparBuffer;
        scanf("%d",&carro[*total].y);
        limparBuffer;
        if(carro[*total].x<0 || carro[*total].x>=DIM || carro[*total].y<0 || carro[*total].y>=DIM){
            printf("Coordenadas erradas\n");
        }
    }while(carro[*total].x<0 || carro[*total].x>=DIM || carro[*total].y<0 || carro[*total].y>=DIM);
    if(parque1[carro[*total].x][carro[*total].y]==1){
        parque1[carro[*total].x][carro[*total].y]=0;
        
        printf("Lugar Desocupado, pode seguir!\n");
    }
    else if(parque1[carro[*total].x][carro[*total].y]==3)
        printf("Lugar Reservado\n");
    else if(parque1[carro[*total].x][carro[*total].y]==2)
        printf("Lugar Inexistente\n");
    else 
        printf("Este lugar já se encontra livre !\n");
}

void tirarCarro2(int parque2 [DIM][DIM],int *total){
    int i;
    do{
        printf("Em que lugar estava estacionado ?\n");
        scanf("%d",&carro[*total].x);
        limparBuffer;
        scanf("%d",&carro[*total].y);
        limparBuffer;
        if(carro[*total].x<0 || carro[*total].x>=DIM || carro[*total].y<0 || carro[*total].y>=DIM){
            printf("Coordenadas erradas\n");
        }
    }while(carro[*total].x<0 || carro[*total].x>=DIM || carro[*total].y<0 || carro[*total].y>=DIM);
    if(parque2[carro[*total].x][carro[*total].y]==1){
        parque2[carro[*total].x][carro[*total].y]=0;

        printf("Lugar Desocupado, pode seguir!\n");
    }
    else if(parque2[carro[*total].x][carro[*total].y]==3)
        printf("Lugar Reservado\n");
    else if(parque2[carro[*total].x][carro[*total].y]==2)
        printf("Lugar Inexistente\n");
    else 
        printf("Este lugar já se encontra livre !\n");
}

void tirarCarro(int parque1[DIM][DIM],int parque2[DIM][DIM],int *total){
    int op;
    char v[20];
    do{
        printf("Estava estacionado no piso 1 ou no piso 2?\n");
        scanf("%d",&carro[*total].piso);
        limparBuffer;
        if(carro[*total].piso!=1 && carro[*total].piso!=2){
            printf("Por favor introduza o número 1 ou 2!\n");
        }
    }while(carro[*total].piso != 1 && carro[*total].piso!=2);
    switch(carro[*total].piso){
        case 1:
            mostraParque1(parque1);
            tirarCarro1(parque1,total);
            break;
        case 2:
            mostraParque2(parque2);
            tirarCarro2(parque2,total);
            break;
        }
}

void lugarInexistente1(int parque1 [DIM][DIM]){
    /**
     * esta função serve para o administrador delimitar os lugares existente no parque
     * @param parque1 a função recebe a variavel parque2 que se refere ao piso 1 do parque de estacionamento
     */
    int i,j,n,x;
    do{ 
        printf("Introduza número de lugares inexistentes no piso 1:\n");
        scanf("%d",&n);
        limparBuffer;
        if(n>DIM*DIM){//verifica se o número introduzido pelo utilizador é válido
            printf("Número de lugares inexistentes impossíveis\n");
        }
    }while(n>DIM*DIM);//não deixa o ciclo terminar enquanto o utilizador não introduzir um número válido

    for(x=0;x<n;x++){

        do{
        printf("Lugar que não exista:\n");
        scanf("%d",&i);
        limparBuffer;
        scanf("%d",&j);
        limparBuffer;
        if(i<0 || i>=DIM || j<0 || j>=DIM){
            printf("Coordenadas erradas\n");
        }
        
    }while(i<0 || i>=DIM || j<0 || j>=DIM);
        if(parque1[i][j]==0){
            parque1[i][j]=2;//no caso de introduzir uma coordenada válida altera o valor
        }
        else{
            x=x-1;
            //no caso de introduzir uma coordenada inválida decrementa para apenas o ciclo acabar quando 
            //introduzir o número de lugares inválidos escolhido em cima
        }
    }
}

void lugarInexistente2(int parque1 [DIM][DIM]){
     /**
     * esta função serve para o administrador delimitar os lugares existente no parque
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    int i,j,n,x;
    do{ 
        printf("Introduza número de lugares inexistentes no piso 2:\n");
        scanf("%d",&n);
        limparBuffer;
        if(n>DIM*DIM){//verifica se o número introduzido pelo utilizador é válido
            printf("Número de lugares inexistentes impossíveis\n");
        }
    }while(n>DIM*DIM);//não deixa o ciclo terminar enquanto o utilizador não introduzir um número válido
    
    for(x=0;x<n;x++){

        do{
        printf("Lugar que não exista:\n");
        scanf("%d",&i);
        limparBuffer;
        scanf("%d",&j);
        limparBuffer;
        if(i<0 || i>=DIM || j<0 || j>=DIM){
            printf("Coordenadas erradas\n");
        }
        
    }while(i<0 || i>=DIM || j<0 || j>=DIM);
        if(parque1[i][j]==0){
            parque1[i][j]=2;//no caso de introduzir uma coordenada válida altera o valor
        }
        else{
            x=x-1;
            //no caso de introduzir uma coordenada inválida decrementa para apenas o ciclo acabar quando 
            //introduzir o número de lugares inválidos escolhido em cima
        }
    }
}

void lugarInexistente(int parque1[DIM][DIM],int parque2 [DIM][DIM]){
    /**
     * esta função serve para juntar os dois pisos do parque de estacionamento de forma a delimitar os dois
     * ao mesmo tempo
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    lugarInexistente1(parque1);//chama a função para delimitar o piso 1
    lugarInexistente2(parque2);//chama a função para delimitar o piso 2
}

void estacionarCarro1(int parque1[DIM][DIM],ESTACIONAMENTO *carro,int *total){
    /**
     * esta função permite ao utilizador estacionar um carro no piso 2, introduzindo ele duas coordenadas válidas
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param carro a função recebe a estrutura carro
     * @param total a função recebe uma variável total onde é armazenada o número total de carros estacionados no parque
     */
    int i,j;
    do{
        do{//permite ao utilizador introduzir duas coordenadas e valida-as       
            printf("Qual o lugar que deseja estacionar:\n");
            scanf("%d",&carro[*total].x);
            limparBuffer;
            scanf("%d",&carro[*total].y);
            limparBuffer;
      
            if(carro[*total].x<0 || carro[*total].x>=DIM || carro[*total].y<0 || carro[*total].y>=DIM){
                printf("Coordenadas erradas\n");
        }
    }while(carro[*total].x<0 || carro[*total].x>=DIM || carro[*total].y<0 || carro[*total].y>=DIM);
        if(parque1[carro[*total].x][carro[*total].y]==2)
            printf("Lugar Inexistente\n");
        else if(parque1[carro[*total].x][carro[*total].y]==1)
            printf("Lugar Ocupado\n");
        else if(parque1[carro[*total].x][carro[*total].y]==3)
            printf("Lugar Reservado\n");
        else
            parque1[carro[*total].x][carro[*total].y]=1;
    }while(parque1[carro[*total].x][carro[*total].y]!=1);
           (*total)++;
}

void estacionarCarro2(int parque2[DIM][DIM],ESTACIONAMENTO *carro,int *total){
    /**
     * esta função permite ao utilizador estacionar um carro no piso 2, introduzindo ele duas coordenadas válidas
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     * @param carro a função recebe a estrutura carro
     * @param total a função recebe uma variável total onde é armazenada o número total de carros estacionados no parque
     */
    int i,j;
    do{
        do{//permite ao utilizador introduzir duas coordenadas e valida-as         
            printf("Qual o lugar que deseja estacionar:\n");
            scanf("%d",&carro[*total].x);
            limparBuffer;
            scanf("%d",&carro[*total].y);
            limparBuffer;
           
            if(carro[*total].x<0 || carro[*total].x>=DIM || carro[*total].y<0 || carro[*total].y>=DIM){
                printf("Coordenadas erradas\n");
        }
    }while(carro[*total].x<0 || carro[*total].x>=DIM || carro[*total].y<0 || carro[*total].y>=DIM);
        if(parque2[carro[*total].x][carro[*total].y]==2)
            printf("Lugar Inexistente\n");
        else if(parque2[carro[*total].x][carro[*total].y]==1)
            printf("Lugar Ocupado\n");
        else if(parque2[carro[*total].x][carro[*total].y]==3)
            printf("Lugar Reservado\n");
        else
            parque2[carro[*total].x][carro[*total].y]=1;
        
    }while(parque2[carro[*total].x][carro[*total].y]!=1);
         (*total)++;
}

void estacionarCarro(int parque1[DIM][DIM],int parque2[DIM][DIM],int *total){
    /**
     * esta função permite ao utilizador escolher em que parque quer estacionar
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     * @param total a função recebe uma variável total onde é armazenada o número total de carros estacionados no parque
     */
    
    printf("Introduza a matrícula do seu carro: ");
    scanf("%s",&carro[*total].mat);//permite ao utilizador introduzir a sua matricula
    limparBuffer;
    
    printf("Marca: ");
    scanf("%s", &carro[*total].marca);//permite ao utilizador introduzir a sua marca
    limparBuffer;
    
    carro[*total].t_tempoEntrada = time(NULL);//grava o tempo de entrada através da função time_t
    
    do{//permite ao utilizador escolher o piso validando-o
        printf("Deseja estacionar no piso 1 ou 2:\n");
        scanf("%d",&carro[*total].piso);//permite ao utilizador escolher o piso
        limparBuffer;
        if(carro[*total].piso !=1 && carro[*total].piso !=2){
            printf("Por favor introduza o número 1 ou 2!\n");
        }
    }while(carro[*total].piso != 1 && carro[*total].piso !=2);
    switch(carro[*total].piso){
        case 1:
            printf("Escolheu o piso 1\n");
            estacionarCarro1(parque1,carro,total);//redireciona o utilizador a função de estacionar no piso pretendido
            break;
        case 2:
            printf("Escolheu o piso 2\n");
            estacionarCarro2(parque2,carro,total);//redireciona o utilizador a função de estacionar no piso pretendido
            break;
        }
}

void estacionarCarroReservado(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * esta função permite ao utilizador introduzir a matricula do seu carro caso tenha reservado um lugar
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    int x=1;
    char v[20+1];
    time_t t_inic;   
    puts("Introduza a sua matricula:");
    scanf("%s",&v);//permite ao utilizador inserir a matricula do carro
    
    for(int i=0;i<5;i++)//checka todas as matriculas existentes
        if(strcmp(v,reserva[i].mat)==0){
            x=0;//altera o valor da variavel em caso de sucesso, ou seja  a matricula existir no array
            printf("O seu lugar reservado é [%d][%d] no piso %d\n",reserva[i].x,reserva[i].y,reserva[i].piso);
            mostraParque(parque1,parque2);//mostra o parque ao utilizador
            t_inic = reserva[i].t_tempoEntrada;
        }

    if(x==1){//em caso de não encontrar nenhuma matricula igual lança uma mensagem de aviso ao utilizador
        puts("Matrícula errada");
        menuUtilizador(parque1,parque2);//permite ao utilizador voltar ao seu menu
    }
}

void reservarCarro1(int parque1 [DIM][DIM],int i){
    /**
     * permite ao administrador reservar um carro para um utilizador
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param i recebe a posição do array no qual vai ficar as coordenas/matriculas
     */
    do{
        do{//pede as coordenadas ao utilizador e valida-as
           printf("Qual o lugar que deseja reservar:\n");
           scanf("%d",&reserva[i].x);
           limparBuffer;
           scanf("%d",&reserva[i].y);
           limparBuffer;
           if(reserva[i].x<0 || reserva[i].x>=DIM || reserva[i].y<0 || reserva[i].y>=DIM){
              printf("Coordenadas erradas\n");
        }
    }while(reserva[i].x<0 || reserva[i].x>=DIM || reserva[i].y<0 || reserva[i].y>=DIM);
        //no caso de as coordenadas serem validas, valida se o lugar está disponivel
        if(parque1[reserva[i].x][reserva[i].y]==2)
            printf("Lugar Inexistente\n");
        else if(parque1[reserva[i].x][reserva[i].y]==1)
            printf("Lugar Ocupado\n");
        else if(parque1[reserva[i].x][reserva[i].y]==3)
            printf("Lugar Reservado");
        else
            parque1[reserva[i].x][reserva[i].y]=3;
    }while(parque1[reserva[i].x][reserva[i].y]!=3);
}

void reservarCarro2(int parque2 [DIM][DIM],int i){
    /**
     * permite ao administrador reservar um carro para um utilizador
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     * @param i recebe a posição do array no qual vai ficar as coordenas/matriculas
     */
    do{
        do{//pede as coordenadas ao utilizador e valida-as
           printf("Qual o lugar que deseja reservar:\n");
           scanf("%d",&reserva[i].x);
           limparBuffer;
           scanf("%d",&reserva[i].y);
           limparBuffer;
           if(reserva[i].x<0 || reserva[i].x>=DIM || reserva[i].y<0 || reserva[i].y>=DIM){
              printf("Coordenadas erradas\n");
        }
    }while(reserva[i].x<0 || reserva[i].x>=DIM || reserva[i].y<0 || reserva[i].y>=DIM);
        //no caso de as coordenadas serem validas, valida se o lugar está disponivel
        if(parque2[reserva[i].x][reserva[i].y]==2)
            printf("Lugar Inexistente\n");
        else if(parque2[reserva[i].x][reserva[i].y]==1)
            printf("Lugar Ocupado\n");
        else if(parque2[reserva[i].x][reserva[i].y]==3)
            printf("Lugar Reservado");
        else
            parque2[reserva[i].x][reserva[i].y]=3;
    }while(parque2[reserva[i].x][reserva[i].y]!=3);
}

void reservarCarro(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * junta os dois pisos num permitindo reservar os carros 
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    int i=0,x=0;
    printf("Quantos carros deseja reservar ?\n");
    scanf("%d",&x);//permite ao administrador introduzir o numero de carros que quer reservar
    do{
        if(x>3){//valida o número de carros
            printf("Impossível reservar tantos lugares ao mesmo tempo!\n");
            scanf("%d",&x);
        }
    }while(x>3);//não termina o ciclo enquanto o administrador não introduz um valor válido
    x=x-1;//decrementa um pois relembre se que a variavel i começa no valor 0
    while(i<=x){
    puts("Introduza a sua matricula:");
    scanf("%s",&reserva[i].mat);//permite ao admin introduzir a matricula
        
    do{
        printf("Reservar no piso 1 ou 2:\n");
        scanf("%d",&reserva[i].piso);//permite ao admin introduzir o piso 1
        limparBuffer;
        if(reserva[i].piso!=1 && reserva[i].piso!=2){//valida se o piso é valido
            printf("Por favor introduza o número 1 ou 2!\n");
        }
    }while(reserva[i].piso != 1 && reserva[i].piso!=2);
    switch(reserva[i].piso){//no caso de ser válido,invoca a função respectiva para introduzir no piso selecionado
        case 1:
            printf("Escolheu o piso 1\n");
            reservarCarro1(parque1,i);
            break;
        case 2:
            printf("Escolheu o piso 2\n");
            reservarCarro2(parque2,i);
            break;
        }
    i++;//incrementa após cada lugar reservado
    }
    }

int contaReservados1(int parque1[DIM][DIM]){
    /**
     * esta função permite contar o numero de lugares que se encontram reservados
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @return o numero de lugares reservados neste piso
     */
    int i,j,reservados=0;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            if(parque1[i][j]==3)
                reservados++;//corre toda a matriz e em cada posição q contiver um 3, incrementa o valor em 1
        
//    if(reservados==1)
//        printf("Existe %d lugar reservado no parque 1\n",reservados);
//    else
//        printf("Existem %d lugares reservados parque 1\n",reservados);
        return reservados;
}

int contaReservados2(int parque2[DIM][DIM]){
    /**
     * esta função permite contar o numero de lugares que se encontram reservados
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     * @return o numero de lugares reservados neste piso
     */
    int i,j,reservados=0;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            if(parque2[i][j]==3)
                reservados++;//corre toda a matriz e em cada posição q contiver um 3, incrementa o valor em 1
        
//    if(reservados==1)
//        printf("Existe %d lugar reservado no parque 2\n",reservados);
//    else
//        printf("Existem %d lugares reservados parque 2\n",reservados);
        return reservados; 
}

int contaReservados(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * esta função permite somar o número de reservados dos dois pisos
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     * @return o numero total de reservados dos dois pisos
     */
    int res=0;
    res=contaReservados1(parque1);//recebe o numero de reservados do piso 1
    res+=contaReservados2(parque2);//recebe o numero de reservados do piso 2
//    printf("%d",res);
    return res;//retorna o numero total de reservados dos dois pisos
}

void permiteReservar(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * esta funçãoa valida ou não as reservas em função com o limite
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    int numeroReservas;
    numeroReservas=contaReservados(parque1,parque2);//recebe o valor de reservados nos dois pisos e grava nesta variável
    if(numeroReservas<LIM)
        reservarCarro(parque1,parque2);//no caso de validar, encaminha à função desejada
    else
        printf("Número de reservas cheias, impossivel reservar mais carros");//no caso de não validar imite uma mensagem de erro
}

void lugaresDisponiveis1(int parque1[DIM][DIM]){
    /**
     * esta função permite contar o número de lugares disponiveis no parque de estacionamento 1
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     */
    int i,j,disponiveis=0;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            if(parque1[i][j]==0)
                disponiveis++;//a cada valor 0, o valor disponiveis é incrementado em 1
    if(disponiveis==1)
        printf("Existe %d lugar dísponível no parque 1\n",disponiveis);
    else
        printf("Existem %d lugares disponíveis parque 1\n",disponiveis);
}

void lugaresDisponiveis2(int parque2[DIM][DIM]){
    /**
     * esta função permite contar o número de lugares disponiveis no parque de estacionamento 2
     * @param parque1 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    int i,j,disponiveis=0;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            if(parque2[i][j]==0)
                disponiveis++;//a cada valor 0, o valor disponiveis é incrementado em 2
    if(disponiveis==1)
        printf("Existe %d lugar dísponível no parque 2\n",disponiveis);
    else
        printf("Existem %d lugares disponíveis parque 2\n",disponiveis);
}

void lugaresDisponiveis(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * esta função permite mostrar os lugares disponiveis de cada piso
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    lugaresDisponiveis1(parque1);//invoca a função responsável pela contagem dos lugares disponiveis no piso 1
    lugaresDisponiveis2(parque2);//invoca a função responsável pela contagem dos lugares disponiveis no piso 2
}

void lugarMaisPerto1(int parque1[DIM][DIM]){
    /**
     * esta função indica as coordenadas do lugar mais perto do piso 1
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     */
    float min=INT_MAX;
    int i,j,k=0;
    float D[DIM*DIM];//declara o array com o número necessário de posições
    // inicializar o array D com valores altos
    for(int x =0; x< DIM*DIM; x++){
        D[x]=DISTANCIAMAX;   
    }
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++){
            if(parque1[i][j]==0)//apenas cacula dos lugares disponiveis
            {
            D[k] = sqrt( pow(i-0,2) + pow(j-0,2));//calcula a distancia cartesiana de cada coordenada gravando as no array
            }
            k++;//incrementa a posição
        }
    for(k=0;k<DIM*DIM;k++)
        if(D[k] < min)
            min = D[k];//compara todas as coordenadas e grava a minima
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++){
           if(parque1[i][j] == 0)//apenas cacula dos lugares disponiveis
           {
                D[k] = sqrt( pow(i-0,2) + pow(j-0,2));//calcula a distancia cartesiana de cada coordenada novamente
                if(D[k] == min){//compara com o valor minimo gravado
                    printf("[%d] [%d]",i,j);//printa o número das coordenadas quando encontrado
                    printf("\n");
                }
          }
        }    
}

void lugarMaisPerto2(int parque2[DIM][DIM]){
    /**
     * esta função indica as coordenadas do lugar mais perto do piso 2
     * @param parque1 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    float min=INT_MAX;
    int i,j,k=0;
    float D[DIM*DIM];//declara o array com o número necessário de posições
    // inicializar o array D com valores altos
    for(int x =0; x< DIM*DIM; x++){
        D[x]=DISTANCIAMAX;   
    }
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++){
            if(parque2[i][j]==0)//apenas cacula dos lugares disponiveis
            {
            D[k] = sqrt( pow(i-0,2) + pow(j-0,2));//calcula a distancia cartesiana de cada coordenada gravando as no array
            }
            k++;//incrementa a posição
        }
    for(k=0;k<DIM*DIM;k++)
        if(D[k] < min)
            min = D[k];//compara todas as coordenadas e grava a minima 
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++){
           if(parque2[i][j] == 0)//apenas cacula dos lugares disponiveis
           {
                D[k] = sqrt( pow(i-0,2) + pow(j-0,2));//calcula a distancia cartesiana de cada coordenada novamente
                if(D[k] == min){//compara com o valor minimo gravado
                    printf("[%d] [%d]",i,j);//printa o número das coordenadas quando encontrado
                    printf("\n");
                }
          }
        }    
}

void lugarMaisPerto(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * esta função permite escolher o lugar mais perto de um piso à escolha
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    int op;
    do{
        printf("Deseja saber o lugar mais perto no piso 1 ou 2?\n");
        scanf("%d",&op);//permite ao utilizador escolher o lugar
        limparBuffer;
        if(op!=1 && op!=2){//verifica o piso
            printf("Por favor introduza o número 1 ou 2!\n");
        }
    }while(op!= 1 && op!=2);
    switch(op){
        case 1:
            printf("Escolheu o piso 1\n");
            lugarMaisPerto1(parque1);//reencaminha o utilizador para o lugar mais perto no piso 1
            break;
        case 2:
            printf("Escolheu a piso 2\n");
            lugarMaisPerto2(parque2);//reencaminha o utilizador para o lugar mais perto no piso 2
            break;
        }
}

void pagamento(int parque1[DIM][DIM],int parque2[DIM][DIM],ESTACIONAMENTO *carro,int total){
    /**
     * 
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     * @param carro a função recebe a estrutura carro
     * @param total a função recebe uma variável total onde é armazenada o número total de carros estacionados no parque
     */
    int i,tempo,tempoM;
    char v[TAM];
    int x=1;    
    
    printf("Introduza a sua matrícula: ");
    scanf("%s",&v);//permite ao utilizador introduzir a matricula
    
    for(i=0; i < total; i++){
        if(strcmp(v,carro[i].mat) == 0){//se a matricula existir nos registos procede ao pagamento
            x=0;
           carro[i].t_tempoSaida = time(NULL); //grava o tempo de saida através da função time_t
           
            puts("");
            printf("DATA : %s HORA: %s\n",__DATE__,__TIME__);
            printf("MATRICULA:\n");
            printf("%s\n",carro[i].mat );
            printf("MARCA:\n");
            printf("%s\n",carro[i].marca );
            printf("PISO:\n");
            printf("%d\n", carro[i].piso);
            printf("LUGAR OCUPADO:\n");
            printf("[%d] [%d]\n", carro[i].x,carro[i].y);


             tempo = difftime(carro[i].t_tempoSaida,carro[i].t_tempoEntrada);//calcula a diferença do tempo de entrada e saída
             tempoM = tempo/60;//transforma o tempo em minutos
     
     
            //escolhe a opção dependendo do tempo que o carro esteve estacionado 
            if(tempoM>=0 && tempoM<=15){

                puts("Total a pagar: 0.10€");
                
                tirarCarro(parque1,parque2,&total);
            }

            else if(tempoM>15 && tempoM<=30)
            {
                puts("Total a pagar: 0.30€ ");
                
                tirarCarro(parque1,parque2,&total);
            }

            else if(tempoM>30 && tempoM<=45)
            {
                puts("Total a pagar: 0.50€ ");
                
                tirarCarro(parque1,parque2,&total);
            }

            else if(tempoM>45 && tempoM<=60)
            {
                puts("Total a pagar: 0.70€ ");
                
                tirarCarro(parque1,parque2,&total);
            }

            else if(tempoM>60 && tempoM<=120)
            {
                puts("Total a pagar: 1.50€ ");
                
                tirarCarro(parque1,parque2,&total);
            }
            else if(tempoM>12000)
            {
                puts("Estacionamento abusivo impossivel o pagamento");
                
                tirarCarro(parque1,parque2,&total);
            }
             
        }      
            

    }
    if(x==1){
        limparEcra();
        printf("Matrícula errada\n");
        
    }
 
}
void lerDados(ESTACIONAMENTO *carro, int *total)
{
    /**
    * Lê dados de ficheiro (se existir) e preenche os registos
    *   
    * @param carro um apontador para o primeiro carro a preencher
    * @param total um apontador para o número de carros que existem atualmente na lista
    */
    FILE *f;
    
    if ((f = fopen("ficheiro.bin","rb")) == NULL)
    {
        *total = 0; //se falhou abertura do ficheiro
        perror(NULL);
        return;
    }
    
    fread(total, sizeof(int), 1, f); //lê nº de registos escritos no ficheiro
    fread(carro, sizeof(ESTACIONAMENTO), *total, f); //lê os registos
    
    fclose(f);
}

void escreverDados(ESTACIONAMENTO *carro, int *total)
{
    /**
    * Escreve o conteúdo dos registos em ficheiro
    * 
    * @param alunos um apontador para o primeiro carro dos registos
    * @param quantos quantos carros existem no registo
     * 
     */
    FILE *f;
    
    if ((f = fopen("ficheiro.bin","wb")) == NULL)
    {
        perror(NULL);//se falhou a escrita do ficheiro
        return;
    }
    
    fwrite(&total, sizeof(int), 1, f); //escreve nº de registos a ser escritos
    fwrite(carro, sizeof(ESTACIONAMENTO), *total, f); //escreve registos
}


void menuUtilizador(int parque1[DIM][DIM],int parque2[DIM][DIM]){
    /**
     * permite ao utilizador interagir de forma simples com o programa
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque2 que se refere ao piso 2 do parque de estacionamento
     */
    limparEcra();
    int total;
    char opUt,opE;
    do{
        do{//menu, o ciclo não termina enquanto não meter uma opção válida 
            puts("\t\t\t*********************************************");
            puts("\t\t\t***          MENU DE UTILIZADOR           ***");
            puts("\t\t\t*********************************************");
            puts("\t\t\t\tEstacionamento - E/e");
            puts("\t\t\t\tPagamento - P/p");
            puts("\t\t\t\tSair - S/s"); 
            puts("\t\t\t*********************************************");
            scanf(" %c",&opUt);
        }while(opUt!= 'P' && opUt!= 'p' && opUt!= 'E' && opUt!= 'e' && opUt!= 'S' && opUt!= 's');
        switch(opUt){//após esta ser validade, o utilziador é rederecionado para a opção que escolheu
            case 'p':
            case 'P':
                pagamento(parque1,parque2,carro,total);
                break;
            case 'e':
            case 'E':
                limparEcra();
                puts("\t\t\t*********************************************");
                puts("\t\t\t\tPara saber o lugar mais perto de si - P/p");
                puts("\t\t\t\tEscolher lugar - L/l");
                puts("\t\t\t\tLugar reservado - R/r");
                puts("\t\t\t*********************************************");
                scanf(" %c",&opE);
                switch(opE){//o utilizador é rederecionado para a opção que escolheu
                    case 'p':
                    case 'P':
                            lugarMaisPerto(parque1,parque2);
                            break;
                    case 'l':
                    case 'L':
                            lugaresDisponiveis(parque1,parque2);
                            estacionarCarro(parque1,parque2,&total);
                            mostraParque(parque1,parque2);
                            break;
                    case 'r':
                    case 'R':
                            estacionarCarroReservado(parque1,parque2);
                            break;
                }   
        }
        
    }while(opUt!= 'S' && opUt!= 's');//o menu não termina enquanto não for introduzido o caracter para sair
    limparEcra();
}

void menuAdministrador(int parque1[DIM][DIM],int parque2[DIM][DIM],ESTACIONAMENTO *carro,int *total){
    /**
     * permite ao administrador interagir de forma simples com o programa
     * @param parque1 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param parque2 a função recebe a variavel parque1 que se refere ao piso 1 do parque de estacionamento
     * @param carro a função recebe a estrutura carro
     * @param total a função recebe uma variável total onde é armazenada o número total de carros estacionados no parque
     */
    limparEcra();
    char opAd;
    char c[20];
    char v[20];
    printf("Introduza o nome do utilizador: ");
    scanf("%s",&c);//o administrador tem que introduzir o seu nome de utilizador
    printf("Introduza a palavra pass: ");
    scanf("%s",&v);//o administrador tem que introduzir a sua palavra passe
    
    if(strcmp(c,ADMIN)==0 && strcmp(v,PASS)==0)//se os dados tiverem corretos
    {
     do{
        do{//menu, o ciclo não termina enquanto não meter uma opção válida 
            puts("\t\t\t*********************************************");
            puts("\t\t\t***         MENU DE ADMINISTRADOR         ***");
            puts("\t\t\t*********************************************");
            puts("\t\t\t\tLugares disponíveis - D/d");
            puts("\t\t\t\tLugares inexistentes - I/i");
            puts("\t\t\t\tLugares reservados - G/g");
            puts("\t\t\t\tRegistos - R/r");
            puts("\t\t\t\tVer Parque - V/v");
            puts("\t\t\t\tSair - S/s"); 
            puts("\t\t\t*********************************************");
            scanf(" %c",&opAd);
        }while(opAd!= 'I' && opAd!= 'i' && opAd!= 'S' && opAd!= 's' && opAd!= 'D' && opAd!= 'd' && opAd!= 'G'
                && opAd!= 'g' && opAd!= 'R' && opAd!= 'r' && opAd!= 'V' && opAd!= 'v');
        switch(opAd){//após esta ser validade, o administrador é rederecionado para a opção que escolheu
            case 'v':
            case 'V':
                mostraParque(parque1,parque2);
                break;
            case 'd':
            case 'D':          
                lugaresDisponiveis(parque1,parque2);
                break;
            case 'i':
            case 'I':
                lugarInexistente(parque1,parque2);
                break;    
            case 'g':
            case 'G':
                reservarCarro(parque1,parque2);
                break;
            case 'r':
            case 'R':
                lerDados(carro,total);
                escreverDados(carro, total);
                break;

        }
    }while(opAd != 'S' && opAd!= 's');
        
    } else{//se os dados tiverem incorretos
        limparEcra();
        puts("Nome de utilizador ou palavra-passe incorretos");
    }
}

void parqueEstacionamento()
{
    //declaração das duas matrizes correspondeste aos dois pisos e de estruturas e variáveis
    int parque1[DIM][DIM];
    int parque2[DIM][DIM];
    ESTACIONAMENTO carro[NCARROS];
    int total;
    iniciaParque(parque1,parque2);//inicialiazação do parque
    char utad;
    do{
        do{//menu, o ciclo não termina enquanto não meter uma opção válida 
            puts("\t\t\t********************************************");
                puts("\t\t\t\tU/u - Utilizador");
                puts("\t\t\t\tA/a - Administrador");
                puts("\t\t\t\tS/s - Sair");
                puts("\t\t\t********************************************");
                scanf(" %c",&utad);
        }while(utad != 'u' && utad != 'U' && utad != 'a' && utad != 'A' && utad !='s' && utad !='S');
        switch(utad){//após esta ser validade, o utilziador é rederecionado para a opção que escolheu
                        case 'u':
                        case 'U':
                            limparEcra();
                            menuUtilizador(parque1,parque2);
                            break;
                        case 'a':
                        case 'A':
                            limparEcra();
                            menuAdministrador(parque1,parque2,carro,&total);
                            break;           
                    } 
    }while(utad != 's' && utad != 'S');//o programa termina com o caracter 'S' ou 's' que significa sair    
    
}

    int main()
    {
        parqueEstacionamento();
    }