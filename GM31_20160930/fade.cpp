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
CMode* CFade::m_NextMode;
int CFade::m_Count;
FADE CFade::m_State;
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CFade::CFade()
{
	/*�e�N�X�`���ւ̃|�C���^*/
	m_pTexturePolygon = NULL ;
	/*���_�o�b�t�@�ւ̃|�C���^*/
	m_pVtxBuffPolygon = NULL ;

	m_Count = 0;
	m_NextMode = NULL;
	m_Alpha = 0;

	m_State = FADE_NONE;

}
//�f�X�g���N�^
CFade::~CFade()
{
}
//����
CFade* CFade::Create(void)
{
	CFade *Fade;
	Fade = new CFade ;
	Fade ->Init();

	return Fade;

}


//�J�n
void CFade::Start(CMode* NextMode)
{
	m_NextMode = NextMode;
	m_State = FADE_OUT;
	m_Count = 0;
}

//�X�V
HRESULT CFade::Init(void)
{
	VERTEX_2D *pVtx ;

	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();



	/*�e�N�X�`���̓ǂݍ���*/
	//D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/bullet000.png" , & m_pTexturePolygon ) ;
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
	pVtx [ 0 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , 0 ) ;
	pVtx [ 1 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , 0 ) ;
	pVtx [ 2 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , 0 ) ;
	pVtx [ 3 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , 0 ) ;
	/*�e�N�X�`�����W*******************   U     V   */
	//pVtx [ 0 ].tex = D3DXVECTOR2 ( 0.0f , 0.0f ) ;
	//pVtx [ 1 ].tex = D3DXVECTOR2 ( 1 , 0.0f ) ;
	//pVtx [ 2 ].tex = D3DXVECTOR2 ( 0.0f , 1 ) ;
	//pVtx [ 3 ].tex = D3DXVECTOR2 ( 1 , 1 ) ;
	/*���*/
	m_pVtxBuffPolygon  ->Unlock ( ) ;
	return S_OK ;

}
//�`��
void CFade::Uninit(void)
{
}
//�I��
void CFade::Update(void)
{
	VERTEX_2D *pVtx ;
	if (m_State != FADE_NONE)
	{
		switch (m_State)
		{
		case FADE_OUT:
			m_Alpha +=2;
			if ( m_Alpha > 255 )
			{
				CManager::SetMode(m_NextMode);
				m_State = FADE_IN;
				m_Count = 0;
				m_Alpha = 255;
			}


			break;
		case FADE_IN:

			m_Alpha -=2;

			if ( m_Alpha < 0)
			{
				m_Alpha = 0;
				m_State = FADE_NONE;
			}

			break;
		}
		//m_Count ++;
	}

	/*�������m��*/
	m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;

	/*���_�J���[*/
	pVtx [ 0 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , m_Alpha ) ;
	pVtx [ 1 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , m_Alpha ) ;
	pVtx [ 2 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , m_Alpha ) ;
	pVtx [ 3 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , m_Alpha ) ;
	/*���*/
	m_pVtxBuffPolygon  ->Unlock ( ) ;



}
//�ʂɏ���
void CFade::Draw(void)
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
	pDevice  ->SetTexture ( 0 , NULL ) ;

	//pDevice ->SetRenderState ( D3DRS_CULLMODE , D3DCULL_CCW ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
	//pDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
	//pDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;


	/*�|���S���`��*/
	/******************************�|���S���̎��****�`�悷��v���~�e�B�u��**�f�[�^�̐擪�A�h���X**�f�[�^�Ԋu*/
	pDevice ->DrawPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , PRIMITIVE ) ;

	//pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , FALSE ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_ALWAYS ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAREF , 0 ) ;

}
