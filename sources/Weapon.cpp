/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:17:49 by thormster         #+#    #+#             */
/*   Updated: 2018/12/20 22:17:49 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "Weapon.hpp"

Weapon::Weapon(int degatsMin, int degatsMax, std::string nom, unsigned type, unsigned rarete, unsigned valeur) : Item(nom, type, rarete, valeur)
{
    this->degatsMin = degatsMin;
    this->degatsMax = degatsMax;
}

Weapon::~Weapon()
{}