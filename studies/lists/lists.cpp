// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "lists.h"

lists_t::lists_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, lists_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_sample_blk = 0;
    m_sample_blk2 = 0;

    UserDefinedMap lists_fields_map({
        {Field_lists::sample_blk, "sample_blk"},
        {Field_lists::sample_blk2, "sample_blk2"}});
    lists_builder.set_fields(lists_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lists_t::_read() {
    std::cout << lists_builder.form();
    m_sample_blk = new std::vector<sample_block_t*>();
    {
        int i = 0;
        auto& sub_lists_builder = lists_builder.content<Field_lists::sample_blk>();   
        while (!m__io->is_eof()) {
            sub_lists_builder.begin_list();
            m_sample_blk->push_back(new sample_block_t(m__io, this, m__root));
            sub_lists_builder.end_list();
            i++;
        }
    }
    m_sample_blk2 = new sample_block2_t(m__io, this, m__root);
}

lists_t::~lists_t() {
    std::cout << lists_builder.form();
    _clean_up();
}

void lists_t::_clean_up() {
    if (m_sample_blk) {
        for (std::vector<sample_block_t*>::iterator it = m_sample_blk->begin(); it != m_sample_blk->end(); ++it) {
            delete *it;
        }
        delete m_sample_blk; m_sample_blk = 0;
    }
    if (m_sample_blk2) {
        delete m_sample_blk2; m_sample_blk2 = 0;
    }
}

lists_t::sample_block_t::sample_block_t(kaitai::kstream* p__io, lists_t* p__parent, lists_t* p__root) : kaitai::kstruct(p__io),
    sample_blk_builder(p__parent->lists_builder.content<Field_lists::sample_blk>().content()) {
    m__parent = p__parent;
    m__root = p__root;
    m_sample = 0;

    UserDefinedMap sample_blk_fields_map({
        {Field_sample_blk::num_sample, "num_sample"},
        {Field_sample_blk::sample, "sample"}});
    sample_blk_builder.set_fields(sample_blk_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lists_t::sample_block_t::_read() {
    m_num_sample = m__io->read_u4le();
    auto& num_sample_builder = sample_blk_builder.content<Field_sample_blk::num_sample>();
    num_sample_builder.append(m_num_sample);
    m_sample = new std::vector<example_t*>();
    const int l_sample = num_sample();
    auto& sub_sample_blk_builder = sample_blk_builder.content<Field_sample_blk::sample>();   
    for (int i = 0; i < l_sample; i++) {
        sub_sample_blk_builder.begin_list();
        m_sample->push_back(new example_t(m__io, this, m__root));
        sub_sample_blk_builder.end_list();
    }
}

lists_t::sample_block_t::~sample_block_t() {
    _clean_up();
}

void lists_t::sample_block_t::_clean_up() {
    if (m_sample) {
        for (std::vector<example_t*>::iterator it = m_sample->begin(); it != m_sample->end(); ++it) {
            delete *it;
        }
        delete m_sample; m_sample = 0;
    }
}

lists_t::sample_block_t::example_t::example_t(kaitai::kstream* p__io, lists_t::sample_block_t* p__parent, lists_t* p__root) : kaitai::kstruct(p__io),
    sample_builder(p__parent->sample_blk_builder.content<Field_sample_blk::sample>().content()) {
    m__parent = p__parent;
    m__root = p__root;

    UserDefinedMap sample_fields_map({
        {Field_sample::num_example, "num_example"}});
    sample_builder.set_fields(sample_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lists_t::sample_block_t::example_t::_read() {
    m_num_example = m__io->read_u4le();
    auto& num_example_builder = sample_builder.content<Field_sample::num_example>();
    num_example_builder.append(m_num_example);
}

lists_t::sample_block_t::example_t::~example_t() {
    _clean_up();
}

void lists_t::sample_block_t::example_t::_clean_up() {
}

lists_t::sample_block2_t::sample_block2_t(kaitai::kstream* p__io, lists_t* p__parent, lists_t* p__root) : kaitai::kstruct(p__io),
    sample_blk2_builder(p__parent->lists_builder.content<Field_lists::sample_blk2>()) {
    m__parent = p__parent;
    m__root = p__root;
    m_sample2 = 0;

    UserDefinedMap sample_blk2_fields_map({
        {Field_sample_blk2::num_sample2, "num_sample2"},
        {Field_sample_blk2::sample2, "sample2"}});
    sample_blk2_builder.set_fields(sample_blk2_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void lists_t::sample_block2_t::_read() {
    m_num_sample2 = m__io->read_u4le();
    auto& num_sample2_builder = sample_blk2_builder.content<Field_sample_blk2::num_sample2>();
    num_sample2_builder.append(m_num_sample2);
    m_sample2 = new std::vector<double>();
    const int l_sample2 = num_sample2();
    auto& sub_sample_blk2_builder = sample_blk2_builder.content<Field_sample_blk2::sample2>();   
    auto& sample2_builder = sub_sample_blk2_builder.begin_list();
    for (int i = 0; i < l_sample2; i++) {
        auto& sample2_builder = sub_sample_blk2_builder.begin_list();
        m_sample2->push_back(m__io->read_f8le());
        sample2_builder.append(m_sample2->at(m_sample2->size() - 1));
        sub_sample_blk2_builder.end_list();
    }
}

lists_t::sample_block2_t::~sample_block2_t() {
    _clean_up();
}

void lists_t::sample_block2_t::_clean_up() {
    if (m_sample2) {
        delete m_sample2; m_sample2 = 0;
    }
}
