#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "lib.h"

int StepOneResult; // Wybor metody;
char text[1000]; // Tablica z tekstem;

void ClearScreen() // znalezione w internecie
{
  printf("\033[2J"); // Czyści ekran
  printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
}

void Welcome()
{
      ClearScreen();
      printf("--------------------------------------------------------------------------------\n");
      printf("------------------------ Program szyfrujący/deszyfrujący -----------------------\n");
      printf("--------------------------------------------------------------------------------\n");
      putchar('\n');
}

void StepOne()
{
   do
   {
      ClearScreen();
      Welcome();
      printf("-------------------------------- Szyfrowanie -----------------------------------\n");
      putchar('\n');
      printf("1. Kodowanie alfabetem Morse'a\n");
      printf("2. Szyfrowanie szyfrem Cezara\n");
      printf("3. Szyfrowanie szyfrem afinicznym\n");
      putchar('\n');
      printf("-------------------------------- Deszyfrowanie ---------------------------------\n");
      putchar('\n');
      printf("4. Dekowanie alfabetu Morse'a\n");
      printf("5. Deszyfrowanie szyfru Cezara\n");
      printf("6. Deszyfrowanie szyfru afinicznego\n");
      putchar('\n');
      printf("[*] Wybierz opcje : ");
      scanf("%d",&StepOneResult);
   }while(StepOneResult != 1 && StepOneResult != 2 && StepOneResult != 3 && StepOneResult != 4 &&StepOneResult != 5 && StepOneResult != 6);
}
void StepTwo()
{
   char ifFile;
   do
   {
      ClearScreen();
      Welcome();
      printf("--------------------------- Czy wczytać tekst z pliku? -------------------------\n");
      //printf("-- Tak\n");
      //printf("-- Nie\n");
      putchar('\n');
      printf("[*] Wybierz 'T' lub 'N' : ");
      scanf("%c",&ifFile);
      uppercase(&ifFile);

   }while(ifFile != 'T' && ifFile != 'N');


   if(ifFile == 'N')
   {
      ClearScreen();
      Welcome();
      printf("---------------------------------- Wprowadź tekst ------------------------------\n");
      putchar('\n');
      printf("[*] Wprowadź tekst : ");
      getchar(); // bo tak działa potem tylko fgets
      fgets(text, sizeof(text), stdin); 
   }
   else if(ifFile == 'T')
   {
      int ErrorReporter = 0;
      do
      {
         ClearScreen();
         Welcome();
         char FileName[100];
         printf("-------------------------------- Podaj nazwę pliku -----------------------------\n");
         putchar('\n');
         printf(" [!] Plik tekstowy musi znajdować się w folderze z programem. \n");
         putchar('\n');
         printf("[*] Wprowadź nazwę pliku ( z rozszerzeniem ) : ");
         scanf("%s", FileName);
         FILE *TextFile;
         if ((TextFile= fopen(FileName, "r")) != NULL) 
         {
            fscanf(TextFile,"%[^\n]",text);
            fclose(TextFile);

            //Dodaj przejscie do nowej lini, poniewaz fscanf tego nie robi
               int stringLength = strlen(text)-1;
               text[stringLength + 1] = '\n';

            ErrorReporter = 0;
         }
         else
         {
            ErrorReporter = 1;
         }
         
      }while(ErrorReporter == 1);
   }


}

void StepThree()
{
    int a,b;
    ClearScreen();
    Welcome();

   if (StepOneResult == '1' || StepOneResult == '2' || StepOneResult == '3')
   {
       printf("----------------------------- Szyfrowanie tekstu -------------------------------\n");
   }
   else
   {
      printf("----------------------------- Deszyfrowanie tekstu -----------------------------\n");
   }
   putchar('\n');

    switch (StepOneResult)
    {
    case 1:
        MorseCode(text);
        break;
    case 2:
        CaesarCipher(text);
        break;
    case 3:
        printf("[*] Wprowadź A : ");
        scanf("%d",&a);
        printf("[*] Wprowadź B : ");
        scanf("%d",&b);
        putchar('\n');
        AffineCipher(text,a,b);
        break;
    case 4:
        MorseDeCode(text);
        break;
    case 5:
        CaesarDeCipher(text);
        break;
    case 6:
        printf("[*] Wprowadź A : ");
        scanf("%d",&a);
        printf("[*] Wprowadź B : ");
        scanf("%d",&b);
        putchar('\n');
        AffineDeCipher(text,a,b);
        break;
    default:
        break;
    }
    putchar('\n');
}
