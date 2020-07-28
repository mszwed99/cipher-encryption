#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"


/* FUNKCJE POMOCNICZE */

// Wielkie litery
void uppercase (char *string)
{
  while ( *string != '\0' ) 
  {
    *string = toupper ( ( unsigned char ) *string );
    ++string;
  }
}
// Wzor szyfru afinicznego
int AffinePattern(int i, int a, int b)
{
    int x,y;
    x = i;
    y = (a*x+b)%26;
    return y;
}
// Wzor deszyfujacy szyfr afiniczny
int AffineDePattern(int i, int a, int b) 
{
    int x = i;
    int inv = InverseElement(a,26);
    int y = inv*(x-b);
    int result = PositiveModulo(y,26);
    return result;
}
// Pozytywne modulo (nieujemne)
int PositiveModulo( int a, int m) 
{
    int mod = a % m;
    if (a < 0) // gdy a jest ujemne to dodaje jeszcze raz m;
    {
        mod += m;
    }
    return mod;
}
// Element odwrotny w pierscieniu m
int InverseElement(int a, int m) 
{
    a = a % m;
    for(int i=1; i<m; i++)
    {
        if((i*a)%m == 1)
        {
            return i;
            break;
        }
    }
    return 0; 
}





/* FUNKCJE SZYFRUJACE */

