#pragma once
#include <algorithm>

#define ObjMgr ObjectMgr::GetInst()
class ObjectMgr : public Singleton<ObjectMgr>
{
public:
	std::list<Object*> m_Objects;

	struct stLISTsort
	{
		bool operator() (const Object* pObject1, const Object* pObject2) const
		{
			if (pObject1->m_Layer < pObject2->m_Layer)
				return TRUE;

			return FALSE;
		}
	};

public:
	float m_Cure;
	void Release();
	void DeleteCheak();
	void Update(float deltaTime, float time);
	void Render();
	float GetCure() { return m_Cure; }
	void AddCure(float cure) { m_Cure += cure; }
	void ReSetCure() { m_Cure = 0; }


	RECT rc;

public:
	void AddObject(Object* obj, const std::string tag);
	void RemoveObject(Object* obj);
	void CollisionCheak(Object* obj, const std::string tag);
	void DeleteObject(std::string tag);

};

