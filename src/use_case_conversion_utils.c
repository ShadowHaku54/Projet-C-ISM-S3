#include <stdio.h>
#include "use_case_conversion_utils.h"
#include "gestion_menu_choix.h"
#include "input.h"
#include "allouage_dynamique_str.h"
#include "convert_all.h"
#include "split.h"
#include "confirmer.h"
#include "view_sms.h"
#include "saisie_small_number.h"

const int Standar_Tab_Base[] ={2, 10, 8, 16};


int useCase_codage_or_transcodage(const char *tabMenu[], int N, int statut, const char *Title)
{
    while (1){
        int n = gestion_menu_choix(tabMenu, N, Title);

        if(n != -1){

            if (n == N){
                return 0;
            }
            else if (n == N-1){
                return 1;
            }

            underUseCase_saisieEtconversion(statut, n);
        }
    };
}



void underUseCase_saisieEtconversion(int statut, int n)
{
    do{
        int base_depart = (statut) ? Standar_Tab_Base[n] : 2;
        int base_arrive = (statut) ? 2 : Standar_Tab_Base[n];

        char *nombre_saisie = input_data_type_int("SAISIR LE NOMBRE:");

        if (view_char_isNull_after_input(nombre_saisie)){
            continue;
        }

        process_conversion(base_depart, base_arrive, nombre_saisie);

        libere_alloue(nombre_saisie);

    }while(confirmer("VOULEZ VOUS CONTINUEZ À CONVERTIR? (O/N)"));
}

void process_conversion(int base_depart, int base_arrive, char *nombre_saisie) {
    char Sneg = (nombre_saisie[0] == '-') ? '-' : '\0';
    char *nouveau_nombre = (Sneg == '-') ? nombre_saisie + 1 : nombre_saisie;

    char *before = NULL;
    char *after = NULL;
    split(nouveau_nombre, '.', &before, &after);


    char *before_converti = NULL;
    char *after_converti = NULL;

    before_converti = convert_all_base(base_depart, base_arrive, before);
    if (before_converti != NULL){
        if (after != NULL){
            after_converti = convert_all_base(base_depart, base_arrive, after);
            if (after_converti != NULL){
                printf("(%c%s.%s)Base%d vaut (%c%s.%s)Base%d\n", Sneg, before, after, base_depart, Sneg, before_converti, after_converti, base_arrive);
            } else {
                printf("DÉSOLÉ ! LE NOMBRE SAISIT N'APPARTIENT PAS À LA BASE %d\n", base_depart);
            }
        } else {
            printf("(%c%s)Base%d vaut (%c%s)Base%d\n", Sneg, before, base_depart, Sneg, before_converti, base_arrive);
        }
    } else {
        printf("DÉSOLÉ ! LE NOMBRE SAISIT N'APPARTIENT PAS À LA BASE %d\n", base_depart);
    }

    libere_alloue(before_converti);
    libere_alloue(after_converti);
    libere_alloue(before);
    libere_alloue(after);
}

void UseCase_personalise()
{
    do{

        int base_depart = saisie_small_number("Entrer la base de départ: ");
        if (base_depart == -1 || !view_check_base(base_depart)){
            continue;
        }

        int base_arrive = saisie_small_number("Entrer la base de d'arrivé: ");
        if (base_arrive == -1 || !view_check_base(base_arrive)){
            continue;
        }

        if (base_depart == base_arrive){
            puts("Veuillez saisir une base de d�part diff�rente de la base d'arrivée!");
            continue;
        }

        char *nombre_saisie = input_data_type_int("Saisir le nombre:");

        if (nombre_saisie == NULL){
            puts("Erreur lors de la saisie. \nValeur trop grande ou comportement inantendue! \nRéessayer!\n");
            libere_alloue(nombre_saisie);
            continue;
        }

        process_conversion(base_depart, base_arrive, nombre_saisie);

        libere_alloue(nombre_saisie);

    }while(confirmer("Voulez vous continuer à convertir? (o/n)"));
}
