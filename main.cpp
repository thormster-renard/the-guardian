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
    std::cout << "\n" << "\n";
    std::cout << std::string(4, ' ') << "--------------------------------------------------" << std::endl;
    std::cout << std::string(4, ' ') << "                 THE BLACK GUARDIAN               " << std::endl;
    std::cout << std::string(4, ' ') << "--------------------------------------------------" << std::endl;
    std::cout << "\n" << "\n";
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