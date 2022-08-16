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

#ifndef FNA3D_DRIVER_OPENGL_H
#define FNA3D_DRIVER_OPENGL_H

#include <stdint.h>

/* Types */
typedef unsigned int	GLenum;
typedef unsigned int	GLbitfield;
typedef void		GLvoid;
typedef unsigned int	GLuint;
typedef int		GLint;
typedef unsigned char	GLubyte;
typedef int		GLsizei;
typedef float		GLfloat;
typedef float		GLclampf;
typedef double  	GLdouble;
typedef char		GLchar;
typedef uintptr_t	GLsizeiptr;
typedef intptr_t	GLintptr;
typedef unsigned char	GLboolean;

/* Hint */
#define GL_DONT_CARE					0x1100

/* 0/1 */
#define GL_ZERO 					0x0000
#define GL_ONE  					0x0001

/* True/False */
#define GL_FALSE					0x0000
#define GL_TRUE 					0x0001

/* Types */
#define GL_BYTE 					0x1400
#define GL_UNSIGNED_BYTE				0x1401
#define GL_SHORT					0x1402
#define GL_UNSIGNED_SHORT				0x1403
#define GL_UNSIGNED_INT 				0x1405
#define GL_FLOAT					0x1406
#define GL_HALF_FLOAT					0x140B
#define GL_UNSIGNED_SHORT_4_4_4_4_REV			0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1_REV			0x8366
#define GL_UNSIGNED_INT_2_10_10_10_REV  		0x8368
#define GL_UNSIGNED_SHORT_5_6_5 			0x8363
#define GL_UNSIGNED_INT_24_8				0x84FA

/* Strings */
#define GL_VENDOR					0x1F00
#define GL_RENDERER					0x1F01
#define GL_VERSION					0x1F02
#define GL_EXTENSIONS					0x1F03

/* Clear Mask */
#define GL_COLOR_BUFFER_BIT				0x4000
#define GL_DEPTH_BUFFER_BIT				0x0100
#define GL_STENCIL_BUFFER_BIT				0x0400

/* Enable Caps */
#define GL_SCISSOR_TEST 				0x0C11
#define GL_DEPTH_TEST					0x0B71
#define GL_STENCIL_TEST 				0x0B90

/* Points */
#define GL_POINT_SPRITE 				0x8861
#define GL_COORD_REPLACE				0x8862

/* Polygons */
#define GL_LINE 					0x1B01
#define GL_FILL 					0x1B02
#define GL_CW						0x0900
#define GL_CCW  					0x0901
#define GL_FRONT					0x0404
#define GL_BACK 					0x0405
#define GL_FRONT_AND_BACK				0x0408
#define GL_CULL_FACE					0x0B44
#define GL_POLYGON_OFFSET_FILL  			0x8037

/* Texture Type */
#define GL_TEXTURE_2D					0x0DE1
#define GL_TEXTURE_3D					0x806F
#define GL_TEXTURE_CUBE_MAP				0x8513
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X  		0x8515

/* Blend Mode */
#define GL_BLEND					0x0BE2
#define GL_SRC_COLOR					0x0300
#define GL_ONE_MINUS_SRC_COLOR  			0x0301
#define GL_SRC_ALPHA					0x0302
#define GL_ONE_MINUS_SRC_ALPHA  			0x0303
#define GL_DST_ALPHA					0x0304
#define GL_ONE_MINUS_DST_ALPHA  			0x0305
#define GL_DST_COLOR					0x0306
#define GL_ONE_MINUS_DST_COLOR  			0x0307
#define GL_SRC_ALPHA_SATURATE				0x0308
#define GL_CONSTANT_COLOR				0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR			0x8002

/* Equations */
#define GL_MIN  					0x8007
#define GL_MAX  					0x8008
#define GL_FUNC_ADD					0x8006
#define GL_FUNC_SUBTRACT				0x800A
#define GL_FUNC_REVERSE_SUBTRACT			0x800B

/* Comparisons */
#define GL_NEVER					0x0200
#define GL_LESS 					0x0201
#define GL_EQUAL					0x0202
#define GL_LEQUAL					0x0203
#define GL_GREATER					0x0204
#define GL_NOTEQUAL					0x0205
#define GL_GEQUAL					0x0206
#define GL_ALWAYS					0x0207

/* Stencil Operations */
#define GL_INVERT					0x150A
#define GL_KEEP 					0x1E00
#define GL_REPLACE					0x1E01
#define GL_INCR 					0x1E02
#define GL_DECR 					0x1E03
#define GL_INCR_WRAP					0x8507
#define GL_DECR_WRAP					0x8508

