#include"stdafx.h"
#include "TextMgr.h"

TextMgr::TextMgr()
{
	m_Color = D3DCOLOR_ARGB(255, 255, 255, 255);

	m_FontRect.top = 0;
	m_FontRect.left = 0;
	m_FontRect.right = 1920;
	m_FontRect.bottom = 1080;

	m_pFont = NULL;
	m_Layer = 101;
}

bool TextMgr::Init(int height, const std::string& fontname)
{
	UINT weight = FW_NORMAL;


	std::wstring temp = std::wstring(fontname.begin(), fontname.end());
	LPCWSTR lstr = temp.c_str();

	HRESULT hr = D3DXCreateFont(
		Renderer::GetInst()->GetDevice(), 
		height,
		0,
		weight,
		1,
		0,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		lstr, 
		&m_pFont);

	if (FAILED(hr))
		return false;

	D3DXMatrixTransformation2D(&m_wMat, 0, 0.0f, 0, 0, 0.0f, 0);

	return true;
}

int TextMgr::print(const std::string& str, int x, int y)
{
	if (m_pFont == NULL)
		return 0;

	m_FontRect.left = x;
	m_FontRect.top = y;

	Vec2 rCenter = Vec2((float)x, (float)y);
	D3DXMatrixTransformation2D(&m_wMat, NULL, 0.0f, NULL, &rCenter, 0, NULL);
	Renderer::GetInst()->GetSprite()->SetTransform(&m_wMat);
	return m_pFont->DrawTextA(Renderer::GetInst()->GetSprite(), str.c_str(), -1, &m_FontRect, DT_LEFT, m_Color);
}

void TextMgr::SetColor(int a, int r, int g, int b)
{
	m_Color = D3DCOLOR_ARGB(a, r, g, b);
}
