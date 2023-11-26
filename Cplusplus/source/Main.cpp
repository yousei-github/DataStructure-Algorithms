

/* Header */
#include "Main.h"

#include "LinkedLists/CircularlyDoublyLinkedList.h"
#include "LinkedLists/DoublyLinkedList.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */
int main(int argc, char** argv)
{
    LinkedLists::CircularlyDoublyLinkedList<int> test2;
    assert(test2.empty());
    test2.add(6);
    test2.add(8);
    test2.add(3);
    test2.add(1);
    std::cout << test2.front() << std::endl;
    std::cout << test2.back() << std::endl;
    test2.advance();
    std::cout << test2.front() << std::endl;
    std::cout << test2.back() << std::endl;

    // LinkedLists::CircularlyDoublyLinkedList<int> test3(test2);
    LinkedLists::CircularlyDoublyLinkedList<int> test3;
    LinkedLists::CircularlyDoublyLinkedList<int> test4 = test3 = test2;

    test2.retreat();
    std::cout << test2.front() << std::endl;
    std::cout << test2.back() << std::endl;
    test2.remove();
    std::cout << test2.front() << std::endl;
    std::cout << test2.back() << std::endl;
    test2.advance();
    std::cout << test2.front() << std::endl;
    std::cout << test2.back() << std::endl;
    test2.retreat();
    std::cout << test2.front() << std::endl;
    std::cout << test2.back() << std::endl;

    std::string output_file("Output_file");
    output_statistics.output_file_initialization(output_file.c_str());

    return EXIT_SUCCESS; // Returns the value zero to indicate success
}
