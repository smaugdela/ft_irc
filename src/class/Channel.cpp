/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:06:15 by smagdela          #+#    #+#             */
/*   Updated: 2022/10/26 17:36:06 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libs.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Channel::Channel()
{
}

Channel::Channel(std::string name) : _name(name)
{
}

Channel::Channel( const Channel & src )
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Channel::~Channel()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Channel &				Channel::operator=( Channel const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Channel const & i )
{
	o << "Channel name: " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Channel::broadcast(std::string msg_str) const
{
	std::map<sockfd, Client*>::const_iterator it;

	for (it = _members.begin(); it != _members.end(); ++it)
		it->second->send_to(msg_str);
}

Client *Channel::getMember(std::string member) const
{
	std::map<sockfd, Client*>::const_iterator	it;

	for (it = _members.begin(); it != _members.end(); ++it)
		if (it->second->getNickname() == member)
			break ;
	if (it == _members.end())
		return NULL;
	return it->second;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const& Channel::getName(void) const
{
	return (this->_name);
}

std::map<sockfd, Client*> const&	Channel::getMembers(void) const
{
 	return (this->_)
}

/* ************************************************************************** */