/**
 * @brief Exception
 *
 * @details
 * Exceptions are unexpected events that occur during the execution of a program.
 * 
 * In C++, an exception is "thrown" by code that encounters some unexpected condition.
 * Exceptions can also be thrown by the C++ run-time environment should it encounter an unexpected condition like running out of memory.
 * A thrown exception is "caught" by other code that "handles" the exception somehow, or the program is terminated unexpectedly.
 * 
 * Exceptions are a relatively recent addition to C++.
 * Prior to having exceptions, errors were typically handled by having the program abort at the source of the error or by having the involved function return some special value.
 * Exceptions provide a much cleaner mechanism for handling errors.
 * 
 * Exceptions are thrown when a piece of code finds some sort of problem during execution.
 * Since there are many types of possible errors, when an exception is thrown, it is identified by a type.
 * Typically this type is a class whose members provide information as to the exact nature of the error, for example a string containing a descriptive error message.
 */
#ifndef _BASIC_EXCEPTION_H
#define _BASIC_EXCEPTION_H 1

/* Header */

// Project configuration
#include "ProjectConfiguration.h"

// C++ standard libraries:
#include <string>

/* Macro */

/* Type */

namespace Exception
{

/** A generic exception class */
class RuntimeException
{
public:
    /** The @p v1 is the capacity */
    RuntimeException(const std::string& error); // Constructor
    ~RuntimeException();                        // Destructor

    std::string getMessage() const;

private:
    /* Data */

    std::string errorMessage;
};

/* Prototype */

/* Variable */

/* Function */

} // namespace Exception

#endif /* _BASIC_EXCEPTION_H */
