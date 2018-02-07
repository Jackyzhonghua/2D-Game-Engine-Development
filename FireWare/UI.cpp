#include "UI.h"
#include "Transform.h"
#include "GameObject.h"
#include "UIControl.h"




UI::UI(Scene* const selfScene) :GameObject("UI", selfScene)
{
	Transform *pTransform = new Transform(this);
	pTransform->SetPosition(0, 0);

	UIControl* pUIControl = new UIControl(this);

}


UI::~UI()
{
}
