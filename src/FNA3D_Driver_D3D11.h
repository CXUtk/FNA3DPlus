/* FNA3D - 3D Graphics Library for FNA
 *
 * Copyright (c) 2020-2022 Ethan Lee
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software in a
 * product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * Ethan "flibitijibibo" Lee <flibitijibibo@flibitijibibo.com>
 *
 */

#ifndef FNA3D_DRIVER_D3D11_H
#define FNA3D_DRIVER_D3D11_H

#define D3D11_NO_HELPERS
//#define CINTERFACE
//#define COBJMACROS
#include <d3d11.h>

#include <d3dcompiler.h>
#include <d3dx11effect.h>


/* IID Imports from https://magnumdb.com */

static const IID D3D_IID_IDXGIFactory1 = {0x770aae78,0xf26f,0x4dba,{0xa8,0x29,0x25,0x3c,0x83,0xd1,0xb3,0x87}};
static const IID D3D_IID_IDXGIFactory2 = {0x50c83a1c,0xe072,0x4c48,{0x87,0xb0,0x36,0x30,0xfa,0x36,0xa6,0xd0}};
static const IID D3D_IID_IDXGIFactory6 = {0xc1b6694f,0xff09,0x44a9,{0xb0,0x3c,0x77,0x90,0x0a,0x0a,0x1d,0x17}};
static const IID D3D_IID_IDXGIAdapter1 = {0x29038f61,0x3839,0x4626,{0x91,0xfd,0x08,0x68,0x79,0x01,0x1a,0x05}};
static const IID D3D_IID_ID3D11Texture2D = {0x6f15aaf2,0xd208,0x4e89,{0x9a,0xb4,0x48,0x95,0x35,0xd3,0x4f,0x9c}};
static const IID D3D_IID_ID3DUserDefinedAnnotation = {0xb2daad8b,0x03d4,0x4dbf,{0x95,0xeb,0x32,0xab,0x4b,0x63,0xd0,0xab}};

/* VS2010 / DirectX SDK Fallback Defines */

#ifndef DXGI_FORMAT_B4G4R4A4_UNORM
#define DXGI_FORMAT_B4G4R4A4_UNORM (DXGI_FORMAT) 115
#endif

#ifndef D3D_FEATURE_LEVEL_11_1
#define D3D_FEATURE_LEVEL_11_1 (D3D_FEATURE_LEVEL) 0xb100
#endif

/* D3D Function Typedefs */

typedef HRESULT(WINAPI *PFN_D3DCOMPILE)(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    LPCSTR pSourceName,
    const D3D_SHADER_MACRO *pDefines,
    ID3DInclude *pInclude,
    LPCSTR pEntrypoint,
    LPCSTR pTarget,
    UINT Flags1,
    UINT Flags2,
    ID3DBlob **ppCode,
    ID3DBlob **ppErrorMsgs
);

/* ID3DUserDefinedAnnotation */
/* From d3d11_1.h, cleaned up a bit... */

//typedef struct ID3DUserDefinedAnnotation ID3DUserDefinedAnnotation;
//typedef struct ID3DUserDefinedAnnotationVtbl
//{
//	HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
//		ID3DUserDefinedAnnotation * This,
//		REFIID riid,
//		void **ppvObject);
//
//	ULONG ( STDMETHODCALLTYPE *AddRef )(
//		ID3DUserDefinedAnnotation * This);
//
//	ULONG ( STDMETHODCALLTYPE *Release )(
//		ID3DUserDefinedAnnotation * This);
//
//	INT ( STDMETHODCALLTYPE *BeginEvent )(
//		ID3DUserDefinedAnnotation * This,
//		LPCWSTR Name);
//
//        INT ( STDMETHODCALLTYPE *EndEvent )(
//            ID3DUserDefinedAnnotation * This);
//
//	void ( STDMETHODCALLTYPE *SetMarker )(
//		ID3DUserDefinedAnnotation * This,
//		LPCWSTR Name);
//
//	BOOL ( STDMETHODCALLTYPE *GetStatus )(
//		ID3DUserDefinedAnnotation * This);
//} ID3DUserDefinedAnnotationVtbl;
//
//struct ID3DUserDefinedAnnotation
//{
//	struct ID3DUserDefinedAnnotationVtbl *lpVtbl;
//};

#define ID3DUserDefinedAnnotation_QueryInterface(This,riid,ppvObject)	\
	( (This) -> QueryInterface(riid,ppvObject) )

#define ID3DUserDefinedAnnotation_AddRef(This)	\
	( (This) -> AddRef() )

#define ID3DUserDefinedAnnotation_Release(This)	\
	( (This) -> Release() )

#define ID3DUserDefinedAnnotation_BeginEvent(This,Name)	\
	( (This) -> BeginEvent(Name) )

#define ID3DUserDefinedAnnotation_EndEvent(This)	\
	( (This) -> EndEvent() )

#define ID3DUserDefinedAnnotation_SetMarker(This,Name)	\
	( (This) -> SetMarker(Name) )

#define ID3DUserDefinedAnnotation_GetStatus(This)	\
	( (This) -> GetStatus() )

/* IDXGIFactory6 */
/* From igdx1_6.h, cleaned up a bit... */

typedef enum
{
	DXGI_FEATURE_PRESENT_ALLOW_TEARING	= 0
} DXGI_FEATURE;

typedef enum
{
	DXGI_GPU_PREFERENCE_UNSPECIFIED	= 0,
	DXGI_GPU_PREFERENCE_MINIMUM_POWER	= ( DXGI_GPU_PREFERENCE_UNSPECIFIED + 1 ) ,
	DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE	= ( DXGI_GPU_PREFERENCE_MINIMUM_POWER + 1 ) 
} DXGI_GPU_PREFERENCE;

