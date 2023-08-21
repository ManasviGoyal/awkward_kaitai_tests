#ifndef LISTS_H_
#define LISTS_H_

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

enum Field_lists : std::size_t {sample_blk, sample_blk2}; 
enum Field_sample_blk : std::size_t {num_sample, sample}; 
enum Field_sample : std::size_t {num_example}; 
enum Field_sample_blk2 : std::size_t {num_sample2, sample2}; 

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class lists_t : public kaitai::kstruct {

public:
    class sample_block_t;
    class sample_block2_t;

    lists_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, lists_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~lists_t();

    class sample_block_t : public kaitai::kstruct {

    public:
        class example_t;

        sample_block_t(kaitai::kstream* p__io, lists_t* p__parent = 0, lists_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sample_block_t();

        class example_t : public kaitai::kstruct {

        public:

            example_t(kaitai::kstream* p__io, lists_t::sample_block_t* p__parent = 0, lists_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~example_t();

        private:
            uint32_t m_num_example;
            lists_t* m__root;
            lists_t::sample_block_t* m__parent;

        public:
            uint32_t num_example() const { return m_num_example; }
            lists_t* _root() const { return m__root; }
            lists_t::sample_block_t* _parent() const { return m__parent; }
            RecordBuilder<
                RecordField<Field_sample::num_example, NumpyBuilder<uint32_t>>
            >& sample_builder;
        };

    private:
        uint32_t m_num_sample;
        std::vector<example_t*>* m_sample;
        lists_t* m__root;
        lists_t* m__parent;

    public:
        uint32_t num_sample() const { return m_num_sample; }
        std::vector<example_t*>* sample() const { return m_sample; }
        lists_t* _root() const { return m__root; }
        lists_t* _parent() const { return m__parent; }
        RecordBuilder<
            RecordField<Field_sample_blk::num_sample, NumpyBuilder<uint32_t>>,
            RecordField<Field_sample_blk::sample, ListOffsetBuilder<int64_t, RecordBuilder<
                RecordField<Field_sample::num_example, NumpyBuilder<uint32_t>>
            >>>
        >& sample_blk_builder;
    };

    class sample_block2_t : public kaitai::kstruct {

    public:

        sample_block2_t(kaitai::kstream* p__io, lists_t* p__parent = 0, lists_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sample_block2_t();

    private:
        uint32_t m_num_sample2;
        std::vector<double>* m_sample2;
        lists_t* m__root;
        lists_t* m__parent;

    public:
        uint32_t num_sample2() const { return m_num_sample2; }
        std::vector<double>* sample2() const { return m_sample2; }
        lists_t* _root() const { return m__root; }
        lists_t* _parent() const { return m__parent; }
        RecordBuilder<
            RecordField<Field_sample_blk2::num_sample2, NumpyBuilder<uint32_t>>,
            RecordField<Field_sample_blk2::sample2, ListOffsetBuilder<int64_t, NumpyBuilder<double>>>
        >& sample_blk2_builder;
    };

private:
    std::vector<sample_block_t*>* m_sample_blk;
    sample_block2_t* m_sample_blk2;
    lists_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::vector<sample_block_t*>* sample_blk() const { return m_sample_blk; }
    sample_block2_t* sample_blk2() const { return m_sample_blk2; }
    lists_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
    RecordBuilder<
        RecordField<Field_lists::sample_blk, ListOffsetBuilder<int64_t, RecordBuilder<
            RecordField<Field_sample_blk::num_sample, NumpyBuilder<uint32_t>>,
            RecordField<Field_sample_blk::sample, ListOffsetBuilder<int64_t, RecordBuilder<
                RecordField<Field_sample::num_example, NumpyBuilder<uint32_t>>
            >>>
        >>>,
        RecordField<Field_lists::sample_blk2, RecordBuilder<
            RecordField<Field_sample_blk2::num_sample2, NumpyBuilder<uint32_t>>,
            RecordField<Field_sample_blk2::sample2, ListOffsetBuilder<int64_t, NumpyBuilder<double>>>
        >>
    > lists_builder;
};

#endif  // LISTS_H_
