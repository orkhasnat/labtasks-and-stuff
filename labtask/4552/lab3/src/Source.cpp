#include <cstdio>
#include <filesystem>

#include "Box.h"
#include "Sequencer.h"
#include "Util.h"

#define TRANSFORM_NO_ANIMATION 0 // Change the value 1 to 0 when you are doing animation tasks

int main()
{    
    // In the case of Task 1, change the Translation, Rotation, Scale or Color values below to see the effect
    Box box{
        { Point{-5.0, 5.0}, Point{5.0, 5.0}, Point{5.0, -5.0}, Point{-5.0, -5.0} }, // Vertex Positions
        { 250.0, 250.0 }, // Translation
        DegreesToRadians(80.0), // Rotation
        { 20.0, 20.0 }, // Scale
        Color{255, 0, 0} // Color
    };

#if TRANSFORM_NO_ANIMATION

    Image image{ 512, 512, Color{233, 233, 233} };
    box.Draw(image);
    std::puts("Written image to './Box.png'");
    image.Write("./Box.png");

#else

    //----------------------------------------        TASK 2        ----------------------------------------
    /* ToDo: Use a linearly interpolating sequencer to create a simple animation by keyframing Translation,
     * Rotation, Scale and Color values. All the calculations are done in frame space, that means frame count
     * is used instead of time. There will be 24 frames in one second of the video. So calculate accordingly.
     * The instructions for creating the keyframe will be provided by the instructor in the lab. The sequencer
     * overwrites the transformation of the box based on a specific frame.
     * 
     * The API calls for the sequencer is listed below.
     * 
     * A) Translation:
     *                  boxSequencer.SetTranslationKey(0.0, { 20, 20 }); // Frame, {dx, dy}
     * 
     * B) Rotation:
     *                  boxSequencer.SetRotationKey(0.0, DegreesToRadians(0.0)); // Frame, Rotation in Radians
     * 
     * C) Scale:
     *                  boxSequencer.SetScaleKey(0.0, { 1.0, 1.0 }); // Frame, {Sx, Sy}
     * 
     * D) Color:
     *                  boxSequencer.SetColorKey(0.0, { 255, 0, 0 }); // Frame, {R, G, B}
     * 
     * Once you are done keyframing via sequencer, if you did not entered one type of keys in sorted order, run:
     * 
     *                   boxSequencer.SortAllKeys();
     * 
     * In short, to be safe, after setting the keyframes, just call the SortAllKeys() method.
     * Also, update the 'frameEnd' value to render frame sequence up to last one of your keyframes.
     * Once you are done producing the render sequence, you can find the images inside './outFrames' folder.
     * You can combine them into a video in a lot of ways, one such way would be to use the commandline
     * tool ffmpeg. After you are done with all these, if you fancy, go through the code of the Sequencer in
     * "Sequencer.h" and "Sequencer.cpp".
     */

    Sequencer boxSequencer{ box };

    //---------------------------------------- INSERT TRANSLATION SEQUENCE CODE HERE ----------------------------------------
    boxSequencer.SetTranslationKey(0.0, { 20, 20 });
    boxSequencer.SetTranslationKey(12.0, { 150, 200 });
    boxSequencer.SetTranslationKey(24.0, { 300, 20 });


    //---------------------------------------- INSERT ROTATION SEQUENCE CODE HERE ----------------------------------------
    boxSequencer.SetRotationKey(0.0, DegreesToRadians(0.0));
    boxSequencer.SetRotationKey(6.0, DegreesToRadians(45.0));
    boxSequencer.SetRotationKey(12.0, DegreesToRadians(0.0));
    boxSequencer.SetRotationKey(18.0, DegreesToRadians(135.0));
    boxSequencer.SetRotationKey(24.0, DegreesToRadians(0.0));

  

    //---------------------------------------- INSERT SCALE SEQUENCE CODE HERE ----------------------------------------
    boxSequencer.SetScaleKey(0.0, { 2.0, 4.0 });
    boxSequencer.SetScaleKey(12.0, { 5.0, 4.5 });
    boxSequencer.SetScaleKey(24.0, { 2.0, 4.0 });



    //---------------------------------------- INSERT COLOR SEQUENCE CODE HERE ----------------------------------------
    boxSequencer.SetColorKey(0.0, { 255, 147, 58 });
    boxSequencer.SetColorKey(12.0, { 25, 147, 58 });
    

    boxSequencer.SortAllKeys();

    double frameStart = 0.0;
    double frameEnd = 25.0; // Update this value to match your final frame count
    double frameIncrement = 1.0;

    std::filesystem::create_directory("./outFrames");
    for (double frame = frameStart; frame <= frameEnd; frame += frameIncrement)
    {
        double percentage = ((frame - frameStart) / (frameEnd - frameStart)) * 100.0;
        std::printf("Rendering Frame [%.2f/%.2f], Completed: %.2f%%\r", frame, frameEnd, percentage);

        Image canvas{ 512, 512 };
        boxSequencer.SetCurrentFrame(frame);
        std::string savePath = "./outFrames/box" + std::to_string(static_cast<int>(frame)) + ".png";
        boxSequencer.Draw(canvas);
        canvas.Write(savePath);
    }
    std::printf("\nCompleted writing all the frames.\n");

#endif // TRANSFORM_NO_ANIMATION

    return 0;
}