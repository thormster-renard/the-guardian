/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgfonctions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:07:52 by thormster         #+#    #+#             */
/*   Updated: 2018/12/18 23:07:52 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../headers/msgfonctions.hpp"

const std::string gui::msgMenuTitre(const std::string titre)
{
  std::stringstream ss;

  ss << "\n" << "     ----------- [[ " << titre << " ]] -----------" << "\n" << "\n";
  return (ss.str());
}

const std::string gui::msgMenuDiviseur(const unsigned nombre, const char symbole)
{
  std::stringstream ss;

  ss << "      " << std::string(nombre, symbole) << "\n" << "\n";
  return (ss.str());
}

const std::string gui::msgMenuItem(const int nbrSpace, const int nombre, const std::string item)
{
  std::stringstream ss;

  ss << std::string(nbrSpace, ' ') << "|  [ " << nombre << " ] " << item << "\n" << "\n";
  return (ss.str());
}

const std::string gui::msgErreur(const std::string erreur)
{
  std::stringstream ss;

  ss << std::string(4, ' ') << " (!)  [[ " << erreur << " ]]" << "\n" << "\n";
  return (ss.str());
}

const std::string gui::msgAlert(const std::string erreur)
{
  std::stringstream ss;

  ss << std::string(4, ' ') << " [[ (*) " << erreur << " ]]" << "\n" << "\n";
  return (ss.str());
}
