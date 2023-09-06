// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "pixie4e.h"

UserDefinedMap pixie4e_fields_map({
	{Field_pixie4e::file_header, "file_header"},
	{Field_pixie4e::events, "events"},
	{Field_pixie4e::file_footer, "file_footer"}});

UserDefinedMap file_header_fields_map({
	{Field_file_header::blk_size, "blk_size"},
	{Field_file_header::mod_num, "mod_num"},
	{Field_file_header::run_format, "run_format"},
	{Field_file_header::chan_head_len, "chan_head_len"},
	{Field_file_header::coinc_pat, "coinc_pat"},
	{Field_file_header::coinc_win, "coinc_win"},
	{Field_file_header::max_comb_event_len, "max_comb_event_len"},
	{Field_file_header::board_version, "board_version"},
	{Field_file_header::event_length_0, "event_length_0"},
	{Field_file_header::event_length_1, "event_length_1"},
	{Field_file_header::event_length_2, "event_length_2"},
	{Field_file_header::event_length_3, "event_length_3"},
	{Field_file_header::serial_number, "serial_number"},
	{Field_file_header::reserved1, "reserved1"}});

UserDefinedMap events_fields_map({
	{Field_events::elements, "elements"}});

UserDefinedMap elements_fields_map({
	{Field_elements::header, "header"},
	{Field_elements::data, "data"}});

UserDefinedMap header_fields_map({
	{Field_header::evt_pattern1, "evt_pattern1"},
	{Field_header::evt_info1, "evt_info1"},
	{Field_header::num_trace_blks1, "num_trace_blks1"},
	{Field_header::num_trace_blks_prev1, "num_trace_blks_prev1"},
	{Field_header::trig_time_lo, "trig_time_lo"},
	{Field_header::trig_time_mi, "trig_time_mi"},
	{Field_header::trig_time_hi, "trig_time_hi"},
	{Field_header::trig_time_x, "trig_time_x"},
	{Field_header::energy, "energy"},
	{Field_header::chan_no, "chan_no"},
	{Field_header::user_psa_value, "user_psa_value"},
	{Field_header::xia_psa_value, "xia_psa_value"},
	{Field_header::extended_psa_values, "extended_psa_values"},
	{Field_header::reserved2, "reserved2"}});

UserDefinedMap file_footer_fields_map({
	{Field_file_footer::evt_pattern2, "evt_pattern2"},
	{Field_file_footer::evt_info2, "evt_info2"},
	{Field_file_footer::num_trace_blks2, "num_trace_blks2"},
	{Field_file_footer::num_trace_blks_prev2, "num_trace_blks_prev2"},
	{Field_file_footer::reserved3, "reserved3"}});

