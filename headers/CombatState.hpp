/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CombatState.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 12:46:50 by thormster         #+#    #+#             */
/*   Updated: 2018/12/08 12:46:50 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __COMBATSTATE_HPP__
#define     __COMBATSTATE_HPP__

#include    "Ennemi.hpp"
#include    "Personnage.hpp"
#include    "PersonnageMenuState.hpp"
#include    "TravelMenuState.hpp"
#include    "Stats.hpp"

class       CombatState : public Stats
{
private:
  Personnage*&    personnage;
  std::stack<Stats*>*etat;
public:
  CombatState(Personnage*& personnage, std::stack<Stats*>*etat);
  virtual ~CombatState();

  // Fonctions
  void    debutCombat();
  void    printMenu();
  void    update();
  void    updateMenu();
  void    updateMiniMap();
  void    updateEncounterMenu();
};

#endif /* __COMBATSTATE_HPP__ */
