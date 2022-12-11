#include "IndexBuffer.h"
#include "glad/glad.h"
#include "../Graphics/Renderer.h"


IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
	:
	m_Count(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	GLCall(glGenBuffers(1, &m_RenderID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));

}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_RenderID));
}

void IndexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));

}

void IndexBuffer::Unbind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
