/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageCreatorState.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:29:40 by thormster         #+#    #+#             */
/*   Updated: 2018/11/17 18:29:40 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef         __PERSONNAGE_CREATOR_STATE_HPP_
#define         __PERSONNAGE_CREATOR_STATE_HPP_

#include        <iomanip>
#include        <iostream>
#include        <stack>
#include        "Personnage.hpp"
#include        "Stats.hpp"

class           PersonnageCreatorState : public Stats
{
private:
    std::vector<Personnage*>*listePersonnage;
    std::stack<Stats*>*etat;
    unsigned&   personnageActif;
    const unsigned    maxPersonnages;
public:
    PersonnageCreatorState(std::vector<Personnage*>*listePersonnage, unsigned& personnageActif, std::stack<Stats*>*etat);
    virtual     ~PersonnageCreatorState();
    //Fonctions
    void        printMenu();
    void        updateMenu();
    void        update();
    void        creerPersonnage();
};

#endif /* __PERSONNAGECREATORSTATE_HPP__ */