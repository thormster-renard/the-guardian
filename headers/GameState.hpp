/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:04:33 by thormster         #+#    #+#             */
/*   Updated: 2018/11/13 19:04:33 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __GAMESTATE_HPP__
#define     __GAMESTATE_HPP__

#include    <fstream>
#include    <iomanip>
#include    <iostream>
#include    <stack>
#include    <vector>
#include    "CombatState.hpp"
#include    "Ennemi.hpp"
#include    "Stats.hpp"
#include    "Personnage.hpp"
#include    "PersonnageMenuState.hpp"
#include    "TravelMenuState.hpp"

class       GameState : public Stats
{
private:
    Personnage*&    personnage;
    std::stack<Stats*>*etat;
public:
            GameState(Personnage*& personnage, std::stack<Stats*>*etat);
    virtual ~GameState();
    
    // Fonctions       
    void    PrintMenu() const;
    void    updateMenu();
    void    update();
};

#endif