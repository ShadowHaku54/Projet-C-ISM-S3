#include "enregistrer_historique.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "allouage_dynamique_str.h"
#include <windows.h>
#include "styles.h"
#include "constantes_prog.h"

const char *chemin_fichier = "./historique.txt";

void enregistrer_historique(int base_depart, int base_arrivee,
                             const char *before, const char *after,
                             char Sneg, const char *before_converti,
                             const char *after_converti) {

    FILE *fichier = fopen(chemin_fichier, "a");
    if (fichier == NULL) {
        printf("\tErreur lors de l'ouverture du fichier historique");
        return;
    }

    int signe_neg = (Sneg == '-')? 1: 0;
    int lenA = strlen(before) + signe_neg;
    if (after != NULL) lenA += strlen(after) + 1;

    int lenB = strlen(before_converti) + signe_neg;
    if (after != NULL) lenB += strlen(after_converti) + 1;

    char *nombre_saisie = NULL;
    char *nombre_converti = NULL;
    alloue_str(&nombre_saisie, lenA + 1);
    alloue_str(&nombre_converti, lenB + 1);

    int a = snprintf(nombre_saisie, lenA + 1, "%s%s%s%s", (Sneg == '-')? "-" : "", before, (after != NULL) ? "." : "", (after != NULL) ? after : "");
    int b = snprintf(nombre_converti, lenB + 1, "%s%s%s%s", (Sneg == '-')? "-" : "", before_converti, (after_converti != NULL) ? "." : "", (after_converti != NULL) ? after_converti : "");

    if (a < 0 || b < 0) {
        printf("\tErreur : formatage échoué pour nombre_saisie ou nombre convertie\n");
        libere_alloue(&nombre_saisie);
        libere_alloue(&nombre_converti);
        fclose(fichier);
        return;
    }

    fprintf(fichier, "%d,%s,%d,%s\n", base_depart, nombre_saisie, base_arrivee, nombre_converti);

    libere_alloue(&nombre_saisie);
    libere_alloue(&nombre_converti);
    fclose(fichier);
}

static int fichier_existe_et_non_vide(const char *chemin) {
    FILE *fichier = fopen(chemin, "r");

    if (fichier == NULL) {
        return 0;
    }

    fseek(fichier, 0, SEEK_END);
    long taille = ftell(fichier);
    fclose(fichier);

    return (taille == 0);
}

void lire_historique() {

    fillConsoleBackground(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf("\n \n \n");
    print_ligne_spaces(SCREEM);
    printf("HISTORIQUE:\n\n");
    if (fichier_existe_et_non_vide(chemin_fichier)) {
        print_ligne_spaces(MARGE_2);
        printf("AUCUN CONTENU ACTUELLEMENT ENREGISTRER!\n");
        system("pause");
        return;
    }

    FILE *fichier = fopen(chemin_fichier, "r");

    print_ligne_spaces(MARGE_2);
    setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    char ligne[256];
    printf("╔══════╦════════════╦══════════════════════╦══════════╦══════════════════════════════════════════╗\n");
    print_ligne_spaces(MARGE_2);
    printf("║ ");
    setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf("odre");
    setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf(" ║ ");
    setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf("Base Début");
    setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);    printf(" ║ ");
    setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf("Nombre Saisi");
    setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf("         ║ ");
    setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf("Base Fin");
    setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf(" ║ ");
    setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf("Valeur Convertie");
    setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
    printf("                         ║\n");
    print_ligne_spaces(MARGE_2);    printf("╠══════╬════════════╬══════════════════════╬══════════╬══════════════════════════════════════════╣\n");

    int i = 0;
    while (fgets(ligne, sizeof(ligne), fichier)) {
        char nombre_saisi[20], valeur_convertie[70];
        int base_depart, base_arrivee;

        print_ligne_spaces(MARGE_2);
        if (sscanf(ligne, "%d,%20[^,],%d,%40[^\n]", &base_depart, nombre_saisi, &base_arrivee, valeur_convertie) == 4) {
            printf("║ ");
            setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf("%-4d", ++i);
            setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf(" ║ ");
            setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf("%-10d", base_depart);
            setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf(" ║ ");
            setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf("%-20s", nombre_saisi);
            setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);            printf(" ║ ");
            setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf("%-8d", base_arrivee);
            setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf(" ║ ");
            setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);            printf("%-40s", valeur_convertie);
            setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf(" ║\n");
        } else {
            setConsoleColor(COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);
            printf("Erreur de lecture sur la ligne : %s\n", ligne);
        }
    }

    setConsoleColor(BORDER_COLOR_HISTORIQUE, BG_COLOR_HISTORIQUE);

    print_ligne_spaces(MARGE_2);
    printf("╚══════╩════════════╩══════════════════════╩══════════╩══════════════════════════════════════════╝\n\n\n");
    fclose(fichier);
        setConsoleColor(GRAY, WHITE);
    print_ligne_spaces(MARGE_2);

    affiche_lettre_par_lettre("Appuyer pour continuer", DELAIS_MS);
    affiche_lettre_par_lettre("...", DELAIS_MS+1000);

    getchar();

}
