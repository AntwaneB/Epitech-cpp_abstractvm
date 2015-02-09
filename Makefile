##
## Makefile for UMLBuddy in /home/buchse_a/Projects/UMLBuddy/tmp
##
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
##
## Started on  Fri Feb  6 11:34:26 2015 Antoine Buchser
## Last update Fri Feb  6 11:34:28 2015 Antoine Buchser
##

CC		  =  g++

NAME		  =  abstractvm

RM		  =  rm -f
MKDIR		  =  mkdir -p

SRCS_DIR	  =  src
SRCS		  =  main.cpp

OBJS_DIR	  =  obj
OBJS		  =  $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

INCS_DIR	  =  inc
INCS		  =  

DEPS		  =  $(patsubst %,$(INCS_DIR)/%,$(INCS))

CFLAGS		  += -I./inc
CFLAGS		  += -Wall -Wextra -W -Werror -g

$(NAME):	     $(OBJS)
		     $(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all:		     $(NAME)

$(OBJS_DIR)/%.o:     $(SRCS_DIR)/%.cpp $(DEPS)
		     @$(MKDIR) $(OBJS_DIR)
		     $(CC) $(CFLAGS) -c -o $@ $<

clean:
		     $(RM) -r $(OBJS_DIR)

fclean:		     clean
		     $(RM) $(NAME)

re:		     fclean all

.PHONY: re fclean clean all
.SILENT:
