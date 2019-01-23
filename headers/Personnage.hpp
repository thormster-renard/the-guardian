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

enum stats { FORCE = 0, VITALITE, AGILITE, DEXTERITE, INTELLIGENCE };

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
    int location;

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

    // Armes
    Weapon      *weapon;

    // Armures
    Armure      *armorHead;
    Armure      *armorChest;
    Armure      *armorShoulders;
    Armure      *armorArms;
    Armure      *armorHand;
    Armure      *armorLegs;
    Armure      *armorFeet;

    // Inventaire
    Inventaire  inventaire;

    void updateStats();
public:
    Personnage(std::string nom, std::string bio);
    virtual ~Personnage();

    // Accesseurs
    inline const unsigned getSeed() const { return (this->x + this->y); };
    inline const unsigned getX() const { return (this->x); };
    inline const unsigned getY() const { return (this->y); };
    inline const bool isDead() const { return (this->pv <= 0); }; //si PV <= 0 alors bool = true
    inline const int getPV() const { return (this->pv); };
    inline const int getPVMax() const { return (this->pvMax); };
    inline const int getLevel() const { return (this->niveau); };
    inline const int getStamina() const { return (this->stamina); };
    inline const int getDefense() const { return (this->defense); };
    inline const int getChanceToucher() const { return (this->chance_toucher); };
    inline Inventaire& getInventaire() { return (this->inventaire); }
    const        int getAttribut(const unsigned);
    const        int getDegatsTotal() const;
    inline const int getLocation() const { return (this->location); }
    Weapon*          getWeapon();
    Armure*          getArmure(int);

    // Modifieurs
    const std::string runAway();
                void  reset();
                void  resetPV();
                void  takeDegats(const int);
                void  setDead();
                void  setLocation(const int);
                void  setPosition(const unsigned, const unsigned);
                void  move(const int, const int);
                void  setWeapon(Weapon*);
                void  setArmure(Armure*, const int);

    // Fonctions
    std::string       getNom();
    const int         getDegatsMin() const;
    const int         getDegatsMax() const;
    bool              addStatsPoints(const unsigned);
    bool              addExp(const unsigned);
    const std::string getMenuBar(const bool voirAttributs = false);
    const std::string toString();
    const std::string toStringNameBio();
    const std::string toStringStats();
    const std::string toStringPosition();
    const std::string toStringEquipe() const;
};

#endif /* __PERSONNAGE_HPP__ */