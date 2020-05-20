#include "Duree.h"

using namespace std;

Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
    if (minutes < 0 || secondes < 0)
    {
        cout << "erreur dans l'entrée de la date";
        exit(EXIT_FAILURE);
    }
    else if (m_minutes >= 60 || m_secondes >= 60)
    {
        cout << "changement de la date pour la reconvertir" << endl;
        while (m_secondes >= 60)
        {
            m_secondes = m_secondes - 60;
            m_minutes++;
        }
        while (minutes >= 60)
        {
            m_minutes = m_minutes - 60;
            m_heures++;
        }

        cout << "nouvelle durée valide :" << m_heures << ":" << m_minutes << ":" << m_secondes << endl;
    }
    
}

bool Duree::estEgal(Duree const& b) const
{
    //Teste si a.m_heure == b.m_heure etc.  
    if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes)
        return true;
    else
        return false;
}

bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)   // Si les heures sont différentes
        return true; 
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else              //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;
}

void Duree::afficher() const
{
    cout << m_heures << "h:" << m_minutes << "min:" << m_secondes << endl;
}


bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const& a, Duree const& b)
{
    return !(a==b); //On utilise l'opérateur == qu'on a défini précédemment !
}
bool operator<(Duree const &a, Duree const& b)
{
    return a.estPlusPetitQue(b);
}

bool operator>(Duree const &a, Duree const& b)
{
    return ! b.estPlusPetitQue(a);
}

bool operator<=(Duree const &a, Duree const& b)
{
    return a < b || a == b;
}
bool operator>=(Duree const &a, Duree const& b)
{
    return a > b || a == b;
}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree copie(a);   //On utilise le constructeur de copie de la classe Duree !
    copie += b;       //On appelle la méthode d'addition qui modifie l'objet 'copie'
    return copie;     //Et on renvoie le résultat. Ni a ni b n'ont changé.
}

Duree operator+(Duree const& duree, int secondes)
{
    Duree copie(duree);    //On utilise le constructeur de copie de la classe Duree !
    copie += secondes;     //On appelle la méthode d'addition qui modifie l'objet 'copie'
    return copie;          //Et on renvoie le résultat
}

Duree& Duree::operator+=(const Duree& a)
{
     //1 : ajout des secondes
    m_secondes += a.m_secondes;
    //Si le nombre de secondes dépasse 60, on rajoute des minutes
    //Et on met un nombre de secondes inférieur à 60
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

    //2 : ajout des minutes
    m_minutes += a.m_minutes;
    //Si le nombre de minutes dépasse 60, on rajoute des heures
    //Et on met un nombre de minutes inférieur à 60
    m_heures += m_minutes / 60;
    m_minutes %= 60;

    //3 : ajout des heures
    m_heures += a.m_heures;
    
    return *this;
}

Duree& Duree::operator+=(int secondes)
{
     //1 : ajout des secondes
    m_secondes += secondes;
    //Si le nombre de secondes dépasse 60, on rajoute des minutes
    //Et on met un nombre de secondes inférieur à 60
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

  
    //Si le nombre de minutes dépasse 60, on rajoute des heures
    //Et on met un nombre de minutes inférieur à 60
    m_heures += m_minutes / 60;
    m_minutes %= 60;

    return *this;
}

void Duree::afficher(ostream &flux) const
{
    flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}

ostream &operator<<( ostream &flux, Duree const& duree)
{
    duree.afficher(flux) ;
    return flux;
}
