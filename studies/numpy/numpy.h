#ifndef NUMPY_H_
#define NUMPY_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include "build/_deps/awkward-headers-src/layout-builder/awkward/LayoutBuilder.h"

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

enum Field_numpy : std::size_t {numpy_array};

class numpy_t : public kaitai::kstruct {

public:

    numpy_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, numpy_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~numpy_t();

private:
    uint32_t m_numpy_array;
    numpy_t* m__root;
    kaitai::kstruct* m__parent;
    RecordBuilder<
        RecordField<Field_numpy::numpy_array, NumpyBuilder<uint32_t>
        >
    > m_numpy_builder;

public:
    uint32_t numpy_array() const { return m_numpy_array; }
    numpy_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // NUMPY_H_
