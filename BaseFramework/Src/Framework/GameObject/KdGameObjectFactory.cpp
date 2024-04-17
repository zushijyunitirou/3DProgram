#include "KdGameObjectFactory.h"

void KdGameObjectFactory::RegisterCreateFunction(const std::string_view str, const std::function<std::shared_ptr<KdGameObject>(void)> func)
{
	m_createFunctions[str.data()] = func;
}

std::shared_ptr<KdGameObject> KdGameObjectFactory::CreateGameObject(const std::string_view objName) const
{
	auto creater = m_createFunctions.find(objName);

	if (creater == m_createFunctions.end())
	{
		assert(0 && "GameObjectFactoryに未登録のゲームオブジェクトクラスです");

		return nullptr;
	}

	return  creater->second();
}
