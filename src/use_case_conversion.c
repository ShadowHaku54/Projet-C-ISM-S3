#include <stdio.h>
#include "use_case_conversion.h"
#include "display_menu.h"
#include "input.h"
#include "allouage_dynamique_str.h"
#include "convert_all.h"
#include "split.h"
#include "check_base.h"
#include "confirmer.h"

const int Standar_Tab_Base[] ={2, 10, 8, 16};


int useCase_codage_or_transcodage(const char *tabMenu[], int N, int statut)
{
    char *choix;
    int n;
    do{

        display_menu(tabMenu, N);
        choix = input("Faites votre choix :");

        if (choix == NULL){
            puts("Erreur lors de la saisie. \nValeur trop grande ou comportement inantendue! \nRéessayer!\n");
            libere_alloue(choix);
            continue;
        }

        n = choix[0] - '0';
        if (choix[1] != '\0' || n <= 0 || n > N){
            printf("Désolé! veuiller saisir un numéro entre 1 et %d\n", N);
            libere_alloue(choix);
            continue;
        }
        else if (n == N){
            libere_alloue(choix);
            return 0;
        }
        else if (n == N-1){
            libere_alloue(choix);
            return 1;
        }

        do{
            int base_depart = (statut) ? Standar_Tab_Base[n] : 2;
            int base_arrive = (statut) ? 2 : Standar_Tab_Base[n];

            char *nombre_saisie = input("Saisir le nombre:");

            process_conversion(base_depart, base_arrive, nombre_saisie);

            libere_alloue(nombre_saisie);
        }while(confirmer("Voulez vous continuer à saisir? (o/n)"));

        libere_alloue(choix);
    } while(1);
}

void process_conversion(int base_depart, int base_arrive, char *nombre_saisie) {
    char Sneg = (nombre_saisie[0] == '-') ? '-' : '\0';
    char *nouveau_nombre = (Sneg == '-') ? nombre_saisie + 1 : nombre_saisie;

    char *before = NULL;
    char *after = NULL;
    split(nouveau_nombre, '.', &before, &after);

    if (check_number_in_base(before, base_depart) && (after == NULL || check_number_in_base(after, base_depart))) {

        char *before_converti = NULL;
        char *after_converti = NULL;
        before_converti = convert_all_base(base_depart, base_arrive, before);

        if (after != NULL) {
            after_converti = convert_all_base(base_depart, base_arrive, after);
            printf("(%c%s.%s)Base%d vaut (%c%s.%s)Base%d\n", Sneg, before, after, base_depart, Sneg, before_converti, after_converti, base_arrive);
        } else {
            printf("(%c%s)Base%d vaut (%c%s)Base%d\n", Sneg, before, base_depart, Sneg, before_converti, base_arrive);
        }
        libere_alloue(before_converti);
        libere_alloue(after_converti);
    } else {
        printf("Désolé ! Le nombre saisit n'appartient pas à la base %d\n", base_depart);
    }

    libere_alloue(before);
    libere_alloue(after);
}

