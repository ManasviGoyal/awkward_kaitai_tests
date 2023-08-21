// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "fake.h"
    
fake_t::fake_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, fake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_points = 0;

    UserDefinedMap fake_fields_map({
	    {Field_fake::points, "points"}});
    fake_builder.set_fields(fake_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void fake_t::_read() {
    m_points = new std::vector<point_t*>();
    {
        int i = 0;
        auto& sub_fake_builder = fake_builder.content<Field_fake::points>();   
        while (!m__io->is_eof()) {
            sub_fake_builder.begin_list();
            m_points->push_back(new point_t(m__io, this, m__root));
            i++;
            sub_fake_builder.end_list();
        }
    }
}

fake_t::~fake_t() {
    std::map<std::string, size_t> names_nbytes = {};
    fake_builder.buffer_nbytes(names_nbytes);

    auto buffers = empty_buffers(names_nbytes);
    fake_builder.to_buffers(buffers);

    std::ostringstream out;
    dump(out,
       "node1-offsets", (int64_t*)buffers["node1-offsets"], names_nbytes["node1-offsets"]/sizeof(int64_t),
       "node3-data", (int32_t*)buffers["node3-data"], names_nbytes["node3-data"]/sizeof(int32_t),
       "node4-data", (int32_t*)buffers["node4-data"], names_nbytes["node4-data"]/sizeof(int32_t),
       "node5-data", (int32_t*)buffers["node5-data"], names_nbytes["node5-data"]/sizeof(int32_t));
    
    std::cout << out.str();
    std::cout << fake_builder.form();

    _clean_up();
}

void fake_t::_clean_up() {
    if (m_points) {
        for (std::vector<point_t*>::iterator it = m_points->begin(); it != m_points->end(); ++it) {
            delete *it;
        }
        delete m_points; m_points = 0;
    }
}

fake_t::point_t::point_t(kaitai::kstream* p__io, fake_t* p__parent, fake_t* p__root) : kaitai::kstruct(p__io),
    points_builder (p__parent->fake_builder.content<Field_fake::points>().content()) {
    m__parent = p__parent;
    m__root = p__root;
    
    UserDefinedMap points_fields_map({
        {Field_points::x, "x"},
        {Field_points::y, "y"},
        {Field_points::z, "z"}});
    points_builder.set_fields(points_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void fake_t::point_t::_read() {
    m_x = m__io->read_u4le();
    m_y = m__io->read_u4le();
    m_z = m__io->read_u4le();

    
    auto& x_builder = points_builder.content<Field_points::x>();
    auto& y_builder = points_builder.content<Field_points::y>();
    auto& z_builder = points_builder.content<Field_points::z>();

    x_builder.append(m_x);
    y_builder.append(m_y);
    z_builder.append(m_z);
}

fake_t::point_t::~point_t() {
    _clean_up();
}

void fake_t::point_t::_clean_up() {
}
