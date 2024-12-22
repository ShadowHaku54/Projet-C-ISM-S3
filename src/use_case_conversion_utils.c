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
#include "page_error.h"

const int Standar_Tab_Base[] ={2, 10, 8, 16};

static char message[90];

void underUseCase_saisieEtconversion(int statut, int n)
{
    fillConsoleBackground(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    do{
        int base_depart = (statut) ? Standar_Tab_Base[n] : 2;
        int base_arrive = (statut) ? 2 : Standar_Tab_Base[n];

        afficher_tables_bases(base_depart, base_arrive);

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
                printf("%s %s", before_converti, after_converti);
                afficher_resultat_apres_conversion(base_depart, base_arrive, Sneg, before, after, before_converti, after_converti);
            } else {
                snprintf(message, sizeof(message), "DÉSOLÉ ! LE NOMBRE SAISIT N'APPARTIENT PAS À LA BASE %d", base_depart);
                page_error(message);
            }
        } else {
            printf("%s %s", before_converti, after_converti);
            afficher_resultat_apres_conversion(base_depart, base_arrive, Sneg, before, after, before_converti, after_converti);
            fillConsoleBackground(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
            setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
        }
    } else {
        snprintf(message, sizeof(message), "DÉSOLÉ ! LE NOMBRE SAISIT N'APPARTIENT PAS À LA BASE %d", base_depart);
        page_error(message);
        fillConsoleBackground(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
        setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    }

    libere_alloue(&before);
    libere_alloue(&after);
    libere_alloue(&after_converti);
    libere_alloue(&before_converti);
}

void UseCase_personalise()
{
    fillConsoleBackground(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    do{
        afficher_tables_bases(-1, -1);

        int base_depart = saisie_small_number("ENTRER LA BASE DE DEPART :");
        if (base_depart == -1 || !view_check_base(base_depart)){
            continue;
        }
        afficher_tables_bases(base_depart, -1);

        int base_arrive = saisie_small_number("ENTRER LA BASE D'ARRIVEE :");
        if (base_arrive == -1 || !view_check_base(base_arrive)){
            continue;
        }
        afficher_tables_bases(base_depart, base_arrive);

        if (base_depart == base_arrive){
            page_error("VEUILLEZ SAISIR UNE BASE DE DEPART DIFFERENTE DE LA BASE D'ARRIVEE!");
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
