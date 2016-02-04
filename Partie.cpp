#include <iostream>
#include <string>
#include <algorithm>
#include "Partie.h"
#include "Joueur.h"
#include "FonctionTri.h"

partie::partie()
{

std::cout << "***********************" "\n" "Welcome to the Nim Game"
			"\n" "***********************" "\n"	<<std::endl;
}

partie::~partie()
{}

int partie::setTotal(int total) {
	m_total = total;
}

void partie::creaJoueurs()
{
	joueurT[1] = new joueur(1);
	joueurT[2] = new joueur(2);
}

void partie::parametresDefault()
{
	m_nbLignes = 4;
	m_nbBaton = 1; 


 	for (int i = 1; i <= m_nbLignes; i ++)
 	{
 		tab[i] = new ligne(i, m_nbBaton);
 		m_nbBaton += 2;
 		tab[i]->display();
 	}

 	std::cout << std::endl;
}

void partie::parametresPerso()
{
	m_nbLignes = 0;
	while (m_nbLignes > 9 || m_nbLignes <= 0)
	{ 		
		m_nbLignes = triNbLignes();
		if (m_nbLignes > 9 || m_nbLignes <= 0)
				std::cout << "Erreur, saisie incorrecte." << std::endl;
	}

	std::cout << std::endl;
 	for (int i = 1; i <= m_nbLignes; i ++)
 	{
 		m_nbBaton = 0;
 		while (m_nbBaton > 50 || m_nbBaton <= 0)
 		{
 			m_nbBaton = triNbBaton(i);
 			if (m_nbBaton > 50 || m_nbBaton <= 0)
				std::cout << "Erreur, saisie incorrecte." << std::endl;
 		}

 		tab[i] = new ligne(i, m_nbBaton);
 	}
	std::cout << std::endl;

 	for (int i = 1; i <= m_nbLignes; i ++)
 	{
 		tab[i]->display();
 	}
 	std::cout << std::endl;
}

void partie::deroulement()
{
	int numLigne =0;
	int jActuel = 2;
	std::string parametre;
	std::string replay;

	m_total = 0;

	std::cout << "Voulez-modifier les paramètres ? oui ou non: "; 
	std::cin >> parametre;
	std::cout << std::endl;

	std::transform(parametre.begin(), parametre.end(), parametre.begin(), ::tolower);

	if (parametre == "oui")
	{
		parametresPerso();
	}
	else
	{
		parametresDefault(); 
	}

	for (int i = 1; i <= m_nbLignes; i ++)
 	{
 		m_total += (tab[i]->getNBaton());
 	}

	while(m_total != 1)
	{
		if (jActuel == 1)
 		{
 			jActuel = 2;
 		} else {
 			jActuel = 1;
 		}
 		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << "C'est au tour de " << joueurT[jActuel]->getNom() << " de jouer !"<< std::endl;
		numLigne = 0;
		while (numLigne > m_nbLignes || numLigne <= 0 || tab[numLigne]->getNBaton() == 0)
		{
			numLigne = triNumLigne();
			if (numLigne > m_nbLignes || numLigne <= 0 || tab[numLigne]->getNBaton() == 0)
				std::cout << "Erreur, saisie incorrecte." << std::endl;
		}

		tab[numLigne]->remove(m_total);


		for (int i = 1; i <= m_nbLignes; i ++)
 		{
 			tab[i]->display();
 		}
 		std::cout << std::endl;

 		m_total = 0;
 		for (int i = 1; i <= m_nbLignes; i ++)
 		{
 			m_total += (tab[i]->getNBaton());
 		}
 		
 	}
 	joueurT[jActuel]->incScore();
 	std::cout << joueurT[jActuel]->getNom() << " a gagné !" << std::endl;
 	std::cout << joueurT[1]->getNom() << " : " << joueurT[1]->getScore() << " - " 
 			  << joueurT[2]->getScore() << " : " << joueurT[2]->getNom() << std::endl;
 	std::cout << "Souhaitez vous rejouer une partie ? oui ou non: "; 
 	std::cin >> replay;
 	std::transform(replay.begin(), replay.end(), replay.begin(), ::tolower);
 	if (replay == "oui")
 	{
 		std::cout << "=============================================================" << std::endl;
 		deroulement();
 	}

}

ligne* partie::getMap(int num)
{
	return(tab[num]);
}