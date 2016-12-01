/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
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
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_center =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_change =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Vec1 =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rot = 0;
	m_Use = true;
	

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
	

	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();
	/*�Ίp���̒���*/
	m_fLengthbillboard = sqrtf ( ( Enemy_WIDTH * billboard_WIDTH ) + ( Enemy_HEIGHT * billboard_HEIGHT ) ) ;
	/*�p�x*/
	m_fAnglebillboard = atan2f ( Enemy_WIDTH , Enemy_HEIGHT ) ;

	m_model = new CModel;
	//���f���ǂݍ���
	m_model->Init("data/MODEL/Sheep.x",NULL);


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
	m_Position = D3DXVECTOR3 ( rand()%1500 , 0 , rand()%1500 ) ;
	//m_Vec1 = D3DXVECTOR3(rand()%5,0,rand()%5);
	EnemyLength =  rand()%100;
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


	if ( Shot == true )
	{
		Block = Player->GetBlock();

		Hit = Block->Use();
	}
	if ( Hit == true )
	{
		m_Position.x = PlayerPos .x - sinf ( m_fAnglebillboard + Rot  ) * m_fLengthbillboard ;
		m_Position.z = PlayerPos .z - sinf ( m_fAnglebillboard + Rot  ) * m_fLengthbillboard ;
	}
	else
	{
		m_Rot += 0.01f;
		//m_Position.x  += 10.0f * sin(D3DX_PI*m_Rot);
	}
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
	//&�v���C���[�Ƃ̂����蔻��
	PlayerPos = game->GetPlayer()->GetPosition();

	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		m_change = enemy->GetPosition();
		if(m_change != m_Position )
		{
			if (enemy->GetUse() == true)
			{
				m_change = m_change - m_Position;
				//����
				Length = D3DXVec3Length(&m_change);
				if (Length < EnemyLength)
				{

					D3DXVec3Normalize(&m_change, &m_change);
					//D3DXVec3Length(&m_change);

					m_Vec1 += -m_change;
				}
			}
			m_change = PlayerPos - m_Position;
			//�v���C���[
			//����
			Length = D3DXVec3Length(&m_change);

			if(Length < PLAYER_DISTANCE)
			{
				D3DXVec3Normalize(&m_change, &m_change);

				m_Vec1 += -m_change*0.1 ;

			}
			if (Length < PLAYER_DISTANCE+100.0f)
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
				m_change = Gatepos - m_Position;
				Length = D3DXVec3Length(&m_change);
				if (Length < AVOID_GATE)
				{
					D3DXVec3Normalize(&m_change, &m_change);

					m_Vec1 += -m_change*0.1;

				}
			}


		}
	}
	//m_Position += m_Vec1 * 2;




	//������
	m_center = D3DXVECTOR3(0,0,0);
	//����
	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		m_center += enemy->GetVec();

	}
	//�e�̂͌��������킹�悤�Ƃ���
	m_center /= ENEMY_MAX;
	
	D3DXVec3Normalize(&m_center,&m_center);
	//D3DXVec3Length(&m_center);
	m_Vec1 += m_center;
	//m_Position += m_Vec1 * 2;




	//����

	//������
	m_center = D3DXVECTOR3(0,0,0);
	m_LastSheepcenter = m_Sheepcenter;

	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		m_center += enemy->GetPosition();
	
	}
	//center.x = center.x/ENEMY_MAX;
	//center.y = center.y/ENEMY_MAX;
	//center.z = center.z/ENEMY_MAX;
	m_center /= ENEMY_MAX;

	//�e�̂͌Q��̒��S�ֈړ����悤�Ƃ���
	m_Sheepcenter = m_center - m_Position;

	D3DXVec3Normalize(&m_centerNor, &m_Sheepcenter);
	//D3DXVec3Length(&m_change);
	m_Vec1 += m_centerNor;


	////�ړ��ʉ��Z
	m_Position += m_Vec1*4 ;


	//���E�̋��E
	if (Field->LimitField(m_Position) == true )
	{
		m_Position += -(m_Vec1*10);
	}
	//���e
	m_change = Gatepos - m_Position;
	Length = D3DXVec3Length(&m_change);
	if (Length < ENEMY_GATE)
	{
		m_Use = false;
	}


	//�����Ă�����������킹��
	float LastSheepRot;
	LastSheepRot = m_Rotation.y;
	//�ω���
	float ConversionQuantity;
	ConversionQuantity = atan2f(m_LastPosition.x-m_Position.x, m_LastPosition.z - m_Position.z);
	m_Rotation.y += (ConversionQuantity - LastSheepRot)*0.5f;
	ConversionQuantity = fabs(fabs(m_Rotation.y) - fabs(LastSheepRot));
	if (ConversionQuantity < 0.1f)
	{
		//m_Rotation.y = LastSheepRot;
	}





	//PrintDebugProc("�G�l�~�[X���W�F%f  Y���W:%f  Z���W%f\n",m_Position.x,m_Position.y,m_Position.z);
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
	}





}