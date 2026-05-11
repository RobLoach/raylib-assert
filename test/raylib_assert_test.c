#include "raylib.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define RAYLIB_ASSERT_LOG LOG_NONE
#define RAYLIB_ASSERT_TRACELOG TestAssertTraceLog

static bool testExpectPass = true; /** When true, will expect the sequential asserts to pass. */
static int testExpectLine = 0; /** The line number for the previous test section. */
static int testFiresInSection = 0; /** The number of test files set in the section. */
static int testRegressions = 0; /** The total number of found regressions. */

static void TestValidateSection(void) {
    if (testExpectPass == false && testFiresInSection == 0) {
        TraceLog(LOG_ERROR, "SetExpectFail section at line %i fired no assertions", testExpectLine);
        testRegressions++;
    }
}

/**
 * Let the testing framework expect the sequential asserts to pass.
 */
#define SetExpectPass() do { TestValidateSection(); testExpectPass = true; testExpectLine = __LINE__; testFiresInSection = 0; } while(0)

/**
 * Let the testing framework expect the sequential asserts should fail.
 */
#define SetExpectFail() do { TestValidateSection(); testExpectPass = false; testExpectLine = __LINE__; testFiresInSection = 0; } while(0)

static void TestAssertTraceLog(int logLevel, const char *text, ...) {
    (void)logLevel;
    static char buffer[4096];
    va_list args;
    va_start(args, text);
    vsnprintf(buffer, sizeof(buffer), text, args);
    va_end(args);

    testFiresInSection++;
    if (testExpectPass) {
        testRegressions++;
        TraceLog(LOG_ERROR, "Expected Pass, but Failed: %s", buffer);
    }
}

#include "raylib-assert.h"

