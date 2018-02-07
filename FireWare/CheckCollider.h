#ifndef _CHECKCOLLIDER_H_
#define _CHECKCOLLIDER_H_

class BoxCollider;
class SphereCollider;
class PointCollider;
class Collider;
class CheckCollider
{
public:
	static bool CheckColliders(Collider *pCollider01, Collider *pCollider02);

	
private:
	static bool CheckColliders(BoxCollider *pBoxCollider01, BoxCollider *pBoxCollider02);
	static bool CheckColliders(BoxCollider *pBoxCollider, SphereCollider *pSphereCollider);
	static bool CheckColliders(BoxCollider *pBoxCollider, PointCollider *pPointCollider);

	static bool CheckColliders(SphereCollider *pSphereCollider01, SphereCollider *pSphereCollider02);
	static bool CheckColliders(SphereCollider *pSphereCollider, BoxCollider *pBoxCollider);
	static bool CheckColliders(SphereCollider *pSphereCollider, PointCollider *pPointCollider);

	static bool CheckColliders(PointCollider *pPointCollider01, PointCollider *pPointCollider02);
	static bool CheckColliders(PointCollider *pPointCollider, BoxCollider *pBoxCollider);
	static bool CheckColliders(PointCollider *pPointCollider, SphereCollider *pSphereCollider);
};
#endif
