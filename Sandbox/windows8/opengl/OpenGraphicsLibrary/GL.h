#ifndef __gl_h_
#ifndef __GL_H__

#define __gl_h_
#define __GL_H__

#include <wrl/client.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

/* Version */
#define GL_VERSION_1_1                    1

/* AccumOp */
#define GL_ACCUM                          0x0100
#define GL_LOAD                           0x0101
#define GL_RETURN                         0x0102
#define GL_MULT                           0x0103
#define GL_ADD                            0x0104

/* AlphaFunction */
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207

/* AttribMask */
#define GL_CURRENT_BIT                    0x00000001
#define GL_POINT_BIT                      0x00000002
#define GL_LINE_BIT                       0x00000004
#define GL_POLYGON_BIT                    0x00000008
#define GL_POLYGON_STIPPLE_BIT            0x00000010
#define GL_PIXEL_MODE_BIT                 0x00000020
#define GL_LIGHTING_BIT                   0x00000040
#define GL_FOG_BIT                        0x00000080
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_ACCUM_BUFFER_BIT               0x00000200
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_VIEWPORT_BIT                   0x00000800
#define GL_TRANSFORM_BIT                  0x00001000
#define GL_ENABLE_BIT                     0x00002000
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_HINT_BIT                       0x00008000
#define GL_EVAL_BIT                       0x00010000
#define GL_LIST_BIT                       0x00020000
#define GL_TEXTURE_BIT                    0x00040000
#define GL_SCISSOR_BIT                    0x00080000
#define GL_ALL_ATTRIB_BITS                0x000fffff

/* BeginMode */
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_QUAD_STRIP                     0x0008
#define GL_POLYGON                        0x0009

/* BlendingFactorDest */
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305

/* BlendingFactorSrc */
/*      GL_ZERO */
/*      GL_ONE */
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
/*      GL_SRC_ALPHA */
/*      GL_ONE_MINUS_SRC_ALPHA */
/*      GL_DST_ALPHA */
/*      GL_ONE_MINUS_DST_ALPHA */

/* Boolean */
#define GL_TRUE                           1
#define GL_FALSE                          0

/* ClearBufferMask */
/*      GL_COLOR_BUFFER_BIT */
/*      GL_ACCUM_BUFFER_BIT */
/*      GL_STENCIL_BUFFER_BIT */
/*      GL_DEPTH_BUFFER_BIT */

/* ClientArrayType */
/*      GL_VERTEX_ARRAY */
/*      GL_NORMAL_ARRAY */
/*      GL_COLOR_ARRAY */
/*      GL_INDEX_ARRAY */
/*      GL_TEXTURE_COORD_ARRAY */
/*      GL_EDGE_FLAG_ARRAY */

/* ClipPlaneName */
#define GL_CLIP_PLANE0                    0x3000
#define GL_CLIP_PLANE1                    0x3001
#define GL_CLIP_PLANE2                    0x3002
#define GL_CLIP_PLANE3                    0x3003
#define GL_CLIP_PLANE4                    0x3004
#define GL_CLIP_PLANE5                    0x3005

/* ColorMaterialFace */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* ColorMaterialParameter */
/*      GL_AMBIENT */
/*      GL_DIFFUSE */
/*      GL_SPECULAR */
/*      GL_EMISSION */
/*      GL_AMBIENT_AND_DIFFUSE */

/* ColorPointerType */
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* CullFaceMode */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* DataType */
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_2_BYTES                        0x1407
#define GL_3_BYTES                        0x1408
#define GL_4_BYTES                        0x1409
#define GL_DOUBLE                         0x140A

/* DepthFunction */
/*      GL_NEVER */
/*      GL_LESS */
/*      GL_EQUAL */
/*      GL_LEQUAL */
/*      GL_GREATER */
/*      GL_NOTEQUAL */
/*      GL_GEQUAL */
/*      GL_ALWAYS */

/* DrawBufferMode */
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_AUX0                           0x0409
#define GL_AUX1                           0x040A
#define GL_AUX2                           0x040B
#define GL_AUX3                           0x040C

/* Enable */
/*      GL_FOG */
/*      GL_LIGHTING */
/*      GL_TEXTURE_1D */
/*      GL_TEXTURE_2D */
/*      GL_LINE_STIPPLE */
/*      GL_POLYGON_STIPPLE */
/*      GL_CULL_FACE */
/*      GL_ALPHA_TEST */
/*      GL_BLEND */
/*      GL_INDEX_LOGIC_OP */
/*      GL_COLOR_LOGIC_OP */
/*      GL_DITHER */
/*      GL_STENCIL_TEST */
/*      GL_DEPTH_TEST */
/*      GL_CLIP_PLANE0 */
/*      GL_CLIP_PLANE1 */
/*      GL_CLIP_PLANE2 */
/*      GL_CLIP_PLANE3 */
/*      GL_CLIP_PLANE4 */
/*      GL_CLIP_PLANE5 */
/*      GL_LIGHT0 */
/*      GL_LIGHT1 */
/*      GL_LIGHT2 */
/*      GL_LIGHT3 */
/*      GL_LIGHT4 */
/*      GL_LIGHT5 */
/*      GL_LIGHT6 */
/*      GL_LIGHT7 */
/*      GL_TEXTURE_GEN_S */
/*      GL_TEXTURE_GEN_T */
/*      GL_TEXTURE_GEN_R */
/*      GL_TEXTURE_GEN_Q */
/*      GL_MAP1_VERTEX_3 */
/*      GL_MAP1_VERTEX_4 */
/*      GL_MAP1_COLOR_4 */
/*      GL_MAP1_INDEX */
/*      GL_MAP1_NORMAL */
/*      GL_MAP1_TEXTURE_COORD_1 */
/*      GL_MAP1_TEXTURE_COORD_2 */
/*      GL_MAP1_TEXTURE_COORD_3 */
/*      GL_MAP1_TEXTURE_COORD_4 */
/*      GL_MAP2_VERTEX_3 */
/*      GL_MAP2_VERTEX_4 */
/*      GL_MAP2_COLOR_4 */
/*      GL_MAP2_INDEX */
/*      GL_MAP2_NORMAL */
/*      GL_MAP2_TEXTURE_COORD_1 */
/*      GL_MAP2_TEXTURE_COORD_2 */
/*      GL_MAP2_TEXTURE_COORD_3 */
/*      GL_MAP2_TEXTURE_COORD_4 */
/*      GL_POINT_SMOOTH */
/*      GL_LINE_SMOOTH */
/*      GL_POLYGON_SMOOTH */
/*      GL_SCISSOR_TEST */
/*      GL_COLOR_MATERIAL */
/*      GL_NORMALIZE */
/*      GL_AUTO_NORMAL */
/*      GL_VERTEX_ARRAY */
/*      GL_NORMAL_ARRAY */
/*      GL_COLOR_ARRAY */
/*      GL_INDEX_ARRAY */
/*      GL_TEXTURE_COORD_ARRAY */
/*      GL_EDGE_FLAG_ARRAY */
/*      GL_POLYGON_OFFSET_POINT */
/*      GL_POLYGON_OFFSET_LINE */
/*      GL_POLYGON_OFFSET_FILL */

/* ErrorCode */
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505

/* FeedBackMode */
#define GL_2D                             0x0600
#define GL_3D                             0x0601
#define GL_3D_COLOR                       0x0602
#define GL_3D_COLOR_TEXTURE               0x0603
#define GL_4D_COLOR_TEXTURE               0x0604

/* FeedBackToken */
#define GL_PASS_THROUGH_TOKEN             0x0700
#define GL_POINT_TOKEN                    0x0701
#define GL_LINE_TOKEN                     0x0702
#define GL_POLYGON_TOKEN                  0x0703
#define GL_BITMAP_TOKEN                   0x0704
#define GL_DRAW_PIXEL_TOKEN               0x0705
#define GL_COPY_PIXEL_TOKEN               0x0706
#define GL_LINE_RESET_TOKEN               0x0707

/* FogMode */
/*      GL_LINEAR */
#define GL_EXP                            0x0800
#define GL_EXP2                           0x0801


/* FogParameter */
/*      GL_FOG_COLOR */
/*      GL_FOG_DENSITY */
/*      GL_FOG_END */
/*      GL_FOG_INDEX */
/*      GL_FOG_MODE */
/*      GL_FOG_START */

/* FrontFaceDirection */
#define GL_CW                             0x0900
#define GL_CCW                            0x0901

/* GetMapTarget */
#define GL_COEFF                          0x0A00
#define GL_ORDER                          0x0A01
#define GL_DOMAIN                         0x0A02

/* GetPixelMap */
/*      GL_PIXEL_MAP_I_TO_I */
/*      GL_PIXEL_MAP_S_TO_S */
/*      GL_PIXEL_MAP_I_TO_R */
/*      GL_PIXEL_MAP_I_TO_G */
/*      GL_PIXEL_MAP_I_TO_B */
/*      GL_PIXEL_MAP_I_TO_A */
/*      GL_PIXEL_MAP_R_TO_R */
/*      GL_PIXEL_MAP_G_TO_G */
/*      GL_PIXEL_MAP_B_TO_B */
/*      GL_PIXEL_MAP_A_TO_A */

/* GetPointerTarget */
/*      GL_VERTEX_ARRAY_POINTER */
/*      GL_NORMAL_ARRAY_POINTER */
/*      GL_COLOR_ARRAY_POINTER */
/*      GL_INDEX_ARRAY_POINTER */
/*      GL_TEXTURE_COORD_ARRAY_POINTER */
/*      GL_EDGE_FLAG_ARRAY_POINTER */

