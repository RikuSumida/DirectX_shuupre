/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "blink.h"
/*******************************************************************************
*
*	マクロ定義
*
*******************************************************************************/
/*******************************************************************************
*
*	グローバル変数
*
*******************************************************************************/
/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/

//コンストラクタ
CTitle::CTitle()
{
}
//デストラクタ
CTitle::~CTitle()
{
}

//更新
void CTitle::Init(void)
{
	CTitleBg::Create();
	CTitleRogo::Create();
	CBlink::Create("data/TEXTURE/PressEnter.png",400.0f,200.0f,D3DXVECTOR3(450.0f,500.0f,0.0f));
	m_Cnt = 0;
	CSoundGL::Init();
	CSoundGL::Load();

	CSoundGL::Start(SOUND_LABEL_BGM000,TRUE);
}
//描画
void CTitle::Uninit(void)
{
	CScene::UninitAll();
	CSoundGL::Uninit();

}
//終了
void CTitle::Update(void)
{
	CInput *Input;
	Input = GetManager()->GetInput();

	m_Cnt++;
	if(m_Cnt >= 120)
	{
		if (Input->GetKeyboardTrigger(DIK_RETURN))
		{
			CSoundGL::Start(SOUND_LABEL_SE_ENTER,FALSE);
			CFade::Start(new CGame);
		}
		//m_Cnt = 0;
	}
	CScene::UpdateAll();

}
//個別に消す
void CTitle::Draw(void)
{
	CScene::DrawAll();
}

