/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"
#include "scene.h"
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
CScene *CScene::m_Top[PRIORITY_NUM];
CScene *CScene::m_Cur[PRIORITY_NUM];
/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/

//コンストラクタ
CScene::CScene(int Priority)
{
	//リストに追加
	if ( m_Top[Priority] == NULL )
	{

		m_Top[Priority] = this ;
		m_Cur[Priority] = this ;
		m_Prev = NULL ;
		m_Next = NULL ;
	}
	else
	{
		m_Cur[Priority] ->m_Next = this ;
		m_Prev = m_Cur[Priority] ;
		m_Cur[Priority] = this ;
		m_Next = NULL;
	}
}
//デストラクタ
CScene::~CScene()
{
}
void CScene::SetPosition(D3DXVECTOR3 Pos )
{
	m_Position = Pos;
}
void CScene::SetRotation(D3DXVECTOR3 Rot)
{
	m_Rotation = Rot;
}
//更新
void CScene::UpdateAll(void)
{
	for (int i = 0 ; i<PRIORITY_NUM ; i++)
	{
		CScene *Scene = m_Top[i];
		CScene *Scene_Next ;
		if (Scene != NULL)
		{
			Scene_Next = Scene->m_Next ;
		}
		while ( Scene != NULL )
		{
			//次のクラスのポインタ格納
			Scene_Next = Scene->m_Next;

			Scene->Update();

			//次のクラスのポインタ
			Scene = Scene_Next;
			//Scene = NULL;
		}
	}
}
//描画
void CScene::DrawAll(void)
{

	for (int i = 0 ; i<PRIORITY_NUM ; i++)
	{

		CScene *Scene = m_Top[i];

		while ( Scene != NULL )
		{
			Scene->Draw();
			Scene = Scene->m_Next;

			//Scene = NULL;
		}
	}
}
//終了
void CScene::UninitAll(void)
{
	for (int i = 0 ; i<PRIORITY_NUM ; i++)
	{

		CScene *Scene = m_Top[i];
		CScene *Scene_Next;
		while ( Scene != NULL )
		{
			//次のクラスのポインタ格納
			Scene_Next = Scene->m_Next;

			//終了
			Scene->Uninit();
			//現在のクラスを破棄
			delete Scene;
			Scene = NULL;
			//次のクラスのポインタ
			Scene = Scene_Next;
			//Scene = NULL;



			//if ( Scene_Next != NULL )
			//{
			//	//終了
			//	Scene->Uninit();
			//	//現在のクラスを破棄
			//	delete Scene;
			//	Scene = NULL;
			//	//次のクラスのポインタ
			//	Scene = Scene_Next;
			//}
			////最後の時
			//else
			//{
			//	Scene->Uninit();
			//	delete Scene;
			//	Scene = NULL;
			//}
		}
		m_Top[i] = NULL;
	}
}
//個別に消す
void CScene::Release(int Priority)
{
	if ( this == m_Top[Priority] )
	{
		m_Top[Priority] = m_Next;
	}
	else
	{
		m_Prev->m_Next = m_Next;
	}

	if ( this == m_Cur[Priority] )
	{
		m_Cur[Priority] = m_Prev;
	}
	else
	{
		m_Next->m_Prev = m_Prev;
	}
	delete this ;
}

//取得関数
D3DXVECTOR3 CScene::GetPosition(void)
{
	return m_Position;
}

D3DXVECTOR3 CScene::GetRotation(void)
{
	return m_Rotation;
}




