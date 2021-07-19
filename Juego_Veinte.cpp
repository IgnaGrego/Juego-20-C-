#include<iostream>
#include"rlutil.h"
#include<cstdlib>
#include<ctime>
using namespace std;

int dadosAzar(int v[], int tam, int limite){
    srand(time(NULL));
    int i;
    for(i=0; i<tam; i++){
                v[i]=(rand()%limite)+1;
                cout << v[i] << endl;
    }
}

int dadosSimulados(int v[], int tam, int limite){
    srand(time(NULL));
    int i,valorDado;
    for(i=0; i<tam; i++){
                cout<<"-------------"<<endl;
                cout<<"Indicar valor del dado "<<i+1<<" de "<<tam<<endl;
                cin>>valorDado;
                v[i]=valorDado;
    }
}

int primerTiroSimulado (int v[], int tam, int limite, int nJ[]){

    int i,j,valorDado,tecla,maxNum;
    nJ[0]=0;

    for(j=1; j<=5;j++){
        maxNum=0;
        for(i=0; i<tam; i++){
            cout<<"-------------"<<endl;
            cout<<"Indicar valor del dado "<<i+1<<" de "<<tam<<endl;
            cin>>valorDado;
            v[i]=valorDado;
            if(v[i]>maxNum){
                maxNum=v[i];
            }
        }
        nJ[0]+=maxNum;
        tam-=1;
    }

    cout<<"--------------" <<endl;
    cout<<"NUMERO OBTENIDO EN PRIMER TIRO: " <<endl<< nJ[0]<<endl;
}

int primerTiro(int v[], int tam, int limite, int nJ[]){
    int i,j, tecla,maxNum=0;
    srand(time(NULL));
    nJ[0]=0;

    cout<<"--------------"<<endl;
    cout<<"Escribi cualquier tecla para tirar dados."<<endl;
    cout<<"--------------"<<endl;

    for(j=1; j<=5;j++){
        maxNum=0;
        rlutil::anykey();
        cout<<"--------------"<<endl;
        for(i=0; i<tam; i++){
            v[i]=(rand()%limite)+1;
            cout << v[i] << endl;
            if(v[i]>maxNum){
                maxNum=v[i];
            }
        }
        nJ[0]+=maxNum;
        tam-=1;
    }
    cout<<"--------------" <<endl;
    cout<<"NUMERO OBTENIDO EN PRIMER TIRO: "<< nJ[0]<<endl;
}

int generadorPuntos(int nJugador[], int vectorDado[]){
int i;
    for(i=0;i<=6;i++){
        if((nJugador[0]==20)&&(vectorDado[i]==1)){
            nJugador[1]+=1;

        }if((nJugador[0]==21)&&(vectorDado[i]==2)){
            nJugador[1]+=1;

        }if((nJugador[0]==22)&&(vectorDado[i]==3)){
            nJugador[1]+=1;

        }if((nJugador[0]==23)&&(vectorDado[i]==4)){
            nJugador[1]+=1;

        }if((nJugador[0]==24)&&(vectorDado[i]==5)){
            nJugador[1]+=1;

        }if((nJugador[0]>=25)&&(vectorDado[i]==6)){
            nJugador[1]+=1;
        }
    }


}
int tiroDePuntajeSim(int vec[],int tam,int nJ[]){

    int i,j,nPuntaje=1,tamDados=5;
    srand(time(NULL));
    nJ[1]=0;

    cout<<"--------------"<<endl;
    cout<<"ESCRIBI CUALQUIER TECLA PARA REALIZAR EL TIRO DE PUNTAJE"<<endl;

    rlutil::anykey();

    cout<<"--------------"<<endl;

    dadosSimulados(vec,tam,6);
    generadorPuntos(nJ,vec);

    cout<<"--------------"<<endl;
    cout<<"TIRO DE PUNTAJE:"<<nJ[1]<<endl;
    cout<<"--------------"<<endl;




}

int puntajeDeRondas(int numeroJ[], int rJuego[]){

    if(numeroJ[0]==0){
        rJuego[0]+=1;
    }

    if(numeroJ[0]<0){
        rJuego[1]+=1;
    }


}

int tiroDePuntaje(int vec[],int tam,int nJ[]){

    int i,j;
    srand(time(NULL));
    nJ[1]=0;

    cout<<"--------------"<<endl;
    cout<<"ESCRIBI CUALQUIER TECLA PARA REALIZAR EL TIRO DE PUNTAJE"<<endl;

    rlutil::anykey();

    cout<<"--------------"<<endl;

    dadosAzar(vec,tam,6);
    generadorPuntos(nJ,vec);

    cout<<"--------------"<<endl;
    cout<<"TIRO DE PUNTAJE:"<<endl;

    cout<<nJ[1]<<endl;

    cout<<"--------------"<<endl;
}

