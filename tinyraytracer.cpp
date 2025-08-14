#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"

void render() {
    const int width    = 1024;
    const int height   = 768;
    std::vector<Vec3f> framebuffer(width*height); //The framebuffer is a 1-d array of RGB values, represented by Vec3f. This 1-d array gives us the color of each pixel. 

    for (size_t j = 0; j<height; j++) {
        for (size_t i = 0; i<width; i++) {
            framebuffer[i+j*width] = Vec3f(j/float(height),i/float(width), 0); 
            //Blurb 1  
            //if (j==0){
            //    std::cout<<"FB["<<i+j*width<<"]=Vec3f("<<j/float(height)<<","<<i/float(width)<<",0)";
            //}
            //If you want to check what the framebuffer array is saving, The above commented out section gives all the RGB values for the first row 
            
        }
    }

    std::ofstream ofs; // save the framebuffer to file
    ofs.open("./out.ppm", std::ofstream::out | std::ofstream::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height*width; ++i) {
        for (size_t j = 0; j<3; j++) {
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

int main() {
    render();

    //In order to prevent the console from exiting after running your exe file, enter the two lines below. This portion was written to check Blurb 1 
    //printf("Press Enter to exit\n");
    //getchar();

    return 0;
}

/*Only render is called in the main() function
Geometry.h contains the addition, subtraction, assignment, multiplication by a scalar, scalar product of 2-d and 3-d vectors*/

