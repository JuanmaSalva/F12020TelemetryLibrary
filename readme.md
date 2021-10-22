#F1TS 2020

Welcome to F1TS (F1 Telemetry System), the open source telemetry system for the
formula 1 2020 game made by Codemasters.

In this repository yo will find a library that is capable of extracting all possible data from the ingame telemetry system. This does not use exploits or any "legal" system of extracting data.

You have 3 options when using this library:
* <strong>Incluide the library</strong> to your project and use it freely. (/Library/)
* <strong>Get the source code</strong>, import it to your own project and use it/modify it as you wish. (/SourceCode/)
* <strong>Use my visual studio project</strong> and start from there. (/VisualStudioProject/)

###Still in progress!!
This is not a beta, this isn't even a alpha! It's lower than that. There are hundreds of methods and
testing each and every one with the game takes time, a lot of it. This should work but there will be 
bug for sure. If you find one, let me know and y will fix it.

In every directory there is another .md that will showw you how to use it.

###How to use
For any of the three options to use this code, the use of the library is the same.
To start the telemetry system you will need to call F1TS_startF1Telemetry or F1Ts_startF1TelemetryThread.
I recomend you to use the second one, is easier to use. It will create a thread and run on the background 
reading the UDP pakets that the game sends. 
If you dont want the code to create it's own thread, you can call F1TS_startF1Telemetry but this method
will block your program. You will need to create a thread.

Once the telemetry is started, you can use all the hundreds of methods available.

IMPORTANT: this library will open a localhost port, it is VERRY important to call the close method (F1TS_closeF1Telemetry()),
if this method is never called, the local port will remain open.
I do not take any responsibilities for any side effects the library may have on your device.
If the library is correctly used, there is no need to worry, only tons of telemetry information that you can extract
from the game ^_^


####Aditional info
If you use any of this code give me a mention  ＜（＾－＾）＞