#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <string>

class joueur
{
private:
	std::string m_nom;
	int 		m_num;
	int 		m_score;
	joueur();
public:
	joueur(int num);
	~joueur();

	std::string getNom() const { return m_nom; }
	int 		getNum() const { return m_num; }
	int 		getScore() const { return m_score; }

	joueur& 	setNom(std::string nom);
	
	void 		incScore();

};

#endif // JOUEUR_H_