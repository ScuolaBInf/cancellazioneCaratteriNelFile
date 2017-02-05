#include<iostream>
#include<string.h>
using namespace std;

char* quantitaLettere(int&, string = "");
void inserisciLettere(char*, int, string = "");
int* contaLettere(char*, int);
void stampaQuantitaLettere(int*, char*, int, string = "", string = "", string = "");
void inizializza(int* vet, int, int = 0);
void cancellazione(FILE*, char*, int);
bool controlloLettere(char, int, char*);

main ()
	{
		int numeroLettere;
		char * lettere = quantitaLettere(numeroLettere, "Qaunte lettere vuoi cercare? ");
		inserisciLettere(lettere, numeroLettere, "Lettera da Cercare: ");
		try
			{
				stampaQuantitaLettere(contaLettere(lettere, numeroLettere), lettere, numeroLettere, "Sono presenti ", " lettere ", " nel file.");	
			}
		catch (const char* msg) 
			{
      			cout << msg;
   			}
   		
   		FILE* fileDaAprire = fopen("myfile.txt", "r");
   		cancellazione(fileDaAprire, lettere, numeroLettere);
   		fclose(fileDaAprire);
	}

char* quantitaLettere(int& numeroLettere, string testo)
	{
		cout << testo;
		cin >> numeroLettere;
		return new char[numeroLettere];	
	}
	
void inserisciLettere(char* lettere, int dimensione, string testo)
	{
		for (int i = 0; i < dimensione; i++)
			{
				cout << testo << endl;	
				cin >> lettere[i];	
			}	
	}
	
int* contaLettere(char* lettere, int dimensione)
	{
		int* contatore = new int[dimensione];		
		inizializza(contatore, dimensione);
		
		FILE* letturaFile = fopen("myfile.txt", "r");
		if (letturaFile != NULL)
			{
				for (int i = 0; i < dimensione; i++)
					{
						while(!feof(letturaFile))
							{
								if (fgetc(letturaFile) == lettere[i])
									{
										contatore[i]++;
									}
							}
						fseek(letturaFile, 0, SEEK_SET);
					}	
				fclose(letturaFile);
			}
		else
			{
				throw "NoFile";
			}
	
		return contatore;
	}
	
void stampaQuantitaLettere(int* contatore, char* lettere, int dimensione, string str1, string str2, string str3)
	{
		for (int i = 0; i < dimensione; i++)
			{
				cout << str1 << contatore[i] << str2 << lettere[i] << str3 << endl; 
			}	
	}

void inizializza(int* vet, int dimensione, int valore)
	{
		for (int i = 0; i < dimensione; i++)
			{
				vet[i] = valore;
			}	
	}
	

void cancellazione(FILE* fileDaAprire, char* lettere, int dimensione)
	{
		FILE* fileCancellare = fopen("cancellato.txt", "w");

			while(!feof(fileDaAprire))
				{
					char carattereDaEsaminare = fgetc(fileDaAprire);
					if (controlloLettere(carattereDaEsaminare, dimensione, lettere))
						{
							fputc(carattereDaEsaminare, fileCancellare);
						}
				}	
		fclose(fileCancellare);
	}

bool controlloLettere(char carattereDaEsaminare, int dimensione, char* lettere)
	{
		for (int i = 0; i < dimensione; i++)
			{
				if (carattereDaEsaminare == lettere[i])
					{
						return false;
					}
			}
		return true;
	}