typedef struct IDXGIFactory6 IDXGIFactory6;
typedef struct IDXGIFactory6Vtbl
{
	HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
		IDXGIFactory6 * This,
		REFIID riid,
		void **ppvObject);
		
	ULONG ( STDMETHODCALLTYPE *AddRef )( 
		IDXGIFactory6 * This);
		
	ULONG ( STDMETHODCALLTYPE *Release )( 
		IDXGIFactory6 * This);
		
	HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
		IDXGIFactory6 * This,
		REFGUID Name,
		UINT DataSize,
		const void *pData);
		
	HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
		IDXGIFactory6 * This,
		REFGUID Name,
		const IUnknown *pUnknown);
		
	HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
		IDXGIFactory6 * This,
		REFGUID Name,
		UINT *pDataSize,
		void *pData);
		
	HRESULT ( STDMETHODCALLTYPE *GetParent )( 
		IDXGIFactory6 * This,
		REFIID riid,
		void **ppParent);
		
	HRESULT ( STDMETHODCALLTYPE *EnumAdapters )( 
		IDXGIFactory6 * This,
		UINT Adapter,
		IDXGIAdapter **ppAdapter);
		
	HRESULT ( STDMETHODCALLTYPE *MakeWindowAssociation )( 
		IDXGIFactory6 * This,
		HWND WindowHandle,
		UINT Flags);
		
	HRESULT ( STDMETHODCALLTYPE *GetWindowAssociation )( 
		IDXGIFactory6 * This,
		HWND *pWindowHandle);
		
	HRESULT ( STDMETHODCALLTYPE *CreateSwapChain )( 
		IDXGIFactory6 * This,
		IUnknown *pDevice,
		DXGI_SWAP_CHAIN_DESC *pDesc,
		IDXGISwapChain **ppSwapChain);
		
	HRESULT ( STDMETHODCALLTYPE *CreateSoftwareAdapter )( 
		IDXGIFactory6 * This,
		HMODULE Module,
		IDXGIAdapter **ppAdapter);
		
	HRESULT ( STDMETHODCALLTYPE *EnumAdapters1 )( 
		IDXGIFactory6 * This,
		UINT Adapter,
		IDXGIAdapter1 **ppAdapter);
		
	BOOL ( STDMETHODCALLTYPE *IsCurrent )( 
		IDXGIFactory6 * This);
		
	BOOL ( STDMETHODCALLTYPE *IsWindowedStereoEnabled )( 
		IDXGIFactory6 * This);
		
	HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForHwnd )( 
		IDXGIFactory6 * This,
		IUnknown *pDevice,
		HWND hWnd,
		void *pDesc,
		void *pFullscreenDesc,
		void *pRestrictToOutput,
		void **ppSwapChain);
		
	HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForCoreWindow )( 
		IDXGIFactory6 * This,
		IUnknown *pDevice,
		IUnknown *pWindow,
		void *pDesc,
		void *pRestrictToOutput,
		void **ppSwapChain);
		
	HRESULT ( STDMETHODCALLTYPE *GetSharedResourceAdapterLuid )( 
		IDXGIFactory6 * This,
		HANDLE hResource,
		LUID *pLuid);
		
	HRESULT ( STDMETHODCALLTYPE *RegisterStereoStatusWindow )( 
		IDXGIFactory6 * This,
		HWND WindowHandle,
		UINT wMsg,
		DWORD *pdwCookie);
		
	HRESULT ( STDMETHODCALLTYPE *RegisterStereoStatusEvent )( 
		IDXGIFactory6 * This,
		HANDLE hEvent,
		DWORD *pdwCookie);
		
	void ( STDMETHODCALLTYPE *UnregisterStereoStatus )( 
		IDXGIFactory6 * This,
		DWORD dwCookie);
		
	HRESULT ( STDMETHODCALLTYPE *RegisterOcclusionStatusWindow )( 
		IDXGIFactory6 * This,
		HWND WindowHandle,
		UINT wMsg,
		DWORD *pdwCookie);
		
	HRESULT ( STDMETHODCALLTYPE *RegisterOcclusionStatusEvent )( 
		IDXGIFactory6 * This,
		HANDLE hEvent,
		DWORD *pdwCookie);
		
	void ( STDMETHODCALLTYPE *UnregisterOcclusionStatus )( 
		IDXGIFactory6 * This,
		DWORD dwCookie);
		
	HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForComposition )( 
		IDXGIFactory6 * This,
		IUnknown *pDevice,
		void *pDesc,
		void *pRestrictToOutput,
		void **ppSwapChain);
		
	UINT ( STDMETHODCALLTYPE *GetCreationFlags )( 
		IDXGIFactory6 * This);
		
	HRESULT ( STDMETHODCALLTYPE *EnumAdapterByLuid )( 
		IDXGIFactory6 * This,
		LUID AdapterLuid,
		REFIID riid,
		void **ppvAdapter);
		
	HRESULT ( STDMETHODCALLTYPE *EnumWarpAdapter )( 
		IDXGIFactory6 * This,
		REFIID riid,
		void **ppvAdapter);
		
	HRESULT ( STDMETHODCALLTYPE *CheckFeatureSupport )( 
		IDXGIFactory6 * This,
		DXGI_FEATURE Feature,
		void *pFeatureSupportData,
		UINT FeatureSupportDataSize);
		
	HRESULT ( STDMETHODCALLTYPE *EnumAdapterByGpuPreference )( 
		IDXGIFactory6 * This,
		UINT Adapter,
		DXGI_GPU_PREFERENCE GpuPreference,
		REFIID riid,
		void **ppvAdapter);
} IDXGIFactory6Vtbl;

struct IDXGIFactory6
{
	struct IDXGIFactory6Vtbl *lpVtbl;
};

#define IDXGIFactory6_EnumAdapterByGpuPreference(This,Adapter,GpuPreference,riid,ppvAdapter)	\
	( (This)->lpVtbl -> EnumAdapterByGpuPreference(This,Adapter,GpuPreference,riid,ppvAdapter) ) 

FX11API ID3DX11EffectVariable* FX11_Effect_GetVariableByName(
	FNA3D_Effect_New* effect,
	const char* name
); 

FX11API ID3DX11EffectVariable* FX11_Effect_GetVariableByIndex(
	FNA3D_Effect_New* effect,
	uint32_t index
);


FX11API ID3DX11EffectVariable* FX11_Effect_GetVariableBySemantic(
	FNA3D_Effect_New* effect,
	const char* semantic
);

FX11API ID3DX11EffectTechnique* FX11_Effect_GetTechniqueByIndex(
	FNA3D_Effect_New* effect,
	uint32_t index
); 

FX11API ID3DX11EffectTechnique* FX11_Effect_GetTechniqueByName(
	FNA3D_Effect_New* effect,
	const char* name
); 

FX11API ID3DX11EffectPass* FX11_Effect_Technique_GetPassByIndex(
	ID3DX11EffectTechnique* technique,
	uint32_t index
);

FX11API ID3DX11EffectPass* FX11_Effect_Technique_GetPassByName(
	ID3DX11EffectTechnique* technique,
	const char* name
);

FX11API void FX11_Effect_Pass_Apply(
    FNA3D_Device* device,
	ID3DX11EffectPass* pass
); 


FX11API void FX11_Effect_Variable_SetUnorderedAccessView_ComputeBuffer(
	ID3DX11EffectVariable* variable,
	FNA3D_ComputeBuffer* computeBuffer
); 

FX11API void FX11_Effect_Variable_SetUnorderedAccessView_Texture(
    ID3DX11EffectVariable* variable,
    FNA3D_Texture* texture
);

FX11API void FX11_Effect_Variable_SetShaderResourceView_ComputeBuffer(
	ID3DX11EffectVariable* variable,
	FNA3D_ComputeBuffer* computeBuffer
); 

FX11API void FX11_Effect_Variable_SetShaderResourceView_Texture(
    ID3DX11EffectVariable* variable,
    FNA3D_Texture* texture
);

FX11API void FX11_Effect_Variable_SetInt(
	ID3DX11EffectVariable* variable,
	int value
);

FX11API void FX11_Effect_Variable_SetBool(
    ID3DX11EffectVariable* variable,
    bool value
);

FX11API void FX11_Effect_Variable_SetFloat(
    ID3DX11EffectVariable* variable,
    float value
);

FX11API void FX11_Effect_Variable_SetIntArray(
    ID3DX11EffectVariable* variable,
    const int* value,
    uint32_t offset,
    uint32_t length
);

FX11API void FX11_Effect_Variable_SetFloatArray(
    ID3DX11EffectVariable* variable,
    const float* value,
    uint32_t offset,
    uint32_t length
);

