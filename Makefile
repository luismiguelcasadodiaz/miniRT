# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:07:33 by luicasad          #+#    #+#              #
#    Updated: 2024/11/09 18:05:55 by luicasad         ###   ########.fr        #
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
SRCDIR_VEC3			= ./src/vec3/
SRCDIR_COLOR		= ./src/color/
SRCDIR_POINT		= ./src/point/
SRCDIR_RAY			= ./src/ray/
SRCDIR_ELEME		= ./src/eleme/
SRCDIR_CAMER		= ./src/camer/
SRCDIR_LIGHT		= ./src/light/
SRCDIR_AMBIL		= ./src/ambil/
SRCDIR_HITTABLE		= ./src/hittable/
SRCDIR_HITRECORD	= ./src/hitrecord/
SRCDIR_INTERVAL		= ./src/interval/
SRCDIR_GETNL		= ./src/getnl/
SRCDIR_CHUNK		= ./src/chunk/
#SRCDIR_SPHERE		= ./src/sphere/
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
WRNFL			= -Wall -Wextra -Werror -Wconversion -Wdouble-promotion #-fsanitize=address
DBGFL			= -g3  -pg
CFLGS			= $(DBGFL) $(WRNFL) -c 
HEADS			= -I$(INCDIR)
LFLGS 			=
LFLGS 			= #-fsanitize=address
FRAMEWORKS		=

# ============================================================================ #
#                              LIBRARIES SETUP                                 #
# ============================================================================ #

NAMELIBMLIBX 		= libmlx.a
PATH_MLIBX 			= $(addprefix $(SRCDIR_MLIBX), $(NAMELIBPRINTF))
LOADLIBMLIBX 		= mlx 

NAMELIBFT 			= libft.a
PATH_LIBFT 			= $(addprefix $(SRCDIR_LIBFT), $(NAMELIBFT))
LOADLIBFT 			= ft

NAMELIBVEC3			= libvec3.a
PATH_VEC3      		= $(addprefix $(SRCDIR_VEC3), $(NAMELIBVEC3))
LOADLIBVEC3      	= vec3

NAMELIBCOLOR		= libcolor.a
PATH_COLOR     		= $(addprefix $(SRCDIR_COLOR), $(NAMELIBCOLOR))
LOADLIBCOLOR      	= color

NAMELIBPOINT		= libpoint.a
PATH_POINT     		= $(addprefix $(SRCDIR_POINT), $(NAMELIBPOINT))
LOADLIBPOINT      	= point

NAMELIBRAY			= libray.a
PATH_RAY     		= $(addprefix $(SRCDIR_RAY), $(NAMELIBRAY))
LOADLIBRAY      	= ray

NAMELIBELEME		= libeleme.a
PATH_ELEME     		= $(addprefix $(SRCDIR_ELEME), $(NAMELIBELEME))
LOADLIBELEME      	= eleme

NAMELIBCAMER		= libcamer.a
PATH_CAMER     		= $(addprefix $(SRCDIR_CAMER), $(NAMELIBCAMER))
LOADLIBCAMER      	= camer

NAMELIBAMBIL		= libambil.a
PATH_AMBIL     		= $(addprefix $(SRCDIR_AMBIL), $(NAMELIBAMBIL))
LOADLIBAMBIL      	= ambil

NAMELIBLIGHT		= liblight.a
PATH_LIGHT     		= $(addprefix $(SRCDIR_LIGHT), $(NAMELIBLIGHT))
LOADLIBLIGHT      	= light

NAMELIBHITRECORD	= libhitrecord.a
PATH_HITRECORD 		= $(addprefix $(SRCDIR_HITRECORD), $(NAMELIBHITRECORD))
LOADLIBHITRECORD   	= hitrecord

NAMELIBHITTABLE		= libhittable.a
PATH_HITTABLE  		= $(addprefix $(SRCDIR_HITTABLE), $(NAMELIBHITTABLE))
LOADLIBHITTABLE    	= hittable

#NAMELIBSPHERE	 	= libsphere.a
#PATH_SPHERE  		= $(addprefix $(SRCDIR_SPHERE), $(NAMELIBSPHERE))
#LOADLIBSPHERE    	= sphere

