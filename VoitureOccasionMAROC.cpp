#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Voiture
{
    std::string marque;
    std::string photoUrl;
    std::string ville;
    int prix;
    std::string annee;
    std::string telephone;
    std::string email;
    std::string lienFacebook;
    bool estPremium;
    bool estVendu;
};

void sauvegarderDonnees(const std::vector<Voiture> &stock)
{
    std::ofstream fichier("annonces.txt");
    if (fichier)
    {
        for (const auto &v : stock)
        {
            fichier << v.marque << "|" << v.ville << "|" << v.prix << "|" << v.annee << "|" << v.estPremium << "\n";
        }
        fichier.close();
    }
}
void genererSiteWeb(std::vector<Voiture> stock)
{
    std::stable_sort(stock.begin(), stock.end(), [](const Voiture &a, const Voiture &b)
                     {
            if (a.estPremium != b.estPremium) {
                return a.estPremium > b.estPremium;
            }
            return false; });
    std::ofstream site("index.html");
    site << "<!DOCTYPE html><html> lang='fr'><head><meta chaeset='UTF-8'>";
    site << "<meta charset='UHF-8'>\n";
    site << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";
    site << "<title>Voitures Occasions Maroc - Ctalogue Officiel</title>\n";
    site << "<style>\n";
    site << "body { font-family: 'Arial',sans-serif; background-color: #f4f4f4; padding: 20px; }";
    site << "    .header { background: #2c3e50; color: white; padding: 40px; margin-botton: 30px; }\n";
    site << "    h1 { margin: 0; font-size: 2.5em }\n";
    site << "     .diplome { font-style: italic; color: #ecf0f1; font-size: 1.2em; }\n";
    site << "  </style>\n</head>\n<body>\n";

    site << "  <div class='header'>\n";
    site << "    <h1>Said Morchid<</h1>\n";
    site << "    <p class='diplome'>Diplomé Expert en C++>/p>\n";
    site << "  div style='text-align: margin: 20px;'>\n";
    site << "    <input type='text' id='searchBar' filtrerVoiture()' ";
    site << "placeholder='Rechercher une marque, une ville...' ";
    site << "style='padding: 12px; width:80%;max-width;500px; border-radius:25px; border:1px solid #ccc; font-size:16px;'>\n";
    site << "  </div>\n";

    site << "  <div class='container'>\n";
    site << ".hero-banner { background: linear-gradien(135deg, #1e3c72, #2a5298); color: white; padding: 30px; text-align: center: }";
    site << ".container { max-width: 800px; margin: auto; }";
    site << ".annonce { background: white; padding: 20px; margin-bottom: 15px; border-radius: 8px; box-shadow: 0 2px 4px rgba(0,0,0,0,1); position: relative; }";
    site << ".annonce:hover {transform: translateY(-5px); }\n";
    site << ".premium { border: 3px solid #FFD700; background-color: #fffef0; }";

    site << ".btn { display: inline-block; padding: 12px 20px; border-radius:25px; text-decoration: none; font-weigth; bold;color: white; margin-top: 10px; }\n";
    site << ".btn-tel { background-color: #27ae60 }\n";
    site << ".btn-mail { background-colog: #2980b9; margin-left: 10px; }\n";
    site << "</style>\n";
    site << "</head>\n";
    site << ".badge-gratuit { background: #2ecc71; color: white; padding: 3px 8px; border-radius: 4px; font-size: 0.8em; }";
    site << ".badge-premium { background: #FFD700; color: black; padding: 3px 8px; border-radius: 4px; font-size: 0.8em; font-weight: bold; }";
    site << "h2 { margin: 10px 0: color: #333; }";
    site << ".prix { color: #e74c3c; font-size: 1.2em; font-weight; bold; }";

    site << "<body>\n";
    site << "<div class='hero-banner'>\n";
    site << " <h1> Voitures Occasions Maroc</h1>\n";
    site << "<p>Le meilleur du marché automobile d'occasions au Royaume</p>\n";
    site << "</div>\n";
    site << "<div class='container'>\n";

    // Barre de recherche JavaScript
    site << "<div style='text-align:center; 20px;'>";
    site << "<input type='text' id='search' onkeyup='filtrer()' placeholder='Rechercher une marque...' style='padding:10px;width:50%;'>";
    site << "</div><div id='liste'>";

    // Boucle pour afficher les voitures avec photo
    for (const auto &v : stock)
    {
        if (v.estVendu)
            site << "<div class='badge-vendu>VENDU</div>";

        // Utilisation de lanouvelle varible photoUrl
        site << "<img src='" << v.photoUrl << "' class='photo'>";

        site << "<div class='info'>";
        site << "<h2>" << v.marque << "</h2>";
        site << "<p><b>Prix : " << v.prix << "</p>";
        site << "<p>Ville : " << v.ville << "</p>";

        // Accés à Facbook contact
        site << "<a href='" << v.lienFacebook << "' class='btn-fb'>Voir sur Facebook</a>";
        site << "</div></div";
    }
    site << "</div>";
    // Le script JavaScript pour filtrer
    site << "<script>function filtrer(){";
    site << "let val=document.getElementsByClassName('search').value.toLowerCase();";
    site << "let cards = document.getElementsByClassName('annonce');";
    site << "for(let c of cards){ c.style.display = c.innerText.toLowerCase().includes(val) ? '' : 'none'; }";
    site << "}</script></body></html>";

    site.close();
}

void chargerDonnees(std::vector<Voiture> &stock)
{
    std::ifstream fichier("annonces.txt");
    if (fichier)
    {
        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            Voiture v;
            size_t pos = 0;

            pos = ligne.find('|');
            v.marque = ligne.substr(0, pos);
            ligne.erase(0, pos + 1);

            pos = ligne.find('|');
            v.ville = ligne.substr(0, pos);
            ligne.erase(0, pos + 1);

            pos = ligne.find('|');
            v.prix = std::stoi(ligne.substr(0, pos));
            ligne.erase(0, pos + 1);

            pos = ligne.find('|');
            v.annee = ligne.substr(0, pos);
            ligne.erase(0, pos + 1);

            v.estPremium = (ligne == "1");

            stock.push_back(v);
        }
        fichier.close();
    }
}

int main()
{
    std::vector<Voiture> stock;

    chargerDonnees(stock);
    std::cout << "--- " << stock.size() << " annonces chargees ---\n";
    char continuer;

    std::cout << "---PLATEFORME AUTOMOBILE MAROC---\n";

    do
    {
        Voiture v; // Declaration propre au debut de la boucle

        std::cout << "\nMarque et Modele : ";
        std::getline(std::cin >> std::ws, v.marque);

        std::cout << "Ville : ";
        std::getline(std::cin, v.ville);

        std::cout << "Prix (DH) ";
        std::cin >> v.prix;

        std::cout << "Annee : ";
        std::cin >> v.annee;

        int choix;
        std::cout << "Activer le mode Premium ? (1 pour Oui, 0 pour Gratuit) : ";
        std::cin >> choix;
        v.estPremium = (choix == 1);

        stock.push_back(v);

        std::cout << "Numero de telephone : ";
        std::getline(std::cin >> std::ws, v.telephone);

        std::cout << "Email de contact : ";
        std::getline(std::cin, v.email);

        std::cin >> continuer;

    } while (continuer == 'o' || continuer == 'O');

    sauvegarderDonnees(stock);

    genererSiteWeb(stock);

    std:
    return 0;
}
