#include "Visitors/PrintVisitor.h"
#include "driver.hpp"

int main(int argc, char **argv)
{
    Driver d;
    int error_code = 0;
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <mini-java file> <output file>";
        return EXIT_FAILURE;
    }
    std::string filename(argv[1]);
    int error = d.parse(filename);
    if (!error)
    {
        d.print_tree(argv[2]);
        error_code = d.run();
    }
    return error_code;
}
