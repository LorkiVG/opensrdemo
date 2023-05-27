#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <stdint.h>

struct RGB {
    uint8_t R;
    uint8_t G;
    uint8_t B;
};
struct RGBA : RGB {
    uint8_t A;
};