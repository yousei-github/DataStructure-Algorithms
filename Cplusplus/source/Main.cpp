

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
    // LinkedLists::DoublyLinkedList<int> test;
    // assert(test.empty());
    // test.addFront(6);
    // test.addBack(8);
    // test.addFront(3);
    // std::cout << test.front() << std::endl;
    // std::cout << test.back() << std::endl;
    // test.removeBack();
    // test.removeBack();
    // test.removeBack();
    // assert(test.empty());

    LinkedLists::CircularlyDoublyLinkedList<int> test2;
    assert(test2.empty());
    test2.add(6);
    test2.add(8);
    test2.add(3);
    std::cout << test2.front() << std::endl;
    std::cout << test2.back() << std::endl;
    test2.advance();
    std::cout << test2.front() << std::endl;
    std::cout << test2.back() << std::endl;
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

    uint8_t binary1 = 0b1001011;
    std::cout << binary1 << std::endl;

    std::string output_file("Output_file");
    output_statistics.output_file_initialization(output_file.c_str());

    return EXIT_SUCCESS;
}
