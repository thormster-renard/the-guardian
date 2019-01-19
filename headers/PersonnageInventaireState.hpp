/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonnageInventaireState.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:52:18 by thormster         #+#    #+#             */
/*   Updated: 2019/01/18 18:52:18 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __PERSONNAGEINVENTAIRESTATE_HPP__
#define     __PERSONNAGEINVENTAIRESTATE_HPP__

#include    <fstream>
#include    <iomanip>
#include    <iostream>
#include    <stack>
#include    <vector>
#include    "CombatState.hpp"
#include    "Stats.hpp"
#include    "Personnage.hpp"

class       PersonnageInventaireState : public Stats
{
    private:
        Personnage *personnage;
        std::stack<Stats*>*etat;
    public:
        PersonnageInventaireState(Personnage*&, std::stack<Stats*>*states);
virtual ~PersonnageInventaireState();

        // Fonctions
        void    PrintMenu() const;
        void    updateMenu();
        void    update();
};

#endif /* __PERSONNAGEINVENTAIRESTATE_HPP__ */