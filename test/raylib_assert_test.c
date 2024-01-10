#include "raylib.h"

#define RAYLIB_ASSERT_LOG LOG_WARNING
// #define NDEBUG
#include "raylib-assert.h"

int main(int argc, char *argv[])
{
    // Make sure we're running in the correct directory.
    Assert(argc > 0);
    const char* dir = GetDirectoryPath(argv[0]);
    Assert(ChangeDirectory(dir));

    // Assert(1)
    TraceLog(LOG_INFO, "Assert(1)");
    Assert(1);
    Assert(1, "Assert(1) - Expected Pass");
    Assert(1, "Assert(1) - Expected Pass - %i", 1);
    Assert(1, "Assert(1) - Expected Pass - %i, %i", 1, 2);
    Assert(1, "Assert(1) - Expected Pass - %i, %i, %i", 1, 2, 3);
    Assert(1, "Assert(1) - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
    Assert(1, "Assert(1) - Expected Pass - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // Assert(0)
    TraceLog(LOG_INFO, "Assert(0)");
    Assert(0);
    Assert(0, "Assert(0) - Expected Fail");
    Assert(0, "Assert(0) - Expected Fail - %i", 1);
    Assert(0, "Assert(0) - Expected Fail - %i, %i", 1, 2);
    Assert(0, "Assert(0) - Expected Fail - %i, %i, %i", 1, 2, 3);
    Assert(0, "Assert(0) - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    Assert(0, "Assert(0) - Expected Fail - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertEqual(TRUE)
    TraceLog(LOG_INFO, "AssertEqual(1, 1)");
    AssertEqual(1);
    AssertEqual(1, 1);
    AssertEqual(1, 1, "AssertEqual(1, 1) - Expected Pass");
    AssertEqual(1, 1, "AssertEqual(1, 1) - Expected Pass - %i", 1);
    AssertEqual(1, 1, "AssertEqual(1, 1) - Expected Pass - %i, %i", 1, 2);
    AssertEqual(1, 1, "AssertEqual(1, 1) - Expected Pass - %i, %i, %i", 1, 2, 3);
    AssertEqual(1, 1, "AssertEqual(1, 1) - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertEqual(NOT)
    TraceLog(LOG_INFO, "AssertEqual(1, 0)");
    AssertEqual(0);
    AssertEqual(1, 0);
    AssertEqual(1, 0, "AssertEqual(1, 0) - Expected Fail");
    AssertEqual(1, 0, "AssertEqual(1, 0) - Expected Fail - %i", 1);
    AssertEqual(1, 0, "AssertEqual(1, 0) - Expected Fail - %i, %i", 1, 2);
    AssertEqual(1, 0, "AssertEqual(1, 0) - Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertEqual(1, 0, "AssertEqual(1, 0) - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertNotEqual(0)
    TraceLog(LOG_INFO, "AssertNotEqual()");
    AssertNotEqual(0);
    AssertNotEqual(1);
    AssertNotEqual(1, 1);
    AssertNotEqual(1, 1, "AssertNotEqual() - Expected Fail");
    AssertNotEqual(1, 1, "AssertNotEqual() - Expected Fail - %i", 1);
    AssertNotEqual(1, 1, "AssertNotEqual() - Expected Fail - %i, %i", 1, 2);
    AssertNotEqual(1, 1, "AssertNotEqual() - Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertNotEqual(1, 1, "AssertNotEqual() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertNot(0)
    TraceLog(LOG_INFO, "AssertNot(0)");
    AssertNot(0);
    AssertNot(0, "AssertNot(0) - Expected Pass");
    AssertNot(0, "AssertNot(0) - Expected Pass - %i", 1);
    AssertNot(0, "AssertNot(0) - Expected Pass - %i, %i", 1, 2);
    AssertNot(0, "AssertNot(0) - Expected Pass - %i, %i, %i", 1, 2, 3);
    AssertNot(0, "AssertNot(0) - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertNot(0, "AssertNot(0) - Expected Pass - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertNot(1)
    TraceLog(LOG_INFO, "AssertNot(1)");
    AssertNot(1);
    AssertNot(1, "AssertNot(1) - Expected Fail");
    AssertNot(1, "AssertNot(1) - Expected Fail - %i", 1);
    AssertNot(1, "AssertNot(1) - Expected Fail - %i, %i", 1, 2);
    AssertNot(1, "AssertNot(1) - Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertNot(1, "AssertNot(1) - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertNot(1, "AssertNot(1) - Expected Fail - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertFail()
    TraceLog(LOG_INFO, "AssertFail()");
    AssertFail("AssertFail() - Expected Fail");
    AssertFail("AssertFail() - Expected Fail - %i", 1);
    AssertFail("AssertFail() - Expected Fail - %i, %i", 1, 2);
    AssertFail("AssertFail() - Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertFail("AssertFail() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertFail("AssertFail() - Expected Fail - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);
    AssertFail("AssertFail() - Expected Fail - %i, %i, %i, %i, %i, %i", 1, 2, 3, 4, 5, 6);

    // AssertImage()
    TraceLog(LOG_INFO, "AssertImage()");
    Image image = LoadImage("NotFound.png");
    AssertImage(image);
    AssertImage(image, "AssertImage() - Expected Fail");
    AssertImage(image, "AssertImage() - Expected Fail - %i", 1);
    AssertImage(image, "AssertImage() - Expected Fail - %i, %i", 1, 2);
    AssertImage(image, "AssertImage() - Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertImage(image, "AssertImage() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertColorSame()
    TraceLog(LOG_INFO, "AssertColorSame()");
    {
        Color red = RED;
        Color blue = BLUE;
        Color red2 = RED;
        AssertColorSame(red, red2);
        AssertColorSame(red, red2, "AssertColorSame() - Expected Pass");
        AssertColorSame(red, blue);
        AssertColorSame(red, blue, "AssertColorSame() - Expected Fail");
    }

    // AssertImageSame()
    TraceLog(LOG_INFO, "AssertImageSame()");
    {
        Image image2 = LoadImage("resources/test-image.png");
        Image image3 = LoadImage("resources/test-image.png");
        AssertImageSame(image2, image3);
        AssertImageSame(image2, image3, "AssertImageSame() - Expected Pass");
        AssertImageSame(image, image2);
        AssertImageSame(image, image2, "AssertImageSame() - Expected Failure");
        UnloadImage(image2);
        UnloadImage(image3);
    }

    // AssertVector2Same()
    {
        TraceLog(LOG_INFO, "AssertVector2Same()");
        Vector2 vector1 = {5, 10};
        Vector2 vector2 = {5, 10};
        Vector2 vector3 = {2, 1};
        AssertVector2Same(vector1, vector2);
        AssertVector2Same(vector1, vector2, "AssertVector2Same() - Expected Pass");
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - Expected Failure");
    }

    return 0;
}
