/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:18:12 by thormster         #+#    #+#             */
/*   Updated: 2018/12/20 22:18:12 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __WEAPON_HPP__
# define    __WEAPON_HPP__

#include    "Item.hpp"

class       Weapon : public Item
{
private:
    int     degatsMin;
    int     degatsMax;
public:
            Weapon(int, int, std::string, unsigned, unsigned, unsigned);
    virtual ~Weapon();

    // Accesseurs
    inline const int& getDegatsMax() const { return (this->degatsMax); }
    inline const int& getDegatsMin() const { return (this->degatsMin); }

    // Fonctions
    Weapon* clone() const;
    const std::string toString() const;
};

#endif /* __WEAPON_HPP__ */