pixie4e_t::pixie4e_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_file_header = 0;
    m_events = 0;
    m__io__raw_events = 0;
    m_file_footer = 0;

    pixie4e_builder.set_fields(pixie4e_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void pixie4e_t::_read() {
    m_file_header = new pixie4e_header_t(m__io, this, m__root);
    m__raw_events = m__io->read_bytes((_io()->size() - 128));
    m__io__raw_events = new kaitai::kstream(m__raw_events);
    m_events = new event_t(m__io__raw_events, this, m__root);
    m_file_footer = new pixie_eor_t(m__io, this, m__root);
}

pixie4e_t::~pixie4e_t() {
    _clean_up();
}

void pixie4e_t::_clean_up() {
    if (m_file_header) {
        delete m_file_header; m_file_header = 0;
    }
    if (m__io__raw_events) {
        delete m__io__raw_events; m__io__raw_events = 0;
    }
    if (m_events) {
        delete m_events; m_events = 0;
    }
    if (m_file_footer) {
        delete m_file_footer; m_file_footer = 0;
    }
}

pixie4e_t::event_t::event_t(kaitai::kstream* p__io, pixie4e_t* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io),
	events_builder(p__parent->pixie4e_builder.content<Field_pixie4e::events>()) {
    m__parent = p__parent;
    m__root = p__root;
    m_elements = 0;

    events_builder.set_fields(events_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void pixie4e_t::event_t::_read() {
    m_elements = new std::vector<element_t*>();
    {
        int i = 0;
        auto& sub_events_builder = events_builder.content<Field_events::elements>();
        while (!m__io->is_eof()) {
            sub_events_builder.begin_list();
            m_elements->push_back(new element_t(m__io, this, m__root));
            sub_events_builder.end_list();
            i++;
        }
    }
}

pixie4e_t::event_t::~event_t() {
    _clean_up();
}

void pixie4e_t::event_t::_clean_up() {
    if (m_elements) {
        for (std::vector<element_t*>::iterator it = m_elements->begin(); it != m_elements->end(); ++it) {
            delete *it;
        }
        delete m_elements; m_elements = 0;
    }
}

pixie4e_t::element_t::element_t(kaitai::kstream* p__io, pixie4e_t::event_t* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io),
	elements_builder(p__parent->events_builder.content<Field_events::elements>().content()) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_data = 0;

    elements_builder.set_fields(elements_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void pixie4e_t::element_t::_read() {
    m_header = new channel_header_t(m__io, this, m__root);
    m_data = new std::vector<uint16_t>();
    const int l_data = (header()->num_trace_blks1() * _root()->file_header()->blk_size());
    auto& sub_elements_builder = elements_builder.content<Field_elements::data>();
    for (int i = 0; i < l_data; i++) {
        sub_elements_builder.begin_list();
        m_data->push_back(m__io->read_u2le());
        auto& data_builder = sub_elements_builder.content();
        data_builder.append(m_data->at(m_data->size() - 1));
        sub_elements_builder.end_list();
    }
}

pixie4e_t::element_t::~element_t() {
    _clean_up();
}

void pixie4e_t::element_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

pixie4e_t::pixie_eor_t::pixie_eor_t(kaitai::kstream* p__io, pixie4e_t* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io),
	file_footer_builder(p__parent->pixie4e_builder.content<Field_pixie4e::file_footer>()) {
    m__parent = p__parent;
    m__root = p__root;

    file_footer_builder.set_fields(file_footer_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void pixie4e_t::pixie_eor_t::_read() {
    m_evt_pattern2 = m__io->read_u2le();
    auto& evt_pattern2_builder = file_footer_builder.content<Field_file_footer::evt_pattern2>();
    evt_pattern2_builder.append(m_evt_pattern2);
    m_evt_info2 = m__io->read_u2le();
    auto& evt_info2_builder = file_footer_builder.content<Field_file_footer::evt_info2>();
    evt_info2_builder.append(m_evt_info2);
    m_num_trace_blks2 = m__io->read_u2le();
    auto& num_trace_blks2_builder = file_footer_builder.content<Field_file_footer::num_trace_blks2>();
    num_trace_blks2_builder.append(m_num_trace_blks2);
    m_num_trace_blks_prev2 = m__io->read_u2le();
    auto& num_trace_blks_prev2_builder = file_footer_builder.content<Field_file_footer::num_trace_blks_prev2>();
    num_trace_blks_prev2_builder.append(m_num_trace_blks_prev2);
    m_reserved3 = m__io->read_u2le();
    auto& reserved3_builder = file_footer_builder.content<Field_file_footer::reserved3>();
    reserved3_builder.append(m_reserved3);
}

pixie4e_t::pixie_eor_t::~pixie_eor_t() {
    _clean_up();
}

void pixie4e_t::pixie_eor_t::_clean_up() {
}

pixie4e_t::pixie4e_header_t::pixie4e_header_t(kaitai::kstream* p__io, pixie4e_t* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io),
	file_header_builder(p__parent->pixie4e_builder.content<Field_pixie4e::file_header>()) {
    m__parent = p__parent;
    m__root = p__root;

    file_header_builder.set_fields(file_header_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void pixie4e_t::pixie4e_header_t::_read() {
    m_blk_size = m__io->read_u2le();
    auto& blk_size_builder = file_header_builder.content<Field_file_header::blk_size>();
    blk_size_builder.append(m_blk_size);
    m_mod_num = m__io->read_u2le();
    auto& mod_num_builder = file_header_builder.content<Field_file_header::mod_num>();
    mod_num_builder.append(m_mod_num);
    m_run_format = m__io->read_u2le();
    auto& run_format_builder = file_header_builder.content<Field_file_header::run_format>();
    run_format_builder.append(m_run_format);
    m_chan_head_len = m__io->read_u2le();
    auto& chan_head_len_builder = file_header_builder.content<Field_file_header::chan_head_len>();
    chan_head_len_builder.append(m_chan_head_len);
    m_coinc_pat = m__io->read_u2le();
    auto& coinc_pat_builder = file_header_builder.content<Field_file_header::coinc_pat>();
    coinc_pat_builder.append(m_coinc_pat);
    m_coinc_win = m__io->read_u2le();
    auto& coinc_win_builder = file_header_builder.content<Field_file_header::coinc_win>();
    coinc_win_builder.append(m_coinc_win);
    m_max_comb_event_len = m__io->read_u2le();
    auto& max_comb_event_len_builder = file_header_builder.content<Field_file_header::max_comb_event_len>();
    max_comb_event_len_builder.append(m_max_comb_event_len);
    m_board_version = m__io->read_u2le();
    auto& board_version_builder = file_header_builder.content<Field_file_header::board_version>();
    board_version_builder.append(m_board_version);
    m_event_length_0 = m__io->read_u2le();
    auto& event_length_0_builder = file_header_builder.content<Field_file_header::event_length_0>();
    event_length_0_builder.append(m_event_length_0);
    m_event_length_1 = m__io->read_u2le();
    auto& event_length_1_builder = file_header_builder.content<Field_file_header::event_length_1>();
    event_length_1_builder.append(m_event_length_1);
    m_event_length_2 = m__io->read_u2le();
    auto& event_length_2_builder = file_header_builder.content<Field_file_header::event_length_2>();
    event_length_2_builder.append(m_event_length_2);
    m_event_length_3 = m__io->read_u2le();
    auto& event_length_3_builder = file_header_builder.content<Field_file_header::event_length_3>();
    event_length_3_builder.append(m_event_length_3);
    m_serial_number = m__io->read_u2le();
    auto& serial_number_builder = file_header_builder.content<Field_file_header::serial_number>();
    serial_number_builder.append(m_serial_number);
    m_reserved1 = m__io->read_u2le();
    auto& reserved1_builder = file_header_builder.content<Field_file_header::reserved1>();
    reserved1_builder.append(m_reserved1);
}

pixie4e_t::pixie4e_header_t::~pixie4e_header_t() {
    _clean_up();
}

void pixie4e_t::pixie4e_header_t::_clean_up() {
}

pixie4e_t::channel_header_t::channel_header_t(kaitai::kstream* p__io, pixie4e_t::element_t* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io),
	header_builder(p__parent->elements_builder.content<Field_elements::header>()) {
    m__parent = p__parent;
    m__root = p__root;
    m_extended_psa_values = 0;
    m_reserved2 = 0;
    f_timestamp_full = false;

    header_builder.set_fields(header_fields_map);

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void pixie4e_t::channel_header_t::_read() {
    m_evt_pattern1 = m__io->read_u2le();
    auto& evt_pattern1_builder = header_builder.content<Field_header::evt_pattern1>();
    evt_pattern1_builder.append(m_evt_pattern1);
    m_evt_info1 = m__io->read_u2le();
    auto& evt_info1_builder = header_builder.content<Field_header::evt_info1>();
    evt_info1_builder.append(m_evt_info1);
    m_num_trace_blks1 = m__io->read_u2le();
    auto& num_trace_blks1_builder = header_builder.content<Field_header::num_trace_blks1>();
    num_trace_blks1_builder.append(m_num_trace_blks1);
    m_num_trace_blks_prev1 = m__io->read_u2le();
    auto& num_trace_blks_prev1_builder = header_builder.content<Field_header::num_trace_blks_prev1>();
    num_trace_blks_prev1_builder.append(m_num_trace_blks_prev1);
    m_trig_time_lo = m__io->read_u2le();
    auto& trig_time_lo_builder = header_builder.content<Field_header::trig_time_lo>();
    trig_time_lo_builder.append(m_trig_time_lo);
    m_trig_time_mi = m__io->read_u2le();
    auto& trig_time_mi_builder = header_builder.content<Field_header::trig_time_mi>();
    trig_time_mi_builder.append(m_trig_time_mi);
    m_trig_time_hi = m__io->read_u2le();
    auto& trig_time_hi_builder = header_builder.content<Field_header::trig_time_hi>();
    trig_time_hi_builder.append(m_trig_time_hi);
    m_trig_time_x = m__io->read_u2le();
    auto& trig_time_x_builder = header_builder.content<Field_header::trig_time_x>();
    trig_time_x_builder.append(m_trig_time_x);
    m_energy = m__io->read_u2le();
    auto& energy_builder = header_builder.content<Field_header::energy>();
    energy_builder.append(m_energy);
    m_chan_no = m__io->read_u2le();
    auto& chan_no_builder = header_builder.content<Field_header::chan_no>();
    chan_no_builder.append(m_chan_no);
    m_user_psa_value = m__io->read_u2le();
    auto& user_psa_value_builder = header_builder.content<Field_header::user_psa_value>();
    user_psa_value_builder.append(m_user_psa_value);
    m_xia_psa_value = m__io->read_u2le();
    auto& xia_psa_value_builder = header_builder.content<Field_header::xia_psa_value>();
    xia_psa_value_builder.append(m_xia_psa_value);
    m_extended_psa_values = new std::vector<uint16_t>();
    const int l_extended_psa_values = 4;
    auto& sub_extended_psa_values_builder = header_builder.content<Field_header::extended_psa_values>();
    for (int i = 0; i < l_extended_psa_values; i++) {
        sub_extended_psa_values_builder.begin_list();
        m_extended_psa_values->push_back(m__io->read_u2le());
        auto& extended_psa_values_builder = sub_extended_psa_values_builder.content();
        extended_psa_values_builder.append(m_extended_psa_values->at(m_extended_psa_values->size() - 1));
        sub_extended_psa_values_builder.end_list();
    }
    m_reserved2 = new std::vector<uint16_t>();
    const int l_reserved = 16;
    auto& sub_reserved2_builder = header_builder.content<Field_header::reserved2>();
    for (int i = 0; i < l_reserved; i++) {
        sub_reserved2_builder.begin_list();
        m_reserved2->push_back(m__io->read_u2le());
        auto& reserved2_builder = sub_reserved2_builder.content();
        reserved2_builder.append(m_reserved2->at(m_reserved2->size() - 1));
        sub_reserved2_builder.end_list();
    }
}

pixie4e_t::channel_header_t::~channel_header_t() {
    _clean_up();
}

void pixie4e_t::channel_header_t::_clean_up() {
    if (m_extended_psa_values) {
        delete m_extended_psa_values; m_extended_psa_values = 0;
    }
    if (m_reserved2) {
        delete m_reserved2; m_reserved2 = 0;
    }
}

int32_t pixie4e_t::channel_header_t::timestamp_full() {
    if (f_timestamp_full)
        return m_timestamp_full;
    m_timestamp_full = ((trig_time_lo() + (trig_time_mi() << 16)) + (trig_time_hi() << 32));
    f_timestamp_full = true;
    return m_timestamp_full;
}
