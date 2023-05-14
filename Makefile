# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 14:57:07 by hait-sal          #+#    #+#              #
#    Updated: 2023/05/07 17:58:06 by hait-sal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########### NAMES ###########
NAME = server

NAME_BONUS = server_bonus

CLIENT = client

CLIENT_BONUS = client_bonus

########### SOURCE FILES ###########
SRC_SERVER = server.c tools.c

SRC_CLIENT = client.c tools.c

SRC_SERVER_BONUS = bonus/server_bonus.c bonus/tools_bonus.c

SRC_CLIENT_BONUS = bonus/client_bonus.c bonus/tools_bonus.c

########### OBJECT FILES ###########
SERVER_OBJ = $(SRC_SERVER:.c=.o)

CLIENT_OBJ = $(SRC_CLIENT:.c=.o)

SERVER_BONUS_OBJ = $(SRC_SERVER_BONUS:.c=.o)

CLIENT_BONUS_OBJ = $(SRC_CLIENT_BONUS:.c=.o)

########### FLAGS ###########
FLAGS = -Wall -Werror -Wextra

########### REMAINING RULES ###########
all : $(NAME) $(CLIENT)

bonus : $(NAME_BONUS) $(CLIENT_BONUS)

########### MANDATORY PART ###########
$(NAME) : $(SERVER_OBJ) minitalk.h 
	@echo "server ✅"
	@cc $(SERVER_OBJ) $(FLAGS) -o $(NAME)

$(CLIENT) : $(CLIENT_OBJ) minitalk.h
	@echo "client ✅"
	@cc $(CLIENT_OBJ) $(FLAGS) -o $(CLIENT)

########### BONUS PART ###########
$(NAME_BONUS) : $(SERVER_BONUS_OBJ) bonus/minitalk_bonus.h
	@echo "server_bonus ✅"
	@cc $(SERVER_BONUS_OBJ) $(FLAGS) -o $(NAME_BONUS)
	
$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJ) bonus/minitalk_bonus.h
	@echo "client_bonus ✅"
	@cc $(CLIENT_BONUS_OBJ) $(FLAGS) -o $(CLIENT_BONUS)

%.o : %.c
	@cc $(FLAGS) -c $^ -o $@

clean :
	@echo "cleaning ✅"
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean : clean
	@echo "Super clean ✅"
	@rm -f $(NAME) $(CLIENT) $(NAME_BONUS) $(CLIENT_BONUS)

re : fclean all