NAMELIBINTERVAL	 	= libinterval.a
PATH_INTERVAL  		= $(addprefix $(SRCDIR_INTERVAL), $(NAMELIBINTERVAL))
LOADLIBINTERVAL    	= interval

NAMELIBGETNL	 	= libgetnl.a
PATH_GETNL  		= $(addprefix $(SRCDIR_GETNL), $(NAMELIBGETNL))
LOADLIBGETNL    	= getnl

NAMELIBCHUNK	 	= libchunk.a
PATH_CHUNK  		= $(addprefix $(SRCDIR_CHUNK), $(NAMELIBCHUNK))
LOADLIBCHUNK    	= chunk

#NAMELIBPRINTF 		= libftprintf.a
#PATH_PRINT 			= $(addprefix $(SRCDIR_PRINT), $(NAMELIBPRINTF))
#LOADLIBPRINTF 		= ftprintf

#NAMELIBFTCOMPLEX 	= libftcomplex.a
#PATH_FTCOMPLEX 		= $(addprefix $(SRCDIR_FTCOMPLEX), $(NAMELIBFTCOMPLEX))
#LOADLIBFTCOMPLEX 	= ftcomplex


#NAMELIBARGPA 		= libargpar.a
#PATH_ARGPA 		= $(addprefix $(SRCDIR_ARGPA), $(NAMELIBARGPA))
#LOADLIBARGPA 		= argpar
#MYLIBS			= $(NAMELIBMLIBX) $(NAMELIBPRINTF) $(NAMELIBFTCOMPLEX) $(NAMELIBFT)
#LLIBS 			= -L$(LIBDIR) -l$(LOADLIBMLIBX) -l$(LOADLIBPRINTF) -l$(LOADLIBFTCOMPLEX) -l$(LOADLIBFT)

MYLIBS			= $(NAMELIBMLIBX)
MYLIBS			+= $(NAMELIBCHUNK)
MYLIBS			+= $(NAMELIBELEME)
#MYLIBS			+= $(NAMELIBSPHERE)
MYLIBS			+= $(NAMELIBRAY)
MYLIBS			+= $(NAMELIBINTERVAL)
MYLIBS			+= $(NAMELIBHITTABLE)
MYLIBS			+= $(NAMELIBELEME)
MYLIBS			+= $(NAMELIBHITRECORD)
MYLIBS			+= $(NAMELIBCAMER)
MYLIBS			+= $(NAMELIBAMBIL)
MYLIBS			+= $(NAMELIBLIGHT)
MYLIBS			+= $(NAMELIBCOLOR)
MYLIBS			+= $(NAMELIBPOINT)
MYLIBS			+= $(NAMELIBVEC3)
MYLIBS			+= $(NAMELIBGETNL)
MYLIBS			+= $(NAMELIBFT)

LLIBS 			= -L$(LIBDIR) -l$(LOADLIBMLIBX)
LLIBS 			+= -l$(LOADLIBRAY)
LLIBS 			+= -l$(LOADLIBCHUNK)
LLIBS 			+= -l$(LOADLIBELEME)
#LLIBS 			+= -l$(LOADLIBSPHERE)
LLIBS 			+= -l$(LOADLIBINTERVAL)
LLIBS 			+= -l$(LOADLIBHITTABLE)
LLIBS 			+= -l$(LOADLIBHITRECORD)
LLIBS 			+= -l$(LOADLIBRAY)
LLIBS 			+= -l$(LOADLIBCAMER)
LLIBS 			+= -l$(LOADLIBAMBIL)
LLIBS 			+= -l$(LOADLIBLIGHT)
LLIBS 			+= -l$(LOADLIBCOLOR)
LLIBS 			+= -l$(LOADLIBPOINT)
LLIBS 			+= -l$(LOADLIBVEC3)
LLIBS 			+= -l$(LOADLIBGETNL)
LLIBS 			+= -l$(LOADLIBFT)
LLIBS 			+= -L$(LIBSYS) $(LOADLIBSYS) 

#LLIBS	+= -L/usr/include/../lib -lXext -lX11 -lm -lbsd

# ============================================================================ #
#                                 SOURCES                                      #
# ============================================================================ #