FX11API void FX11_Effect_Variable_SetVectorf(
    ID3DX11EffectVariable* variable,
    const float* valueArray 
);

FX11API void FX11_Effect_Variable_SetVectorb(
    ID3DX11EffectVariable* variable,
    const bool* valueArray
);

FX11API void FX11_Effect_Variable_SetVectori(
    ID3DX11EffectVariable* variable,
    const int* valueArray
);

//FX11API void FX11_Effect_Variable_SetVectorfArray(
//    ID3DX11EffectVariable* variable,
//    const float* value,
//    uint32_t length
//);
//
//FX11API void FX11_Effect_Variable_SetVectoriArray(
//    ID3DX11EffectVariable* variable,
//    const int* value,
//    uint32_t length
//);

FX11API void FX11_Effect_Variable_SetMatrix4f(
    ID3DX11EffectVariable* variable,
    const float* valueMatrix
);

FX11API void FX11_Effect_Variable_SetRawData(
    ID3DX11EffectVariable* variable,
    const void* pData,
    uint32_t byteOffset,
    uint32_t byteCount
);


struct EffectReflectionData
{
    D3DX11_EFFECT_DESC ShaderDesc;
    uint32_t ConstantBufferCount;
    D3DX11_EFFECT_VARIABLE_DESC* ConstantBufferDescs;
    D3DX11_EFFECT_VARIABLE_DESC* Variables;
    D3DX11_EFFECT_TYPE_DESC* VariableTypes;
    ID3DX11EffectVariable** PVarialbes;
    D3DX11_GROUP_DESC* Groups;
    D3DX11_TECHNIQUE_DESC* Techniques;
    ID3DX11EffectTechnique** PTechniques;
    D3DX11_PASS_DESC** Passes;
    ID3DX11EffectPass*** PPasses;
};

FX11API void FX11_Effect_CreateReflectionData(
    void* effect,
    EffectReflectionData* result
);

FX11API void FX11_Effect_ReleaseReflectionData(
    EffectReflectionData* data
);

#endif /* FNA3D_DRIVER_D3D11_H */


#ifndef COBJMACROS

#define ID3D11Device_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11Device_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11Device_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11Device_CreateBuffer(This,pDesc,pInitialData,ppBuffer)	\
    ( (This) -> CreateBuffer(pDesc,pInitialData,ppBuffer) ) 

#define ID3D11Device_CreateTexture1D(This,pDesc,pInitialData,ppTexture1D)	\
    ( (This) -> CreateTexture1D(pDesc,pInitialData,ppTexture1D) ) 

#define ID3D11Device_CreateTexture2D(This,pDesc,pInitialData,ppTexture2D)	\
    ( (This) -> CreateTexture2D(pDesc,pInitialData,ppTexture2D) ) 

#define ID3D11Device_CreateTexture3D(This,pDesc,pInitialData,ppTexture3D)	\
    ( (This) -> CreateTexture3D(pDesc,pInitialData,ppTexture3D) ) 

#define ID3D11Device_CreateShaderResourceView(This,pResource,pDesc,ppSRView)	\
    ( (This) -> CreateShaderResourceView(pResource,pDesc,ppSRView) ) 

#define ID3D11Device_CreateUnorderedAccessView(This,pResource,pDesc,ppUAView)	\
    ( (This) -> CreateUnorderedAccessView(pResource,pDesc,ppUAView) ) 

#define ID3D11Device_CreateRenderTargetView(This,pResource,pDesc,ppRTView)	\
    ( (This) -> CreateRenderTargetView(pResource,pDesc,ppRTView) ) 

#define ID3D11Device_CreateDepthStencilView(This,pResource,pDesc,ppDepthStencilView)	\
    ( (This) -> CreateDepthStencilView(pResource,pDesc,ppDepthStencilView) ) 

#define ID3D11Device_CreateInputLayout(This,pInputElementDescs,NumElements,pShaderBytecodeWithInputSignature,BytecodeLength,ppInputLayout)	\
    ( (This) -> CreateInputLayout(pInputElementDescs,NumElements,pShaderBytecodeWithInputSignature,BytecodeLength,ppInputLayout) ) 

#define ID3D11Device_CreateVertexShader(This,pShaderBytecode,BytecodeLength,pClassLinkage,ppVertexShader)	\
    ( (This) -> CreateVertexShader(pShaderBytecode,BytecodeLength,pClassLinkage,ppVertexShader) ) 

#define ID3D11Device_CreateGeometryShader(This,pShaderBytecode,BytecodeLength,pClassLinkage,ppGeometryShader)	\
    ( (This) -> CreateGeometryShader(pShaderBytecode,BytecodeLength,pClassLinkage,ppGeometryShader) ) 

#define ID3D11Device_CreateGeometryShaderWithStreamOutput(This,pShaderBytecode,BytecodeLength,pSODeclaration,NumEntries,pBufferStrides,NumStrides,RasterizedStream,pClassLinkage,ppGeometryShader)	\
    ( (This) -> CreateGeometryShaderWithStreamOutput(pShaderBytecode,BytecodeLength,pSODeclaration,NumEntries,pBufferStrides,NumStrides,RasterizedStream,pClassLinkage,ppGeometryShader) ) 

#define ID3D11Device_CreatePixelShader(This,pShaderBytecode,BytecodeLength,pClassLinkage,ppPixelShader)	\
    ( (This) -> CreatePixelShader(pShaderBytecode,BytecodeLength,pClassLinkage,ppPixelShader) ) 

#define ID3D11Device_CreateHullShader(This,pShaderBytecode,BytecodeLength,pClassLinkage,ppHullShader)	\
    ( (This) -> CreateHullShader(pShaderBytecode,BytecodeLength,pClassLinkage,ppHullShader) ) 

#define ID3D11Device_CreateDomainShader(This,pShaderBytecode,BytecodeLength,pClassLinkage,ppDomainShader)	\
    ( (This) -> CreateDomainShader(pShaderBytecode,BytecodeLength,pClassLinkage,ppDomainShader) ) 

#define ID3D11Device_CreateComputeShader(This,pShaderBytecode,BytecodeLength,pClassLinkage,ppComputeShader)	\
    ( (This) -> CreateComputeShader(pShaderBytecode,BytecodeLength,pClassLinkage,ppComputeShader) ) 

#define ID3D11Device_CreateClassLinkage(This,ppLinkage)	\
    ( (This) -> CreateClassLinkage(ppLinkage) ) 

#define ID3D11Device_CreateBlendState(This,pBlendStateDesc,ppBlendState)	\
    ( (This) -> CreateBlendState(pBlendStateDesc,ppBlendState) ) 

#define ID3D11Device_CreateDepthStencilState(This,pDepthStencilDesc,ppDepthStencilState)	\
    ( (This) -> CreateDepthStencilState(pDepthStencilDesc,ppDepthStencilState) ) 

#define ID3D11Device_CreateRasterizerState(This,pRasterizerDesc,ppRasterizerState)	\
    ( (This) -> CreateRasterizerState(pRasterizerDesc,ppRasterizerState) ) 

