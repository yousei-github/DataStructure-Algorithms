
/* Header */
#include <iostream>

#include "ProjectConfiguration.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

/** @test Inheritance hierarchy test */
TEST(Inheritance, InheritanceHierarchy)
{
    /* Arrange */

    class Object
    {
    public:
        virtual void printMe() = 0;
    };

    class Place : public Object
    {
    public:
        virtual void printMe() { std::cout << "Buy it.\n"; }
    };

    class Region : public Place
    {
    public:
        virtual void printMe() { std::cout << "Box it.\n"; }
    };

    class State : public Region
    {
    public:
        virtual void printMe() { std::cout << "Ship it.\n"; }
    };

    class Maryland : public State
    {
    public:
        virtual void printMe() { std::cout << "Read it.\n"; }
    };

    Region* mid = new State;
    State* md   = new Maryland;
    Object* obj = new Place;
    Place* usa  = new Region;

    /* Act */
    md->printMe();                          // Polymorphism
    mid->printMe();                         // Polymorphism
    (dynamic_cast<Place*>(obj))->printMe(); // Casting in an inheritance hierarchy
    obj = md;
    (dynamic_cast<Maryland*>(obj))->printMe(); // Casting in an inheritance hierarchy
    obj = usa;
    (dynamic_cast<Place*>(obj))->printMe(); // Casting in an inheritance hierarchy and Polymorphism
    usa = md;
    (dynamic_cast<Place*>(usa))->printMe(); // Polymorphism

    /* Assert */
    SUCCEED();
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}