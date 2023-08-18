#ifndef FAKE_H_
#define FAKE_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "build/_deps/awkward-headers-src/layout-builder/awkward/LayoutBuilder.h"
#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

using UserDefinedMap = std::map<std::size_t, std::string>;
template<class... BUILDERS>
using RecordBuilder = awkward::LayoutBuilder::Record<UserDefinedMap, BUILDERS...>;
template<std::size_t field_name, class BUILDER>
using RecordField = awkward::LayoutBuilder::Field<field_name, BUILDER>;
template<class PRIMITIVE, class BUILDER>
using ListOffsetBuilder = awkward::LayoutBuilder::ListOffset<PRIMITIVE, BUILDER>;
template<class PRIMITIVE>
using NumpyBuilder = awkward::LayoutBuilder::Numpy<PRIMITIVE>;

enum Field_fake : std::size_t {points};

enum Field_points : std::size_t {x, y, z};

class fake_t : public kaitai::kstruct {

public:
    class point_t;

    fake_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, fake_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~fake_t();

    class point_t : public kaitai::kstruct {

    public:

        point_t(kaitai::kstream* p__io, fake_t* p__parent = 0, fake_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~point_t();

    private:
        uint32_t m_x;
        uint32_t m_y;
        uint32_t m_z;
        fake_t* m__root;
        fake_t* m__parent;
        RecordBuilder<
            RecordField<Field_points::x, NumpyBuilder<uint32_t>>,
            RecordField<Field_points::y, NumpyBuilder<uint32_t>>,
            RecordField<Field_points::z, NumpyBuilder<uint32_t>>
        > m_points_builder;

    public:
        uint32_t x() const { return m_x; }
        uint32_t y() const { return m_y; }
        uint32_t z() const { return m_z; }
        fake_t* _root() const { return m__root; }
        fake_t* _parent() const { return m__parent; }
    };

private:
    std::vector<point_t*>* m_points;
    fake_t* m__root;
    kaitai::kstruct* m__parent;
    RecordBuilder<
        RecordField<Field_fake::points, ListOffsetBuilder<int64_t, RecordBuilder<
            RecordField<Field_points::x, NumpyBuilder<uint32_t>>,
            RecordField<Field_points::y, NumpyBuilder<uint32_t>>,
            RecordField<Field_points::z, NumpyBuilder<uint32_t>>
        >>>
    > m_fake_builder;

public:
    std::vector<point_t*>* points() const { return m_points; }
    fake_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // FAKE_H_