#define ID3D11Device_CreateSamplerState(This,pSamplerDesc,ppSamplerState)	\
    ( (This) -> CreateSamplerState(pSamplerDesc,ppSamplerState) ) 

#define ID3D11Device_CreateQuery(This,pQueryDesc,ppQuery)	\
    ( (This) -> CreateQuery(pQueryDesc,ppQuery) ) 

#define ID3D11Device_CreatePredicate(This,pPredicateDesc,ppPredicate)	\
    ( (This) -> CreatePredicate(pPredicateDesc,ppPredicate) ) 

#define ID3D11Device_CreateCounter(This,pCounterDesc,ppCounter)	\
    ( (This) -> CreateCounter(pCounterDesc,ppCounter) ) 

#define ID3D11Device_CreateDeferredContext(This,ContextFlags,ppDeferredContext)	\
    ( (This) -> CreateDeferredContext(ContextFlags,ppDeferredContext) ) 

#define ID3D11Device_OpenSharedResource(This,hResource,ReturnedInterface,ppResource)	\
    ( (This) -> OpenSharedResource(hResource,ReturnedInterface,ppResource) ) 

#define ID3D11Device_CheckFormatSupport(This,Format,pFormatSupport)	\
    ( (This) -> CheckFormatSupport(Format,pFormatSupport) ) 

#define ID3D11Device_CheckMultisampleQualityLevels(This,Format,SampleCount,pNumQualityLevels)	\
    ( (This) -> CheckMultisampleQualityLevels(Format,SampleCount,pNumQualityLevels) ) 

#define ID3D11Device_CheckCounterInfo(This,pCounterInfo)	\
    ( (This) -> CheckCounterInfo(pCounterInfo) ) 

#define ID3D11Device_CheckCounter(This,pDesc,pType,pActiveCounters,szName,pNameLength,szUnits,pUnitsLength,szDescription,pDescriptionLength)	\
    ( (This) -> CheckCounter(pDesc,pType,pActiveCounters,szName,pNameLength,szUnits,pUnitsLength,szDescription,pDescriptionLength) ) 

#define ID3D11Device_CheckFeatureSupport(This,Feature,pFeatureSupportData,FeatureSupportDataSize)	\
    ( (This) -> CheckFeatureSupport(Feature,pFeatureSupportData,FeatureSupportDataSize) ) 

#define ID3D11Device_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11Device_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11Device_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 

#define ID3D11Device_GetFeatureLevel(This)	\
    ( (This) -> GetFeatureLevel() ) 

#define ID3D11Device_GetCreationFlags(This)	\
    ( (This) -> GetCreationFlags() ) 

#define ID3D11Device_GetDeviceRemovedReason(This)	\
    ( (This) -> GetDeviceRemovedReason() ) 

#define ID3D11Device_GetImmediateContext(This,ppImmediateContext)	\
    ( (This) -> GetImmediateContext(ppImmediateContext) ) 

#define ID3D11Device_SetExceptionMode(This,RaiseFlags)	\
    ( (This) -> SetExceptionMode(RaiseFlags) ) 

#define ID3D11Device_GetExceptionMode(This)	\
    ( (This) -> GetExceptionMode() ) 



#define ID3D11DeviceContext_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11DeviceContext_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11DeviceContext_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11DeviceContext_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11DeviceContext_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11DeviceContext_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11DeviceContext_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11DeviceContext_VSSetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> VSSetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_PSSetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> PSSetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_PSSetShader(This,pPixelShader,ppClassInstances,NumClassInstances)	\
    ( (This) -> PSSetShader(pPixelShader,ppClassInstances,NumClassInstances) ) 

#define ID3D11DeviceContext_PSSetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> PSSetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_VSSetShader(This,pVertexShader,ppClassInstances,NumClassInstances)	\
    ( (This) -> VSSetShader(pVertexShader,ppClassInstances,NumClassInstances) ) 

#define ID3D11DeviceContext_DrawIndexed(This,IndexCount,StartIndexLocation,BaseVertexLocation)	\
    ( (This) -> DrawIndexed(IndexCount,StartIndexLocation,BaseVertexLocation) ) 

#define ID3D11DeviceContext_Draw(This,VertexCount,StartVertexLocation)	\
    ( (This) -> Draw(VertexCount,StartVertexLocation) ) 

#define ID3D11DeviceContext_Map(This,pResource,Subresource,MapType,MapFlags,pMappedResource)	\
    ( (This) -> Map(pResource,Subresource,MapType,MapFlags,pMappedResource) ) 

#define ID3D11DeviceContext_Unmap(This,pResource,Subresource)	\
    ( (This) -> Unmap(pResource,Subresource) ) 

#define ID3D11DeviceContext_PSSetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> PSSetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_IASetInputLayout(This,pInputLayout)	\
    ( (This) -> IASetInputLayout(pInputLayout) ) 

#define ID3D11DeviceContext_IASetVertexBuffers(This,StartSlot,NumBuffers,ppVertexBuffers,pStrides,pOffsets)	\
    ( (This) -> IASetVertexBuffers(StartSlot,NumBuffers,ppVertexBuffers,pStrides,pOffsets) ) 

#define ID3D11DeviceContext_IASetIndexBuffer(This,pIndexBuffer,Format,Offset)	\
    ( (This) -> IASetIndexBuffer(pIndexBuffer,Format,Offset) ) 

#define ID3D11DeviceContext_DrawIndexedInstanced(This,IndexCountPerInstance,InstanceCount,StartIndexLocation,BaseVertexLocation,StartInstanceLocation)	\
    ( (This) -> DrawIndexedInstanced(IndexCountPerInstance,InstanceCount,StartIndexLocation,BaseVertexLocation,StartInstanceLocation) ) 

#define ID3D11DeviceContext_DrawInstanced(This,VertexCountPerInstance,InstanceCount,StartVertexLocation,StartInstanceLocation)	\
    ( (This) -> DrawInstanced(VertexCountPerInstance,InstanceCount,StartVertexLocation,StartInstanceLocation) ) 

#define ID3D11DeviceContext_GSSetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> GSSetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_GSSetShader(This,pShader,ppClassInstances,NumClassInstances)	\
    ( (This) -> GSSetShader(pShader,ppClassInstances,NumClassInstances) ) 

#define ID3D11DeviceContext_IASetPrimitiveTopology(This,Topology)	\
    ( (This) -> IASetPrimitiveTopology(Topology) ) 

#define ID3D11DeviceContext_VSSetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> VSSetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_VSSetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> VSSetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_Begin(This,pAsync)	\
    ( (This) -> Begin(pAsync) ) 

#define ID3D11DeviceContext_End(This,pAsync)	\
    ( (This) -> End(pAsync) ) 

#define ID3D11DeviceContext_GetData(This,pAsync,pData,DataSize,GetDataFlags)	\
    ( (This) -> GetData(pAsync,pData,DataSize,GetDataFlags) ) 

#define ID3D11DeviceContext_SetPredication(This,pPredicate,PredicateValue)	\
    ( (This) -> SetPredication(pPredicate,PredicateValue) ) 

