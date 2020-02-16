#include "pch.h"
#include "funzioni.h"
#include <iostream>
using namespace std;


int main()
{
	palindromo *totale;
	string *elem, nomefile;
	int n, k = 0;
	cout << "Inserisci nome file: ";
	cin >> nomefile;

	n = trovaN(nomefile);

	//alloco mememoria per i due vettori 
	elem = new string[n];
	totale = new palindromo[n];

	caricaVet(nomefile, elem, n);

	//carico il vettore "totale" considerando solo i palindromi
	for (int i = 0; i < n; i++) {
		bool f = false;
		if (elem[i] == reverseString(elem[i])) {
			//siamo di fronte ad un palindromo, verifico se è già presente un palindromo uguale
			for (int j = 0; j < k; j++) {
				if (elem[i] == totale[j].elem) {
					totale[j].occ++;
					f = true;
					break;
				}
			}
			//se non esiste alcun palindromo uguale, lo aggiungo al "totale"
			if (!f) {
				totale[k].elem = elem[i];
				totale[k].occ++;
				k++;
			}
			
			
		}
	}
	cout << "Il numero di stringhe totali e': " << n<<endl;

	//ordino e stampo il vettore "totale"
	ordinaOccorrenze(totale, k);
	stampaOccorrenze(totale, k);
	
}
