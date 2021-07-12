#include<iostream>
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

    for(j=1; j<=5;j++){
        maxNum=0;
        cout<<"--------------"<<endl;
        cout<<"Escribi un numero para tirar dados."<<endl;
        cout<<"--------------"<<endl;
        cin>>tecla;
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
    cout<<"NUMERO OBTENIDO EN PRIMER TIRO: " <<endl<< nJ[0]<<endl;
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

    int i,j, tecla,nPuntaje=1,tamDados=5;
    srand(time(NULL));
    nJ[1]=0;

    cout<<"--------------"<<endl;
    cout<<"ESCRIBI UN NUMERO PARA REALIZAR EL TIRO DE PUNTAJE"<<endl;

    cin>>tecla;

    cout<<"--------------"<<endl;

    dadosSimulados(vec,tam,6);
    generadorPuntos(nJ,vec);

    cout<<"--------------"<<endl;
    cout<<"TIRO DE PUNTAJE:"<<endl;

    cout<<nJ[1]<<endl;

    cout<<"--------------"<<endl;




}

int tiroDePuntaje(int vec[],int tam,int nJ[]){

    int i,j, tecla;
    srand(time(NULL));
    nJ[1]=0;

    cout<<"--------------"<<endl;
    cout<<"ESCRIBI UN NUMERO PARA REALIZAR EL TIRO DE PUNTAJE"<<endl;

    cin>>tecla;

    cout<<"--------------"<<endl;

    dadosAzar(vec,tam,6);
    generadorPuntos(nJ,vec);

    cout<<"--------------"<<endl;
    cout<<"TIRO DE PUNTAJE:"<<endl;

    cout<<nJ[1]<<endl;

    cout<<"--------------"<<endl;
}

int main(){
    //MODO UN JUGADOR
    int vec[6], apuesta, modo,botonDeJuego,total;
    string nombreJugador;
    int nJugador[3]={0};
    int puntajeJugador[2]={0};

    cout<<"SELECCIONAR MODO"<<endl;
    cout<<"--------------"<<endl;
    cout<<"1 - UN JUGADOR"<<endl;
    cout<<"2 - DOS JUGADORES"<<endl;
    cout<<"3 - MODO SIMULADO"<<endl;
    cout<<"--------------"<<endl;
    cin>>modo;



        switch(modo){

            case 1:

                cout<<"--------------"<<endl;
                cout<<"Ingresar nombre del jugador: "<<endl;

                cin>>nombreJugador;

                botonDeJuego=modo;

                while (botonDeJuego !=0){

                puntajeJugador[0]=0;

                cout<<"--------------"<<endl;
                cout<<"Que cantidad queres apostar?"<<endl;

                cin>>apuesta;

                cout<<"--------------"<<endl;

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
                cout<<"Puntaje de la ronda:"<<endl;
                cout<<puntajeJugador[0]<<endl;
                cout<<"--------------"<<endl;
                cout<<"   "<<endl;

                puntajeJugador[1]+=puntajeJugador[0];

                cout<<"ESCRIBI UN NUMERO PARA VOLVER A JUGAR OTRA RONDA - 0 PARA FINALIZAR"<<endl;
                cin>>botonDeJuego;
                cout<<"   "<<endl;

                }

                system ("cls");

                cout<<"PUNTAJE TOTAL PARA "<<nombreJugador<<": "<<endl;
                cout<<puntajeJugador[1]<<endl;



            case 3:
                botonDeJuego=modo;

                cout<<"     "<<endl;
                cout<<"Ingresar nombre del jugador: "<<endl;
                cin>>nombreJugador;
                cout<<"     "<<endl;

                while (botonDeJuego !=0){

                cout<<"Que cantidad queres apostar?"<<endl;
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
                cout<<"No corresponde tiro de puntaje."<<endl;
                cout<<"   "<<endl;
                puntajeJugador[0] -= nJugador[2];
                }

                cout<<"   "<<endl;
                cout<<"Puntaje de la ronda:"<<endl;
                cout<<puntajeJugador[0]<<endl;
                cout<<"   "<<endl;
                cout<<"   "<<endl;

                puntajeJugador[1]+=puntajeJugador[0];

                cout<<"ESCRIBI UN NUMERO PARA VOLVER A JUGAR OTRA RONDA - 0 PARA FINALIZAR"<<endl;
                cin>>botonDeJuego;
                cout<<"   "<<endl;
                }

                system ("cls");
                cout<<"PUNTAJE TOTAL PARA "<<nombreJugador<<": "<<endl;
                cout<<puntajeJugador[1]<<endl;
        }
    system ("pause");
    return 0;
    }