#define ID3D11DeviceContext_GSSetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> GSSetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_GSSetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> GSSetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_OMSetRenderTargets(This,NumViews,ppRenderTargetViews,pDepthStencilView)	\
    ( (This) -> OMSetRenderTargets(NumViews,ppRenderTargetViews,pDepthStencilView) ) 

#define ID3D11DeviceContext_OMSetRenderTargetsAndUnorderedAccessViews(This,NumRTVs,ppRenderTargetViews,pDepthStencilView,UAVStartSlot,NumUAVs,ppUnorderedAccessViews,pUAVInitialCounts)	\
    ( (This) -> OMSetRenderTargetsAndUnorderedAccessViews(NumRTVs,ppRenderTargetViews,pDepthStencilView,UAVStartSlot,NumUAVs,ppUnorderedAccessViews,pUAVInitialCounts) ) 

#define ID3D11DeviceContext_OMSetBlendState(This,pBlendState,BlendFactor,SampleMask)	\
    ( (This) -> OMSetBlendState(pBlendState,BlendFactor,SampleMask) ) 

#define ID3D11DeviceContext_OMSetDepthStencilState(This,pDepthStencilState,StencilRef)	\
    ( (This) -> OMSetDepthStencilState(pDepthStencilState,StencilRef) ) 

#define ID3D11DeviceContext_SOSetTargets(This,NumBuffers,ppSOTargets,pOffsets)	\
    ( (This) -> SOSetTargets(NumBuffers,ppSOTargets,pOffsets) ) 

#define ID3D11DeviceContext_DrawAuto(This)	\
    ( (This) -> DrawAuto() ) 

#define ID3D11DeviceContext_DrawIndexedInstancedIndirect(This,pBufferForArgs,AlignedByteOffsetForArgs)	\
    ( (This) -> DrawIndexedInstancedIndirect(pBufferForArgs,AlignedByteOffsetForArgs) ) 

#define ID3D11DeviceContext_DrawInstancedIndirect(This,pBufferForArgs,AlignedByteOffsetForArgs)	\
    ( (This) -> DrawInstancedIndirect(pBufferForArgs,AlignedByteOffsetForArgs) ) 

#define ID3D11DeviceContext_Dispatch(This,ThreadGroupCountX,ThreadGroupCountY,ThreadGroupCountZ)	\
    ( (This) -> Dispatch(ThreadGroupCountX,ThreadGroupCountY,ThreadGroupCountZ) ) 

#define ID3D11DeviceContext_DispatchIndirect(This,pBufferForArgs,AlignedByteOffsetForArgs)	\
    ( (This) -> DispatchIndirect(pBufferForArgs,AlignedByteOffsetForArgs) ) 

#define ID3D11DeviceContext_RSSetState(This,pRasterizerState)	\
    ( (This) -> RSSetState(pRasterizerState) ) 

#define ID3D11DeviceContext_RSSetViewports(This,NumViewports,pViewports)	\
    ( (This) -> RSSetViewports(NumViewports,pViewports) ) 

#define ID3D11DeviceContext_RSSetScissorRects(This,NumRects,pRects)	\
    ( (This) -> RSSetScissorRects(NumRects,pRects) ) 

#define ID3D11DeviceContext_CopySubresourceRegion(This,pDstResource,DstSubresource,DstX,DstY,DstZ,pSrcResource,SrcSubresource,pSrcBox)	\
    ( (This) -> CopySubresourceRegion(pDstResource,DstSubresource,DstX,DstY,DstZ,pSrcResource,SrcSubresource,pSrcBox) ) 

#define ID3D11DeviceContext_CopyResource(This,pDstResource,pSrcResource)	\
    ( (This) -> CopyResource(pDstResource,pSrcResource) ) 

#define ID3D11DeviceContext_UpdateSubresource(This,pDstResource,DstSubresource,pDstBox,pSrcData,SrcRowPitch,SrcDepthPitch)	\
    ( (This) -> UpdateSubresource(pDstResource,DstSubresource,pDstBox,pSrcData,SrcRowPitch,SrcDepthPitch) ) 

#define ID3D11DeviceContext_CopyStructureCount(This,pDstBuffer,DstAlignedByteOffset,pSrcView)	\
    ( (This) -> CopyStructureCount(pDstBuffer,DstAlignedByteOffset,pSrcView) ) 

#define ID3D11DeviceContext_ClearRenderTargetView(This,pRenderTargetView,ColorRGBA)	\
    ( (This) -> ClearRenderTargetView(pRenderTargetView,ColorRGBA) ) 

#define ID3D11DeviceContext_ClearUnorderedAccessViewUint(This,pUnorderedAccessView,Values)	\
    ( (This) -> ClearUnorderedAccessViewUint(pUnorderedAccessView,Values) ) 

#define ID3D11DeviceContext_ClearUnorderedAccessViewFloat(This,pUnorderedAccessView,Values)	\
    ( (This) -> ClearUnorderedAccessViewFloat(pUnorderedAccessView,Values) ) 

#define ID3D11DeviceContext_ClearDepthStencilView(This,pDepthStencilView,ClearFlags,Depth,Stencil)	\
    ( (This) -> ClearDepthStencilView(pDepthStencilView,ClearFlags,Depth,Stencil) ) 

#define ID3D11DeviceContext_GenerateMips(This,pShaderResourceView)	\
    ( (This) -> GenerateMips(pShaderResourceView) ) 

#define ID3D11DeviceContext_SetResourceMinLOD(This,pResource,MinLOD)	\
    ( (This) -> SetResourceMinLOD(pResource,MinLOD) ) 

#define ID3D11DeviceContext_GetResourceMinLOD(This,pResource)	\
    ( (This) -> GetResourceMinLOD(pResource) ) 

#define ID3D11DeviceContext_ResolveSubresource(This,pDstResource,DstSubresource,pSrcResource,SrcSubresource,Format)	\
    ( (This) -> ResolveSubresource(pDstResource,DstSubresource,pSrcResource,SrcSubresource,Format) ) 

#define ID3D11DeviceContext_ExecuteCommandList(This,pCommandList,RestoreContextState)	\
    ( (This) -> ExecuteCommandList(pCommandList,RestoreContextState) ) 

#define ID3D11DeviceContext_HSSetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> HSSetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_HSSetShader(This,pHullShader,ppClassInstances,NumClassInstances)	\
    ( (This) -> HSSetShader(pHullShader,ppClassInstances,NumClassInstances) ) 

#define ID3D11DeviceContext_HSSetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> HSSetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_HSSetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> HSSetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_DSSetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> DSSetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_DSSetShader(This,pDomainShader,ppClassInstances,NumClassInstances)	\
    ( (This) -> DSSetShader(pDomainShader,ppClassInstances,NumClassInstances) ) 

#define ID3D11DeviceContext_DSSetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> DSSetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_DSSetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> DSSetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_CSSetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> CSSetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_CSSetUnorderedAccessViews(This,StartSlot,NumUAVs,ppUnorderedAccessViews,pUAVInitialCounts)	\
    ( (This) -> CSSetUnorderedAccessViews(StartSlot,NumUAVs,ppUnorderedAccessViews,pUAVInitialCounts) ) 

#define ID3D11DeviceContext_CSSetShader(This,pComputeShader,ppClassInstances,NumClassInstances)	\
    ( (This) -> CSSetShader(pComputeShader,ppClassInstances,NumClassInstances) ) 

