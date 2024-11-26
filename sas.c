#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char titre[50];
    char description[50];
    char priorite[50]; // "high" or "low"
    char etat[50];     // "completed" or "pending"
    Date date;
} Tache;

Tache Tc[60];
int t = 0;

void afficherMenu() {
    printf("\n=== Gestion des Tâches ===\n");
    printf("1. Ajouter une Tâche\n");
    printf("2. Afficher les Tâches\n");
    printf("3. Modifier une Tâche\n");
    printf("4. Supprimer une Tâche\n");
    printf("5. Filtrer les Tâches\n");
    printf("6. Quitter\n");
}

void creerTache() {
    printf("Entrez le titre: ");
    scanf(" %[^\n]%*c", Tc[t].titre); // Read multi-word input
    printf("Entrez la description: ");
    scanf(" %[^\n]%*c", Tc[t].description);
    printf("Entrez la priorité (high/low): ");
    scanf("%s", Tc[t].priorite);
    printf("Entrez l'état (completed/pending): ");
    scanf("%s", Tc[t].etat);
    printf("Entrez la date (jour mois année): ");
    scanf("%d %d %d", &Tc[t].date.jour, &Tc[t].date.mois, &Tc[t].date.annee);

    t++;
}

void afficherTache() {
    if (t == 0) {
        printf("Aucune tâche à afficher.\n");
        return;
    }

    for (int i = 0; i < t; i++) {
        printf("\nTâche %d:\n", i + 1);
        printf("Titre: %s\n", Tc[i].titre);
        printf("Description: %s\n", Tc[i].description);
        printf("Priorité: %s\n", Tc[i].priorite);
        printf("Etat: %s\n", Tc[i].etat);
        printf("Date: %02d/%02d/%04d\n", Tc[i].date.jour, Tc[i].date.mois, Tc[i].date.annee);
    }
}

void modifierTache() {
    int index;
    printf("Entrez le numéro de la tâche à modifier: ");
    scanf("%d", &index);

    if (index < 1 || index > t) {
        printf("Numéro de tâche invalide.\n");
        return;
    }

    index--;  // Convert to zero-indexed

    printf("Modifier le titre (actuel: %s): ", Tc[index].titre);
    scanf(" %[^\n]%*c", Tc[index].titre);
    printf("Modifier la description (actuelle: %s): ", Tc[index].description);
    scanf(" %[^\n]%*c", Tc[index].description);
    printf("Modifier la priorité (actuelle: %s): ", Tc[index].priorite);
    scanf("%s", Tc[index].priorite);
    printf("Modifier l'état (actuel: %s): ", Tc[index].etat);
    scanf("%s", Tc[index].etat);
    printf("Modifier la date (jour mois année): ");
    scanf("%d %d %d", &Tc[index].date.jour, &Tc[index].date.mois, &Tc[index].date.annee);

    printf("Tâche modifiée avec succès.\n");
}

void supprimerTache() {
    int index;
    printf("Entrez le numéro de la tâche à supprimer: ");
    scanf("%d", &index);

    if (index < 1 || index > t) {
        printf("Numéro de tâche invalide.\n");
        return;
    }

    index--;  // Convert to zero-indexed

    for (int i = index; i < t - 1; i++) {
        Tc[i] = Tc[i + 1];  // Shift tasks to fill the gap
    }

    t--;
    printf("Tâche supprimée avec succès.\n");
}

void filtrer() {
    char priorite[50];
    printf("Entrez la priorité à filtrer (high/low): ");
    scanf("%s", priorite);

    int found = 0;
    for (int i = 0; i < t; i++) {
        if (strcmp(Tc[i].priorite, priorite) == 0) {
            found = 1;
            printf("\nTâche %d:\n", i + 1);
            printf("Titre: %s\n", Tc[i].titre);
            printf("Description: %s\n", Tc[i].description);
            printf("Priorité: %s\n", Tc[i].priorite);
            printf("Etat: %s\n", Tc[i].etat);
            printf("Date: %02d/%02d/%04d\n", Tc[i].date.jour, Tc[i].date.mois, Tc[i].date.annee);
        }
    }

    if (!found) {
        printf("Aucune tâche trouvée avec cette priorité.\n");
    }
}

int main() {
    int action;
    do {
        afficherMenu();
        printf("Entrez votre choix: ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                creerTache();
                break;
            case 2:
                afficherTache();
                break;
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                filtrer();
                break;
            case 6:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix introuvable.\n");
        }
    } while (action != 6);

    return 0;
}
