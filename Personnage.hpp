/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Personnage.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:54:42 by thormster         #+#    #+#             */
/*   Updated: 2018/11/13 14:54:42 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __PERSONNAGE_HPP__
#define     __PERSONNAGE_HPP__

#include    <cmath>
#include    <iostream>
#include    <sstream>
#include    <string>
#include    <vector>
#include    "Inventaire.hpp"

class       Personnage
{
private:
    //Core
    std::string nom;
    std::string bio;
    bool premierLache;
    int niveau;
    int experience;
    int experience_suivante;
    int statpoints;
    int pv;
    int pvMax;
    int gold;
    int stamina;
    int staminaMax;

    int degatsMin;
    int degatsMax;
    int defense;
    float chance_toucher;
    float chance_critique;
    int mana;
    int manaMax;
    int trouvailles_magiques;
    // Attributs
    int force; //degats inflige
    int vitalite; // point_de_vie
    int agilite; // Defense && chance de parer
    int dexterite; // Chance de toucher et coups critiques
    int intelligence; // Mana && trouvailles magiques
    // Location
    unsigned x;
    unsigned y;
    
    // Inventaire
    Inventaire  inventaire;

    void updateStats();
public:
    Personnage(std::string nom, std::string bio);
    virtual ~Personnage();
    
    // Accessors
    inline const unsigned getSeed() const { return (this->x + this->y); };
    inline const unsigned getX() const { return (this->x); };
    inline const unsigned getY() const { return (this->y); };
    inline const bool isDead() const { return (this->pv <= 0); }; //si PV <= 0 alors bool = true
    inline const int getPV() const { return (this->pv); };
    inline const int getPVMax() const { return (this->pvMax); };
    inline const int getLevel() const { return (this->niveau); };
    inline const int getStamina() const { return (this->stamina); };
    inline const int getDegatsMin() const { return (this->degatsMin); };
    inline const int getDegatsMax() const { return (this->degatsMax); };
    inline const int getDefense() const { return (this->defense); };
    inline const int getChanceToucher() const { return (this->chance_toucher); };
    
    // Modifiers
    const std::string runAway();
                void  reset();
                void  takeDegats(const int);
                void  setDead();
                void  setPosition(const unsigned, const unsigned);
                void  move(const int, const int);
    
    // Fonctions
    std::string       getNom();
    const std::string getMenuBar();
    const std::string toString();
    const std::string toStringNameBio();
    const std::string toStringStats();
    const std::string toStringPosition();
                 bool canLevelUp();
                 void addExp(const unsigned);
};

#endif