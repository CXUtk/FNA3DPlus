#pragma once
#include <memory>
#include <vector>

class IVertexShader;
class IPixelShader;
class IComputeShader;
class IGeometryShader;
class IDomainShader;
class IHullShader;

class IConstBuffer;
class IRasterState;
class IDepthStencilState;
class IBlendState;

class IVertexBuffer;
class IIndexBuffer;

class IShaderResource;

class IGraphicsContext
{
public:
	virtual ~IGraphicsContext() = 0 {};

	virtual void SetVertexShader(std::shared_ptr<IVertexShader> vertexShader) = 0;
	virtual void SetPixelShader(std::shared_ptr<IPixelShader> pixelShader) = 0;
	virtual void SetComputeShader(std::shared_ptr<IComputeShader> computeShader) = 0;
	virtual void SetGeometryShader(std::shared_ptr<IGeometryShader> geometryShader) = 0;
	virtual void SetDomainShader(std::shared_ptr<IDomainShader> domainShader) = 0;
	virtual void SetHullShader(std::shared_ptr<IHullShader> hullShader) = 0;

	virtual void SetVertexBuffer(std::shared_ptr<IVertexBuffer> vertexBuffer) = 0;
	virtual void SetIndexBuffer(std::shared_ptr<IIndexBuffer> indexBuffer) = 0;

	virtual void SetConstantBuffer(int start, int size, const std::vector<IConstBuffer>& buffers) = 0;
	virtual void SetShaderResource(int start, int size, const std::vector<IShaderResource>& shaderResources) = 0;

};