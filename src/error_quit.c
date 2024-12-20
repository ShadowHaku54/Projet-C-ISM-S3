#include <stdio.h>
#include <string.h>

// Largeur fixe configurable
#define TERMINAL_WIDTH 80

// Codes couleurs ANSI
#define RESET "\033[0m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define GREEN "\033[1;32m"

// Fonction pour calculer les espaces à gauche
int calculer_espaces(const char *message)
{
    int longueur_message = strlen(message);
    int padding = (TERMINAL_WIDTH - longueur_message) / 2;
    return (padding > 0) ? padding : 0;
}

// Fonction pour afficher un texte centré avec une couleur
void afficher_texte_centre(const char *message, const char *couleur)
{
    int espaces = calculer_espaces(message);
    printf("%s", couleur); // Appliquer la couleur
    for (int i = 0; i < espaces; i++)
        printf(" ");
    printf("%s\n", message);
    printf(RESET); // Réinitialiser les couleurs
}

// Fonction pour afficher une ligne d'encadrement
void afficher_ligne_encadrement(char bordure, const char *couleur)
{
    printf("%s", couleur);
    for (int i = 0; i < TERMINAL_WIDTH; i++)
        printf("%c", bordure);
    printf("\n%s", RESET);
}

// Fonction pour afficher un texte dans un cadre
void afficher_cadre(const char *message, const char *couleur)
{
    afficher_ligne_encadrement('*', couleur); // Ligne du haut
    afficher_texte_centre(message, couleur); // Texte centré
    afficher_ligne_encadrement('*', couleur); // Ligne du bas
}

// Fonction principale d'affichage de fin
void end_program()
{
    printf("\n");
    afficher_cadre("FIN DU PROGRAMME", CYAN);
    printf("\n");
    afficher_texte_centre("Merci d'avoir utilisé le Projet-C-ISM-S3 !", YELLOW);
    afficher_texte_centre("À bientôt pour de nouvelles conversions.", GREEN);
    printf("\n");
    afficher_cadre("✨ Programme 🀀󲠀🐀𢰀🐀𣐀❌✅🐀𼀀❗🐀򐠀 OK ✨", MAGENTA);
    printf("\n");
}