/* Wrap Modes */
#define GL_REPEAT					0x2901
#define GL_CLAMP_TO_EDGE				0x812F
#define GL_MIRRORED_REPEAT				0x8370

/* Filters */
#define GL_NEAREST					0x2600
#define GL_LINEAR					0x2601
#define GL_NEAREST_MIPMAP_NEAREST			0x2700
#define GL_NEAREST_MIPMAP_LINEAR			0x2702
#define GL_LINEAR_MIPMAP_NEAREST			0x2701
#define GL_LINEAR_MIPMAP_LINEAR 			0x2703

/* Attachments */
#define GL_COLOR_ATTACHMENT0				0x8CE0
#define GL_DEPTH_ATTACHMENT				0x8D00
#define GL_STENCIL_ATTACHMENT				0x8D20
#define GL_DEPTH_STENCIL_ATTACHMENT			0x821A

/* Texture Formats */
#define GL_RED  					0x1903
#define GL_ALPHA					0x1906
#define GL_RGB  					0x1907
#define GL_RGBA 					0x1908
#define GL_RGB8 					0x8051
#define GL_RGBA8					0x8058
#define GL_RGBA4					0x8056
#define GL_RGB5_A1					0x8057
#define GL_RGB10_A2_EXT 				0x8059
#define GL_RGBA16					0x805B
#define GL_BGRA 					0x80E1
#define GL_DEPTH_COMPONENT16				0x81A5
#define GL_DEPTH_COMPONENT24				0x81A6
#define GL_RG   					0x8227
#define GL_RG8  					0x822B
#define GL_RG16 					0x822C
#define GL_R16F 					0x822D
#define GL_R32F 					0x822E
#define GL_RG16F					0x822F
#define GL_RG32F					0x8230
#define GL_RGBA32F					0x8814
#define GL_RGBA16F					0x881A
#define GL_DEPTH24_STENCIL8				0x88F0
#define GL_COMPRESSED_TEXTURE_FORMATS			0x86A3
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT		0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT		0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT		0x83F3
#define GL_SRGB_EXT					0x8C40
#define GL_SRGB8_EXT					0x8C41
#define GL_SRGB_ALPHA_EXT				0x8C42
#define GL_SRGB8_ALPHA8_EXT				0x8C43
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT		0x8C4F
#define GL_COMPRESSED_RGBA_BPTC_UNORM_EXT		0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_EXT		0x8E8D

/* EXT_framebuffer_sRGB */
#define GL_FRAMEBUFFER_SRGB_EXT				0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT			0x8DBA

/* Texture Internal Formats */
#define GL_DEPTH_COMPONENT				0x1902
#define GL_DEPTH_STENCIL				0x84F9

/* Textures */
#define GL_TEXTURE_WRAP_S				0x2802
#define GL_TEXTURE_WRAP_T				0x2803
#define GL_TEXTURE_WRAP_R				0x8072
#define GL_TEXTURE_MAG_FILTER				0x2800
#define GL_TEXTURE_MIN_FILTER				0x2801
#define GL_TEXTURE_MAX_ANISOTROPY_EXT			0x84FE
#define GL_TEXTURE_BASE_LEVEL				0x813C
#define GL_TEXTURE_MAX_LEVEL				0x813D
#define GL_TEXTURE_LOD_BIAS				0x8501
#define GL_UNPACK_ALIGNMENT				0x0CF5

/* Multitexture */
#define GL_TEXTURE0					0x84C0
#define GL_MAX_TEXTURE_IMAGE_UNITS			0x8872
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS		0x8B4C

/* Buffer objects */
#define GL_ARRAY_BUFFER 				0x8892
#define GL_ELEMENT_ARRAY_BUFFER 			0x8893
#define GL_STREAM_DRAW  				0x88E0
#define GL_STATIC_DRAW  				0x88E4
#define GL_MAX_VERTEX_ATTRIBS				0x8869

/* Render targets */
#define GL_FRAMEBUFFER  				0x8D40
#define GL_READ_FRAMEBUFFER				0x8CA8
#define GL_DRAW_FRAMEBUFFER				0x8CA9
#define GL_RENDERBUFFER 				0x8D41
#define GL_MAX_DRAW_BUFFERS				0x8824

/* Draw Primitives */
#define GL_POINTS					0x0000
#define GL_LINES					0x0001
#define GL_LINE_STRIP					0x0003
#define GL_TRIANGLES					0x0004
#define GL_TRIANGLE_STRIP				0x0005

