#include "UI.h"

CUI::CUI() 
: CObject()
, IsMouseOn(false)
{

}

CUI::CUI(Vector2D InPosition, Vector2D InScale) 
: CObject(InPosition, InScale)
, IsMouseOn(false)
{

}

CUI::~CUI()
{

}