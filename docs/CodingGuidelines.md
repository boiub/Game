
# Coding Guidelines

The general idea is to achieve readability over cleverness as well as a structured code base 

## Braces
Braces are placed as a new line, opening and closíng alike as such:

type function(type var)\
{  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; function   
}  

## Comments
Comments are highly encouraged when the code is not clearly self-explanatory and needed for any code one might be 
confused by. They should explain *why* and not *what*. \
For longer documentation that does not fit well in a single line, block comments are used. Start a block by typing /* on
a new line and end it with \*/ on a new line.\
Public documentation is required for all classes and may be used to explain complex functions which others should use as
well. Add them by starting with /** on a new line and end with */ on a new line.

## Includes
Includes are ordered first by their origin and then by alphabetical order where the standard C++ library comes first
followed by third party files and lastly own project files.\
See example below with extra comments

// Standard Library\
#include <iostream\>\
#include <vector\>

// Third Party\
#include <raylib.h\>

// Project\
#include "main.hpp"

## Naming Conventions
| Item        | Naming      |
|-------------|-------------|
| Class       | PascalCase  |
| Structs     | PascalCase  |
| Functions   | camelCase   |
| Variables   | camelCase   | 
| Constants   | UPPER_CASE  |
| Enums       | PascalCase  |
| Enum Values | PascalCase  |
| Namespaces  | lowercase   |
| Files       | PascalCase  |

