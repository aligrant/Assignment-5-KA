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
int getTriPeri(int side1, int side2, int side3)
{ 
  int tri_peri = side1 + side2 + side3;
  return;
}
float getTriArea(int side1, int side2, int side3, int peri)
{
  s_peri = peri/2;
  float tri_area = sqrt((s_peri*(s_peri-side1)) * (s_peri-side2) * (s_peri - side3));
  return;
}
float getQuadPeri(int side1, int side2, int side3, int side4)
{
  float quad_peri = side1 + side2 + side3 + side4;
  return;
}
float getQuadArea(int side1, int side2) // must use getTriArea
{
  float QuadArea = 
}
using namespace std;

int main()
{
  ifstream FileIn("Sep_jobs2023.txt")
  if (!FileIn)
{
  cout << "Unable to open file.\n";
  return EXIT_FAILURE;
}


