/* FUNKCJE SZYFRUJACE */

void MorseCode(char *);
void MorseDeCode(char *);
void CaesarCipher(char *);
void CaesarDeCipher(char *);
void AffineCipher(char *,int,int);
void AffineDeCipher(char *,int,int);

/* FUNKCJE POMOCNICZE */

void uppercase (char *);
int AffinePattern(int,int,int);
int AffineDePattern(int,int,int);
int PositiveModulo(int,int);
int InverseElement(int,int);

/* MENU */
void ClearScreen();
void Welcome();
void StepOne();
void StepTwo();
void StepThree();