#define ID3D11DeviceContext_CSSetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> CSSetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_CSSetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> CSSetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_VSGetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> VSGetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_PSGetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> PSGetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_PSGetShader(This,ppPixelShader,ppClassInstances,pNumClassInstances)	\
    ( (This) -> PSGetShader(ppPixelShader,ppClassInstances,pNumClassInstances) ) 

#define ID3D11DeviceContext_PSGetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> PSGetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_VSGetShader(This,ppVertexShader,ppClassInstances,pNumClassInstances)	\
    ( (This) -> VSGetShader(ppVertexShader,ppClassInstances,pNumClassInstances) ) 

#define ID3D11DeviceContext_PSGetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> PSGetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_IAGetInputLayout(This,ppInputLayout)	\
    ( (This) -> IAGetInputLayout(ppInputLayout) ) 

#define ID3D11DeviceContext_IAGetVertexBuffers(This,StartSlot,NumBuffers,ppVertexBuffers,pStrides,pOffsets)	\
    ( (This) -> IAGetVertexBuffers(StartSlot,NumBuffers,ppVertexBuffers,pStrides,pOffsets) ) 

#define ID3D11DeviceContext_IAGetIndexBuffer(This,pIndexBuffer,Format,Offset)	\
    ( (This) -> IAGetIndexBuffer(pIndexBuffer,Format,Offset) ) 

#define ID3D11DeviceContext_GSGetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> GSGetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_GSGetShader(This,ppGeometryShader,ppClassInstances,pNumClassInstances)	\
    ( (This) -> GSGetShader(ppGeometryShader,ppClassInstances,pNumClassInstances) ) 

#define ID3D11DeviceContext_IAGetPrimitiveTopology(This,pTopology)	\
    ( (This) -> IAGetPrimitiveTopology(pTopology) ) 

#define ID3D11DeviceContext_VSGetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> VSGetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_VSGetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> VSGetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_GetPredication(This,ppPredicate,pPredicateValue)	\
    ( (This) -> GetPredication(ppPredicate,pPredicateValue) ) 

#define ID3D11DeviceContext_GSGetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> GSGetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_GSGetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> GSGetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_OMGetRenderTargets(This,NumViews,ppRenderTargetViews,ppDepthStencilView)	\
    ( (This) -> OMGetRenderTargets(NumViews,ppRenderTargetViews,ppDepthStencilView) ) 

#define ID3D11DeviceContext_OMGetRenderTargetsAndUnorderedAccessViews(This,NumRTVs,ppRenderTargetViews,ppDepthStencilView,UAVStartSlot,NumUAVs,ppUnorderedAccessViews)	\
    ( (This) -> OMGetRenderTargetsAndUnorderedAccessViews(NumRTVs,ppRenderTargetViews,ppDepthStencilView,UAVStartSlot,NumUAVs,ppUnorderedAccessViews) ) 

#define ID3D11DeviceContext_OMGetBlendState(This,ppBlendState,BlendFactor,pSampleMask)	\
    ( (This) -> OMGetBlendState(ppBlendState,BlendFactor,pSampleMask) ) 

#define ID3D11DeviceContext_OMGetDepthStencilState(This,ppDepthStencilState,pStencilRef)	\
    ( (This) -> OMGetDepthStencilState(ppDepthStencilState,pStencilRef) ) 

#define ID3D11DeviceContext_SOGetTargets(This,NumBuffers,ppSOTargets)	\
    ( (This) -> SOGetTargets(NumBuffers,ppSOTargets) ) 

#define ID3D11DeviceContext_RSGetState(This,ppRasterizerState)	\
    ( (This) -> RSGetState(ppRasterizerState) ) 

#define ID3D11DeviceContext_RSGetViewports(This,pNumViewports,pViewports)	\
    ( (This) -> RSGetViewports(pNumViewports,pViewports) ) 

#define ID3D11DeviceContext_RSGetScissorRects(This,pNumRects,pRects)	\
    ( (This) -> RSGetScissorRects(pNumRects,pRects) ) 

#define ID3D11DeviceContext_HSGetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> HSGetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_HSGetShader(This,ppHullShader,ppClassInstances,pNumClassInstances)	\
    ( (This) -> HSGetShader(ppHullShader,ppClassInstances,pNumClassInstances) ) 

#define ID3D11DeviceContext_HSGetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> HSGetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_HSGetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> HSGetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_DSGetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> DSGetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_DSGetShader(This,ppDomainShader,ppClassInstances,pNumClassInstances)	\
    ( (This) -> DSGetShader(ppDomainShader,ppClassInstances,pNumClassInstances) ) 

#define ID3D11DeviceContext_DSGetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> DSGetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_DSGetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> DSGetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_CSGetShaderResources(This,StartSlot,NumViews,ppShaderResourceViews)	\
    ( (This) -> CSGetShaderResources(StartSlot,NumViews,ppShaderResourceViews) ) 

#define ID3D11DeviceContext_CSGetUnorderedAccessViews(This,StartSlot,NumUAVs,ppUnorderedAccessViews)	\
    ( (This) -> CSGetUnorderedAccessViews(StartSlot,NumUAVs,ppUnorderedAccessViews) ) 

#define ID3D11DeviceContext_CSGetShader(This,ppComputeShader,ppClassInstances,pNumClassInstances)	\
    ( (This) -> CSGetShader(ppComputeShader,ppClassInstances,pNumClassInstances) ) 

#define ID3D11DeviceContext_CSGetSamplers(This,StartSlot,NumSamplers,ppSamplers)	\
    ( (This) -> CSGetSamplers(StartSlot,NumSamplers,ppSamplers) ) 

#define ID3D11DeviceContext_CSGetConstantBuffers(This,StartSlot,NumBuffers,ppConstantBuffers)	\
    ( (This) -> CSGetConstantBuffers(StartSlot,NumBuffers,ppConstantBuffers) ) 

#define ID3D11DeviceContext_ClearState(This)	\
    ( (This) -> ClearState() ) 

#define ID3D11DeviceContext_Flush(This)	\
    ( (This) -> Flush() ) 

#define ID3D11DeviceContext_GetType(This)	\
    ( (This) -> GetType() ) 

#define ID3D11DeviceContext_GetContextFlags(This)	\
    ( (This) -> GetContextFlags() ) 

#define ID3D11DeviceContext_FinishCommandList(This,RestoreDeferredContextState,ppCommandList)	\
    ( (This) -> FinishCommandList(RestoreDeferredContextState,ppCommandList) ) 




#define ID3D11RenderTargetView_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11RenderTargetView_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11RenderTargetView_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11RenderTargetView_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11RenderTargetView_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11RenderTargetView_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11RenderTargetView_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11RenderTargetView_GetResource(This,ppResource)	\
    ( (This) -> GetResource(ppResource) ) 


#define ID3D11RenderTargetView_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 




#define ID3D11BlendState_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11BlendState_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11BlendState_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11BlendState_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11BlendState_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11BlendState_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11BlendState_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11BlendState_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 




