#pragma once
class VertexBuffer
{

private:
	unsigned int m_RenderID;

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind();
	void Unbind();
};