/* GetTarget */
#define GL_CURRENT_COLOR                  0x0B00
#define GL_CURRENT_INDEX                  0x0B01
#define GL_CURRENT_NORMAL                 0x0B02
#define GL_CURRENT_TEXTURE_COORDS         0x0B03
#define GL_CURRENT_RASTER_COLOR           0x0B04
#define GL_CURRENT_RASTER_INDEX           0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS  0x0B06
#define GL_CURRENT_RASTER_POSITION        0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID  0x0B08
#define GL_CURRENT_RASTER_DISTANCE        0x0B09
#define GL_POINT_SMOOTH                   0x0B10
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_LINE_STIPPLE                   0x0B24
#define GL_LINE_STIPPLE_PATTERN           0x0B25
#define GL_LINE_STIPPLE_REPEAT            0x0B26
#define GL_LIST_MODE                      0x0B30
#define GL_MAX_LIST_NESTING               0x0B31
#define GL_LIST_BASE                      0x0B32
#define GL_LIST_INDEX                     0x0B33
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_POLYGON_STIPPLE                0x0B42
#define GL_EDGE_FLAG                      0x0B43
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_LIGHTING                       0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER       0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE           0x0B52
#define GL_LIGHT_MODEL_AMBIENT            0x0B53
#define GL_SHADE_MODEL                    0x0B54
#define GL_COLOR_MATERIAL_FACE            0x0B55
#define GL_COLOR_MATERIAL_PARAMETER       0x0B56
#define GL_COLOR_MATERIAL                 0x0B57
#define GL_FOG                            0x0B60
#define GL_FOG_INDEX                      0x0B61
#define GL_FOG_DENSITY                    0x0B62
#define GL_FOG_START                      0x0B63
#define GL_FOG_END                        0x0B64
#define GL_FOG_MODE                       0x0B65
#define GL_FOG_COLOR                      0x0B66
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_ACCUM_CLEAR_VALUE              0x0B80
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_MATRIX_MODE                    0x0BA0
#define GL_NORMALIZE                      0x0BA1
#define GL_VIEWPORT                       0x0BA2
#define GL_MODELVIEW_STACK_DEPTH          0x0BA3
#define GL_PROJECTION_STACK_DEPTH         0x0BA4
#define GL_TEXTURE_STACK_DEPTH            0x0BA5
#define GL_MODELVIEW_MATRIX               0x0BA6
#define GL_PROJECTION_MATRIX              0x0BA7
#define GL_TEXTURE_MATRIX                 0x0BA8
#define GL_ATTRIB_STACK_DEPTH             0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH      0x0BB1
#define GL_ALPHA_TEST                     0x0BC0
#define GL_ALPHA_TEST_FUNC                0x0BC1
#define GL_ALPHA_TEST_REF                 0x0BC2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_INDEX_LOGIC_OP                 0x0BF1
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_AUX_BUFFERS                    0x0C00
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_INDEX_CLEAR_VALUE              0x0C20
#define GL_INDEX_WRITEMASK                0x0C21
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_INDEX_MODE                     0x0C30
#define GL_RGBA_MODE                      0x0C31
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_RENDER_MODE                    0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT    0x0C50
#define GL_POINT_SMOOTH_HINT              0x0C51
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_FOG_HINT                       0x0C54
#define GL_TEXTURE_GEN_S                  0x0C60
#define GL_TEXTURE_GEN_T                  0x0C61
#define GL_TEXTURE_GEN_R                  0x0C62
#define GL_TEXTURE_GEN_Q                  0x0C63
#define GL_PIXEL_MAP_I_TO_I               0x0C70
#define GL_PIXEL_MAP_S_TO_S               0x0C71
#define GL_PIXEL_MAP_I_TO_R               0x0C72
#define GL_PIXEL_MAP_I_TO_G               0x0C73
#define GL_PIXEL_MAP_I_TO_B               0x0C74
#define GL_PIXEL_MAP_I_TO_A               0x0C75
#define GL_PIXEL_MAP_R_TO_R               0x0C76
#define GL_PIXEL_MAP_G_TO_G               0x0C77
#define GL_PIXEL_MAP_B_TO_B               0x0C78
#define GL_PIXEL_MAP_A_TO_A               0x0C79
#define GL_PIXEL_MAP_I_TO_I_SIZE          0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE          0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE          0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE          0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE          0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE          0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE          0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE          0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE          0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE          0x0CB9
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAP_COLOR                      0x0D10
#define GL_MAP_STENCIL                    0x0D11
#define GL_INDEX_SHIFT                    0x0D12
#define GL_INDEX_OFFSET                   0x0D13
#define GL_RED_SCALE                      0x0D14
#define GL_RED_BIAS                       0x0D15
#define GL_ZOOM_X                         0x0D16
#define GL_ZOOM_Y                         0x0D17
#define GL_GREEN_SCALE                    0x0D18
#define GL_GREEN_BIAS                     0x0D19
#define GL_BLUE_SCALE                     0x0D1A
#define GL_BLUE_BIAS                      0x0D1B
#define GL_ALPHA_SCALE                    0x0D1C
#define GL_ALPHA_BIAS                     0x0D1D
#define GL_DEPTH_SCALE                    0x0D1E
#define GL_DEPTH_BIAS                     0x0D1F
#define GL_MAX_EVAL_ORDER                 0x0D30
#define GL_MAX_LIGHTS                     0x0D31
#define GL_MAX_CLIP_PLANES                0x0D32
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_PIXEL_MAP_TABLE            0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH         0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH      0x0D36
#define GL_MAX_NAME_STACK_DEPTH           0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH     0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH        0x0D39
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH  0x0D3B
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_INDEX_BITS                     0x0D51
#define GL_RED_BITS                       0x0D52
#define GL_GREEN_BITS                     0x0D53
#define GL_BLUE_BITS                      0x0D54
#define GL_ALPHA_BITS                     0x0D55
#define GL_DEPTH_BITS                     0x0D56
#define GL_STENCIL_BITS                   0x0D57
#define GL_ACCUM_RED_BITS                 0x0D58
#define GL_ACCUM_GREEN_BITS               0x0D59
#define GL_ACCUM_BLUE_BITS                0x0D5A
#define GL_ACCUM_ALPHA_BITS               0x0D5B
#define GL_NAME_STACK_DEPTH               0x0D70
#define GL_AUTO_NORMAL                    0x0D80
#define GL_MAP1_COLOR_4                   0x0D90
#define GL_MAP1_INDEX                     0x0D91
#define GL_MAP1_NORMAL                    0x0D92
#define GL_MAP1_TEXTURE_COORD_1           0x0D93
#define GL_MAP1_TEXTURE_COORD_2           0x0D94
#define GL_MAP1_TEXTURE_COORD_3           0x0D95
#define GL_MAP1_TEXTURE_COORD_4           0x0D96
#define GL_MAP1_VERTEX_3                  0x0D97
#define GL_MAP1_VERTEX_4                  0x0D98
#define GL_MAP2_COLOR_4                   0x0DB0
#define GL_MAP2_INDEX                     0x0DB1
#define GL_MAP2_NORMAL                    0x0DB2
#define GL_MAP2_TEXTURE_COORD_1           0x0DB3
#define GL_MAP2_TEXTURE_COORD_2           0x0DB4
#define GL_MAP2_TEXTURE_COORD_3           0x0DB5
#define GL_MAP2_TEXTURE_COORD_4           0x0DB6
#define GL_MAP2_VERTEX_3                  0x0DB7
#define GL_MAP2_VERTEX_4                  0x0DB8
#define GL_MAP1_GRID_DOMAIN               0x0DD0
#define GL_MAP1_GRID_SEGMENTS             0x0DD1
#define GL_MAP2_GRID_DOMAIN               0x0DD2
#define GL_MAP2_GRID_SEGMENTS             0x0DD3
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_FEEDBACK_BUFFER_POINTER        0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE           0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE           0x0DF2
#define GL_SELECTION_BUFFER_POINTER       0x0DF3
#define GL_SELECTION_BUFFER_SIZE          0x0DF4
/*      GL_TEXTURE_BINDING_1D */
/*      GL_TEXTURE_BINDING_2D */
/*      GL_VERTEX_ARRAY */
/*      GL_NORMAL_ARRAY */
/*      GL_COLOR_ARRAY */
/*      GL_INDEX_ARRAY */
/*      GL_TEXTURE_COORD_ARRAY */
/*      GL_EDGE_FLAG_ARRAY */
/*      GL_VERTEX_ARRAY_SIZE */
/*      GL_VERTEX_ARRAY_TYPE */
/*      GL_VERTEX_ARRAY_STRIDE */
/*      GL_NORMAL_ARRAY_TYPE */
/*      GL_NORMAL_ARRAY_STRIDE */
/*      GL_COLOR_ARRAY_SIZE */
/*      GL_COLOR_ARRAY_TYPE */
/*      GL_COLOR_ARRAY_STRIDE */
/*      GL_INDEX_ARRAY_TYPE */
/*      GL_INDEX_ARRAY_STRIDE */
/*      GL_TEXTURE_COORD_ARRAY_SIZE */
/*      GL_TEXTURE_COORD_ARRAY_TYPE */
/*      GL_TEXTURE_COORD_ARRAY_STRIDE */
/*      GL_EDGE_FLAG_ARRAY_STRIDE */
/*      GL_POLYGON_OFFSET_FACTOR */
/*      GL_POLYGON_OFFSET_UNITS */

/* GetTextureParameter */
/*      GL_TEXTURE_MAG_FILTER */
/*      GL_TEXTURE_MIN_FILTER */
/*      GL_TEXTURE_WRAP_S */
/*      GL_TEXTURE_WRAP_T */
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_TEXTURE_BORDER                 0x1005
/*      GL_TEXTURE_RED_SIZE */
/*      GL_TEXTURE_GREEN_SIZE */
/*      GL_TEXTURE_BLUE_SIZE */
/*      GL_TEXTURE_ALPHA_SIZE */
/*      GL_TEXTURE_LUMINANCE_SIZE */
/*      GL_TEXTURE_INTENSITY_SIZE */
/*      GL_TEXTURE_PRIORITY */
/*      GL_TEXTURE_RESIDENT */

/* HintMode */
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102

