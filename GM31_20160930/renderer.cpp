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
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CRenderer::CRenderer()
{
	/*Direct3D�I�u�W�F�N�g�ւ̃|�C���^*/
	 m_pD3D = NULL  ;
	/*Direct3D�f�o�C�X�ւ̃|�C���^*/
	 m_pD3DDevice = NULL ;

	 m_WireFrame = false;

}
//�f�X�g���N�^
CRenderer::~CRenderer()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CRenderer :: Init ( HINSTANCE hInstance , HWND hWnd , BOOL bWindow ) 
{

	D3DPRESENT_PARAMETERS d3dpp ;
	D3DDISPLAYMODE d3ddm ;
	/*Direct3D�I�u�W�F�N�g�̐���*/
	m_pD3D = Direct3DCreate9 ( D3D_SDK_VERSION ) ;
	if ( m_pD3D == NULL )
	{
		return E_FAIL ;
	}
	/*�f�B�X�v���C���[�h���擾*/
	if (  ( m_pD3D ->GetAdapterDisplayMode ( D3DADAPTER_DEFAULT , & d3ddm ) ) )
	{
		return E_FAIL ;
	}
	/*������*/
	ZeroMemory ( & d3dpp , sizeof ( d3dpp ) ) ;
	/*��ʂ̕�����( �o�b�N�o�b�t�@ )*/
	d3dpp .BackBufferWidth = SCREEN_WIDTH ;
	d3dpp .BackBufferHeight = SCREEN_HEIGHT ;
	/*�o�b�N�o�b�t�@�̌`��*/
	d3dpp .BackBufferFormat = d3ddm .Format ;
	/*�o�b�N�o�b�t�@�̐�*/
	d3dpp .BackBufferCount = 1 ;
	d3dpp .SwapEffect = D3DSWAPEFFECT_DISCARD ;
	/*�f�v�X�o�b�t�@�ƃX�e���V���o�b�t�@���쐬����*/
	d3dpp .EnableAutoDepthStencil = TRUE ;
	/*�f�v�X�o�b�t�@�Ƃ���16�r�b�g�g�p����*/
	d3dpp .AutoDepthStencilFormat = D3DFMT_D16 ;
	/*�E�C���h�E���[�h/�t���X�N���[�����[�h*/
	d3dpp .Windowed = bWindow ;
	d3dpp .FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT ;
	d3dpp .PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT ;

	/*Direct3d�f�o�C�X�̐���*/
	if ( FAILED( m_pD3D ->CreateDevice ( D3DADAPTER_DEFAULT , D3DDEVTYPE_HAL , hWnd , D3DCREATE_HARDWARE_VERTEXPROCESSING , & d3dpp , & m_pD3DDevice ) ) )
	{
		if ( FAILED( m_pD3D ->CreateDevice ( D3DADAPTER_DEFAULT , D3DDEVTYPE_HAL , hWnd , D3DCREATE_SOFTWARE_VERTEXPROCESSING , & d3dpp , & m_pD3DDevice ) ) )
		{
			if ( FAILED( m_pD3D ->CreateDevice ( D3DADAPTER_DEFAULT , D3DDEVTYPE_REF , hWnd , D3DCREATE_SOFTWARE_VERTEXPROCESSING , & d3dpp , & m_pD3DDevice ) ) )
			{
				return E_FAIL ;
			}
		}
	}
	/*�����_�[�X�e�[�g�̐ݒ�*/
	m_pD3DDevice ->SetRenderState ( D3DRS_CULLMODE , D3DCULL_CCW ) ;
	m_pD3DDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
	m_pD3DDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
	m_pD3DDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;

	m_pD3DDevice ->SetTextureStageState (0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	m_pD3DDevice ->SetTextureStageState (0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pD3DDevice ->SetTextureStageState (0, D3DTSS_COLORARG2, D3DTA_CURRENT);




	return S_OK ;

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
void CRenderer::Uninit(void)
{
	if ( m_pD3DDevice != NULL )
	{
		m_pD3DDevice ->Release (  ) ;
		m_pD3DDevice = NULL ;
	}
	if ( m_pD3D != NULL )
	{
		m_pD3D ->Release (  ) ;
		m_pD3D = NULL ;
	}
}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CRenderer::Update(void)
{
	//CInput *Input;
	//Input = GetManager()->GetInput();

	//if ( Input->GetKeyboardTrigger(DIK_F8) )m_WireFrame =! m_WireFrame;
	//m_WireFrame ? m_pD3DDevice -> SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME) : m_pD3DDevice -> SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);


}
/*******************************************************************************
*
*	�`��
*
*
*******************************************************************************/
void CRenderer::Draw(void)
{

}
/*******************************************************************************
*
*	�`��J�n
*
*
*******************************************************************************/
void CRenderer::Begin(void)
{
	/*��ʂ̃N���A*/
	/**********************************�����ꏊ***********���s*****************�w�i�F( 0�`255 )*********R    G   B   ��(�����x)*/
	m_pD3DDevice ->Clear ( 0 , NULL , ( D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER ) , D3DCOLOR_RGBA ( 255 ,255 , 255 , 0 ) , 1.0f , 0 ) ;


	m_pD3DDevice ->BeginScene();

}
/*******************************************************************************
*
*	�`��I��
*
*
*******************************************************************************/
void CRenderer::End(void)
{
	/*�`��I��*/
	m_pD3DDevice ->EndScene (  ) ;
	/*�o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�̓���ւ�*/
	m_pD3DDevice ->Present ( NULL , NULL , NULL , NULL ) ;

}

/*******************************************************************************
*
*	�f�o�C�X�̎擾�֐�
*	���� : ����
*	�߂�l : g_pD3DDevice
*******************************************************************************/
LPDIRECT3DDEVICE9 CRenderer:: GetDevice ( void )
{
	return m_pD3DDevice ;
}


