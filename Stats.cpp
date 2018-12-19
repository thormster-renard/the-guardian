/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stats.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:28:15 by thormster         #+#    #+#             */
/*   Updated: 2018/11/13 14:28:15 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include        "Stats.hpp"

Stats::Stats()
{
    this->quit = false;
}

Stats::~Stats()
{
}

const bool&     Stats::getQuit() const
{
    return (this->quit);
}

void            Stats::setQuit(const bool quit)
{
    this->quit = quit;
}

int             Stats::getChoice() const
{
    int     choice;

    choice = -1;
    std::cout << "    " << "| - [[ Entrez votre choix : ";
    std::cin >> std::setw(1) >> choice;
    while (!std::cin.good())
        {
            std::cout << msgErreur("Excusez-moi, mais..vous devez faire un choix qui.. et bien qui existe !");
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "    " << "| - [[ Entrez votre choix : ";
            std::cin >> std::setw(1) >> choice;
        }
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    return (choice);
}