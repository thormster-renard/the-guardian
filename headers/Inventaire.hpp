/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventaire.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:15:38 by thormster         #+#    #+#             */
/*   Updated: 2018/12/12 20:15:38 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __INVENTAIRE_HPP__
#define     __INVENTAIRE_HPP__

#include    <sstream>
#include    <string>
#include    "msgfonctions.hpp"
#include    "Weapon.hpp"

class       Inventaire
{
private:
    unsigned    capacite;
    unsigned    nbrItems;
    Item        **items;

    // Fonctions privées
    void    initialize(const unsigned);
    void    expand();
public:
    // Constructeurs & Destructeurs
            Inventaire(unsigned capacity = 10);
            Inventaire(const Inventaire&);
    virtual ~Inventaire();

    // Operateurs
    void    operator=(const Inventaire&);
    Item    &operator[](const unsigned);

    // Accesseurs
    const unsigned &size() const;
    const unsigned &capaciteTot() const;
    Item& at(const unsigned);

    // Modifieurs
    // Fonctions
    void    add(const Item&);
    void    del(const unsigned);
    std::string toString() const;
};

#endif /* __INVENTAIRE_HPP__ */