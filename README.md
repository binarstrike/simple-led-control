# Simple LED Control
### Catatan
Jika ingin menaruh data yang bersifat rahasia seperti `auth token`, `nama akses point` atau `password wifi` di luar file sketch .ino
ubah nama file `secret.example.h` menjadi `secret.h` dan isi pada file header tersebut.

Jika tidak, hapus baris pada file sketch `simple-led-control.ino` yang terdapat kode berikut:
```cpp
#include "secret.h"
```
