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
CBillbord *Billbord;
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CBillbord::CBillbord(int Priority):CScene3D(Priority)
{
	/*�e�N�X�`���ւ̃|�C���^*/
	m_pTexturePolygon = NULL ;
	/*���_�o�b�t�@�ւ̃|�C���^*/
	m_pVtxBuffPolygon = NULL ;
	
	m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;

	m_Rot = 0;

}
//�f�X�g���N�^
CBillbord::~CBillbord()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CBillbord:: Init ( void )
{
	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();
	/*�Ίp���̒���*/
	m_fLengthbillboard = sqrtf ( ( billboard_WIDTH * billboard_WIDTH ) + ( billboard_HEIGHT * billboard_HEIGHT ) ) ;
	/*�p�x*/
	m_fAnglebillboard = atan2f ( billboard_WIDTH , billboard_HEIGHT ) ;


	/*�e�N�X�`���̓ǂݍ���*/
	D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/gauge.png" , & m_pTexturePolygon ) ;
	for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	{
		/*���_�o�b�t�@�̐���*                        �m�ۂ���o�b�t�@�T�C�Y                         �g�p���钸�_�t�H�[�}�b�g*/
		if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_3D ) * 4 , D3DUSAGE_WRITEONLY , FVF_VERTEX_3D , D3DPOOL_MANAGED , & m_pVtxBuffPolygon  , NULL ) ) )
		{
			return E_FAIL ;
		}
	}

	/*�������m��*/
	m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;
	pVtx [ 0 ].pos .x = m_Position .x - sinf ( m_fAnglebillboard + m_Rotation .z  ) * m_fLengthbillboard ;
	pVtx [ 0 ].pos .y = 100.0f;//g_posbillboard .y - cosf ( g_fAnglebillboard + g_rotbillboard .z  ) * g_fLengthbillboard ;
	pVtx [ 0 ].pos .z = 0.0f ;
	pVtx [ 1 ].pos .x = m_Position .x + sinf ( m_fAnglebillboard + m_Rotation .z  ) * m_fLengthbillboard ;
	pVtx [ 1 ].pos .y = 100.0f;//g_posbillboard .y - cosf ( g_fAnglebillboard + g_rotbillboard .z  ) * g_fLengthbillboard ;
	pVtx [ 1 ].pos .z = 0.0f ;
	pVtx [ 2 ].pos .x = m_Position .x - sinf ( m_fAnglebillboard - m_Rotation .z  ) * m_fLengthbillboard ;
	pVtx [ 2 ].pos .y = 0;//g_posbillboard .y + cosf ( g_fAnglebillboard - g_rotbillboard .z  ) * g_fLengthbillboard ;
	pVtx [ 2 ].pos .z = 0.0f ;
	pVtx [ 3 ].pos .x = m_Position .x + sinf ( m_fAnglebillboard - m_Rotation .z ) * m_fLengthbillboard ;
	pVtx [ 3 ].pos .y = 0;//g_posbillboard .y + cosf ( g_fAnglebillboard - g_rotbillboard .z ) * g_fLengthbillboard ;
	pVtx [ 3 ].pos .z = 0.0f ;


	pVtx [ 0 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	pVtx [ 1 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	pVtx [ 2 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	pVtx [ 3 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;

	/*���_�J���[*/

	pVtx [ 0 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	pVtx [ 1 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	pVtx [ 2 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	pVtx [ 3 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	/*�e�N�X�`�����W*******************   U     V   */
	pVtx [ 0 ].tex = D3DXVECTOR2 ( 0.125f , 0.0f ) ;
	pVtx [ 1 ].tex = D3DXVECTOR2 ( 0.25 , 0.0f ) ;
	pVtx [ 2 ].tex = D3DXVECTOR2 ( 0.125f , 1 ) ;
	pVtx [ 3 ].tex = D3DXVECTOR2 ( 0.25 , 1 ) ;
	/*���*/
	m_pVtxBuffPolygon  ->Unlock ( ) ;
	m_Position = D3DXVECTOR3 ( 750 , 100 , 750 ) ;
	return S_OK ;

}
//����
CBillbord* CBillbord::Create(void)
{
	//CBillbord *Billbord;
	Billbord = new CBillbord ;
	Billbord ->Init();

	return Billbord;

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
void CBillbord::Uninit(void)
{
	for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	{
		/*���_�o�b�t�@�̉��*/
		if ( m_pVtxBuffPolygon  != NULL )
		{
			m_pVtxBuffPolygon ->Release ( ) ;
			m_pVtxBuffPolygon  = NULL ;
		}
		
		/*���_�o�b�t�@�̉��*/
		if ( m_pTexturePolygon  != NULL )
		{
			m_pTexturePolygon ->Release ( ) ;
			m_pTexturePolygon  = NULL ;
		}

	}

}

/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CBillbord::Update(void)
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
		//m_Position.x  += 30.0f * sin(D3DX_PI*m_Rot);
	}

	//PrintDebugProc("�G�l�~�[X���W�F%f  Y���W:%f  Z���W%f",m_Position.x,m_Position.y,m_Position.z);
}
void CBillbord::SetPosition(D3DXVECTOR3 Pos)
{
	m_Position = Pos;
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

void CBillbord:: Draw ( void )
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

	/*�t�s������߂�*/
	D3DXMatrixInverse ( & m_mtxWorld , NULL , & mtxView ) ;

	m_mtxWorld ._41 = 0.0f ;
	m_mtxWorld ._42 = 0.0f ;
	m_mtxWorld ._43 = 0.0f ;


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



	/*���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h*/
	pDevice  ->SetStreamSource ( 0 , m_pVtxBuffPolygon , 0 , sizeof ( VERTEX_3D ) ) ;
	/*�|���S���`��*/
	/*���_�t�H�[�}�b�g�̐ݒ�*/
	pDevice ->SetFVF ( FVF_VERTEX_3D ) ;
	/*�e�N�X�`���̐ݒ�*/
	pDevice  ->SetTexture ( 0 , m_pTexturePolygon ) ;

	pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , TRUE ) ;
	pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_GREATER ) ;
	pDevice ->SetRenderState ( D3DRS_ALPHAREF , 30 ) ;


	/*�|���S���`��*/
	/******************************�|���S���̎��****�`�悷��v���~�e�B�u��**�f�[�^�̐擪�A�h���X**�f�[�^�Ԋu*/
	pDevice ->DrawPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , PRIMITIVE ) ;

	pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , FALSE ) ;
	pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_ALWAYS ) ;
	pDevice ->SetRenderState ( D3DRS_ALPHAREF , 0 ) ;
	//pDevice ->SetRenderState ( D3DRS_CULLMODE , D3DCULL_CCW ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
	//pDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
	//pDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;


}
