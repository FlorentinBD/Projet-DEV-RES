#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <sstream>
#include "FonctionTri.h"


void vider_buffer()
{
    std::cin.clear();
    std::cin.seekg(0, std::ios::end);

    if(!std::cin.fail())
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max());
    }

    else
    {
        std::cin.clear();
    }
}


//===========================================================
// Fonction de tri pour le numéro de ligne.
//===========================================================
int triNumLigne(void)
{
    unsigned short int numLigne;

    std::string temp;

    while(true)
    {
        std::cout << "Sur quelle ligne souhaitez vous enlever des batons: ";
        std::cin >> temp;

        if(std::cin.eof() || std::cin.bad())
        {
            std::cerr << "Une erreur interne est survenue." << std::endl;

            if(std::cin.eof())
            {
                break;
            }

            vider_buffer();

            continue;
        }

        else if(std::cin.fail() || temp.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Erreur, saisie incorrecte." << std::endl;

            vider_buffer();

            continue;
        }

        std::istringstream stream(temp);
        stream >> numLigne;

        if(stream.fail() || !stream.eof())
        {
            std::cerr << "Erreur, saisie incorrecte." << std::endl;
        }

        else
        {
            break;
        }
    }

    return (numLigne);
}


//===========================================================
// Fonction de tri pour le nombre de battons a supprimer.
//===========================================================
int triNbSup(void)
{
    unsigned short int nbSup;

    std::string temp;

    while(true)
    {
        std::cout << "Combien de batons souhaitez-vous retirer: ";
        std::cin >> temp;

        if(std::cin.eof() || std::cin.bad())
        {
            std::cerr << "Une erreur interne est survenue." << std::endl;

            if(std::cin.eof())
            {
                break;
            }

            vider_buffer();

            continue;
        }

        else if(std::cin.fail() || temp.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Erreur, saisie incorrecte." << std::endl;

            vider_buffer();

            continue;
        }

        std::istringstream stream(temp);
        stream >> nbSup;

        if(stream.fail() || !stream.eof())
        {
            std::cerr << "Erreur, saisie incorrecte." << std::endl;
        }

        else
        {
            break;
        }
    }

    return (nbSup);
}


//==================================================================
// Fonction de tri pour le nombre de lignes souhaités en parametres.
//==================================================================
int triNbLignes(void)
{
    unsigned short int nbLignes;

    std::string temp;

    while(true)
    {
        std::cout << "Entrez le nombre de lignes que vous souhaitez (inférieur à 10): ";
        std::cin >> temp;

        if(std::cin.eof() || std::cin.bad())
        {
            std::cerr << "Une erreur interne est survenue." << std::endl;

            if(std::cin.eof())
            {
                break;
            }

            vider_buffer();

            continue;
        }

        else if(std::cin.fail() || temp.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Erreur, saisie incorrecte." << std::endl;

            vider_buffer();

            continue;
        }

        std::istringstream stream(temp);
        stream >> nbLignes;

        if(stream.fail() || !stream.eof())
        {
            std::cerr << "Erreur, saisie incorrecte." << std::endl;
        }

        else
        {
            break;
        }
    }

    return (nbLignes);
}



//===================================================================
// Fonction de tri pour le nombre de battons souhaités sur une ligne.
//===================================================================
int triNbBaton(int i)
{
    unsigned short int nbBaton;

    std::string temp;

    while(true)
    {
        std::cout << "Entrez le nombre de batons souhaités (inférieur à 50) sur la ligne " << i << ": ";
        std::cin >> temp;

        if(std::cin.eof() || std::cin.bad())
        {
            std::cerr << "Une erreur interne est survenue." << std::endl;

            if(std::cin.eof())
            {
                break;
            }

            vider_buffer();

            continue;
        }

        else if(std::cin.fail() || temp.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Erreur, saisie incorrecte." << std::endl;

            vider_buffer();

            continue;
        }

        std::istringstream stream(temp);
        stream >> nbBaton;

        if(stream.fail() || !stream.eof())
        {
            std::cerr << "Erreur, saisie incorrecte." << std::endl;
        }

        else
        {
            break;
        }
    }

    return (nbBaton);
}