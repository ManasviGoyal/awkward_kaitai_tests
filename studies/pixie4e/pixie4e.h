#ifndef PIXIE4E_H_
#define PIXIE4E_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include "build/_deps/awkward-headers-src/layout-builder/awkward/LayoutBuilder.h"
#include <vector>

using UserDefinedMap = std::map<std::size_t, std::string>;
template<class... BUILDERS>
using RecordBuilder = awkward::LayoutBuilder::Record<UserDefinedMap, BUILDERS...>;
template<std::size_t field_name, class BUILDER>
using RecordField = awkward::LayoutBuilder::Field<field_name, BUILDER>;
template<class PRIMITIVE, class BUILDER>
using ListOffsetBuilder = awkward::LayoutBuilder::ListOffset<PRIMITIVE, BUILDER>;
template<class PRIMITIVE>
using NumpyBuilder = awkward::LayoutBuilder::Numpy<PRIMITIVE>;

enum Field_pixie4e : std::size_t {file_header, events, file_footer};
enum Field_file_header : std::size_t {blk_size, mod_num, run_format, chan_head_len, coinc_pat, coinc_win, max_comb_event_len, board_version, event_length_0, event_length_1, event_length_2, event_length_3, serial_number, reserved1};
enum Field_events : std::size_t {elements};
enum Field_elements : std::size_t {header, data};
enum Field_header : std::size_t {evt_pattern1, evt_info1, num_trace_blks1, num_trace_blks_prev1, trig_time_lo, trig_time_mi, trig_time_hi, trig_time_x, energy, chan_no, user_psa_value, xia_psa_value, extended_psa_values, reserved2};
enum Field_file_footer : std::size_t {evt_pattern2, evt_info2, num_trace_blks2, num_trace_blks_prev2, reserved3};

using Pixie4eBuilderType =
	RecordBuilder<
		RecordField<Field_pixie4e::file_header, RecordBuilder<
			RecordField<Field_file_header::blk_size, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::mod_num, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::run_format, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::chan_head_len, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::coinc_pat, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::coinc_win, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::max_comb_event_len, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::board_version, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::event_length_0, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::event_length_1, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::event_length_2, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::event_length_3, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::serial_number, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_header::reserved1, NumpyBuilder<uint16_t>>
		>>,
		RecordField<Field_pixie4e::events, RecordBuilder<
			RecordField<Field_events::elements, ListOffsetBuilder<int64_t, RecordBuilder<
				RecordField<Field_elements::header, RecordBuilder<
					RecordField<Field_header::evt_pattern1, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::evt_info1, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::num_trace_blks1, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::num_trace_blks_prev1, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::trig_time_lo, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::trig_time_mi, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::trig_time_hi, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::trig_time_x, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::energy, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::chan_no, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::user_psa_value, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::xia_psa_value, NumpyBuilder<uint16_t>>,
					RecordField<Field_header::extended_psa_values, ListOffsetBuilder<int64_t, NumpyBuilder<uint16_t>>>,
					RecordField<Field_header::reserved2, ListOffsetBuilder<int64_t, NumpyBuilder<uint16_t>>>
				>>,
				RecordField<Field_elements::data, ListOffsetBuilder<int64_t, NumpyBuilder<uint16_t>>>
			>>>
		>>,
		RecordField<Field_pixie4e::file_footer, RecordBuilder<
			RecordField<Field_file_footer::evt_pattern2, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_footer::evt_info2, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_footer::num_trace_blks2, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_footer::num_trace_blks_prev2, NumpyBuilder<uint16_t>>,
			RecordField<Field_file_footer::reserved3, NumpyBuilder<uint16_t>>
		>>
	>;
using EventsBuilderType = decltype(std::declval<Pixie4eBuilderType>().content<Field_pixie4e::events>());
using ElementsBuilderType = decltype(std::declval<EventsBuilderType>().content<Field_events::elements>().content());
using File_footerBuilderType = decltype(std::declval<Pixie4eBuilderType>().content<Field_pixie4e::file_footer>());
using File_headerBuilderType = decltype(std::declval<Pixie4eBuilderType>().content<Field_pixie4e::file_header>());
using HeaderBuilderType = decltype(std::declval<ElementsBuilderType>().content<Field_elements::header>());


#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class pixie4e_t : public kaitai::kstruct {

