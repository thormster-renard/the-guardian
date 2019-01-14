/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageMenuState.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:00:53 by thormster         #+#    #+#             */
/*   Updated: 2018/11/23 19:00:53 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __PERSONNAGEMENUSTATE_HPP__
#define     __PERSONNAGEMENUSTATE_HPP__

#include        <iomanip>
#include        <iostream>
#include        <stack>
#include        "Personnage.hpp"
#include        "PersonnageStatMenuState.hpp"

class           PersonnageMenuState : public Stats
{
private:
    Personnage*& personnage;
    std::stack<Stats*>*etat;
public:
    PersonnageMenuState(Personnage*& personnage, std::stack<Stats*>*etat);
    virtual ~PersonnageMenuState();

    void        update();
    void        printMenu();
    void        updateMenu();
};

#endif /* __PERSONNAGEMENUSTATE_HPP__ */