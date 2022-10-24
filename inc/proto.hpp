/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:41:25 by smagdela          #+#    #+#             */
/*   Updated: 2022/10/24 13:53:00 by smagdela         ###   ########.fr       */
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
void	setConfigData(Server *dataConfig);
bool	setData(std::string str, Server *dataConfig);
void	serv_send(sockfd clientfd, Server *server);
std::list<std::string> split(char *str, const char *delim);

/* Commandes */

void error(Server *serv, Message &msg);
void info(Server *serv, Message &msg);
void join(Server *serv, Message &msg);
void kick(Server *serv, Message &msg);
void my_kill(Server *serv, Message &msg);
void list(Server *serv, Message &msg);
void motd(Server *serv, Message &msg);
void names(Server *serv, Message &msg);
void nick(Server *serv, Message &msg);
void oper(Server *serv, Message &msg);
void part(Server *serv, Message &msg);
void ping(Server *serv, Message &msg);
void pong(Server *serv, Message &msg);
void privmsg(Server *serv, Message &msg);
void quit(Server *serv, Message &msg);
void squit(Server *serv, Message &msg);
void stats(Server *serv, Message &msg);
void topic(Server *serv, Message &msg);
void user(Server *serv, Message &msg);

#endif
