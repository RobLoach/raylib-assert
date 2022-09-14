#include "raylib.h"

#define RAYLIB_ASSERT_LOG LOG_INFO
// #define NDEBUG
#include "raylib-assert.h"

int main(void)
{
    // Assert(1)
    TraceLog(LOG_INFO, "Assert(1) - Expected Passes");
    Assert(1);
    Assert(1, "Expected Pass");
    Assert(1, "Expected Pass - %i", 1);
    Assert(1, "Expected Pass - %i, %i", 1, 2);
    Assert(1, "Expected Pass - %i, %i, %i", 1, 2, 3);
    Assert(1, "Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
    Assert(1, "Expected Pass - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // Assert(0)
    TraceLog(LOG_INFO, "Assert(0) - Expected Fails");
    Assert(0);
    Assert(0, "Expected Fail");
    Assert(0, "Expected Fail - %i", 1);
    Assert(0, "Expected Fail - %i, %i", 1, 2);
    Assert(0, "Expected Fail - %i, %i, %i", 1, 2, 3);
    Assert(0, "Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    Assert(0, "Expected Fail - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertEqual(TRUE)
    TraceLog(LOG_INFO, "AssertEqual(1, 1) - Expected Passes");
    AssertEqual(1);
    AssertEqual(1, 1);
    AssertEqual(1, 1, "Expected Pass");
    AssertEqual(1, 1, "Expected Pass - %i", 1);
    AssertEqual(1, 1, "Expected Pass - %i, %i", 1, 2);
    AssertEqual(1, 1, "Expected Pass - %i, %i, %i", 1, 2, 3);
    AssertEqual(1, 1, "Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertEqual(NOT)
    TraceLog(LOG_INFO, "AssertEqual(1, 0) - Expected Fails");
    AssertEqual(0);
    AssertEqual(1, 0);
    AssertEqual(1, 0, "Expected Fail");
    AssertEqual(1, 0, "Expected Fail - %i", 1);
    AssertEqual(1, 0, "Expected Fail - %i, %i", 1, 2);
    AssertEqual(1, 0, "Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertEqual(1, 0, "Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertNotEqual(0)
    TraceLog(LOG_INFO, "AssertNotEqual() - Expected Fails");
    AssertNotEqual(0);
    AssertNotEqual(1);
    AssertNotEqual(1, 1);
    AssertNotEqual(1, 1, "Expected Fail");
    AssertNotEqual(1, 1, "Expected Fail - %i", 1);
    AssertNotEqual(1, 1, "Expected Fail - %i, %i", 1, 2);
    AssertNotEqual(1, 1, "Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertNotEqual(1, 1, "Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);

    // AssertNot(0)
    TraceLog(LOG_INFO, "AssertNot(0) - Expected Passes");
    AssertNot(0);
    AssertNot(0, "Expected Pass");
    AssertNot(0, "Expected Pass - %i", 1);
    AssertNot(0, "Expected Pass - %i, %i", 1, 2);
    AssertNot(0, "Expected Pass - %i, %i, %i", 1, 2, 3);
    AssertNot(0, "Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertNot(0, "Expected Pass - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertNot(1)
    TraceLog(LOG_INFO, "AssertNot(1) - Expected Fails");
    AssertNot(1);
    AssertNot(1, "Expected Fail");
    AssertNot(1, "Expected Fail - %i", 1);
    AssertNot(1, "Expected Fail - %i, %i", 1, 2);
    AssertNot(1, "Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertNot(1, "Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertNot(1, "Expected Fail - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);

    // AssertFail()
    TraceLog(LOG_INFO, "AssertFail() - Expected Fail");
    AssertFail("Expected Fail");
    AssertFail("Expected Fail - %i", 1);
    AssertFail("Expected Fail - %i, %i", 1, 2);
    AssertFail("Expected Fail - %i, %i, %i", 1, 2, 3);
    AssertFail("Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    AssertFail("Expected Fail - %i, %i, %i, %i, %i", 1, 2, 3, 4, 5);
    AssertFail("Expected Fail - %i, %i, %i, %i, %i, %i", 1, 2, 3, 4, 5, 6);

    // AssertBreakpoint()
    TraceLog(LOG_INFO, "AssertBreakpoint - Expect Break");
    AssertBreakpoint();

    // AssertImage()
    Image image = LoadImage("NotFound.png");
    AssertImage(image);
    AssertImage(image, "This image is not found!");
    AssertImage(image, "This image is not found! %i", 1);
    AssertImage(image, "This image is not found! %i, %i", 1, 2);
    AssertImage(image, "This image is not found! %i, %i, %i", 1, 2, 3);
    AssertImage(image, "This image is not found! %i, %i, %i, %i", 1, 2, 3, 4);

    return 0;
}