/* HintTarget */
/*      GL_PERSPECTIVE_CORRECTION_HINT */
/*      GL_POINT_SMOOTH_HINT */
/*      GL_LINE_SMOOTH_HINT */
/*      GL_POLYGON_SMOOTH_HINT */
/*      GL_FOG_HINT */
/*      GL_PHONG_HINT */

/* IndexPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* LightModelParameter */
/*      GL_LIGHT_MODEL_AMBIENT */
/*      GL_LIGHT_MODEL_LOCAL_VIEWER */
/*      GL_LIGHT_MODEL_TWO_SIDE */

/* LightName */
#define GL_LIGHT0                         0x4000
#define GL_LIGHT1                         0x4001
#define GL_LIGHT2                         0x4002
#define GL_LIGHT3                         0x4003
#define GL_LIGHT4                         0x4004
#define GL_LIGHT5                         0x4005
#define GL_LIGHT6                         0x4006
#define GL_LIGHT7                         0x4007

/* LightParameter */
#define GL_AMBIENT                        0x1200
#define GL_DIFFUSE                        0x1201
#define GL_SPECULAR                       0x1202
#define GL_POSITION                       0x1203
#define GL_SPOT_DIRECTION                 0x1204
#define GL_SPOT_EXPONENT                  0x1205
#define GL_SPOT_CUTOFF                    0x1206
#define GL_CONSTANT_ATTENUATION           0x1207
#define GL_LINEAR_ATTENUATION             0x1208
#define GL_QUADRATIC_ATTENUATION          0x1209

/* InterleavedArrays */
/*      GL_V2F */
/*      GL_V3F */
/*      GL_C4UB_V2F */
/*      GL_C4UB_V3F */
/*      GL_C3F_V3F */
/*      GL_N3F_V3F */
/*      GL_C4F_N3F_V3F */
/*      GL_T2F_V3F */
/*      GL_T4F_V4F */
/*      GL_T2F_C4UB_V3F */
/*      GL_T2F_C3F_V3F */
/*      GL_T2F_N3F_V3F */
/*      GL_T2F_C4F_N3F_V3F */
/*      GL_T4F_C4F_N3F_V4F */

/* ListMode */
#define GL_COMPILE                        0x1300
#define GL_COMPILE_AND_EXECUTE            0x1301

/* ListNameType */
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */
/*      GL_2_BYTES */
/*      GL_3_BYTES */
/*      GL_4_BYTES */

/* LogicOp */
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F

/* MapTarget */
/*      GL_MAP1_COLOR_4 */
/*      GL_MAP1_INDEX */
/*      GL_MAP1_NORMAL */
/*      GL_MAP1_TEXTURE_COORD_1 */
/*      GL_MAP1_TEXTURE_COORD_2 */
/*      GL_MAP1_TEXTURE_COORD_3 */
/*      GL_MAP1_TEXTURE_COORD_4 */
/*      GL_MAP1_VERTEX_3 */
/*      GL_MAP1_VERTEX_4 */
/*      GL_MAP2_COLOR_4 */
/*      GL_MAP2_INDEX */
/*      GL_MAP2_NORMAL */
/*      GL_MAP2_TEXTURE_COORD_1 */
/*      GL_MAP2_TEXTURE_COORD_2 */
/*      GL_MAP2_TEXTURE_COORD_3 */
/*      GL_MAP2_TEXTURE_COORD_4 */
/*      GL_MAP2_VERTEX_3 */
/*      GL_MAP2_VERTEX_4 */

/* MaterialFace */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* MaterialParameter */
#define GL_EMISSION                       0x1600
#define GL_SHININESS                      0x1601
#define GL_AMBIENT_AND_DIFFUSE            0x1602
#define GL_COLOR_INDEXES                  0x1603
/*      GL_AMBIENT */
/*      GL_DIFFUSE */
/*      GL_SPECULAR */

/* MatrixMode */
#define GL_MODELVIEW                      0x1700
#define GL_PROJECTION                     0x1701
#define GL_TEXTURE                        0x1702

/* MeshMode1 */
/*      GL_POINT */
/*      GL_LINE */

/* MeshMode2 */
/*      GL_POINT */
/*      GL_LINE */
/*      GL_FILL */

/* NormalPointerType */
/*      GL_BYTE */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* PixelCopyType */
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802

/* PixelFormat */
#define GL_COLOR_INDEX                    0x1900
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_LUMINANCE                      0x1909
#define GL_LUMINANCE_ALPHA                0x190A

/* PixelMap */
/*      GL_PIXEL_MAP_I_TO_I */
/*      GL_PIXEL_MAP_S_TO_S */
/*      GL_PIXEL_MAP_I_TO_R */
/*      GL_PIXEL_MAP_I_TO_G */
/*      GL_PIXEL_MAP_I_TO_B */
/*      GL_PIXEL_MAP_I_TO_A */
/*      GL_PIXEL_MAP_R_TO_R */
/*      GL_PIXEL_MAP_G_TO_G */
/*      GL_PIXEL_MAP_B_TO_B */
/*      GL_PIXEL_MAP_A_TO_A */

/* PixelStore */
/*      GL_UNPACK_SWAP_BYTES */
/*      GL_UNPACK_LSB_FIRST */
/*      GL_UNPACK_ROW_LENGTH */
/*      GL_UNPACK_SKIP_ROWS */
/*      GL_UNPACK_SKIP_PIXELS */
/*      GL_UNPACK_ALIGNMENT */
/*      GL_PACK_SWAP_BYTES */
/*      GL_PACK_LSB_FIRST */
/*      GL_PACK_ROW_LENGTH */
/*      GL_PACK_SKIP_ROWS */
/*      GL_PACK_SKIP_PIXELS */
/*      GL_PACK_ALIGNMENT */

/* PixelTransfer */
/*      GL_MAP_COLOR */
/*      GL_MAP_STENCIL */
/*      GL_INDEX_SHIFT */
/*      GL_INDEX_OFFSET */
/*      GL_RED_SCALE */
/*      GL_RED_BIAS */
/*      GL_GREEN_SCALE */
/*      GL_GREEN_BIAS */
/*      GL_BLUE_SCALE */
/*      GL_BLUE_BIAS */
/*      GL_ALPHA_SCALE */
/*      GL_ALPHA_BIAS */
/*      GL_DEPTH_SCALE */
/*      GL_DEPTH_BIAS */

/* PixelType */
#define GL_BITMAP                         0x1A00
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */

/* PolygonMode */
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02

/* ReadBufferMode */
/*      GL_FRONT_LEFT */
/*      GL_FRONT_RIGHT */
/*      GL_BACK_LEFT */
/*      GL_BACK_RIGHT */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_LEFT */
/*      GL_RIGHT */
/*      GL_AUX0 */
/*      GL_AUX1 */
/*      GL_AUX2 */
/*      GL_AUX3 */

/* RenderingMode */
#define GL_RENDER                         0x1C00
#define GL_FEEDBACK                       0x1C01
#define GL_SELECT                         0x1C02

/* ShadingModel */
#define GL_FLAT                           0x1D00
#define GL_SMOOTH                         0x1D01


/* StencilFunction */
/*      GL_NEVER */
/*      GL_LESS */
/*      GL_EQUAL */
/*      GL_LEQUAL */
/*      GL_GREATER */
/*      GL_NOTEQUAL */
/*      GL_GEQUAL */
/*      GL_ALWAYS */

/* StencilOp */
/*      GL_ZERO */
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
/*      GL_INVERT */

/* StringName */
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03

/* TextureCoordName */
#define GL_S                              0x2000
#define GL_T                              0x2001
#define GL_R                              0x2002
#define GL_Q                              0x2003

/* TexCoordPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* TextureEnvMode */
#define GL_MODULATE                       0x2100
#define GL_DECAL                          0x2101
/*      GL_BLEND */
/*      GL_REPLACE */

/* TextureEnvParameter */
#define GL_TEXTURE_ENV_MODE               0x2200
#define GL_TEXTURE_ENV_COLOR              0x2201

/* TextureEnvTarget */
#define GL_TEXTURE_ENV                    0x2300

/* TextureGenMode */
#define GL_EYE_LINEAR                     0x2400
#define GL_OBJECT_LINEAR                  0x2401
#define GL_SPHERE_MAP                     0x2402

/* TextureGenParameter */
#define GL_TEXTURE_GEN_MODE               0x2500
#define GL_OBJECT_PLANE                   0x2501
#define GL_EYE_PLANE                      0x2502

/* TextureMagFilter */
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601

/* TextureMinFilter */
/*      GL_NEAREST */
/*      GL_LINEAR */
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703

/* TextureParameterName */
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
/*      GL_TEXTURE_BORDER_COLOR */
/*      GL_TEXTURE_PRIORITY */

/* TextureTarget */
/*      GL_TEXTURE_1D */
/*      GL_TEXTURE_2D */
/*      GL_PROXY_TEXTURE_1D */
/*      GL_PROXY_TEXTURE_2D */

/* TextureWrapMode */
#define GL_CLAMP                          0x2900
#define GL_REPEAT                         0x2901

/* VertexPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* ClientAttribMask */
#define GL_CLIENT_PIXEL_STORE_BIT         0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT        0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS         0xffffffff

/* polygon_offset */
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037

/* texture */
#define GL_ALPHA4                         0x803B
#define GL_ALPHA8                         0x803C
#define GL_ALPHA12                        0x803D
#define GL_ALPHA16                        0x803E
#define GL_LUMINANCE4                     0x803F
#define GL_LUMINANCE8                     0x8040
#define GL_LUMINANCE12                    0x8041
#define GL_LUMINANCE16                    0x8042
#define GL_LUMINANCE4_ALPHA4              0x8043
#define GL_LUMINANCE6_ALPHA2              0x8044
#define GL_LUMINANCE8_ALPHA8              0x8045
#define GL_LUMINANCE12_ALPHA4             0x8046
#define GL_LUMINANCE12_ALPHA12            0x8047
#define GL_LUMINANCE16_ALPHA16            0x8048
#define GL_INTENSITY                      0x8049
#define GL_INTENSITY4                     0x804A
#define GL_INTENSITY8                     0x804B
#define GL_INTENSITY12                    0x804C
#define GL_INTENSITY16                    0x804D
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_TEXTURE_LUMINANCE_SIZE         0x8060
#define GL_TEXTURE_INTENSITY_SIZE         0x8061
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064