// Kodowanie alfabet Morse'a
void MorseCode(char *string)
{
    char *WordToMorse[1000];
    char *MorseCode[59] = {
    ".-", // A
    "-...", // B
    "-.-.", // C
    "-..", // D 
    ".", // E
    "..-.", // F
    "--.", // D 
    "....", // G
    "..", // H
    ".---", // I
    "-.-", // J
    ".-..", // K
    "--", // L
    "-.", // M
    "---", // N
    ".--.", // O
    "--.-", // P
    ".-.", // Q
    "...", // R
    "-", // S
    "..-", // T
    "...-", // U
    ".--", // V
    "-..-", // W
    "-.--", // X 
    "--..", // Y 
    ".----", // Z 
    "..---", // 1
    "...--", // 2
    "....-", // 3
    ".....", // 4
    "-....", // 5
    "--...", // 6
    "---..", // 7
    "----.", // 8
    "-----", // 9
    "     ", // space
    "...-..-", // $
    ".-...", // &
    "--..--", // ,
    ".-.-.-", // .
    "..--..", // ?
    "-.-.-", // ;
    "---...", // :
    "-..-.", // /
    "-....-", // -
    ".----.", // '
    "-.--.", // (
    "-.--.-", // )
    "..--.-", // _
    ".--.-.",// @
    "-.-.--", // !
    "-...-", // =
    ".-.-.", // +
    ".-..-.", // "
    "..---.", // #
    "-..--", // *
    "...-.-", // %
    "-...--"}; // ^

    int stringLength = strlen(string)-1;
    uppercase(string);
    for(int i=0; i<stringLength; i++)
    {
        char character = string[i];
        switch(character)
        {
            case 'A':
                WordToMorse[i] = MorseCode[0];
                break;
            case 'B':
                WordToMorse[i] = MorseCode[1];
                break;
            case 'C':
                WordToMorse[i] = MorseCode[2];
                break;
            case 'D':
                WordToMorse[i] = MorseCode[3];
                break;
            case 'E':
                WordToMorse[i] = MorseCode[4];
                break;
            case 'F':
                WordToMorse[i] = MorseCode[5];
                break;
            case 'G':
                WordToMorse[i] = MorseCode[6];
                break;
            case 'H':
                WordToMorse[i] = MorseCode[7];
                break;
            case 'I':
                WordToMorse[i] = MorseCode[8];
                break;
            case 'J':
                WordToMorse[i] = MorseCode[9];
                break;
            case 'K':
                WordToMorse[i] = MorseCode[10];
                break;
            case 'L':
                WordToMorse[i] = MorseCode[11];
                break;
            case 'M':
                WordToMorse[i] = MorseCode[12];
                break;
            case 'N':
                WordToMorse[i] = MorseCode[13];
                break;
            case 'O':
                WordToMorse[i] = MorseCode[14];
                break;
            case 'P':
                WordToMorse[i] = MorseCode[15];
                break;
            case 'Q':
                WordToMorse[i] = MorseCode[16];
                break;
            case 'R':
                WordToMorse[i] = MorseCode[17];
                break;
            case 'S':
                WordToMorse[i] = MorseCode[18];
                break;
            case 'T':
                WordToMorse[i] = MorseCode[19];
                break;
            case 'U':
                WordToMorse[i] = MorseCode[20];
                break;
            case 'V':
                WordToMorse[i] = MorseCode[21];
                break;
            case 'W':
                WordToMorse[i] = MorseCode[22];
                break;
            case 'X':
                WordToMorse[i] = MorseCode[23];
                break;
            case 'Y':
                WordToMorse[i] = MorseCode[24];
                break;
            case 'Z':
                WordToMorse[i] = MorseCode[25];
                break;
             case '1':
                WordToMorse[i] = MorseCode[26];
                break;
            case '2':
                WordToMorse[i] = MorseCode[27];
                break;
            case '3':
                WordToMorse[i] = MorseCode[28];
                break;
            case '4':
                WordToMorse[i] = MorseCode[29];
                break;
            case '5':
                WordToMorse[i] = MorseCode[30];
                break;
            case '6':
                WordToMorse[i] = MorseCode[31];
                break;
            case '7':
                WordToMorse[i] = MorseCode[32];
                break;
            case '8':
                WordToMorse[i] = MorseCode[33];
                break;
            case '9':
                WordToMorse[i] = MorseCode[34];
                break;
            case '0':
                WordToMorse[i] = MorseCode[35];
                break;
            case ' ':
                WordToMorse[i] = MorseCode[36];
                break;
            case '$':
                WordToMorse[i] = MorseCode[37];
                break;
            case '&':
                WordToMorse[i] = MorseCode[38];
                break;
            case ',':
                WordToMorse[i] = MorseCode[39];
                break;
            case '.':
                WordToMorse[i] = MorseCode[40];
                break;
            case '?':
                WordToMorse[i] = MorseCode[41];
                break;    
            case ';':
                WordToMorse[i] = MorseCode[42];
                break;
            case ':':
                WordToMorse[i] = MorseCode[43];
                break;
            case '/':
                WordToMorse[i] = MorseCode[44];
                break;
            case '-':
                WordToMorse[i] = MorseCode[45];
                break;
            case '\'':
                WordToMorse[i] = MorseCode[46];
                break;
            case '(':
                WordToMorse[i] = MorseCode[47];
                break;
            case ')':
                WordToMorse[i] = MorseCode[48];
                break;
            case '_':
                WordToMorse[i] = MorseCode[49];
                break;
            case '@':
                WordToMorse[i] = MorseCode[50];
                break;
            case '!':
                WordToMorse[i] = MorseCode[51];
                break;
            case '=':
                WordToMorse[i] = MorseCode[52];
                break;
            case '+':
                WordToMorse[i] = MorseCode[53];
                break;
            case '"':
                WordToMorse[i] = MorseCode[54];
                break;
            case '#':
                WordToMorse[i] = MorseCode[55];
                break;
            case '*':
                WordToMorse[i] = MorseCode[56];
                break;
            case '%':
                WordToMorse[i] = MorseCode[57];
                break;
            case '^':
                WordToMorse[i] = MorseCode[58];
                break;
        }
    }
    printf("Wczytany tekst     --->    %s", string);
    printf("Zakodowany tekst   --->    ");

       for(int i=0; i<stringLength; i++)
       {
           if(i==stringLength-1)
              printf("%s\n",WordToMorse[i]);
           else if(WordToMorse[i] == MorseCode[36])
              printf("\b%s",WordToMorse[i]);
           else
              printf("%s ",WordToMorse[i]);
       }

}
void MorseDeCode(char *string){
    
    printf("Wczytany tekst     --->    %s", string);
    printf("Odkodowany tekst   --->    ");
    char t[]= "%TEMNAIOGKDWRUS-.QZYCXBJP%L-FVH09%8%%%7%%%%%%%61%%%%%%%2%%%3%45";
    int stringLength = strlen(string)-1;
    int i, j = 0;

    for(i = 0; i<stringLength; i++){ 
        if(string[i] == '-'){ 
            j=j*2+1;
        }
        else if (string[i] == '.') { 
            j=j*2+2;
        }
        else if (string[i] == ' ' && string[i+1] == ' '){
            printf("%c ", t[j]);
            i+=4;
            j=0;
        }
        else {
            printf("%c", t[j]);
            j=0; 
        }
    }
    
    printf("%c", t[j]);
    putchar('\n');

}

