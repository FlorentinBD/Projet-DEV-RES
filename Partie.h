#ifndef PARTIE_H_
#define PARTIE_H_

#include "Ligne.h"
#include "Joueur.h"
#include <string>
#include <map>

class partie
{
private:
	int 	m_nbLignes;
	int 	m_nbBaton;
	int 	m_numLigne;
	int 	m_total;
	std::map <int, ligne*> tab;
	std::map <int, joueur*> joueurT;
public:
	partie();
	~partie();

	int 	getNbLignes() const { return m_nbLignes; }
	int 	getNbBaton() const { return m_nbBaton; }
	int 	getNumLigne() const { return m_numLigne; }
	int 	getTotal() const { return m_total; }

	int 	setTotal(int total);

	void 	parametresDefault();

	void 	parametresPerso();

	void 	creaJoueurs();

	void 	deroulement();

	ligne* 	getMap(int num);

};

#endif  // PARTIE_H_		