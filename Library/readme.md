# F1TS library

Here you will find the .lib, the .dll and the main .h file. With only this three things you can
use the library.

In any cases you will first need to move the F1TS_Externs.h file to your project.

Next, you will need to move and include the .lib of the platform that your are using and your configuration to 
your project.

Finally, move the .dll to the working directory of your project

##### Organization

---

I recomend you to create a /dependecies/ folder and in that folder have a /include/ with the .lib and
a /build/ with the .h for a better organization. The dll will need to go to the working directory
in any cases.