/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TravelMenuState.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:20:48 by thormster         #+#    #+#             */
/*   Updated: 2018/11/30 18:20:48 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __TRAVELMENUSTATE_HPP__
#define     __TRAVELMENUSTATE_HPP__

#include    <ctime>
#include    <iostream>
#include    <iomanip>
#include    <stack>
#include    "CombatState.hpp"
#include    "Personnage.hpp"
#include    "Stats.hpp"

enum        encounters { VIDE = 0, FORET, FERME, BOURG, SHOP, BANK };

class       TravelMenuState : public Stats
{
private:
    Personnage*& personnage;
    std::stack<Stats*>*etat;
    std::string locationString;
    std::string miniMapString;
    int     nbLieux;
public:
            TravelMenuState(Personnage*& personnage, std::stack<Stats*>*etat);
    virtual ~TravelMenuState();
    
    // Fonctions
    void        printMenu();
    void        update();
    void        updateMenu();
    void        updateMiniMap();
    void        updateEncounterMenu();
};

#endif/* __TRAVELSTATE_HPP__ */