int main(int argc, char *argv[]) {
    // Not used paraemters.
    (void)argc;
    (void)argv;

    // Only output failures.
    SetTraceLogLevel(LOG_ERROR);

    // Make sure we're running in the correct directory.
    ChangeDirectory(GetApplicationDirectory());

    // Assert(1)
    SetExpectPass();
    Assert(1);
    Assert(1, "Assert(1)");
    Assert(1, "Assert(1) - %i", 1);
    Assert(1, "Assert(1) - %i, %i", 1, 2);
    Assert(1, "Assert(1) - %i, %i, %i", 1, 2, 3);
    Assert(1, "Assert(1) - %i, %i, %i, %i", 1, 2, 3, 4);
    Assert(1, "Assert(1) - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // Assert(0)
    SetExpectFail();
    Assert(0, "Assert(0)");
    Assert(0, "Assert(0) - %i", 1);
    Assert(0, "Assert(0) - %i, %i", 1, 2);
    Assert(0, "Assert(0) - %i, %i, %i", 1, 2, 3);
    Assert(0, "Assert(0) - %i, %i, %i, %i", 1, 2, 3, 4);
    Assert(0, "Assert(0) - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertEqual: single-arg form fails (requires two parameters)
    SetExpectFail();
    AssertEqual(1);

    // AssertEqual: matching values pass
    SetExpectPass();
    AssertEqual(1, 1);
    AssertEqual(1, 1, "AssertEqual(1, 1)");
    AssertEqual(1, 1, "AssertEqual(1, 1) - %i", 1);
    AssertEqual(1, 1, "AssertEqual(1, 1) - %i, %i", 1, 2);
    AssertEqual(1, 1, "AssertEqual(1, 1) - %i, %i, %i", 1, 2, 3);
    AssertEqual(1, 1, "AssertEqual(1, 1) - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertEqual: mismatching values fail (plus another single-arg form)
    SetExpectFail();
    AssertEqual(0);
    AssertEqual(1, 0);
    AssertEqual(1, 0, "AssertEqual(1, 0)");
    AssertEqual(1, 0, "AssertEqual(1, 0) - %i", 1);
    AssertEqual(1, 0, "AssertEqual(1, 0) - %i, %i", 1, 2);
    AssertEqual(1, 0, "AssertEqual(1, 0) - %i, %i, %i", 1, 2, 3);
    AssertEqual(1, 0, "AssertEqual(1, 0) - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertNotEqual: single-arg forms fail (requires two parameters)
    SetExpectFail();
    AssertNotEqual(0);
    AssertNotEqual(1);

    // AssertNotEqual: different values pass
    SetExpectPass();
    AssertNotEqual(1, 0);
    AssertNotEqual(1, 0, "AssertNotEqual(1, 0)");
    AssertNotEqual(1, 0, "AssertNotEqual(1, 0) - %i", 1);
    AssertNotEqual(1, 0, "AssertNotEqual(1, 0) - %i, %i", 1, 2);
    AssertNotEqual(1, 0, "AssertNotEqual(1, 0) - %i, %i, %i", 1, 2, 3);
    AssertNotEqual(1, 0, "AssertNotEqual(1, 0) - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertNotEqual: equal values fail
    SetExpectFail();
    AssertNotEqual(1, 1);
    AssertNotEqual(1, 1, "AssertNotEqual(1, 1)");
    AssertNotEqual(1, 1, "AssertNotEqual(1, 1) - %i", 1);
    AssertNotEqual(1, 1, "AssertNotEqual(1, 1) - %i, %i", 1, 2);
    AssertNotEqual(1, 1, "AssertNotEqual(1, 1) - %i, %i, %i", 1, 2, 3);
    AssertNotEqual(1, 1, "AssertNotEqual(1, 1) - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertNot(0)
    SetExpectPass();
    AssertNot(0);
    AssertNot(0, "AssertNot(0)");
    AssertNot(0, "AssertNot(0) - %i", 1);
    AssertNot(0, "AssertNot(0) - %i, %i", 1, 2);
    AssertNot(0, "AssertNot(0) - %i, %i, %i", 1, 2, 3);
    AssertNot(0, "AssertNot(0) - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertNot(0, "AssertNot(0) - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertNot(1)
    SetExpectFail();
    AssertNot(1);
    AssertNot(1, "AssertNot(1)");
    AssertNot(1, "AssertNot(1) - %i", 1);
    AssertNot(1, "AssertNot(1) - %i, %i", 1, 2);
    AssertNot(1, "AssertNot(1) - %i, %i, %i", 1, 2, 3);
    AssertNot(1, "AssertNot(1) - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertNot(1, "AssertNot(1) - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertFail()
    SetExpectFail();
    AssertFail("AssertFail()");
    AssertFail("AssertFail() - %i", 1);
    AssertFail("AssertFail() - %i, %i", 1, 2);
    AssertFail("AssertFail() - %i, %i, %i", 1, 2, 3);
    AssertFail("AssertFail() - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertFail("AssertFail() - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);
    AssertFail("AssertFail() - %i, %i, %i, %i, %i, %i", 1, 2, 3, 4, 5, 6);

    // AssertImage() - valid image passes
    {
        Image validImage = LoadImage("resources/test-image.png");
        SetExpectPass();
        AssertImage(validImage);
        AssertImage(validImage, "AssertImage()");
        AssertImage(validImage, "AssertImage() - %i", 1);
        AssertImage(validImage, "AssertImage() - %i, %i", 1, 2);
        AssertImage(validImage, "AssertImage() - %i, %i, %i", 1, 2, 3);
        AssertImage(validImage, "AssertImage() - %i, %i, %i, %i", 1, 2, 3, 4);
        UnloadImage(validImage);
    }

    // AssertImage() - missing image fails
    {
        Image image = LoadImage("NotFound.png");
        SetExpectFail();
        AssertImage(image);
        AssertImage(image, "AssertImage()");
        AssertImage(image, "AssertImage() - %i", 1);
        AssertImage(image, "AssertImage() - %i, %i", 1, 2);
        AssertImage(image, "AssertImage() - %i, %i, %i", 1, 2, 3);
        AssertImage(image, "AssertImage() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertImageSize()
    {
        Image sizedImage = LoadImage("resources/test-image.png");

        SetExpectPass();
        AssertImageSize(sizedImage, sizedImage.width, sizedImage.height);
        AssertImageSize(sizedImage, sizedImage.width, sizedImage.height, "AssertImageSize()");

        SetExpectFail();
        AssertImageSize(sizedImage, sizedImage.width + 1, sizedImage.height + 1);
        AssertImageSize(sizedImage, sizedImage.width + 1, sizedImage.height + 1, "AssertImageSize()");
        AssertImageSize(sizedImage, sizedImage.width + 1, sizedImage.height + 1, "AssertImageSize() - %i", 1);
        AssertImageSize(sizedImage, sizedImage.width + 1, sizedImage.height + 1, "AssertImageSize() - %i, %i", 1, 2);
        AssertImageSize(sizedImage, sizedImage.width + 1, sizedImage.height + 1, "AssertImageSize() - %i, %i, %i", 1, 2, 3);
        UnloadImage(sizedImage);
    }

    // AssertColorSame()
    {
        Color red = RED;
        Color blue = BLUE;
        Color red2 = RED;

        SetExpectPass();
        AssertColorSame(red, red2);
        AssertColorSame(red, red2, "AssertColorSame()");

        SetExpectFail();
        AssertColorSame(red, blue);
        AssertColorSame(red, blue, "AssertColorSame()");
        AssertColorSame(red, blue, "AssertColorSame() - %i", 1);
        AssertColorSame(red, blue, "AssertColorSame() - %i, %i", 1, 2);
        AssertColorSame(red, blue, "AssertColorSame() - %i, %i, %i", 1, 2, 3);
        AssertColorSame(red, blue, "AssertColorSame() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertColorApprox()
    {
        Color red = RED;
        Color almostRed = {
            (unsigned char)(red.r > 2 ? red.r - 2 : red.r),
            (unsigned char)(red.g < 254 ? red.g + 1 : red.g),
            (unsigned char)(red.b < 253 ? red.b + 2 : red.b),
            red.a
        };
        Color blue = BLUE;

        SetExpectPass();
        AssertColorApprox(red, almostRed, 8);
        AssertColorApprox(red, almostRed, 8, "AssertColorApprox()");

        SetExpectFail();
        AssertColorApprox(red, blue, 8);
        AssertColorApprox(red, blue, 8, "AssertColorApprox()");
        AssertColorApprox(red, blue, 8, "AssertColorApprox() - %i", 1);
        AssertColorApprox(red, blue, 8, "AssertColorApprox() - %i, %i", 1, 2);
        AssertColorApprox(red, blue, 8, "AssertColorApprox() - %i, %i, %i", 1, 2, 3);
    }

    // AssertImageSame()
    {
        Image image1;
        Image image2 = LoadImage("resources/test-image.png");
        Image image3 = LoadImage("resources/test-image.png");

        SetExpectPass();
        AssertImageSame(image2, image3);
        AssertImageSame(image2, image3, "AssertImageSame()");

        SetExpectFail();
        AssertImageSame(image1, image2, "AssertImageSame()");

        UnloadImage(image2);
        UnloadImage(image3);
    }

    // AssertVector2Same()
    {
        Vector2 vector1 = {5, 10};
        Vector2 vector2 = {5, 10};
        Vector2 vector3 = {2, 1};

        SetExpectPass();
        AssertVector2Same(vector1, vector2);
        AssertVector2Same(vector1, vector2, "AssertVector2Same()");

        SetExpectFail();
        AssertVector2Same(vector1, vector3, "AssertVector2Same()");
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - %i", 1);
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - %i, %i", 1, 2);
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - %i, %i, %i", 1, 2, 3);
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertVector3Same()
    {
        Vector3 vector1 = {5, 10, 15};
        Vector3 vector2 = {5, 10, 15};
        Vector3 vector3 = {2, 1, 5};

        SetExpectPass();
        AssertVector3Same(vector1, vector2);
        AssertVector3Same(vector1, vector2, "AssertVector3Same()");

        SetExpectFail();
        AssertVector3Same(vector1, vector3, "AssertVector3Same()");
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - %i", 1);
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - %i, %i", 1, 2);
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - %i, %i, %i", 1, 2, 3);
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertVector4Same()
    {
        Vector4 vector1 = {5, 10, 15, 20};
        Vector4 vector2 = {5, 10, 15, 20};
        Vector4 vector3 = {2, 1, 5, 9};

        SetExpectPass();
        AssertVector4Same(vector1, vector2);
        AssertVector4Same(vector1, vector2, "AssertVector4Same()");

        SetExpectFail();
        AssertVector4Same(vector1, vector3, "AssertVector4Same()");
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - %i", 1);
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - %i, %i", 1, 2);
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - %i, %i, %i", 1, 2, 3);
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertRectangleSame()
    {
        Rectangle rect1 = {0, 0, 100, 200};
        Rectangle rect2 = {0, 0, 100, 200};
        Rectangle rect3 = {5, 10, 50, 75};

        SetExpectPass();
        AssertRectangleSame(rect1, rect2);
        AssertRectangleSame(rect1, rect2, "AssertRectangleSame()");

        SetExpectFail();
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame()");
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - %i", 1);
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - %i, %i", 1, 2);
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - %i, %i, %i", 1, 2, 3);
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertNull()
    {
        int x = 0;
        int* null_ptr = NULL;
        int* non_null_ptr = &x;

        SetExpectPass();
        AssertNull(null_ptr);
        AssertNull(null_ptr, "AssertNull()");
        AssertNull(null_ptr, "AssertNull() - %i", 1);
        AssertNull(null_ptr, "AssertNull() - %i, %i", 1, 2);
        AssertNull(null_ptr, "AssertNull() - %i, %i, %i", 1, 2, 3);
        AssertNull(null_ptr, "AssertNull() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertNull(non_null_ptr);
        AssertNull(non_null_ptr, "AssertNull()");
        AssertNull(non_null_ptr, "AssertNull() - %i", 1);
        AssertNull(non_null_ptr, "AssertNull() - %i, %i", 1, 2);
        AssertNull(non_null_ptr, "AssertNull() - %i, %i, %i", 1, 2, 3);
        AssertNull(non_null_ptr, "AssertNull() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertNotNull()
    {
        int x = 0;
        int* non_null_ptr = &x;
        int* null_ptr = NULL;

        SetExpectPass();
        AssertNotNull(non_null_ptr);
        AssertNotNull(non_null_ptr, "AssertNotNull()");
        AssertNotNull(non_null_ptr, "AssertNotNull() - %i", 1);
        AssertNotNull(non_null_ptr, "AssertNotNull() - %i, %i", 1, 2);
        AssertNotNull(non_null_ptr, "AssertNotNull() - %i, %i, %i", 1, 2, 3);
        AssertNotNull(non_null_ptr, "AssertNotNull() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertNotNull(null_ptr);
        AssertNotNull(null_ptr, "AssertNotNull()");
        AssertNotNull(null_ptr, "AssertNotNull() - %i", 1);
        AssertNotNull(null_ptr, "AssertNotNull() - %i, %i", 1, 2);
        AssertNotNull(null_ptr, "AssertNotNull() - %i, %i, %i", 1, 2, 3);
        AssertNotNull(null_ptr, "AssertNotNull() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertStringEqual()
    {
        SetExpectPass();
        AssertStringEqual("hello", "hello");
        AssertStringEqual("hello", "hello", "AssertStringEqual()");
        AssertStringEqual("hello", "hello", "AssertStringEqual() - %i", 1);
        AssertStringEqual("hello", "hello", "AssertStringEqual() - %i, %i", 1, 2);
        AssertStringEqual("hello", "hello", "AssertStringEqual() - %i, %i, %i", 1, 2, 3);
        AssertStringEqual("hello", "hello", "AssertStringEqual() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertStringEqual("hello", "world");
        AssertStringEqual("hello", "world", "AssertStringEqual()");
        AssertStringEqual("hello", "world", "AssertStringEqual() - %i", 1);
        AssertStringEqual("hello", "world", "AssertStringEqual() - %i, %i", 1, 2);
        AssertStringEqual("hello", "world", "AssertStringEqual() - %i, %i, %i", 1, 2, 3);
        AssertStringEqual("hello", "world", "AssertStringEqual() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertGreater()
    {
        SetExpectPass();
        AssertGreater(10, 5);
        AssertGreater(10, 5, "AssertGreater()");
        AssertGreater(10, 5, "AssertGreater() - %i", 1);
        AssertGreater(10, 5, "AssertGreater() - %i, %i", 1, 2);
        AssertGreater(10, 5, "AssertGreater() - %i, %i, %i", 1, 2, 3);
        AssertGreater(10, 5, "AssertGreater() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertGreater(5, 10);
        AssertGreater(5, 10, "AssertGreater()");
        AssertGreater(5, 10, "AssertGreater() - %i", 1);
        AssertGreater(5, 10, "AssertGreater() - %i, %i", 1, 2);
        AssertGreater(5, 10, "AssertGreater() - %i, %i, %i", 1, 2, 3);
        AssertGreater(5, 10, "AssertGreater() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertLess()
    {
        SetExpectPass();
        AssertLess(5, 10);
        AssertLess(5, 10, "AssertLess()");
        AssertLess(5, 10, "AssertLess() - %i", 1);
        AssertLess(5, 10, "AssertLess() - %i, %i", 1, 2);
        AssertLess(5, 10, "AssertLess() - %i, %i, %i", 1, 2, 3);
        AssertLess(5, 10, "AssertLess() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertLess(10, 5);
        AssertLess(10, 5, "AssertLess()");
        AssertLess(10, 5, "AssertLess() - %i", 1);
        AssertLess(10, 5, "AssertLess() - %i, %i", 1, 2);
        AssertLess(10, 5, "AssertLess() - %i, %i, %i", 1, 2, 3);
        AssertLess(10, 5, "AssertLess() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertGreaterEqual()
    {
        SetExpectPass();
        AssertGreaterEqual(10, 5);
        AssertGreaterEqual(10, 10);
        AssertGreaterEqual(10, 5, "AssertGreaterEqual()");
        AssertGreaterEqual(10, 10, "AssertGreaterEqual() (equal)");
        AssertGreaterEqual(10, 5, "AssertGreaterEqual() - %i", 1);
        AssertGreaterEqual(10, 5, "AssertGreaterEqual() - %i, %i", 1, 2);
        AssertGreaterEqual(10, 5, "AssertGreaterEqual() - %i, %i, %i", 1, 2, 3);
        AssertGreaterEqual(10, 5, "AssertGreaterEqual() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertGreaterEqual(5, 10);
        AssertGreaterEqual(5, 10, "AssertGreaterEqual()");
        AssertGreaterEqual(5, 10, "AssertGreaterEqual() - %i", 1);
        AssertGreaterEqual(5, 10, "AssertGreaterEqual() - %i, %i", 1, 2);
        AssertGreaterEqual(5, 10, "AssertGreaterEqual() - %i, %i, %i", 1, 2, 3);
        AssertGreaterEqual(5, 10, "AssertGreaterEqual() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertLessEqual()
    {
        SetExpectPass();
        AssertLessEqual(5, 10);
        AssertLessEqual(10, 10);
        AssertLessEqual(5, 10, "AssertLessEqual()");
        AssertLessEqual(10, 10, "AssertLessEqual() (equal)");
        AssertLessEqual(5, 10, "AssertLessEqual() - %i", 1);
        AssertLessEqual(5, 10, "AssertLessEqual() - %i, %i", 1, 2);
        AssertLessEqual(5, 10, "AssertLessEqual() - %i, %i, %i", 1, 2, 3);
        AssertLessEqual(5, 10, "AssertLessEqual() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertLessEqual(10, 5);
        AssertLessEqual(10, 5, "AssertLessEqual()");
        AssertLessEqual(10, 5, "AssertLessEqual() - %i", 1);
        AssertLessEqual(10, 5, "AssertLessEqual() - %i, %i", 1, 2);
        AssertLessEqual(10, 5, "AssertLessEqual() - %i, %i, %i", 1, 2, 3);
        AssertLessEqual(10, 5, "AssertLessEqual() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertFloatEqual()
    {
        SetExpectPass();
        AssertFloatEqual(1.0f, 1.0f);
        AssertFloatEqual(1.0f, 1.0f, "AssertFloatEqual()");
        AssertFloatEqual(1.0f, 1.0f, "AssertFloatEqual() - %i", 1);
        AssertFloatEqual(1.0f, 1.0f, "AssertFloatEqual() - %i, %i", 1, 2);
        AssertFloatEqual(1.0f, 1.0f, "AssertFloatEqual() - %i, %i, %i", 1, 2, 3);
        AssertFloatEqual(1.0f, 1.0f, "AssertFloatEqual() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertFloatEqual(1.0f, 2.0f);
        AssertFloatEqual(1.0f, 2.0f, "AssertFloatEqual()");
        AssertFloatEqual(1.0f, 2.0f, "AssertFloatEqual() - %i", 1);
        AssertFloatEqual(1.0f, 2.0f, "AssertFloatEqual() - %i, %i", 1, 2);
        AssertFloatEqual(1.0f, 2.0f, "AssertFloatEqual() - %i, %i, %i", 1, 2, 3);
        AssertFloatEqual(1.0f, 2.0f, "AssertFloatEqual() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertInRange()
    {
        SetExpectPass();
        AssertInRange(5, 1, 10);
        AssertInRange(1, 1, 10);
        AssertInRange(10, 1, 10);
        AssertInRange(5, 1, 10, "AssertInRange()");
        AssertInRange(5, 1, 10, "AssertInRange() - %i", 1);
        AssertInRange(5, 1, 10, "AssertInRange() - %i, %i", 1, 2);
        AssertInRange(5, 1, 10, "AssertInRange() - %i, %i, %i", 1, 2, 3);

        SetExpectFail();
        AssertInRange(0, 1, 10);
        AssertInRange(11, 1, 10);
        AssertInRange(0, 1, 10, "AssertInRange()");
        AssertInRange(0, 1, 10, "AssertInRange() - %i", 1);
        AssertInRange(0, 1, 10, "AssertInRange() - %i, %i", 1, 2);
        AssertInRange(0, 1, 10, "AssertInRange() - %i, %i, %i", 1, 2, 3);
    }

    // AssertStringNotEqual()
    {
        SetExpectPass();
        AssertStringNotEqual("hello", "world");
        AssertStringNotEqual("hello", "world", "AssertStringNotEqual()");
        AssertStringNotEqual("hello", "world", "AssertStringNotEqual() - %i", 1);
        AssertStringNotEqual("hello", "world", "AssertStringNotEqual() - %i, %i", 1, 2);
        AssertStringNotEqual("hello", "world", "AssertStringNotEqual() - %i, %i, %i", 1, 2, 3);
        AssertStringNotEqual("hello", "world", "AssertStringNotEqual() - %i, %i, %i, %i", 1, 2, 3, 4);

        SetExpectFail();
        AssertStringNotEqual("hello", "hello");
        AssertStringNotEqual("hello", "hello", "AssertStringNotEqual()");
        AssertStringNotEqual("hello", "hello", "AssertStringNotEqual() - %i", 1);
        AssertStringNotEqual("hello", "hello", "AssertStringNotEqual() - %i, %i", 1, 2);
        AssertStringNotEqual("hello", "hello", "AssertStringNotEqual() - %i, %i, %i", 1, 2, 3);
        AssertStringNotEqual("hello", "hello", "AssertStringNotEqual() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertTexture()
    {
        Texture2D texture = {0};
        SetExpectFail();
        AssertTexture(texture);
        AssertTexture(texture, "AssertTexture()");
        AssertTexture(texture, "AssertTexture() - %i", 1);
        AssertTexture(texture, "AssertTexture() - %i, %i", 1, 2);
        AssertTexture(texture, "AssertTexture() - %i, %i, %i", 1, 2, 3);
        AssertTexture(texture, "AssertTexture() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertMesh()
    {
        float vertices[9] = {
            0.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f
        };
        Mesh validMesh = {0};
        validMesh.vertexCount = 3;
        validMesh.triangleCount = 1;
        validMesh.vertices = vertices;
        Mesh invalidMesh = {0};

        SetExpectPass();
        AssertMesh(validMesh);
        AssertMesh(validMesh, "AssertMesh()");

        SetExpectFail();
        AssertMesh(invalidMesh);
        AssertMesh(invalidMesh, "AssertMesh()");
        AssertMesh(invalidMesh, "AssertMesh() - %i", 1);
        AssertMesh(invalidMesh, "AssertMesh() - %i, %i", 1, 2);
        AssertMesh(invalidMesh, "AssertMesh() - %i, %i, %i", 1, 2, 3);
        AssertMesh(invalidMesh, "AssertMesh() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertMaterial()
    {
        MaterialMap maps[MATERIAL_MAP_BRDF + 1] = {0};
        Material validMaterial = {0};
        validMaterial.shader.id = 1;
        validMaterial.maps = maps;
        Material invalidMaterial = {0};

        SetExpectPass();
        AssertMaterial(validMaterial);
        AssertMaterial(validMaterial, "AssertMaterial()");

        SetExpectFail();
        AssertMaterial(invalidMaterial);
        AssertMaterial(invalidMaterial, "AssertMaterial()");
        AssertMaterial(invalidMaterial, "AssertMaterial() - %i", 1);
        AssertMaterial(invalidMaterial, "AssertMaterial() - %i, %i", 1, 2);
        AssertMaterial(invalidMaterial, "AssertMaterial() - %i, %i, %i", 1, 2, 3);
        AssertMaterial(invalidMaterial, "AssertMaterial() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertRenderTexture()
    {
        RenderTexture2D target = {0};
        SetExpectFail();
        AssertRenderTexture(target);
        AssertRenderTexture(target, "AssertRenderTexture()");
        AssertRenderTexture(target, "AssertRenderTexture() - %i", 1);
        AssertRenderTexture(target, "AssertRenderTexture() - %i, %i", 1, 2);
        AssertRenderTexture(target, "AssertRenderTexture() - %i, %i, %i", 1, 2, 3);
        AssertRenderTexture(target, "AssertRenderTexture() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertFont()
    {
        Font font = {0};
        SetExpectFail();
        AssertFont(font);
        AssertFont(font, "AssertFont()");
        AssertFont(font, "AssertFont() - %i", 1);
        AssertFont(font, "AssertFont() - %i, %i", 1, 2);
        AssertFont(font, "AssertFont() - %i, %i, %i", 1, 2, 3);
        AssertFont(font, "AssertFont() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertShader()
    {
        Shader shader = {0};
        SetExpectFail();
        AssertShader(shader);
        AssertShader(shader, "AssertShader()");
        AssertShader(shader, "AssertShader() - %i", 1);
        AssertShader(shader, "AssertShader() - %i, %i", 1, 2);
        AssertShader(shader, "AssertShader() - %i, %i, %i", 1, 2, 3);
        AssertShader(shader, "AssertShader() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertModel()
    {
        Model model = {0};
        SetExpectFail();
        AssertModel(model);
        AssertModel(model, "AssertModel()");
        AssertModel(model, "AssertModel() - %i", 1);
        AssertModel(model, "AssertModel() - %i, %i", 1, 2);
        AssertModel(model, "AssertModel() - %i, %i, %i", 1, 2, 3);
        AssertModel(model, "AssertModel() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertModelAnimation()
    {
        Model validModel = {0};
        validModel.skeleton.boneCount = 2;
        ModelAnimation validAnimation = {0};
        validAnimation.boneCount = 2;
        ModelAnimation invalidAnimation = {0};
        invalidAnimation.boneCount = 1;

        SetExpectPass();
        AssertModelAnimation(validModel, validAnimation);
        AssertModelAnimation(validModel, validAnimation, "AssertModelAnimation()");

        SetExpectFail();
        AssertModelAnimation(validModel, invalidAnimation);
        AssertModelAnimation(validModel, invalidAnimation, "AssertModelAnimation()");
        AssertModelAnimation(validModel, invalidAnimation, "AssertModelAnimation() - %i", 1);
        AssertModelAnimation(validModel, invalidAnimation, "AssertModelAnimation() - %i, %i", 1, 2);
        AssertModelAnimation(validModel, invalidAnimation, "AssertModelAnimation() - %i, %i, %i", 1, 2, 3);
        AssertModelAnimation(validModel, invalidAnimation, "AssertModelAnimation() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertWave()
    {
        Wave wave = {0};
        SetExpectFail();
        AssertWave(wave);
        AssertWave(wave, "AssertWave()");
        AssertWave(wave, "AssertWave() - %i", 1);
        AssertWave(wave, "AssertWave() - %i, %i", 1, 2);
        AssertWave(wave, "AssertWave() - %i, %i, %i", 1, 2, 3);
        AssertWave(wave, "AssertWave() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertSound()
    {
        Sound sound = {0};
        SetExpectFail();
        AssertSound(sound);
        AssertSound(sound, "AssertSound()");
        AssertSound(sound, "AssertSound() - %i", 1);
        AssertSound(sound, "AssertSound() - %i, %i", 1, 2);
        AssertSound(sound, "AssertSound() - %i, %i, %i", 1, 2, 3);
        AssertSound(sound, "AssertSound() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertMusic()
    {
        Music music = {0};
        SetExpectFail();
        AssertMusic(music);
        AssertMusic(music, "AssertMusic()");
        AssertMusic(music, "AssertMusic() - %i", 1);
        AssertMusic(music, "AssertMusic() - %i, %i", 1, 2);
        AssertMusic(music, "AssertMusic() - %i, %i, %i", 1, 2, 3);
        AssertMusic(music, "AssertMusic() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertAudioStream()
    {
        AudioStream stream = {0};
        SetExpectFail();
        AssertAudioStream(stream);
        AssertAudioStream(stream, "AssertAudioStream()");
        AssertAudioStream(stream, "AssertAudioStream() - %i", 1);
        AssertAudioStream(stream, "AssertAudioStream() - %i, %i", 1, 2);
        AssertAudioStream(stream, "AssertAudioStream() - %i, %i, %i", 1, 2, 3);
        AssertAudioStream(stream, "AssertAudioStream() - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // Validate the final section before returning.
    TestValidateSection();

    if (testRegressions > 0) {
        TraceLog(LOG_ERROR, "Test failed: %i regression(s) detected", testRegressions);
        return 1;
    }

    return 0;
}
