/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"
#include "title.h"
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
	m_Cnt = 0;
}
//描画
void CTitle::Uninit(void)
{
	CScene::UninitAll();
}
//終了
void CTitle::Update(void)
{
	CInput *Input;
	Input = GetManager()->GetInput();

	m_Cnt++;
	if(m_Cnt >= 300)
	{
		if (Input->GetKeyboardTrigger(DIK_RETURN))
		{
			CFade::Start(new CGame);
		}
		m_Cnt = 300;
	}
	CScene::UpdateAll();

}
//個別に消す
void CTitle::Draw(void)
{
	CScene::DrawAll();
}

