#include <iostream>
#include <cstring>
using namespace std;

int Pretvorba(char* polje, int i){
	return int((polje[i]-64)%10);
}
int main(){	

	char dokument[50],trazena[20];
	int N,M;
	
	cout<<"Unesi niz znakova bez razmaka: ";
	cin.getline(dokument,50);
	cout<<"Unesi trazenu rijec: ";
	cin.getline(trazena,20);
	N=strlen(dokument);
	M=strlen(trazena);
	
	long long int HashTrazena=0, HashDokument=0;
	int mnozi=1;
	
	for(int i=M-1;i>=0;i--){
		HashTrazena += Pretvorba(trazena,i) * mnozi;
		mnozi*=10;
	}
	
	mnozi=1;
	for(int i=M-1;i>=0;i--){
		HashDokument+=Pretvorba(dokument,i) * mnozi;
		mnozi*=10;
	}
	mnozi/=10;
	
	for(int i=1;i<=N-M+1;i++){
		if(HashDokument==HashTrazena){
			bool jednako = true;
			for(int j=0;j<M;j++){
				if(dokument[i+j-1] != trazena[j]){
					jednako = false;
				}	
			}
			if(jednako==true){
				cout<<"Podudaranje na indeksu "<<i-1<<endl;
			}
		}
		HashDokument=((HashDokument-(Pretvorba(dokument,i-1)*mnozi))*10)
					  + Pretvorba(dokument,i+M-1);			
	}	
}