int main(){

    int vec[6], apuesta, modo,total,rondasAJugar,nRonda=1,cUltimaRonda,i;
    string nombreJugador;
    int nJugador[3]={0};
    int puntajeJugador[2]={0};
    int rondas[2]={0};

    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::MAGENTA);

    rlutil::cls();

    cout<<"SELECCIONAR MODO"<<endl;
    cout<<"--------------"<<endl;
    cout<<"1 - UN JUGADOR"<<endl;
    cout<<"2 - MODO SIMULADO"<<endl;
    cout<<"0 - FINALIZAR PROGRAMA"<<endl;
    cout<<"--------------"<<endl;
    cin>>modo;



        switch(modo){

            case 1:
                cout<<"--------------"<<endl;
                cout<<"Ingresar nombre del jugador: "<<endl;
                cout<<"             "<<endl;
                cin>>nombreJugador;

                cout<<"             "<<endl;
                cout<<"?Cuantas rondas queres jugar?"<<endl;
                cin>>rondasAJugar;

                for(i=1;i<=rondasAJugar;i++){

                        cUltimaRonda=rondasAJugar-1;
                        puntajeJugador[0]=0;

                        cout<<"       "<<endl;
                        cout<<"Ronda N°: "<<i<<endl;
                        cout<<"       "<<endl;

                        cout<<"             "<<endl;
                        cout<<"Que cantidad queres apostar?"<<endl;
                        cout<<"         "<<endl;
                        cin>>apuesta;
                        cout<<"             "<<endl;
                        nJugador[2]=apuesta;

                        primerTiro(vec,5,6,nJugador);
                        if(nJugador[0]>=20){
                            tiroDePuntaje(vec,5,nJugador);
                            total=nJugador[1]*nJugador[2];
                            puntajeJugador[0] += total;
                        }

                        if(nJugador[0]<20){
                            cout<<"   "<<endl;
                            cout<<"No corresponde tiro de puntaje."<<endl;
                            cout<<"   "<<endl;
                            puntajeJugador[0] -= nJugador[2];
                        }


                        cout<<"--------------"<<endl;
                        cout<<"Puntaje de la ronda: "<<puntajeJugador[0]<<endl;
                        cout<<"--------------"<<endl;
                        cout<<"   "<<endl;

                        puntajeDeRondas(puntajeJugador,rondas);

                        puntajeJugador[1]+=puntajeJugador[0];

                        if(i<cUltimaRonda){
                            cout<<"ESCRIBI UNA TECLA PARA JUGAR LA PROXIMA RONDA"<<endl;
                            cout<<"   "<<endl;
                            rlutil::anykey();
                            cout<<"   "<<endl;
                        } if(i==cUltimaRonda){
                            cout<<"ESCRIBI UNA TECLA PARA JUGAR LA ULTIMA RONDA"<<endl;
                            cout<<"   "<<endl;
                            rlutil::anykey();
                            cout<<"   "<<endl;
                        }


                }

                cout<<"PUNTAJE TOTAL PARA "<<nombreJugador<<": "<<puntajeJugador[1]<<endl;
                cout<<"          "<<endl;

                cout<<"TOTAL RONDAS SIN PUNTOS: "<<rondas[0]<<endl;
                cout<<"      "<<endl;
                cout<<"TOTAL RONDAS CON PERDIDA DE PUNTOS: "<<rondas[1]<<endl;
                cout<<"      "<<endl;
                break;


            case 2:

                cout<<"--------------"<<endl;
                cout<<"Ingresar nombre del jugador: "<<endl;
                cout<<"             "<<endl;
                cin>>nombreJugador;

                cout<<"             "<<endl;
                cout<<"?Cuantas rondas queres jugar?"<<endl;
                cin>>rondasAJugar;

                for(i=1;i<=rondasAJugar;i++){

                    cUltimaRonda=rondasAJugar-1;

                    cout<<"       "<<endl;
                    cout<<"Ronda N°: "<<i<<endl;
                    cout<<"       "<<endl;

                    puntajeJugador[0]=0;

                    cout<<"Que cantidad queres apostar?"<<endl;
                    cout<<"     "<<endl;
                    cin>>apuesta;
                    nJugador[2]=apuesta;

                    primerTiroSimulado(vec,5,6,nJugador);

                    if(nJugador[0]>=20){
                        tiroDePuntajeSim(vec,5,nJugador);
                        total=nJugador[1]*nJugador[2];
                        puntajeJugador[0] += total;
                    }

                    if(nJugador[0]<20){
                        cout<<"   "<<endl;
                        rlutil::setColor(rlutil::RED);
                        cout<<"NO CORRESPONDE TIRO DE PUNTAJE."<<endl;
                        rlutil::setColor(rlutil::MAGENTA);
                        cout<<"   "<<endl;
                        puntajeJugador[0] -= nJugador[2];
                    }

                cout<<"   "<<endl;
                cout<<"Puntaje de la ronda:"<<puntajeJugador[0]<<endl;
                cout<<"   "<<endl;

                puntajeDeRondas(puntajeJugador,rondas);

                puntajeJugador[1]+=puntajeJugador[0];

                if(i<cUltimaRonda){
                        cout<<"ESCRIBI UNA TECLA PARA JUGAR LA PROXIMA RONDA"<<endl;
                        cout<<"   "<<endl;
                        rlutil::anykey();
                        cout<<"   "<<endl;
                } if(i==cUltimaRonda){
                        cout<<"ESCRIBI UNA TECLA PARA JUGAR LA ULTIMA RONDA"<<endl;
                        cout<<"   "<<endl;
                        rlutil::anykey();
                        cout<<"   "<<endl;
                }

                }

                cout<<"      "<<endl;
                cout<<"PUNTAJE TOTAL PARA "<<nombreJugador<<": "<<puntajeJugador[1]<<endl;
                cout<<"      "<<endl;

                cout<<"TOTAL RONDAS SIN PUNTOS: "<<rondas[0]<<endl;
                cout<<"      "<<endl;
                cout<<"TOTAL RONDAS CON PERDIDA DE PUNTOS: "<<rondas[1]<<endl;
                cout<<"      "<<endl;


                break;

            case 0:
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::YELLOW);
                rlutil::cls();
                cout<<"!Muchas gracias por jugar!"<<endl;
                break;

            default:
                rlutil::setColor(rlutil::RED);
                cout<<" OPCION INCORRECTA "<<endl;
                rlutil::setColor(rlutil::MAGENTA);
                cin>>modo;
                break;
        }
    system ("pause");
    return 0;
    }
