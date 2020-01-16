/* 
 * File:   parking.c
 * Author: João Moreira & Carlos Barros
 *
 * Created on 22 de Novembro de 2017, 9:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <math.h>

void menuUtilizador(){
    char opUt;
    do{
        do{
            printf("\t\t\t*************************************************\n");
            printf("\t\t\t*****          MENU DE UTILIZADOR           *****\n");
            printf("\t\t\t\tOpção Pagamento - P\n");
            printf("\t\t\t\tOpção Estacionamento - E\n");
            printf("\t\t\t\tOpção Sair - S\n"); 
            printf("\t\t\t*************************************************\n\n\n");
            scanf(" %c",&opUt);
        }while(opUt != 'P' && opUt != 'E' && opUt!= 'S');
        switch(opUt){
            case 'P':
                printf("Escolheu a opção Pagamento\n");
                break;
            case 'E':
                printf("Escolheu a opção de Estacionamento\n");
                break;
            case 'S':
                printf("Até logo");
                break;
        }
    }while(opUt != 'S');
}
void menuAdministrador(){
    char opAd;
    do{
        do{
            printf("\t\t\t****************************************\n");
            printf("\t\t\t*****          MENU ADMIN          *****\n");
            printf("\t\t\t\tOpção Registos - R\n");
            printf("\t\t\t\tOpção  - Lugares Disponíveis\n");
            printf("\t\t\t\tOpção Sair - S\n"); 
            printf("\t\t\t****************************************\n\n\n");
            scanf(" %c",&opAd);
        }while(opAd= 'R' && opAd != 'L' && opAd!= 'S');
        switch(opAd){
            case 'R':
                printf("Escolheu a opção Pagamento\n");
                break;
            case 'L':
                printf("Escolheu a opção de Estacionamento\n");
                break;
            case 'S':
                printf("Até logo");
                break;
        }
    }while(opAd != 'S');
}
void userMenu(){
    char opUt;
    do{
        do{
            printf("\t\t\t******************************************\n");
            printf("\t\t\t*****          USER's MENU           *****\n");
            printf("\t\t\t\tOption Payment - €\n");
            printf("\t\t\t\tOption  - X\n");
            printf("\t\t\t\tOption EXIT - E\n"); 
            printf("\t\t\t******************************************\n\n\n");
            scanf(" %c",&opUt);
        }while(opUt != 'P' && opUt != 'X' && opUt!= 'E');
        switch(opUt){
            case 'P':
                printf("You select the payment option\n");
                break;
            case 'X':
                printf("Escolheu a opção de Estacionamento\n");
                break;
            case 'E':
                printf("See you soon");
                break;
        }
    }while(opUt != 'E');
}
void adminMenu(){
    char opAd;
    do{
        do{
            printf("\t\t\t******************************************\n");
            printf("\t\t\t*****          ADMIN's MENU          *****\n");
            printf("\t\t\t\tOption Registers - R\n");
            printf("\t\t\t\tOption  - Available Place - A\n");
            printf("\t\t\t\tOption EXIT - E\n"); 
            printf("\t\t\t******************************************\n\n\n");
            scanf(" %c",&opAd);
        }while(opAd= 'R' && opAd != 'A' && opAd!= 'E');
        switch(opAd){
            case 'R':
                printf("Escolheu a opção Pagamento\n");
                break;
            case 'A':
                printf("Escolheu a opção de Estacionamento\n");
                break;
            case 'E':
                printf("See you soon");
                break;
        }
    }while(opAd != 'E');
}
int main(int argc, char** argv) {
    char language,tipoUtilizador;
    printf("Português\n");
    printf("English\n");
    scanf(" %c",&language);
    switch(language){
            case 'p':
            case 'P':
                printf("Utilizador - U\n");
                printf("Administrador - A\n");
                scanf(" %c",&tipoUtilizador);
                    switch(tipoUtilizador){
                        case 'u':
                        case 'U':
                            menuUtilizador();
                            break;
                        case 'a':
                        case 'A':
                            menuAdministrador();
                            break;           
                }
                break;
            case 'e':
            case 'E':
                printf("User - U\n");
                printf("Admin - A\n");
                scanf(" %c",&tipoUtilizador);
                    switch(tipoUtilizador){
                        case 'u':
                        case 'U':
                            userMenu();
                            break;
                        case 'a':   
                        case 'A':
                            adminMenu();
                            break;    
                }
                break;
    }
}