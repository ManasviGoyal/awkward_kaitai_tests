#ifndef RECORDS_H_
#define RECORDS_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include "build/_deps/awkward-headers-src/layout-builder/awkward/LayoutBuilder.h"
#include <vector>

template <class NODE, class PRIMITIVE, class LENGTH>
void dump(std::ostringstream& out, NODE&& node, PRIMITIVE&& ptr, LENGTH&& length) {
  out << node << ": ";
  for (size_t i = 0; i < length; i++) {
    out << +ptr[i] << " ";
  }
  out << std::endl;
}

template<class NODE, class PRIMITIVE, class LENGTH, class ... Args>
void dump(std::ostringstream& out, NODE&& node, PRIMITIVE&& ptr, LENGTH&& length, Args&&...args)
{
    dump(out, node, ptr, length);
    dump(out, args...);
}

std::map<std::string, void*>
inline empty_buffers(std::map<std::string, size_t> &names_nbytes) {
  std::map<std::string, void*> buffers = {};
  for(const auto& it : names_nbytes) {
    auto* ptr = new uint8_t[it.second];
    buffers[it.first] = (void*)ptr;
  }
  return buffers;
}

using UserDefinedMap = std::map<std::size_t, std::string>;
template<class... BUILDERS>
using RecordBuilder = awkward::LayoutBuilder::Record<UserDefinedMap, BUILDERS...>;
template<std::size_t field_name, class BUILDER>
using RecordField = awkward::LayoutBuilder::Field<field_name, BUILDER>;
template<class PRIMITIVE, class BUILDER>
using ListOffsetBuilder = awkward::LayoutBuilder::ListOffset<PRIMITIVE, BUILDER>;
template<class PRIMITIVE>
using NumpyBuilder = awkward::LayoutBuilder::Numpy<PRIMITIVE>;

enum Field_records : std::size_t {points}; 
enum Field_points : std::size_t {x}; 
enum Field_x : std::size_t {a}; 

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class records_t : public kaitai::kstruct {

public:
    class point_t;

    records_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, records_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~records_t();

    class point_t : public kaitai::kstruct {

    public:
        class x_point_t;

        point_t(kaitai::kstream* p__io, records_t* p__parent = 0, records_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~point_t();

        class x_point_t : public kaitai::kstruct {

        public:

            x_point_t(kaitai::kstream* p__io, records_t::point_t* p__parent = 0, records_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~x_point_t();

        private:
            double m_a;
            records_t* m__root;
            records_t::point_t* m__parent;

        public:
            double a() const { return m_a; }
            records_t* _root() const { return m__root; }
            records_t::point_t* _parent() const { return m__parent; }
            RecordBuilder<
                RecordField<Field_x::a, NumpyBuilder<double>>
            >& x_builder;
        };

    private:
        std::vector<x_point_t*>* m_x;
        records_t* m__root;
        records_t* m__parent;

    public:
        std::vector<x_point_t*>* x() const { return m_x; }
        records_t* _root() const { return m__root; }
        records_t* _parent() const { return m__parent; }
        RecordBuilder<
            RecordField<Field_points::x, ListOffsetBuilder<int64_t, RecordBuilder<
                RecordField<Field_x::a, NumpyBuilder<double>>
            >>>
        >& points_builder;
    };

private:
    std::vector<point_t*>* m_points;
    records_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::vector<point_t*>* points() const { return m_points; }
    records_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
    RecordBuilder<
        RecordField<Field_records::points, ListOffsetBuilder<int64_t, RecordBuilder<
            RecordField<Field_points::x, ListOffsetBuilder<int64_t, RecordBuilder<
                RecordField<Field_x::a, NumpyBuilder<double>>
            >>>
        >>>
    > records_builder;
};

#endif  // RECORDS_H_
