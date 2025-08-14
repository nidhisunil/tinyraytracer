This Ray tracer is my own implementation following the guide by https://github.com/ssloy/tinyraytracer. CMake builds were difficult for me to execute, so if you're following his tutorial, then at the bottom of this Readme, I have listed the exact steps I followed to make his code work

To run my repo, follow these steps: 
->Download Cmake
->Download VSCode with C++ option ticked
->Download GIMP https://www.gimp.org/
->Open the Developer Command Prompt for VS Code (you can search the start bar for this)
->mkdir Graphics (this will hold all your files. You might have to navigate to C://Users/<yourName> before doing this.)
->cd Graphics 
->git clone <this repo>
->(optional)git checkout <commit you want to go to.>
->cd tinyraytracer
->cmake -B build
->cmake --build build
->This should give you a path to a .exe file. Double click that, and it should create out.ppm in the same location. 





If you want to follow SSOL's guide directly and make sure Step 1 from https://github.com/ssloy/tinyraytracer/wiki/Part-1:-understandable-raytracing is working:
->Download Cmake
->Download VSCode with C++ option ticked
->Download GIMP https://www.gimp.org/
->Open the Developer Command Prompt for VS Code (you can search the start bar for this)
->mkdir Graphics (this will hold all your files. You might have to navigate to C://Users/<yourName> before doing this.)
->cd Graphics 
->git clone https://github.com/ssloy/tinyraytracer.git  
->git checkout bd36c98 (this is the ID of the first commit of the tinyraytracer repo by ssol. This commit will help us with the initial setup and make sure we are able to write images to a file)
->cd tinyraytracer
->Open your code in any IDE, and make all the changes from this pull request: https://github.com/ssloy/tinyraytracer/pull/32/commits/9ccbbff0d7ca153fde81a57c5b991e999ba75dcf
->Save the files
->cmake -B build
->cmake --build build
->This should give you a path to a .exe file. Double click that, and it should create out.ppm in the same location. 







