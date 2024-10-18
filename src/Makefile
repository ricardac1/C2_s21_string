GCC_FLAGS = -Wall -Wextra -Werror -std=c11
SANITAIZER = -g -fsanitize=address
TEST_FLAGS = -lcheck -lm -lpthread
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
EXE=test.out

# Папки поиска
SRC_DIR = .
TEST_DIR = ./test
OBJ_DIR = ./objs
TEST_OBJ_DIR = ./test/objs
BUILD_PATH=./


SRC_C_FILES := $(shell find $(SRC_DIR) -name "s21_*.c")
OBJS_C_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_C_FILES:.c=.o)))


TEST_C_FILES := $(shell find $(TEST_DIR) -name "test_*.c")
OBJS_TEST_FILES := $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_C_FILES:.c=.o)))


all: s21_string.a test gcov_report

rebuild: clean all

test: $(OBJS_TEST_FILES) s21_string.a main.o
	gcc $(TEST_FLAGS) $(OBJS_TEST_FILES) $(OBJS_C_FILES) main.o
	./a.out

s21_string.a: $(OBJS_C_FILES)
	ar rcs s21_string.a $(OBJS_C_FILES)
	ranlib s21_string.a

main.o: main.c
	gcc -c $(GCC_FLAGS) -o $@ $<


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(GCC_FLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(TEST_OBJ_DIR)
	gcc $(GCC_FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

gcov_report: s21_string.a
	gcc $(GCC_FLAGS) --coverage main.c $(TEST_C_FILES) $(SRC_C_FILES) s21_string.a -L. s21_string.a $(TEST_FLAGS) -o $(BUILD_PATH)$(EXE) 
	$(BUILD_PATH)$(EXE)
	lcov -t "Report" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/
	open $(BUILD_PATH)report/index.html

clean: 
	rm -rf *.a *.out *.info
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(TEST_OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_OBJ_DIR)
	rm -rf *.o
	rm -rf *.gcno *.gcov *.gcda
	rm -rf report/