HEADER_iRT	=	miniRT.h
SRCS_MINRT	= 	miniRT.c \
				show_usage.c \
				show_data.c \
				win_create_world.c \
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
				is_scene1.c \
				is_scene2.c \
				is_scene3.c \
				is_scene4.c \
				is_white.c \

HEADER_BON	=	miniRT_bonus.h
SRCS_BONUS	 =	miniRT_bonus.c \
				show_usage_bonus.c \
				show_data_bonus.c \
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
$(NAMELIBFT): makelibft  $(LIBDIR)$(NAMELIBFT)
$(NAMELIBGETNL): makelibgetnl  $(LIBDIR)$(NAMELIBGETNL)
$(NAMELIBCHUNK): makelibchunk  $(LIBDIR)$(NAMELIBCHUNK)
$(NAMELIBVEC3): makelibvec3  $(LIBDIR)$(NAMELIBVEC3)
$(NAMELIBCOLOR): makelibcolor  $(LIBDIR)$(NAMELIBCOLOR)
$(NAMELIBPOINT): makelibpoint  $(LIBDIR)$(NAMELIBPOINT)
$(NAMELIBRAY): makelibray  $(LIBDIR)$(NAMELIBRAY)
$(NAMELIBELEME): makelibeleme  $(LIBDIR)$(NAMELIBELEME)
$(NAMELIBCAMER): makelibcamer  $(LIBDIR)$(NAMELIBCAMER)
$(NAMELIBAMBIL): makelibambil  $(LIBDIR)$(NAMELIBAMBIL)
$(NAMELIBLIGHT): makeliblight  $(LIBDIR)$(NAMELIBLIGHT)
$(NAMELIBHITRECORD): makelibhitrecord  $(LIBDIR)$(NAMELIBHITRECORD)
$(NAMELIBHITTABLE): makelibhittable  $(LIBDIR)$(NAMELIBHITTABLE)
$(NAMELIBINTERVAL): makelibinterval  $(LIBDIR)$(NAMELIBINTERVAL)
#$(NAMELIBSPHERE): makelibshpere  $(LIBDIR)$(NAMELIBSPHERE)
#$(NAMELIBPRINTF): makelibftprintf  $(LIBDIR)$(NAMELIBPRINTF)
#$(NAMELIBFTCOMPLEX): makelibftcomplex  $(LIBDIR)$(NAMELIBFTCOMPLEX)

makelibmlibx: 
	$(MAKE) -C $(SRCDIR_MLIBX)
	cp $(SRCDIR_MLIBX)$(NAMELIBMLIBX) $(LIBDIR)

makelibft:
	$(MAKE) -C $(SRCDIR_LIBFT)

makelibgetnl:
	$(MAKE) -C $(SRCDIR_GETNL)

makelibchunk:
	$(MAKE) -C $(SRCDIR_CHUNK)

makelibvec3:
	$(MAKE) -C $(SRCDIR_VEC3)

makelibcolor:
	$(MAKE) -C $(SRCDIR_COLOR)

makelibpoint:
	$(MAKE) -C $(SRCDIR_POINT)

makelibray:
	$(MAKE) -C $(SRCDIR_RAY)

makelibeleme:
	$(MAKE) -C $(SRCDIR_ELEME)

makelibcamer:
	$(MAKE) -C $(SRCDIR_CAMER)

makelibambil:
	$(MAKE) -C $(SRCDIR_AMBIL)

makeliblight:
	$(MAKE) -C $(SRCDIR_LIGHT)

makelibhitrecord:
	$(MAKE) -C $(SRCDIR_HITRECORD)

makelibhittable:
	$(MAKE) -C $(SRCDIR_HITTABLE)

makelibinterval:
	$(MAKE) -C $(SRCDIR_INTERVAL)

#makelibsphere:
#	$(MAKE) -C $(SRCDIR_SPHERE)

