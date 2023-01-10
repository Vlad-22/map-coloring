/*Un grup de N țări trebuie reprezentate pe o hartă cu culori diferite, astfel încât oricare dintre
acestea să fie colorată diferit de vecinii săi. Să se scrie un program care primește la intrare lista
celor N țări (denumire, listă vecini), lista de culori posibile și determină culoarea pentru fiecare
țară în parte.
*/

/* Date de intrare:
N - numărul de țări (număr întreg)
denumirea țărilor - array de texte
lista vecinilor pentru fiecare țară - array?
lista de culori - array de texte
    Date de ieșire:
culoarea pentru fiecare țară (respectând regulile)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1. Definim parametrii cu care lucrăm
    int N, i;
    char countries[N][20];

    // 2. Citim datele de intrare
    printf("Introduceti numarul de tari: ");
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        printf("\nTara numarul %d: ", i+1);
        scanf("%s", countries[i]);
    }

    // 3. Prelucrăm datele ca să obținem rezultatul
    // 4. Afișăm rezultatul.
    printf("\nNumarul de tari este: %d\n", N);
      for (i = 0; i < N; i++)
    {
         printf("\n%d -> %s: \n", i, countries[i]);
    }


    return 0;
}
