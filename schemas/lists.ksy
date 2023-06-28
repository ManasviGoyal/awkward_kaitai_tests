meta:
  id: lists
  file-extension: lists
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