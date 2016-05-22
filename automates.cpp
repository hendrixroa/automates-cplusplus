#include <iostream>
#include <fstream>
using namespace std;

string M1,M2,CAD,RES;

	void ReconocerCadena(string M1,string M2, string CAD, string& RES){
	int i,j1=0,j2=0,k=0,tamCad,tamM1,tamM2;
	tamCad = CAD.length();
	tamM1 = M1.length();
	tamM2 = M2.length();
	
		for(i=0;i<tamCad;i++){
	     
		if(CAD[k]==M1[j1] || CAD[k]==M2[j2]){//CASO QUE RECONOCEMOS POR AMBOS LADOS
			k++;
			if((CAD[k]==M1[j1])==true){
				j1++;
			} else if ((CAD[k]==M2[j2])==true){
			      j2++;
			}
		}
		
		if(CAD[k]==' ' || (M1[j1]=='0' || M1[j1]=='1' || M2[j2]=='1' || M2[j2]=='0')){//CASO EN QUE ESTAMOS EN ESPACIO Y NOS VAMOS AL INICIO 
			k++;
			j1=j2=0;
		}
		
		if(CAD[k]==' ' || (j1==(tamM1+1) || j2==(tamM2+1))){//caso en que estamos en espacio y ya reconocimos la cadena
			k++;
			int iterbuf = k;
			while(CAD[iterbuf] != ' '){//guardo en res todo lo que esta despues de la cadena que reconozco 
				RES = RES + CAD[iterbuf];
				iterbuf++;
			}
			return;
		}	
	 }	
	}	

	int main(){
		
		fstream file,fileout;
			file.open("tarea4.in",ios::in);
			fileout.open("Hendrix_Roa.out",ios::out);
				if(!file.is_open()){
				cout <<"El archivo no se puede abrir"<<endl;
			}else{
					while(!file.eof()){
					file >> M1;
					file >> M2;
					file.ignore();
					getline(file,CAD);
					if(file.eof()){
						break;
					}
				    ReconocerCadena(M1,M2,CAD,RES);
				    fileout <<RES <<endl;
					RES=M1=M2=CAD="";
					}		
			}
			file.close();
			fileout.close();
	return 0;
	}
