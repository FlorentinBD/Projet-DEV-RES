#ifndef LIGNE_H
#define LIGNE_H

#include <string>

class ligne
{
private:
	int m_ligne;
	int m_nBaton;
	ligne();
public:
	ligne(int ligne, int nBaton);
	~ligne();

	int 	getLigne() const { return m_ligne; }
	int 	getNBaton() const { return m_nBaton; }

	ligne& 	setLigne(int ligne);

	void 	display();
	
	void 	remove(int total);

};

#endif  // LIGNE_H