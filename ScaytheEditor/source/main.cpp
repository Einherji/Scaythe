#ifndef EDITOR_ENTRY
#define EDITOR_ENTRY

#include <stdio.h>
#include "Scaythe.h"

using Scaythe::Logging;

int main(int argc, char* argv[]) {
    Logging logging;
    logging.Log();
    printf(Scaythe::Logging::str);
}

#endif