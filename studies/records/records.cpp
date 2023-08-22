// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "records.h"

records_t::records_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, records_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_points = 0;

    UserDefinedMap records_fields_map({
	    {Field_records::points, "points"}});
    records_builder.set_fields(records_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void records_t::_read() {
    m_points = new std::vector<point_t*>();
    {
        int i = 0;
        auto& sub_records_builder = records_builder.content<Field_records::points>();   
        while (!m__io->is_eof()) {
            sub_records_builder.begin_list();
            m_points->push_back(new point_t(m__io, this, m__root));
            i++;
            sub_records_builder.end_list();
        }
    }
}

records_t::~records_t() {
    std::map<std::string, size_t> names_nbytes = {};
    records_builder.buffer_nbytes(names_nbytes);

    auto buffers = empty_buffers(names_nbytes);
    records_builder.to_buffers(buffers);

    std::ostringstream out;
    dump(out,
       "node1-offsets", (int64_t*)buffers["node1-offsets"], names_nbytes["node1-offsets"]/sizeof(int64_t),
       "node3-offsets", (int64_t*)buffers["node3-offsets"], names_nbytes["node3-offsets"]/sizeof(int64_t),
       "node5-data", (int32_t*)buffers["node5-data"], names_nbytes["node5-data"]/sizeof(int32_t));
    
    std::cout << out.str();
    std::cout << records_builder.form();
    _clean_up();
}

void records_t::_clean_up() {
    if (m_points) {
        for (std::vector<point_t*>::iterator it = m_points->begin(); it != m_points->end(); ++it) {
            delete *it;
        }
        delete m_points; m_points = 0;
    }
}

records_t::point_t::point_t(kaitai::kstream* p__io, records_t* p__parent, records_t* p__root) : kaitai::kstruct(p__io) 
    , points_builder (p__parent->records_builder.content<Field_records::points>().content()) {
    m__parent = p__parent;
    m__root = p__root;
    m_x = 0;

    UserDefinedMap points_fields_map({
        {Field_points::x, "x"}});
    points_builder.set_fields(points_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void records_t::point_t::_read() {
    m_x = new std::vector<x_point_t*>();
    {
        int i = 0;
        auto& sub_points_builder = points_builder.content<Field_points::x>();   
        while (!m__io->is_eof()) {
            sub_points_builder.begin_list();
            m_x->push_back(new x_point_t(m__io, this, m__root));
            i++;
            sub_points_builder.end_list();
        }
    }
}

records_t::point_t::~point_t() {
    _clean_up();
}

void records_t::point_t::_clean_up() {
    if (m_x) {
        for (std::vector<x_point_t*>::iterator it = m_x->begin(); it != m_x->end(); ++it) {
            delete *it;
        }
        delete m_x; m_x = 0;
    }
}

records_t::point_t::x_point_t::x_point_t(kaitai::kstream* p__io, records_t::point_t* p__parent, records_t* p__root) : kaitai::kstruct(p__io)
    , x_builder(p__parent->points_builder.content<Field_points::x>().content()) {
    m__parent = p__parent;
    m__root = p__root;

    UserDefinedMap x_fields_map({
        {Field_x::a, "a"}});
    x_builder.set_fields(x_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void records_t::point_t::x_point_t::_read() {
    m_a = m__io->read_f8le();
    auto& a_builder = x_builder.content<Field_x::a>();
    a_builder.append(m_a);
}

records_t::point_t::x_point_t::~x_point_t() {
    _clean_up();
}

void records_t::point_t::x_point_t::_clean_up() {
}
