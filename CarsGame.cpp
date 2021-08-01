#include <iostream>
#include <string>
#include<stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;


class Auto{
	
	public:		
	string Brand;
	string Specialty;
	string Color;
	int distancia=0;
	int distanciadelapista=0;
	int llego=0;
	
	Auto(){
		
	}
	
	void avanzar(int km){				
		
		distancia=distancia+km;
		
		if(distancia>this->distanciadelapista){
			llego=1;
		}
	
	}	
};


class Player{    	
		
	public:	
    
		string NickName;
		string ShoutVictory;		
		int llegoalameta=0;
		Auto *Carro;
        Player *liga;
		
		Player(string NickName,string ShoutVictory){
			this->NickName=NickName;			
			this->ShoutVictory=ShoutVictory;
		}	

		void SetAuto(Auto Carro){
			Carro=Carro;
			cout<<"mi cacrro es un "<<Carro.Brand;
		}

		~Player(){

		}

		void Saludar(){
			cout<<"hola soy "<<NickName;

		}


        void ResetName(string NickName){
            this->NickName=NickName;

        }
        
         int mostrarDistancia(){  	        
        	cout<<"mi distancia parcial es de: "<<Carro->distancia;
		}		
};



class CarsTrack{
	
	public:
	string City;
	int Distance;
	string Ground;
	int ban=1;
	
	
		CarsTrack(){			
			int opcion=0;			
			do{
			
				cout<<"SELECCION CIUDAD PARA LA CARRERA"<<endl;
				cout<<"\n\t1-  Cartagena"<<endl;
				cout<<"\n\t2-  Medellin"<<endl;
				cout<<"\n\t3-  Bogota"<<endl;				
				cin>>opcion;				
			
				switch(opcion){
				
					case 1: 
						this->City="Cartagena";
						this->Distance=50;
						ban=0;		
					break;
					
					
					case 2: 
						this->City="Medellin";
						this->Distance=100;
						ban=0;
					break;
					
					
					case 3:
						this->City="Bogota";
						this->Distance=150;
						ban=0;
					break;			
					
					default:
					cout<<"\n OPCION NO VALIDA"<<endl;		
				}
			}while(ban==1);
			
			cout<<"CIRCUITO DE "<<City<<endl;
			cout<<"Distancia DE "<<Distance<<endl;
		}	
		
		
		void MostrarPista(){
			
			cout<<"Circuito de : "<<this->City;
			cout<<"Distancia total: "<<this->Distance<<"km"<<endl;
			//cout<<"Distancia total: "<<CarsTrack.Distance<<"km";
			
		}	
		
		int EntregarDistancia(){			
			float d=0;
			return this->Distance; 
		}
	
};



class Podio{
	
	Player *primero;
	Player *segundo;
	Player *tercero;	
	

	Podio();
	
	void Ganadores(){
		
		
			cout<<" PRIMER PUESTO "<<primero->NickName;
			cout<<" SEGUNDO PUESTO "<<segundo->NickName;
			cout<<" TERCER PUESTO"<<tercero->NickName;
	}


};



Player *cabezera=NULL;
Player *buscar_principio(Player *L);
void OrganizarJugadores(Player *L);
void recorrido(Player *L);
void insertar(Player *L,Player *pos,string N,string grito);
void iniciarJuego();
int NumeroAleatoreo();

int main(){	
	
	iniciarJuego();	
	return 0;

}

void insertar(Player *L,Player *pos,string N,string grito){	
	Auto *Autox=new Auto();
	Player *nuevo=NULL;
	nuevo=(Player *)malloc(sizeof(Player));	
	nuevo->Carro=Autox;
		
	
	//cout<<"direccion de memoria de nuevo: "<<&nuevo<<endl;
	//cout<<"donde apunta nuevo:"<<nuevo<<endl;	
	//cout<<"nombre por parametro"<<N<<endl;
	//cout<<"grito por parametro"<<grito<<endl;		
	nuevo->NickName=N;
	cout<<"Nombre--->"<<nuevo->NickName<<endl;
	nuevo->ShoutVictory=grito;
	cout<<"Grito de festejo nuevo--->"<<nuevo->ShoutVictory<<endl;			
	nuevo->liga=NULL;	
	
	if(pos==NULL){
	
		nuevo->liga=L;
		cabezera=nuevo;
	}	
	
	else
	{
		nuevo->liga=pos->liga;
		pos->liga=nuevo;
	}	
	
}

Player *buscar_principio(Player *L){		

	Player *ultimo=NULL;
	Player *p=L;
	
	while(p!=NULL){		
	
		
		ultimo=p;
		p=p->liga;		
	}
	return ultimo;	
}


void OrganizarJugadores(Player *L){	
	
	int cantidad;
    string NickName;
	string ShoutVictory;    
	int i=0;	
	cout<<"\ndigite la cantidad de jugadores: ";
	cin>>cantidad;
	
	while(i<cantidad){
		
		cout<<"Jugador # "<<i+1<<endl;
		cout<<"\ningresa tu NickName: "<<endl;		
		cin>>NickName;

  
        cout<<"Tu grito de victoria!"<<endl;
        cin>>ShoutVictory;	 	
	
		Player *y=NULL;
		y=buscar_principio(cabezera);
		
		cout<<y;
		insertar(cabezera,y,NickName,ShoutVictory);
		i++;
	}		
	
} 



void recorrido(Player *L){


	if(L==0){
		cout<<"NO HAY JUGADORES"<<endl;
	}
	else{
		
		Player *recorre=NULL;
		recorre=L;
		
		cout<<"-------------------------------"<<endl;
		cout<<"LISTA DE JUGADORES"<<endl;
		
		while(recorre!=0){			
			cout<<"\n";
			cout<<"NOMBRE : "<<recorre->NickName<<endl;
			recorre->mostrarDistancia();
			recorre=recorre->liga;
		}		
	}
	
	
}


int numeroAleatoreo(){
	
	int numero;
	numero = rand () % (6-1+1) + 1;  

return numero;

}


void iniciarJuego(){	
	
	int distanciapista=0;	
	OrganizarJugadores(cabezera);	
	recorrido(cabezera);
	CarsTrack *PISTA=new CarsTrack();		
	distanciapista=PISTA->Distance;
		
}






