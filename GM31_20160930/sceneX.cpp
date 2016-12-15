/*******************************************************************************
*
*	プレイヤー
*
*******************************************************************************/



/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"
#include "effect.h"
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
CSceneX *SceneX;


KEY_INFO g_KeyNeutral [] =
{
	{40,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,0.1f,0.0f,0.0f},  //右腕
	{-10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,0.1f,0.0f,0.0f},  //左腕
	{10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左手
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//左足

	{40,
	{{0.0f,10.0f,0.0f,0.1f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.0f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,0.0f,0.0f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,0.1f,0.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //左手
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//左足

};
KEY_INFO g_KeyWalk [] =
{
	{40,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,0.1f,0.0f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,0.1f,0.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左手
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//左足

	{40,
	{{0.0f,10.0f,0.0f,0.1f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.0f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,1.0f,0.0f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,-1.1f,0.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //左手
	{-5.0f,0.0f,0.0f,-1.1f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,-1.1f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,1.1f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,-1.1f,0.0f,0.0f}}},//左足

	{40,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,0.1f,0.0f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,0.1f,0.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左手
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//左足


	{40,
	{{0.0f,10.0f,0.0f,0.1f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.0f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,-1.0f,0.0f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,1.1f,0.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //左手
	{-5.0f,0.0f,0.0f,1.1f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,-1.1f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,-1.1f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,-1.1f,0.0f,0.0f}}}//左足

};
KEY_INFO g_KeyPanch [] =
{
	{40,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,0.1f,0.0f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,0.1f,0.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左手
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//左足

	{10,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,-2.0f,0.5f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,2.0f,1.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.5f,0.0f,-0.5f},  //左手
	{-5.0f,0.0f,0.0f,-1.0f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,1.0f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,-1.0f,0.0f,0.0f}}},//左足

	{10,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,-2.0f,-1.5f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,0.0f,1.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.5f,0.0f,-0.5f},  //左手
	{-5.0f,0.0f,0.0f,-1.0f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,1.0f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,-1.0f,0.0f,0.0f}}},//左足

	{40,
	{{0.0f,10.0f,0.0f,-0.3f,-0.5f,0.0f}, //胴
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //頭
	{-7.0f,12.0f,0.0f,-2.0f,-2.5f,1.0f},  //右腕
	{-10.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //右手
	{7.0f,12.0f,0.0f,0.0f,1.0f,-1.0f},  //左腕
	{10.0f,0.0f,0.0f,0.5f,0.0f,-0.5f},  //左手
	{-5.0f,0.0f,0.0f,-1.0f,0.0f,0.0f},  //右脚
	{0.0f,-10.0f,0.0f,1.0f,0.0f,0.0f},  //右足
	{5.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //左脚
	{0.0f,-10.0f,0.0f,-1.0f,0.0f,0.0f}}},//左足

};
/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/

//コンストラクタ
CSceneX::CSceneX(int Priority):CScene(Priority)
{
	/*メッシュのポインタ*/
	m_pMesh = NULL ;
	/*マテリアルへのポインタ*/
	m_pBuffMat = NULL ;

	/*マテリアルの数*/
	m_numMat = NULL ;


	
	m_Position = D3DXVECTOR3 ( 500 , 0 , 500 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Speed = 5;
	m_Cnt = 0;

}
//デストラクタ
CSceneX::~CSceneX()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CSceneX:: Init ( void )
{
	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	m_Shot = false;
	m_fue = false;
	for (int i = 0 ;i<10 ; i++)
	{
		m_Model[i] = new CModel;

	}
	//モデル読み込み 親設定
	m_Model[0] ->Init("data/MODEL/body.x"  ,NULL);
	m_Model[1] ->Init("data/MODEL/head.x"  ,m_Model[0]);
	m_Model[2] ->Init("data/MODEL/arm_r.x" ,m_Model[0]);
	m_Model[3] ->Init("data/MODEL/hand_r.x",m_Model[2]);
	m_Model[4] ->Init("data/MODEL/arm_l.x" ,m_Model[0]);
	m_Model[5] ->Init("data/MODEL/hand_l.x",m_Model[4]);
	m_Model[6] ->Init("data/MODEL/leg_r.x",m_Model[0]);
	m_Model[7] ->Init("data/MODEL/foot_r.x" ,m_Model[6]);
	m_Model[8] ->Init("data/MODEL/leg_l.x",m_Model[0]);
	m_Model[9] ->Init("data/MODEL/foot_l.x" ,m_Model[8]);
	//初期モーション設定
	////胴体
	//m_Model[0]->SetMotion(D3DXVECTOR3(0,10,0), D3DXVECTOR3(0,0,0) );
	////頭
	//m_Model[1]->SetMotion(D3DXVECTOR3(0,15,0), D3DXVECTOR3(0,0,0) );
	////右腕
	//m_Model[2]->SetMotion(D3DXVECTOR3(-7,12,0), D3DXVECTOR3(0,0,-1) );
	////右手
	//m_Model[3]->SetMotion(D3DXVECTOR3(-10,0,0), D3DXVECTOR3(0,0,1) );
	////左腕
	//m_Model[4]->SetMotion(D3DXVECTOR3(7,12,0), D3DXVECTOR3(0,0,1) );
	////左手
	//m_Model[5]->SetMotion(D3DXVECTOR3(10,0,0), D3DXVECTOR3(0,0,-1) );
	////右脚
	//m_Model[6]->SetMotion(D3DXVECTOR3(-5,0,0), D3DXVECTOR3(2,0,0) );
	////右足
	//m_Model[7]->SetMotion(D3DXVECTOR3(0,-10,0), D3DXVECTOR3(-1,0,0) );
	////左脚
	//m_Model[8]->SetMotion(D3DXVECTOR3(5,0,0), D3DXVECTOR3(-1.5,0,0) );
	////左足
	//m_Model[9]->SetMotion(D3DXVECTOR3(0,-10,0), D3DXVECTOR3(-1,0,0) );

	SetAnim (MOTIONTYPE_WALK);


	return S_OK ;

}
//モーション設定
void CSceneX::SetAnim(MOTIONTYPE MotionType)
{
	switch(MotionType)
	{
		//ニュートラル
	case MOTIONTYPE_NEUTRAL:
		m_KeyInfo = g_KeyNeutral;
		m_NumKey = 2;
		break;
		//歩き
	case MOTIONTYPE_WALK: 
		m_KeyInfo = g_KeyWalk;
		m_NumKey = 4;
		break;
		//パンチ
	case MOTIONTYPE_PANCH:
		m_KeyInfo = g_KeyPanch;
		m_NumKey = 4;

		break;
	}
	m_Key = 0;
	m_Frame = 0;
	m_MotionType = MotionType;
}
//モーションアップデート
void CSceneX::UpdateMotion(void)
{
	if(m_KeyInfo == g_KeyPanch && m_Key >= 3  )
	{
		return;
	}

	for (int i=0 ; i<10;i++)
	{
		KEY *Key,*KeyNext;
		float rate;
		D3DXVECTOR3 pos ,rot;

		Key = &m_KeyInfo[m_Key].Key[i];

		KeyNext = &m_KeyInfo[(m_Key+1)%m_NumKey].Key[i];

		rate = (float)m_Frame/m_KeyInfo[m_Key].Frame;

		pos.x = Key->PositionX*(1.0f-rate) + KeyNext->PositionX * rate;
		pos.y = Key->PositionY*(1.0f-rate) + KeyNext->PositionY * rate;
		pos.z = Key->PositionZ*(1.0f-rate) + KeyNext->PositionZ * rate;

		rot.x = Key->RotationX*(1.0f-rate) + KeyNext->RotationX * rate;
		rot.y = Key->RotationY*(1.0f-rate) + KeyNext->RotationY * rate;
		rot.z = Key->RotationZ*(1.0f-rate) + KeyNext->RotationZ * rate;

		m_Model[i]->SetMotion(pos,rot);

	}

	m_Frame ++;

	if (m_Frame >= m_KeyInfo[m_Key].Frame)
	{
		//ループ対応
		m_Key = (m_Key+1)%m_NumKey;

		m_Frame = 0;
	}
}
//生成
CSceneX* CSceneX::Create(void)
{
	SceneX = new CSceneX ;
	SceneX ->Init();

	return SceneX;

}
//取得
//D3DXVECTOR3 CSceneX::GetPosition(void)
//{
//	return SceneX->m_Position;
//}
bool CSceneX::GetShot(void)
{
	return m_Shot;
}
bool CSceneX::GetFue(void)
{
	return m_fue;
}

/*******************************************************************************
*
*	終了
*
*
*******************************************************************************/
/*******************************************************************************
*
*	終了処理関数
*	引数 : 無し
*	戻り値 : 無し
*******************************************************************************/
void CSceneX::Uninit(void)
{
	for(int i=0; i<10; i++)
	{
		m_Model[i]->Uninit();
	}
	/*メッシュ情報の解放*/
	if ( m_pMesh != NULL )
	{
		m_pMesh -> Release (  ) ;
		m_pMesh = NULL ;
	}

	/*マテリアル情報の解放*/
	if ( m_pBuffMat != NULL )
	{
		m_pBuffMat -> Release (  ) ;
		m_pBuffMat = NULL ;
	}

}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CSceneX::Update(void)
{
	CInput *Input;
	CCamera *pCamera;
	CAMERA Camera;
	CMeshfield *MeshField;
	CGame* game = (CGame*)GetManager()->GetMode();
	MeshField = game->GetMeshField();
	pCamera = game->GetCamera();
	Camera = pCamera->m_Camera;
	Input = GetManager()->GetInput();

	m_OldPos = m_Position;

	if ( Input->GetKeyboardTrigger ( DIK_1 ) )
	{
		SetAnim (MOTIONTYPE_NEUTRAL);
	}
	if ( Input->GetKeyboardTrigger ( DIK_2 ) )
	{
		SetAnim (MOTIONTYPE_WALK);
	}
	m_Cnt++;
	if (m_Cnt > 180)
	{
		m_fue = true;
		if (Input->GetKeyboardTrigger(DIK_SPACE))
		{
			m_Shot = true;
			m_fue = false;

			SetAnim(MOTIONTYPE_PANCH);
			m_Cnt = 0;
			CEffect::Create("data/TEXTURE/!!.png", 5, 1, D3DXVECTOR3(m_Position.x, m_Position.y+100.0f, m_Position.z));
			CSoundGL::Start(SOUND_LABEL_SE_FUE,FALSE);

		}

	}
	if (m_Shot == true && m_Cnt > 100)
	{
		m_Shot = false;
		SetAnim(MOTIONTYPE_WALK);
	}



	/*モデル移動*/
	/*奥*/
	if ( Input->GetKeyboardPress ( DIK_W ) )
	{
		/*モデルが移動方向に向くようにする*/
		m_Rotation . y = D3DX_PI - ( - Camera .rot .y ) ;
		/*移動*/
		m_Position . x += sinf ( Camera .rot .y )*m_Speed ;
		m_Position . z += cosf ( Camera .rot .y )*m_Speed ;

	}
	/*手前*/
	if ( Input->GetKeyboardPress ( DIK_S ) )
	{
		/*モデルが移動方向に向くようにする*/
		m_Rotation . y = ( Camera .rot .y ) ;
		/*移動*/
		m_Position . x -= sinf ( Camera .rot .y )*m_Speed  ;
		m_Position . z -= cosf ( Camera .rot .y )*m_Speed  ;
	}

	/*左*/
	if ( Input->GetKeyboardPress ( DIK_A ) )
	{

		/*モデルが移動方向に向くようにする*/
		m_Rotation . y = ( D3DX_PI * 0.5 ) - ( - Camera .rot .y ) ;

		/*斜め移動*/
		if ( Input->GetKeyboardPress ( DIK_W ) )
		{
			/*モデルが移動方向に向くようにする*/
			//m_Rotation . y = ( PI * 0.75 ) - ( - Camera .rot .y ) ;
			/*移動*/
			m_Position . x += sinf ( ( D3DX_PI * ( 0.75 ) ) + Camera . rot . y ) ;
			m_Position . z += cosf ( ( D3DX_PI * ( 0.75 ) ) + Camera . rot . y ) ;

		}
		/*斜め移動*/
		if ( Input->GetKeyboardPress ( DIK_S ) )
		{
			/*モデルが移動方向に向くようにする*/
			m_Rotation . y = ( D3DX_PI * 0.25 ) - ( - Camera .rot .y ) ;

			/*移動*/
			m_Position . x += sinf ( ( D3DX_PI * ( 0.25 ) ) + Camera . rot . y ) ;
			m_Position . z += cosf ( ( D3DX_PI * ( 0.25 ) ) + Camera . rot . y ) ;

		}
		/*移動*/
		m_Position . x -= cosf ( -Camera . rot . y )*m_Speed  ;
		m_Position . z -= sinf ( -Camera . rot . y )*m_Speed  ;


	}

	if ( Input->GetKeyboardPress ( DIK_D ) )
	{
		/*モデルが移動方向に向くようにする*/
		m_Rotation . y = ( - D3DX_PI * 0.5 ) - ( - Camera .rot .y ) ;

		/*斜め移動*/
		if ( Input->GetKeyboardPress ( DIK_W ) )
		{
			/*モデルが移動方向に向くようにする*/
			m_Rotation . y = ( -D3DX_PI * 0.75 ) - ( - Camera .rot .y ) ;

			/*移動*/
			m_Position . x += sinf ( ( -D3DX_PI * ( 0.75 ) ) + Camera . rot . y ) ;
			m_Position . z += cosf ( ( -D3DX_PI * ( 0.75 ) ) + Camera . rot . y ) ;

		}
		/*斜め移動*/
		if ( Input->GetKeyboardPress ( DIK_S ) )
		{
			/*モデルが移動方向に向くようにする*/
			m_Rotation . y = ( -D3DX_PI * 0.25 ) - ( - Camera .rot .y ) ;

			/*移動*/
			m_Position .x += sinf ( ( -D3DX_PI * ( 0.25 ) ) + Camera . rot . y ) ;
			m_Position .z += cosf ( ( -D3DX_PI * ( 0.25 ) ) + Camera . rot . y ) ;

		}
		/*移動*/
		m_Position .x += cosf ( -Camera . rot . y )*m_Speed  ;
		m_Position .z += sinf ( -Camera . rot . y )*m_Speed  ;

	}
	if ( Input->GetKeyboardPress ( DIK_SPACE ) )
	{
		m_Speed = 8;

		//m_Shot = true;
		//m_Block = CBlock::Create();
	}
	else
	{
		m_Speed = 8;
	}

	if ( Input->GetKeyboardPress(DIK_Z) )
	{
		m_Rotation.y += 0.1;
	}
	if (Input->GetKeyboardPress(DIK_C) )
	{
		m_Rotation.y -= 0.1;
	}
	m_Position.y = MeshField->GetHeight(m_Position);
	//オブジェクトを消す
	if ( Input->GetKeyboardTrigger(DIK_DELETE))
	{
		Uninit();
		Release(1);
	}

	//世界の境界
	if (MeshField->LimitField(m_Position) == true )
	{
		m_Position = m_OldPos;
	}


	UpdateMotion();
	PrintDebugProc("プレイヤーX座標：%f  Y座標:%f  Z座標%f\n",m_Position.x,m_Position.y,m_Position.z);



}
CBlock* CSceneX::GetBlock ( void )
{
	return m_Block;
}
/*******************************************************************************
*
*	描画
*
*
*******************************************************************************/
/*******************************************************************************
*
*	描画処理関数
*	引数 : 無し
*	戻り値 : 無し
*******************************************************************************/

void CSceneX:: Draw ( void )
{

	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;
	D3DMATERIAL9 matDef ;
	D3DXMATERIAL * pMat ;



	/*ワールドマトリクスの初期化*/
	D3DXMatrixIdentity ( & m_mtxWorld ) ;

	/*スケールを反映*/
	D3DXMatrixScaling ( & mtxScl , 1.0f , 1.0f , 1.0f) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;
		
	/*回転を反映*/
	D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
		
	/*移動を反映*/
	D3DXMatrixTranslation ( & mtxTrans , m_Position . x , m_Position . y , m_Position . z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;
		
	/*ワールドマトリクスの設定*/
		
	pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;

	for(int i=0; i<10; i++)
	{
		m_Model[i]->Draw();
	}

	///*現在のマテリアルを取得*/
	//pDevice ->GetMaterial ( & matDef ) ;

	//pMat = ( D3DXMATERIAL * ) m_pBuffMat ->GetBufferPointer (  ) ;

	//for ( int nCntMat = 0 ; nCntMat < ( int ) m_numMat ; nCntMat ++ )
	//{
	//	pDevice ->SetMaterial ( & pMat [ nCntMat ] .MatD3D ) ;
	//	pDevice ->SetTexture ( NULL , 0 ) ;
	//	m_pMesh ->DrawSubset ( nCntMat ) ;
	//}
	///*マテリアルを元に戻す*/
	//pDevice ->SetMaterial( & matDef ) ;

}
