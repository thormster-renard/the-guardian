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

#include    "../headers/Game.hpp"

void        welcome()
{
#ifdef _WIN32
  system("CLS");
#elif __linux__
  system("clear");
#endif
  std::cout << "\n" << "\n";
  std::cout << std::string(4, ' ') << "--------------------------------------------------" << std::endl;
  std::cout << std::string(4, ' ') << "                 THE BLACK GUARDIAN               " << std::endl;
  std::cout << std::string(4, ' ') << "--------------------------------------------------" << std::endl;
  std::cout << "\n" << "\n";
#ifdef _WIN32
  system("PAUSE");
#elif __linux__
  std::cin.get();
#endif
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
