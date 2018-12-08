/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stats.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:24:57 by thormster         #+#    #+#             */
/*   Updated: 2018/11/13 14:24:57 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef             __STATS_HPP__
#define             __STATS_HPP__

#include            <iostream>
#include            <iomanip>

class               Stats
{
private:
    bool            quit;
public:
    // Constructeur / Destructeur
    Stats();
    virtual         ~Stats();
    // Accesseurs
    const bool&     getQuit() const;
    // Modifieurs
    void            setQuit(const bool);
    // Fonctions
    virtual int     getChoice() const;
    // Fonction virtuelle pure
    virtual void    update() = 0;
};

#endif /* __STATS_HPP__ */