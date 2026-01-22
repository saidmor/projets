#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<char>> plateau(3, vector<char>(3, ' '));
    int ligne, colonne;
    char joueur = 'X';
    for (int tour = 0; tour < 9; ++tour)
    {
        cout << "Joueur " << joueur << ", entrez votre coup (ligne et colonne): ";
        cin >> ligne >> colonne;

        // Vérifier si la case est vide
        if (plateau[ligne][colonne] == ' ')
        {
            plateau[ligne][colonne] = joueur;

            // Afficher le plateau
            for (const auto &row : plateau)
            {
                for (const auto &cell : row)
                {
                    cout << cell << " ";
                }
                cout << endl;
            }
            joueur = (joueur == 'X') ? 'O' : 'X';
        }
        else
        {
            cout << "Case déjà occupée, essayez à nouveau." << endl;
            --tour; // Refaire le tour
        }
    }
    cout << "Match nul!" << endl;
    return 0;
}