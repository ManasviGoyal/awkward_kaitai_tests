# awkward-kaitai
Building Awkward Arrays using Kaitai binary file descriptors.

Steps for reproducing the environment:

1. Clone kaitai_struct_compiler: `git clone https://github.com/ManasviGoyal/kaitai_struct_compiler.git` and checkout `ManasviGoyal/awkward-target` branch.

2. Compile the kaitai_struct_compiler in its repository: `sbt package`

3. Clone awkward_kaitai_tests `git clone --recursive https://github.com/ManasviGoyal/awkward_kaitai_tests.git`

4. Convert the KSY specs into C++ code in the awkward_kaitai_tests repository: `./kaitai-struct-compiler -t awkward --outdir src-animal schemas/animal.ksy`

5. Then compile it: `g++ -DKS_STR_ENCODING_NONE -Ikaitai_struct_awkward_runtime -I. kaitai_struct_awkward_runtime/kaitai/kaitaistream.cpp src-animal/animal.cpp test-animal.cpp -o test-animal`

6. Run: `./test-animal`