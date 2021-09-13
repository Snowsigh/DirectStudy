#include "VectorMath.h"


int main()
{
	TLogic tlog;
	TVector vec;
	TVector vec1;
	TVector vec2;
	vec = tlog.SetVector(3,7);
	vec1 = tlog.SetVector(5, 5);
	vec2 = tlog.SetVector(10,5);

	float fdot = tlog.DotPruduct(vec, vec1);
	float fAngle = tlog.AngleBetween(vec, vec1);
	float fProjection = tlog.Projection(vec,vec1,vec2);


	std::cout << fdot << "\n" << fAngle << "\n" << fProjection;



	return 0;
}