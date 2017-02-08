
/*!
*@brief �v���~�e�B�u�B
*/
#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include<d3d9.h>
/*!
* @brief�@�v���~�e�B�u�B
*/
class Primitive {
public:
	/*!
	*@brief �v���~�e�B�u�^�C�v�B
	*/
	enum EType {
		eTriangleList,
		eTriangleStrip,
		etypeNum,
	};
public:
	/*!
	* @brief �R���X�g���N�^�B
	*/
	Primitive();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~Primitive();
	/*!
	*@brief	�v���~�e�B�u�̍쐬�B
	*@param[in]	primitiveType		�v���~�e�B�u�^�C�v�B
	*@param[in]	numVertex			���_��
	*@param[in]	vertexStride		���_�X�g���C�h
	*@param[in]	vertexLayout		���_���C�A�E�g�BEVertexFormat�̘_���a��n���B
	*@param[in]	pSrcVertexBuffer	�\�[�X���_�o�b�t�@�B
	*@param[in]	numIndex			�C���f�b�N�X�̐�
	*@param[in]	indexFormat			�C���f�b�N�X�o�b�t�@�̃t�H�[�}�b�g�B
	*@param[in]	pSrcIndexBuffer		�\�[�X�C���f�b�N�X�o�b�t�@�B
	*/
	void Create(
		EType 					primitiveType,
		int 					numVertex,
		int 					vertexStride,
		const D3DVERTEXELEMENT9* vertexLayout,
		void*					pSrcVertexBuffer,
		int 					numIndex,
		D3DFORMAT				indexFormat,
		void*					pSrcIndexbuffer
	);
	/*!
	* @brief	�����[�X�B
	*/
	void Release();
	/*!
	* @brief	���_�o�b�t�@�̎擾�B
	*/
	VertexBuffer* GetVertexBuffer()
	{
		return &m_vertexBuffer;
	}
	/*!
	* @brief	�C���f�b�N�X�o�b�t�@�̎擾�B
	*/
	IndexBuffer*  GetIndexBuffer()
	{
		return &m_indexBuffer;
	}
	/*!
	* @brief	D3DPRIMITIVETYPE���擾�B
	*/
	D3DPRIMITIVETYPE GetD3DPrimitiveType() const
	{
		return m_d3dPrimitiveType;
	}
	/*!
	* @brief	���_�����擾�B
	*/
	int GetNumVertex() const
	{
		return m_numVertex;
	}
	/*!
	* @brief	�|���S�������擾�B
	*/
	int GetNumPolygon() const
	{
		return m_numPolygon;
	}
	/*!
	* @brief	���_��`���擾�B
	*/
	IDirect3DVertexDeclaration9* GetVertexDecl()
	{
		return m_vertexBuffer.GetVertexDecl();
	}
private:
	int					m_numVertex;		//!<���_���B
	int					m_vertexStride;		//!<���_�X�g���C�h�B
	int					m_numIndex;			//!<�C���f�b�N�X���B
	int					m_numPolygon;		//!<�|���S���̐��B
	VertexBuffer		m_vertexBuffer;		//!<���_�o�b�t�@�B
	IndexBuffer		m_indexBuffer;		//!<�C���f�b�N�X�o�b�t�@�B
	EType				m_type;				//!<�v���~�e�B�u�^�C�v�B
	D3DPRIMITIVETYPE	m_d3dPrimitiveType;	//!<D3DPRIMITIVETYPE�B
};

#endif //_PRIMIRIVE_H_