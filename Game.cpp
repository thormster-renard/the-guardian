/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:55:37 by thormster         #+#    #+#             */
/*   Updated: 2018/11/13 13:55:37 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "Game.hpp"

Game::Game()
{
    quit = false;
    this->personnageActif = 0;
    this->etat.push(new MainMenuState(&this->listePersonnage, this->personnageActif, &this->etat));
}

Game::~Game()
{
    int i;

    while (!this->etat.empty())
    {
        delete this->etat.top();
        this->etat.pop();
    }
    i = 0;
    while (i < this->listePersonnage.size())
    {
        delete this->listePersonnage[i];
        i += 1;
    }
}

void        Game::update()
{
    this->etat.top()->update();
    if (this->etat.top()->getQuit())
    {
        delete this->etat.top();
        this->etat.pop();
    }
    if (this->etat.empty())
        this->quit = true;
}

const bool&        Game::GetQuit() const
{
    return (this->quit);    
}