public:
    class event_t;
    class element_t;
    class pixie_eor_t;
    class pixie4e_header_t;
    class channel_header_t;

    pixie4e_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, pixie4e_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~pixie4e_t();

    class event_t : public kaitai::kstruct {

    public:

        event_t(kaitai::kstream* p__io, pixie4e_t* p__parent = 0, pixie4e_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~event_t();

    private:
        std::vector<element_t*>* m_elements;
        pixie4e_t* m__root;
        pixie4e_t* m__parent;

    public:
        std::vector<element_t*>* elements() const { return m_elements; }
        pixie4e_t* _root() const { return m__root; }
        pixie4e_t* _parent() const { return m__parent; }
        EventsBuilderType events_builder;
    };

    class element_t : public kaitai::kstruct {

    public:

        element_t(kaitai::kstream* p__io, pixie4e_t::event_t* p__parent = 0, pixie4e_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~element_t();

    private:
        channel_header_t* m_header;
        std::vector<uint16_t>* m_data;
        pixie4e_t* m__root;
        pixie4e_t::event_t* m__parent;

    public:
        channel_header_t* header() const { return m_header; }
        std::vector<uint16_t>* data() const { return m_data; }
        pixie4e_t* _root() const { return m__root; }
        pixie4e_t::event_t* _parent() const { return m__parent; }
        ElementsBuilderType elements_builder;
    };

    class pixie_eor_t : public kaitai::kstruct {

    public:

        pixie_eor_t(kaitai::kstream* p__io, pixie4e_t* p__parent = 0, pixie4e_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~pixie_eor_t();

    private:
        uint16_t m_evt_pattern2;
        uint16_t m_evt_info2;
        uint16_t m_num_trace_blks2;
        uint16_t m_num_trace_blks_prev2;
        uint16_t m_reserved3;
        pixie4e_t* m__root;
        pixie4e_t* m__parent;

    public:
        uint16_t evt_pattern2() const { return m_evt_pattern2; }
        uint16_t evt_info2() const { return m_evt_info2; }
        uint16_t num_trace_blks2() const { return m_num_trace_blks2; }
        uint16_t num_trace_blks_prev2() const { return m_num_trace_blks_prev2; }
        uint16_t reserved3() const { return m_reserved3; }
        pixie4e_t* _root() const { return m__root; }
        pixie4e_t* _parent() const { return m__parent; }
        File_footerBuilderType file_footer_builder;
    };

    class pixie4e_header_t : public kaitai::kstruct {

    public:

        pixie4e_header_t(kaitai::kstream* p__io, pixie4e_t* p__parent = 0, pixie4e_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~pixie4e_header_t();

    private:
        uint16_t m_blk_size;
        uint16_t m_mod_num;
        uint16_t m_run_format;
        uint16_t m_chan_head_len;
        uint16_t m_coinc_pat;
        uint16_t m_coinc_win;
        uint16_t m_max_comb_event_len;
        uint16_t m_board_version;
        uint16_t m_event_length_0;
        uint16_t m_event_length_1;
        uint16_t m_event_length_2;
        uint16_t m_event_length_3;
        uint16_t m_serial_number;
        uint16_t m_reserved1;
        pixie4e_t* m__root;
        pixie4e_t* m__parent;

    public:
        uint16_t blk_size() const { return m_blk_size; }
        uint16_t mod_num() const { return m_mod_num; }
        uint16_t run_format() const { return m_run_format; }
        uint16_t chan_head_len() const { return m_chan_head_len; }
        uint16_t coinc_pat() const { return m_coinc_pat; }
        uint16_t coinc_win() const { return m_coinc_win; }
        uint16_t max_comb_event_len() const { return m_max_comb_event_len; }
        uint16_t board_version() const { return m_board_version; }
        uint16_t event_length_0() const { return m_event_length_0; }
        uint16_t event_length_1() const { return m_event_length_1; }
        uint16_t event_length_2() const { return m_event_length_2; }
        uint16_t event_length_3() const { return m_event_length_3; }
        uint16_t serial_number() const { return m_serial_number; }
        uint16_t reserved1() const { return m_reserved1; }
        pixie4e_t* _root() const { return m__root; }
        pixie4e_t* _parent() const { return m__parent; }
        File_headerBuilderType file_header_builder;
    };

    class channel_header_t : public kaitai::kstruct {

    public:

        channel_header_t(kaitai::kstream* p__io, pixie4e_t::element_t* p__parent = 0, pixie4e_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~channel_header_t();

    private:
        bool f_timestamp_full;
        int32_t m_timestamp_full;

    public:
        int32_t timestamp_full();

    private:
        uint16_t m_evt_pattern1;
        uint16_t m_evt_info1;
        uint16_t m_num_trace_blks1;
        uint16_t m_num_trace_blks_prev1;
        uint16_t m_trig_time_lo;
        uint16_t m_trig_time_mi;
        uint16_t m_trig_time_hi;
        uint16_t m_trig_time_x;
        uint16_t m_energy;
        uint16_t m_chan_no;
        uint16_t m_user_psa_value;
        uint16_t m_xia_psa_value;
        std::vector<uint16_t>* m_extended_psa_values;
        std::vector<uint16_t>* m_reserved2;
        pixie4e_t* m__root;
        pixie4e_t::element_t* m__parent;

    public:
        uint16_t evt_pattern1() const { return m_evt_pattern1; }
        uint16_t evt_info1() const { return m_evt_info1; }
        uint16_t num_trace_blks1() const { return m_num_trace_blks1; }
        uint16_t num_trace_blks_prev1() const { return m_num_trace_blks_prev1; }
        uint16_t trig_time_lo() const { return m_trig_time_lo; }
        uint16_t trig_time_mi() const { return m_trig_time_mi; }
        uint16_t trig_time_hi() const { return m_trig_time_hi; }
        uint16_t trig_time_x() const { return m_trig_time_x; }
        uint16_t energy() const { return m_energy; }
        uint16_t chan_no() const { return m_chan_no; }
        uint16_t user_psa_value() const { return m_user_psa_value; }
        uint16_t xia_psa_value() const { return m_xia_psa_value; }
        std::vector<uint16_t>* extended_psa_values() const { return m_extended_psa_values; }
        std::vector<uint16_t>* reserved2() const { return m_reserved2; }
        pixie4e_t* _root() const { return m__root; }
        pixie4e_t::element_t* _parent() const { return m__parent; }
        HeaderBuilderType header_builder;
    };

private:
    pixie4e_header_t* m_file_header;
    event_t* m_events;
    pixie_eor_t* m_file_footer;
    pixie4e_t* m__root;
    kaitai::kstruct* m__parent;
    std::string m__raw_events;
    kaitai::kstream* m__io__raw_events;

public:
    pixie4e_header_t* file_header() const { return m_file_header; }
    event_t* events() const { return m_events; }
    pixie_eor_t* file_footer() const { return m_file_footer; }
    pixie4e_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
    std::string _raw_events() const { return m__raw_events; }
    kaitai::kstream* _io__raw_events() const { return m__io__raw_events; }
    Pixie4eBuilderType pixie4e_builder;
};

#endif  // PIXIE4E_H_
