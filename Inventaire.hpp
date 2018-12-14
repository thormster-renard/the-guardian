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

#include    "Item.hpp"

class       Inventaire
{
private:
    unsigned    capacity;
    unsigned    nbrItems;
    Item    **items;
    void    initialize(const unsigned);
    void    expand();
public:
            Inventaire(unsigned capacity = 10);
    virtual ~Inventaire();
};

#endif