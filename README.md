# raylib-assert

Minimalistic assertion library for [raylib](https://www.raylib.com).

## Example

``` c
#include "raylib.h"
#include "raylib-assert.h"

int main(void)
{
    Assert(15 == 20);
    // => ASSERT: 15 == 20 (main.c:22)

    Assert(IsWindowReady(), "Window has not been created");
    // => ASSERT: Window has not been created (main.c:25)

    int x = 10;
    int y = 20;
    AssertEqual(x, y, "%i and %i aren't the same!", x, y);
    // => ASSERT: 10 and 20 aren't the same! (main.c:30)

    AssertFail("DESTROY ALL HUMANS!");
    // => ASSERT: DESTROY ALL HUMANS! (main.c: 35)

    AssertBreakpoint();
    // => ASSERT: AssertBreakpoint() (main.c: 35)
}
```

## API

``` c
Assert(condition, [message], [params]);     // Asserts whether the given condition is true, with the given message parameters.
AssertNot(condition, [message], [params]);  // Asserts whether the given condition is false.
AssertEqual(expected, actual, [message], [params]); // Asserts that the expected parameter is the same as the actual parameter.
AssertFail(message, [params]);              // Sets a failed assertion, with the given message.
AssertBreakpoint();                         // Similar to AssertFail(), without a message.
```

## Options

You are able to change the behavior of assertions by making some defines prior to `#include "raylib-assert.h"`.

### `RAYLIB_ASSERT_LOG`

By default, failed assertions will report to `LOG_FATAL`, which means raylib will forcefully exit the program, and fail the application. To have failed assertions simply report a warning with `LOG_WARNING` instead, you can use...

``` c
#define RAYLIB_ASSERT_LOG LOG_WARNING
#include "raylib-assert.h"
```

### `RAYLIB_ASSERT_NDEBUG`

Assertions can be completely ignored by defining `RAYLIB_ASSERT_NDEBUG` prior to including the file. This is enabled automatically if [`NDEBUG`](https://www.oreilly.com/library/view/c-in-a/059600298X/re171.html) is in use.

``` c
#define RAYLIB_ASSERT_NDEBUG
#include "raylib-assert.h"
```

## License

raylib-assert is licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.
