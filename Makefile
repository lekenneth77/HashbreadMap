.DEFAULT_GOAL := run-link


run-link: ./MyLinkedList/MyLinkedListTest.cpp
	g++ -o ./MyLinkedList/my_Linked_List ./MyLinkedList/MyLinkedListTest.cpp 
	./MyLinkedList/my_Linked_List

grind-link: ./MyLinkedList/MyLinkedListTest.cpp ./MyLinkedList//my_Linked_List
	valgrind ./MyLinkedList/my_Linked_List

test-link: ./MyLinkedList/test_MyLinkedList.cpp
	g++ -o ./MyLinkedList/test_Linked_List ./MyLinkedList/test_MyLinkedList.cpp -lgtest -lgtest_main
	valgrind ./MyLinkedList/test_Linked_List