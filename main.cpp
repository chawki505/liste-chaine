#include <stdio.h>
#include <stdlib.h>


//simplement chainer
typedef struct maillion maillion;
struct maillion {
    int val;
    struct maillion *next;
};


typedef maillion *list;



list ajouterEnFin(list maliste, int valeur) {
    /* On crée un nouvel élément */
    maillion *newMaillion = (maillion *) malloc(sizeof(maillion));

    /* On assigne la valeur au nouvel élément */
    newMaillion->val = valeur;

    /* On ajoute en fin, donc aucun élément ne va suivre */
    newMaillion->next = NULL;

    if (maliste == NULL) {
        /* Si la liste est videé il suffit de renvoyer l'élément créé */
        return newMaillion;
    } else {
        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        maillion *temp = maliste;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMaillion;
        return maliste;
    }
}


list ajoutElementEnTete(list lalist, int element) {

    /* On crée un nouvel maillion */
    maillion * newMaillion = (maillion* ) malloc(sizeof(maillion));

    /* On assigne la valeur au nouveau maillion */
    newMaillion->val = element;

    /* On assigne l'adresse du mmaillion suivant au nouveau maillion */
    newMaillion->next = lalist;

    /* On retourne la nouvelle liste, i.e. on pointe sur le premier élément */
    return newMaillion;
}

list suprimerdebut(list lalist) {
    if (lalist != NULL) {
        /* Si la liste est non vide, on se prépare à renvoyer l'adresse de
        l'élément en 2ème position */
        maillion *aRenvoyer = lalist->next;
        /* On libère le premier élément */
       free(lalist);

        /* On retourne le nouveau début de la liste */
        return aRenvoyer;
    } else {
        return NULL;
    }

}

list supprimerElementEnFin(list lalist) {
    /* Si la liste est vide, on retourne NULL */
    if (lalist == NULL)
        return NULL;

    /* Si la liste contient un seul élément */
    if (lalist->next == NULL) {
        /* On le libère et on retourne NULL (la liste est maintenant vide) */
        free(lalist);
        return NULL;
    }

    /* Si la liste contient au moins deux éléments */
    maillion *tmp = lalist;
    maillion *ptmp = lalist;
    /* Tant qu'on n'est pas au dernier élément */
    while (tmp->next != NULL) {
        /* ptmp stock l'adresse de tmp */
        ptmp = tmp;
        /* On déplace tmp (mais ptmp garde l'ancienne valeur de tmp */
        tmp = tmp->next;
    }
    /* A la sortie de la boucle, tmp pointe sur le dernier élément, et ptmp sur
    l'avant-dernier. On indique que l'avant-dernier devient la fin de la liste
    et on supprime le dernier élément */
    ptmp->next = NULL;
    free(tmp);
    return lalist;
}

list rechercherElement(list liste, int valeur) {
    maillion *tmp = liste;
    /* Tant que l'on n'est pas au bout de la liste */
    while (tmp != NULL) {
        if (tmp->val == valeur) {
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

list effacerListe(list liste) {
    maillion *tmp = liste;
    maillion *tmpnxt;

    /* Tant que l'on n'est pas au bout de la liste */
    while (tmp != NULL) {
        /* On stocke l'élément suivant pour pouvoir ensuite avancer */
        tmpnxt = tmp->next;
        /* On efface l'élément courant */
         free(tmp);
        /* On avance d'une case */
        tmp = tmpnxt;
    }
    /* La liste est vide : on retourne NULL */
    return NULL;
}


void afficherListe(list laliste) {
    maillion *tmp = laliste;
    /* Tant que l'on n'est pas au bout de la liste */
    while (tmp != NULL) {
        /* On affiche */
        printf("%d ", tmp->val);
        /* On avance d'une case */
        tmp = tmp->next;
    }
}

int main() {
    maillion *malist = NULL;

    malist = ajoutElementEnTete(malist, 10);
    malist = ajouterEnFin(malist, 20);
    malist = ajouterEnFin(malist, 30);


    printf("avant : ");
    afficherListe(malist);


    printf("\napres :");


    malist=suprimerdebut(malist);

    afficherListe(malist);
    printf("\nfin");


}