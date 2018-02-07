#ifndef _BOXCOLLIDER_H_
#define _BOXCOLLIDER_H_
#include "Collider.h"
#include <iostream>
#include <vector>
#include "Vector2.h"

class Vector2;
class Transform;
class BoxCollider : public Collider
{
public:
	BoxCollider(GameObject *pGameobject, const double offsetLeft = 0, const double offsetUp = 0, const double offsetRight = 0, const double offsetDown = 0);
	~BoxCollider();

	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;

	
	friend class CheckCollider;
private:
	std::vector<Vector2*> m_pointOrigin;
	std::vector<Vector2*> m_points;
	double m_pLengths[4];
	double m_pAngles[4];
	double m_pAnglesReal[4];
	double m_rotation;

	double m_offsets[4];
	Vector2 *m_centerPoint;
	int a;

	void InitByScal();

};
#endif
