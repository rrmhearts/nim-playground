# Nim Startup

The version of Nim being tested is what was available through the snap package on Ubuntu. The version info is as follows:
```
nim-lang.nim --version
Nim Compiler Version 1.0.4 [Linux: amd64]
Compiled at 2019-12-17
Copyright (c) 2006-2019 by Andreas Rumpf

git hash: 99bbbea1d5f1d68406734d87fe87ba67cb5b1f7b
active boot switches: -d:release

```
## Installation
```
snap install nim-lang --classic
```
## Compile
```
nim c hello
./hello

### Build and run
nim c -r hello
```


## Run Time
The run time of Nim compared to C
**Nim**
```
var x = 0;
for i in 1 .. 100_000_000:
    inc x # comment
echo "... ", x
echo "Hello, world!"
```
**Nim Timing**
```
time ./hello 
... 100000000
Hello, world!

real	0m0.777s
user	0m0.773s
sys	0m0.004s

```
**C**
<div style="-webkit-column-count: 2; -moz-column-count: 2; column-count: 2; -webkit-column-rule: 1px dotted #e0e0e0; -moz-column-rule: 1px dotted #e0e0e0; column-rule: 1px dotted #e0e0e0;">
    <div style="display: inline-block;">
        <h2>C</h2>
        <pre><code class="language-c">
#include <stdio.h>

int main() {
  int i;
  for (i = 0; i < 100000000; i++)
    i++;
  printf("... %d\n", i);
  printf("Hello, world!\n");
}

</code></pre>
    </div>
    <div style="display: inline-block;">
        <h2>Timing</h2>
        <pre>
time ./helloC
... 100000000
Hello, world!

real	0m0.143s
user	0m0.143s
sys	0m0.000s
	</pre>
    </div>
</div>

## Errors

There seems to be issues with importing packages. This program from the homepage will not compile.
```
import strformat 

type
  Person = object
    name: string
    age: Natural # Ensures the age is positive

let people = [
  Person(name: "John", age: 45),
  Person(name: "Kate", age: 30)
]

for person in people:
  # Type-safe string interpolation,
  # evaluated at compile time.
  echo(fmt"{person.name} is {person.age} years old")
```
The error is `object.nim(1, 8) Error: cannot open file: strformat`. 

A similar error exists with the `macros` package from a snippet also available on the homepage.

## Conclusion
It seems to me that `Nim` is not ready for primetime.
