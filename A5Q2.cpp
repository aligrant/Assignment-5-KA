/*
A landscaping company has a crew of co-op students who do both paving and (sometimes) fencing. The company
charges $ 19.50 for paving each square metre, or any part of a square metre, (i.e. 2.1 becomes 3 sq. m) and $27.00 per
metre, or any part of a metre, for fencing. (Hint: There is a C++ function called ceil that rounds towards +8.) All fences
also have a $150.00 gate. Added to each bill is a $45.00 administration fee. HST is 13%.
The sales representative for the company has created a file called “Sep_jobs2023.txt” that contains the jobs completed
by the work crew for the month of September. Each line of the file contains the following information:
? Job number
? Fencing Job? (indicating whether fencing has been done as well as paving)
? Shape (indicating the shape of the area paved/fenced)
? Dimensions (varying number of distances depending on the shape)
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
//perim tri A function that receives three side lengths of a triangle and returns the perimeter.
float getTriPeri(float side1, float side2, float side3)
{ 
  float tri_peri = side1 + side2 + side3;
  return tri_peri;
}
// AreA TRI Function that recieves 3 side lengths and returns area
float getTriArea(float side1, float side2, float side3)
{
  //Added this float and removed parameter peri
  float peri=getTriPeri(side1,side2,side3);
  float s_peri = peri/2;
  float tri_area = sqrt((s_peri*(s_peri-side1))*(s_peri-side2)*(s_peri - side3));
  return tri_area;
}
//Gets perimeter of a quadrilateral
float getQuadPeri(float side1, float side2, float side3, float side4) 
{
  float quad_peri = side1 + side2 + side3 + side4;
  return quad_peri;
}
//Gets Area of a Quadrilateral
float getQuadArea(float side1, float side2, float diagonal, float side3, float side4) // must use getTriArea
{
  float triArea = getTriArea(side1, side2, side3);
  float QuadArea;
}
float getTotalCost(float area, float peri, float fence) // finds total cost, area and perimeter are just starting variables, will declare in base code
{
	float f_or_no;
  float pave_cost = area * 19.50;
  float fence_cost = peri * 27;
  if (fence == 1) // whether fence is there or not, costs 150, shoudlve probably used boolean but I hate those
    {
      f_or_no = 150;
        }
  else
    { 
      f_or_no = 0;
        }
  float admin_cost = 45;
  float sub_total = admin_cost + f_or_no + pave_cost + fence_cost;
  float total_tax = sub_total*0.13;
  float grand_total = sub_total + total_tax;
}

using namespace std;

int main()
{
  ifstream FileIn("Sep_jobs2023.txt");
  if (!FileIn)
{
  cout << "Unable to open file.\n";
  return EXIT_FAILURE;
}
int job_no = 1;
int fence_y_n = 0;
string q_or_tri = "";
 
while (find out how many jobs // loop it so it reads until there are no other jobs to complete
 FileIn >> job_no >> fence_y_n >> q_or_tri
  if (q_or_tri == "tri")
    {
      int side1 = side2 = side3 = 0;
      FileIn >> job_no >> fence_y_n >> q_or_tri >> side1 >> side2 >> side3;
      getTriPeri(side1, side2, side3);
      getTriArea(side1, side2, side3);
      area = getTriArea(side1, side2, side3);
      peri =  getTriPeri(side1, side2, side3);
      int fence = fence_y_n;
      getTotalCost(area, peri, fence);
    }
  else 
    {
        
  return EXIT_SUCCESS;
}


