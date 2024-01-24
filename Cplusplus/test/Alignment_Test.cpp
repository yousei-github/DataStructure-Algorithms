
/* Header */
#include <stdint.h>

#include <iostream>

#include "ProjectConfiguration.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

/** 
 * @test 
 * Data structure alignment test 
 * 
 * Alignment is a property of a memory address, expressed as the numeric address modulo a power of 2.
 * For example, the address 0x0001103F modulo 4 is 3. That address is said to be aligned to 4n+3, where 4 indicates the chosen power of 2.
 * The alignment of an address depends on the chosen power of 2. The same address modulo 8 is 7.
 * 
 * An address is said to be aligned to X if its alignment is Xn+0.
 * 
 * We call a datum naturally aligned if its address is aligned to its size, or, the data's memory address is a multiple of the data size.
 * Otherwise, it's called misaligned.
 * 
 * Compilers attempt to make data allocations in a way that prevents data misalignment:
 * (1) For simple data types, the compiler assigns addresses that are multiples of the size in bytes of the data type.
 * (2) The compiler also pads structures in a way that naturally aligns each element of the structure.
 * (3) It is important to note that the last member is padded with the number of bytes required so that the total size of the structure should be a multiple of the largest alignment of any structure member
 * 
*/
TEST(Alignment, DataStructure)
{
    /* Arrange */
    struct StructureA
    {
        uint8_t memberOne;    // 1 byte
        uint32_t memberTwo;   // 4 byte
        uint16_t memberThree; // 2 byte
        uint8_t memberFour;   // 1 byte
    } dataA = {};

    struct StructureB
    {
        uint8_t memberOne;    // 1 byte
        uint8_t _pad0[3];     // Padding to put [memberTwo] on 4-byte boundary
        uint32_t memberTwo;   // 4 byte
        uint16_t memberThree; // 2 byte
        uint8_t memberFour;   // 1 byte
        uint8_t _pad1[1];     // Padding to make sizeof(StructureB) multiple of 4, or the last member is padded with the number of bytes required so that the total size of the structure should be a multiple of the largest alignment of any structure member
    } dataB                                             = {};

    /* Act */
    uint32_t structureA_size                            = sizeof(StructureA);
    uint32_t structureB_size                            = sizeof(StructureB);

    uint64_t structureA_offsetBetweenHeadAndMemberOne   = (uint64_t) (&dataA.memberOne) - (uint64_t) (&dataA);
    uint64_t structureB_offsetBetweenHeadAndMemberOne   = (uint64_t) (&dataB.memberOne) - (uint64_t) (&dataB);

    uint64_t structureA_offsetBetweenMemberOneAndTwo    = (uint64_t) (&dataA.memberTwo) - (uint64_t) (&dataA.memberOne);
    uint64_t structureB_offsetBetweenMemberOneAndTwo    = (uint64_t) (&dataB.memberTwo) - (uint64_t) (&dataB.memberOne);

    uint64_t structureA_offsetBetweenMemberTwoAndThree  = (uint64_t) (&dataA.memberThree) - (uint64_t) (&dataA.memberTwo);
    uint64_t structureB_offsetBetweenMemberTwoAndThree  = (uint64_t) (&dataB.memberThree) - (uint64_t) (&dataB.memberTwo);

    uint64_t structureA_offsetBetweenMemberThreeAndFour = (uint64_t) (&dataA.memberFour) - (uint64_t) (&dataA.memberThree);
    uint64_t structureB_offsetBetweenMemberThreeAndFour = (uint64_t) (&dataB.memberFour) - (uint64_t) (&dataB.memberThree);

    uint64_t structureA_offsetBetweenTailAndMemberFour  = ((uint64_t) (&dataA) + structureA_size) - (uint64_t) (&dataA.memberFour);
    uint64_t structureB_offsetBetweenTailAndMemberFour  = ((uint64_t) (&dataB) + structureB_size) - (uint64_t) (&dataB.memberFour);

    /* Assert */
    EXPECT_EQ(structureA_size, structureB_size);
    EXPECT_EQ(structureA_offsetBetweenHeadAndMemberOne, structureB_offsetBetweenHeadAndMemberOne);
    EXPECT_EQ(structureA_offsetBetweenMemberOneAndTwo, structureB_offsetBetweenMemberOneAndTwo);
    EXPECT_EQ(structureA_offsetBetweenMemberTwoAndThree, structureB_offsetBetweenMemberTwoAndThree);
    EXPECT_EQ(structureA_offsetBetweenMemberThreeAndFour, structureB_offsetBetweenMemberThreeAndFour);
    EXPECT_EQ(structureA_offsetBetweenTailAndMemberFour, structureB_offsetBetweenTailAndMemberFour);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}