/* Query Objects */
#define GL_QUERY_RESULT 				0x8866
#define GL_QUERY_RESULT_AVAILABLE			0x8867
#define GL_SAMPLES_PASSED				0x8914

/* Multisampling */
#define GL_MULTISAMPLE  				0x809D
#define GL_MAX_SAMPLES  				0x8D57
#define GL_SAMPLE_MASK  				0x8E51
#define GL_SAMPLES					0x80A9

/* 3.2 Core Profile */
#define GL_NUM_EXTENSIONS				0x821D

/* Debug Source */
#define GL_DEBUG_SOURCE_API				0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM			0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER			0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY			0x8249
#define GL_DEBUG_SOURCE_APPLICATION			0x824A
#define GL_DEBUG_SOURCE_OTHER				0x824B

/* Debug Type */
#define GL_DEBUG_TYPE_ERROR				0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR		0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR		0x824E
#define GL_DEBUG_TYPE_PORTABILITY			0x824F
#define GL_DEBUG_TYPE_PERFORMANCE			0x8250
#define GL_DEBUG_TYPE_OTHER				0x8251

/* Debug Severity */
#define GL_DEBUG_SEVERITY_HIGH  			0x9146
#define GL_DEBUG_SEVERITY_MEDIUM			0x9147
#define GL_DEBUG_SEVERITY_LOW				0x9148
#define GL_DEBUG_SEVERITY_NOTIFICATION  		0x826B

#ifndef GL_ARB_shader_image_load_store
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#endif