#makelibftprintf:
#	$(MAKE) -C $(SRCDIR_PRINT)

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
	$(MAKE) -C $(SRCDIR_VEC3) clean
	$(MAKE) -C $(SRCDIR_COLOR) clean
	$(MAKE) -C $(SRCDIR_POINT) clean
	$(MAKE) -C $(SRCDIR_RAY) clean
	$(MAKE) -C $(SRCDIR_ELEME) clean
	$(MAKE) -C $(SRCDIR_CAMER) clean
	$(MAKE) -C $(SRCDIR_AMBIL) clean
	$(MAKE) -C $(SRCDIR_LIGHT) clean
	$(MAKE) -C $(SRCDIR_HITRECORD) clean
	$(MAKE) -C $(SRCDIR_HITTABLE) clean
	$(MAKE) -C $(SRCDIR_INTERVAL) clean
#	$(MAKE) -C $(SRCDIR_SPHERE) clean
#	$(MAKE) -C $(SRCDIR_PRINT) clean
	$(MAKE) -C $(SRCDIR_GETNL) clean
	$(MAKE) -C $(SRCDIR_CHUNK) clean
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
	@echo "$(ORANGE)========== CHECKING NORME $(BONUS) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_BONUS)
#	@echo "$(MAGENTA)========== CHECKING NORME $(TESTS) ==============$(DEF_COLOR)"
#	norminette $(SRCDIR_TESTS)
#	@echo "$(WHITE)========== CHECKING NORME $(SRCDIR_PRINT) ==============$(DEF_COLOR)"
#	$(MAKE) -C $(SRCDIR_PRINT)  norma
#	@echo "$(WHITE)========== CHECKING NORME $(SRCDIR_FTCOMPLEX) ==============$(DEF_COLOR)"
#	$(MAKE) -C $(SRCDIR_FTCOMPLEX)  norma
	@echo "$(DARK_GRAY)========== CHECKING NORME $(SRCDIR_LIBFT) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_LIBFT)  norma
	@echo "$(YELLOW)========== CHECKING NORME $(SRCDIR_GETNL) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_GETNL)  norma
	@echo "$(DARK_GREEEN)========== CHECKING NORME $(SRCDIR_CHUNK) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_CHUNK)  norma
	@echo "$(BLUE)========== CHECKING NORME $(SRCDIR_VEC3) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_VEC3)  norma
	@echo "$(YELLOW)========== CHECKING NORME $(SRCDIR_COLOR) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_COLOR)  norma
	@echo "$(MID_GRAY)========== CHECKING NORME $(SRCDIR_POINT) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_POINT)  norma
	@echo "$(DARK_YELLOW)========== CHECKING NORME $(SRCDIR_ELEME) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_ELEME)  norma
	@echo "$(DARK_CYAN)========== CHECKING NORME $(SRCDIR_CAMER) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_CAMER)  norma
	@echo "$(DARK_GRAY)========== CHECKING NORME $(SRCDIR_AMBIL) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_AMBIL)  norma
	@echo "$(DARK_BLACK)========== CHECKING NORME $(SRCDIR_LIGHT) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_LIGHT)  norma
	@echo "$(DARK_BLUE)========== CHECKING NORME $(SRCDIR_HITTABLE) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_HITRECORD)  norma
	@echo "$(YELLOW)========== CHECKING NORME $(SRCDIR_HITRECORD) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_HITTABLE)  norma
#	@echo "$(MID_GRAY)========== CHECKING NORME $(SRCDIR_SPHERE) ==============$(DEF_COLOR)"
#	$(MAKE) -C $(SRCDIR_SPHERE)  norma
	@echo "$(DARK_GREEN)========== CHECKING NORME $(SRCDIR_INTERVAL) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_INTERVAL)  norma
	@echo "$(GREEN)============ CHECKING NORME $(INCDIR) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_RAY)  norma
	@echo "$(GREEN)============ CHECKING NORME $(MINRT) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_MINRT) 
	@echo "$(RED)========== CHECKING NORME $(SRCDIR_MLIBX) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_MLIBX)  norma
	norminette $(INCDIR)
	@echo "$(DARK_GREEN)========== CHECKING NORME $(SRCDIR_RAY) ==============$(DEF_COLOR)"

profile:
	valgrind --tool=callgrind ./$(MINRT) scenes/spheres.rt
	callgrind_annotate

leaks:
	valgrind -s --tool=memcheck --leak-check=full ./$(MINRT) scenes/sabado.rt

.PHONY: all bonus test clean fclean re rebonus norma profile leaks

