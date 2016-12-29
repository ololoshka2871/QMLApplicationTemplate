#include <stdlib.h>

#include "appInstance.hpp"

int main(int argc, char *argv[]) {
    return app::Instance::Execute(argc, argv);
}
