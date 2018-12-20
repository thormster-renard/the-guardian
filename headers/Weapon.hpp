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

class       Weapon : public Item
{
private:
    int     degatsMin;
    int     degatsMax;
public:
            Weapon(int, int, std::string, unsigned, unsigned, unsigned);
    virtual ~Weapon;
};

#endif /* __WEAPON_HPP__ */