#define ID3D11DepthStencilState_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11DepthStencilState_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11DepthStencilState_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11DepthStencilState_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11DepthStencilState_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11DepthStencilState_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11DepthStencilState_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11DepthStencilState_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 




#define ID3D11Buffer_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11Buffer_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11Buffer_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11Buffer_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11Buffer_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11Buffer_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11Buffer_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11Buffer_GetType(This,pResourceDimension)	\
    ( (This) -> GetType(pResourceDimension) ) 

#define ID3D11Buffer_SetEvictionPriority(This,EvictionPriority)	\
    ( (This) -> SetEvictionPriority(EvictionPriority) ) 

#define ID3D11Buffer_GetEvictionPriority(This)	\
    ( (This) -> GetEvictionPriority() ) 


#define ID3D11Buffer_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 



#define ID3D11InputLayout_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11InputLayout_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11InputLayout_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11InputLayout_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11InputLayout_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11InputLayout_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11InputLayout_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 




#define ID3D11PixelShader_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11PixelShader_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11PixelShader_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11PixelShader_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11PixelShader_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11PixelShader_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11PixelShader_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 




#define ID3D11SamplerState_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11SamplerState_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11SamplerState_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11SamplerState_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11SamplerState_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11SamplerState_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11SamplerState_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11SamplerState_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 




#define ID3D11RasterizerState_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11RasterizerState_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11RasterizerState_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11RasterizerState_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11RasterizerState_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11RasterizerState_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11RasterizerState_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11RasterizerState_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 




#define ID3D11VertexShader_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11VertexShader_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11VertexShader_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11VertexShader_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11VertexShader_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11VertexShader_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11VertexShader_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 




#define IDXGISwapChain_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define IDXGISwapChain_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define IDXGISwapChain_Release(This)	\
    ( (This) -> Release() ) 


#define IDXGISwapChain_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This) -> SetPrivateData(Name,DataSize,pData) ) 

#define IDXGISwapChain_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This) -> SetPrivateDataInterface(Name,pUnknown) ) 

#define IDXGISwapChain_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This) -> GetPrivateData(Name,pDataSize,pData) ) 

#define IDXGISwapChain_GetParent(This,riid,ppParent)	\
    ( (This) -> GetParent(riid,ppParent) ) 


#define IDXGISwapChain_GetDevice(This,riid,ppDevice)	\
    ( (This) -> GetDevice(riid,ppDevice) ) 


#define IDXGISwapChain_Present(This,SyncInterval,Flags)	\
    ( (This) -> Present(SyncInterval,Flags) ) 

#define IDXGISwapChain_GetBuffer(This,Buffer,riid,ppSurface)	\
    ( (This) -> GetBuffer(Buffer,riid,ppSurface) ) 

#define IDXGISwapChain_SetFullscreenState(This,Fullscreen,pTarget)	\
    ( (This) -> SetFullscreenState(Fullscreen,pTarget) ) 

#define IDXGISwapChain_GetFullscreenState(This,pFullscreen,ppTarget)	\
    ( (This) -> GetFullscreenState(pFullscreen,ppTarget) ) 

#define IDXGISwapChain_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 

#define IDXGISwapChain_ResizeBuffers(This,BufferCount,Width,Height,NewFormat,SwapChainFlags)	\
    ( (This) -> ResizeBuffers(BufferCount,Width,Height,NewFormat,SwapChainFlags) ) 

#define IDXGISwapChain_ResizeTarget(This,pNewTargetParameters)	\
    ( (This) -> ResizeTarget(pNewTargetParameters) ) 

#define IDXGISwapChain_GetContainingOutput(This,ppOutput)	\
    ( (This) -> GetContainingOutput(ppOutput) ) 

#define IDXGISwapChain_GetFrameStatistics(This,pStats)	\
    ( (This) -> GetFrameStatistics(pStats) ) 

#define IDXGISwapChain_GetLastPresentCount(This,pLastPresentCount)	\
    ( (This) -> GetLastPresentCount(pLastPresentCount) ) 



#define IUnknown_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define IUnknown_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define IUnknown_Release(This)	\
    ( (This) -> Release() ) 




#define ID3D11Texture2D_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11Texture2D_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11Texture2D_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11Texture2D_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11Texture2D_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11Texture2D_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11Texture2D_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11Texture2D_GetType(This,pResourceDimension)	\
    ( (This) -> GetType(pResourceDimension) ) 

#define ID3D11Texture2D_SetEvictionPriority(This,EvictionPriority)	\
    ( (This) -> SetEvictionPriority(EvictionPriority) ) 

#define ID3D11Texture2D_GetEvictionPriority(This)	\
    ( (This) -> GetEvictionPriority() ) 


#define ID3D11Texture2D_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 



#define ID3D11ShaderResourceView_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11ShaderResourceView_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11ShaderResourceView_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11ShaderResourceView_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11ShaderResourceView_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11ShaderResourceView_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11ShaderResourceView_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11ShaderResourceView_GetResource(This,ppResource)	\
    ( (This) -> GetResource(ppResource) ) 


#define ID3D11ShaderResourceView_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 



#define ID3D11UnorderedAccessView_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11UnorderedAccessView_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11UnorderedAccessView_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11UnorderedAccessView_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11UnorderedAccessView_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11UnorderedAccessView_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11UnorderedAccessView_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11UnorderedAccessView_GetResource(This,ppResource)	\
    ( (This) -> GetResource(ppResource) ) 


#define ID3D11UnorderedAccessView_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 





#define ID3D11DepthStencilView_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11DepthStencilView_AddRef(This)	\
    ( (This) -> AddRef()) 

#define ID3D11DepthStencilView_Release(This)	\
    ( (This) -> Release()) 


#define ID3D11DepthStencilView_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11DepthStencilView_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11DepthStencilView_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11DepthStencilView_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11DepthStencilView_GetResource(This,ppResource)	\
    ( (This) -> GetResource(ppResource) ) 


#define ID3D11DepthStencilView_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 




#define ID3D11Resource_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11Resource_AddRef(This)	\
    ( (This) -> AddRef() ) 

#define ID3D11Resource_Release(This)	\
    ( (This) -> Release() ) 


#define ID3D11Resource_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11Resource_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11Resource_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11Resource_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11Resource_GetType(This,pResourceDimension)	\
    ( (This) -> GetType(pResourceDimension) ) 

#define ID3D11Resource_SetEvictionPriority(This,EvictionPriority)	\
    ( (This) -> SetEvictionPriority(EvictionPriority) ) 

#define ID3D11Resource_GetEvictionPriority(This)	\
    ( (This) -> GetEvictionPriority() ) 


//#define IDXGIFactory6_EnumAdapterByGpuPreference(This,Adapter,GpuPreference,riid,ppvAdapter)	\
//	( (This) -> EnumAdapterByGpuPreference(Adapter,GpuPreference,riid,ppvAdapter) ) 


#define IDXGIFactory1_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define IDXGIFactory1_AddRef(This)	\
    ( (This) -> AddRef()) 

#define IDXGIFactory1_Release(This)	\
    ( (This) -> Release()) 


#define IDXGIFactory1_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This) -> SetPrivateData(Name,DataSize,pData) ) 

#define IDXGIFactory1_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This) -> SetPrivateDataInterface(Name,pUnknown) ) 

