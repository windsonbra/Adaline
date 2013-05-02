#include "Adaline.h"

Adaline::Adaline()
{
    inicializarVariaveisInternas();
};

void Adaline::inicializarVariaveisInternas()
{

    epoca=0;
    maximoDeEpocasPermitido=100;

    numeroDePesos=2;

    vetorDePesos=new double[numeroDePesos];

    taxaDeAprendizagem=1;

    srand (time(NULL));

    bias=((rand() % 1000000 + 1)/1000000.000000);

    //inicializa vetor de pesos aleatoriamente
    for(int i=0; i<numeroDePesos; i++)
    {
        vetorDePesos[i]=((rand() % 1000000 + 1)/1000000.000000);
    }

    numeroDeParesDeEntradas=4;

    inicializarMatrizDeEntradas();
    inicializarVetorDeSaidasEsperadas();

    erros=new double[numeroDeParesDeEntradas];

};



void Adaline::inicializarMatrizDeEntradas()
{
    matrizDeEntradas=new double*[numeroDeParesDeEntradas];

    for(int i=0; i<numeroDeParesDeEntradas; i++)
    {
        matrizDeEntradas[i]=new double[2];
    }

    matrizDeEntradas[0][0]=0; // entrada 1
    matrizDeEntradas[0][1]=0; // entrada 2

    matrizDeEntradas[1][0]=0; // entrada 1
    matrizDeEntradas[1][1]=1; // entrada 2

    matrizDeEntradas[2][0]=1; // entrada 1
    matrizDeEntradas[2][1]=0; // entrada 2

    matrizDeEntradas[3][0]=1; // entrada 1
    matrizDeEntradas[3][1]=1; // entrada 2

}

void Adaline::inicializarVetorDeSaidasEsperadas()
{
    vetorDeSaidasEsperadas=new double[numeroDeParesDeEntradas];

    vetorDeSaidasEsperadas[0]=0; //Saída para entrada (0,0)
    vetorDeSaidasEsperadas[1]=0; //Saída para entrada (1,0)
    vetorDeSaidasEsperadas[2]=0; //Saída para entrada (0,1)
    vetorDeSaidasEsperadas[3]=1; //Saída para entrada (1,1)
    //Todas as saída formam uma porta AND
}

void Adaline::treinar()
{
    //variavel que recebe o valor da saida do limiar
    double saidaDoLimiar;

    for(int i=0; i<numeroDeParesDeEntradas; i++)
    {
        //A saída recebe o resultado
        saidaDoLimiar = atingiuLimiar(matrizDeEntradas[i][0],matrizDeEntradas[i][1]);
        calcularErros(i,saidaDoLimiar);
        //if(saidaDoLimiar !=vetorDeSaidasEsperadas[i]) {
        //  corrigirPeso(i,saidaDoLimiar);
    }

    print();
    corrigirPeso();
    epoca++;

    if(epoca < maximoDeEpocasPermitido && ((vetorDePesos[0]+vetorDePesos[1]+bias)!=1))
    {
        // chamada recursiva do método
        treinar();

    }
}


double Adaline::atingiuLimiar(double x1,double x2)
{
    double somatorio = x1*vetorDePesos[0] + x2*vetorDePesos[1] + bias;

    if(somatorio>0)
        return somatorio;
    else
        return somatorio;
}

void Adaline::calcularErros(int i,double somatorio)
{

    erros[i]=vetorDeSaidasEsperadas[i]-somatorio;

}

void Adaline::corrigirPeso()
{
    double z;
    for(int i=0; i<numeroDePesos; i++)
    {
        z=0;
        for(int j=0; j<numeroDeParesDeEntradas; j++)
        {
            z+=erros[j]*matrizDeEntradas[j][i];
        }
        vetorDePesos[i] += (taxaDeAprendizagem * z);
        bias+= (taxaDeAprendizagem * z);
    }
}
void Adaline::testar()
{
    cout << "\n\nTeste:\n";
    cout << "Entrada (0,0): " << atingiuLimiar(0,0) << endl;
    cout << "Entrada (0,1): " << atingiuLimiar(0,1) << endl;
    cout << "Entrada (1,0): " << atingiuLimiar(1,0) << endl;
    cout << "Entrada (1,1): " << atingiuLimiar(1,1) << endl;

    cout << "Numero de epocas: " << epoca << endl;

}

void Adaline::print()
{
    cout << "-----------------\n";
    cout << "Epoca: " << epoca << endl;
    cout << "Bias: " << bias << endl;
    cout << "Peso w1: " << vetorDePesos[0] << endl;
    cout << "Peso w2: " << vetorDePesos[1] << endl;
    cout << "-----------------\n";

}
