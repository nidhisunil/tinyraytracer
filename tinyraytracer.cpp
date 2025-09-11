#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#define M_PI   3.14159265358979323846264338327950288
#include "geometry.h"

struct Sphere{

    Vec3f center;
    float radius;

    Sphere(const Vec3f &c, const float &r) : center(c), radius(r) {} //default constructor, you can now use "center" and "radius"

    //function to check for ray intersections with this sphere
    bool ray_intersect(const Vec3f &orig, const Vec3f &dir, float &t0) const { //the final const guarantees that calling this function won't change any of the member variables (the data) of the class instance
        Vec3f L = center - orig;
        float tca = L*dir;
        float d2 = L*L - tca*tca;
        if (d2 > radius*radius) return false;
        float thc = sqrtf(radius*radius - d2);
        t0 = tca-thc;
        float t1 = tca+thc;
        if (t0<0) t0=t1;
        if (t0<0) return false;
        return true;
    }
};

//function to cast a ray and return respective bg color based on whether it intersects the sphere
Vec3f cast_ray(const Vec3f &orig, const Vec3f &dir, const Sphere &sphere){
    float sphere_dist = std::numeric_limits<float>::max();
    if (!sphere.ray_intersect(orig,dir,sphere_dist)){
        return Vec3f(0.2, 0.7, 0.8);
    }
    return Vec3f(0.4, 0.4, 0.3);
}

void render(const Sphere &sphere) {
    const int width    = 1024;
    const int height   = 768;
    const int fov = M_PI/2.;
    std::vector<Vec3f> framebuffer(width*height); //The framebuffer is a 1-d array of RGB values, represented by Vec3f. This 1-d array gives us the color of each pixel. 

    for (size_t j = 0; j<height; j++) {
        for (size_t i = 0; i<width; i++) {
            
            //Blurb 1  
            //if (j==0){
            //    std::cout<<"FB["<<i+j*width<<"]=Vec3f("<<j/float(height)<<","<<i/float(width)<<",0)";
            //}
            //If you want to check what the framebuffer array is saving, The above commented out section gives all the RGB values for the first row 
            //Blurb 2 Testing dot product of two vectors
            //Vec3f a = Vec3f(3,7,2);
            //Vec3f b = Vec3f(9,4,1);
            //float dotProduct = a*b;
            //std::cout<<dotProduct;
            float x =  (2*(i + 0.5)/(float)width  - 1)*tan(fov/2.)*width/(float)height;
            float y = -(2*(j + 0.5)/(float)height - 1)*tan(fov/2.);
            Vec3f dir = Vec3f(x, y, -1).normalize();
            framebuffer[i+j*width] = cast_ray(Vec3f(0,0,0), dir, sphere);


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
    Sphere sphere(Vec3f(-3, 0, -16), 2);
    render(sphere);

    //In order to prevent the console from exiting after running your exe file, enter the two lines below. This portion was written to check Blurb 1 
    //printf("Press Enter to exit\n");
    //getchar();

    return 0;
}

/*Only render is called in the main() function
Geometry.h contains the addition, subtraction, assignment, multiplication by a scalar, scalar product of 2-d and 3-d vectors*/

