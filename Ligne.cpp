#include <iostream>
#include "Ligne.h"
#include "Partie.h"
#include "FonctionTri.h"

ligne::ligne()
{}

ligne::ligne(int ligne, int nBaton)
{
	m_ligne = ligne;
	m_nBaton = nBaton;
}

ligne::~ligne()
{}

ligne& ligne::setLigne(int ligne)
{
	m_ligne = ligne;
}

void ligne::display()
{
	int i = 0;
	std::cout << m_ligne <<": ";
	while (i < m_nBaton)
	{
		std::cout << "|" ;
		i ++;
	}
	std::cout << std::endl;
}
	
void ligne::remove(int total)
{
	int nbSup = 0;
	while (nbSup > m_nBaton || nbSup <= 0 || nbSup >= total) 
	{
		nbSup = triNbSup();
		if (nbSup > m_nBaton || nbSup <= 0 || nbSup >= total)
				std::cout << "Erreur, saisie incorrecte." << std::endl;
	}
	std::cout << std::endl;
	m_nBaton -= nbSup;
}