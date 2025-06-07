CC = gcc
CFLAGS = -Ilib -Wall -std=c11

# program 1

transition_test_p1: tests/program1/test-transition.c program1/model.c
	$(CC) $(CFLAGS) tests/program1/test-transition.c program1/model.c -o ./tests/program1/test-transition

run_transition_test_p1: transition_test_p1
	./tests/program1/test-transition

boundary_test_p1: tests/program1/test-boundary.c program1/model.c
	$(CC) $(CFLAGS) tests/program1/test-boundary.c program1/model.c -o ./tests/program1/test-boundary

run_boundary_test_p1: boundary_test_p1
	./tests/program1/test-boundary

table_test_p1: tests/program1/test-table.c program1/model.c
	$(CC) $(CFLAGS) tests/program1/test-table.c program1/model.c -o ./tests/program1/test-table

run_table_test_p1: table_test_p1
	./tests/program1/test-table


# program 2

branch_test_p2: tests/program2/test-branch.c program2/model.c
	$(CC) $(CFLAGS) tests/program2/test-branch.c program2/model.c -o ./tests/program2/test-branch

run_branch_test_p2: branch_test_p2
	./tests/program2/test-branch

decision_test_p2: tests/program2/test-decision.c program2/model.c
	$(CC) $(CFLAGS) tests/program2/test-decision.c program2/model.c -o ./tests/program2/test-decision

run_decision_test_p2: decision_test_p2
	./tests/program2/test-decision

clean:
	rm -f tests/program1/test
	rm -f tests/program2/test
