#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char M[128];
char K[128];                         //dichiarare stringa da 128 posizioni
char C[128];
int scelta;
time_t t;

int main() {

    printf(".....Salve.....\n");
    printf("Hai richiesto una stringa M di testo max 127 caratteri: \n");   //stampa stringa M
    fgets(M,128,stdin);               /*controlla che M che non
                                      superi le 128 posizioni*/


    printf("Adesso puoi scegliere di digitare una delle 2 opzioni \n");
    printf("-->Digitare '1' per inserire la chiave K: \n-->Digitare '2' per generare la chiave K:");
    scanf("%d", &scelta );
    getchar();

    if (scelta==1) {                                //prima scelta: inserire una chiave K.
      printf("OTTIMO, hai scelto di digitare 1.\n" );
      printf("Inserire la chiave K max 127 caratteri.\n");
      do {

          fgets(K,128,stdin);          //controlla che K non superi le 128 posizioni
          if (strlen(M)>strlen(K))
          printf("ERRORE, la chiave è troppo piccola. Riscrivi K.\n");

      } while(strlen(M)>strlen(K));

      printf("GIUSTO, la chiave è corretta.\n");

      for(int i=0; i<strlen(M); i++){
        C[i]=M[i]^K[i];                            //'^'--> operatore XOR
        printf("%c", C[i]+32);
      }

      printf("\nM: ");

      for(int i=0; i<strlen(M); i++){
        M[i]=C[i]^K[i];
        printf("%c", M[i]);
      }


    }
    if(scelta==2){                             //seconda scelta: generare una chiave K.
      printf("Stupendo, hai scelto di digitare 2\n" );
      printf("Ecco la tua chiave K generata.\n" );

      srand((unsigned)time(&t));                //generatore di numeri casuali

      for(int i=0; i<strlen(M); i++){
        K[i]=rand() % 128;
        printf("%d", rand() % 128);            //stampa un numero random
      }

      for(int i=0; i<strlen(M); i++){
        C[i]=M[i]^K[i];
        printf("%c", C[i]+32);
      }

      printf("\nK: ");

      for(int i=0; i<strlen(M); i++){
        M[i]=C[i]^K[i];
        printf("%c", M[i]);
      }


    }

    return 0;

}
