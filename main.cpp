/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:27:05 by thormster         #+#    #+#             */
/*   Updated: 2018/11/12 14:27:05 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "Game.hpp"

void        welcome()
{
    system("CLS");
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "                 THE BLACK GUARDIAN               " << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    system("PAUSE");
}

int         main(void)
{
    Game    game;

    welcome();
    while (!game.GetQuit())
    {
        game.update();
    }
    return (0);
}