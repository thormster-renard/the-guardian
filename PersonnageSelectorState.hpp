/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageSelectorState.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:50:22 by thormster         #+#    #+#             */
/*   Updated: 2018/11/29 21:50:22 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __PERSONNAGESELECTORSTATE_HPP__
#define     __PERSONNAGESELECTORSTATE_HPP__

#include    <iostream>
#include    <iomanip>
#include    <stack>
#include    <vector>
#include    "Personnage.hpp"
#include    "Stats.hpp"

class       PersonnageSelectorState : public Stats
{
private:
    std::vector<Personnage*>*listePersonnage;
    std::stack<Stats*>*etat;
    unsigned personnageActif;
public:
    PersonnageSelectorState(std::vector<Personnage*>*listePersonnage, unsigned& personnageActif, std::stack<Stats*>*etat);
    virtual ~PersonnageSelectorState();

    //Fonctions
    void        printMenu();
    void        updateMenu();
    void        update();
};

#endif