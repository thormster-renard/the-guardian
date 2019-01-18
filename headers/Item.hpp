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

enum            item_types { WEAPON = 0, ARMOR, };
enum            item_raretes { COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY, MYTHIC };

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
    const std::string getTypeAsString() const;
    const std::string& getNom() const;
    const std::string getRareteAsString() const;
    const unsigned& getType() const;
    const unsigned& getRarete() const;
    const unsigned& getValeur() const;

    // Fonctions
    virtual const std::string toString() const = 0;
    virtual Item* clone() const = 0;
};

#endif  /* __ITEM_HPP__ */