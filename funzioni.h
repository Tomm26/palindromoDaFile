#pragma once
#include <string>

//struct per salvare il palindromo, considerando anche le sue occorrenze
struct palindromo {
	std::string elem="";
	int occ = 0;
};
void stampaVet(int v[], int n);
int trovaN(std::string nomefile);
void caricaVet(std::string nomefile, std::string v[], int n);
void swap(char &a, char &b);
void swap(palindromo &a, palindromo &b);
std::string reverseString(std::string temp);
void ordinaOccorrenze(palindromo v[], int k);
void stampaOccorrenze(palindromo v[], int k);