/* texture_object */
#define GL_TEXTURE_PRIORITY               0x8066
#define GL_TEXTURE_RESIDENT               0x8067
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069

/* vertex_array */
#define GL_VERTEX_ARRAY                   0x8074
#define GL_NORMAL_ARRAY                   0x8075
#define GL_COLOR_ARRAY                    0x8076
#define GL_INDEX_ARRAY                    0x8077
#define GL_TEXTURE_COORD_ARRAY            0x8078
#define GL_EDGE_FLAG_ARRAY                0x8079
#define GL_VERTEX_ARRAY_SIZE              0x807A
#define GL_VERTEX_ARRAY_TYPE              0x807B
#define GL_VERTEX_ARRAY_STRIDE            0x807C
#define GL_NORMAL_ARRAY_TYPE              0x807E
#define GL_NORMAL_ARRAY_STRIDE            0x807F
#define GL_COLOR_ARRAY_SIZE               0x8081
#define GL_COLOR_ARRAY_TYPE               0x8082
#define GL_COLOR_ARRAY_STRIDE             0x8083
#define GL_INDEX_ARRAY_TYPE               0x8085
#define GL_INDEX_ARRAY_STRIDE             0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE       0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE       0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE     0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE         0x808C
#define GL_VERTEX_ARRAY_POINTER           0x808E
#define GL_NORMAL_ARRAY_POINTER           0x808F
#define GL_COLOR_ARRAY_POINTER            0x8090
#define GL_INDEX_ARRAY_POINTER            0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER    0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER        0x8093
#define GL_V2F                            0x2A20
#define GL_V3F                            0x2A21
#define GL_C4UB_V2F                       0x2A22
#define GL_C4UB_V3F                       0x2A23
#define GL_C3F_V3F                        0x2A24
#define GL_N3F_V3F                        0x2A25
#define GL_C4F_N3F_V3F                    0x2A26
#define GL_T2F_V3F                        0x2A27
#define GL_T4F_V4F                        0x2A28
#define GL_T2F_C4UB_V3F                   0x2A29
#define GL_T2F_C3F_V3F                    0x2A2A
#define GL_T2F_N3F_V3F                    0x2A2B
#define GL_T2F_C4F_N3F_V3F                0x2A2C
#define GL_T4F_C4F_N3F_V4F                0x2A2D

/* Extensions */
#define GL_EXT_vertex_array               1
#define GL_EXT_bgra                       1
#define GL_EXT_paletted_texture           1
#define GL_WIN_swap_hint                  1
#define GL_WIN_draw_range_elements        1
// #define GL_WIN_phong_shading              1
// #define GL_WIN_specular_fog               1

/* EXT_vertex_array */
#define GL_VERTEX_ARRAY_EXT               0x8074
#define GL_NORMAL_ARRAY_EXT               0x8075
#define GL_COLOR_ARRAY_EXT                0x8076
#define GL_INDEX_ARRAY_EXT                0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT        0x8078
#define GL_EDGE_FLAG_ARRAY_EXT            0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT          0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT          0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT        0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT         0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT          0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT        0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT         0x8080
#define GL_COLOR_ARRAY_SIZE_EXT           0x8081
#define GL_COLOR_ARRAY_TYPE_EXT           0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT         0x8083
#define GL_COLOR_ARRAY_COUNT_EXT          0x8084
#define GL_INDEX_ARRAY_TYPE_EXT           0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT         0x8086
#define GL_INDEX_ARRAY_COUNT_EXT          0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT   0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT   0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT  0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT     0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT      0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT       0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT       0x808F
#define GL_COLOR_ARRAY_POINTER_EXT        0x8090
#define GL_INDEX_ARRAY_POINTER_EXT        0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT    0x8093
#define GL_DOUBLE_EXT                     GL_DOUBLE

/* EXT_bgra */
#define GL_BGR_EXT                        0x80E0
#define GL_BGRA_EXT                       0x80E1

/* EXT_paletted_texture */

/* These must match the GL_COLOR_TABLE_*_SGI enumerants */
#define GL_COLOR_TABLE_FORMAT_EXT         0x80D8
#define GL_COLOR_TABLE_WIDTH_EXT          0x80D9
#define GL_COLOR_TABLE_RED_SIZE_EXT       0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_EXT     0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_EXT      0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_EXT     0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_EXT 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_EXT 0x80DF

#define GL_COLOR_INDEX1_EXT               0x80E2
#define GL_COLOR_INDEX2_EXT               0x80E3
#define GL_COLOR_INDEX4_EXT               0x80E4
#define GL_COLOR_INDEX8_EXT               0x80E5
#define GL_COLOR_INDEX12_EXT              0x80E6
#define GL_COLOR_INDEX16_EXT              0x80E7

/* WIN_draw_range_elements */
#define GL_MAX_ELEMENTS_VERTICES_WIN      0x80E8
#define GL_MAX_ELEMENTS_INDICES_WIN       0x80E9

/* WIN_phong_shading */
#define GL_PHONG_WIN                      0x80EA 
#define GL_PHONG_HINT_WIN                 0x80EB 

/* WIN_specular_fog */
#define GL_FOG_SPECULAR_TEXTURE_WIN       0x80EC

/* For compatibility with OpenGL v1.0 */
#define GL_LOGIC_OP GL_INDEX_LOGIC_OP
#define GL_TEXTURE_COMPONENTS GL_TEXTURE_INTERNAL_FORMAT

