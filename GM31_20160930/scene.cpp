/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "scene.h"
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
CScene *CScene::m_Top[PRIORITY_NUM];
CScene *CScene::m_Cur[PRIORITY_NUM];
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CScene::CScene(int Priority)
{
	//���X�g�ɒǉ�
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
//�f�X�g���N�^
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
//�X�V
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
			//���̃N���X�̃|�C���^�i�[
			Scene_Next = Scene->m_Next;

			Scene->Update();

			//���̃N���X�̃|�C���^
			Scene = Scene_Next;
			//Scene = NULL;
		}
	}
}
//�`��
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
//�I��
void CScene::UninitAll(void)
{
	for (int i = 0 ; i<PRIORITY_NUM ; i++)
	{

		CScene *Scene = m_Top[i];
		CScene *Scene_Next;
		while ( Scene != NULL )
		{
			//���̃N���X�̃|�C���^�i�[
			Scene_Next = Scene->m_Next;

			//�I��
			Scene->Uninit();
			//���݂̃N���X��j��
			delete Scene;
			Scene = NULL;
			//���̃N���X�̃|�C���^
			Scene = Scene_Next;
			//Scene = NULL;



			//if ( Scene_Next != NULL )
			//{
			//	//�I��
			//	Scene->Uninit();
			//	//���݂̃N���X��j��
			//	delete Scene;
			//	Scene = NULL;
			//	//���̃N���X�̃|�C���^
			//	Scene = Scene_Next;
			//}
			////�Ō�̎�
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
//�ʂɏ���
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

//�擾�֐�
D3DXVECTOR3 CScene::GetPosition(void)
{
	return m_Position;
}

D3DXVECTOR3 CScene::GetRotation(void)
{
	return m_Rotation;
}




