// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "numpy.h"

numpy_t::numpy_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, numpy_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_numpy_array = 0;

    UserDefinedMap numpy_fields_map({
	    {Field_numpy::numpy_array, "numpy_array"}});
    numpy_builder.set_fields(numpy_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void numpy_t::_read() {
    m_numpy_array = new std::vector<uint32_t>();
    {
        auto& sub_numpy_builder = numpy_builder.content<Field_numpy::numpy_array>();
        int i = 0;
        while (!m__io->is_eof()) {
            sub_numpy_builder.begin_list();
            m_numpy_array->push_back(m__io->read_u4le());
            auto& numpy_array_builder = sub_numpy_builder.content();
            numpy_array_builder.append(m_numpy_array->at(m_numpy_array->size() - 1));
            sub_numpy_builder.end_list();
            i++;
        }
    }
}

numpy_t::~numpy_t() {
    std::map<std::string, size_t> names_nbytes = {};
    numpy_builder.buffer_nbytes(names_nbytes);

    auto buffers = empty_buffers(names_nbytes);
    numpy_builder.to_buffers(buffers);

    std::ostringstream out;
    dump(out,
       "node1-offsets", (int64_t*)buffers["node1-offsets"], names_nbytes["node1-offsets"]/sizeof(int64_t),
       "node2-data", (int32_t*)buffers["node2-data"], names_nbytes["node2-data"]/sizeof(int32_t));
    
    std::cout << out.str();
    std::cout << numpy_builder.form();

    _clean_up();
}

void numpy_t::_clean_up() {
    if (m_numpy_array) {
        delete m_numpy_array; m_numpy_array = 0;
    }
}
