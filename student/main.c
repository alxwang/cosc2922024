#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"




int main() {
    classroom  * c = PopulateClassroom();
    DisplayClassroom(c);
    FreeClassroom(c);
    return 0;
}