typedef void (__stdcall *PFAccum) (GLenum op, GLfloat value);
typedef void (__stdcall *PFAlphaFunc) (GLenum func, GLclampf ref);
typedef GLboolean (__stdcall *PFAreTexturesResident) (GLsizei n, const GLuint *textures, GLboolean *residences);
typedef void (__stdcall *PFArrayElement) (GLint i);
typedef void (__stdcall *PFBegin) (GLenum mode);
typedef void (__stdcall *PFBindTexture) (GLenum target, GLuint texture);
typedef void (__stdcall *PFBitmap) (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
typedef void (__stdcall *PFBlendFunc) (GLenum sfactor, GLenum dfactor);
typedef void (__stdcall *PFCallList) (GLuint list);
typedef void (__stdcall *PFCallLists) (GLsizei n, GLenum type, const GLvoid *lists);
typedef void (__stdcall *PFClear) (GLbitfield mask);
typedef void (__stdcall *PFClearAccum) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (__stdcall *PFClearColor) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (__stdcall *PFClearDepth) (GLclampd depth);
typedef void (__stdcall *PFClearIndex) (GLfloat c);
typedef void (__stdcall *PFClearStencil) (GLint s);
typedef void (__stdcall *PFClipPlane) (GLenum plane, const GLdouble *equation);
typedef void (__stdcall *PFColor3b) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (__stdcall *PFColor3bv) (const GLbyte *v);
typedef void (__stdcall *PFColor3d) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (__stdcall *PFColor3dv) (const GLdouble *v);
typedef void (__stdcall *PFColor3f) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (__stdcall *PFColor3fv) (const GLfloat *v);
typedef void (__stdcall *PFColor3i) (GLint red, GLint green, GLint blue);
typedef void (__stdcall *PFColor3iv) (const GLint *v);
typedef void (__stdcall *PFColor3s) (GLshort red, GLshort green, GLshort blue);
typedef void (__stdcall *PFColor3sv) (const GLshort *v);
typedef void (__stdcall *PFColor3ub) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (__stdcall *PFColor3ubv) (const GLubyte *v);
typedef void (__stdcall *PFColor3ui) (GLuint red, GLuint green, GLuint blue);
typedef void (__stdcall *PFColor3uiv) (const GLuint *v);
typedef void (__stdcall *PFColor3us) (GLushort red, GLushort green, GLushort blue);
typedef void (__stdcall *PFColor3usv) (const GLushort *v);
typedef void (__stdcall *PFColor4b) (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef void (__stdcall *PFColor4bv) (const GLbyte *v);
typedef void (__stdcall *PFColor4d) (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef void (__stdcall *PFColor4dv) (const GLdouble *v);
typedef void (__stdcall *PFColor4f) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (__stdcall *PFColor4fv) (const GLfloat *v);
typedef void (__stdcall *PFColor4i) (GLint red, GLint green, GLint blue, GLint alpha);
typedef void (__stdcall *PFColor4iv) (const GLint *v);
typedef void (__stdcall *PFColor4s) (GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef void (__stdcall *PFColor4sv) (const GLshort *v);
typedef void (__stdcall *PFColor4ub) (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (__stdcall *PFColor4ubv) (const GLubyte *v);
typedef void (__stdcall *PFColor4ui) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (__stdcall *PFColor4uiv) (const GLuint *v);
typedef void (__stdcall *PFColor4us) (GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef void (__stdcall *PFColor4usv) (const GLushort *v);
typedef void (__stdcall *PFColorMask) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (__stdcall *PFColorMaterial) (GLenum face, GLenum mode);
typedef void (__stdcall *PFColorPointer) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (__stdcall *PFCopyPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef void (__stdcall *PFCopyTexImage1D) (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (__stdcall *PFCopyTexImage2D) (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (__stdcall *PFCopyTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (__stdcall *PFCopyTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (__stdcall *PFCullFace) (GLenum mode);
typedef void (__stdcall *PFDeleteLists) (GLuint list, GLsizei range);
typedef void (__stdcall *PFDeleteTextures) (GLsizei n, const GLuint *textures);
typedef void (__stdcall *PFDepthFunc) (GLenum func);
typedef void (__stdcall *PFDepthMask) (GLboolean flag);
typedef void (__stdcall *PFDepthRange) (GLclampd zNear, GLclampd zFar);
typedef void (__stdcall *PFDisable) (GLenum cap);
typedef void (__stdcall *PFDisableClientState) (GLenum array);
typedef void (__stdcall *PFDrawArrays) (GLenum mode, GLint first, GLsizei count);
typedef void (__stdcall *PFDrawBuffer) (GLenum mode);
typedef void (__stdcall *PFDrawElements) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
typedef void (__stdcall *PFDrawPixels) (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (__stdcall *PFEdgeFlag) (GLboolean flag);
typedef void (__stdcall *PFEdgeFlagPointer) (GLsizei stride, const GLvoid *pointer);
typedef void (__stdcall *PFEdgeFlagv) (const GLboolean *flag);
typedef void (__stdcall *PFEnable) (GLenum cap);
typedef void (__stdcall *PFEnableClientState) (GLenum array);
typedef void (__stdcall *PFEnd) (void);
typedef void (__stdcall *PFEndList) (void);
typedef void (__stdcall *PFEvalCoord1d) (GLdouble u);
typedef void (__stdcall *PFEvalCoord1dv) (const GLdouble *u);
typedef void (__stdcall *PFEvalCoord1f) (GLfloat u);
typedef void (__stdcall *PFEvalCoord1fv) (const GLfloat *u);
typedef void (__stdcall *PFEvalCoord2d) (GLdouble u, GLdouble v);
typedef void (__stdcall *PFEvalCoord2dv) (const GLdouble *u);
typedef void (__stdcall *PFEvalCoord2f) (GLfloat u, GLfloat v);
typedef void (__stdcall *PFEvalCoord2fv) (const GLfloat *u);
typedef void (__stdcall *PFEvalMesh1) (GLenum mode, GLint i1, GLint i2);
typedef void (__stdcall *PFEvalMesh2) (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef void (__stdcall *PFEvalPoint1) (GLint i);
typedef void (__stdcall *PFEvalPoint2) (GLint i, GLint j);
typedef void (__stdcall *PFFeedbackBuffer) (GLsizei size, GLenum type, GLfloat *buffer);
typedef void (__stdcall *PFFinish) (void);
typedef void (__stdcall *PFFlush) (void);
typedef void (__stdcall *PFFogf) (GLenum pname, GLfloat param);
typedef void (__stdcall *PFFogfv) (GLenum pname, const GLfloat *params);
typedef void (__stdcall *PFFogi) (GLenum pname, GLint param);
typedef void (__stdcall *PFFogiv) (GLenum pname, const GLint *params);
typedef void (__stdcall *PFFrontFace) (GLenum mode);
typedef void (__stdcall *PFFrustum) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef GLuint (__stdcall *PFGenLists) (GLsizei range);
typedef void (__stdcall *PFGenTextures) (GLsizei n, GLuint *textures);
typedef void (__stdcall *PFGetBooleanv) (GLenum pname, GLboolean *params);
typedef void (__stdcall *PFGetClipPlane) (GLenum plane, GLdouble *equation);
typedef void (__stdcall *PFGetDoublev) (GLenum pname, GLdouble *params);
typedef GLenum (__stdcall *PFGetError) (void);
typedef void (__stdcall *PFGetFloatv) (GLenum pname, GLfloat *params);
typedef void (__stdcall *PFGetIntegerv) (GLenum pname, GLint *params);
typedef void (__stdcall *PFGetLightfv) (GLenum light, GLenum pname, GLfloat *params);
typedef void (__stdcall *PFGetLightiv) (GLenum light, GLenum pname, GLint *params);
typedef void (__stdcall *PFGetMapdv) (GLenum target, GLenum query, GLdouble *v);
typedef void (__stdcall *PFGetMapfv) (GLenum target, GLenum query, GLfloat *v);
typedef void (__stdcall *PFGetMapiv) (GLenum target, GLenum query, GLint *v);
typedef void (__stdcall *PFGetMaterialfv) (GLenum face, GLenum pname, GLfloat *params);
typedef void (__stdcall *PFGetMaterialiv) (GLenum face, GLenum pname, GLint *params);
typedef void (__stdcall *PFGetPixelMapfv) (GLenum map, GLfloat *values);
typedef void (__stdcall *PFGetPixelMapuiv) (GLenum map, GLuint *values);
typedef void (__stdcall *PFGetPixelMapusv) (GLenum map, GLushort *values);
typedef void (__stdcall *PFGetPointerv) (GLenum pname, GLvoid* *params);
typedef void (__stdcall *PFGetPolygonStipple) (GLubyte *mask);
typedef const GLubyte * (__stdcall *PFGetString) (GLenum name);
typedef void (__stdcall *PFGetTexEnvfv) (GLenum target, GLenum pname, GLfloat *params);
typedef void (__stdcall *PFGetTexEnviv) (GLenum target, GLenum pname, GLint *params);
typedef void (__stdcall *PFGetTexGendv) (GLenum coord, GLenum pname, GLdouble *params);
typedef void (__stdcall *PFGetTexGenfv) (GLenum coord, GLenum pname, GLfloat *params);
typedef void (__stdcall *PFGetTexGeniv) (GLenum coord, GLenum pname, GLint *params);
typedef void (__stdcall *PFGetTexImage) (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
typedef void (__stdcall *PFGetTexLevelParameterfv) (GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (__stdcall *PFGetTexLevelParameteriv) (GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (__stdcall *PFGetTexParameterfv) (GLenum target, GLenum pname, GLfloat *params);
typedef void (__stdcall *PFGetTexParameteriv) (GLenum target, GLenum pname, GLint *params);
typedef void (__stdcall *PFHint) (GLenum target, GLenum mode);
typedef void (__stdcall *PFIndexMask) (GLuint mask);
typedef void (__stdcall *PFIndexPointer) (GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (__stdcall *PFIndexd) (GLdouble c);
typedef void (__stdcall *PFIndexdv) (const GLdouble *c);
typedef void (__stdcall *PFIndexf) (GLfloat c);
typedef void (__stdcall *PFIndexfv) (const GLfloat *c);
typedef void (__stdcall *PFIndexi) (GLint c);
typedef void (__stdcall *PFIndexiv) (const GLint *c);
typedef void (__stdcall *PFIndexs) (GLshort c);
typedef void (__stdcall *PFIndexsv) (const GLshort *c);
typedef void (__stdcall *PFIndexub) (GLubyte c);
typedef void (__stdcall *PFIndexubv) (const GLubyte *c);
typedef void (__stdcall *PFInitNames) (void);
typedef void (__stdcall *PFInterleavedArrays) (GLenum format, GLsizei stride, const GLvoid *pointer);
typedef GLboolean (__stdcall *PFIsEnabled) (GLenum cap);
typedef GLboolean (__stdcall *PFIsList) (GLuint list);
typedef GLboolean (__stdcall *PFIsTexture) (GLuint texture);
typedef void (__stdcall *PFLightModelf) (GLenum pname, GLfloat param);
typedef void (__stdcall *PFLightModelfv) (GLenum pname, const GLfloat *params);
typedef void (__stdcall *PFLightModeli) (GLenum pname, GLint param);
typedef void (__stdcall *PFLightModeliv) (GLenum pname, const GLint *params);
typedef void (__stdcall *PFLightf) (GLenum light, GLenum pname, GLfloat param);
typedef void (__stdcall *PFLightfv) (GLenum light, GLenum pname, const GLfloat *params);
typedef void (__stdcall *PFLighti) (GLenum light, GLenum pname, GLint param);
typedef void (__stdcall *PFLightiv) (GLenum light, GLenum pname, const GLint *params);
typedef void (__stdcall *PFLineStipple) (GLint factor, GLushort pattern);
typedef void (__stdcall *PFLineWidth) (GLfloat width);
typedef void (__stdcall *PFListBase) (GLuint base);
typedef void (__stdcall *PFLoadIdentity) (void);
typedef void (__stdcall *PFLoadMatrixd) (const GLdouble *m);
typedef void (__stdcall *PFLoadMatrixf) (const GLfloat *m);
typedef void (__stdcall *PFLoadName) (GLuint name);
typedef void (__stdcall *PFLogicOp) (GLenum opcode);
typedef void (__stdcall *PFMap1d) (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
typedef void (__stdcall *PFMap1f) (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
typedef void (__stdcall *PFMap2d) (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
typedef void (__stdcall *PFMap2f) (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
typedef void (__stdcall *PFMapGrid1d) (GLint un, GLdouble u1, GLdouble u2);
typedef void (__stdcall *PFMapGrid1f) (GLint un, GLfloat u1, GLfloat u2);
typedef void (__stdcall *PFMapGrid2d) (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef void (__stdcall *PFMapGrid2f) (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef void (__stdcall *PFMaterialf) (GLenum face, GLenum pname, GLfloat param);
typedef void (__stdcall *PFMaterialfv) (GLenum face, GLenum pname, const GLfloat *params);
typedef void (__stdcall *PFMateriali) (GLenum face, GLenum pname, GLint param);
typedef void (__stdcall *PFMaterialiv) (GLenum face, GLenum pname, const GLint *params);
typedef void (__stdcall *PFMatrixMode) (GLenum mode);
typedef void (__stdcall *PFMultMatrixd) (const GLdouble *m);
typedef void (__stdcall *PFMultMatrixf) (const GLfloat *m);
typedef void (__stdcall *PFNewList) (GLuint list, GLenum mode);
typedef void (__stdcall *PFNormal3b) (GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (__stdcall *PFNormal3bv) (const GLbyte *v);
typedef void (__stdcall *PFNormal3d) (GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (__stdcall *PFNormal3dv) (const GLdouble *v);
typedef void (__stdcall *PFNormal3f) (GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (__stdcall *PFNormal3fv) (const GLfloat *v);
typedef void (__stdcall *PFNormal3i) (GLint nx, GLint ny, GLint nz);
typedef void (__stdcall *PFNormal3iv) (const GLint *v);
typedef void (__stdcall *PFNormal3s) (GLshort nx, GLshort ny, GLshort nz);
typedef void (__stdcall *PFNormal3sv) (const GLshort *v);
typedef void (__stdcall *PFNormalPointer) (GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (__stdcall *PFOrtho) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (__stdcall *PFPassThrough) (GLfloat token);
typedef void (__stdcall *PFPixelMapfv) (GLenum map, GLsizei mapsize, const GLfloat *values);
typedef void (__stdcall *PFPixelMapuiv) (GLenum map, GLsizei mapsize, const GLuint *values);
typedef void (__stdcall *PFPixelMapusv) (GLenum map, GLsizei mapsize, const GLushort *values);
typedef void (__stdcall *PFPixelStoref) (GLenum pname, GLfloat param);
typedef void (__stdcall *PFPixelStorei) (GLenum pname, GLint param);
typedef void (__stdcall *PFPixelTransferf) (GLenum pname, GLfloat param);
typedef void (__stdcall *PFPixelTransferi) (GLenum pname, GLint param);
typedef void (__stdcall *PFPixelZoom) (GLfloat xfactor, GLfloat yfactor);
typedef void (__stdcall *PFPointSize) (GLfloat size);
typedef void (__stdcall *PFPolygonMode) (GLenum face, GLenum mode);
typedef void (__stdcall *PFPolygonOffset) (GLfloat factor, GLfloat units);
typedef void (__stdcall *PFPolygonStipple) (const GLubyte *mask);
typedef void (__stdcall *PFPopAttrib) (void);
typedef void (__stdcall *PFPopClientAttrib) (void);
typedef void (__stdcall *PFPopMatrix) (void);
typedef void (__stdcall *PFPopName) (void);
typedef void (__stdcall *PFPrioritizeTextures) (GLsizei n, const GLuint *textures, const GLclampf *priorities);
typedef void (__stdcall *PFPushAttrib) (GLbitfield mask);
typedef void (__stdcall *PFPushClientAttrib) (GLbitfield mask);
typedef void (__stdcall *PFPushMatrix) (void);
typedef void (__stdcall *PFPushName) (GLuint name);
typedef void (__stdcall *PFRasterPos2d) (GLdouble x, GLdouble y);
typedef void (__stdcall *PFRasterPos2dv) (const GLdouble *v);
typedef void (__stdcall *PFRasterPos2f) (GLfloat x, GLfloat y);
typedef void (__stdcall *PFRasterPos2fv) (const GLfloat *v);
typedef void (__stdcall *PFRasterPos2i) (GLint x, GLint y);
typedef void (__stdcall *PFRasterPos2iv) (const GLint *v);
typedef void (__stdcall *PFRasterPos2s) (GLshort x, GLshort y);
typedef void (__stdcall *PFRasterPos2sv) (const GLshort *v);
typedef void (__stdcall *PFRasterPos3d) (GLdouble x, GLdouble y, GLdouble z);
typedef void (__stdcall *PFRasterPos3dv) (const GLdouble *v);
typedef void (__stdcall *PFRasterPos3f) (GLfloat x, GLfloat y, GLfloat z);
typedef void (__stdcall *PFRasterPos3fv) (const GLfloat *v);
typedef void (__stdcall *PFRasterPos3i) (GLint x, GLint y, GLint z);
typedef void (__stdcall *PFRasterPos3iv) (const GLint *v);
typedef void (__stdcall *PFRasterPos3s) (GLshort x, GLshort y, GLshort z);
typedef void (__stdcall *PFRasterPos3sv) (const GLshort *v);
typedef void (__stdcall *PFRasterPos4d) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (__stdcall *PFRasterPos4dv) (const GLdouble *v);
typedef void (__stdcall *PFRasterPos4f) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (__stdcall *PFRasterPos4fv) (const GLfloat *v);
typedef void (__stdcall *PFRasterPos4i) (GLint x, GLint y, GLint z, GLint w);
typedef void (__stdcall *PFRasterPos4iv) (const GLint *v);
typedef void (__stdcall *PFRasterPos4s) (GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (__stdcall *PFRasterPos4sv) (const GLshort *v);
typedef void (__stdcall *PFReadBuffer) (GLenum mode);
typedef void (__stdcall *PFReadPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
typedef void (__stdcall *PFRectd) (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
typedef void (__stdcall *PFRectdv) (const GLdouble *v1, const GLdouble *v2);
typedef void (__stdcall *PFRectf) (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
typedef void (__stdcall *PFRectfv) (const GLfloat *v1, const GLfloat *v2);
typedef void (__stdcall *PFRecti) (GLint x1, GLint y1, GLint x2, GLint y2);
typedef void (__stdcall *PFRectiv) (const GLint *v1, const GLint *v2);
typedef void (__stdcall *PFRects) (GLshort x1, GLshort y1, GLshort x2, GLshort y2);
typedef void (__stdcall *PFRectsv) (const GLshort *v1, const GLshort *v2);
typedef GLint (__stdcall *PFRenderMode) (GLenum mode);
typedef void (__stdcall *PFRotated) (GLdouble anGLe, GLdouble x, GLdouble y, GLdouble z);
typedef void (__stdcall *PFRotatef) (GLfloat anGLe, GLfloat x, GLfloat y, GLfloat z);
typedef void (__stdcall *PFScaled) (GLdouble x, GLdouble y, GLdouble z);
typedef void (__stdcall *PFScalef) (GLfloat x, GLfloat y, GLfloat z);
typedef void (__stdcall *PFScissor) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (__stdcall *PFSelectBuffer) (GLsizei size, GLuint *buffer);
typedef void (__stdcall *PFShadeModel) (GLenum mode);
typedef void (__stdcall *PFStencilFunc) (GLenum func, GLint ref, GLuint mask);
typedef void (__stdcall *PFStencilMask) (GLuint mask);
typedef void (__stdcall *PFStencilOp) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void (__stdcall *PFTexCoord1d) (GLdouble s);
typedef void (__stdcall *PFTexCoord1dv) (const GLdouble *v);
typedef void (__stdcall *PFTexCoord1f) (GLfloat s);
typedef void (__stdcall *PFTexCoord1fv) (const GLfloat *v);
typedef void (__stdcall *PFTexCoord1i) (GLint s);
typedef void (__stdcall *PFTexCoord1iv) (const GLint *v);
typedef void (__stdcall *PFTexCoord1s) (GLshort s);
typedef void (__stdcall *PFTexCoord1sv) (const GLshort *v);
typedef void (__stdcall *PFTexCoord2d) (GLdouble s, GLdouble t);
typedef void (__stdcall *PFTexCoord2dv) (const GLdouble *v);
typedef void (__stdcall *PFTexCoord2f) (GLfloat s, GLfloat t);
typedef void (__stdcall *PFTexCoord2fv) (const GLfloat *v);
typedef void (__stdcall *PFTexCoord2i) (GLint s, GLint t);
typedef void (__stdcall *PFTexCoord2iv) (const GLint *v);
typedef void (__stdcall *PFTexCoord2s) (GLshort s, GLshort t);
typedef void (__stdcall *PFTexCoord2sv) (const GLshort *v);
typedef void (__stdcall *PFTexCoord3d) (GLdouble s, GLdouble t, GLdouble r);
typedef void (__stdcall *PFTexCoord3dv) (const GLdouble *v);
typedef void (__stdcall *PFTexCoord3f) (GLfloat s, GLfloat t, GLfloat r);
typedef void (__stdcall *PFTexCoord3fv) (const GLfloat *v);
typedef void (__stdcall *PFTexCoord3i) (GLint s, GLint t, GLint r);
typedef void (__stdcall *PFTexCoord3iv) (const GLint *v);
typedef void (__stdcall *PFTexCoord3s) (GLshort s, GLshort t, GLshort r);
typedef void (__stdcall *PFTexCoord3sv) (const GLshort *v);
typedef void (__stdcall *PFTexCoord4d) (GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (__stdcall *PFTexCoord4dv) (const GLdouble *v);
typedef void (__stdcall *PFTexCoord4f) (GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (__stdcall *PFTexCoord4fv) (const GLfloat *v);
typedef void (__stdcall *PFTexCoord4i) (GLint s, GLint t, GLint r, GLint q);
typedef void (__stdcall *PFTexCoord4iv) (const GLint *v);
typedef void (__stdcall *PFTexCoord4s) (GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (__stdcall *PFTexCoord4sv) (const GLshort *v);
typedef void (__stdcall *PFTexCoordPointer) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (__stdcall *PFTexEnvf) (GLenum target, GLenum pname, GLfloat param);
typedef void (__stdcall *PFTexEnvfv) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (__stdcall *PFTexEnvi) (GLenum target, GLenum pname, GLint param);
typedef void (__stdcall *PFTexEnviv) (GLenum target, GLenum pname, const GLint *params);
typedef void (__stdcall *PFTexGend) (GLenum coord, GLenum pname, GLdouble param);
typedef void (__stdcall *PFTexGendv) (GLenum coord, GLenum pname, const GLdouble *params);
typedef void (__stdcall *PFTexGenf) (GLenum coord, GLenum pname, GLfloat param);
typedef void (__stdcall *PFTexGenfv) (GLenum coord, GLenum pname, const GLfloat *params);
typedef void (__stdcall *PFTexGeni) (GLenum coord, GLenum pname, GLint param);
typedef void (__stdcall *PFTexGeniv) (GLenum coord, GLenum pname, const GLint *params);
typedef void (__stdcall *PFTexImage1D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (__stdcall *PFTexImage2D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (__stdcall *PFTexParameterf) (GLenum target, GLenum pname, GLfloat param);
typedef void (__stdcall *PFTexParameterfv) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (__stdcall *PFTexParameteri) (GLenum target, GLenum pname, GLint param);
typedef void (__stdcall *PFTexParameteriv) (GLenum target, GLenum pname, const GLint *params);
typedef void (__stdcall *PFTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (__stdcall *PFTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (__stdcall *PFTranslated) (GLdouble x, GLdouble y, GLdouble z);
typedef void (__stdcall *PFTranslatef) (GLfloat x, GLfloat y, GLfloat z);
typedef void (__stdcall *PFVertex2d) (GLdouble x, GLdouble y);
typedef void (__stdcall *PFVertex2dv) (const GLdouble *v);
typedef void (__stdcall *PFVertex2f) (GLfloat x, GLfloat y);
typedef void (__stdcall *PFVertex2fv) (const GLfloat *v);
typedef void (__stdcall *PFVertex2i) (GLint x, GLint y);
typedef void (__stdcall *PFVertex2iv) (const GLint *v);
typedef void (__stdcall *PFVertex2s) (GLshort x, GLshort y);
typedef void (__stdcall *PFVertex2sv) (const GLshort *v);
typedef void (__stdcall *PFVertex3d) (GLdouble x, GLdouble y, GLdouble z);
typedef void (__stdcall *PFVertex3dv) (const GLdouble *v);
typedef void (__stdcall *PFVertex3f) (GLfloat x, GLfloat y, GLfloat z);
typedef void (__stdcall *PFVertex3fv) (const GLfloat *v);
typedef void (__stdcall *PFVertex3i) (GLint x, GLint y, GLint z);
typedef void (__stdcall *PFVertex3iv) (const GLint *v);
typedef void (__stdcall *PFVertex3s) (GLshort x, GLshort y, GLshort z);
typedef void (__stdcall *PFVertex3sv) (const GLshort *v);
typedef void (__stdcall *PFVertex4d) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (__stdcall *PFVertex4dv) (const GLdouble *v);
typedef void (__stdcall *PFVertex4f) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (__stdcall *PFVertex4fv) (const GLfloat *v);
typedef void (__stdcall *PFVertex4i) (GLint x, GLint y, GLint z, GLint w);
typedef void (__stdcall *PFVertex4iv) (const GLint *v);
typedef void (__stdcall *PFVertex4s) (GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (__stdcall *PFVertex4sv) (const GLshort *v);
typedef void (__stdcall *PFVertexPointer) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (__stdcall *PFViewport) (GLint x, GLint y, GLsizei width, GLsizei height);

/* EXT_vertex_array */
typedef void (__stdcall * PFNGLARRAYELEMENTEXTPROC) (GLint i);
typedef void (__stdcall * PFNGLDRAWARRAYSEXTPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (__stdcall * PFNGLVERTEXPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (__stdcall * PFNGLNORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (__stdcall * PFNGLCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (__stdcall * PFNGLINDEXPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (__stdcall * PFNGLTEXCOORDPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (__stdcall * PFNGLEDGEFLAGPOINTEREXTPROC) (GLsizei stride, GLsizei count, const GLboolean *pointer);
typedef void (__stdcall * PFNGLGETPOINTERVEXTPROC) (GLenum pname, GLvoid* *params);
typedef void (__stdcall * PFNGLARRAYELEMENTARRAYEXTPROC)(GLenum mode, GLsizei count, const GLvoid* pi);

/* WIN_draw_range_elements */
typedef void (__stdcall * PFNGLDRAWRANGEELEMENTSWINPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);

/* WIN_swap_hint */
typedef void (__stdcall * PFNGLADDSWAPHINTRECTWINPROC)  (GLint x, GLint y, GLsizei width, GLsizei height);

/* EXT_paletted_texture */
typedef void (__stdcall * PFNGLCOLORTABLEEXTPROC)(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid *data);
typedef void (__stdcall * PFNGLCOLORSUBTABLEEXTPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
typedef void (__stdcall * PFNGLGETCOLORTABLEEXTPROC)(GLenum target, GLenum format, GLenum type, GLvoid *data);
typedef void (__stdcall * PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (__stdcall * PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);

typedef HGLRC (__stdcall *PFCreateContext)(HDC hDC);
typedef BOOL (__stdcall *PFMakeCurrent)(HDC hDC, HGLRC hRC);
typedef BOOL (__stdcall *PFDeleteContext)(HGLRC hRC);
typedef PROC (__stdcall *PFGetProcAddress)(LPCSTR lpszProc);
typedef BOOL (__stdcall * PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

extern PFAccum glAccum;
extern PFAlphaFunc glAlphaFunc;
extern PFAreTexturesResident glAreTexturesResident;
extern PFArrayElement glArrayElement;
extern PFBegin glBegin;
extern PFBindTexture glBindTexture;
extern PFBitmap glBitmap;
extern PFBlendFunc glBlendFunc;
extern PFCallList glCallList;
extern PFCallLists glCallLists;
extern PFClear glClear;
extern PFClearAccum glClearAccum;
extern PFClearColor glClearColor;
extern PFClearDepth glClearDepth;
extern PFClearIndex glClearIndex;
extern PFClearStencil glClearStencil;
extern PFClipPlane glClipPlane;
extern PFColor3b glColor3b;
extern PFColor3bv glColor3bv;
extern PFColor3d glColor3d;
extern PFColor3dv glColor3dv;
extern PFColor3f glColor3f;
extern PFColor3fv glColor3fv;
extern PFColor3i glColor3i;
extern PFColor3iv glColor3iv;
extern PFColor3s glColor3s;
extern PFColor3sv glColor3sv;
extern PFColor3ub glColor3ub;
extern PFColor3ubv glColor3ubv;
extern PFColor3ui glColor3ui;
extern PFColor3uiv glColor3uiv;
extern PFColor3us glColor3us;
extern PFColor3usv glColor3usv;
extern PFColor4b glColor4b;
extern PFColor4bv glColor4bv;
extern PFColor4d glColor4d;
extern PFColor4dv glColor4dv;
extern PFColor4f glColor4f;
extern PFColor4fv glColor4fv;
extern PFColor4i glColor4i;
extern PFColor4iv glColor4iv;
extern PFColor4s glColor4s;
extern PFColor4sv glColor4sv;
extern PFColor4ub glColor4ub;
extern PFColor4ubv glColor4ubv;
extern PFColor4ui glColor4ui;
extern PFColor4uiv glColor4uiv;
extern PFColor4us glColor4us;
extern PFColor4usv glColor4usv;
extern PFColorMask glColorMask;
extern PFColorMaterial glColorMaterial;
extern PFColorPointer glColorPointer;
extern PFCopyPixels glCopyPixels;
extern PFCopyTexImage1D glCopyTexImage1D;
extern PFCopyTexImage2D glCopyTexImage2D;
extern PFCopyTexSubImage1D glCopyTexSubImage1D;
extern PFCopyTexSubImage2D glCopyTexSubImage2D;
extern PFCullFace glCullFace;
extern PFDeleteLists glDeleteLists;
extern PFDeleteTextures glDeleteTextures;
extern PFDepthFunc glDepthFunc;
extern PFDepthMask glDepthMask;
extern PFDepthRange glDepthRange;
extern PFDisable glDisable;
extern PFDisableClientState glDisableClientState;
extern PFDrawArrays glDrawArrays;
extern PFDrawBuffer glDrawBuffer;
extern PFDrawElements glDrawElements;
extern PFDrawPixels glDrawPixels;
extern PFEdgeFlag glEdgeFlag;
extern PFEdgeFlagPointer glEdgeFlagPointer;
extern PFEdgeFlagv glEdgeFlagv;
extern PFEnable glEnable;
extern PFEnableClientState glEnableClientState;
extern PFEnd glEnd;
extern PFEndList glEndList;
extern PFEvalCoord1d glEvalCoord1d;
extern PFEvalCoord1dv glEvalCoord1dv;
extern PFEvalCoord1f glEvalCoord1f;
extern PFEvalCoord1fv glEvalCoord1fv;
extern PFEvalCoord2d glEvalCoord2d;
extern PFEvalCoord2dv glEvalCoord2dv;
extern PFEvalCoord2f glEvalCoord2f;
extern PFEvalCoord2fv glEvalCoord2fv;
extern PFEvalMesh1 glEvalMesh1;
extern PFEvalMesh2 glEvalMesh2;
extern PFEvalPoint1 glEvalPoint1;
extern PFEvalPoint2 glEvalPoint2;
extern PFFeedbackBuffer glFeedbackBuffer;
extern PFFinish glFinish;
extern PFFlush glFlush;
extern PFFogf glFogf;
extern PFFogfv glFogfv;
extern PFFogi glFogi;
extern PFFogiv glFogiv;
extern PFFrontFace glFrontFace;
extern PFFrustum glFrustum;
extern PFGenLists glGenLists;
extern PFGenTextures glGenTextures;
extern PFGetBooleanv glGetBooleanv;
extern PFGetClipPlane glGetClipPlane;
extern PFGetDoublev glGetDoublev;
extern PFGetError glGetError;
extern PFGetFloatv glGetFloatv;
extern PFGetIntegerv glGetIntegerv;
extern PFGetLightfv glGetLightfv;
extern PFGetLightiv glGetLightiv;
extern PFGetMapdv glGetMapdv;
extern PFGetMapfv glGetMapfv;
extern PFGetMapiv glGetMapiv;
extern PFGetMaterialfv glGetMaterialfv;
extern PFGetMaterialiv glGetMaterialiv;
extern PFGetPixelMapfv glGetPixelMapfv;
extern PFGetPixelMapuiv glGetPixelMapuiv;
extern PFGetPixelMapusv glGetPixelMapusv;
extern PFGetPointerv glGetPointerv;
extern PFGetPolygonStipple glGetPolygonStipple;
extern PFGetString glGetString;
extern PFGetTexEnvfv glGetTexEnvfv;
extern PFGetTexEnviv glGetTexEnviv;
extern PFGetTexGendv glGetTexGendv;
extern PFGetTexGenfv glGetTexGenfv;
extern PFGetTexGeniv glGetTexGeniv;
extern PFGetTexImage glGetTexImage;
extern PFGetTexLevelParameterfv glGetTexLevelParameterfv;
extern PFGetTexLevelParameteriv glGetTexLevelParameteriv;
extern PFGetTexParameterfv glGetTexParameterfv;
extern PFGetTexParameteriv glGetTexParameteriv;
extern PFHint glHint;
extern PFIndexMask glIndexMask;
extern PFIndexPointer glIndexPointer;
extern PFIndexd glIndexd;
extern PFIndexdv glIndexdv;
extern PFIndexf glIndexf;
extern PFIndexfv glIndexfv;
extern PFIndexi glIndexi;
extern PFIndexiv glIndexiv;
extern PFIndexs glIndexs;
extern PFIndexsv glIndexsv;
extern PFIndexub glIndexub;
extern PFIndexubv glIndexubv;
extern PFInitNames glInitNames;
extern PFInterleavedArrays glInterleavedArrays;
extern PFIsEnabled glIsEnabled;
extern PFIsList glIsList;
extern PFIsTexture glIsTexture;
extern PFLightModelf glLightModelf;
extern PFLightModelfv glLightModelfv;
extern PFLightModeli glLightModeli;
extern PFLightModeliv glLightModeliv;
extern PFLightf glLightf;
extern PFLightfv glLightfv;
extern PFLighti glLighti;
extern PFLightiv glLightiv;
extern PFLineStipple glLineStipple;
extern PFLineWidth glLineWidth;
extern PFListBase glListBase;
extern PFLoadIdentity glLoadIdentity;
extern PFLoadMatrixd glLoadMatrixd;
extern PFLoadMatrixf glLoadMatrixf;
extern PFLoadName glLoadName;
extern PFLogicOp glLogicOp;
extern PFMap1d glMap1d;
extern PFMap1f glMap1f;
extern PFMap2d glMap2d;
extern PFMap2f glMap2f;
extern PFMapGrid1d glMapGrid1d;
extern PFMapGrid1f glMapGrid1f;
extern PFMapGrid2d glMapGrid2d;
extern PFMapGrid2f glMapGrid2f;
extern PFMaterialf glMaterialf;
extern PFMaterialfv glMaterialfv;
extern PFMateriali glMateriali;
extern PFMaterialiv glMaterialiv;
extern PFMatrixMode glMatrixMode;
extern PFMultMatrixd glMultMatrixd;
extern PFMultMatrixf glMultMatrixf;
extern PFNewList glNewList;
extern PFNormal3b glNormal3b;
extern PFNormal3bv glNormal3bv;
extern PFNormal3d glNormal3d;
extern PFNormal3dv glNormal3dv;
extern PFNormal3f glNormal3f;
extern PFNormal3fv glNormal3fv;
extern PFNormal3i glNormal3i;
extern PFNormal3iv glNormal3iv;
extern PFNormal3s glNormal3s;
extern PFNormal3sv glNormal3sv;
extern PFNormalPointer glNormalPointer;
extern PFOrtho glOrtho;
extern PFPassThrough glPassThrough;
extern PFPixelMapfv glPixelMapfv;
extern PFPixelMapuiv glPixelMapuiv;
extern PFPixelMapusv glPixelMapusv;
extern PFPixelStoref glPixelStoref;
extern PFPixelStorei glPixelStorei;
extern PFPixelTransferf glPixelTransferf;
extern PFPixelTransferi glPixelTransferi;
extern PFPixelZoom glPixelZoom;
extern PFPointSize glPointSize;
extern PFPolygonMode glPolygonMode;
extern PFPolygonOffset glPolygonOffset;
extern PFPolygonStipple glPolygonStipple;
extern PFPopAttrib glPopAttrib;
extern PFPopClientAttrib glPopClientAttrib;
extern PFPopMatrix glPopMatrix;
extern PFPopName glPopName;
extern PFPrioritizeTextures glPrioritizeTextures;
extern PFPushAttrib glPushAttrib;
extern PFPushClientAttrib glPushClientAttrib;
extern PFPushMatrix glPushMatrix;
extern PFPushName glPushName;
extern PFRasterPos2d glRasterPos2d;
extern PFRasterPos2dv glRasterPos2dv;
extern PFRasterPos2f glRasterPos2f;
extern PFRasterPos2fv glRasterPos2fv;
extern PFRasterPos2i glRasterPos2i;
extern PFRasterPos2iv glRasterPos2iv;
extern PFRasterPos2s glRasterPos2s;
extern PFRasterPos2sv glRasterPos2sv;
extern PFRasterPos3d glRasterPos3d;
extern PFRasterPos3dv glRasterPos3dv;
extern PFRasterPos3f glRasterPos3f;
extern PFRasterPos3fv glRasterPos3fv;
extern PFRasterPos3i glRasterPos3i;
extern PFRasterPos3iv glRasterPos3iv;
extern PFRasterPos3s glRasterPos3s;
extern PFRasterPos3sv glRasterPos3sv;
extern PFRasterPos4d glRasterPos4d;
extern PFRasterPos4dv glRasterPos4dv;
extern PFRasterPos4f glRasterPos4f;
extern PFRasterPos4fv glRasterPos4fv;
extern PFRasterPos4i glRasterPos4i;
extern PFRasterPos4iv glRasterPos4iv;
extern PFRasterPos4s glRasterPos4s;
extern PFRasterPos4sv glRasterPos4sv;
extern PFReadBuffer glReadBuffer;
extern PFReadPixels glReadPixels;
extern PFRectd glRectd;
extern PFRectdv glRectdv;
extern PFRectf glRectf;
extern PFRectfv glRectfv;
extern PFRecti glRecti;
extern PFRectiv glRectiv;
extern PFRects glRects;
extern PFRectsv glRectsv;
extern PFRenderMode glRenderMode;
extern PFRotated glRotated;
extern PFRotatef glRotatef;
extern PFScaled glScaled;
extern PFScalef glScalef;
extern PFScissor glScissor;
extern PFSelectBuffer glSelectBuffer;
extern PFShadeModel glShadeModel;
extern PFStencilFunc glStencilFunc;
extern PFStencilMask glStencilMask;
extern PFStencilOp glStencilOp;
extern PFTexCoord1d glTexCoord1d;
extern PFTexCoord1dv glTexCoord1dv;
extern PFTexCoord1f glTexCoord1f;
extern PFTexCoord1fv glTexCoord1fv;
extern PFTexCoord1i glTexCoord1i;
extern PFTexCoord1iv glTexCoord1iv;
extern PFTexCoord1s glTexCoord1s;
extern PFTexCoord1sv glTexCoord1sv;
extern PFTexCoord2d glTexCoord2d;
extern PFTexCoord2dv glTexCoord2dv;
extern PFTexCoord2f glTexCoord2f;
extern PFTexCoord2fv glTexCoord2fv;
extern PFTexCoord2i glTexCoord2i;
extern PFTexCoord2iv glTexCoord2iv;
extern PFTexCoord2s glTexCoord2s;
extern PFTexCoord2sv glTexCoord2sv;
extern PFTexCoord3d glTexCoord3d;
extern PFTexCoord3dv glTexCoord3dv;
extern PFTexCoord3f glTexCoord3f;
extern PFTexCoord3fv glTexCoord3fv;
extern PFTexCoord3i glTexCoord3i;
extern PFTexCoord3iv glTexCoord3iv;
extern PFTexCoord3s glTexCoord3s;
extern PFTexCoord3sv glTexCoord3sv;
extern PFTexCoord4d glTexCoord4d;
extern PFTexCoord4dv glTexCoord4dv;
extern PFTexCoord4f glTexCoord4f;
extern PFTexCoord4fv gTexCoord4fv;
extern PFTexCoord4i glTexCoord4i;
extern PFTexCoord4iv glTexCoord4iv;
extern PFTexCoord4s glTexCoord4s;
extern PFTexCoord4sv glTexCoord4sv;
extern PFTexCoordPointer glTexCoordPointer;
extern PFTexEnvf glTexEnvf;
extern PFTexEnvfv glTexEnvfv;
extern PFTexEnvi glTexEnvi;
extern PFTexEnviv glTexEnviv;
extern PFTexGend glTexGend;
extern PFTexGendv glTexGendv;
extern PFTexGenf glTexGenf;
extern PFTexGenfv glTexGenfv;
extern PFTexGeni glTexGeni;
extern PFTexGeniv glTexGeniv;
extern PFTexImage1D glTexImage1D;
extern PFTexImage2D glTexImage2D;
extern PFTexParameterf glTexParameterf;
extern PFTexParameterfv glTexParameterfv;
extern PFTexParameteri glTexParameteri;
extern PFTexParameteriv glTexParameteriv;
extern PFTexSubImage1D glTexSubImage1D;
extern PFTexSubImage2D glTexSubImage2D;
extern PFTranslated glTranslated;
extern PFTranslatef glTranslatef;
extern PFVertex2d glVertex2d;
extern PFVertex2dv glVertex2dv;
extern PFVertex2f glVertex2f;
extern PFVertex2fv glVertex2fv;
extern PFVertex2i glVertex2i;
extern PFVertex2iv glVertex2iv;
extern PFVertex2s glVertex2s;
extern PFVertex2sv glVertex2sv;
extern PFVertex3d glVertex3d;
extern PFVertex3dv glVertex3dv;
extern PFVertex3f glVertex3f;
extern PFVertex3fv glVertex3fv;
extern PFVertex3i glVertex3i;
extern PFVertex3iv glVertex3iv;
extern PFVertex3s glVertex3s;
extern PFVertex3sv glVertex3sv;
extern PFVertex4d glVertex4d;
extern PFVertex4dv glVertex4dv;
extern PFVertex4f glVertex4f;
extern PFVertex4fv glVertex4fv;
extern PFVertex4i glVertex4i;
extern PFVertex4iv glVertex4iv;
extern PFVertex4s glVertex4s;
extern PFVertex4sv glVertex4sv;
extern PFVertexPointer glVertexPointer;
extern PFViewport glViewport;

extern PFCreateContext wglCreateContext;
extern PFMakeCurrent wglMakeCurrent;
extern PFDeleteContext wglDeleteContext; 
extern PFGetProcAddress wglGetProcAddress;

extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;

BOOL glLoadLibrary(char* user, char* gdi, char* openGL);


#ifdef __cplusplus
}
#endif


#endif /* __GL_H__ */
#endif /* __gl_h_ */
