/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "effect.h"
#include "3Dobject.h"
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
CEnemy *Enemy;

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CEnemy::CEnemy(int Priority):CScene3D(Priority)
{
	/*�e�N�X�`���ւ̃|�C���^*/
	m_pTexturePolygon = NULL ;
	/*���_�o�b�t�@�ւ̃|�C���^*/
	m_pVtxBuffPolygon = NULL ;
	
	m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0, 0 ) ;
	m_center =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_change =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Vec1 =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rot = 0;
	m_Use = true;
	m_Cnt = 0;

	m_WanderPos = D3DXVECTOR3(0, 0, 0);
	m_randvalue = 0;

	m_WanderJitter = 70;
	m_WanderRadius = 200;
	m_WanderDistance = 250;

	m_tex = CEffect::Load("data/TEXTURE/explosion000.png");



}
//�f�X�g���N�^
CEnemy::~CEnemy()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CEnemy:: Init ( void )
{
	
	//m_Target = CBillbord::Create();
	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();
	/*�Ίp���̒���*/
	m_fLengthbillboard = sqrtf ( ( Enemy_WIDTH * billboard_WIDTH ) + ( Enemy_HEIGHT * billboard_HEIGHT ) ) ;
	/*�p�x*/
	m_fAnglebillboard = atan2f ( Enemy_WIDTH , Enemy_HEIGHT ) ;

	m_model = new CModel;
	//m_Target = new CModel;
	//���f���ǂݍ���
	m_model->Init("data/MODEL/Sheep.x",NULL);
	//m_Target->Init("data/MODEL/Target.x", NULL);
	//m_Target = CSceneObject::Create("data/MODEL/Target.x");


	///*�e�N�X�`���̓ǂݍ���*/
	//D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/seep.png" , & m_pTexturePolygon ) ;
	//for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	//{
	//	/*���_�o�b�t�@�̐���*                        �m�ۂ���o�b�t�@�T�C�Y                         �g�p���钸�_�t�H�[�}�b�g*/
	//	if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_3D ) * 4 , D3DUSAGE_WRITEONLY , FVF_VERTEX_3D , D3DPOOL_MANAGED , & m_pVtxBuffPolygon  , NULL ) ) )
	//	{
	//		return E_FAIL ;
	//	}
	//}

	///*�������m��*/
	//m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;
	//pVtx [ 0 ].pos .x = m_Position .x - sinf ( m_fAnglebillboard + m_Rotation .z  ) * m_fLengthbillboard ;
	//pVtx [ 0 ].pos .y = 50.0f;//g_posbillboard .y - cosf ( g_fAnglebillboard + g_rotbillboard .z  ) * g_fLengthbillboard ;
	//pVtx [ 0 ].pos .z = 0.0f ;
	//pVtx [ 1 ].pos .x = m_Position .x + sinf ( m_fAnglebillboard + m_Rotation .z  ) * m_fLengthbillboard ;
	//pVtx [ 1 ].pos .y = 50.0f;//g_posbillboard .y - cosf ( g_fAnglebillboard + g_rotbillboard .z  ) * g_fLengthbillboard ;
	//pVtx [ 1 ].pos .z = 0.0f ;
	//pVtx [ 2 ].pos .x = m_Position .x - sinf ( m_fAnglebillboard - m_Rotation .z  ) * m_fLengthbillboard ;
	//pVtx [ 2 ].pos .y = 0;//g_posbillboard .y + cosf ( g_fAnglebillboard - g_rotbillboard .z  ) * g_fLengthbillboard ;
	//pVtx [ 2 ].pos .z = 0.0f ;
	//pVtx [ 3 ].pos .x = m_Position .x + sinf ( m_fAnglebillboard - m_Rotation .z ) * m_fLengthbillboard ;
	//pVtx [ 3 ].pos .y = 0;//g_posbillboard .y + cosf ( g_fAnglebillboard - g_rotbillboard .z ) * g_fLengthbillboard ;
	//pVtx [ 3 ].pos .z = 0.0f ;


	//pVtx [ 0 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 1 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 2 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 3 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;

	///*���_�J���[*/

	//pVtx [ 0 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	//pVtx [ 1 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	//pVtx [ 2 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	//pVtx [ 3 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	///*�e�N�X�`�����W*******************   U     V   */
	//pVtx [ 0 ].tex = D3DXVECTOR2 ( 0.0f , 0.0f ) ;
	//pVtx [ 1 ].tex = D3DXVECTOR2 ( 1 , 0.0f ) ;
	//pVtx [ 2 ].tex = D3DXVECTOR2 ( 0.0f , 1 ) ;
	//pVtx [ 3 ].tex = D3DXVECTOR2 ( 1 , 1 ) ;
	///*���*/
	//m_pVtxBuffPolygon  ->Unlock ( ) ;
	m_Position = D3DXVECTOR3 ( rand()%1000 , 0 , rand()%1500 ) ;

	//m_Vec1 = D3DXVECTOR3(rand()%5,0,rand()%5);
	EnemyLength = ENEMY_DISTANCE + rand()%100;


	m_WanderTarget = m_Position;
	double theta = (1 / (rand() % 10 + 1)) * (D3DX_PI * 2);
	m_WanderTarget += D3DXVECTOR3(m_WanderRadius*sinf(theta)*m_WanderRadius, 0, m_WanderRadius*cosf(theta)*m_WanderRadius);

	return S_OK ;

}
//����
CEnemy* CEnemy::Create(void)
{
	//CBillbord *Billbord;
	Enemy = new CEnemy ;
	Enemy ->Init();

	return Enemy;

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
void CEnemy::Uninit(void)
{
	m_model->Uninit();
	delete m_model;
	//for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	//{
	//	/*���_�o�b�t�@�̉��*/
	//	if ( m_pVtxBuffPolygon  != NULL )
	//	{
	//		m_pVtxBuffPolygon ->Release ( ) ;
	//		m_pVtxBuffPolygon  = NULL ;
	//	}
	//	
	//	/*���_�o�b�t�@�̉��*/
	//	if ( m_pTexturePolygon  != NULL )
	//	{
	//		m_pTexturePolygon ->Release ( ) ;
	//		m_pTexturePolygon  = NULL ;
	//	}

	//}

}
D3DXVECTOR3 CEnemy::GetVec(void)
{
	return m_Vec1;
}
bool CEnemy::GetUse(void)
{
	return m_Use;
}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CEnemy::Update(void)
{
	CSceneX *Player;
	D3DXVECTOR3 PlayerPos;
	CBlock* Block;
	CMeshfield* Field;
	float Rot;
	bool Shot,Hit;

	CGame* game = (CGame*)GetManager()->GetMode();

	
	Shot = false;
	Hit = false;
	Field = game->GetMeshField();

	Player = game->GetPlayer();
	PlayerPos = Player->GetPosition();
	Shot = Player->GetShot();

	m_OldPos = m_Position;
	/*�Ίp���̒���*/
	m_fLengthbillboard = sqrtf ( ( PLAYER_WIDTH * PLAYER_WIDTH ) + ( PLAYER_WIDTH * PLAYER_WIDTH ) ) ;
	/*�p�x*/
	m_fAnglebillboard = atan2f ( PLAYER_WIDTH , PLAYER_WIDTH ) ;

	Rot = 2.0f;

	m_Position.y = Field->GetHeight(m_Position);


	//////////////////////////boids

	//��
	CGate* gate;
	D3DXVECTOR3 Gatepos;
	gate = game->GetGate();
	Gatepos = gate->GetPosition();


	
	CEnemy* enemy;
	m_LastPosition = m_Position;

	float Length;

	m_Vec1 = D3DXVECTOR3(0,0,0);
	//��������
	PlayerPos = game->GetPlayer()->GetPosition();
	Shot = Player->GetShot();
	int ShotLength = 0;
	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		m_change = enemy->GetPosition();
		if(m_change != m_Position )
		{
			if (enemy->GetUse() == true)
			{
				m_change = m_Position-  m_change ;
				//����
				Length = D3DXVec3Length(&m_change);
				if (Length < EnemyLength)
				{

					D3DXVec3Normalize(&m_change, &m_change);
					//D3DXVec3Length(&m_change);

					m_Vec1 += m_change*2;
				}
			}
			


		}
	}
	//�v���C���[�Ƃ̈�������
	//����
	m_change = PlayerPos - m_Position;
	Length = D3DXVec3Length(&m_change);
	if (Shot == true)
	{
		ShotLength = 400;
	}
	if (Length < PLAYER_DISTANCE + ShotLength)
	{
		D3DXVec3Normalize(&m_change, &m_change);

		m_Vec1 += -m_change*4;

		//CEffect::Create("data/TEXTURE/explosion000.png", 8, 1, m_Position, 30.0f, 30.0f,m_tex);

	}
	if (Length < PLAYER_DISTANCE + 100.0f + ShotLength)
	{
		m_Tracking = true;

	}
	else
	{
		m_Tracking = false;
	}
	//��
	if (m_Tracking == false)
	{
		m_change = m_Position - Gatepos  ;
		Length = D3DXVec3Length(&m_change);
		if (Length < AVOID_GATE)
		{
			D3DXVec3Normalize(&m_change, &m_change);

			m_Vec1 += m_change*4;

		}
	}

	//m_Position += m_Vec1 * 2;




	//������
	m_center = D3DXVECTOR3(0,0,0);
	D3DXVECTOR3 Pos = D3DXVECTOR3(0, 0, 0);
	int enemyCnt = 0;
	//����
	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		if (enemy->GetUse() == true)
		{
			Pos = enemy->GetPosition();
			Pos = Pos - m_Position;
			Length = D3DXVec3Length(&Pos);
			if (Length <= LOOK_AREA)
			{
				enemyCnt++;
				m_center += enemy->GetRotation();
			}

		}

	}
	//�e�̂͌��������킹�悤�Ƃ���
	m_center /= enemyCnt;

	m_Rotation = m_center;

	
	//D3DXVec3Normalize(&m_center,&m_center);
	//D3DXVec3Length(&m_center);
	//m_Vec1 += m_center;
	//m_Position += m_Vec1 * 2;




	//����
	int Cnt = 0;
	//������
	m_center = D3DXVECTOR3(0,0,0);
	m_LastSheepcenter = m_Sheepcenter;

	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		if (enemy->GetUse() == true)
		{
			Pos = enemy->GetPosition();
			Pos = Pos - m_Position;
			Length = D3DXVec3Length(&Pos);
			if (Length <= LOOK_AREA)
			{
				m_center += enemy->GetPosition();
				Cnt++;
			}

		}

		
	
	}
	//m_center /= ENEMY_MAX;
	m_center /= Cnt;
	//�e�̂͌Q��̒��S�ֈړ����悤�Ƃ���
	m_Sheepcenter = m_center - m_Position;

	D3DXVec3Normalize(&m_centerNor, &m_Sheepcenter);
	//D3DXVec3Length(&m_change);
	m_Vec1 += m_centerNor*4;

	D3DXVECTOR3 move = D3DXVECTOR3(0.0f,0.0f,0.0f);
	////�ړ��ʉ��Z
	move = m_Vec1 ;
	//m_Position += (move - m_Position)*0.8f;
	//m_Position += move;


	//�p�j�s��
	//m_Vec1 = Wander(m_Position);

	//m_Position += Wander(m_Position);

	move += Wander(m_Position);
	D3DXVECTOR3 wallvec;
	//���E�̋��E
	if (Field->LimitField(m_Position + move) == true)
	{
		wallvec = Field->FieldNormal(m_Position + move);
		move += wallvec * 6;
		//move *= -1;
		//m_Position += move;

	}


	m_Position += move;



	//m_WanderTarget = m_Position;
	//�����Ă�����������킹��
	float LastSheepRot;
	LastSheepRot = m_Rotation.y;
	//�ω���
	float ConversionQuantity;
	//ConversionQuantity = atan2f(m_LastPosition.x-m_Position.x, m_LastPosition.z - m_Position.z);
	ConversionQuantity = atan2f(m_Position.x - m_LastPosition.x, m_Position.z - m_LastPosition.z);
	m_Rotation.y += (ConversionQuantity - LastSheepRot)*0.3f;
	//PrintDebugProc("�ry����]�F%f \n", m_Rotation.y);
	if (ConversionQuantity > D3DX_PI)
	{
		//m_Rotation.y = -D3DX_PI + (D3DX_PI - m_Rotation.y);
		m_Rotation.y -= D3DX_PI * 2;
	}
	else if (ConversionQuantity < -D3DX_PI)
	{
		//m_Rotation.y = -D3DX_PI - (D3DX_PI + m_Rotation.y);
		m_Rotation.y += D3DX_PI * 2;
	}

	//���e
	m_change = Gatepos - m_Position;
	Length = D3DXVec3Length(&m_change);
	if (Length < ENEMY_GATE && m_Use == true && m_Tracking == true)
	{
		m_Use = false;
		CEffect::Create("data/TEXTURE/explosion000.png", 8, 1, m_Position,100.0f,100.0f,m_tex);
		//CSoundGL::Start(SOUND_LABEL_SE_CRY, FALSE);
	}






	//PrintDebugProc("�G�l�~�[X���W�F%f  Y���W:%f  Z���W%f\n",m_Position.x,m_Position.y,m_Position.z);
}
D3DXVECTOR3 CEnemy::Wander(D3DXVECTOR3 Pos)
{
	
	
	float random = (1 / ((float)(rand() % 100) - 50.0f));
	//if (m_Cnt > 120)
	//{
	//	m_randvalue = 0;
	//	m_Cnt = 0;
	//}

	//�r�̈ʒu�Ɠ���
	m_WanderTarget.y = Pos.y;
	//m_WanderTarget = Pos;
	m_Cnt++;
	//if (m_Cnt > 1)
	//{
	//	m_WanderOldPos = D3DXVECTOR3((1 / ((float)(rand() % 100) - 50.0f))*m_WanderJitter, 0, (1 / ((float)(rand() % 100) - 50.0f))*m_WanderJitter);
	//	m_Cnt = 0;
	//}

	//�����_���̒l��ڕW�ɉ�����
	m_WanderTarget += D3DXVECTOR3((1 / ((float)(rand() % 100) - 50.0f))*m_WanderJitter, 0, (1 / ((float)(rand() % 100) - 50.0f))*m_WanderJitter);
	m_WanderTarget -= Pos;

	//�ڕW��p�j�~��ɍē��e����
	D3DXVec3Normalize(&m_WanderTarget, &m_WanderTarget);
	m_WanderTarget *= m_WanderRadius;
	m_WanderTarget += Pos;

	////�r�̌����Ă���������擾
	//double front = atan2f(m_Position.x - m_LastPosition.x, m_Position.z - m_LastPosition.z);

	////�ڕW��r�̑O��Distane�̗ʂ����ړ�����

	m_WanderPos = m_WanderTarget + D3DXVECTOR3(sinf(m_Rotation.y) * m_WanderDistance,0, cosf(m_Rotation.y)*m_WanderDistance);
	//m_WanderPos += m_WanderTarget ;
	//m_Target->SetPosition(m_WanderPos);


	//m_WanderPos = D3DXVECTOR3(m_WanderTarget.x + m_WanderDistance,0, m_WanderTarget.z  + m_WanderDistance );
	//m_WanderPos = D3DXVECTOR3(m_WanderTarget.x + (sinf(m_Rotation.y) * m_WanderDistance), 0, m_WanderTarget.z + (cosf(m_Rotation.y) * m_WanderDistance));
	//m_WanderPos = D3DXVECTOR3(sinf(m_Rotation.y) * m_WanderDistance, 0, cosf(m_Rotation.y*m_WanderDistance));
	//Pos = (m_WanderPos - m_WanderOldPos) *0.3f;
	
	m_WanderPos -= m_Position;
	D3DXVec3Normalize(&m_WanderPos,&m_WanderPos);
	
	return (m_WanderPos * 4 );
	//return m_WanderPos - Pos;
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

void CEnemy:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;

	/*��Ɨp�ϐ�*/
	D3DXMATRIX mtxView ;



	




	/*���[���h�}�g���N�X�̏�����*/
	D3DXMatrixIdentity ( & m_mtxWorld ) ;

	/*�r���[�}�g���N�X���擾*/
	pDevice ->GetTransform ( D3DTS_VIEW , & mtxView ) ;

	///*�t�s������߂�*/
	//D3DXMatrixInverse ( & m_mtxWorld , NULL , & mtxView ) ;

	//m_mtxWorld ._41 = 0.0f ;
	//m_mtxWorld ._42 = 0.0f ;
	//m_mtxWorld ._43 = 0.0f ;


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
	if (m_Use == true)
	{
		m_model->Draw();
		//m_Target->Draw();
	}






}