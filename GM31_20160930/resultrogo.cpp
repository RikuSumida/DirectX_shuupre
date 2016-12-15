/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "score.h"
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
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CResultRogo::CResultRogo(int Priority):CScene(Priority)
{
	/*�e�N�X�`���ւ̃|�C���^*/
	m_pTexturePolygon = NULL ;
	/*���_�o�b�t�@�ւ̃|�C���^*/
	m_pVtxBuffPolygon = NULL ;

}
//�f�X�g���N�^
CResultRogo::~CResultRogo()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CResultRogo:: Init ( void )
{
	VERTEX_2D *pVtx ;

	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();



	/*�e�N�X�`���̓ǂݍ���*/
	int EnemyCnt = GetEnemyNum();
	CScore::Create(D3DXVECTOR3(450.0f,350.0f,0.0f), D3DXVECTOR3(200.0f, 350.0f, 0.0f), EnemyCnt);
	CScore::Create(D3DXVECTOR3(1000.0f, 350.0f, 0.0f), D3DXVECTOR3(800.0f, 350.0f, 0.0f), ENEMY_MAX);

	if(EnemyCnt > 15)
	{
		//D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/clear.png" , & m_pTexturePolygon ) ;
	}
	else
	{
		//D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/failed.png" , & m_pTexturePolygon ) ;
	}
	for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	{
		/*���_�o�b�t�@�̐���*                        �m�ۂ���o�b�t�@�T�C�Y                         �g�p���钸�_�t�H�[�}�b�g*/
		if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_2D ) * 4 , D3DUSAGE_WRITEONLY , FVF_VERTEX_2D , D3DPOOL_MANAGED , & m_pVtxBuffPolygon  , NULL ) ) )
		{
			return E_FAIL ;
		}
	}

	/*�������m��*/
	m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;
	/*���_���W*/
	pVtx [ 0 ].pos = D3DXVECTOR3 ( 0.0f , 0.0f ,0.0f ) ;
	pVtx [ 1 ].pos = D3DXVECTOR3 ( SCREEN_WIDTH , 0.0f ,0.0f ) ;
	pVtx [ 2 ].pos = D3DXVECTOR3 ( 0.0f , SCREEN_HEIGHT ,0.0f ) ;
	pVtx [ 3 ].pos = D3DXVECTOR3 ( SCREEN_WIDTH , SCREEN_HEIGHT ,0.0f ) ;


	/*���W�ϊ��p�֐�*/
	pVtx [ 0 ].rhw = 1.0f ;
	pVtx [ 1 ].rhw = 1.0f ;
	pVtx [ 2 ].rhw = 1.0f ;
	pVtx [ 3 ].rhw = 1.0f ;
	/*���_�J���[*/
	pVtx [ 0 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	pVtx [ 1 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	pVtx [ 2 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	pVtx [ 3 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
	/*�e�N�X�`�����W*******************   U     V   */
	pVtx [ 0 ].tex = D3DXVECTOR2 ( 0.0f , 0.0f ) ;
	pVtx [ 1 ].tex = D3DXVECTOR2 ( 1 , 0.0f ) ;
	pVtx [ 2 ].tex = D3DXVECTOR2 ( 0.0f , 1 ) ;
	pVtx [ 3 ].tex = D3DXVECTOR2 ( 1 , 1 ) ;
	/*���*/
	m_pVtxBuffPolygon  ->Unlock ( ) ;
	return S_OK ;

}
//����
CResultRogo* CResultRogo::Create(void)
{
	CResultRogo *Scene2D;
	Scene2D = new CResultRogo ;
	Scene2D ->Init();

	return Scene2D;

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
void CResultRogo::Uninit(void)
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
void CResultRogo::Update(void)
{
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

void CResultRogo:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	/*���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h*/
	pDevice  ->SetStreamSource ( 0 , m_pVtxBuffPolygon , 0 , sizeof ( VERTEX_2D ) ) ;
	/*�|���S���`��*/
	/*���_�t�H�[�}�b�g�̐ݒ�*/
	pDevice ->SetFVF ( FVF_VERTEX_2D ) ;
	/*�e�N�X�`���̐ݒ�*/
	pDevice  ->SetTexture ( 0 , m_pTexturePolygon ) ;

	//pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , TRUE ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_GREATER ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAREF , 30 ) ;


	/*�|���S���`��*/
	/******************************�|���S���̎��****�`�悷��v���~�e�B�u��**�f�[�^�̐擪�A�h���X**�f�[�^�Ԋu*/
	pDevice ->DrawPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , PRIMITIVE ) ;

	//pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , FALSE ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_ALWAYS ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAREF , 0 ) ;



}
