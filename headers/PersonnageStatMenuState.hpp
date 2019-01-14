/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageStatMenuState.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:58:10 by thormster         #+#    #+#             */
/*   Updated: 2018/12/19 21:58:10 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __PERSONNAGESTATMENUSTATE_HPP__
#define     __PERSONNAGESTATMENUSTATE_HPP__

#include        <iomanip>
#include        <iostream>
#include        <stack>
#include        "Personnage.hpp"
#include        "Stats.hpp"

class           PersonnageStatMenuState : public Stats
{
private:
    Personnage*&    personnage;
    std::stack<Stats*>*etat;
public:
                PersonnageStatMenuState(Personnage*& personnage, std::stack<Stats*>*etat);
    virtual     ~PersonnageStatMenuState();

    //Fonctions
    void        printMenu();
    void        updateMenu();
    void        update();
};

#endif /* __PERSONNAGESTATMENUSTATE_HPP__ */