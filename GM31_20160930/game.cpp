/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"
#include "game.h"
#include "fence.h"
#include "effect.h"
#include "fue.h"
#include "gauge.h"
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
CGame::CGame()
{
	m_Camera = NULL;
	m_Light = NULL;

}
//デストラクタ
CGame::~CGame()
{
}

//初期化
void CGame::Init(void)
{
	m_Camera = new CCamera;
	m_Camera ->Init();

	m_Light = new CLight ;
	m_Light ->Init();

	m_Mesh = CMeshfield::Create();
	CSky::Create();

	//m_Billbord = CBillbord::Create();
	for (int i = 0 ;i<ENEMY_MAX;i++)
	{
		m_Enemy[i] = CEnemy::Create();
	}
	//CScene3D::Create();	
	m_Player = CSceneX::Create();
	m_Gate = CGate::Create();
	CFence::Create();
	CTime::Create();
	CScene2D::Create();
	CFue::Create("data/TEXTURE/fue2.png", 150.0f, 150.0f, D3DXVECTOR3(700.0f, 500.0f, 0.0f));
	CGauge::Create();

	CSoundGL::Init();
	CSoundGL::Load();

	CSoundGL::Start(SOUND_LABEL_BGM000,TRUE);
	


}
//終了
void CGame::Uninit(void)
{
	m_Camera ->Uninit();
	delete m_Camera;
	m_Camera = NULL;

	m_Light ->Uninit();
	delete m_Light;
	m_Light = NULL;

	CScene::UninitAll();
	CSoundGL::Uninit();


}
//更新
void CGame::Update(void)
{
	CInput *Input;
	Input = GetManager()->GetInput();
	m_Camera ->Update();
	m_Light ->Update();

	CScene::UpdateAll();

	//if (Input->GetKeyboardTrigger(DIK_RETURN))
	//{
	//	CFade::Start(new CResult);
	//}

	//for ( int i = 0 ; i < SCENE_NUM ; i++ )
	//{
	//	m_Scene[i] ->Draw();
	//}
	//終了
	//if (Input->GetKeyboardTrigger(DIK_RETURN))
	//{
	//	CFade::Start(new CResult);
	//}


	
}
//個別に消す
void CGame::Draw(void)
{
	m_Camera ->SetCamera();

	CScene::DrawAll();

}
CMeshfield* CGame::GetMeshField (void)
{
	return  m_Mesh; 
}
CCamera* CGame::GetCamera (void)
{
	return  m_Camera; 
}
CSceneX* CGame::GetPlayer (void)
{
	return m_Player;
}
CBillbord* CGame::GetBillbord (void)
{
	return m_Billbord;
}
CEnemy* CGame::GetEnemy(int id)
{

	return m_Enemy[id];
}
CGate* CGame::GetGate(void)
{
	return m_Gate;
}