// Kodowanie szyfr Cezara
void CaesarCipher(char *string)
{
    char character; // jedna litera
    int stringLength = strlen(string)-1; // długosc napisu liczona od 0;
    char caesar[10000]; // tablica ktora będzie przechowywać zaszyfrowany tekst 
    uppercase(string); // funckja zmieniająca wszystkie litery na wielkie
    strcpy(caesar, string); // funkcja kopiująca podany tekst do tablicy z zaszyfrowanym tekstem
	
    for(int i = 0; i != stringLength; ++i)
    {
		character = caesar[i];
		if(character >= 'A' && character <= 'Z')
        {
			character = character + 3;	
			if(character > 'Z')
            {
				character = character - 26; //
			}	
			caesar[i] = character;
		}
	}

    printf("Wczytany tekst      --->    %s", string);
    printf("Zaszyfrowany tekst  --->    %s", caesar);

    
}

// Dekodowanie szyfru Cezara
void CaesarDeCipher(char *string)
{
    char character; // jedna litera
    int stringLength = strlen(string)-1; // długosc napisu liczona od 0;
    char caesar[10000]; // tablica ktora będzie przechowywać zaszyfrowany tekst 
    uppercase(string); // funckja zmieniająca wszystkie litery na wielkie
    strcpy(caesar, string); // funkcja kopiująca podany tekst do tablicy z zaszyfrowanym tekstem
	
    for(int i = 0; i != stringLength; ++i)
    { 
		character = caesar[i];
		if(character >= 'A' && character <= 'Z')
        {
			character = character - 3;	
			if(character < 'A')
            {
				character = character + 26; //
			}	
			caesar[i] = character;
		}
	}

   printf("Wczytany tekst      --->    %s", string);
   printf("Odszyfrowany tekst  --->    %s", caesar);

}

