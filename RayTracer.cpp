#include "Precision.h"
#include "Vector3.h"
#include "Camera.h"
#include "Ray.h"
#include "pngwriter.h"
#include <vector>

int main()
{
	//// PARSE COMMAND LINE AND SETUP
	//Camera camera(Vector3(0,0,-5), Vector3(0,1,0), Vector3(1,0,0), 1024, 768, 180, 100);
	//int nx = camera.getNx();
	//int ny = camera.getNy();
	//
	//vector<vector<colour>> image(camera.getNx(), vector<colour>(camera.getNy()));

	//// PARSE INPUT FILE
	//// parseInputFile();


	//// RENDER IMAGE
	//Ray worriedAboutRay();
	//Vector3 rayOrigin = camera.getCameraOrigin();
	//for (int x=0; x<nx; x++)
	//{
	//	for(int y=0; y<ny; y++)
	//	{
	//		Ray worriedAboutRay(rayOrigin , camera.findDirection(x,y));
	//		image.push_back(trace_ray(worriedAboutRay));
	//	}
	//}
	// WRITE IMAGE
	 int i;
   int y;

   pngwriter png(300,300,0,"test.png");
   
   for(i = 1; i < 300;i++)
     {
     	y = 150+100*sin((double)i*9/300.0);
     	
        png.plot(i,y, 0.0, 0.0, 1.0);
     }
     
   png.close();
   
   return 0;
}
