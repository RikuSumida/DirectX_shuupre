/*******************************************************************************
*
*	�v���C���[
*
*******************************************************************************/



/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "effect.h"
/*******************************************************************************
*
*	�}�N����`
*
*******************************************************************************/
/*******************************************************************************
*
*	�O���[�o���ϐ�
*
*******************************************************************************/
CSceneX *SceneX;


KEY_INFO g_KeyNeutral [] =
{
	{40,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,0.1f,0.0f,0.0f},  //�E�r
	{-10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,0.1f,0.0f,0.0f},  //���r
	{10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //����
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//����

	{40,
	{{0.0f,10.0f,0.0f,0.1f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.0f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,0.0f,0.0f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,0.1f,0.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //����
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//����

};
KEY_INFO g_KeyWalk [] =
{
	{40,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,0.1f,0.0f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,0.1f,0.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //����
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//����

	{40,
	{{0.0f,10.0f,0.0f,0.1f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.0f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,1.0f,0.0f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,-1.1f,0.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //����
	{-5.0f,0.0f,0.0f,-1.1f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,-1.1f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,1.1f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,-1.1f,0.0f,0.0f}}},//����

	{40,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,0.1f,0.0f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,0.1f,0.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //����
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//����


	{40,
	{{0.0f,10.0f,0.0f,0.1f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.0f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,-1.0f,0.0f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,1.1f,0.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.0f,0.0f,0.0f},  //����
	{-5.0f,0.0f,0.0f,1.1f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,-1.1f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,-1.1f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,-1.1f,0.0f,0.0f}}}//����

};
KEY_INFO g_KeyPanch [] =
{
	{40,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,0.1f,0.0f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,0.1f,0.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //����
	{-5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,0.1f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,0.1f,0.0f,0.0f}}},//����

	{10,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,-2.0f,0.5f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,2.0f,1.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.5f,0.0f,-0.5f},  //����
	{-5.0f,0.0f,0.0f,-1.0f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,1.0f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,-1.0f,0.0f,0.0f}}},//����

	{10,
	{{0.0f,10.0f,0.0f,0.0f,0.0f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,-2.0f,-1.5f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,0.0f,1.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.5f,0.0f,-0.5f},  //����
	{-5.0f,0.0f,0.0f,-1.0f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,1.0f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,-1.0f,0.0f,0.0f}}},//����

	{40,
	{{0.0f,10.0f,0.0f,-0.3f,-0.5f,0.0f}, //��
	{0.0f,15.0f,0.0f,0.1f,0.0f,0.0f},  //��
	{-7.0f,12.0f,0.0f,-2.0f,-2.5f,1.0f},  //�E�r
	{-10.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //�E��
	{7.0f,12.0f,0.0f,0.0f,1.0f,-1.0f},  //���r
	{10.0f,0.0f,0.0f,0.5f,0.0f,-0.5f},  //����
	{-5.0f,0.0f,0.0f,-1.0f,0.0f,0.0f},  //�E�r
	{0.0f,-10.0f,0.0f,1.0f,0.0f,0.0f},  //�E��
	{5.0f,0.0f,0.0f,1.0f,0.0f,0.0f},  //���r
	{0.0f,-10.0f,0.0f,-1.0f,0.0f,0.0f}}},//����

};
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CSceneX::CSceneX(int Priority):CScene(Priority)
{
	/*���b�V���̃|�C���^*/
	m_pMesh = NULL ;
	/*�}�e���A���ւ̃|�C���^*/
	m_pBuffMat = NULL ;

	/*�}�e���A���̐�*/
	m_numMat = NULL ;


	
	m_Position = D3DXVECTOR3 ( 500 , 0 , 500 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Speed = 5;
	m_Cnt = 0;

}
//�f�X�g���N�^
CSceneX::~CSceneX()
{
}

/*******************************************************************************
*
*	������
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
	//���f���ǂݍ��� �e�ݒ�
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
	//�������[�V�����ݒ�
	////����
	//m_Model[0]->SetMotion(D3DXVECTOR3(0,10,0), D3DXVECTOR3(0,0,0) );
	////��
	//m_Model[1]->SetMotion(D3DXVECTOR3(0,15,0), D3DXVECTOR3(0,0,0) );
	////�E�r
	//m_Model[2]->SetMotion(D3DXVECTOR3(-7,12,0), D3DXVECTOR3(0,0,-1) );
	////�E��
	//m_Model[3]->SetMotion(D3DXVECTOR3(-10,0,0), D3DXVECTOR3(0,0,1) );
	////���r
	//m_Model[4]->SetMotion(D3DXVECTOR3(7,12,0), D3DXVECTOR3(0,0,1) );
	////����
	//m_Model[5]->SetMotion(D3DXVECTOR3(10,0,0), D3DXVECTOR3(0,0,-1) );
	////�E�r
	//m_Model[6]->SetMotion(D3DXVECTOR3(-5,0,0), D3DXVECTOR3(2,0,0) );
	////�E��
	//m_Model[7]->SetMotion(D3DXVECTOR3(0,-10,0), D3DXVECTOR3(-1,0,0) );
	////���r
	//m_Model[8]->SetMotion(D3DXVECTOR3(5,0,0), D3DXVECTOR3(-1.5,0,0) );
	////����
	//m_Model[9]->SetMotion(D3DXVECTOR3(0,-10,0), D3DXVECTOR3(-1,0,0) );

	SetAnim (MOTIONTYPE_WALK);


	return S_OK ;

}
//���[�V�����ݒ�
void CSceneX::SetAnim(MOTIONTYPE MotionType)
{
	switch(MotionType)
	{
		//�j���[�g����
	case MOTIONTYPE_NEUTRAL:
		m_KeyInfo = g_KeyNeutral;
		m_NumKey = 2;
		break;
		//����
	case MOTIONTYPE_WALK: 
		m_KeyInfo = g_KeyWalk;
		m_NumKey = 4;
		break;
		//�p���`
	case MOTIONTYPE_PANCH:
		m_KeyInfo = g_KeyPanch;
		m_NumKey = 4;

		break;
	}
	m_Key = 0;
	m_Frame = 0;
	m_MotionType = MotionType;
}
//���[�V�����A�b�v�f�[�g
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
		//���[�v�Ή�
		m_Key = (m_Key+1)%m_NumKey;

		m_Frame = 0;
	}
}
//����
CSceneX* CSceneX::Create(void)
{
	SceneX = new CSceneX ;
	SceneX ->Init();

	return SceneX;

}
//�擾
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
*	�I��
*
*
*******************************************************************************/
/*******************************************************************************
*
*	�I�������֐�
*	���� : ����
*	�߂�l : ����
*******************************************************************************/
void CSceneX::Uninit(void)
{
	for(int i=0; i<10; i++)
	{
		m_Model[i]->Uninit();
	}
	/*���b�V�����̉��*/
	if ( m_pMesh != NULL )
	{
		m_pMesh -> Release (  ) ;
		m_pMesh = NULL ;
	}

	/*�}�e���A�����̉��*/
	if ( m_pBuffMat != NULL )
	{
		m_pBuffMat -> Release (  ) ;
		m_pBuffMat = NULL ;
	}

}
/*******************************************************************************
*
*	�X�V
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



	/*���f���ړ�*/
	/*��*/
	if ( Input->GetKeyboardPress ( DIK_W ) )
	{
		/*���f�����ړ������Ɍ����悤�ɂ���*/
		m_Rotation . y = D3DX_PI - ( - Camera .rot .y ) ;
		/*�ړ�*/
		m_Position . x += sinf ( Camera .rot .y )*m_Speed ;
		m_Position . z += cosf ( Camera .rot .y )*m_Speed ;

	}
	/*��O*/
	if ( Input->GetKeyboardPress ( DIK_S ) )
	{
		/*���f�����ړ������Ɍ����悤�ɂ���*/
		m_Rotation . y = ( Camera .rot .y ) ;
		/*�ړ�*/
		m_Position . x -= sinf ( Camera .rot .y )*m_Speed  ;
		m_Position . z -= cosf ( Camera .rot .y )*m_Speed  ;
	}

	/*��*/
	if ( Input->GetKeyboardPress ( DIK_A ) )
	{

		/*���f�����ړ������Ɍ����悤�ɂ���*/
		m_Rotation . y = ( D3DX_PI * 0.5 ) - ( - Camera .rot .y ) ;

		/*�΂߈ړ�*/
		if ( Input->GetKeyboardPress ( DIK_W ) )
		{
			/*���f�����ړ������Ɍ����悤�ɂ���*/
			//m_Rotation . y = ( PI * 0.75 ) - ( - Camera .rot .y ) ;
			/*�ړ�*/
			m_Position . x += sinf ( ( D3DX_PI * ( 0.75 ) ) + Camera . rot . y ) ;
			m_Position . z += cosf ( ( D3DX_PI * ( 0.75 ) ) + Camera . rot . y ) ;

		}
		/*�΂߈ړ�*/
		if ( Input->GetKeyboardPress ( DIK_S ) )
		{
			/*���f�����ړ������Ɍ����悤�ɂ���*/
			m_Rotation . y = ( D3DX_PI * 0.25 ) - ( - Camera .rot .y ) ;

			/*�ړ�*/
			m_Position . x += sinf ( ( D3DX_PI * ( 0.25 ) ) + Camera . rot . y ) ;
			m_Position . z += cosf ( ( D3DX_PI * ( 0.25 ) ) + Camera . rot . y ) ;

		}
		/*�ړ�*/
		m_Position . x -= cosf ( -Camera . rot . y )*m_Speed  ;
		m_Position . z -= sinf ( -Camera . rot . y )*m_Speed  ;


	}

	if ( Input->GetKeyboardPress ( DIK_D ) )
	{
		/*���f�����ړ������Ɍ����悤�ɂ���*/
		m_Rotation . y = ( - D3DX_PI * 0.5 ) - ( - Camera .rot .y ) ;

		/*�΂߈ړ�*/
		if ( Input->GetKeyboardPress ( DIK_W ) )
		{
			/*���f�����ړ������Ɍ����悤�ɂ���*/
			m_Rotation . y = ( -D3DX_PI * 0.75 ) - ( - Camera .rot .y ) ;

			/*�ړ�*/
			m_Position . x += sinf ( ( -D3DX_PI * ( 0.75 ) ) + Camera . rot . y ) ;
			m_Position . z += cosf ( ( -D3DX_PI * ( 0.75 ) ) + Camera . rot . y ) ;

		}
		/*�΂߈ړ�*/
		if ( Input->GetKeyboardPress ( DIK_S ) )
		{
			/*���f�����ړ������Ɍ����悤�ɂ���*/
			m_Rotation . y = ( -D3DX_PI * 0.25 ) - ( - Camera .rot .y ) ;

			/*�ړ�*/
			m_Position .x += sinf ( ( -D3DX_PI * ( 0.25 ) ) + Camera . rot . y ) ;
			m_Position .z += cosf ( ( -D3DX_PI * ( 0.25 ) ) + Camera . rot . y ) ;

		}
		/*�ړ�*/
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
	//�I�u�W�F�N�g������
	if ( Input->GetKeyboardTrigger(DIK_DELETE))
	{
		Uninit();
		Release(1);
	}

	//���E�̋��E
	if (MeshField->LimitField(m_Position) == true )
	{
		m_Position = m_OldPos;
	}


	UpdateMotion();
	PrintDebugProc("�v���C���[X���W�F%f  Y���W:%f  Z���W%f\n",m_Position.x,m_Position.y,m_Position.z);



}
CBlock* CSceneX::GetBlock ( void )
{
	return m_Block;
}
/*******************************************************************************
*
*	�`��
*
*
*******************************************************************************/
/*******************************************************************************
*
*	�`�揈���֐�
*	���� : ����
*	�߂�l : ����
*******************************************************************************/

void CSceneX:: Draw ( void )
{

	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;
	D3DMATERIAL9 matDef ;
	D3DXMATERIAL * pMat ;



	/*���[���h�}�g���N�X�̏�����*/
	D3DXMatrixIdentity ( & m_mtxWorld ) ;

	/*�X�P�[���𔽉f*/
	D3DXMatrixScaling ( & mtxScl , 1.0f , 1.0f , 1.0f) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;
		
	/*��]�𔽉f*/
	D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
		
	/*�ړ��𔽉f*/
	D3DXMatrixTranslation ( & mtxTrans , m_Position . x , m_Position . y , m_Position . z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;
		
	/*���[���h�}�g���N�X�̐ݒ�*/
		
	pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;

	for(int i=0; i<10; i++)
	{
		m_Model[i]->Draw();
	}

	///*���݂̃}�e���A�����擾*/
	//pDevice ->GetMaterial ( & matDef ) ;

	//pMat = ( D3DXMATERIAL * ) m_pBuffMat ->GetBufferPointer (  ) ;

	//for ( int nCntMat = 0 ; nCntMat < ( int ) m_numMat ; nCntMat ++ )
	//{
	//	pDevice ->SetMaterial ( & pMat [ nCntMat ] .MatD3D ) ;
	//	pDevice ->SetTexture ( NULL , 0 ) ;
	//	m_pMesh ->DrawSubset ( nCntMat ) ;
	//}
	///*�}�e���A�������ɖ߂�*/
	//pDevice ->SetMaterial( & matDef ) ;

}
