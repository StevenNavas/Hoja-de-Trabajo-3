/*Un empresa que se dedica a la venta de seguros de vehiculos, calcula el importe
según el modelo y color del automovil, asi como la edad del conductor.

Modelo       Color             Precio
A              Blanco           240.50
                  Metalizado    330.00
                Otros             270.50
B               Blanco          300.00
                 Metalizado     360.50
                 Otros             330.00
            
Incremento de precio
Edad            % Incremento
<31                    25%
Entre 31 y 65    0%
>65                   30%

Determine el importe a pagar mostrandolo en pantalla según los datos del vehículo (modelo y color) 
y la edad del conductor.

Grabe los datos a un archivo.*/


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
struct seguro{
	string modelo;
	string color;
	float precio;
	int edad;
};
void mp();
void leer_archivo();
void grabar_archivo();
int main(){
	mp();
}

void mp(){ // menu principal
	
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Seguros de Vehiculos"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar seguro "<<"\n";
		cout<<" 2 - Mostrar seguros "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}

void grabar_archivo(){
	//variables basadas en la estructura
	string modelo;
	string color;
	int edad;
	float precio;
	float incremento;
	fflush(stdin);
	cout<<"Ingrese modelo del auto: "<<endl;
	getline(cin,modelo);
	fflush(stdin);
	cout<<"Ingrese color: "<<endl;
	getline(cin,color);
	cout<<"Ingrese la edad del asegurado: "<<endl;
	cin>>edad;
	
	ofstream archivo; //leer archivo 
	archivo.open("seguro.txt",ios::app);
	
	if(edad < 31)
		incremento = 0.25;
	else if(edad >= 31 and edad <=65)
		incremento = 0;
	else if(edad > 65)
		incremento = 30;
	
	if(modelo == "a")
	{
		if(color == "blanco"){
			precio = 240.50 * (1+ incremento);
		}else if(color == "metalizado"){
			precio = 330 * (1+ incremento);
		}else{
			precio = 270.50 * (1+ incremento);
		}
	}else if(modelo == "b"){
		if(color == "blanco"){
			precio = 300.00 * (1+ incremento);
		}else if(color == "metalizado"){
			precio = 360.50 * (1+ incremento);
		}else{
			precio = 330.00 * (1+ incremento);
		}
	}
		
	//archivo.open(na.c_str(),ios::app);
	archivo<<modelo<<"\t"<<color<<"\t"<<edad<<"\t"<<precio<<endl;
	archivo.close();
	
}
void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("seguro.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	float sumatoriasalarial=0.00;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); //break;
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	seguro recordset[lineas];
	
	archivo.open("seguro.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        //cout<<"i: "<<i;
        archivo>>recordset[i].modelo>>recordset[i].color>>recordset[i].edad>>recordset[i].precio;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].modelo<<" "<<recordset[i].color<<" "<<recordset[i].edad<<" "<<recordset[i].precio<<endl;
    	sumatoriasalarial+=recordset[i].precio;
	}
	cout<<"Sumatorial total: "<<sumatoriasalarial;
	system("PAUSE");
}
