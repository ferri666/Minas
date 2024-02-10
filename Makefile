
NAME 			= minas
LIBFT_DIR		= libft/
LIBFT			= $(LIBFT_DIR)/libft.a

SRC_FILES		= validate minas error utils load game game_utils stat draw map main
SRC_DIR			= srcs/
OBJ_DIR			= objs/
INCLUDE			= include/

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE)
MFLAGS			= -ldl -lm -lmlx -framework OpenGL -framework AppKit -lz

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

$(NAME)			:	$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(MFLAGS) $^ -o $@ 
					@echo "Program Created"

all:				$(NAME)


$(LIBFT)		:	$(LIBFT_DIR)
					@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^
					

clean:
	@echo "Clean Boys!"
	@$(RM) ${OBJ}
	@make -C $(LIBFT_DIR) clean
	@${RM} -r ${OBJ_DIR} 

fclean: clean
	@echo "Super Clean Boys!"
	@${RM} ${OBJS} ${NAME} ${LIBFT}
	@make -C $(LIBFT_DIR) fclean

re: fclean all
re-bonus: fclean bonus
re-all: fclean all bonus

norm:          
		@norminette $(INCLUDE) $(LIBFT_DIR) $(SRC_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm bonus re-all re-bonus