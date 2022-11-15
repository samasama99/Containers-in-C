all:
	@gcc -Wall -Wextra -o vector_test vector_test.c
	@gcc -Wall -Wextra -o list_test list_test.c
	@gcc -Wall -Wextra -o stack_test stack_test.c
	@gcc -Wall -Wextra -o queue_test queue_test.c
	@./vector_test && ./list_test && ./stack_test && ./queue_test

clean:
	@rm -f vector_test list_test stack_test queue_test
