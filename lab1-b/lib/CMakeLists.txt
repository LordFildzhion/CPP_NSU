add_library(cb_lib
    ./circularbuffer/circularbuffer.hpp
    ./circularbuffer/circularbuffer.cpp
)

set_target_properties(cb_lib PROPERTIES LINKER_LANGUAGE CXX)