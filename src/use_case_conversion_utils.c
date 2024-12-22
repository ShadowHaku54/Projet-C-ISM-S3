#include <stdio.h>
#include "use_case_conversion_utils.h"
#include "input.h"
#include "allouage_dynamique_str.h"
#include "convert_all.h"
#include "gestions_str.h"
#include "confirmer.h"
#include "view_sms.h"
#include "saisie_small_number.h"
#include "constantes_prog.h"
#include "styles.h"
#include <windows.h>

const int Standar_Tab_Base[] ={2, 10, 8, 16};


void underUseCase_saisieEtconversion(int statut, int n)
{
    fillConsoleBackground(COLOR_TEXT_PRIMARY, BG_COLOR_PAGE_CONVERTIR);
    setConsoleColor(COLOR_TEXT_PRIMARY, BG_COLOR_PAGE_CONVERTIR);
    do{
        int base_depart = (statut) ? Standar_Tab_Base[n] : 2;
        int base_arrive = (statut) ? 2 : Standar_Tab_Base[n];

        afficher_tables(base_depart, base_arrive, BG_COLOR_PAGE_CONVERTIR, COLOR_TEXT_PRIMARY, BORDER_COLOR_PAGE_CONVERTIR, MARGE_1);

        char *nombre_saisie = input_data_type_int("SAISIR LE NOMBRE:");

        if (view_char_isNull_after_input(nombre_saisie)){
            continue;
        }

        process_conversion(base_depart, base_arrive, nombre_saisie);

        libere_alloue(&nombre_saisie);

    }while(confirmer("VOULEZ VOUS CONTINUEZ À CONVERTIR? (O/N)"));
}

void process_conversion(int base_depart, int base_arrive, char *nombre_saisie)
{

    char Sneg = (nombre_saisie[0] == '-') ? '-' : '\0';
    char *nouveau_nombre = (Sneg == '-') ? nombre_saisie + 1 : nombre_saisie;

    char *before = NULL;
    char *after = NULL;
    split(nouveau_nombre, '.', &before, &after);


    char *before_converti = NULL;
    char *after_converti = NULL;

    before_converti = convert_all_base_partInt(base_depart, base_arrive, before);
    if (before_converti != NULL){
        if (after != NULL){
            after_converti = convert_all_base_partFract(base_depart, base_arrive, after, PRECISION_FLOAT);
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

    libere_alloue(&before);
    libere_alloue(&after);
    libere_alloue(&after_converti);
    libere_alloue(&before_converti);
}

void UseCase_personalise()
{
    fillConsoleBackground(COLOR_TEXT_PRIMARY, BG_COLOR_PAGE_CONVERTIR);
    setConsoleColor(COLOR_TEXT_PRIMARY, BG_COLOR_PAGE_CONVERTIR);
    do{
        afficher_tables(-1, -1, BG_COLOR_PAGE_CONVERTIR, COLOR_TEXT_PRIMARY, BORDER_COLOR_PAGE_CONVERTIR, MARGE_1);

        int base_depart = saisie_small_number("Entrer la base de départ: ");
        if (base_depart == -1 || !view_check_base(base_depart)){
            continue;
        }
        afficher_tables(base_depart, -1, BG_COLOR_PAGE_CONVERTIR, COLOR_TEXT_PRIMARY, BORDER_COLOR_PAGE_CONVERTIR, MARGE_1);

        int base_arrive = saisie_small_number("Entrer la base de d'arrivé: ");
        if (base_arrive == -1 || !view_check_base(base_arrive)){
            continue;
        }
        afficher_tables(base_depart, base_arrive, BG_COLOR_PAGE_CONVERTIR, COLOR_TEXT_PRIMARY, BORDER_COLOR_PAGE_CONVERTIR, MARGE_1);

        if (base_depart == base_arrive){
            puts("Veuillez saisir une base de départ différente de la base d'arrivée!");
            continue;
        }

        char *nombre_saisie = input_data_type_int("Saisir le nombre:");

        if (nombre_saisie == NULL){
            puts("Erreur lors de la saisie. \nValeur trop grande ou comportement inantendue! \nRéessayer!\n");
            libere_alloue(&nombre_saisie);

        } else {
            process_conversion(base_depart, base_arrive, nombre_saisie);
            libere_alloue(&nombre_saisie);
        }


    }while(confirmer("Voulez vous continuer à convertir? (o/n)"));
}
