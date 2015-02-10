##
## Makefile for UMLBuddy in /home/buchse_a/Projects/UMLBuddy/tmp
##
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
##
## Started on  Fri Feb  6 11:34:26 2015 Antoine Buchser
## Last update Tue Feb 10 12:45:54 2015 Antoine Buchser
##

CC		  =  clang++

NAME		  =  abstractvm

RM		  =  rm -f
MKDIR		  =  mkdir -p

SRCS_DIR	  =  src
SRCS		  =  main.cpp \
		     App.cpp \
		     Parser.cpp

OBJS_DIR	  =  obj
OBJS		  =  $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

INCS_DIR	  =  inc
INCS		  =  Exception.hpp \
		     App.hpp \
		     IOperand.hpp \
		     Operand.hpp \
		     Parser.hpp

DEPS		  =  $(patsubst %,$(INCS_DIR)/%,$(INCS))

CFLAGS		  += -I./inc
CFLAGS		  += -Wall -Wextra -W -Werror

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
