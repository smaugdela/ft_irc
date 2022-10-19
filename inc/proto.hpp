/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:41:25 by smagdela          #+#    #+#             */
/*   Updated: 2022/10/19 16:46:51 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_HPP
# define PROTO_HPP

/* Templates */

template<typename T>
T	shield(T ft, T error, const char *description, const char *file, int line);
# include "shield.tpp"

/* Functions */

bool	parse_input(int ac, const char **av, Server *serv);
sockfd	start_listening(Server *serv);
void	server_loop(Server *serv);
void	serv_receive(sockfd client, Server *server);
void  setConfigData(Server *dataConfig);
bool	setData(std::string str, Server *dataConfig);

#endif
