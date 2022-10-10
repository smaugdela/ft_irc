/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:40:31 by smagdela          #+#    #+#             */
/*   Updated: 2022/10/10 15:57:44 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

static bool	parse_input(int ac, const char **av, serv_env* env)
{
	if (ac != 3)
		return (false);
	std::string	port(av[1]);
	std::string	pwrd(av[2]);
	if (port.find_first_not_of("0123456789") == std::string::npos)
	{
		long portint = strtol(port.c_str(), NULL, 10);
		if (port.size() > 5 || portint < 1 || portint > 65536)
		{
			return false;
		}
		env->password = pwrd;
		env->port = portint;
		return true;
	}
	else
		return false;
}

static void	init_env(serv_env* env)
{
	size_t			max;
	std::ifstream	ifs;

	ifs.open("/proc/sys/net/ipv4/tcp_max_syn_backlog");
	if (ifs.fail())
		max = 10;
	else
		ifs >> max;
	ifs.close();
	env->max_backlogs = max;
}

static sockfd	start_listening(serv_env *env)
{
	struct protoent *protoent = shield<struct protoent*>(getprotobyname("tcp"), NULL, "getprotobyname", __FILE__, __LINE__);
	std::cout << "Protoent, prototcol name :" << protoent->p_name << "\nProtocol number : " << protoent->p_proto << std::endl;

	sockfd			sock = shield<sockfd>(socket(AF_INET, SOCK_STREAM, protoent->p_proto), -1, "socket", __FILE__, __LINE__);

	struct sockaddr_in	addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(env->port);
	memset(addr.sin_zero, 0, sizeof(addr.sin_zero));
	shield(bind(sock, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr)), -1, "bind", __FILE__, __LINE__);

	shield(listen(sock, env->max_backlogs), -1, "listen", __FILE__, __LINE__);

	std::cout << "Listening Socket : " << sock << "\nMax Backlogs: " << env->max_backlogs << std::endl;

	return sock;
}

int	main(int ac, const char **av)
{
	serv_env	env;

	shield(parse_input(ac, av, &env), false, "Usage: ./ircserv <port> <password>", __FILE__, __LINE__);
	std::cout << "Port : " << env.port << "\nPassword : " << env.password << std::endl;

	init_env(&env);

	start_listening(&env);


	/* Accept incoming connection requests from clients here */
	while (true)
	{
		shield(accept());
	}

	return EXIT_SUCCESS;
}
