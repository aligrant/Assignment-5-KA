/*
Koustav Bhasin and Alessandra Grant
Note: If a yard is fenced it is assumed that the entire perimeter,
overlapping the gate is also fenced.
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
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
	float triArea1 = getTriArea(side1, side2, diagonal);
	float triArea2 = getTriArea(side3, side4, diagonal);
	//area / (0.5*base ) is the height of a triangle
	float QuadArea = 0.5*diagonal*((triArea1/(0.5*side1))+(triArea2/(0.5*side3)));
}

void printCost(float area, float peri, bool fence)
{
	//ceiiling area first
	float pave_cost = ceil(area)*19.50;
	//ceiling perim firs
	float fence_cost = (ceil(peri)*27*fence)+(150*fence);
	int admin_cost = 45;
	float sub_total = admin_cost + pave_cost + fence_cost;
	float total_tax = sub_total*0.13;
	float grand_total = sub_total + total_tax;
	/*prints the cost of everything but also actual fence length
	because of assignment requirement*/
	cout<<setprecision(2)<<fixed<<setw(9)<<pave_cost<<setw(18)<<(peri*fence)<<setw(10)<<fence_cost;
	cout<<setw(8)<<total_tax<<setw(10)<<grand_total<<endl;
	return;
}

int main()
{
	ifstream FileIn("Sep_jobs2023.txt");
	if (!FileIn)
		{
			cout << "Unable to open file.\n";
			return EXIT_FAILURE;
		}
	int job_no = 0;
	bool fence_y_n = 0;
	string q_or_tri = "";
	float area=0;
	float peri=0;
	float totalCost=0;
	float side1 = 0, side2 = 0, diagonal=0,side3 = 0, side4 = 0;

	cout<<" Job#"<<setw(6)<<"Fence";
	cout<<setw(16)<<"ActualPavedArea"<<setw(9)<<"PaveCost"<<setw(18);
	cout<<"ActualFenceLength"<<setw(10)<<"FenceCost";
	cout<<setw(7)<<"Taxes"<<setw(11)<<"TotalCost"<<endl;

	while (FileIn>>job_no)
		{
// loop it so it reads until there are no other jobs to complete
			FileIn >> fence_y_n >> q_or_tri;
//if triangle
			if (q_or_tri == "tri")
				{
					FileIn>>side1>>side2>>side3;
					area = getTriArea(side1, side2, side3);
					peri = getTriPeri(side1, side2, side3);
				}
			else if(q_or_tri == "quad")
				{
					FileIn>>side1>>side2>>diagonal>>side3>>side4;
					area = getQuadArea(side1, side2, diagonal,side3,side4);
					peri = getQuadPeri(side1, side2, side3, side4);
				}
			else
				{
					cout<<"Error reading file. No shape detected.";
				}
			//print in table
			cout<<job_no<<setw(7)<<fence_y_n<<setw(16)<<area;
			printCost(area, peri, fence_y_n);

		}

	return EXIT_SUCCESS;
}
/*
Job#  Fence ActualPavedArea PaveCost ActualFenceLength FenceCost  Taxes  TotalCost
7100      1         290.474  5674.50             90.00   2580.00 1078.94   9378.44
7101      1           22.64   448.50             16.00    582.00  139.82   1215.31
7102      0          884.00 17238.00              0.00      0.00 2246.79  19529.79
7103      0           89.68  1755.00              0.00      0.00  234.00   2034.00
7104      0         3191.05 62244.00              0.00      0.00 8097.57  70386.57
7105      1          582.81 11368.50             81.20   2364.00 1791.07  15568.58
7106      0           10.10   214.50              0.00      0.00   33.74    293.23
7107      1            8.77   175.50             13.50    528.00   97.31    845.80
7108      1          117.12  2301.00             36.40   1149.00  454.35   3949.35

--------------------------------
Process exited after 0.08778 seconds with return value 0
Press any key to continue . . .
*/
