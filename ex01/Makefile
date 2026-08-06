# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/02 13:28:35 by gyildiz           #+#    #+#              #
#    Updated: 2026/08/06 20:43:55 by gyildiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Serializer.cpp
OBJS = $(SRCS:.cpp=.o)
EXE_NAME = Serializer
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(EXE_NAME)

$(EXE_NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXE_NAME)

fclean: clean
	rm -rf $(EXE_NAME)

clean: 
	rm -rf $(OBJS)

re: fclean all

.PHONY: all fclean clean re