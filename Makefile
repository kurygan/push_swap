CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = create_list.c \
			 ft_split.c \
			 main.c \
			 ft_strdup.c \
			 lstlib.c \
			 error_handle.c \
			 swap_rotate.c \
			 push.c

OBJS = $(SRCS:.c=.o)
SRCS_DIR = src/
OBJS_DIR = build/
SRCS_PREF = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = push_swap

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@cc $(FLAGS) -g -c $< -o $@

$(NAME): $(OBJS_PREF) signature
	@cc $(FLAGS) $(OBJS_PREF) -g -o $(NAME)
	@echo "Program Compiled"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Removing objects.."

fclean: clean signature
	@rm -f $(NAME)
	@echo "Cleaning.."

re: fclean all signature

signature:
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo "        ,====,,'''',,,             _____________________________________"
	@echo " _______||__||_______ ''',       /'                                    |"
	@echo "|    | |      | |    |    ;    /'  Name: ____Kurygan (mkettab)________ |"
	@echo "|   CMIYGL    | |    |   ;   / o   Address: __mkettab@student.42.fr___ |"
	@echo "|    | |      | |    |    '''\     School: ______42_Mulhouse__________ |"
	@echo "|    | |      IGOR   |        \`\          __CALL_ME_IF_YOU_GET_LOST___ |"
	@echo "|  OFWGKTA    | |    |          \`\.____________________________________|"
	@echo "|____|_|______|_|____|"
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""