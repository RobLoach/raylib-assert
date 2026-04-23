# raylib-assert

Minimalistic [assertion](https://en.wikipedia.org/wiki/Assertion_(software_development)) library for [raylib](https://www.raylib.com).

Targets `raylib` `6.0+`.

## Example

``` c
#include "raylib.h"
#include "raylib-assert.h"

int main(void)
{
    Assert(10 == 10);
    // => Reports nothing, since the assert passes.

    Assert(IsWindowReady());
    // => ASSERT: IsWindowReady() (main.c:22)

    Assert(IsWindowReady(), "Window has not been created");
    // => ASSERT: Window has not been created (main.c:25)

    int x = 10;
    int y = 20;
    AssertEqual(x, y, "%i and %i aren't the same!", x, y);
    // => ASSERT: 10 and 20 aren't the same! (main.c:30)

    AssertFail("DESTROY ALL HUMANS!");
    // => ASSERT: DESTROY ALL HUMANS! (main.c: 35)

    Image image = LoadImage("NotFound.png");
    AssertImage(image);
    // => ASSERT: AssertImage(image) - Image not loaded (main.c:40)
}
```

## API

``` c
Assert(condition, [message], [params]);      // Asserts whether the given condition is true.
AssertNot(condition, [message], [params]);   // Asserts whether the given condition is false.
AssertEqual(actual, expected, [message], [params]); // Asserts that the actual value equals the expected value.
AssertNotEqual(actual, unexpected, [message], [params]); // Asserts that the actual value does not equal the unexpected value.
AssertFail([message], [params]);             // Sets a failed assertion, with the given message.
AssertNull(ptr, [message], [params]);        // Asserts whether the given pointer is NULL.
AssertNotNull(ptr, [message], [params]);     // Asserts whether the given pointer is not NULL.
AssertStringEqual(str1, str2, [message], [params]); // Asserts whether the two strings are equal.
AssertStringNotEqual(str1, str2, [message], [params]); // Asserts whether the two strings are not equal.
AssertGreater(actual, expected, [message], [params]); // Asserts that actual is greater than expected.
AssertLess(actual, expected, [message], [params]);    // Asserts that actual is less than expected.
AssertGreaterEqual(actual, expected, [message], [params]); // Asserts that actual is greater than or equal to expected.
AssertLessEqual(actual, expected, [message], [params]); // Asserts that actual is less than or equal to expected.
AssertFloatEqual(actual, expected, [message], [params]); // Asserts that two floats are equal within `RAYLIB_ASSERT_EPSILON`.
AssertInRange(value, min, max, [message], [params]); // Asserts that a value is within the inclusive range `[min, max]`.
AssertImage(image, [message], [params]);     // Asserts whether the given image has been loaded properly.
AssertImageSize(image, width, height, [message], [params]); // Asserts whether the given image matches the expected size.
AssertTexture(texture, [message], [params]); // Asserts whether the given texture has been loaded properly.
AssertMesh(mesh, [message], [params]);       // Asserts whether the given mesh contains valid CPU-side geometry data.
AssertMaterial(material, [message], [params]); // Asserts whether the given material has been loaded properly.
AssertRenderTexture(target, [message], [params]); // Asserts whether the given render texture has been loaded properly.
AssertFont(font, [message], [params]);       // Asserts whether the given font has been loaded properly.
AssertShader(shader, [message], [params]);   // Asserts whether the given shader has been loaded properly.
AssertModel(model, [message], [params]);     // Asserts whether the given model has been loaded properly.
AssertModelAnimation(model, animation, [message], [params]); // Asserts whether the given animation is valid for the given model.
AssertWave(wave, [message], [params]);       // Asserts whether the given wave has been loaded properly.
AssertSound(sound, [message], [params]);     // Asserts whether the given sound has been loaded properly.
AssertMusic(music, [message], [params]);     // Asserts whether the given music has been loaded properly.
AssertAudioStream(stream, [message], [params]); // Asserts whether the given audio stream has been loaded properly.
AssertColorSame(color1, color2, [message], [params]);     // Asserts whether the given colors are the same.
AssertColorApprox(color1, color2, tolerance, [message], [params]); // Asserts whether the given colors are within a per-channel tolerance.
AssertImageSame(image1, image2, [message], [params]);     // Asserts whether the given images are the same.
AssertVector2Same(vector1, vector2, [message], [params]); // Asserts whether the given Vector2s are the same.
AssertVector3Same(vector1, vector2, [message], [params]); // Asserts whether the given Vector3s are the same.
AssertVector4Same(vector1, vector2, [message], [params]); // Asserts whether the given Vector4s are the same.
AssertRectangleSame(rect1, rect2, [message], [params]);   // Asserts whether the given Rectangles are the same.
```

Notes:

- `AssertMesh()` validates basic CPU-side mesh data (`vertexCount`, `triangleCount`, and `vertices`).
- `AssertModelAnimation()` maps to raylib's `IsModelAnimationValid(model, animation)` check.
- `AssertColorApprox()` uses the explicit `tolerance` you provide instead of `RAYLIB_ASSERT_EPSILON`.

## Options

You are able to change the behavior of assertions by making some defines prior to including `raylib-assert.h`:
``` c
// #define RAYLIB_ASSERT_LOG LOG_FATAL
// #define RAYLIB_ASSERT_NDEBUG
// #define RAYLIB_ASSERT_TRACELOG TraceLog
// #define RAYLIB_ASSERT_TEXTFORMAT TextFormat
// #define RAYLIB_ASSERT_EPSILON 0.000001f
#include "raylib-assert.h"
```

### `RAYLIB_ASSERT_LOG`

The trace log level to use when reporting to TraceLog() on failed assertions. By default, will report to `LOG_FATAL`. This will result in a forceful exit of the program, and fail the application. To have failed assertions simply report a warning with `LOG_WARNING` instead, you can use...

``` c
#define RAYLIB_ASSERT_LOG LOG_WARNING
```

### `RAYLIB_ASSERT_NDEBUG`

Assertions can be completely ignored by defining `RAYLIB_ASSERT_NDEBUG` prior to including the file. This is enabled automatically if [`NDEBUG`](https://www.oreilly.com/library/view/c-in-a/059600298X/re171.html) is in use.

``` c
#define RAYLIB_ASSERT_NDEBUG
```

### `RAYLIB_ASSERT_TRACELOG`

Allows changing which `TraceLog()` function the assertion library uses to output messages.

``` c
#define RAYLIB_ASSERT_TRACELOG TraceLog
```

### `RAYLIB_ASSERT_TEXTFORMAT`

Allows changing which `TextFormat()` function the assertion library uses to output messages.

``` c
#define RAYLIB_ASSERT_TEXTFORMAT TextFormat
```

### `RAYLIB_ASSERT_EPSILON`

The tolerance used for floating-point comparisons in `AssertFloatEqual()`, `AssertVector2Same()`, `AssertVector3Same()`, `AssertVector4Same()`, and `AssertRectangleSame()`. Defaults to `0.000001f`.

``` c
#define RAYLIB_ASSERT_EPSILON 0.000001f
```

## License

raylib-assert is licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.
