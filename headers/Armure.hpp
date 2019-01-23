/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Armure.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:39:57 by thormster         #+#    #+#             */
/*   Updated: 2019/01/21 21:39:57 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __ARMURE_HPP__
#define     __ARMURE_HPP__

#include    <iostream>
#include    <sstream>
#include    <string>
#include    "Item.hpp"

enum armureTypes { ARMOR_HEAD = 0, ARMOR_CHEST, ARMOR_SHOULDERS, ARMOR_ARMS, ARMOR_HAND, ARMOR_LEGS, ARMOR_FEET };

class       Armure : public Item
{
    private:
        unsigned armorType;
        int defense;

    public:
            Armure(int, unsigned, std::string, unsigned, unsigned, unsigned);
    virtual ~Armure();

    // Accesseurs
    inline const int& getDefense() const { return (this->defense); }
    inline const int& getArmorType() const { return (this->armorType); }
    const std::string getArmorTypeAsString() const;

    // Fonctions
    Armure* clone() const;
    const std::string toString() const;
};

#endif /* __ARMURE_HPP__ */