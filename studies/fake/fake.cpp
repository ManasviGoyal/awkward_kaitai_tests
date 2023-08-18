// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "fake.h"

UserDefinedMap fields_map_fake({
    {Field_fake::points, "points"}});

UserDefinedMap fields_map_points({
    {Field_points::x, "x"},
    {Field_points::y, "y"},
    {Field_points::z, "z"}});

fake_t::fake_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, fake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_points = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }

    m_fake_builder.set_fields(fields_map_fake);
}

void fake_t::_read() {
    m_points = new std::vector<point_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_points->push_back(new point_t(m__io, this, m__root));
            i++;
        }
    }
}

fake_t::~fake_t() {
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

fake_t::point_t::point_t(kaitai::kstream* p__io, fake_t* p__parent, fake_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }

    m_points_builder.set_fields(fields_map_points);
}

void fake_t::point_t::_read() {
    m_x = m__io->read_u4le();
    m_y = m__io->read_u4le();
    m_z = m__io->read_u4le();

    auto& m_sub_fake_builder = m_fake_builder.content<Field_fake::points>();   

    m_sub_fake_builder.begin_list();

    auto& m_x_builder = m_points_builder.content<Field_points::x>();
    auto& m_y_builder = m_points_builder.content<Field_points::y>();
    auto& m_z_builder = m_points_builder.content<Field_points::z>();

    m_x_builder.append(m_x);
    m_y_builder.append(m_y);
    m_z_builder.append(m_z);

    m_sub_fake_builder.begin_list();

}

fake_t::point_t::~point_t() {
    _clean_up();
}

void fake_t::point_t::_clean_up() {
}
