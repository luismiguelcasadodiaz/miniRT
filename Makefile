# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:07:33 by luicasad          #+#    #+#              #
#    Updated: 2024/09/08 11:47:11 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
BLACK			=	\033[0;99m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;2;184;143;29m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;2;75;179;82m
DARK_YELLOW		=	\033[38;5;143m
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #

MINRT 			= miniRT
BONUS 			= miniRT_bonus
TESTS			= fenetre

# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
OPSYS := $(shell uname)
SRCDIR_MINRT		= ./src/miniRT/
SRCDIR_BONUS		= ./src/miniRT_bonus/
SRCDIR_TESTS		= ./src/tests/
SRCDIR_LIBFT		= ./src/libft/
#SRCDIR_FTCOMPLEX	= ./src/compl/
SRCDIR_MLIBX		= ./src/minilibx-linux/

OBJDIR 			= ./obj/
INCDIR 			= ./inc/
LIBDIR			= ./lib/
LIBSYS			= /usr/include/../lib 
LOADLIBSYS		= -lXext -lX11 -lm -lbsd
REQUIRED_DIRS	= $(OBJDIR) $(INCDIR) $(LIBDIR)
vpath %.a $(LIBDIR)
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 				= cc
WRNFL			= -Wall -Wextra -Werror ####-fsanitize=address
DBGFL			= -g3  -pg
CFLGS			= $(DBGFL) $(WRNFL) -c 
HEADS			= -I$(INCDIR)
LFLGS 			=
LFLGS 			= ####-fsanitize=address
FRAMEWORKS		=

# ============================================================================ #
#                              LIBRARIES SETUP                                 #
# ============================================================================ #

NAMELIBMLIBX 		= libmlx.a
PATH_MLIBX 			= $(addprefix $(SRCDIR_MLIBX), $(NAMELIBPRINTF))
LOADLIBMLIBX 		= mlx 

#NAMELIBPRINTF 		= libftprintf.a
#PATH_PRINT 			= $(addprefix $(SRCDIR_PRINT), $(NAMELIBPRINTF))
#LOADLIBPRINTF 		= ftprintf

#NAMELIBFTCOMPLEX 	= libftcomplex.a
#PATH_FTCOMPLEX 		= $(addprefix $(SRCDIR_FTCOMPLEX), $(NAMELIBFTCOMPLEX))
#LOADLIBFTCOMPLEX 	= ftcomplex

NAMELIBFT 			= libft.a
PATH_LIBFT 			= $(addprefix $(SRCDIR_LIBFT), $(NAMELIBFT))
LOADLIBFT 			= ft

#NAMELIBARGPA 		= libargpar.a
#PATH_ARGPA 		= $(addprefix $(SRCDIR_ARGPA), $(NAMELIBARGPA))
#LOADLIBARGPA 		= argpar
#MYLIBS			= $(NAMELIBMLIBX) $(NAMELIBPRINTF) $(NAMELIBFTCOMPLEX) $(NAMELIBFT)
#LLIBS 			= -L$(LIBDIR) -l$(LOADLIBMLIBX) -l$(LOADLIBPRINTF) -l$(LOADLIBFTCOMPLEX) -l$(LOADLIBFT)

MYLIBS			= $(NAMELIBMLIBX) $(NAMELIBFT)
LLIBS 			= -L$(LIBDIR) -l$(LOADLIBMLIBX) -l$(LOADLIBFT) -L$(LIBSYS) $(LOADLIBSYS) 

#LLIBS	+= -L/usr/include/../lib -lXext -lX11 -lm -lbsd

# ============================================================================ #
#                                 SOURCES                                      #
# ============================================================================ #

HEADER_iRT	=	miniRT.h
SRCS_MINRT	= 	miniRT.c \
				show_usage.c \
				show_data.c \
				point_init.c \
				point_set.c \
				win_init.c \
				win_h_key_down.c \
				win_h_key_up.c \
				win_h_mouse_down.c \
				win_h_mouse_up.c \
				win_h_mouse_move.c \
				win_h_not_event.c \
				win_h_destroy.c \
				win_h_expose.c \
				win_pixel_put.c \
				draw_fractal.c \
				col_create.c \
				is_scene1.c \
				is_white.c

HEADER_BON	=	miniRT_bonus.h
SRCS_BONUS	 =	miniRT_bonus.c \
				show_usage_bonus.c \
				show_data_bonus.c \
				point_init_bonus.c \
				point_set_bonus.c \
				win_init_bonus.c \
				win_h_key_down_bonus.c \
				win_h_key_up_bonus.c \
				win_h_mouse_down_bonus.c \
				win_h_mouse_up_bonus.c \
				win_h_mouse_move_bonus.c \
				win_h_not_event_bonus.c \
				win_h_destroy_bonus.c \
				win_h_expose_bonus.c \
				win_pixel_put_bonus.c \
				draw_fractal_bonus.c \
				col_create_bonus.c \
				is_white_bonus.c

HEADER_TES	=	fenetre.h
SRCS_TESTS	=	fenetre.c

FILE_MINRT = $(addprefix $(SRCDIR_MINRT), $(SRCS_MINRT))
FILE_BONUS = $(addprefix $(SRCDIR_BONUS), $(SRCS_BONUS))
FILE_TESTS = $(addprefix $(SRCDIR_TESTS), $(SRCS_TESTS))

OBJS_MINRT = $(addprefix $(OBJDIR), $(SRCS_MINRT:.c=.o))
OBJS_BONUS = $(addprefix $(OBJDIR), $(SRCS_BONUS:.c=.o))
OBJS_TESTS = $(addprefix $(OBJDIR), $(SRCS_TESTS:.c=.o))

DEPE_MINRT = $(addprefix $(OBJDIR), $(SRCS_MINRT:.c=.d))
DEPE_BONUS = $(addprefix $(OBJDIR), $(SRCS_BONUS:.c=.d))
DEPE_TESTS = $(addprefix $(OBJDIR), $(SRCS_TESTS:.c=.d))

#$(info minrt source files $(SRCS_MINRT))
#$(info minrt source paths $(FILE_MINRT))
#$(info minrt object patha $(OBJS_MINRT))

#$(info bonus source files $(SRCS_BONUS))
#$(info bonus source paths $(FILE_BONUS))
#$(info bonus object patha $(OBJS_BONUS))

#$(info tests source files $(SRCS_TESTS))
#$(info tests source paths $(FILE_TESTS))
#$(info tests object patha $(OBJS_TESTS))

$(info tests object patha $(LLIBS))

# ============================================================================ #
#                                 RULES                                        #
# ============================================================================ #
all: makedirs makelibs $(MINRT)
-include $(DEPE_FRACT)

bonus: makedirs makelibs $(BONUS)
-include $(DEPE_BONUS)

tests: makedirs makelibs $(TESTS)
-include $(DEPE_TESTS)

# .......................... directories creation ............................ #

makedirs:
	$(shell for d in $(REQUIRED_DIRS); \
 				do \
 					[[ -d $$d ]] || mkdir -p $$d; \
 				done)


# .......................... library construction ............................ #
makelibs: $(MYLIBS) 

$(NAMELIBMLIBX): makelibmlibx $(LIBDIR)$(NAMELIBMLIBX)
#$(NAMELIBPRINTF): makelibftprintf  $(LIBDIR)$(NAMELIBPRINTF)
$(NAMELIBFT): makelibft  $(LIBDIR)$(NAMELIBFT)
#$(NAMELIBFTCOMPLEX): makelibftcomplex  $(LIBDIR)$(NAMELIBFTCOMPLEX)

makelibmlibx: 
	$(MAKE) -C $(SRCDIR_MLIBX)
	cp $(SRCDIR_MLIBX)$(NAMELIBMLIBX) $(LIBDIR)

#makelibftprintf:
#	$(MAKE) -C $(SRCDIR_PRINT)

makelibft:
	$(MAKE) -C $(SRCDIR_LIBFT)

#makelibftcomplex:
#	$(MAKE) -C $(SRCDIR_FTCOMPLEX)
 
# ....................... dependencies construction .......................... #
#for each c file create its dependency file 
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
#READ GNU gcc manuel 3.13 Options controlling the preprocessor.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

# .......................... targets construction ............................ #
$(MINRT): Makefile  $(OBJS_MINRT) -l$(LOADLIBMLIBX) 
	@echo "$(GREEN)========== GATHERING MINIRT OBJECTS =============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_MINRT) -o $@ $(LLIBS) $(FRAMEWORKS)

$(BONUS): Makefile $(OBJS_BONUS) -l$(LOADLIBMLIBX)
	@echo "$(ORANGE)======= GATHERING MINIRT BONUS OBJECTS ============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_BONUS) -o $@ $(LLIBS) $(FRAMEWORKS)

$(TESTS): Makefile $(OBJS_TESTS) -l$(LOADLIBMLIBX)
	@echo "$(MAGENTA)========== GATHERING TESTS OBJECTS ===============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_TESTS) -o $@ $(LLIBS) $(FRAMEWORKS)

# .......................... objects construction ............................ #
$(OBJDIR)%.o: $(SRCDIR_MINRT)%.c $(INCDIR)$(HEADER_iRT)
	@echo "$(GREEN)========== COMPILING MINIRT FILES ===============$(DEF_COLOR)"
	$(CC) $(CFLGS) $< -o $@ $(HEADS)  

$(OBJDIR)%.o: $(SRCDIR_BONUS)%.c $(INCDIR)$(HEADER_BON)
	@echo "$(ORANGE)========== COMPILING MINIRT BONUS FILES ===============$(DEF_COLOR)"
	$(CC) $(CFLGS) $< -o $@ $(HEADS)  

$(OBJDIR)%.o: $(SRCDIR_TESTS)%.c $(INCDIR)$(HEADER_TES)
	@echo "$(MAGENTA)========== COMPILING TESTS FILES ===============$(DEF_COLOR)"
	$(info source files $(SRCS_TESTS))
	$(info source paths $(FILE_TESTS))
	$(info object patha $(OBJS_TESTS))
	$(CC) $(CFLGS) $< -o $@ $(HEADS)  


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		:\n	$(SRC)\n"
	@printf "OBJ		:\n	$(OBJ)\n"

clean:
	rm -f $(NAME) $(OBJ)
	rm -rf $(OBJDIR)
	$(MAKE) -C $(SRCDIR_MLIBX) clean
#	$(MAKE) -C $(SRCDIR_PRINT) clean
	$(MAKE) -C $(SRCDIR_LIBFT) clean


fclean: clean
	rm -f $(MINRT)
	rm -f $(BONUS)
	rm -f $(TESTS)
	rm -rf $(LIBDIR)
	rm -rf $(OBJDIR)

re: fclean all

rebonus : fclean bonus

norma:
	@echo "$(GREEN)============ CHECKING NORME $(MINRT) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_MINRT) 
	@echo "$(ORANGE)========== CHECKING NORME $(BONUS) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_BONUS)
	@echo "$(MAGENTA)========== CHECKING NORME $(TESTS) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_TESTS)
#	@echo "$(WHITE)========== CHECKING NORME $(SRCDIR_PRINT) ==============$(DEF_COLOR)"
#	$(MAKE) -C $(SRCDIR_PRINT)  norma
#	@echo "$(WHITE)========== CHECKING NORME $(SRCDIR_FTCOMPLEX) ==============$(DEF_COLOR)"
#	$(MAKE) -C $(SRCDIR_FTCOMPLEX)  norma
	@echo "$(GREEN)============ CHECKING NORME $(INCDIR) ==============$(DEF_COLOR)"
	norminette $(INCDIR)
	@echo "$(WHITE)========== CHECKING NORME $(SRCDIR_MLIBX) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_MLIBX)  norma

profile:
	valgrind --tool=callgrind ./$(MINRT) tirame
	callgrind_annotate

.PHONY: all bonus test clean fclean re rebonus norma profile

