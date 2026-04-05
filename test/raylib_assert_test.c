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
    AssertNotEqual(1, 0);
    AssertNotEqual(1, 0, "AssertNotEqual() - Expected Pass");
    AssertNotEqual(1, 0, "AssertNotEqual() - Expected Pass - %i", 1);
    AssertNotEqual(1, 0, "AssertNotEqual() - Expected Pass - %i, %i", 1, 2);
    AssertNotEqual(1, 0, "AssertNotEqual() - Expected Pass - %i, %i, %i", 1, 2, 3);
    AssertNotEqual(1, 0, "AssertNotEqual() - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
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
    Image validImage = LoadImage("resources/test-image.png");
    AssertImage(validImage);
    AssertImage(validImage, "AssertImage() - Expected Pass");
    AssertImage(validImage, "AssertImage() - Expected Pass - %i", 1);
    AssertImage(validImage, "AssertImage() - Expected Pass - %i, %i", 1, 2);
    AssertImage(validImage, "AssertImage() - Expected Pass - %i, %i, %i", 1, 2, 3);
    AssertImage(validImage, "AssertImage() - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
    UnloadImage(validImage);
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
        AssertColorSame(red, blue, "AssertColorSame() - Expected Fail - %i", 1);
        AssertColorSame(red, blue, "AssertColorSame() - Expected Fail - %i, %i", 1, 2);
        AssertColorSame(red, blue, "AssertColorSame() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertColorSame(red, blue, "AssertColorSame() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertImageSame()
    TraceLog(LOG_INFO, "AssertImageSame()");
    {
        Image image2 = LoadImage("resources/test-image.png");
        Image image3 = LoadImage("resources/test-image.png");
        AssertImageSame(image2, image3);
        AssertImageSame(image2, image3, "AssertImageSame() - Expected Pass");
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
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - Expected Failure - %i", 1);
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - Expected Failure - %i, %i", 1, 2);
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - Expected Failure - %i, %i, %i", 1, 2, 3);
        AssertVector2Same(vector1, vector3, "AssertVector2Same() - Expected Failure - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertVector3Same()
    {
        TraceLog(LOG_INFO, "AssertVector3Same()");
        Vector3 vector1 = {5, 10, 15};
        Vector3 vector2 = {5, 10, 15};
        Vector3 vector3 = {2, 1, 5};
        AssertVector3Same(vector1, vector2);
        AssertVector3Same(vector1, vector2, "AssertVector3Same() - Expected Pass");
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - Expected Failure");
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - Expected Failure - %i", 1);
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - Expected Failure - %i, %i", 1, 2);
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - Expected Failure - %i, %i, %i", 1, 2, 3);
        AssertVector3Same(vector1, vector3, "AssertVector3Same() - Expected Failure - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertVector4Same()
    {
        TraceLog(LOG_INFO, "AssertVector4Same()");
        Vector4 vector1 = {5, 10, 15, 20};
        Vector4 vector2 = {5, 10, 15, 20};
        Vector4 vector3 = {2, 1, 5, 9};
        AssertVector4Same(vector1, vector2);
        AssertVector4Same(vector1, vector2, "AssertVector4Same() - Expected Pass");
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - Expected Failure");
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - Expected Failure - %i", 1);
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - Expected Failure - %i, %i", 1, 2);
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - Expected Failure - %i, %i, %i", 1, 2, 3);
        AssertVector4Same(vector1, vector3, "AssertVector4Same() - Expected Failure - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertRectangleSame()
    {
        TraceLog(LOG_INFO, "AssertRectangleSame()");
        Rectangle rect1 = {0, 0, 100, 200};
        Rectangle rect2 = {0, 0, 100, 200};
        Rectangle rect3 = {5, 10, 50, 75};
        AssertRectangleSame(rect1, rect2);
        AssertRectangleSame(rect1, rect2, "AssertRectangleSame() - Expected Pass");
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - Expected Failure");
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - Expected Failure - %i", 1);
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - Expected Failure - %i, %i", 1, 2);
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - Expected Failure - %i, %i, %i", 1, 2, 3);
        AssertRectangleSame(rect1, rect3, "AssertRectangleSame() - Expected Failure - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertNull()
    {
        TraceLog(LOG_INFO, "AssertNull()");
        int x = 0;
        int* null_ptr = NULL;
        int* non_null_ptr = &x;
        AssertNull(null_ptr);
        AssertNull(null_ptr, "AssertNull() - Expected Pass");
        AssertNull(null_ptr, "AssertNull() - Expected Pass - %i", 1);
        AssertNull(null_ptr, "AssertNull() - Expected Pass - %i, %i", 1, 2);
        AssertNull(null_ptr, "AssertNull() - Expected Pass - %i, %i, %i", 1, 2, 3);
        AssertNull(null_ptr, "AssertNull() - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
        AssertNull(non_null_ptr);
        AssertNull(non_null_ptr, "AssertNull() - Expected Fail");
        AssertNull(non_null_ptr, "AssertNull() - Expected Fail - %i", 1);
        AssertNull(non_null_ptr, "AssertNull() - Expected Fail - %i, %i", 1, 2);
        AssertNull(non_null_ptr, "AssertNull() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertNull(non_null_ptr, "AssertNull() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertNotNull()
    {
        TraceLog(LOG_INFO, "AssertNotNull()");
        int x = 0;
        int* non_null_ptr = &x;
        int* null_ptr = NULL;
        AssertNotNull(non_null_ptr);
        AssertNotNull(non_null_ptr, "AssertNotNull() - Expected Pass");
        AssertNotNull(non_null_ptr, "AssertNotNull() - Expected Pass - %i", 1);
        AssertNotNull(non_null_ptr, "AssertNotNull() - Expected Pass - %i, %i", 1, 2);
        AssertNotNull(non_null_ptr, "AssertNotNull() - Expected Pass - %i, %i, %i", 1, 2, 3);
        AssertNotNull(non_null_ptr, "AssertNotNull() - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
        AssertNotNull(null_ptr);
        AssertNotNull(null_ptr, "AssertNotNull() - Expected Fail");
        AssertNotNull(null_ptr, "AssertNotNull() - Expected Fail - %i", 1);
        AssertNotNull(null_ptr, "AssertNotNull() - Expected Fail - %i, %i", 1, 2);
        AssertNotNull(null_ptr, "AssertNotNull() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertNotNull(null_ptr, "AssertNotNull() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertStringEqual()
    {
        TraceLog(LOG_INFO, "AssertStringEqual()");
        AssertStringEqual("hello", "hello");
        AssertStringEqual("hello", "hello", "AssertStringEqual() - Expected Pass");
        AssertStringEqual("hello", "hello", "AssertStringEqual() - Expected Pass - %i", 1);
        AssertStringEqual("hello", "hello", "AssertStringEqual() - Expected Pass - %i, %i", 1, 2);
        AssertStringEqual("hello", "hello", "AssertStringEqual() - Expected Pass - %i, %i, %i", 1, 2, 3);
        AssertStringEqual("hello", "hello", "AssertStringEqual() - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
        AssertStringEqual("hello", "world");
        AssertStringEqual("hello", "world", "AssertStringEqual() - Expected Fail");
        AssertStringEqual("hello", "world", "AssertStringEqual() - Expected Fail - %i", 1);
        AssertStringEqual("hello", "world", "AssertStringEqual() - Expected Fail - %i, %i", 1, 2);
        AssertStringEqual("hello", "world", "AssertStringEqual() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertStringEqual("hello", "world", "AssertStringEqual() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertGreater()
    {
        TraceLog(LOG_INFO, "AssertGreater()");
        AssertGreater(10, 5);
        AssertGreater(10, 5, "AssertGreater() - Expected Pass");
        AssertGreater(10, 5, "AssertGreater() - Expected Pass - %i", 1);
        AssertGreater(10, 5, "AssertGreater() - Expected Pass - %i, %i", 1, 2);
        AssertGreater(10, 5, "AssertGreater() - Expected Pass - %i, %i, %i", 1, 2, 3);
        AssertGreater(10, 5, "AssertGreater() - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
        AssertGreater(5, 10);
        AssertGreater(5, 10, "AssertGreater() - Expected Fail");
        AssertGreater(5, 10, "AssertGreater() - Expected Fail - %i", 1);
        AssertGreater(5, 10, "AssertGreater() - Expected Fail - %i, %i", 1, 2);
        AssertGreater(5, 10, "AssertGreater() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertGreater(5, 10, "AssertGreater() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertLess()
    {
        TraceLog(LOG_INFO, "AssertLess()");
        AssertLess(5, 10);
        AssertLess(5, 10, "AssertLess() - Expected Pass");
        AssertLess(5, 10, "AssertLess() - Expected Pass - %i", 1);
        AssertLess(5, 10, "AssertLess() - Expected Pass - %i, %i", 1, 2);
        AssertLess(5, 10, "AssertLess() - Expected Pass - %i, %i, %i", 1, 2, 3);
        AssertLess(5, 10, "AssertLess() - Expected Pass - %i, %i, %i, %i", 1, 2, 3, 4);
        AssertLess(10, 5);
        AssertLess(10, 5, "AssertLess() - Expected Fail");
        AssertLess(10, 5, "AssertLess() - Expected Fail - %i", 1);
        AssertLess(10, 5, "AssertLess() - Expected Fail - %i, %i", 1, 2);
        AssertLess(10, 5, "AssertLess() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertLess(10, 5, "AssertLess() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertTexture()
    {
        TraceLog(LOG_INFO, "AssertTexture()");
        Texture2D texture = {0};
        AssertTexture(texture);
        AssertTexture(texture, "AssertTexture() - Expected Fail");
        AssertTexture(texture, "AssertTexture() - Expected Fail - %i", 1);
        AssertTexture(texture, "AssertTexture() - Expected Fail - %i, %i", 1, 2);
        AssertTexture(texture, "AssertTexture() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertTexture(texture, "AssertTexture() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertRenderTexture()
    {
        TraceLog(LOG_INFO, "AssertRenderTexture()");
        RenderTexture2D target = {0};
        AssertRenderTexture(target);
        AssertRenderTexture(target, "AssertRenderTexture() - Expected Fail");
        AssertRenderTexture(target, "AssertRenderTexture() - Expected Fail - %i", 1);
        AssertRenderTexture(target, "AssertRenderTexture() - Expected Fail - %i, %i", 1, 2);
        AssertRenderTexture(target, "AssertRenderTexture() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertRenderTexture(target, "AssertRenderTexture() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertFont()
    {
        TraceLog(LOG_INFO, "AssertFont()");
        Font font = {0};
        AssertFont(font);
        AssertFont(font, "AssertFont() - Expected Fail");
        AssertFont(font, "AssertFont() - Expected Fail - %i", 1);
        AssertFont(font, "AssertFont() - Expected Fail - %i, %i", 1, 2);
        AssertFont(font, "AssertFont() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertFont(font, "AssertFont() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertShader()
    {
        TraceLog(LOG_INFO, "AssertShader()");
        Shader shader = {0};
        AssertShader(shader);
        AssertShader(shader, "AssertShader() - Expected Fail");
        AssertShader(shader, "AssertShader() - Expected Fail - %i", 1);
        AssertShader(shader, "AssertShader() - Expected Fail - %i, %i", 1, 2);
        AssertShader(shader, "AssertShader() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertShader(shader, "AssertShader() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertModel()
    {
        TraceLog(LOG_INFO, "AssertModel()");
        Model model = {0};
        AssertModel(model);
        AssertModel(model, "AssertModel() - Expected Fail");
        AssertModel(model, "AssertModel() - Expected Fail - %i", 1);
        AssertModel(model, "AssertModel() - Expected Fail - %i, %i", 1, 2);
        AssertModel(model, "AssertModel() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertModel(model, "AssertModel() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertWave()
    {
        TraceLog(LOG_INFO, "AssertWave()");
        Wave wave = {0};
        AssertWave(wave);
        AssertWave(wave, "AssertWave() - Expected Fail");
        AssertWave(wave, "AssertWave() - Expected Fail - %i", 1);
        AssertWave(wave, "AssertWave() - Expected Fail - %i, %i", 1, 2);
        AssertWave(wave, "AssertWave() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertWave(wave, "AssertWave() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertSound()
    {
        TraceLog(LOG_INFO, "AssertSound()");
        Sound sound = {0};
        AssertSound(sound);
        AssertSound(sound, "AssertSound() - Expected Fail");
        AssertSound(sound, "AssertSound() - Expected Fail - %i", 1);
        AssertSound(sound, "AssertSound() - Expected Fail - %i, %i", 1, 2);
        AssertSound(sound, "AssertSound() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertSound(sound, "AssertSound() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertMusic()
    {
        TraceLog(LOG_INFO, "AssertMusic()");
        Music music = {0};
        AssertMusic(music);
        AssertMusic(music, "AssertMusic() - Expected Fail");
        AssertMusic(music, "AssertMusic() - Expected Fail - %i", 1);
        AssertMusic(music, "AssertMusic() - Expected Fail - %i, %i", 1, 2);
        AssertMusic(music, "AssertMusic() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertMusic(music, "AssertMusic() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    // AssertAudioStream()
    {
        TraceLog(LOG_INFO, "AssertAudioStream()");
        AudioStream stream = {0};
        AssertAudioStream(stream);
        AssertAudioStream(stream, "AssertAudioStream() - Expected Fail");
        AssertAudioStream(stream, "AssertAudioStream() - Expected Fail - %i", 1);
        AssertAudioStream(stream, "AssertAudioStream() - Expected Fail - %i, %i", 1, 2);
        AssertAudioStream(stream, "AssertAudioStream() - Expected Fail - %i, %i, %i", 1, 2, 3);
        AssertAudioStream(stream, "AssertAudioStream() - Expected Fail - %i, %i, %i, %i", 1, 2, 3, 4);
    }

    return 0;
}
