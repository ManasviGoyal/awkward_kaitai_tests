meta:
  id: array_of_lists_of_floats
  file-extension: array_of_lists_of_floats
  endian: le
  
seq:
  - id: sample_blk
    type: sample_block
    repeat: eos
    
types:
  sample_block:
    seq:
      - id: num_sample
        type: u4
      - id: sample
        type: f8
        repeat: expr
        repeat-expr: num_sample