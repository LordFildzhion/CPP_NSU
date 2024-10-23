add_library(wc_lib
    ./circularbuffer/circularbuffer.hpp
    ./circularbuffer/circularbuffer.cpp
)

set_target_properties(wc_lib PROPERTIES LINKER_LANGUAGE CXX)