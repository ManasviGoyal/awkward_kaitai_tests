// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "numpy.h"

UserDefinedMap m_fields_map_numpy({
    {Field_numpy::numpy_array, "numpy_array"}});

numpy_t::numpy_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, numpy_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void numpy_t::_read() {
    m_numpy_array = m__io->read_u4le();
    auto& m_numpy_array_builder = m_numpy_builder.content<Field_numpy::numpy_array>();
    m_numpy_array_builder.append(m_numpy_array);
    std::cout << "numpy_array: " << m_numpy_array <<std::endl;

}

numpy_t::~numpy_t() {
    _clean_up();
}

void numpy_t::_clean_up() {
}
