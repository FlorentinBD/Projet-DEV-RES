#include <iostream>
#include "Joueur.h"

joueur::joueur()
{ m_score = 0;}

joueur::joueur(int num)
{
	m_num = num;
	std::cout << "Joueur " << m_num << " entrez votre nom: ";
	std::cin >> m_nom;
}

joueur::~joueur()
{}

joueur& joueur::setNom(std::string nom)
{
	m_nom = nom;
}

void joueur::incScore()
{
	m_score ++;
}