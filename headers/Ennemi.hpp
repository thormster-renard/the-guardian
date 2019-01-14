/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemi.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:04:08 by thormster         #+#    #+#             */
/*   Updated: 2018/12/06 12:04:08 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __ENNEMI_HPP__
#define     __ENNEMI_HPP__

#include    <string>
#include    <sstream>

class       Ennemi
{
private:
            int         niveau;
            int         pv;
            int         pvMax;
            int         degatsMin;
            int         degatsMax;
            int         defense;
            float       chance_toucher;
            float       chance_critique;

public:
                        Ennemi(int);
        virtual         ~Ennemi();

    // Accesseurs
    inline const bool   isDead() const { return (this->pv <= 0); }; //si PV <= 0 alors bool = true
    inline const int    getPV() const { return (this->pv); };
    inline const int    getPVMax() const { return (this->pvMax); };
    inline const int    getLevel() const { return (this->niveau); };
    inline const int    getDegatsMin() const { return (this->degatsMin); };
    inline const int    getDegatsMax() const { return (this->degatsMax); };
    inline const int    getDefense() const { return (this->defense); };
    inline const int    getChanceToucher() const { return (this->chance_toucher); };

    // Fonctions
    void                takeDegats(const int);
    void                setDead();
    const std::string   toStringStats();
};

#endif /* __ENNEMI_HPP__ */