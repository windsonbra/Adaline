#include <iostream>
#include <cstdlib>

using namespace std;

class Adaline
{
public:

    int epoca;
    int maximoDeEpocasPermitido;
    int numeroDePesos;
    double *vetorDePesos;
    double taxaDeAprendizagem;
    double bias;
    int numeroDeParesDeEntradas;
    double **matrizDeEntradas;
    double *vetorDeSaidasEsperadas;
    double *erros;

    Adaline();
    void inicializarVariaveisInternas();
    void inicializarVetorDeSaidasEsperadas();
    void inicializarMatrizDeEntradas();
    void treinar();
    double atingiuLimiar(double,double);
    void calcularErros(int,double);
    void corrigirPeso();
    void testar();
    void print();
};