#define IDXGIFactory1_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This) -> GetPrivateData(Name,pDataSize,pData) ) 

#define IDXGIFactory1_GetParent(This,riid,ppParent)	\
    ( (This) -> GetParent(riid,ppParent) ) 


#define IDXGIFactory1_EnumAdapters(This,Adapter,ppAdapter)	\
    ( (This) -> EnumAdapters(Adapter,ppAdapter) ) 

#define IDXGIFactory1_MakeWindowAssociation(This,WindowHandle,Flags)	\
    ( (This) -> MakeWindowAssociation(WindowHandle,Flags) ) 

#define IDXGIFactory1_GetWindowAssociation(This,pWindowHandle)	\
    ( (This) -> GetWindowAssociation(pWindowHandle) ) 

#define IDXGIFactory1_CreateSwapChain(This,pDevice,pDesc,ppSwapChain)	\
    ( (This) -> CreateSwapChain(pDevice,pDesc,ppSwapChain) ) 

#define IDXGIFactory1_CreateSoftwareAdapter(This,Module,ppAdapter)	\
    ( (This) -> CreateSoftwareAdapter(Module,ppAdapter) ) 


#define IDXGIFactory1_EnumAdapters1(This,Adapter,ppAdapter)	\
    ( (This) -> EnumAdapters1(Adapter,ppAdapter) ) 

#define IDXGIFactory1_IsCurrent(This)	\
    ( (This) -> IsCurrent()) 




#define IDXGIOutput_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define IDXGIOutput_AddRef(This)	\
    ( (This) -> AddRef()) 

#define IDXGIOutput_Release(This)	\
    ( (This) -> Release()) 


#define IDXGIOutput_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This) -> SetPrivateData(Name,DataSize,pData) ) 

#define IDXGIOutput_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This) -> SetPrivateDataInterface(Name,pUnknown) ) 

#define IDXGIOutput_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This) -> GetPrivateData(Name,pDataSize,pData) ) 

#define IDXGIOutput_GetParent(This,riid,ppParent)	\
    ( (This) -> GetParent(riid,ppParent) ) 


#define IDXGIOutput_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 

#define IDXGIOutput_GetDisplayModeList(This,EnumFormat,Flags,pNumModes,pDesc)	\
    ( (This) -> GetDisplayModeList(EnumFormat,Flags,pNumModes,pDesc) ) 

#define IDXGIOutput_FindClosestMatchingMode(This,pModeToMatch,pClosestMatch,pConcernedDevice)	\
    ( (This) -> FindClosestMatchingMode(pModeToMatch,pClosestMatch,pConcernedDevice) ) 

#define IDXGIOutput_WaitForVBlank(This)	\
    ( (This) -> WaitForVBlank()) 

#define IDXGIOutput_TakeOwnership(This,pDevice,Exclusive)	\
    ( (This) -> TakeOwnership(pDevice,Exclusive) ) 

#define IDXGIOutput_ReleaseOwnership(This)	\
    ( (This) -> ReleaseOwnership()) 

#define IDXGIOutput_GetGammaControlCapabilities(This,pGammaCaps)	\
    ( (This) -> GetGammaControlCapabilities(pGammaCaps) ) 

#define IDXGIOutput_SetGammaControl(This,pArray)	\
    ( (This) -> SetGammaControl(pArray) ) 

#define IDXGIOutput_GetGammaControl(This,pArray)	\
    ( (This) -> GetGammaControl(pArray) ) 

#define IDXGIOutput_SetDisplaySurface(This,pScanoutSurface)	\
    ( (This) -> SetDisplaySurface(pScanoutSurface) ) 

#define IDXGIOutput_GetDisplaySurfaceData(This,pDestination)	\
    ( (This) -> GetDisplaySurfaceData(pDestination) ) 

#define IDXGIOutput_GetFrameStatistics(This,pStats)	\
    ( (This) -> GetFrameStatistics(pStats) ) 




#define IDXGIAdapter1_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define IDXGIAdapter1_AddRef(This)	\
    ( (This) -> AddRef()) 

#define IDXGIAdapter1_Release(This)	\
    ( (This) -> Release()) 


#define IDXGIAdapter1_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This) -> SetPrivateData(Name,DataSize,pData) ) 

#define IDXGIAdapter1_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This) -> SetPrivateDataInterface(Name,pUnknown) ) 

#define IDXGIAdapter1_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This) -> GetPrivateData(Name,pDataSize,pData) ) 

#define IDXGIAdapter1_GetParent(This,riid,ppParent)	\
    ( (This) -> GetParent(riid,ppParent) ) 


#define IDXGIAdapter1_EnumOutputs(This,Output,ppOutput)	\
    ( (This) -> EnumOutputs(Output,ppOutput) ) 

#define IDXGIAdapter1_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 

#define IDXGIAdapter1_CheckInterfaceSupport(This,InterfaceName,pUMDVersion)	\
    ( (This) -> CheckInterfaceSupport(InterfaceName,pUMDVersion) ) 


#define IDXGIAdapter1_GetDesc1(This,pDesc)	\
    ( (This) -> GetDesc1(pDesc) ) 




#define IDXGIAdapter_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) )

#define IDXGIAdapter_AddRef(This)	\
    ( (This) -> AddRef()) 

#define IDXGIAdapter_Release(This)	\
    ( (This) -> Release()) 


#define IDXGIAdapter_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This) -> SetPrivateData(Name,DataSize,pData) )

#define IDXGIAdapter_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This) -> SetPrivateDataInterface(Name,pUnknown) )

#define IDXGIAdapter_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This) -> GetPrivateData(Name,pDataSize,pData) )

#define IDXGIAdapter_GetParent(This,riid,ppParent)	\
    ( (This) -> GetParent(riid,ppParent) )


#define IDXGIAdapter_EnumOutputs(This,Output,ppOutput)	\
    ( (This) -> EnumOutputs(Output,ppOutput) )

#define IDXGIAdapter_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) )

#define IDXGIAdapter_CheckInterfaceSupport(This,InterfaceName,pUMDVersion)	\
    ( (This) -> CheckInterfaceSupport(InterfaceName,pUMDVersion) )



#define ID3D11Query_QueryInterface(This,riid,ppvObject)	\
    ( (This) -> QueryInterface(riid,ppvObject) ) 

#define ID3D11Query_AddRef(This)	\
    ( (This) -> AddRef()) 

#define ID3D11Query_Release(This)	\
    ( (This) -> Release()) 


#define ID3D11Query_GetDevice(This,ppDevice)	\
    ( (This) -> GetDevice(ppDevice) ) 

#define ID3D11Query_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This) -> GetPrivateData(guid,pDataSize,pData) ) 

#define ID3D11Query_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This) -> SetPrivateData(guid,DataSize,pData) ) 

#define ID3D11Query_SetPrivateDataInterface(This,guid,pData)	\
    ( (This) -> SetPrivateDataInterface(guid,pData) ) 


#define ID3D11Query_GetDataSize(This)	\
    ( (This) -> GetDataSize()) 


#define ID3D11Query_GetDesc(This,pDesc)	\
    ( (This) -> GetDesc(pDesc) ) 
#endif 