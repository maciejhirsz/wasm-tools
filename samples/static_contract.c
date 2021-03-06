int data;

int call(void* descriptor) {
    int* input_length = (int*)(descriptor+4);
    data += *input_length;
}

/* produces the following code (with gas counter and call optimization)
(module
  (type (;0;) (func (param i32) (result i32)))
  (type (;1;) (func))
  (type (;2;) (func (param i32)))
  (import "env" "memoryBase" (global (;0;) i32))
  (import "env" "memory" (memory (;0;) 256))
  (import "env" "table" (table (;0;) 0 anyfunc))
  (import "env" "gas" (func (;0;) (type 2)))
  (func (;1;) (type 0) (param i32) (result i32)
    i32.const 2
    call 0
    block i32  ;; label = @1
      i32.const 13
      call 0
      get_global 0
      i32.const 5242880
      i32.add
      get_global 0
      i32.const 5242880
      i32.add
      i32.load
      get_local 0
      i32.load offset=4
      i32.add
      i32.store
      i32.const 0
    end)
  (export "_call" (func 1)))

*/
