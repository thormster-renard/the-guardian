/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgfonctions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thormster <thormster.renard@outlook.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:06:59 by thormster         #+#    #+#             */
/*   Updated: 2018/12/18 23:06:59 by thormster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     __MSGFONCTIONS_HPP__
#define     __MSGFONCTIONS_HPP__

#include    <iomanip>
#include    <sstream>
#include    <string>

namespace   gui
{
  const   std::string msgMenuTitre(const std::string);
  const   std::string msgMenuDiviseur(const unsigned, const char);
  const   std::string msgMenuItem(const int, const int, const std::string);
  const   std::string msgErreur(const std::string);
  const   std::string msgAlert(const std::string);
}
#endif /* __MSGFONTIONS_HPP__ */