// Szyfr afiniczny
void AffineCipher(char *string, int a, int b)
{   
    char *AffineCipher[10000];
    int y=0;
    char *Alphabet[27] = 
    {
        "A", "B", "C", "D", "E",
        "F", "G", "H", "I", "J",
        "K", "L", "M", "N", "O",
        "P", "Q", "R", "S", "T",
        "U", "V", "W", "X", "Y",
        "Z", " "
    };
    int stringLength = strlen(string)-1;
    uppercase(string);
    for(int i = 0; i != stringLength; ++i)
    {
        char character = string[i];
        switch(character)
        {
            case 'A':
                y = AffinePattern(0,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'B':
                y = AffinePattern(1,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'C':
                y = AffinePattern(2,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'D':
                y = AffinePattern(3,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'E':
                y = AffinePattern(4,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'F':
                y = AffinePattern(5,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'G':
                y = AffinePattern(6,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'H':
                y = AffinePattern(7,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'I':
                y = AffinePattern(8,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'J':
                y = AffinePattern(9,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'K':
                y = AffinePattern(10,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'L':
                y = AffinePattern(11,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'M':
                y = AffinePattern(12,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'N':
                y = AffinePattern(13,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'O':
                y = AffinePattern(14,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'P':
                y = AffinePattern(15,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'Q':
                y = AffinePattern(16,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'R':
                y = AffinePattern(17,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'S':
                y = AffinePattern(18,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'T':
                y = AffinePattern(19,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'U':
                y = AffinePattern(20,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'V':
                y = AffinePattern(21,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'W':
                y = AffinePattern(22,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'X':
                y = AffinePattern(23,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'Y':
                y = AffinePattern(24,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case 'Z':
                y = AffinePattern(25,a,b);
                AffineCipher[i] = Alphabet[y];
                break;
            case ' ':
                AffineCipher[i] = Alphabet[26];
                break;
            default :
                AffineCipher[i] = &character;
                break;
        } 
    }

   printf("Wczytany tekst      --->    %s", string);
   printf("Zaszyfrowany tekst  --->    ");

       for(int i=0; i<stringLength; i++)
       {
           if(i==stringLength-1)
              printf("%s\n",AffineCipher[i]);
           else if(AffineCipher[i] == AffineCipher[36])
              printf("\b%s",AffineCipher[i]);
           else
              printf("%s",AffineCipher[i]);
       }
}

void AffineDeCipher(char *string, int a, int b)
{   
    char *AffineDeCipher[10000];
    int y = 0;
    char *Alphabet[27] = 
    {
        "A", "B", "C", "D", "E",
        "F", "G", "H", "I", "J",
        "K", "L", "M", "N", "O",
        "P", "Q", "R", "S", "T",
        "U", "V", "W", "X", "Y",
        "Z", " "
    };
    int stringLength = strlen(string)-1;
    uppercase(string);
    

    for(int i = 0; i != stringLength; ++i)
    {
        char character = string[i];
        switch(character)
        {
            case 'A':
                y = AffineDePattern(0,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'B':
                y = AffineDePattern(1,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'C':
                y = AffineDePattern(2,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'D':
                y = AffineDePattern(3,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'E':
                y = AffineDePattern(4,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'F':
                y = AffineDePattern(5,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'G':
                y = AffineDePattern(6,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'H':
                y = AffineDePattern(7,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'I':
                y = AffineDePattern(8,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'J':
                y = AffineDePattern(9,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'K':
                y = AffineDePattern(10,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'L':
                y = AffineDePattern(11,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'M':
                y = AffineDePattern(12,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'N':
                y = AffineDePattern(13,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'O':
                y = AffineDePattern(14,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'P':
                y = AffineDePattern(15,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'Q':
                y = AffineDePattern(16,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'R':
                y = AffineDePattern(17,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'S':
                y = AffineDePattern(18,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'T':
                y = AffineDePattern(19,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'U':
                y = AffineDePattern(20,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'V':
                y = AffineDePattern(21,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'W':
                y = AffineDePattern(22,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'X':
                y = AffineDePattern(23,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'Y':
                y = AffineDePattern(24,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case 'Z':
                y = AffineDePattern(25,a,b);
                AffineDeCipher[i] = Alphabet[y];
                break;
            case ' ':
                AffineDeCipher[i] = Alphabet[26];
                break;
            default :
                AffineDeCipher[i] = &character;
                break;
        } 
    }

    printf("Wczytany tekst      --->    %s", string);
    printf("Odszyfrowany tekst  --->    ");
       for(int i=0; i<stringLength; i++)
       {
           if(i==stringLength-1)
              printf("%s\n",AffineDeCipher[i]);
           else if(AffineDeCipher[i] == AffineDeCipher[36])
              printf("\b%s",AffineDeCipher[i]);
           else
              printf("%s",AffineDeCipher[i]);
       }
}