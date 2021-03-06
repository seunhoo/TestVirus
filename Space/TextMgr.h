#pragma once
class TextMgr : public Object
{
private:
	D3DXCOLOR m_Color;
	LPD3DXFONT m_pFont;
	RECT m_FontRect;
	Matrix m_wMat;

public:
	TextMgr();


	bool Init(int height, const std::string& fontname);
	int print(const std::string& str, int x, int y);

	void SetColor(int a, int r, int g, int b);


};

