This is an example C++ library for Arduino , based on one created by 
A.Reha Salmaner for RGB LED with 4 legs

DNA Tech. & Cons. Ltd.Sti. 
Ankara/Turkey

Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries folder.

When installed, this library should look like:

Arduino/lib/targets/libraries/RGB_LED              (this library's folder)
Arduino/lib/targets/libraries/RGB_LED/src/RGB_LED.cpp     (the library implementation file)
Arduino/lib/targets/libraries/RGB_LED//src/RGB_LED.h       (the library description file)
Arduino/lib/targets/libraries/RGB_LED/keywords.txt (the syntax coloring file)
Arduino/lib/targets/libraries/RGB_LED/examples     (the examples in the "open" menu)
Arduino/lib/targets/libraries/RGB_LED/readme.md   (this file)
Arduino/lib/targets/libraries/RGB_LED/library.properties   (this file)

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select Test.  This will add a corresponding line to the top of your sketch:
#include <RGB_LED.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "RGB_LED.o" will appear
in "Arduino/lib/targets/libraries/RGB_LED". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "RGB_LED.cpp" or "RGB_LED.h"),
then you must first 'unbuild' this library by deleting the "RGB_LED.o" file. The
new "RGB_LED.o" with your code will appear after the next press of "verify"

