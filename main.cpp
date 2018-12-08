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

int         main(void)
{
    Game    game;

    while (!game.GetQuit())
    {
        game.update();
    }
    return (0);
}