/* Header */
#include "Exception/BasicException.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Exception
{

RuntimeException::RuntimeException(const std::string& error)
: errorMessage(error)
{
}

RuntimeException::~RuntimeException()
{
}

std::string RuntimeException::getMessage() const
{
    return errorMessage;
}

} // namespace Exception
