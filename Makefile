# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 15:19:32 by bel-kase          #+#    #+#              #
#    Updated: 2023/02/12 22:15:28 by bel-kase         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_xoxo.c

CLIENT_SRC = client.c $(SRC)
SERVER_SRC = server.c $(SRC)


all : server client

server : $(SERVER_SRC)
	cc $(CFLAGS) $(SERVER_SRC) -o server

client : $(CLIENT_SRC)
	cc $(CFLAGS) $(CLIENT_SRC) -o client

clean :
	rm -f server client

fclean : clean 
	
re : fclean all