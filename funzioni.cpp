#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "funzioni.h"



void stampaVet(int v[], int n) {
	for (int i = 0; i < n; i++) std::cout << v[i] << " ";
}
//restituisce il valore di N
int trovaN(std::string nomefile) {
	int n=0;
	std::string temp;
	std::fstream file;
	file.open(nomefile, std::ios::in);
	if (!file) { std::cout << "Errore nel file!"; exit(1); }
	while (std::getline(file, temp)) {
		n++;
	}
	file.close();
	return n;
}
//carica vettore da file
void caricaVet(std::string nomefile,std::string v[], int n) {
	std::fstream file;
	file.open(nomefile, std::ios::in);
	if (!file) { std::cout << "Errore nel file!"; exit(1); }
	for (int i = 0; i < n; i++) {
		file >> v[i];
	}
	file.close();
}
//scambia due caratteri
void swap(char &a, char &b) {
	char t;
	t = a;
	a = b;
	b = a;
}
//scambia due oggetti di tipo palindromo
void swap(palindromo &a, palindromo &b) {
	palindromo t;
	t.elem = a.elem;
	a.elem = b.elem;
	b.elem = t.elem;
	t.occ = a.occ;
	a.occ = b.occ;
	b.occ = t.occ;
}
//inverte una stringa
std::string reverseString(std::string temp) {
	int n = temp.length();
	for (int i = 0; i < n; i++) {
		swap(temp[i], temp[n - i - 1]);
	}
	return temp;
}
//ordina un vettore di tipo palindromo con metodo bubblesort, ordinando rispetto al numero di occorrenze
void ordinaOccorrenze(palindromo v[], int k) {
	for (int i = 0; i < k-1; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if (v[j].occ > v[j + 1].occ) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}
//stampa vettore di tipo palindromo 
void stampaOccorrenze(palindromo v[], int k) {
	int max = 0;
	for (int i = 0; i < k; i++) {
		std::cout << "il palindromo " << v[i].elem << " ha " << v[i].occ << " occorrenze\n";
	}
}
