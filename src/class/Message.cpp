/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:04:49 by smagdela          #+#    #+#             */
/*   Updated: 2022/10/19 16:16:52 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libs.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Message::Message()
{
}

Message::Message(Client *sender, Client *receiver, char *message) : _sender(sender), _receiver(receiver)
{
	std::string str(message);
	this->_message = str;
}

Message::Message( const Message & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Message::~Message()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Message &				Message::operator=( Message const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Message const & i )
{
	o << "Raw message: " << i.getMessage();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const& Message::getMessage(void) const
{
	return (this->_message);
}

/* ************************************************************************** */