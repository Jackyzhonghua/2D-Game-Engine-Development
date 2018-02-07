#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_


class Transform;
#include "Componentbehavior.h"
#include "Vector2.h"
#include <vector>
#include "Mathf.h"

class Transform : public Componentbehavior 
{
public:
	Transform();
	Transform(GameObject *pGameobject);
	~Transform();

	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;

	virtual void  SetEnable(bool bEnable) override;

	//access
	Vector2 GetPosition() const { return this->m_position; }
	double GetRotation() const { return this->m_rotation; }
	Vector2 GetScale() const { return this->m_scale; }

	Vector2 GetLocalPosition() const { return this->m_localPosition; }
	double GetLocalRotation() const { return this->m_localRotation; }
	Vector2 GetLocalScale() const { return this->m_localScale; }

	Vector2 Right() { return m_right; }
	Vector2 Up() { return m_up; }

	void SetPosition(Vector2 newPosition);
	void SetPosition(double const x, double const y);
	void SetRotation(double angle);
	void SetScale(Vector2 newScal);
	void SetScale(double x, double y);

	void SetLocalPosition(Vector2 newPosition);
	void SetLocalPosition(double x, double y);
	void SetLocalRotation(double angle);
	void SetLocalScale(Vector2 newScal);
	void SetLocalScale(double x, double y);

	void TranslateLocal(const Vector2 dirction);
	void Translate(const Vector2 dirction);
	void Rotate(double angle);
	void Scal(Vector2 scal);
	void SetParent(Transform *parent);
	void AddChild(Transform *child);
	Transform* Find(std::string  name) const;
	Transform *GetChild (int index) const;
	Transform *GetParent() const { return m_pParent; }




private:
	Transform *m_pParent;
	std::vector<Transform*> m_childs;
	Transform *m_pRoot;

	Vector2 m_position;
	double m_rotation;
	Vector2 m_scale;

	Vector2 m_localPosition;
	double m_localRotation;
	Vector2 m_localScale;

	Vector2 m_right;
	Vector2 m_up;

	double m_oldParentRotation;



	unsigned int m_childCount;


	void SetLocalPRSByWorld();
	void SetWroldPRSByLocal();
	void SetUpRight();
	void ResetRotation();
	void SetRotationByParent();
};
#endif

