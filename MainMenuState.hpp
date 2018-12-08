/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenuState.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:50:18 by thormster         #+#    #+#             */
/*   Updated: 2018/11/16 18:50:18 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef         __MAINMENUSTATE_HPP__
#define         __MAINMENUSTATE_HPP__

#include        <iomanip>
#include        <iostream>
#include        <stack>
#include        "PersonnageSelectorState.hpp"
#include        "PersonnageCreatorState.hpp"
#include        "GameState.hpp"

class           MainMenuState : public Stats
{
private:
    std::vector<Personnage*>*listePersonnage;
    std::stack<Stats*>*etat;
    unsigned personnageActif;
public:
    MainMenuState(std::vector<Personnage*>*listePersonnage, unsigned& personnageActif, std::stack<Stats*>*etat);
    virtual     ~MainMenuState();

    void        printMenu();
    void        updateMenu();
    void        update();
};

#endif