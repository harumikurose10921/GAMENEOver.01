
/*!
*@brief	�C���f�b�N�X�o�b�t�@
*/
#ifndef _INDEXBUFFER_H_
#define _INDEXBUFFER_H_
#include <d3d9.h>
class IndexBuffer{
public:
	IndexBuffer();
	~IndexBuffer();
	/*!
	*@brief	�C���f�b�N�X�o�b�t�@�̍쐬�B
	*@param[in]	numIndex		�C���f�b�N�X�̐�
	*@param[in]	format			�C���f�b�N�X�o�b�t�@�̃t�H�[�}�b�g�B
	*@param[in]	pSrcIndexBuffer	�\�[�X�C���f�b�N�X�o�b�t�@�B�쐬���ꂽ�C���f�b�N�X�o�b�t�@�ɃR�s�[����܂��BNULL���w��\�B
	*/
	void Create(int numIndex, D3DFORMAT format, const void* pSrcIndexBuffer);
	/*!
	*@brief	�C���f�b�N�X�o�b�t�@�̉���B
	*/
	void Release();
	/*!
	*@brief	LPDIRECT3DINDEXBUFFER9�̎擾�B
	*/
	LPDIRECT3DINDEXBUFFER9 GetBody()
	{
		return m_pIB;
	}
private:
	LPDIRECT3DINDEXBUFFER9	m_pIB;	//!<�C���f�b�N�X�o�b�t�@�B
};
#endif //_INDEXBUFFER_H_