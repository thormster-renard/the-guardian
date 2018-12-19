/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:27:37 by thormster         #+#    #+#             */
/*   Updated: 2018/11/12 14:27:37 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef           __GAME_HPP__
#define           __GAME_HPP__

#include          <iostream>
#include          <stack>
#include          <vector>
#include          "MainMenuState.hpp"

class             Game
{
private:
  bool          quit;
  std::stack<Stats*> etat;
  std::vector<Personnage*>listePersonnage;
  unsigned personnageActif;
public:
  Game();
  virtual ~Game();
  const bool&   GetQuit() const;
  void          update();
};

#endif /* __GAME_HPP__ */