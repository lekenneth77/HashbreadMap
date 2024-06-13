.DEFAULT_GOAL := run


run: MyLinkedListTest.cpp
	g++ -o ./my_Linked_List MyLinkedListTest.cpp 
	./my_Linked_List

grind: MyLinkedListTest.cpp ./my_Linked_List
	valgrind ./my_Linked_List

test: test_MyLinkedList.cpp
	g++ -o ./test_Linked_List test_MyLinkedList.cpp -lgtest -lgtest_main
	valgrind ./test_Linked_List