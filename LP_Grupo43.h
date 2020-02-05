
#ifndef LP_GRUPO43_H
#define LP_GRUPO43_H


#define DIM 5
#define LIM 5
#define limparBuffer while(getchar()!='\n')
#define DISTANCIAMAX 100
#define ADMIN "admin"
#define PASS "admin"
#define NCARROS 50
#define NCARROSRES 5
#define TAM 20

typedef struct{
    char mat[TAM];
    char marca[TAM];
    int piso;
    int x;
    int y;
    time_t t_tempoEntrada;
    time_t t_tempoSaida;
    
}ESTACIONAMENTO;

void parqueEstacionamento();
void menuAdministrador(int parque1[DIM][DIM],int parque2[DIM][DIM],ESTACIONAMENTO *carro,int *total);
void menuUtilizador(int parque1[DIM][DIM],int parque2[DIM][DIM]);
void escreverDados(ESTACIONAMENTO *carro, int *total);
void lerDados(ESTACIONAMENTO *carro, int *total);
void pagamento(int parque1[DIM][DIM],int parque2[DIM][DIM],ESTACIONAMENTO *carro,int total);
void lugarMaisPerto(int parque1[DIM][DIM],int parque2[DIM][DIM]);
void lugarMaisPerto2(int parque2[DIM][DIM]);
void lugarMaisPerto1(int parque1[DIM][DIM]);
void lugaresDisponiveis(int parque1[DIM][DIM],int parque2[DIM][DIM]);
void lugaresDisponiveis2(int parque2[DIM][DIM]);
void lugaresDisponiveis1(int parque1[DIM][DIM]);
void permiteReservar(int parque1[DIM][DIM],int parque2[DIM][DIM]);
int contaReservados(int parque1[DIM][DIM],int parque2[DIM][DIM]);
int contaReservados2(int parque2[DIM][DIM]);
int contaReservados1(int parque1[DIM][DIM]);
void reservarCarro(int parque1[DIM][DIM],int parque2[DIM][DIM]);
void reservarCarro2(int parque2 [DIM][DIM],int i);
void reservarCarro1(int parque1 [DIM][DIM],int i);
void estacionarCarroReservado(int parque1[DIM][DIM],int parque2[DIM][DIM]);
void estacionarCarro(int parque1[DIM][DIM],int parque2[DIM][DIM],int *total);
void estacionarCarro2(int parque2[DIM][DIM],ESTACIONAMENTO *carro,int *total);
void estacionarCarro1(int parque1[DIM][DIM],ESTACIONAMENTO *carro,int *total);
void lugarInexistente(int parque1[DIM][DIM],int parque2 [DIM][DIM]);
void lugarInexistente2(int parque1 [DIM][DIM]);
void lugarInexistente1(int parque1 [DIM][DIM]);
void tirarCarro(int parque1[DIM][DIM],int parque2[DIM][DIM],int *total);
void tirarCarro2(int parque2 [DIM][DIM],int *total);
void tirarCarro1(int parque1 [DIM][DIM],int *total);
void mostraParque(int parque1[DIM][DIM],int parque2[DIM][DIM]);
void mostraParque2(int parque2 [DIM][DIM]);
void mostraParque1(int parque1 [DIM][DIM]);
void iniciaParque(int parque1[DIM][DIM],int parque2[DIM][DIM]);
void iniciaParque2(int parque2[DIM] [DIM]);
void iniciaParque1(int parque1[DIM] [DIM]);
void limparEcra();


#endif /* LP_GRUPO43_H */

