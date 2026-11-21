#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Position {
    int x;
    int y;
};


void afficherEtat(
    const Position& joueur,
    const std::vector<Position>& obstacles,
    int score
) {
    cout << "==== Etat du jeu ====" << endl;
    cout << "Score  : " << score << endl;
    cout << "Joueur : (" << joueur.x << ", " << joueur.y << ")" << endl;
    for (const auto& obs : obstacles) {
        cout << "Obstacle : (" << obs.x << ", " << obs.y << ")" << endl;
    }
}


void traiterCommande(
    const std::string& cmd,
    Position& joueur,
    int& score
) {
    if (cmd ==  "avance") {
        joueur.x++;
        score++;
    }
}


bool verifierCollision(
    const Position& joueur,
    const std::vector<Position>& obstacles
) {
    for (const auto& obs : obstacles) {
        if (obs.x == joueur.x) {
            return true;
        }
    }
    return false;
}


int main() {

    // Menu de démarrage
    cout << "Runner CS.1109\n1. Jouer\n2. Quitter\nChoix : ";
    int choix;
    cin >> choix;
    if (choix == 2) {
        exit(0);
    }

    // Initialisation
    Position joueur = {0,0};
    vector<Position> obstacles;
    obstacles.push_back({5,0});
    obstacles.push_back({10,0});
    obstacles.push_back({15,0});
    int score = 0;
    string commande;

    // Boucle de jeu
    while (commande != "quitte") {
        afficherEtat(joueur, obstacles, score);
        cout << "Commande (avance / quitte) ? ";
        cin >> commande;
        traiterCommande(commande, joueur, score);
        if (verifierCollision(joueur, obstacles) == true) {
            cout << "Collision !" << endl;
            break;
        }
    }

    // Fin du jeu
    cout << "Score final : " << score << endl;
    cout << "Merci d'avoir joué" << endl;
    return 0;
}
git initializer_li