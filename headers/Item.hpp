/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:11:16 by thormster         #+#    #+#             */
/*   Updated: 2018/12/12 20:11:16 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef         __ITEM_HPP__
#define         __ITEM_HPP__

#include        <string>
#include        <sstream>

enum            item_types { ARME = 0, ARMURE = 0, };

class           Item
{
private:
    std::string nom;
    unsigned    type;
    unsigned    sousType;
    unsigned    rarete;
    unsigned    valeur;

    void        generate();
public:
                Item(std::string, unsigned, unsigned, unsigned);
        virtual ~Item();

    // Accesseurs
    const std::string& getNom();
    const unsigned& getType();
    const unsigned& getRarete();
    const unsigned& getValeur();

    // Fonctions
    const std::string toString() const;

};

#endif  /* __ITEM_HPP__ */