#ifndef GL_VERSION_3_0
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
/* Reuse tokens from ARB_depth_buffer_float */
/* reuse GL_DEPTH_COMPONENT32F */
/* reuse GL_DEPTH32F_STENCIL8 */
/* reuse GL_FLOAT_32_UNSIGNED_INT_24_8_REV */
/* Reuse tokens from ARB_framebuffer_object */
/* reuse GL_INVALID_FRAMEBUFFER_OPERATION */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE */
/* reuse GL_FRAMEBUFFER_DEFAULT */
/* reuse GL_FRAMEBUFFER_UNDEFINED */
/* reuse GL_DEPTH_STENCIL_ATTACHMENT */
/* reuse GL_INDEX */
/* reuse GL_MAX_RENDERBUFFER_SIZE */
/* reuse GL_DEPTH_STENCIL */
/* reuse GL_UNSIGNED_INT_24_8 */
/* reuse GL_DEPTH24_STENCIL8 */
/* reuse GL_TEXTURE_STENCIL_SIZE */
/* reuse GL_TEXTURE_RED_TYPE */
/* reuse GL_TEXTURE_GREEN_TYPE */
/* reuse GL_TEXTURE_BLUE_TYPE */
/* reuse GL_TEXTURE_ALPHA_TYPE */
/* reuse GL_TEXTURE_DEPTH_TYPE */
/* reuse GL_UNSIGNED_NORMALIZED */
/* reuse GL_FRAMEBUFFER_BINDING */
/* reuse GL_DRAW_FRAMEBUFFER_BINDING */
/* reuse GL_RENDERBUFFER_BINDING */
/* reuse GL_READ_FRAMEBUFFER */
/* reuse GL_DRAW_FRAMEBUFFER */
/* reuse GL_READ_FRAMEBUFFER_BINDING */
/* reuse GL_RENDERBUFFER_SAMPLES */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER */
/* reuse GL_FRAMEBUFFER_COMPLETE */
/* reuse GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT */
/* reuse GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT */
/* reuse GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER */
/* reuse GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER */
/* reuse GL_FRAMEBUFFER_UNSUPPORTED */
/* reuse GL_MAX_COLOR_ATTACHMENTS */
/* reuse GL_COLOR_ATTACHMENT0 */
/* reuse GL_COLOR_ATTACHMENT1 */
/* reuse GL_COLOR_ATTACHMENT2 */
/* reuse GL_COLOR_ATTACHMENT3 */
/* reuse GL_COLOR_ATTACHMENT4 */
/* reuse GL_COLOR_ATTACHMENT5 */
/* reuse GL_COLOR_ATTACHMENT6 */
/* reuse GL_COLOR_ATTACHMENT7 */
/* reuse GL_COLOR_ATTACHMENT8 */
/* reuse GL_COLOR_ATTACHMENT9 */
/* reuse GL_COLOR_ATTACHMENT10 */
/* reuse GL_COLOR_ATTACHMENT11 */
/* reuse GL_COLOR_ATTACHMENT12 */
/* reuse GL_COLOR_ATTACHMENT13 */
/* reuse GL_COLOR_ATTACHMENT14 */
/* reuse GL_COLOR_ATTACHMENT15 */
/* reuse GL_DEPTH_ATTACHMENT */
/* reuse GL_STENCIL_ATTACHMENT */
/* reuse GL_FRAMEBUFFER */
/* reuse GL_RENDERBUFFER */
/* reuse GL_RENDERBUFFER_WIDTH */
/* reuse GL_RENDERBUFFER_HEIGHT */
/* reuse GL_RENDERBUFFER_INTERNAL_FORMAT */
/* reuse GL_STENCIL_INDEX1 */
/* reuse GL_STENCIL_INDEX4 */
/* reuse GL_STENCIL_INDEX8 */
/* reuse GL_STENCIL_INDEX16 */
/* reuse GL_RENDERBUFFER_RED_SIZE */
/* reuse GL_RENDERBUFFER_GREEN_SIZE */
/* reuse GL_RENDERBUFFER_BLUE_SIZE */
/* reuse GL_RENDERBUFFER_ALPHA_SIZE */
/* reuse GL_RENDERBUFFER_DEPTH_SIZE */
/* reuse GL_RENDERBUFFER_STENCIL_SIZE */
/* reuse GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE */
/* reuse GL_MAX_SAMPLES */
/* Reuse tokens from ARB_framebuffer_sRGB */
/* reuse GL_FRAMEBUFFER_SRGB */
/* Reuse tokens from ARB_half_float_vertex */
/* reuse GL_HALF_FLOAT */
/* Reuse tokens from ARB_map_buffer_range */
/* reuse GL_MAP_READ_BIT */
/* reuse GL_MAP_WRITE_BIT */
/* reuse GL_MAP_INVALIDATE_RANGE_BIT */
/* reuse GL_MAP_INVALIDATE_BUFFER_BIT */
/* reuse GL_MAP_FLUSH_EXPLICIT_BIT */
/* reuse GL_MAP_UNSYNCHRONIZED_BIT */
/* Reuse tokens from ARB_texture_compression_rgtc */
/* reuse GL_COMPRESSED_RED_RGTC1 */
/* reuse GL_COMPRESSED_SIGNED_RED_RGTC1 */
/* reuse GL_COMPRESSED_RG_RGTC2 */
/* reuse GL_COMPRESSED_SIGNED_RG_RGTC2 */
/* Reuse tokens from ARB_texture_rg */
/* reuse GL_RG */
/* reuse GL_RG_INTEGER */
/* reuse GL_R8 */
/* reuse GL_R16 */
/* reuse GL_RG8 */
/* reuse GL_RG16 */
/* reuse GL_R16F */
/* reuse GL_R32F */
/* reuse GL_RG16F */
/* reuse GL_RG32F */
/* reuse GL_R8I */
/* reuse GL_R8UI */
/* reuse GL_R16I */
/* reuse GL_R16UI */
/* reuse GL_R32I */
/* reuse GL_R32UI */
/* reuse GL_RG8I */
/* reuse GL_RG8UI */
/* reuse GL_RG16I */
/* reuse GL_RG16UI */
/* reuse GL_RG32I */
/* reuse GL_RG32UI */
/* Reuse tokens from ARB_vertex_array_object */
/* reuse GL_VERTEX_ARRAY_BINDING */
#endif


#ifndef GL_VERSION_1_5
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#endif

/* In case this needs to be exported in a certain way... */
#ifdef _WIN32 /* Windows OpenGL uses stdcall */
#define GLAPIENTRY __stdcall
#else
#define GLAPIENTRY
#endif

/* Debug callback typedef */
typedef void (GLAPIENTRY *DEBUGPROC)(
	GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar *message,
	const void *userParam
);

/* Function typedefs */
#define GL_EXT(ext)
#define GL_PROC(ext, ret, func, parms) \
	typedef ret (GLAPIENTRY *glfntype_##func) parms;
#define GL_PROC_EXT(ext, fallbacl, ret, func, parms) \
	typedef ret (GLAPIENTRY *glfntype_##func) parms;
#include "FNA3D_Driver_OpenGL_glfuncs.h"

/* glGetString is a bit different since we load it early */
typedef const GLubyte* (GLAPIENTRY *glfntype_glGetString)(GLenum a);

#endif /* FNA3D_DRIVER_OPENGL_H */

/* vim: set noexpandtab shiftwidth=8 tabstop=8: */
