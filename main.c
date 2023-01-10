/*Un grup de N țări trebuie reprezentate pe o hartă cu culori diferite, astfel încât oricare dintre
acestea să fie colorată diferit de vecinii săi. Să se scrie un program care primește la intrare lista
celor N țări (denumire, listă vecini), lista de culori posibile și determină culoarea pentru fiecare
țară în parte.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_country_name(char *token, char countries[30][20], int countries_number) {
  // Cauta un cuvant in lista de tari (teoretic e nume de tara)
  for (int i = 0; i < countries_number; i++) {
    if (strcmp(countries[i], token) == 0) {
      return i;
    }
  }

  return -1;
}

int main()
{
  // Definim parametrii cu care lucrăm
  int countries_number, colors_number;
  char countries[30][20]; // lista de tari
  char colors[30][20]; // lista de culori
  char countries_temp[200]; // o variabila temporara in care salvam vecinii
                            // introdusi de utilizator sub forma tara1,tara2
  char *token; // o variabila temporara in care salvam un posibil nume de tara
               // pentru a face validarea ei
  int map[30][30]; // fiecare linie = tara cu acelasi index din countries
                   // pe coloana: 1 sau 0 = vecin sau nu
                   // functioneaza ca o matrice de adiacenta
  int country_index;
  char countries_colors[30]; // lista de culori pentru fiecare tara

  // ==========================================================================
  // Citim numarul de tari
  printf("Introduceti numarul de tari: ");
  scanf("%d", &countries_number);

  // Citim numele tarilor
  for (int i = 0; i < countries_number; i++) {
    printf("Tara numarul %d este: ", i+1);
    scanf("%s", countries[i]);
  }

  // Afisam de proba numele tarilor asa cum au fost citite
  printf("Verificam tarile introduse:\n");
  for (int i = 0; i < countries_number; i++) {
    printf("%d. %s\n", i+1, countries[i]);
  }

  // Initializam harta (matricea de adiacenta corespunzatoare)
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 30; j++) {
      map[i][j] = 0;
    }
  }

  // Citim vecinii pentru fiecare tara
  printf("Introduceti numele tarilor invecinate cu virgula intre ele:\n");
  for (int i = 0; i < countries_number; i++) {
    printf("%s are vecinii: ", countries[i]);
    scanf("%s", countries_temp);

    // Interpretez ce a introdus utilizatorul
    token = strtok(countries_temp, ","); // ia primul token

    while(token != NULL) {
      /* printf("%s\n", token); */
      country_index = find_country_name(token, countries, countries_number);

      if (country_index != -1) {
        map[i][country_index] = 1;
        map[country_index][i] = 1;
      }
      token = strtok(NULL, ","); // trece la urmatorul token
    }
  }

  // Afisare harta
  /*
    printf("Harta (matricea de adiacenta) dupa prelucrarea vecinilor:\n");
    for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 30; j++) {
        printf("%d ", map[i][j]);
      }
      printf("\n");
    }
  */

  // ==========================================================================
  // Citim numarul de culori
  printf("Introduceti numarul de culori: ");
  scanf("%d", &colors_number);

  // Citim numele culorilor
  for (int i = 0; i < colors_number; i++) {
    printf("Culoarea numarul %d este: ", i+1);
    scanf("%s", colors[i]);
  }

  // Afisam de proba numele culorilor asa cum au fost citite
  printf("Verificam culorile introduse:\n");
  for (int i = 0; i < colors_number; i++) {
    printf("Culoarea numarul %d este: %s\n", i+1, colors[i]);
  }

  // ==========================================================================
  // Colorarea

  // Initializam cu -1 lista de culori
  for (int i = 0; i < countries_number; i++) {
    countries_colors[i] = -1;
  }

  for (int i = 0; i < countries_number; i++) {
    /* printf("Caut culoare pentru tara: %d %s\n", i, countries[i]); */

    if (i == 0) {
      countries_colors[i] = 0;
    }

    int valid;

    for (int color_index = 0; color_index < colors_number; color_index++) {
      // incercam sa coloram cu prima culoare posibila
      valid = 1;

      for (int a_country = 0; a_country < countries_number; a_country++) {
        if (map[i][a_country] == 1) {
          /* printf("Am gasit un vecin: %d %s\n", a_country, countries[a_country]); */
          /* printf("CULOAREA PENTRU ACEST VECIN ESTE ACUM: %d", countries_colors[a_country]); */
          if (countries_colors[a_country] == color_index) {
            valid = 0;
          }
        }
      }

      if (valid == 1) {
        countries_colors[i] = color_index;
      }
    }

    // countries_colors[i] = 0;
  }

  // ==========================================================================
  // Rezultatul
  printf("\nAm terminat de colorat!\n");
  for (int i = 0; i < countries_number; i++) {
    if (countries_colors[i] != -1) {
      printf("%s are culoarea %s \n", countries[i], colors[countries_colors[i]]);
    }
  }

  return 0;
}
