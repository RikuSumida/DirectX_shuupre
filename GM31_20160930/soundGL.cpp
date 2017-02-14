/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "al.h"
#include "alut.h"


ALuint CSoundGL::m_buffer[SOUND_NUM], CSoundGL::m_source[SOURCE_NUM];

//�R���X�g���N�^
CSoundGL::CSoundGL()
{
}
//�f�X�g���N�^
CSoundGL::~CSoundGL()
{
}

//������
void CSoundGL::Init(void)
{
    alutInit(NULL, NULL);

}
//�ǂݍ���
void CSoundGL::Load(void)
{
	alGenBuffers( SOUND_NUM, m_buffer );
	alGenSources( SOURCE_NUM, m_source );
	//m_buffer[0] = alutCreateBufferHelloWorld(); 

	m_buffer[0] = alutCreateBufferFromFile("data/BGM/game.wav");
	m_buffer[1] = alutCreateBufferFromFile("data/SE/Enemycapture.wav");
	m_buffer[2] = alutCreateBufferFromFile("data/SE/fue.wav");
	m_buffer[3] = alutCreateBufferFromFile("data/SE/enter.wav");
	m_buffer[4] = alutCreateBufferFromFile("data/SE/sheep-cry1.wav");

}
//�Đ�
void CSoundGL::Start(SOUND_LABEL label, bool Loop)
{
	int i;
	// ��ԕϐ�
	ALint state[SOURCE_NUM];

	for ( i = 0 ; i<SOURCE_NUM;i++)
	{
		// �\�[�X�̏�Ԃ��擾
		alGetSourcei(m_source[i], AL_SOURCE_STATE, &state[i]);

		//�g����\�[�X��?
		if ( state[i] != AL_PLAYING )
		{
			alSourcei(m_source[i], AL_BUFFER, m_buffer[label]); // ���f�[�^�̃o�b�t�@���w��
			if (Loop==true)
			{
				alSourcei(m_source[i], AL_LOOPING, AL_TRUE); // ���[�v�̐ݒ�

			}
			else
			{
				alSourcei(m_source[i], AL_LOOPING, AL_FALSE); // ���[�v�̐ݒ�
			}

			alSourcePlay(m_source[i]);
			break;

		}
	}
 
 

 	//alSourcei(m_source[i], AL_LOOPING, AL_FALSE); // ���[�v�̐ݒ�
 

}
//�I��
void CSoundGL::Uninit(void)
{
	alDeleteBuffers(SOUND_NUM,&m_buffer[0]);
	alDeleteSources(SOURCE_NUM,&m_source[0]);
	alutExit();
}
