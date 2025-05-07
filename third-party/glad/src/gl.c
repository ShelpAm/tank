/**
 * SPDX-License-Identifier: (WTFPL OR CC0-1.0) AND Apache-2.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/gl.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */

#ifdef __cplusplus
extern "C" {
#endif




static GLADapiproc glad_gl_internal_loader_get_proc(const char *name);
static GLADloadfunc glad_global_on_demand_gl_loader_func = glad_gl_internal_loader_get_proc;

void gladSetGLOnDemandLoader(GLADloadfunc loader) {
    glad_global_on_demand_gl_loader_func = loader;
}

static GLADapiproc glad_gl_on_demand_loader(const char *name) {
    GLADapiproc result = NULL;
    if (result == NULL && glad_global_on_demand_gl_loader_func != NULL) {
        result = glad_global_on_demand_gl_loader_func(name);
    }
    /* this provokes a segmentation fault if there was no loader or no loader returned something useful */
    return result;
}


static void GLAD_API_PTR glad_on_demand_impl_glActiveShaderProgram(GLuint pipeline, GLuint program) {
    glad_glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC) glad_gl_on_demand_loader("glActiveShaderProgram");
    glad_glActiveShaderProgram(pipeline, program);
}
PFNGLACTIVESHADERPROGRAMPROC glad_glActiveShaderProgram = glad_on_demand_impl_glActiveShaderProgram;
static void GLAD_API_PTR glad_on_demand_impl_glActiveTexture(GLenum texture) {
    glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC) glad_gl_on_demand_loader("glActiveTexture");
    glad_glActiveTexture(texture);
}
PFNGLACTIVETEXTUREPROC glad_glActiveTexture = glad_on_demand_impl_glActiveTexture;
static void GLAD_API_PTR glad_on_demand_impl_glAttachShader(GLuint program, GLuint shader) {
    glad_glAttachShader = (PFNGLATTACHSHADERPROC) glad_gl_on_demand_loader("glAttachShader");
    glad_glAttachShader(program, shader);
}
PFNGLATTACHSHADERPROC glad_glAttachShader = glad_on_demand_impl_glAttachShader;
static void GLAD_API_PTR glad_on_demand_impl_glBeginConditionalRender(GLuint id, GLenum mode) {
    glad_glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC) glad_gl_on_demand_loader("glBeginConditionalRender");
    glad_glBeginConditionalRender(id, mode);
}
PFNGLBEGINCONDITIONALRENDERPROC glad_glBeginConditionalRender = glad_on_demand_impl_glBeginConditionalRender;
static void GLAD_API_PTR glad_on_demand_impl_glBeginQuery(GLenum target, GLuint id) {
    glad_glBeginQuery = (PFNGLBEGINQUERYPROC) glad_gl_on_demand_loader("glBeginQuery");
    glad_glBeginQuery(target, id);
}
PFNGLBEGINQUERYPROC glad_glBeginQuery = glad_on_demand_impl_glBeginQuery;
static void GLAD_API_PTR glad_on_demand_impl_glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) {
    glad_glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC) glad_gl_on_demand_loader("glBeginQueryIndexed");
    glad_glBeginQueryIndexed(target, index, id);
}
PFNGLBEGINQUERYINDEXEDPROC glad_glBeginQueryIndexed = glad_on_demand_impl_glBeginQueryIndexed;
static void GLAD_API_PTR glad_on_demand_impl_glBeginTransformFeedback(GLenum primitiveMode) {
    glad_glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glBeginTransformFeedback");
    glad_glBeginTransformFeedback(primitiveMode);
}
PFNGLBEGINTRANSFORMFEEDBACKPROC glad_glBeginTransformFeedback = glad_on_demand_impl_glBeginTransformFeedback;
static void GLAD_API_PTR glad_on_demand_impl_glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    glad_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) glad_gl_on_demand_loader("glBindAttribLocation");
    glad_glBindAttribLocation(program, index, name);
}
PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation = glad_on_demand_impl_glBindAttribLocation;
static void GLAD_API_PTR glad_on_demand_impl_glBindBuffer(GLenum target, GLuint buffer) {
    glad_glBindBuffer = (PFNGLBINDBUFFERPROC) glad_gl_on_demand_loader("glBindBuffer");
    glad_glBindBuffer(target, buffer);
}
PFNGLBINDBUFFERPROC glad_glBindBuffer = glad_on_demand_impl_glBindBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
    glad_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC) glad_gl_on_demand_loader("glBindBufferBase");
    glad_glBindBufferBase(target, index, buffer);
}
PFNGLBINDBUFFERBASEPROC glad_glBindBufferBase = glad_on_demand_impl_glBindBufferBase;
static void GLAD_API_PTR glad_on_demand_impl_glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    glad_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC) glad_gl_on_demand_loader("glBindBufferRange");
    glad_glBindBufferRange(target, index, buffer, offset, size);
}
PFNGLBINDBUFFERRANGEPROC glad_glBindBufferRange = glad_on_demand_impl_glBindBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint * buffers) {
    glad_glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC) glad_gl_on_demand_loader("glBindBuffersBase");
    glad_glBindBuffersBase(target, first, count, buffers);
}
PFNGLBINDBUFFERSBASEPROC glad_glBindBuffersBase = glad_on_demand_impl_glBindBuffersBase;
static void GLAD_API_PTR glad_on_demand_impl_glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes) {
    glad_glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC) glad_gl_on_demand_loader("glBindBuffersRange");
    glad_glBindBuffersRange(target, first, count, buffers, offsets, sizes);
}
PFNGLBINDBUFFERSRANGEPROC glad_glBindBuffersRange = glad_on_demand_impl_glBindBuffersRange;
static void GLAD_API_PTR glad_on_demand_impl_glBindFragDataLocation(GLuint program, GLuint color, const GLchar * name) {
    glad_glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC) glad_gl_on_demand_loader("glBindFragDataLocation");
    glad_glBindFragDataLocation(program, color, name);
}
PFNGLBINDFRAGDATALOCATIONPROC glad_glBindFragDataLocation = glad_on_demand_impl_glBindFragDataLocation;
static void GLAD_API_PTR glad_on_demand_impl_glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name) {
    glad_glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) glad_gl_on_demand_loader("glBindFragDataLocationIndexed");
    glad_glBindFragDataLocationIndexed(program, colorNumber, index, name);
}
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glad_glBindFragDataLocationIndexed = glad_on_demand_impl_glBindFragDataLocationIndexed;
static void GLAD_API_PTR glad_on_demand_impl_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    glad_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC) glad_gl_on_demand_loader("glBindFramebuffer");
    glad_glBindFramebuffer(target, framebuffer);
}
PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer = glad_on_demand_impl_glBindFramebuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
    glad_glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC) glad_gl_on_demand_loader("glBindImageTexture");
    glad_glBindImageTexture(unit, texture, level, layered, layer, access, format);
}
PFNGLBINDIMAGETEXTUREPROC glad_glBindImageTexture = glad_on_demand_impl_glBindImageTexture;
static void GLAD_API_PTR glad_on_demand_impl_glBindImageTextures(GLuint first, GLsizei count, const GLuint * textures) {
    glad_glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC) glad_gl_on_demand_loader("glBindImageTextures");
    glad_glBindImageTextures(first, count, textures);
}
PFNGLBINDIMAGETEXTURESPROC glad_glBindImageTextures = glad_on_demand_impl_glBindImageTextures;
static void GLAD_API_PTR glad_on_demand_impl_glBindProgramPipeline(GLuint pipeline) {
    glad_glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC) glad_gl_on_demand_loader("glBindProgramPipeline");
    glad_glBindProgramPipeline(pipeline);
}
PFNGLBINDPROGRAMPIPELINEPROC glad_glBindProgramPipeline = glad_on_demand_impl_glBindProgramPipeline;
static void GLAD_API_PTR glad_on_demand_impl_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    glad_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC) glad_gl_on_demand_loader("glBindRenderbuffer");
    glad_glBindRenderbuffer(target, renderbuffer);
}
PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer = glad_on_demand_impl_glBindRenderbuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBindSampler(GLuint unit, GLuint sampler) {
    glad_glBindSampler = (PFNGLBINDSAMPLERPROC) glad_gl_on_demand_loader("glBindSampler");
    glad_glBindSampler(unit, sampler);
}
PFNGLBINDSAMPLERPROC glad_glBindSampler = glad_on_demand_impl_glBindSampler;
static void GLAD_API_PTR glad_on_demand_impl_glBindSamplers(GLuint first, GLsizei count, const GLuint * samplers) {
    glad_glBindSamplers = (PFNGLBINDSAMPLERSPROC) glad_gl_on_demand_loader("glBindSamplers");
    glad_glBindSamplers(first, count, samplers);
}
PFNGLBINDSAMPLERSPROC glad_glBindSamplers = glad_on_demand_impl_glBindSamplers;
static void GLAD_API_PTR glad_on_demand_impl_glBindTexture(GLenum target, GLuint texture) {
    glad_glBindTexture = (PFNGLBINDTEXTUREPROC) glad_gl_on_demand_loader("glBindTexture");
    glad_glBindTexture(target, texture);
}
PFNGLBINDTEXTUREPROC glad_glBindTexture = glad_on_demand_impl_glBindTexture;
static void GLAD_API_PTR glad_on_demand_impl_glBindTextureUnit(GLuint unit, GLuint texture) {
    glad_glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC) glad_gl_on_demand_loader("glBindTextureUnit");
    glad_glBindTextureUnit(unit, texture);
}
PFNGLBINDTEXTUREUNITPROC glad_glBindTextureUnit = glad_on_demand_impl_glBindTextureUnit;
static void GLAD_API_PTR glad_on_demand_impl_glBindTextures(GLuint first, GLsizei count, const GLuint * textures) {
    glad_glBindTextures = (PFNGLBINDTEXTURESPROC) glad_gl_on_demand_loader("glBindTextures");
    glad_glBindTextures(first, count, textures);
}
PFNGLBINDTEXTURESPROC glad_glBindTextures = glad_on_demand_impl_glBindTextures;
static void GLAD_API_PTR glad_on_demand_impl_glBindTransformFeedback(GLenum target, GLuint id) {
    glad_glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glBindTransformFeedback");
    glad_glBindTransformFeedback(target, id);
}
PFNGLBINDTRANSFORMFEEDBACKPROC glad_glBindTransformFeedback = glad_on_demand_impl_glBindTransformFeedback;
static void GLAD_API_PTR glad_on_demand_impl_glBindVertexArray(GLuint array) {
    glad_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC) glad_gl_on_demand_loader("glBindVertexArray");
    glad_glBindVertexArray(array);
}
PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray = glad_on_demand_impl_glBindVertexArray;
static void GLAD_API_PTR glad_on_demand_impl_glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
    glad_glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC) glad_gl_on_demand_loader("glBindVertexBuffer");
    glad_glBindVertexBuffer(bindingindex, buffer, offset, stride);
}
PFNGLBINDVERTEXBUFFERPROC glad_glBindVertexBuffer = glad_on_demand_impl_glBindVertexBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBindVertexBuffers(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides) {
    glad_glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC) glad_gl_on_demand_loader("glBindVertexBuffers");
    glad_glBindVertexBuffers(first, count, buffers, offsets, strides);
}
PFNGLBINDVERTEXBUFFERSPROC glad_glBindVertexBuffers = glad_on_demand_impl_glBindVertexBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glad_glBlendColor = (PFNGLBLENDCOLORPROC) glad_gl_on_demand_loader("glBlendColor");
    glad_glBlendColor(red, green, blue, alpha);
}
PFNGLBLENDCOLORPROC glad_glBlendColor = glad_on_demand_impl_glBlendColor;
static void GLAD_API_PTR glad_on_demand_impl_glBlendEquation(GLenum mode) {
    glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC) glad_gl_on_demand_loader("glBlendEquation");
    glad_glBlendEquation(mode);
}
PFNGLBLENDEQUATIONPROC glad_glBlendEquation = glad_on_demand_impl_glBlendEquation;
static void GLAD_API_PTR glad_on_demand_impl_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
    glad_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) glad_gl_on_demand_loader("glBlendEquationSeparate");
    glad_glBlendEquationSeparate(modeRGB, modeAlpha);
}
PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate = glad_on_demand_impl_glBlendEquationSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    glad_glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC) glad_gl_on_demand_loader("glBlendEquationSeparatei");
    glad_glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
}
PFNGLBLENDEQUATIONSEPARATEIPROC glad_glBlendEquationSeparatei = glad_on_demand_impl_glBlendEquationSeparatei;
static void GLAD_API_PTR glad_on_demand_impl_glBlendEquationi(GLuint buf, GLenum mode) {
    glad_glBlendEquationi = (PFNGLBLENDEQUATIONIPROC) glad_gl_on_demand_loader("glBlendEquationi");
    glad_glBlendEquationi(buf, mode);
}
PFNGLBLENDEQUATIONIPROC glad_glBlendEquationi = glad_on_demand_impl_glBlendEquationi;
static void GLAD_API_PTR glad_on_demand_impl_glBlendFunc(GLenum sfactor, GLenum dfactor) {
    glad_glBlendFunc = (PFNGLBLENDFUNCPROC) glad_gl_on_demand_loader("glBlendFunc");
    glad_glBlendFunc(sfactor, dfactor);
}
PFNGLBLENDFUNCPROC glad_glBlendFunc = glad_on_demand_impl_glBlendFunc;
static void GLAD_API_PTR glad_on_demand_impl_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) glad_gl_on_demand_loader("glBlendFuncSeparate");
    glad_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate = glad_on_demand_impl_glBlendFuncSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    glad_glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC) glad_gl_on_demand_loader("glBlendFuncSeparatei");
    glad_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
PFNGLBLENDFUNCSEPARATEIPROC glad_glBlendFuncSeparatei = glad_on_demand_impl_glBlendFuncSeparatei;
static void GLAD_API_PTR glad_on_demand_impl_glBlendFunci(GLuint buf, GLenum src, GLenum dst) {
    glad_glBlendFunci = (PFNGLBLENDFUNCIPROC) glad_gl_on_demand_loader("glBlendFunci");
    glad_glBlendFunci(buf, src, dst);
}
PFNGLBLENDFUNCIPROC glad_glBlendFunci = glad_on_demand_impl_glBlendFunci;
static void GLAD_API_PTR glad_on_demand_impl_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    glad_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC) glad_gl_on_demand_loader("glBlitFramebuffer");
    glad_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer = glad_on_demand_impl_glBlitFramebuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    glad_glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC) glad_gl_on_demand_loader("glBlitNamedFramebuffer");
    glad_glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLBLITNAMEDFRAMEBUFFERPROC glad_glBlitNamedFramebuffer = glad_on_demand_impl_glBlitNamedFramebuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage) {
    glad_glBufferData = (PFNGLBUFFERDATAPROC) glad_gl_on_demand_loader("glBufferData");
    glad_glBufferData(target, size, data, usage);
}
PFNGLBUFFERDATAPROC glad_glBufferData = glad_on_demand_impl_glBufferData;
static void GLAD_API_PTR glad_on_demand_impl_glBufferStorage(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags) {
    glad_glBufferStorage = (PFNGLBUFFERSTORAGEPROC) glad_gl_on_demand_loader("glBufferStorage");
    glad_glBufferStorage(target, size, data, flags);
}
PFNGLBUFFERSTORAGEPROC glad_glBufferStorage = glad_on_demand_impl_glBufferStorage;
static void GLAD_API_PTR glad_on_demand_impl_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) {
    glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glBufferSubData");
    glad_glBufferSubData(target, offset, size, data);
}
PFNGLBUFFERSUBDATAPROC glad_glBufferSubData = glad_on_demand_impl_glBufferSubData;
static GLenum GLAD_API_PTR glad_on_demand_impl_glCheckFramebufferStatus(GLenum target) {
    glad_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) glad_gl_on_demand_loader("glCheckFramebufferStatus");
    return glad_glCheckFramebufferStatus(target);
}
PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus = glad_on_demand_impl_glCheckFramebufferStatus;
static GLenum GLAD_API_PTR glad_on_demand_impl_glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) {
    glad_glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) glad_gl_on_demand_loader("glCheckNamedFramebufferStatus");
    return glad_glCheckNamedFramebufferStatus(framebuffer, target);
}
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glad_glCheckNamedFramebufferStatus = glad_on_demand_impl_glCheckNamedFramebufferStatus;
static void GLAD_API_PTR glad_on_demand_impl_glClampColor(GLenum target, GLenum clamp) {
    glad_glClampColor = (PFNGLCLAMPCOLORPROC) glad_gl_on_demand_loader("glClampColor");
    glad_glClampColor(target, clamp);
}
PFNGLCLAMPCOLORPROC glad_glClampColor = glad_on_demand_impl_glClampColor;
static void GLAD_API_PTR glad_on_demand_impl_glClear(GLbitfield mask) {
    glad_glClear = (PFNGLCLEARPROC) glad_gl_on_demand_loader("glClear");
    glad_glClear(mask);
}
PFNGLCLEARPROC glad_glClear = glad_on_demand_impl_glClear;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data) {
    glad_glClearBufferData = (PFNGLCLEARBUFFERDATAPROC) glad_gl_on_demand_loader("glClearBufferData");
    glad_glClearBufferData(target, internalformat, format, type, data);
}
PFNGLCLEARBUFFERDATAPROC glad_glClearBufferData = glad_on_demand_impl_glClearBufferData;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) {
    glad_glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glClearBufferSubData");
    glad_glClearBufferSubData(target, internalformat, offset, size, format, type, data);
}
PFNGLCLEARBUFFERSUBDATAPROC glad_glClearBufferSubData = glad_on_demand_impl_glClearBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
    glad_glClearBufferfi = (PFNGLCLEARBUFFERFIPROC) glad_gl_on_demand_loader("glClearBufferfi");
    glad_glClearBufferfi(buffer, drawbuffer, depth, stencil);
}
PFNGLCLEARBUFFERFIPROC glad_glClearBufferfi = glad_on_demand_impl_glClearBufferfi;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value) {
    glad_glClearBufferfv = (PFNGLCLEARBUFFERFVPROC) glad_gl_on_demand_loader("glClearBufferfv");
    glad_glClearBufferfv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERFVPROC glad_glClearBufferfv = glad_on_demand_impl_glClearBufferfv;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value) {
    glad_glClearBufferiv = (PFNGLCLEARBUFFERIVPROC) glad_gl_on_demand_loader("glClearBufferiv");
    glad_glClearBufferiv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERIVPROC glad_glClearBufferiv = glad_on_demand_impl_glClearBufferiv;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value) {
    glad_glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC) glad_gl_on_demand_loader("glClearBufferuiv");
    glad_glClearBufferuiv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERUIVPROC glad_glClearBufferuiv = glad_on_demand_impl_glClearBufferuiv;
static void GLAD_API_PTR glad_on_demand_impl_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glad_glClearColor = (PFNGLCLEARCOLORPROC) glad_gl_on_demand_loader("glClearColor");
    glad_glClearColor(red, green, blue, alpha);
}
PFNGLCLEARCOLORPROC glad_glClearColor = glad_on_demand_impl_glClearColor;
static void GLAD_API_PTR glad_on_demand_impl_glClearDepth(GLdouble depth) {
    glad_glClearDepth = (PFNGLCLEARDEPTHPROC) glad_gl_on_demand_loader("glClearDepth");
    glad_glClearDepth(depth);
}
PFNGLCLEARDEPTHPROC glad_glClearDepth = glad_on_demand_impl_glClearDepth;
static void GLAD_API_PTR glad_on_demand_impl_glClearDepthf(GLfloat d) {
    glad_glClearDepthf = (PFNGLCLEARDEPTHFPROC) glad_gl_on_demand_loader("glClearDepthf");
    glad_glClearDepthf(d);
}
PFNGLCLEARDEPTHFPROC glad_glClearDepthf = glad_on_demand_impl_glClearDepthf;
static void GLAD_API_PTR glad_on_demand_impl_glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data) {
    glad_glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC) glad_gl_on_demand_loader("glClearNamedBufferData");
    glad_glClearNamedBufferData(buffer, internalformat, format, type, data);
}
PFNGLCLEARNAMEDBUFFERDATAPROC glad_glClearNamedBufferData = glad_on_demand_impl_glClearNamedBufferData;
static void GLAD_API_PTR glad_on_demand_impl_glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) {
    glad_glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glClearNamedBufferSubData");
    glad_glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data);
}
PFNGLCLEARNAMEDBUFFERSUBDATAPROC glad_glClearNamedBufferSubData = glad_on_demand_impl_glClearNamedBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
    glad_glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) glad_gl_on_demand_loader("glClearNamedFramebufferfi");
    glad_glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil);
}
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glad_glClearNamedFramebufferfi = glad_on_demand_impl_glClearNamedFramebufferfi;
static void GLAD_API_PTR glad_on_demand_impl_glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value) {
    glad_glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) glad_gl_on_demand_loader("glClearNamedFramebufferfv");
    glad_glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value);
}
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glad_glClearNamedFramebufferfv = glad_on_demand_impl_glClearNamedFramebufferfv;
static void GLAD_API_PTR glad_on_demand_impl_glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value) {
    glad_glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) glad_gl_on_demand_loader("glClearNamedFramebufferiv");
    glad_glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value);
}
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glad_glClearNamedFramebufferiv = glad_on_demand_impl_glClearNamedFramebufferiv;
static void GLAD_API_PTR glad_on_demand_impl_glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value) {
    glad_glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) glad_gl_on_demand_loader("glClearNamedFramebufferuiv");
    glad_glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value);
}
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glad_glClearNamedFramebufferuiv = glad_on_demand_impl_glClearNamedFramebufferuiv;
static void GLAD_API_PTR glad_on_demand_impl_glClearStencil(GLint s) {
    glad_glClearStencil = (PFNGLCLEARSTENCILPROC) glad_gl_on_demand_loader("glClearStencil");
    glad_glClearStencil(s);
}
PFNGLCLEARSTENCILPROC glad_glClearStencil = glad_on_demand_impl_glClearStencil;
static void GLAD_API_PTR glad_on_demand_impl_glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void * data) {
    glad_glClearTexImage = (PFNGLCLEARTEXIMAGEPROC) glad_gl_on_demand_loader("glClearTexImage");
    glad_glClearTexImage(texture, level, format, type, data);
}
PFNGLCLEARTEXIMAGEPROC glad_glClearTexImage = glad_on_demand_impl_glClearTexImage;
static void GLAD_API_PTR glad_on_demand_impl_glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data) {
    glad_glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC) glad_gl_on_demand_loader("glClearTexSubImage");
    glad_glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}
PFNGLCLEARTEXSUBIMAGEPROC glad_glClearTexSubImage = glad_on_demand_impl_glClearTexSubImage;
static GLenum GLAD_API_PTR glad_on_demand_impl_glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    glad_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC) glad_gl_on_demand_loader("glClientWaitSync");
    return glad_glClientWaitSync(sync, flags, timeout);
}
PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync = glad_on_demand_impl_glClientWaitSync;
static void GLAD_API_PTR glad_on_demand_impl_glClipControl(GLenum origin, GLenum depth) {
    glad_glClipControl = (PFNGLCLIPCONTROLPROC) glad_gl_on_demand_loader("glClipControl");
    glad_glClipControl(origin, depth);
}
PFNGLCLIPCONTROLPROC glad_glClipControl = glad_on_demand_impl_glClipControl;
static void GLAD_API_PTR glad_on_demand_impl_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    glad_glColorMask = (PFNGLCOLORMASKPROC) glad_gl_on_demand_loader("glColorMask");
    glad_glColorMask(red, green, blue, alpha);
}
PFNGLCOLORMASKPROC glad_glColorMask = glad_on_demand_impl_glColorMask;
static void GLAD_API_PTR glad_on_demand_impl_glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
    glad_glColorMaski = (PFNGLCOLORMASKIPROC) glad_gl_on_demand_loader("glColorMaski");
    glad_glColorMaski(index, r, g, b, a);
}
PFNGLCOLORMASKIPROC glad_glColorMaski = glad_on_demand_impl_glColorMaski;
static void GLAD_API_PTR glad_on_demand_impl_glCompileShader(GLuint shader) {
    glad_glCompileShader = (PFNGLCOMPILESHADERPROC) glad_gl_on_demand_loader("glCompileShader");
    glad_glCompileShader(shader);
}
PFNGLCOMPILESHADERPROC glad_glCompileShader = glad_on_demand_impl_glCompileShader;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) {
    glad_glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC) glad_gl_on_demand_loader("glCompressedTexImage1D");
    glad_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D = glad_on_demand_impl_glCompressedTexImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
    glad_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) glad_gl_on_demand_loader("glCompressedTexImage2D");
    glad_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D = glad_on_demand_impl_glCompressedTexImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
    glad_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC) glad_gl_on_demand_loader("glCompressedTexImage3D");
    glad_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D = glad_on_demand_impl_glCompressedTexImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) glad_gl_on_demand_loader("glCompressedTexSubImage1D");
    glad_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D = glad_on_demand_impl_glCompressedTexSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) glad_gl_on_demand_loader("glCompressedTexSubImage2D");
    glad_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D = glad_on_demand_impl_glCompressedTexSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) glad_gl_on_demand_loader("glCompressedTexSubImage3D");
    glad_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D = glad_on_demand_impl_glCompressedTexSubImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) glad_gl_on_demand_loader("glCompressedTextureSubImage1D");
    glad_glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glad_glCompressedTextureSubImage1D = glad_on_demand_impl_glCompressedTextureSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) glad_gl_on_demand_loader("glCompressedTextureSubImage2D");
    glad_glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glad_glCompressedTextureSubImage2D = glad_on_demand_impl_glCompressedTextureSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) glad_gl_on_demand_loader("glCompressedTextureSubImage3D");
    glad_glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glad_glCompressedTextureSubImage3D = glad_on_demand_impl_glCompressedTextureSubImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    glad_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glCopyBufferSubData");
    glad_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}
PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData = glad_on_demand_impl_glCopyBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
    glad_glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC) glad_gl_on_demand_loader("glCopyImageSubData");
    glad_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
PFNGLCOPYIMAGESUBDATAPROC glad_glCopyImageSubData = glad_on_demand_impl_glCopyImageSubData;
static void GLAD_API_PTR glad_on_demand_impl_glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    glad_glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glCopyNamedBufferSubData");
    glad_glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
}
PFNGLCOPYNAMEDBUFFERSUBDATAPROC glad_glCopyNamedBufferSubData = glad_on_demand_impl_glCopyNamedBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    glad_glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC) glad_gl_on_demand_loader("glCopyTexImage1D");
    glad_glCopyTexImage1D(target, level, internalformat, x, y, width, border);
}
PFNGLCOPYTEXIMAGE1DPROC glad_glCopyTexImage1D = glad_on_demand_impl_glCopyTexImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    glad_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC) glad_gl_on_demand_loader("glCopyTexImage2D");
    glad_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D = glad_on_demand_impl_glCopyTexImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    glad_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC) glad_gl_on_demand_loader("glCopyTexSubImage1D");
    glad_glCopyTexSubImage1D(target, level, xoffset, x, y, width);
}
PFNGLCOPYTEXSUBIMAGE1DPROC glad_glCopyTexSubImage1D = glad_on_demand_impl_glCopyTexSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) glad_gl_on_demand_loader("glCopyTexSubImage2D");
    glad_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D = glad_on_demand_impl_glCopyTexSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) glad_gl_on_demand_loader("glCopyTexSubImage3D");
    glad_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D = glad_on_demand_impl_glCopyTexSubImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    glad_glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC) glad_gl_on_demand_loader("glCopyTextureSubImage1D");
    glad_glCopyTextureSubImage1D(texture, level, xoffset, x, y, width);
}
PFNGLCOPYTEXTURESUBIMAGE1DPROC glad_glCopyTextureSubImage1D = glad_on_demand_impl_glCopyTextureSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC) glad_gl_on_demand_loader("glCopyTextureSubImage2D");
    glad_glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXTURESUBIMAGE2DPROC glad_glCopyTextureSubImage2D = glad_on_demand_impl_glCopyTextureSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC) glad_gl_on_demand_loader("glCopyTextureSubImage3D");
    glad_glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLCOPYTEXTURESUBIMAGE3DPROC glad_glCopyTextureSubImage3D = glad_on_demand_impl_glCopyTextureSubImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glCreateBuffers(GLsizei n, GLuint * buffers) {
    glad_glCreateBuffers = (PFNGLCREATEBUFFERSPROC) glad_gl_on_demand_loader("glCreateBuffers");
    glad_glCreateBuffers(n, buffers);
}
PFNGLCREATEBUFFERSPROC glad_glCreateBuffers = glad_on_demand_impl_glCreateBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glCreateFramebuffers(GLsizei n, GLuint * framebuffers) {
    glad_glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC) glad_gl_on_demand_loader("glCreateFramebuffers");
    glad_glCreateFramebuffers(n, framebuffers);
}
PFNGLCREATEFRAMEBUFFERSPROC glad_glCreateFramebuffers = glad_on_demand_impl_glCreateFramebuffers;
static GLuint GLAD_API_PTR glad_on_demand_impl_glCreateProgram(void) {
    glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC) glad_gl_on_demand_loader("glCreateProgram");
    return glad_glCreateProgram();
}
PFNGLCREATEPROGRAMPROC glad_glCreateProgram = glad_on_demand_impl_glCreateProgram;
static void GLAD_API_PTR glad_on_demand_impl_glCreateProgramPipelines(GLsizei n, GLuint * pipelines) {
    glad_glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC) glad_gl_on_demand_loader("glCreateProgramPipelines");
    glad_glCreateProgramPipelines(n, pipelines);
}
PFNGLCREATEPROGRAMPIPELINESPROC glad_glCreateProgramPipelines = glad_on_demand_impl_glCreateProgramPipelines;
static void GLAD_API_PTR glad_on_demand_impl_glCreateQueries(GLenum target, GLsizei n, GLuint * ids) {
    glad_glCreateQueries = (PFNGLCREATEQUERIESPROC) glad_gl_on_demand_loader("glCreateQueries");
    glad_glCreateQueries(target, n, ids);
}
PFNGLCREATEQUERIESPROC glad_glCreateQueries = glad_on_demand_impl_glCreateQueries;
static void GLAD_API_PTR glad_on_demand_impl_glCreateRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    glad_glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC) glad_gl_on_demand_loader("glCreateRenderbuffers");
    glad_glCreateRenderbuffers(n, renderbuffers);
}
PFNGLCREATERENDERBUFFERSPROC glad_glCreateRenderbuffers = glad_on_demand_impl_glCreateRenderbuffers;
static void GLAD_API_PTR glad_on_demand_impl_glCreateSamplers(GLsizei n, GLuint * samplers) {
    glad_glCreateSamplers = (PFNGLCREATESAMPLERSPROC) glad_gl_on_demand_loader("glCreateSamplers");
    glad_glCreateSamplers(n, samplers);
}
PFNGLCREATESAMPLERSPROC glad_glCreateSamplers = glad_on_demand_impl_glCreateSamplers;
static GLuint GLAD_API_PTR glad_on_demand_impl_glCreateShader(GLenum type) {
    glad_glCreateShader = (PFNGLCREATESHADERPROC) glad_gl_on_demand_loader("glCreateShader");
    return glad_glCreateShader(type);
}
PFNGLCREATESHADERPROC glad_glCreateShader = glad_on_demand_impl_glCreateShader;
static GLuint GLAD_API_PTR glad_on_demand_impl_glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const* strings) {
    glad_glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC) glad_gl_on_demand_loader("glCreateShaderProgramv");
    return glad_glCreateShaderProgramv(type, count, strings);
}
PFNGLCREATESHADERPROGRAMVPROC glad_glCreateShaderProgramv = glad_on_demand_impl_glCreateShaderProgramv;
static void GLAD_API_PTR glad_on_demand_impl_glCreateTextures(GLenum target, GLsizei n, GLuint * textures) {
    glad_glCreateTextures = (PFNGLCREATETEXTURESPROC) glad_gl_on_demand_loader("glCreateTextures");
    glad_glCreateTextures(target, n, textures);
}
PFNGLCREATETEXTURESPROC glad_glCreateTextures = glad_on_demand_impl_glCreateTextures;
static void GLAD_API_PTR glad_on_demand_impl_glCreateTransformFeedbacks(GLsizei n, GLuint * ids) {
    glad_glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC) glad_gl_on_demand_loader("glCreateTransformFeedbacks");
    glad_glCreateTransformFeedbacks(n, ids);
}
PFNGLCREATETRANSFORMFEEDBACKSPROC glad_glCreateTransformFeedbacks = glad_on_demand_impl_glCreateTransformFeedbacks;
static void GLAD_API_PTR glad_on_demand_impl_glCreateVertexArrays(GLsizei n, GLuint * arrays) {
    glad_glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC) glad_gl_on_demand_loader("glCreateVertexArrays");
    glad_glCreateVertexArrays(n, arrays);
}
PFNGLCREATEVERTEXARRAYSPROC glad_glCreateVertexArrays = glad_on_demand_impl_glCreateVertexArrays;
static void GLAD_API_PTR glad_on_demand_impl_glCullFace(GLenum mode) {
    glad_glCullFace = (PFNGLCULLFACEPROC) glad_gl_on_demand_loader("glCullFace");
    glad_glCullFace(mode);
}
PFNGLCULLFACEPROC glad_glCullFace = glad_on_demand_impl_glCullFace;
static void GLAD_API_PTR glad_on_demand_impl_glDebugMessageCallback(GLDEBUGPROC callback, const void * userParam) {
    glad_glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC) glad_gl_on_demand_loader("glDebugMessageCallback");
    glad_glDebugMessageCallback(callback, userParam);
}
PFNGLDEBUGMESSAGECALLBACKPROC glad_glDebugMessageCallback = glad_on_demand_impl_glDebugMessageCallback;
static void GLAD_API_PTR glad_on_demand_impl_glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled) {
    glad_glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC) glad_gl_on_demand_loader("glDebugMessageControl");
    glad_glDebugMessageControl(source, type, severity, count, ids, enabled);
}
PFNGLDEBUGMESSAGECONTROLPROC glad_glDebugMessageControl = glad_on_demand_impl_glDebugMessageControl;
static void GLAD_API_PTR glad_on_demand_impl_glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf) {
    glad_glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC) glad_gl_on_demand_loader("glDebugMessageInsert");
    glad_glDebugMessageInsert(source, type, id, severity, length, buf);
}
PFNGLDEBUGMESSAGEINSERTPROC glad_glDebugMessageInsert = glad_on_demand_impl_glDebugMessageInsert;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC) glad_gl_on_demand_loader("glDeleteBuffers");
    glad_glDeleteBuffers(n, buffers);
}
PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers = glad_on_demand_impl_glDeleteBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers) {
    glad_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC) glad_gl_on_demand_loader("glDeleteFramebuffers");
    glad_glDeleteFramebuffers(n, framebuffers);
}
PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers = glad_on_demand_impl_glDeleteFramebuffers;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteProgram(GLuint program) {
    glad_glDeleteProgram = (PFNGLDELETEPROGRAMPROC) glad_gl_on_demand_loader("glDeleteProgram");
    glad_glDeleteProgram(program);
}
PFNGLDELETEPROGRAMPROC glad_glDeleteProgram = glad_on_demand_impl_glDeleteProgram;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteProgramPipelines(GLsizei n, const GLuint * pipelines) {
    glad_glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC) glad_gl_on_demand_loader("glDeleteProgramPipelines");
    glad_glDeleteProgramPipelines(n, pipelines);
}
PFNGLDELETEPROGRAMPIPELINESPROC glad_glDeleteProgramPipelines = glad_on_demand_impl_glDeleteProgramPipelines;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteQueries(GLsizei n, const GLuint * ids) {
    glad_glDeleteQueries = (PFNGLDELETEQUERIESPROC) glad_gl_on_demand_loader("glDeleteQueries");
    glad_glDeleteQueries(n, ids);
}
PFNGLDELETEQUERIESPROC glad_glDeleteQueries = glad_on_demand_impl_glDeleteQueries;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers) {
    glad_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC) glad_gl_on_demand_loader("glDeleteRenderbuffers");
    glad_glDeleteRenderbuffers(n, renderbuffers);
}
PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers = glad_on_demand_impl_glDeleteRenderbuffers;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteSamplers(GLsizei count, const GLuint * samplers) {
    glad_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC) glad_gl_on_demand_loader("glDeleteSamplers");
    glad_glDeleteSamplers(count, samplers);
}
PFNGLDELETESAMPLERSPROC glad_glDeleteSamplers = glad_on_demand_impl_glDeleteSamplers;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteShader(GLuint shader) {
    glad_glDeleteShader = (PFNGLDELETESHADERPROC) glad_gl_on_demand_loader("glDeleteShader");
    glad_glDeleteShader(shader);
}
PFNGLDELETESHADERPROC glad_glDeleteShader = glad_on_demand_impl_glDeleteShader;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteSync(GLsync sync) {
    glad_glDeleteSync = (PFNGLDELETESYNCPROC) glad_gl_on_demand_loader("glDeleteSync");
    glad_glDeleteSync(sync);
}
PFNGLDELETESYNCPROC glad_glDeleteSync = glad_on_demand_impl_glDeleteSync;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteTextures(GLsizei n, const GLuint * textures) {
    glad_glDeleteTextures = (PFNGLDELETETEXTURESPROC) glad_gl_on_demand_loader("glDeleteTextures");
    glad_glDeleteTextures(n, textures);
}
PFNGLDELETETEXTURESPROC glad_glDeleteTextures = glad_on_demand_impl_glDeleteTextures;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteTransformFeedbacks(GLsizei n, const GLuint * ids) {
    glad_glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC) glad_gl_on_demand_loader("glDeleteTransformFeedbacks");
    glad_glDeleteTransformFeedbacks(n, ids);
}
PFNGLDELETETRANSFORMFEEDBACKSPROC glad_glDeleteTransformFeedbacks = glad_on_demand_impl_glDeleteTransformFeedbacks;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteVertexArrays(GLsizei n, const GLuint * arrays) {
    glad_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC) glad_gl_on_demand_loader("glDeleteVertexArrays");
    glad_glDeleteVertexArrays(n, arrays);
}
PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays = glad_on_demand_impl_glDeleteVertexArrays;
static void GLAD_API_PTR glad_on_demand_impl_glDepthFunc(GLenum func) {
    glad_glDepthFunc = (PFNGLDEPTHFUNCPROC) glad_gl_on_demand_loader("glDepthFunc");
    glad_glDepthFunc(func);
}
PFNGLDEPTHFUNCPROC glad_glDepthFunc = glad_on_demand_impl_glDepthFunc;
static void GLAD_API_PTR glad_on_demand_impl_glDepthMask(GLboolean flag) {
    glad_glDepthMask = (PFNGLDEPTHMASKPROC) glad_gl_on_demand_loader("glDepthMask");
    glad_glDepthMask(flag);
}
PFNGLDEPTHMASKPROC glad_glDepthMask = glad_on_demand_impl_glDepthMask;
static void GLAD_API_PTR glad_on_demand_impl_glDepthRange(GLdouble n, GLdouble f) {
    glad_glDepthRange = (PFNGLDEPTHRANGEPROC) glad_gl_on_demand_loader("glDepthRange");
    glad_glDepthRange(n, f);
}
PFNGLDEPTHRANGEPROC glad_glDepthRange = glad_on_demand_impl_glDepthRange;
static void GLAD_API_PTR glad_on_demand_impl_glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble * v) {
    glad_glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC) glad_gl_on_demand_loader("glDepthRangeArrayv");
    glad_glDepthRangeArrayv(first, count, v);
}
PFNGLDEPTHRANGEARRAYVPROC glad_glDepthRangeArrayv = glad_on_demand_impl_glDepthRangeArrayv;
static void GLAD_API_PTR glad_on_demand_impl_glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) {
    glad_glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC) glad_gl_on_demand_loader("glDepthRangeIndexed");
    glad_glDepthRangeIndexed(index, n, f);
}
PFNGLDEPTHRANGEINDEXEDPROC glad_glDepthRangeIndexed = glad_on_demand_impl_glDepthRangeIndexed;
static void GLAD_API_PTR glad_on_demand_impl_glDepthRangef(GLfloat n, GLfloat f) {
    glad_glDepthRangef = (PFNGLDEPTHRANGEFPROC) glad_gl_on_demand_loader("glDepthRangef");
    glad_glDepthRangef(n, f);
}
PFNGLDEPTHRANGEFPROC glad_glDepthRangef = glad_on_demand_impl_glDepthRangef;
static void GLAD_API_PTR glad_on_demand_impl_glDetachShader(GLuint program, GLuint shader) {
    glad_glDetachShader = (PFNGLDETACHSHADERPROC) glad_gl_on_demand_loader("glDetachShader");
    glad_glDetachShader(program, shader);
}
PFNGLDETACHSHADERPROC glad_glDetachShader = glad_on_demand_impl_glDetachShader;
static void GLAD_API_PTR glad_on_demand_impl_glDisable(GLenum cap) {
    glad_glDisable = (PFNGLDISABLEPROC) glad_gl_on_demand_loader("glDisable");
    glad_glDisable(cap);
}
PFNGLDISABLEPROC glad_glDisable = glad_on_demand_impl_glDisable;
static void GLAD_API_PTR glad_on_demand_impl_glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) {
    glad_glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC) glad_gl_on_demand_loader("glDisableVertexArrayAttrib");
    glad_glDisableVertexArrayAttrib(vaobj, index);
}
PFNGLDISABLEVERTEXARRAYATTRIBPROC glad_glDisableVertexArrayAttrib = glad_on_demand_impl_glDisableVertexArrayAttrib;
static void GLAD_API_PTR glad_on_demand_impl_glDisableVertexAttribArray(GLuint index) {
    glad_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) glad_gl_on_demand_loader("glDisableVertexAttribArray");
    glad_glDisableVertexAttribArray(index);
}
PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray = glad_on_demand_impl_glDisableVertexAttribArray;
static void GLAD_API_PTR glad_on_demand_impl_glDisablei(GLenum target, GLuint index) {
    glad_glDisablei = (PFNGLDISABLEIPROC) glad_gl_on_demand_loader("glDisablei");
    glad_glDisablei(target, index);
}
PFNGLDISABLEIPROC glad_glDisablei = glad_on_demand_impl_glDisablei;
static void GLAD_API_PTR glad_on_demand_impl_glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
    glad_glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC) glad_gl_on_demand_loader("glDispatchCompute");
    glad_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
}
PFNGLDISPATCHCOMPUTEPROC glad_glDispatchCompute = glad_on_demand_impl_glDispatchCompute;
static void GLAD_API_PTR glad_on_demand_impl_glDispatchComputeIndirect(GLintptr indirect) {
    glad_glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC) glad_gl_on_demand_loader("glDispatchComputeIndirect");
    glad_glDispatchComputeIndirect(indirect);
}
PFNGLDISPATCHCOMPUTEINDIRECTPROC glad_glDispatchComputeIndirect = glad_on_demand_impl_glDispatchComputeIndirect;
static void GLAD_API_PTR glad_on_demand_impl_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    glad_glDrawArrays = (PFNGLDRAWARRAYSPROC) glad_gl_on_demand_loader("glDrawArrays");
    glad_glDrawArrays(mode, first, count);
}
PFNGLDRAWARRAYSPROC glad_glDrawArrays = glad_on_demand_impl_glDrawArrays;
static void GLAD_API_PTR glad_on_demand_impl_glDrawArraysIndirect(GLenum mode, const void * indirect) {
    glad_glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC) glad_gl_on_demand_loader("glDrawArraysIndirect");
    glad_glDrawArraysIndirect(mode, indirect);
}
PFNGLDRAWARRAYSINDIRECTPROC glad_glDrawArraysIndirect = glad_on_demand_impl_glDrawArraysIndirect;
static void GLAD_API_PTR glad_on_demand_impl_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
    glad_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC) glad_gl_on_demand_loader("glDrawArraysInstanced");
    glad_glDrawArraysInstanced(mode, first, count, instancecount);
}
PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced = glad_on_demand_impl_glDrawArraysInstanced;
static void GLAD_API_PTR glad_on_demand_impl_glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
    glad_glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) glad_gl_on_demand_loader("glDrawArraysInstancedBaseInstance");
    glad_glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance);
}
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glad_glDrawArraysInstancedBaseInstance = glad_on_demand_impl_glDrawArraysInstancedBaseInstance;
static void GLAD_API_PTR glad_on_demand_impl_glDrawBuffer(GLenum buf) {
    glad_glDrawBuffer = (PFNGLDRAWBUFFERPROC) glad_gl_on_demand_loader("glDrawBuffer");
    glad_glDrawBuffer(buf);
}
PFNGLDRAWBUFFERPROC glad_glDrawBuffer = glad_on_demand_impl_glDrawBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glDrawBuffers(GLsizei n, const GLenum * bufs) {
    glad_glDrawBuffers = (PFNGLDRAWBUFFERSPROC) glad_gl_on_demand_loader("glDrawBuffers");
    glad_glDrawBuffers(n, bufs);
}
PFNGLDRAWBUFFERSPROC glad_glDrawBuffers = glad_on_demand_impl_glDrawBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices) {
    glad_glDrawElements = (PFNGLDRAWELEMENTSPROC) glad_gl_on_demand_loader("glDrawElements");
    glad_glDrawElements(mode, count, type, indices);
}
PFNGLDRAWELEMENTSPROC glad_glDrawElements = glad_on_demand_impl_glDrawElements;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
    glad_glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC) glad_gl_on_demand_loader("glDrawElementsBaseVertex");
    glad_glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
}
PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex = glad_on_demand_impl_glDrawElementsBaseVertex;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect) {
    glad_glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC) glad_gl_on_demand_loader("glDrawElementsIndirect");
    glad_glDrawElementsIndirect(mode, type, indirect);
}
PFNGLDRAWELEMENTSINDIRECTPROC glad_glDrawElementsIndirect = glad_on_demand_impl_glDrawElementsIndirect;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount) {
    glad_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC) glad_gl_on_demand_loader("glDrawElementsInstanced");
    glad_glDrawElementsInstanced(mode, count, type, indices, instancecount);
}
PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced = glad_on_demand_impl_glDrawElementsInstanced;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance) {
    glad_glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) glad_gl_on_demand_loader("glDrawElementsInstancedBaseInstance");
    glad_glDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance);
}
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glad_glDrawElementsInstancedBaseInstance = glad_on_demand_impl_glDrawElementsInstancedBaseInstance;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
    glad_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) glad_gl_on_demand_loader("glDrawElementsInstancedBaseVertex");
    glad_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex = glad_on_demand_impl_glDrawElementsInstancedBaseVertex;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
    glad_glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) glad_gl_on_demand_loader("glDrawElementsInstancedBaseVertexBaseInstance");
    glad_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance);
}
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glad_glDrawElementsInstancedBaseVertexBaseInstance = glad_on_demand_impl_glDrawElementsInstancedBaseVertexBaseInstance;
static void GLAD_API_PTR glad_on_demand_impl_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) {
    glad_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) glad_gl_on_demand_loader("glDrawRangeElements");
    glad_glDrawRangeElements(mode, start, end, count, type, indices);
}
PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements = glad_on_demand_impl_glDrawRangeElements;
static void GLAD_API_PTR glad_on_demand_impl_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
    glad_glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) glad_gl_on_demand_loader("glDrawRangeElementsBaseVertex");
    glad_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex = glad_on_demand_impl_glDrawRangeElementsBaseVertex;
static void GLAD_API_PTR glad_on_demand_impl_glDrawTransformFeedback(GLenum mode, GLuint id) {
    glad_glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glDrawTransformFeedback");
    glad_glDrawTransformFeedback(mode, id);
}
PFNGLDRAWTRANSFORMFEEDBACKPROC glad_glDrawTransformFeedback = glad_on_demand_impl_glDrawTransformFeedback;
static void GLAD_API_PTR glad_on_demand_impl_glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) {
    glad_glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) glad_gl_on_demand_loader("glDrawTransformFeedbackInstanced");
    glad_glDrawTransformFeedbackInstanced(mode, id, instancecount);
}
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glad_glDrawTransformFeedbackInstanced = glad_on_demand_impl_glDrawTransformFeedbackInstanced;
static void GLAD_API_PTR glad_on_demand_impl_glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) {
    glad_glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) glad_gl_on_demand_loader("glDrawTransformFeedbackStream");
    glad_glDrawTransformFeedbackStream(mode, id, stream);
}
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glad_glDrawTransformFeedbackStream = glad_on_demand_impl_glDrawTransformFeedbackStream;
static void GLAD_API_PTR glad_on_demand_impl_glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) {
    glad_glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) glad_gl_on_demand_loader("glDrawTransformFeedbackStreamInstanced");
    glad_glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
}
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glad_glDrawTransformFeedbackStreamInstanced = glad_on_demand_impl_glDrawTransformFeedbackStreamInstanced;
static void GLAD_API_PTR glad_on_demand_impl_glEnable(GLenum cap) {
    glad_glEnable = (PFNGLENABLEPROC) glad_gl_on_demand_loader("glEnable");
    glad_glEnable(cap);
}
PFNGLENABLEPROC glad_glEnable = glad_on_demand_impl_glEnable;
static void GLAD_API_PTR glad_on_demand_impl_glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) {
    glad_glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC) glad_gl_on_demand_loader("glEnableVertexArrayAttrib");
    glad_glEnableVertexArrayAttrib(vaobj, index);
}
PFNGLENABLEVERTEXARRAYATTRIBPROC glad_glEnableVertexArrayAttrib = glad_on_demand_impl_glEnableVertexArrayAttrib;
static void GLAD_API_PTR glad_on_demand_impl_glEnableVertexAttribArray(GLuint index) {
    glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) glad_gl_on_demand_loader("glEnableVertexAttribArray");
    glad_glEnableVertexAttribArray(index);
}
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray = glad_on_demand_impl_glEnableVertexAttribArray;
static void GLAD_API_PTR glad_on_demand_impl_glEnablei(GLenum target, GLuint index) {
    glad_glEnablei = (PFNGLENABLEIPROC) glad_gl_on_demand_loader("glEnablei");
    glad_glEnablei(target, index);
}
PFNGLENABLEIPROC glad_glEnablei = glad_on_demand_impl_glEnablei;
static void GLAD_API_PTR glad_on_demand_impl_glEndConditionalRender(void) {
    glad_glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC) glad_gl_on_demand_loader("glEndConditionalRender");
    glad_glEndConditionalRender();
}
PFNGLENDCONDITIONALRENDERPROC glad_glEndConditionalRender = glad_on_demand_impl_glEndConditionalRender;
static void GLAD_API_PTR glad_on_demand_impl_glEndQuery(GLenum target) {
    glad_glEndQuery = (PFNGLENDQUERYPROC) glad_gl_on_demand_loader("glEndQuery");
    glad_glEndQuery(target);
}
PFNGLENDQUERYPROC glad_glEndQuery = glad_on_demand_impl_glEndQuery;
static void GLAD_API_PTR glad_on_demand_impl_glEndQueryIndexed(GLenum target, GLuint index) {
    glad_glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC) glad_gl_on_demand_loader("glEndQueryIndexed");
    glad_glEndQueryIndexed(target, index);
}
PFNGLENDQUERYINDEXEDPROC glad_glEndQueryIndexed = glad_on_demand_impl_glEndQueryIndexed;
static void GLAD_API_PTR glad_on_demand_impl_glEndTransformFeedback(void) {
    glad_glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glEndTransformFeedback");
    glad_glEndTransformFeedback();
}
PFNGLENDTRANSFORMFEEDBACKPROC glad_glEndTransformFeedback = glad_on_demand_impl_glEndTransformFeedback;
static GLsync GLAD_API_PTR glad_on_demand_impl_glFenceSync(GLenum condition, GLbitfield flags) {
    glad_glFenceSync = (PFNGLFENCESYNCPROC) glad_gl_on_demand_loader("glFenceSync");
    return glad_glFenceSync(condition, flags);
}
PFNGLFENCESYNCPROC glad_glFenceSync = glad_on_demand_impl_glFenceSync;
static void GLAD_API_PTR glad_on_demand_impl_glFinish(void) {
    glad_glFinish = (PFNGLFINISHPROC) glad_gl_on_demand_loader("glFinish");
    glad_glFinish();
}
PFNGLFINISHPROC glad_glFinish = glad_on_demand_impl_glFinish;
static void GLAD_API_PTR glad_on_demand_impl_glFlush(void) {
    glad_glFlush = (PFNGLFLUSHPROC) glad_gl_on_demand_loader("glFlush");
    glad_glFlush();
}
PFNGLFLUSHPROC glad_glFlush = glad_on_demand_impl_glFlush;
static void GLAD_API_PTR glad_on_demand_impl_glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
    glad_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC) glad_gl_on_demand_loader("glFlushMappedBufferRange");
    glad_glFlushMappedBufferRange(target, offset, length);
}
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_glFlushMappedBufferRange = glad_on_demand_impl_glFlushMappedBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) {
    glad_glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) glad_gl_on_demand_loader("glFlushMappedNamedBufferRange");
    glad_glFlushMappedNamedBufferRange(buffer, offset, length);
}
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glad_glFlushMappedNamedBufferRange = glad_on_demand_impl_glFlushMappedNamedBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferParameteri(GLenum target, GLenum pname, GLint param) {
    glad_glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC) glad_gl_on_demand_loader("glFramebufferParameteri");
    glad_glFramebufferParameteri(target, pname, param);
}
PFNGLFRAMEBUFFERPARAMETERIPROC glad_glFramebufferParameteri = glad_on_demand_impl_glFramebufferParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    glad_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC) glad_gl_on_demand_loader("glFramebufferRenderbuffer");
    glad_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer = glad_on_demand_impl_glFramebufferRenderbuffer;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {
    glad_glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC) glad_gl_on_demand_loader("glFramebufferTexture");
    glad_glFramebufferTexture(target, attachment, texture, level);
}
PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture = glad_on_demand_impl_glFramebufferTexture;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    glad_glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC) glad_gl_on_demand_loader("glFramebufferTexture1D");
    glad_glFramebufferTexture1D(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE1DPROC glad_glFramebufferTexture1D = glad_on_demand_impl_glFramebufferTexture1D;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    glad_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC) glad_gl_on_demand_loader("glFramebufferTexture2D");
    glad_glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D = glad_on_demand_impl_glFramebufferTexture2D;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    glad_glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC) glad_gl_on_demand_loader("glFramebufferTexture3D");
    glad_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
}
PFNGLFRAMEBUFFERTEXTURE3DPROC glad_glFramebufferTexture3D = glad_on_demand_impl_glFramebufferTexture3D;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    glad_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC) glad_gl_on_demand_loader("glFramebufferTextureLayer");
    glad_glFramebufferTextureLayer(target, attachment, texture, level, layer);
}
PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_glFramebufferTextureLayer = glad_on_demand_impl_glFramebufferTextureLayer;
static void GLAD_API_PTR glad_on_demand_impl_glFrontFace(GLenum mode) {
    glad_glFrontFace = (PFNGLFRONTFACEPROC) glad_gl_on_demand_loader("glFrontFace");
    glad_glFrontFace(mode);
}
PFNGLFRONTFACEPROC glad_glFrontFace = glad_on_demand_impl_glFrontFace;
static void GLAD_API_PTR glad_on_demand_impl_glGenBuffers(GLsizei n, GLuint * buffers) {
    glad_glGenBuffers = (PFNGLGENBUFFERSPROC) glad_gl_on_demand_loader("glGenBuffers");
    glad_glGenBuffers(n, buffers);
}
PFNGLGENBUFFERSPROC glad_glGenBuffers = glad_on_demand_impl_glGenBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
    glad_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) glad_gl_on_demand_loader("glGenFramebuffers");
    glad_glGenFramebuffers(n, framebuffers);
}
PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers = glad_on_demand_impl_glGenFramebuffers;
static void GLAD_API_PTR glad_on_demand_impl_glGenProgramPipelines(GLsizei n, GLuint * pipelines) {
    glad_glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC) glad_gl_on_demand_loader("glGenProgramPipelines");
    glad_glGenProgramPipelines(n, pipelines);
}
PFNGLGENPROGRAMPIPELINESPROC glad_glGenProgramPipelines = glad_on_demand_impl_glGenProgramPipelines;
static void GLAD_API_PTR glad_on_demand_impl_glGenQueries(GLsizei n, GLuint * ids) {
    glad_glGenQueries = (PFNGLGENQUERIESPROC) glad_gl_on_demand_loader("glGenQueries");
    glad_glGenQueries(n, ids);
}
PFNGLGENQUERIESPROC glad_glGenQueries = glad_on_demand_impl_glGenQueries;
static void GLAD_API_PTR glad_on_demand_impl_glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    glad_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC) glad_gl_on_demand_loader("glGenRenderbuffers");
    glad_glGenRenderbuffers(n, renderbuffers);
}
PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers = glad_on_demand_impl_glGenRenderbuffers;
static void GLAD_API_PTR glad_on_demand_impl_glGenSamplers(GLsizei count, GLuint * samplers) {
    glad_glGenSamplers = (PFNGLGENSAMPLERSPROC) glad_gl_on_demand_loader("glGenSamplers");
    glad_glGenSamplers(count, samplers);
}
PFNGLGENSAMPLERSPROC glad_glGenSamplers = glad_on_demand_impl_glGenSamplers;
static void GLAD_API_PTR glad_on_demand_impl_glGenTextures(GLsizei n, GLuint * textures) {
    glad_glGenTextures = (PFNGLGENTEXTURESPROC) glad_gl_on_demand_loader("glGenTextures");
    glad_glGenTextures(n, textures);
}
PFNGLGENTEXTURESPROC glad_glGenTextures = glad_on_demand_impl_glGenTextures;
static void GLAD_API_PTR glad_on_demand_impl_glGenTransformFeedbacks(GLsizei n, GLuint * ids) {
    glad_glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC) glad_gl_on_demand_loader("glGenTransformFeedbacks");
    glad_glGenTransformFeedbacks(n, ids);
}
PFNGLGENTRANSFORMFEEDBACKSPROC glad_glGenTransformFeedbacks = glad_on_demand_impl_glGenTransformFeedbacks;
static void GLAD_API_PTR glad_on_demand_impl_glGenVertexArrays(GLsizei n, GLuint * arrays) {
    glad_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC) glad_gl_on_demand_loader("glGenVertexArrays");
    glad_glGenVertexArrays(n, arrays);
}
PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays = glad_on_demand_impl_glGenVertexArrays;
static void GLAD_API_PTR glad_on_demand_impl_glGenerateMipmap(GLenum target) {
    glad_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) glad_gl_on_demand_loader("glGenerateMipmap");
    glad_glGenerateMipmap(target);
}
PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap = glad_on_demand_impl_glGenerateMipmap;
static void GLAD_API_PTR glad_on_demand_impl_glGenerateTextureMipmap(GLuint texture) {
    glad_glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC) glad_gl_on_demand_loader("glGenerateTextureMipmap");
    glad_glGenerateTextureMipmap(texture);
}
PFNGLGENERATETEXTUREMIPMAPPROC glad_glGenerateTextureMipmap = glad_on_demand_impl_glGenerateTextureMipmap;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params) {
    glad_glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) glad_gl_on_demand_loader("glGetActiveAtomicCounterBufferiv");
    glad_glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params);
}
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glad_glGetActiveAtomicCounterBufferiv = glad_on_demand_impl_glGetActiveAtomicCounterBufferiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    glad_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC) glad_gl_on_demand_loader("glGetActiveAttrib");
    glad_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib = glad_on_demand_impl_glGetActiveAttrib;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
    glad_glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC) glad_gl_on_demand_loader("glGetActiveSubroutineName");
    glad_glGetActiveSubroutineName(program, shadertype, index, bufSize, length, name);
}
PFNGLGETACTIVESUBROUTINENAMEPROC glad_glGetActiveSubroutineName = glad_on_demand_impl_glGetActiveSubroutineName;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
    glad_glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) glad_gl_on_demand_loader("glGetActiveSubroutineUniformName");
    glad_glGetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name);
}
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glad_glGetActiveSubroutineUniformName = glad_on_demand_impl_glGetActiveSubroutineUniformName;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values) {
    glad_glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) glad_gl_on_demand_loader("glGetActiveSubroutineUniformiv");
    glad_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values);
}
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glad_glGetActiveSubroutineUniformiv = glad_on_demand_impl_glGetActiveSubroutineUniformiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    glad_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) glad_gl_on_demand_loader("glGetActiveUniform");
    glad_glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform = glad_on_demand_impl_glGetActiveUniform;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName) {
    glad_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) glad_gl_on_demand_loader("glGetActiveUniformBlockName");
    glad_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName = glad_on_demand_impl_glGetActiveUniformBlockName;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params) {
    glad_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC) glad_gl_on_demand_loader("glGetActiveUniformBlockiv");
    glad_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv = glad_on_demand_impl_glGetActiveUniformBlockiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName) {
    glad_glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC) glad_gl_on_demand_loader("glGetActiveUniformName");
    glad_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
}
PFNGLGETACTIVEUNIFORMNAMEPROC glad_glGetActiveUniformName = glad_on_demand_impl_glGetActiveUniformName;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params) {
    glad_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC) glad_gl_on_demand_loader("glGetActiveUniformsiv");
    glad_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}
PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv = glad_on_demand_impl_glGetActiveUniformsiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) {
    glad_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) glad_gl_on_demand_loader("glGetAttachedShaders");
    glad_glGetAttachedShaders(program, maxCount, count, shaders);
}
PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders = glad_on_demand_impl_glGetAttachedShaders;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetAttribLocation(GLuint program, const GLchar * name) {
    glad_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) glad_gl_on_demand_loader("glGetAttribLocation");
    return glad_glGetAttribLocation(program, name);
}
PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation = glad_on_demand_impl_glGetAttribLocation;
static void GLAD_API_PTR glad_on_demand_impl_glGetBooleani_v(GLenum target, GLuint index, GLboolean * data) {
    glad_glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC) glad_gl_on_demand_loader("glGetBooleani_v");
    glad_glGetBooleani_v(target, index, data);
}
PFNGLGETBOOLEANI_VPROC glad_glGetBooleani_v = glad_on_demand_impl_glGetBooleani_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetBooleanv(GLenum pname, GLboolean * data) {
    glad_glGetBooleanv = (PFNGLGETBOOLEANVPROC) glad_gl_on_demand_loader("glGetBooleanv");
    glad_glGetBooleanv(pname, data);
}
PFNGLGETBOOLEANVPROC glad_glGetBooleanv = glad_on_demand_impl_glGetBooleanv;
static void GLAD_API_PTR glad_on_demand_impl_glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 * params) {
    glad_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC) glad_gl_on_demand_loader("glGetBufferParameteri64v");
    glad_glGetBufferParameteri64v(target, pname, params);
}
PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v = glad_on_demand_impl_glGetBufferParameteri64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetBufferParameteriv");
    glad_glGetBufferParameteriv(target, pname, params);
}
PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv = glad_on_demand_impl_glGetBufferParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetBufferPointerv(GLenum target, GLenum pname, void ** params) {
    glad_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC) glad_gl_on_demand_loader("glGetBufferPointerv");
    glad_glGetBufferPointerv(target, pname, params);
}
PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv = glad_on_demand_impl_glGetBufferPointerv;
static void GLAD_API_PTR glad_on_demand_impl_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data) {
    glad_glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glGetBufferSubData");
    glad_glGetBufferSubData(target, offset, size, data);
}
PFNGLGETBUFFERSUBDATAPROC glad_glGetBufferSubData = glad_on_demand_impl_glGetBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glGetCompressedTexImage(GLenum target, GLint level, void * img) {
    glad_glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC) glad_gl_on_demand_loader("glGetCompressedTexImage");
    glad_glGetCompressedTexImage(target, level, img);
}
PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage = glad_on_demand_impl_glGetCompressedTexImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void * pixels) {
    glad_glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) glad_gl_on_demand_loader("glGetCompressedTextureImage");
    glad_glGetCompressedTextureImage(texture, level, bufSize, pixels);
}
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glad_glGetCompressedTextureImage = glad_on_demand_impl_glGetCompressedTextureImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels) {
    glad_glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) glad_gl_on_demand_loader("glGetCompressedTextureSubImage");
    glad_glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glad_glGetCompressedTextureSubImage = glad_on_demand_impl_glGetCompressedTextureSubImage;
static GLuint GLAD_API_PTR glad_on_demand_impl_glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog) {
    glad_glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC) glad_gl_on_demand_loader("glGetDebugMessageLog");
    return glad_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
PFNGLGETDEBUGMESSAGELOGPROC glad_glGetDebugMessageLog = glad_on_demand_impl_glGetDebugMessageLog;
static void GLAD_API_PTR glad_on_demand_impl_glGetDoublei_v(GLenum target, GLuint index, GLdouble * data) {
    glad_glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC) glad_gl_on_demand_loader("glGetDoublei_v");
    glad_glGetDoublei_v(target, index, data);
}
PFNGLGETDOUBLEI_VPROC glad_glGetDoublei_v = glad_on_demand_impl_glGetDoublei_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetDoublev(GLenum pname, GLdouble * data) {
    glad_glGetDoublev = (PFNGLGETDOUBLEVPROC) glad_gl_on_demand_loader("glGetDoublev");
    glad_glGetDoublev(pname, data);
}
PFNGLGETDOUBLEVPROC glad_glGetDoublev = glad_on_demand_impl_glGetDoublev;
static GLenum GLAD_API_PTR glad_on_demand_impl_glGetError(void) {
    glad_glGetError = (PFNGLGETERRORPROC) glad_gl_on_demand_loader("glGetError");
    return glad_glGetError();
}
PFNGLGETERRORPROC glad_glGetError = glad_on_demand_impl_glGetError;
static void GLAD_API_PTR glad_on_demand_impl_glGetFloati_v(GLenum target, GLuint index, GLfloat * data) {
    glad_glGetFloati_v = (PFNGLGETFLOATI_VPROC) glad_gl_on_demand_loader("glGetFloati_v");
    glad_glGetFloati_v(target, index, data);
}
PFNGLGETFLOATI_VPROC glad_glGetFloati_v = glad_on_demand_impl_glGetFloati_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetFloatv(GLenum pname, GLfloat * data) {
    glad_glGetFloatv = (PFNGLGETFLOATVPROC) glad_gl_on_demand_loader("glGetFloatv");
    glad_glGetFloatv(pname, data);
}
PFNGLGETFLOATVPROC glad_glGetFloatv = glad_on_demand_impl_glGetFloatv;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetFragDataIndex(GLuint program, const GLchar * name) {
    glad_glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC) glad_gl_on_demand_loader("glGetFragDataIndex");
    return glad_glGetFragDataIndex(program, name);
}
PFNGLGETFRAGDATAINDEXPROC glad_glGetFragDataIndex = glad_on_demand_impl_glGetFragDataIndex;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetFragDataLocation(GLuint program, const GLchar * name) {
    glad_glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC) glad_gl_on_demand_loader("glGetFragDataLocation");
    return glad_glGetFragDataLocation(program, name);
}
PFNGLGETFRAGDATALOCATIONPROC glad_glGetFragDataLocation = glad_on_demand_impl_glGetFragDataLocation;
static void GLAD_API_PTR glad_on_demand_impl_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    glad_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) glad_gl_on_demand_loader("glGetFramebufferAttachmentParameteriv");
    glad_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv = glad_on_demand_impl_glGetFramebufferAttachmentParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetFramebufferParameteriv");
    glad_glGetFramebufferParameteriv(target, pname, params);
}
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glad_glGetFramebufferParameteriv = glad_on_demand_impl_glGetFramebufferParameteriv;
static GLenum GLAD_API_PTR glad_on_demand_impl_glGetGraphicsResetStatus(void) {
    glad_glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC) glad_gl_on_demand_loader("glGetGraphicsResetStatus");
    return glad_glGetGraphicsResetStatus();
}
PFNGLGETGRAPHICSRESETSTATUSPROC glad_glGetGraphicsResetStatus = glad_on_demand_impl_glGetGraphicsResetStatus;
static void GLAD_API_PTR glad_on_demand_impl_glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data) {
    glad_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC) glad_gl_on_demand_loader("glGetInteger64i_v");
    glad_glGetInteger64i_v(target, index, data);
}
PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v = glad_on_demand_impl_glGetInteger64i_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetInteger64v(GLenum pname, GLint64 * data) {
    glad_glGetInteger64v = (PFNGLGETINTEGER64VPROC) glad_gl_on_demand_loader("glGetInteger64v");
    glad_glGetInteger64v(pname, data);
}
PFNGLGETINTEGER64VPROC glad_glGetInteger64v = glad_on_demand_impl_glGetInteger64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetIntegeri_v(GLenum target, GLuint index, GLint * data) {
    glad_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC) glad_gl_on_demand_loader("glGetIntegeri_v");
    glad_glGetIntegeri_v(target, index, data);
}
PFNGLGETINTEGERI_VPROC glad_glGetIntegeri_v = glad_on_demand_impl_glGetIntegeri_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetIntegerv(GLenum pname, GLint * data) {
    glad_glGetIntegerv = (PFNGLGETINTEGERVPROC) glad_gl_on_demand_loader("glGetIntegerv");
    glad_glGetIntegerv(pname, data);
}
PFNGLGETINTEGERVPROC glad_glGetIntegerv = glad_on_demand_impl_glGetIntegerv;
static void GLAD_API_PTR glad_on_demand_impl_glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params) {
    glad_glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC) glad_gl_on_demand_loader("glGetInternalformati64v");
    glad_glGetInternalformati64v(target, internalformat, pname, count, params);
}
PFNGLGETINTERNALFORMATI64VPROC glad_glGetInternalformati64v = glad_on_demand_impl_glGetInternalformati64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params) {
    glad_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC) glad_gl_on_demand_loader("glGetInternalformativ");
    glad_glGetInternalformativ(target, internalformat, pname, count, params);
}
PFNGLGETINTERNALFORMATIVPROC glad_glGetInternalformativ = glad_on_demand_impl_glGetInternalformativ;
static void GLAD_API_PTR glad_on_demand_impl_glGetMultisamplefv(GLenum pname, GLuint index, GLfloat * val) {
    glad_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC) glad_gl_on_demand_loader("glGetMultisamplefv");
    glad_glGetMultisamplefv(pname, index, val);
}
PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv = glad_on_demand_impl_glGetMultisamplefv;
static void GLAD_API_PTR glad_on_demand_impl_glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params) {
    glad_glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) glad_gl_on_demand_loader("glGetNamedBufferParameteri64v");
    glad_glGetNamedBufferParameteri64v(buffer, pname, params);
}
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glad_glGetNamedBufferParameteri64v = glad_on_demand_impl_glGetNamedBufferParameteri64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params) {
    glad_glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetNamedBufferParameteriv");
    glad_glGetNamedBufferParameteriv(buffer, pname, params);
}
PFNGLGETNAMEDBUFFERPARAMETERIVPROC glad_glGetNamedBufferParameteriv = glad_on_demand_impl_glGetNamedBufferParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void ** params) {
    glad_glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC) glad_gl_on_demand_loader("glGetNamedBufferPointerv");
    glad_glGetNamedBufferPointerv(buffer, pname, params);
}
PFNGLGETNAMEDBUFFERPOINTERVPROC glad_glGetNamedBufferPointerv = glad_on_demand_impl_glGetNamedBufferPointerv;
static void GLAD_API_PTR glad_on_demand_impl_glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data) {
    glad_glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glGetNamedBufferSubData");
    glad_glGetNamedBufferSubData(buffer, offset, size, data);
}
PFNGLGETNAMEDBUFFERSUBDATAPROC glad_glGetNamedBufferSubData = glad_on_demand_impl_glGetNamedBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params) {
    glad_glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) glad_gl_on_demand_loader("glGetNamedFramebufferAttachmentParameteriv");
    glad_glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params);
}
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetNamedFramebufferAttachmentParameteriv = glad_on_demand_impl_glGetNamedFramebufferAttachmentParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint * param) {
    glad_glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetNamedFramebufferParameteriv");
    glad_glGetNamedFramebufferParameteriv(framebuffer, pname, param);
}
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glad_glGetNamedFramebufferParameteriv = glad_on_demand_impl_glGetNamedFramebufferParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint * params) {
    glad_glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetNamedRenderbufferParameteriv");
    glad_glGetNamedRenderbufferParameteriv(renderbuffer, pname, params);
}
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glad_glGetNamedRenderbufferParameteriv = glad_on_demand_impl_glGetNamedRenderbufferParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label) {
    glad_glGetObjectLabel = (PFNGLGETOBJECTLABELPROC) glad_gl_on_demand_loader("glGetObjectLabel");
    glad_glGetObjectLabel(identifier, name, bufSize, length, label);
}
PFNGLGETOBJECTLABELPROC glad_glGetObjectLabel = glad_on_demand_impl_glGetObjectLabel;
static void GLAD_API_PTR glad_on_demand_impl_glGetObjectPtrLabel(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label) {
    glad_glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC) glad_gl_on_demand_loader("glGetObjectPtrLabel");
    glad_glGetObjectPtrLabel(ptr, bufSize, length, label);
}
PFNGLGETOBJECTPTRLABELPROC glad_glGetObjectPtrLabel = glad_on_demand_impl_glGetObjectPtrLabel;
static void GLAD_API_PTR glad_on_demand_impl_glGetPointerv(GLenum pname, void ** params) {
    glad_glGetPointerv = (PFNGLGETPOINTERVPROC) glad_gl_on_demand_loader("glGetPointerv");
    glad_glGetPointerv(pname, params);
}
PFNGLGETPOINTERVPROC glad_glGetPointerv = glad_on_demand_impl_glGetPointerv;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary) {
    glad_glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC) glad_gl_on_demand_loader("glGetProgramBinary");
    glad_glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}
PFNGLGETPROGRAMBINARYPROC glad_glGetProgramBinary = glad_on_demand_impl_glGetProgramBinary;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) glad_gl_on_demand_loader("glGetProgramInfoLog");
    glad_glGetProgramInfoLog(program, bufSize, length, infoLog);
}
PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog = glad_on_demand_impl_glGetProgramInfoLog;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params) {
    glad_glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC) glad_gl_on_demand_loader("glGetProgramInterfaceiv");
    glad_glGetProgramInterfaceiv(program, programInterface, pname, params);
}
PFNGLGETPROGRAMINTERFACEIVPROC glad_glGetProgramInterfaceiv = glad_on_demand_impl_glGetProgramInterfaceiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    glad_glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC) glad_gl_on_demand_loader("glGetProgramPipelineInfoLog");
    glad_glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
}
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glad_glGetProgramPipelineInfoLog = glad_on_demand_impl_glGetProgramPipelineInfoLog;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint * params) {
    glad_glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC) glad_gl_on_demand_loader("glGetProgramPipelineiv");
    glad_glGetProgramPipelineiv(pipeline, pname, params);
}
PFNGLGETPROGRAMPIPELINEIVPROC glad_glGetProgramPipelineiv = glad_on_demand_impl_glGetProgramPipelineiv;
static GLuint GLAD_API_PTR glad_on_demand_impl_glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name) {
    glad_glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC) glad_gl_on_demand_loader("glGetProgramResourceIndex");
    return glad_glGetProgramResourceIndex(program, programInterface, name);
}
PFNGLGETPROGRAMRESOURCEINDEXPROC glad_glGetProgramResourceIndex = glad_on_demand_impl_glGetProgramResourceIndex;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name) {
    glad_glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC) glad_gl_on_demand_loader("glGetProgramResourceLocation");
    return glad_glGetProgramResourceLocation(program, programInterface, name);
}
PFNGLGETPROGRAMRESOURCELOCATIONPROC glad_glGetProgramResourceLocation = glad_on_demand_impl_glGetProgramResourceLocation;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar * name) {
    glad_glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) glad_gl_on_demand_loader("glGetProgramResourceLocationIndex");
    return glad_glGetProgramResourceLocationIndex(program, programInterface, name);
}
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glad_glGetProgramResourceLocationIndex = glad_on_demand_impl_glGetProgramResourceLocationIndex;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
    glad_glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC) glad_gl_on_demand_loader("glGetProgramResourceName");
    glad_glGetProgramResourceName(program, programInterface, index, bufSize, length, name);
}
PFNGLGETPROGRAMRESOURCENAMEPROC glad_glGetProgramResourceName = glad_on_demand_impl_glGetProgramResourceName;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params) {
    glad_glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC) glad_gl_on_demand_loader("glGetProgramResourceiv");
    glad_glGetProgramResourceiv(program, programInterface, index, propCount, props, count, length, params);
}
PFNGLGETPROGRAMRESOURCEIVPROC glad_glGetProgramResourceiv = glad_on_demand_impl_glGetProgramResourceiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint * values) {
    glad_glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC) glad_gl_on_demand_loader("glGetProgramStageiv");
    glad_glGetProgramStageiv(program, shadertype, pname, values);
}
PFNGLGETPROGRAMSTAGEIVPROC glad_glGetProgramStageiv = glad_on_demand_impl_glGetProgramStageiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC) glad_gl_on_demand_loader("glGetProgramiv");
    glad_glGetProgramiv(program, pname, params);
}
PFNGLGETPROGRAMIVPROC glad_glGetProgramiv = glad_on_demand_impl_glGetProgramiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
    glad_glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC) glad_gl_on_demand_loader("glGetQueryBufferObjecti64v");
    glad_glGetQueryBufferObjecti64v(id, buffer, pname, offset);
}
PFNGLGETQUERYBUFFEROBJECTI64VPROC glad_glGetQueryBufferObjecti64v = glad_on_demand_impl_glGetQueryBufferObjecti64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
    glad_glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC) glad_gl_on_demand_loader("glGetQueryBufferObjectiv");
    glad_glGetQueryBufferObjectiv(id, buffer, pname, offset);
}
PFNGLGETQUERYBUFFEROBJECTIVPROC glad_glGetQueryBufferObjectiv = glad_on_demand_impl_glGetQueryBufferObjectiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
    glad_glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC) glad_gl_on_demand_loader("glGetQueryBufferObjectui64v");
    glad_glGetQueryBufferObjectui64v(id, buffer, pname, offset);
}
PFNGLGETQUERYBUFFEROBJECTUI64VPROC glad_glGetQueryBufferObjectui64v = glad_on_demand_impl_glGetQueryBufferObjectui64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
    glad_glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC) glad_gl_on_demand_loader("glGetQueryBufferObjectuiv");
    glad_glGetQueryBufferObjectuiv(id, buffer, pname, offset);
}
PFNGLGETQUERYBUFFEROBJECTUIVPROC glad_glGetQueryBufferObjectuiv = glad_on_demand_impl_glGetQueryBufferObjectuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params) {
    glad_glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC) glad_gl_on_demand_loader("glGetQueryIndexediv");
    glad_glGetQueryIndexediv(target, index, pname, params);
}
PFNGLGETQUERYINDEXEDIVPROC glad_glGetQueryIndexediv = glad_on_demand_impl_glGetQueryIndexediv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params) {
    glad_glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC) glad_gl_on_demand_loader("glGetQueryObjecti64v");
    glad_glGetQueryObjecti64v(id, pname, params);
}
PFNGLGETQUERYOBJECTI64VPROC glad_glGetQueryObjecti64v = glad_on_demand_impl_glGetQueryObjecti64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    glad_glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC) glad_gl_on_demand_loader("glGetQueryObjectiv");
    glad_glGetQueryObjectiv(id, pname, params);
}
PFNGLGETQUERYOBJECTIVPROC glad_glGetQueryObjectiv = glad_on_demand_impl_glGetQueryObjectiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params) {
    glad_glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC) glad_gl_on_demand_loader("glGetQueryObjectui64v");
    glad_glGetQueryObjectui64v(id, pname, params);
}
PFNGLGETQUERYOBJECTUI64VPROC glad_glGetQueryObjectui64v = glad_on_demand_impl_glGetQueryObjectui64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    glad_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC) glad_gl_on_demand_loader("glGetQueryObjectuiv");
    glad_glGetQueryObjectuiv(id, pname, params);
}
PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv = glad_on_demand_impl_glGetQueryObjectuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetQueryiv = (PFNGLGETQUERYIVPROC) glad_gl_on_demand_loader("glGetQueryiv");
    glad_glGetQueryiv(target, pname, params);
}
PFNGLGETQUERYIVPROC glad_glGetQueryiv = glad_on_demand_impl_glGetQueryiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetRenderbufferParameteriv");
    glad_glGetRenderbufferParameteriv(target, pname, params);
}
PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv = glad_on_demand_impl_glGetRenderbufferParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params) {
    glad_glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC) glad_gl_on_demand_loader("glGetSamplerParameterIiv");
    glad_glGetSamplerParameterIiv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIIVPROC glad_glGetSamplerParameterIiv = glad_on_demand_impl_glGetSamplerParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params) {
    glad_glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC) glad_gl_on_demand_loader("glGetSamplerParameterIuiv");
    glad_glGetSamplerParameterIuiv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIUIVPROC glad_glGetSamplerParameterIuiv = glad_on_demand_impl_glGetSamplerParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params) {
    glad_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC) glad_gl_on_demand_loader("glGetSamplerParameterfv");
    glad_glGetSamplerParameterfv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERFVPROC glad_glGetSamplerParameterfv = glad_on_demand_impl_glGetSamplerParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params) {
    glad_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetSamplerParameteriv");
    glad_glGetSamplerParameteriv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIVPROC glad_glGetSamplerParameteriv = glad_on_demand_impl_glGetSamplerParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) glad_gl_on_demand_loader("glGetShaderInfoLog");
    glad_glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog = glad_on_demand_impl_glGetShaderInfoLog;
static void GLAD_API_PTR glad_on_demand_impl_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
    glad_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC) glad_gl_on_demand_loader("glGetShaderPrecisionFormat");
    glad_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
PFNGLGETSHADERPRECISIONFORMATPROC glad_glGetShaderPrecisionFormat = glad_on_demand_impl_glGetShaderPrecisionFormat;
static void GLAD_API_PTR glad_on_demand_impl_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    glad_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC) glad_gl_on_demand_loader("glGetShaderSource");
    glad_glGetShaderSource(shader, bufSize, length, source);
}
PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource = glad_on_demand_impl_glGetShaderSource;
static void GLAD_API_PTR glad_on_demand_impl_glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    glad_glGetShaderiv = (PFNGLGETSHADERIVPROC) glad_gl_on_demand_loader("glGetShaderiv");
    glad_glGetShaderiv(shader, pname, params);
}
PFNGLGETSHADERIVPROC glad_glGetShaderiv = glad_on_demand_impl_glGetShaderiv;
static const GLubyte * GLAD_API_PTR glad_on_demand_impl_glGetString(GLenum name) {
    glad_glGetString = (PFNGLGETSTRINGPROC) glad_gl_on_demand_loader("glGetString");
    return glad_glGetString(name);
}
PFNGLGETSTRINGPROC glad_glGetString = glad_on_demand_impl_glGetString;
static const GLubyte * GLAD_API_PTR glad_on_demand_impl_glGetStringi(GLenum name, GLuint index) {
    glad_glGetStringi = (PFNGLGETSTRINGIPROC) glad_gl_on_demand_loader("glGetStringi");
    return glad_glGetStringi(name, index);
}
PFNGLGETSTRINGIPROC glad_glGetStringi = glad_on_demand_impl_glGetStringi;
static GLuint GLAD_API_PTR glad_on_demand_impl_glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar * name) {
    glad_glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC) glad_gl_on_demand_loader("glGetSubroutineIndex");
    return glad_glGetSubroutineIndex(program, shadertype, name);
}
PFNGLGETSUBROUTINEINDEXPROC glad_glGetSubroutineIndex = glad_on_demand_impl_glGetSubroutineIndex;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar * name) {
    glad_glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) glad_gl_on_demand_loader("glGetSubroutineUniformLocation");
    return glad_glGetSubroutineUniformLocation(program, shadertype, name);
}
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glad_glGetSubroutineUniformLocation = glad_on_demand_impl_glGetSubroutineUniformLocation;
static void GLAD_API_PTR glad_on_demand_impl_glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values) {
    glad_glGetSynciv = (PFNGLGETSYNCIVPROC) glad_gl_on_demand_loader("glGetSynciv");
    glad_glGetSynciv(sync, pname, count, length, values);
}
PFNGLGETSYNCIVPROC glad_glGetSynciv = glad_on_demand_impl_glGetSynciv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels) {
    glad_glGetTexImage = (PFNGLGETTEXIMAGEPROC) glad_gl_on_demand_loader("glGetTexImage");
    glad_glGetTexImage(target, level, format, type, pixels);
}
PFNGLGETTEXIMAGEPROC glad_glGetTexImage = glad_on_demand_impl_glGetTexImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    glad_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC) glad_gl_on_demand_loader("glGetTexLevelParameterfv");
    glad_glGetTexLevelParameterfv(target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv = glad_on_demand_impl_glGetTexLevelParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    glad_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC) glad_gl_on_demand_loader("glGetTexLevelParameteriv");
    glad_glGetTexLevelParameteriv(target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv = glad_on_demand_impl_glGetTexLevelParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC) glad_gl_on_demand_loader("glGetTexParameterIiv");
    glad_glGetTexParameterIiv(target, pname, params);
}
PFNGLGETTEXPARAMETERIIVPROC glad_glGetTexParameterIiv = glad_on_demand_impl_glGetTexParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params) {
    glad_glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC) glad_gl_on_demand_loader("glGetTexParameterIuiv");
    glad_glGetTexParameterIuiv(target, pname, params);
}
PFNGLGETTEXPARAMETERIUIVPROC glad_glGetTexParameterIuiv = glad_on_demand_impl_glGetTexParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glad_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC) glad_gl_on_demand_loader("glGetTexParameterfv");
    glad_glGetTexParameterfv(target, pname, params);
}
PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv = glad_on_demand_impl_glGetTexParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC) glad_gl_on_demand_loader("glGetTexParameteriv");
    glad_glGetTexParameteriv(target, pname, params);
}
PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv = glad_on_demand_impl_glGetTexParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels) {
    glad_glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC) glad_gl_on_demand_loader("glGetTextureImage");
    glad_glGetTextureImage(texture, level, format, type, bufSize, pixels);
}
PFNGLGETTEXTUREIMAGEPROC glad_glGetTextureImage = glad_on_demand_impl_glGetTextureImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat * params) {
    glad_glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC) glad_gl_on_demand_loader("glGetTextureLevelParameterfv");
    glad_glGetTextureLevelParameterfv(texture, level, pname, params);
}
PFNGLGETTEXTURELEVELPARAMETERFVPROC glad_glGetTextureLevelParameterfv = glad_on_demand_impl_glGetTextureLevelParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint * params) {
    glad_glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC) glad_gl_on_demand_loader("glGetTextureLevelParameteriv");
    glad_glGetTextureLevelParameteriv(texture, level, pname, params);
}
PFNGLGETTEXTURELEVELPARAMETERIVPROC glad_glGetTextureLevelParameteriv = glad_on_demand_impl_glGetTextureLevelParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint * params) {
    glad_glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC) glad_gl_on_demand_loader("glGetTextureParameterIiv");
    glad_glGetTextureParameterIiv(texture, pname, params);
}
PFNGLGETTEXTUREPARAMETERIIVPROC glad_glGetTextureParameterIiv = glad_on_demand_impl_glGetTextureParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params) {
    glad_glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC) glad_gl_on_demand_loader("glGetTextureParameterIuiv");
    glad_glGetTextureParameterIuiv(texture, pname, params);
}
PFNGLGETTEXTUREPARAMETERIUIVPROC glad_glGetTextureParameterIuiv = glad_on_demand_impl_glGetTextureParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat * params) {
    glad_glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC) glad_gl_on_demand_loader("glGetTextureParameterfv");
    glad_glGetTextureParameterfv(texture, pname, params);
}
PFNGLGETTEXTUREPARAMETERFVPROC glad_glGetTextureParameterfv = glad_on_demand_impl_glGetTextureParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTextureParameteriv(GLuint texture, GLenum pname, GLint * params) {
    glad_glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC) glad_gl_on_demand_loader("glGetTextureParameteriv");
    glad_glGetTextureParameteriv(texture, pname, params);
}
PFNGLGETTEXTUREPARAMETERIVPROC glad_glGetTextureParameteriv = glad_on_demand_impl_glGetTextureParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels) {
    glad_glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC) glad_gl_on_demand_loader("glGetTextureSubImage");
    glad_glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}
PFNGLGETTEXTURESUBIMAGEPROC glad_glGetTextureSubImage = glad_on_demand_impl_glGetTextureSubImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) {
    glad_glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) glad_gl_on_demand_loader("glGetTransformFeedbackVarying");
    glad_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_glGetTransformFeedbackVarying = glad_on_demand_impl_glGetTransformFeedbackVarying;
static void GLAD_API_PTR glad_on_demand_impl_glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 * param) {
    glad_glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC) glad_gl_on_demand_loader("glGetTransformFeedbacki64_v");
    glad_glGetTransformFeedbacki64_v(xfb, pname, index, param);
}
PFNGLGETTRANSFORMFEEDBACKI64_VPROC glad_glGetTransformFeedbacki64_v = glad_on_demand_impl_glGetTransformFeedbacki64_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint * param) {
    glad_glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC) glad_gl_on_demand_loader("glGetTransformFeedbacki_v");
    glad_glGetTransformFeedbacki_v(xfb, pname, index, param);
}
PFNGLGETTRANSFORMFEEDBACKI_VPROC glad_glGetTransformFeedbacki_v = glad_on_demand_impl_glGetTransformFeedbacki_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint * param) {
    glad_glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC) glad_gl_on_demand_loader("glGetTransformFeedbackiv");
    glad_glGetTransformFeedbackiv(xfb, pname, param);
}
PFNGLGETTRANSFORMFEEDBACKIVPROC glad_glGetTransformFeedbackiv = glad_on_demand_impl_glGetTransformFeedbackiv;
static GLuint GLAD_API_PTR glad_on_demand_impl_glGetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName) {
    glad_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC) glad_gl_on_demand_loader("glGetUniformBlockIndex");
    return glad_glGetUniformBlockIndex(program, uniformBlockName);
}
PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex = glad_on_demand_impl_glGetUniformBlockIndex;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices) {
    glad_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC) glad_gl_on_demand_loader("glGetUniformIndices");
    glad_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}
PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices = glad_on_demand_impl_glGetUniformIndices;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetUniformLocation(GLuint program, const GLchar * name) {
    glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) glad_gl_on_demand_loader("glGetUniformLocation");
    return glad_glGetUniformLocation(program, name);
}
PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation = glad_on_demand_impl_glGetUniformLocation;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * params) {
    glad_glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC) glad_gl_on_demand_loader("glGetUniformSubroutineuiv");
    glad_glGetUniformSubroutineuiv(shadertype, location, params);
}
PFNGLGETUNIFORMSUBROUTINEUIVPROC glad_glGetUniformSubroutineuiv = glad_on_demand_impl_glGetUniformSubroutineuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformdv(GLuint program, GLint location, GLdouble * params) {
    glad_glGetUniformdv = (PFNGLGETUNIFORMDVPROC) glad_gl_on_demand_loader("glGetUniformdv");
    glad_glGetUniformdv(program, location, params);
}
PFNGLGETUNIFORMDVPROC glad_glGetUniformdv = glad_on_demand_impl_glGetUniformdv;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    glad_glGetUniformfv = (PFNGLGETUNIFORMFVPROC) glad_gl_on_demand_loader("glGetUniformfv");
    glad_glGetUniformfv(program, location, params);
}
PFNGLGETUNIFORMFVPROC glad_glGetUniformfv = glad_on_demand_impl_glGetUniformfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformiv(GLuint program, GLint location, GLint * params) {
    glad_glGetUniformiv = (PFNGLGETUNIFORMIVPROC) glad_gl_on_demand_loader("glGetUniformiv");
    glad_glGetUniformiv(program, location, params);
}
PFNGLGETUNIFORMIVPROC glad_glGetUniformiv = glad_on_demand_impl_glGetUniformiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformuiv(GLuint program, GLint location, GLuint * params) {
    glad_glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC) glad_gl_on_demand_loader("glGetUniformuiv");
    glad_glGetUniformuiv(program, location, params);
}
PFNGLGETUNIFORMUIVPROC glad_glGetUniformuiv = glad_on_demand_impl_glGetUniformuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param) {
    glad_glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC) glad_gl_on_demand_loader("glGetVertexArrayIndexed64iv");
    glad_glGetVertexArrayIndexed64iv(vaobj, index, pname, param);
}
PFNGLGETVERTEXARRAYINDEXED64IVPROC glad_glGetVertexArrayIndexed64iv = glad_on_demand_impl_glGetVertexArrayIndexed64iv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint * param) {
    glad_glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC) glad_gl_on_demand_loader("glGetVertexArrayIndexediv");
    glad_glGetVertexArrayIndexediv(vaobj, index, pname, param);
}
PFNGLGETVERTEXARRAYINDEXEDIVPROC glad_glGetVertexArrayIndexediv = glad_on_demand_impl_glGetVertexArrayIndexediv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint * param) {
    glad_glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC) glad_gl_on_demand_loader("glGetVertexArrayiv");
    glad_glGetVertexArrayiv(vaobj, pname, param);
}
PFNGLGETVERTEXARRAYIVPROC glad_glGetVertexArrayiv = glad_on_demand_impl_glGetVertexArrayiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params) {
    glad_glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC) glad_gl_on_demand_loader("glGetVertexAttribIiv");
    glad_glGetVertexAttribIiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIIVPROC glad_glGetVertexAttribIiv = glad_on_demand_impl_glGetVertexAttribIiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params) {
    glad_glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC) glad_gl_on_demand_loader("glGetVertexAttribIuiv");
    glad_glGetVertexAttribIuiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIUIVPROC glad_glGetVertexAttribIuiv = glad_on_demand_impl_glGetVertexAttribIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble * params) {
    glad_glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC) glad_gl_on_demand_loader("glGetVertexAttribLdv");
    glad_glGetVertexAttribLdv(index, pname, params);
}
PFNGLGETVERTEXATTRIBLDVPROC glad_glGetVertexAttribLdv = glad_on_demand_impl_glGetVertexAttribLdv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer) {
    glad_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC) glad_gl_on_demand_loader("glGetVertexAttribPointerv");
    glad_glGetVertexAttribPointerv(index, pname, pointer);
}
PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv = glad_on_demand_impl_glGetVertexAttribPointerv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params) {
    glad_glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC) glad_gl_on_demand_loader("glGetVertexAttribdv");
    glad_glGetVertexAttribdv(index, pname, params);
}
PFNGLGETVERTEXATTRIBDVPROC glad_glGetVertexAttribdv = glad_on_demand_impl_glGetVertexAttribdv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    glad_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC) glad_gl_on_demand_loader("glGetVertexAttribfv");
    glad_glGetVertexAttribfv(index, pname, params);
}
PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv = glad_on_demand_impl_glGetVertexAttribfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    glad_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC) glad_gl_on_demand_loader("glGetVertexAttribiv");
    glad_glGetVertexAttribiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv = glad_on_demand_impl_glGetVertexAttribiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void * pixels) {
    glad_glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC) glad_gl_on_demand_loader("glGetnCompressedTexImage");
    glad_glGetnCompressedTexImage(target, lod, bufSize, pixels);
}
PFNGLGETNCOMPRESSEDTEXIMAGEPROC glad_glGetnCompressedTexImage = glad_on_demand_impl_glGetnCompressedTexImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels) {
    glad_glGetnTexImage = (PFNGLGETNTEXIMAGEPROC) glad_gl_on_demand_loader("glGetnTexImage");
    glad_glGetnTexImage(target, level, format, type, bufSize, pixels);
}
PFNGLGETNTEXIMAGEPROC glad_glGetnTexImage = glad_on_demand_impl_glGetnTexImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble * params) {
    glad_glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC) glad_gl_on_demand_loader("glGetnUniformdv");
    glad_glGetnUniformdv(program, location, bufSize, params);
}
PFNGLGETNUNIFORMDVPROC glad_glGetnUniformdv = glad_on_demand_impl_glGetnUniformdv;
static void GLAD_API_PTR glad_on_demand_impl_glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat * params) {
    glad_glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC) glad_gl_on_demand_loader("glGetnUniformfv");
    glad_glGetnUniformfv(program, location, bufSize, params);
}
PFNGLGETNUNIFORMFVPROC glad_glGetnUniformfv = glad_on_demand_impl_glGetnUniformfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint * params) {
    glad_glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC) glad_gl_on_demand_loader("glGetnUniformiv");
    glad_glGetnUniformiv(program, location, bufSize, params);
}
PFNGLGETNUNIFORMIVPROC glad_glGetnUniformiv = glad_on_demand_impl_glGetnUniformiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint * params) {
    glad_glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC) glad_gl_on_demand_loader("glGetnUniformuiv");
    glad_glGetnUniformuiv(program, location, bufSize, params);
}
PFNGLGETNUNIFORMUIVPROC glad_glGetnUniformuiv = glad_on_demand_impl_glGetnUniformuiv;
static void GLAD_API_PTR glad_on_demand_impl_glHint(GLenum target, GLenum mode) {
    glad_glHint = (PFNGLHINTPROC) glad_gl_on_demand_loader("glHint");
    glad_glHint(target, mode);
}
PFNGLHINTPROC glad_glHint = glad_on_demand_impl_glHint;
static void GLAD_API_PTR glad_on_demand_impl_glInvalidateBufferData(GLuint buffer) {
    glad_glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC) glad_gl_on_demand_loader("glInvalidateBufferData");
    glad_glInvalidateBufferData(buffer);
}
PFNGLINVALIDATEBUFFERDATAPROC glad_glInvalidateBufferData = glad_on_demand_impl_glInvalidateBufferData;
static void GLAD_API_PTR glad_on_demand_impl_glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) {
    glad_glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glInvalidateBufferSubData");
    glad_glInvalidateBufferSubData(buffer, offset, length);
}
PFNGLINVALIDATEBUFFERSUBDATAPROC glad_glInvalidateBufferSubData = glad_on_demand_impl_glInvalidateBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments) {
    glad_glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC) glad_gl_on_demand_loader("glInvalidateFramebuffer");
    glad_glInvalidateFramebuffer(target, numAttachments, attachments);
}
PFNGLINVALIDATEFRAMEBUFFERPROC glad_glInvalidateFramebuffer = glad_on_demand_impl_glInvalidateFramebuffer;
static void GLAD_API_PTR glad_on_demand_impl_glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments) {
    glad_glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) glad_gl_on_demand_loader("glInvalidateNamedFramebufferData");
    glad_glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments);
}
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glad_glInvalidateNamedFramebufferData = glad_on_demand_impl_glInvalidateNamedFramebufferData;
static void GLAD_API_PTR glad_on_demand_impl_glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glInvalidateNamedFramebufferSubData");
    glad_glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height);
}
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glad_glInvalidateNamedFramebufferSubData = glad_on_demand_impl_glInvalidateNamedFramebufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC) glad_gl_on_demand_loader("glInvalidateSubFramebuffer");
    glad_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
}
PFNGLINVALIDATESUBFRAMEBUFFERPROC glad_glInvalidateSubFramebuffer = glad_on_demand_impl_glInvalidateSubFramebuffer;
static void GLAD_API_PTR glad_on_demand_impl_glInvalidateTexImage(GLuint texture, GLint level) {
    glad_glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC) glad_gl_on_demand_loader("glInvalidateTexImage");
    glad_glInvalidateTexImage(texture, level);
}
PFNGLINVALIDATETEXIMAGEPROC glad_glInvalidateTexImage = glad_on_demand_impl_glInvalidateTexImage;
static void GLAD_API_PTR glad_on_demand_impl_glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) {
    glad_glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC) glad_gl_on_demand_loader("glInvalidateTexSubImage");
    glad_glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}
PFNGLINVALIDATETEXSUBIMAGEPROC glad_glInvalidateTexSubImage = glad_on_demand_impl_glInvalidateTexSubImage;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsBuffer(GLuint buffer) {
    glad_glIsBuffer = (PFNGLISBUFFERPROC) glad_gl_on_demand_loader("glIsBuffer");
    return glad_glIsBuffer(buffer);
}
PFNGLISBUFFERPROC glad_glIsBuffer = glad_on_demand_impl_glIsBuffer;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsEnabled(GLenum cap) {
    glad_glIsEnabled = (PFNGLISENABLEDPROC) glad_gl_on_demand_loader("glIsEnabled");
    return glad_glIsEnabled(cap);
}
PFNGLISENABLEDPROC glad_glIsEnabled = glad_on_demand_impl_glIsEnabled;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsEnabledi(GLenum target, GLuint index) {
    glad_glIsEnabledi = (PFNGLISENABLEDIPROC) glad_gl_on_demand_loader("glIsEnabledi");
    return glad_glIsEnabledi(target, index);
}
PFNGLISENABLEDIPROC glad_glIsEnabledi = glad_on_demand_impl_glIsEnabledi;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsFramebuffer(GLuint framebuffer) {
    glad_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC) glad_gl_on_demand_loader("glIsFramebuffer");
    return glad_glIsFramebuffer(framebuffer);
}
PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer = glad_on_demand_impl_glIsFramebuffer;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsProgram(GLuint program) {
    glad_glIsProgram = (PFNGLISPROGRAMPROC) glad_gl_on_demand_loader("glIsProgram");
    return glad_glIsProgram(program);
}
PFNGLISPROGRAMPROC glad_glIsProgram = glad_on_demand_impl_glIsProgram;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsProgramPipeline(GLuint pipeline) {
    glad_glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC) glad_gl_on_demand_loader("glIsProgramPipeline");
    return glad_glIsProgramPipeline(pipeline);
}
PFNGLISPROGRAMPIPELINEPROC glad_glIsProgramPipeline = glad_on_demand_impl_glIsProgramPipeline;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsQuery(GLuint id) {
    glad_glIsQuery = (PFNGLISQUERYPROC) glad_gl_on_demand_loader("glIsQuery");
    return glad_glIsQuery(id);
}
PFNGLISQUERYPROC glad_glIsQuery = glad_on_demand_impl_glIsQuery;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsRenderbuffer(GLuint renderbuffer) {
    glad_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC) glad_gl_on_demand_loader("glIsRenderbuffer");
    return glad_glIsRenderbuffer(renderbuffer);
}
PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer = glad_on_demand_impl_glIsRenderbuffer;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsSampler(GLuint sampler) {
    glad_glIsSampler = (PFNGLISSAMPLERPROC) glad_gl_on_demand_loader("glIsSampler");
    return glad_glIsSampler(sampler);
}
PFNGLISSAMPLERPROC glad_glIsSampler = glad_on_demand_impl_glIsSampler;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsShader(GLuint shader) {
    glad_glIsShader = (PFNGLISSHADERPROC) glad_gl_on_demand_loader("glIsShader");
    return glad_glIsShader(shader);
}
PFNGLISSHADERPROC glad_glIsShader = glad_on_demand_impl_glIsShader;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsSync(GLsync sync) {
    glad_glIsSync = (PFNGLISSYNCPROC) glad_gl_on_demand_loader("glIsSync");
    return glad_glIsSync(sync);
}
PFNGLISSYNCPROC glad_glIsSync = glad_on_demand_impl_glIsSync;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsTexture(GLuint texture) {
    glad_glIsTexture = (PFNGLISTEXTUREPROC) glad_gl_on_demand_loader("glIsTexture");
    return glad_glIsTexture(texture);
}
PFNGLISTEXTUREPROC glad_glIsTexture = glad_on_demand_impl_glIsTexture;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsTransformFeedback(GLuint id) {
    glad_glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glIsTransformFeedback");
    return glad_glIsTransformFeedback(id);
}
PFNGLISTRANSFORMFEEDBACKPROC glad_glIsTransformFeedback = glad_on_demand_impl_glIsTransformFeedback;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsVertexArray(GLuint array) {
    glad_glIsVertexArray = (PFNGLISVERTEXARRAYPROC) glad_gl_on_demand_loader("glIsVertexArray");
    return glad_glIsVertexArray(array);
}
PFNGLISVERTEXARRAYPROC glad_glIsVertexArray = glad_on_demand_impl_glIsVertexArray;
static void GLAD_API_PTR glad_on_demand_impl_glLineWidth(GLfloat width) {
    glad_glLineWidth = (PFNGLLINEWIDTHPROC) glad_gl_on_demand_loader("glLineWidth");
    glad_glLineWidth(width);
}
PFNGLLINEWIDTHPROC glad_glLineWidth = glad_on_demand_impl_glLineWidth;
static void GLAD_API_PTR glad_on_demand_impl_glLinkProgram(GLuint program) {
    glad_glLinkProgram = (PFNGLLINKPROGRAMPROC) glad_gl_on_demand_loader("glLinkProgram");
    glad_glLinkProgram(program);
}
PFNGLLINKPROGRAMPROC glad_glLinkProgram = glad_on_demand_impl_glLinkProgram;
static void GLAD_API_PTR glad_on_demand_impl_glLogicOp(GLenum opcode) {
    glad_glLogicOp = (PFNGLLOGICOPPROC) glad_gl_on_demand_loader("glLogicOp");
    glad_glLogicOp(opcode);
}
PFNGLLOGICOPPROC glad_glLogicOp = glad_on_demand_impl_glLogicOp;
static void * GLAD_API_PTR glad_on_demand_impl_glMapBuffer(GLenum target, GLenum access) {
    glad_glMapBuffer = (PFNGLMAPBUFFERPROC) glad_gl_on_demand_loader("glMapBuffer");
    return glad_glMapBuffer(target, access);
}
PFNGLMAPBUFFERPROC glad_glMapBuffer = glad_on_demand_impl_glMapBuffer;
static void * GLAD_API_PTR glad_on_demand_impl_glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    glad_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC) glad_gl_on_demand_loader("glMapBufferRange");
    return glad_glMapBufferRange(target, offset, length, access);
}
PFNGLMAPBUFFERRANGEPROC glad_glMapBufferRange = glad_on_demand_impl_glMapBufferRange;
static void * GLAD_API_PTR glad_on_demand_impl_glMapNamedBuffer(GLuint buffer, GLenum access) {
    glad_glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC) glad_gl_on_demand_loader("glMapNamedBuffer");
    return glad_glMapNamedBuffer(buffer, access);
}
PFNGLMAPNAMEDBUFFERPROC glad_glMapNamedBuffer = glad_on_demand_impl_glMapNamedBuffer;
static void * GLAD_API_PTR glad_on_demand_impl_glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    glad_glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC) glad_gl_on_demand_loader("glMapNamedBufferRange");
    return glad_glMapNamedBufferRange(buffer, offset, length, access);
}
PFNGLMAPNAMEDBUFFERRANGEPROC glad_glMapNamedBufferRange = glad_on_demand_impl_glMapNamedBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glMemoryBarrier(GLbitfield barriers) {
    glad_glMemoryBarrier = (PFNGLMEMORYBARRIERPROC) glad_gl_on_demand_loader("glMemoryBarrier");
    glad_glMemoryBarrier(barriers);
}
PFNGLMEMORYBARRIERPROC glad_glMemoryBarrier = glad_on_demand_impl_glMemoryBarrier;
static void GLAD_API_PTR glad_on_demand_impl_glMemoryBarrierByRegion(GLbitfield barriers) {
    glad_glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC) glad_gl_on_demand_loader("glMemoryBarrierByRegion");
    glad_glMemoryBarrierByRegion(barriers);
}
PFNGLMEMORYBARRIERBYREGIONPROC glad_glMemoryBarrierByRegion = glad_on_demand_impl_glMemoryBarrierByRegion;
static void GLAD_API_PTR glad_on_demand_impl_glMinSampleShading(GLfloat value) {
    glad_glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC) glad_gl_on_demand_loader("glMinSampleShading");
    glad_glMinSampleShading(value);
}
PFNGLMINSAMPLESHADINGPROC glad_glMinSampleShading = glad_on_demand_impl_glMinSampleShading;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    glad_glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC) glad_gl_on_demand_loader("glMultiDrawArrays");
    glad_glMultiDrawArrays(mode, first, count, drawcount);
}
PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays = glad_on_demand_impl_glMultiDrawArrays;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawArraysIndirect(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride) {
    glad_glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC) glad_gl_on_demand_loader("glMultiDrawArraysIndirect");
    glad_glMultiDrawArraysIndirect(mode, indirect, drawcount, stride);
}
PFNGLMULTIDRAWARRAYSINDIRECTPROC glad_glMultiDrawArraysIndirect = glad_on_demand_impl_glMultiDrawArraysIndirect;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawArraysIndirectCount(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
    glad_glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC) glad_gl_on_demand_loader("glMultiDrawArraysIndirectCount");
    glad_glMultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride);
}
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glad_glMultiDrawArraysIndirectCount = glad_on_demand_impl_glMultiDrawArraysIndirectCount;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount) {
    glad_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC) glad_gl_on_demand_loader("glMultiDrawElements");
    glad_glMultiDrawElements(mode, count, type, indices, drawcount);
}
PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements = glad_on_demand_impl_glMultiDrawElements;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex) {
    glad_glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) glad_gl_on_demand_loader("glMultiDrawElementsBaseVertex");
    glad_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex);
}
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glad_glMultiDrawElementsBaseVertex = glad_on_demand_impl_glMultiDrawElementsBaseVertex;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride) {
    glad_glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC) glad_gl_on_demand_loader("glMultiDrawElementsIndirect");
    glad_glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride);
}
PFNGLMULTIDRAWELEMENTSINDIRECTPROC glad_glMultiDrawElementsIndirect = glad_on_demand_impl_glMultiDrawElementsIndirect;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
    glad_glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) glad_gl_on_demand_loader("glMultiDrawElementsIndirectCount");
    glad_glMultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride);
}
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glad_glMultiDrawElementsIndirectCount = glad_on_demand_impl_glMultiDrawElementsIndirectCount;
static void GLAD_API_PTR glad_on_demand_impl_glNamedBufferData(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage) {
    glad_glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC) glad_gl_on_demand_loader("glNamedBufferData");
    glad_glNamedBufferData(buffer, size, data, usage);
}
PFNGLNAMEDBUFFERDATAPROC glad_glNamedBufferData = glad_on_demand_impl_glNamedBufferData;
static void GLAD_API_PTR glad_on_demand_impl_glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags) {
    glad_glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC) glad_gl_on_demand_loader("glNamedBufferStorage");
    glad_glNamedBufferStorage(buffer, size, data, flags);
}
PFNGLNAMEDBUFFERSTORAGEPROC glad_glNamedBufferStorage = glad_on_demand_impl_glNamedBufferStorage;
static void GLAD_API_PTR glad_on_demand_impl_glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data) {
    glad_glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glNamedBufferSubData");
    glad_glNamedBufferSubData(buffer, offset, size, data);
}
PFNGLNAMEDBUFFERSUBDATAPROC glad_glNamedBufferSubData = glad_on_demand_impl_glNamedBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) {
    glad_glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) glad_gl_on_demand_loader("glNamedFramebufferDrawBuffer");
    glad_glNamedFramebufferDrawBuffer(framebuffer, buf);
}
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glad_glNamedFramebufferDrawBuffer = glad_on_demand_impl_glNamedFramebufferDrawBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum * bufs) {
    glad_glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) glad_gl_on_demand_loader("glNamedFramebufferDrawBuffers");
    glad_glNamedFramebufferDrawBuffers(framebuffer, n, bufs);
}
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glad_glNamedFramebufferDrawBuffers = glad_on_demand_impl_glNamedFramebufferDrawBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) {
    glad_glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) glad_gl_on_demand_loader("glNamedFramebufferParameteri");
    glad_glNamedFramebufferParameteri(framebuffer, pname, param);
}
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glad_glNamedFramebufferParameteri = glad_on_demand_impl_glNamedFramebufferParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) {
    glad_glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) glad_gl_on_demand_loader("glNamedFramebufferReadBuffer");
    glad_glNamedFramebufferReadBuffer(framebuffer, src);
}
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glad_glNamedFramebufferReadBuffer = glad_on_demand_impl_glNamedFramebufferReadBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    glad_glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) glad_gl_on_demand_loader("glNamedFramebufferRenderbuffer");
    glad_glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer);
}
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glad_glNamedFramebufferRenderbuffer = glad_on_demand_impl_glNamedFramebufferRenderbuffer;
static void GLAD_API_PTR glad_on_demand_impl_glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
    glad_glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) glad_gl_on_demand_loader("glNamedFramebufferTexture");
    glad_glNamedFramebufferTexture(framebuffer, attachment, texture, level);
}
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glad_glNamedFramebufferTexture = glad_on_demand_impl_glNamedFramebufferTexture;
static void GLAD_API_PTR glad_on_demand_impl_glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    glad_glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) glad_gl_on_demand_loader("glNamedFramebufferTextureLayer");
    glad_glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer);
}
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glad_glNamedFramebufferTextureLayer = glad_on_demand_impl_glNamedFramebufferTextureLayer;
static void GLAD_API_PTR glad_on_demand_impl_glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
    glad_glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC) glad_gl_on_demand_loader("glNamedRenderbufferStorage");
    glad_glNamedRenderbufferStorage(renderbuffer, internalformat, width, height);
}
PFNGLNAMEDRENDERBUFFERSTORAGEPROC glad_glNamedRenderbufferStorage = glad_on_demand_impl_glNamedRenderbufferStorage;
static void GLAD_API_PTR glad_on_demand_impl_glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    glad_glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) glad_gl_on_demand_loader("glNamedRenderbufferStorageMultisample");
    glad_glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height);
}
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glNamedRenderbufferStorageMultisample = glad_on_demand_impl_glNamedRenderbufferStorageMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label) {
    glad_glObjectLabel = (PFNGLOBJECTLABELPROC) glad_gl_on_demand_loader("glObjectLabel");
    glad_glObjectLabel(identifier, name, length, label);
}
PFNGLOBJECTLABELPROC glad_glObjectLabel = glad_on_demand_impl_glObjectLabel;
static void GLAD_API_PTR glad_on_demand_impl_glObjectPtrLabel(const void * ptr, GLsizei length, const GLchar * label) {
    glad_glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC) glad_gl_on_demand_loader("glObjectPtrLabel");
    glad_glObjectPtrLabel(ptr, length, label);
}
PFNGLOBJECTPTRLABELPROC glad_glObjectPtrLabel = glad_on_demand_impl_glObjectPtrLabel;
static void GLAD_API_PTR glad_on_demand_impl_glPatchParameterfv(GLenum pname, const GLfloat * values) {
    glad_glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC) glad_gl_on_demand_loader("glPatchParameterfv");
    glad_glPatchParameterfv(pname, values);
}
PFNGLPATCHPARAMETERFVPROC glad_glPatchParameterfv = glad_on_demand_impl_glPatchParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glPatchParameteri(GLenum pname, GLint value) {
    glad_glPatchParameteri = (PFNGLPATCHPARAMETERIPROC) glad_gl_on_demand_loader("glPatchParameteri");
    glad_glPatchParameteri(pname, value);
}
PFNGLPATCHPARAMETERIPROC glad_glPatchParameteri = glad_on_demand_impl_glPatchParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glPauseTransformFeedback(void) {
    glad_glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glPauseTransformFeedback");
    glad_glPauseTransformFeedback();
}
PFNGLPAUSETRANSFORMFEEDBACKPROC glad_glPauseTransformFeedback = glad_on_demand_impl_glPauseTransformFeedback;
static void GLAD_API_PTR glad_on_demand_impl_glPixelStoref(GLenum pname, GLfloat param) {
    glad_glPixelStoref = (PFNGLPIXELSTOREFPROC) glad_gl_on_demand_loader("glPixelStoref");
    glad_glPixelStoref(pname, param);
}
PFNGLPIXELSTOREFPROC glad_glPixelStoref = glad_on_demand_impl_glPixelStoref;
static void GLAD_API_PTR glad_on_demand_impl_glPixelStorei(GLenum pname, GLint param) {
    glad_glPixelStorei = (PFNGLPIXELSTOREIPROC) glad_gl_on_demand_loader("glPixelStorei");
    glad_glPixelStorei(pname, param);
}
PFNGLPIXELSTOREIPROC glad_glPixelStorei = glad_on_demand_impl_glPixelStorei;
static void GLAD_API_PTR glad_on_demand_impl_glPointParameterf(GLenum pname, GLfloat param) {
    glad_glPointParameterf = (PFNGLPOINTPARAMETERFPROC) glad_gl_on_demand_loader("glPointParameterf");
    glad_glPointParameterf(pname, param);
}
PFNGLPOINTPARAMETERFPROC glad_glPointParameterf = glad_on_demand_impl_glPointParameterf;
static void GLAD_API_PTR glad_on_demand_impl_glPointParameterfv(GLenum pname, const GLfloat * params) {
    glad_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC) glad_gl_on_demand_loader("glPointParameterfv");
    glad_glPointParameterfv(pname, params);
}
PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv = glad_on_demand_impl_glPointParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glPointParameteri(GLenum pname, GLint param) {
    glad_glPointParameteri = (PFNGLPOINTPARAMETERIPROC) glad_gl_on_demand_loader("glPointParameteri");
    glad_glPointParameteri(pname, param);
}
PFNGLPOINTPARAMETERIPROC glad_glPointParameteri = glad_on_demand_impl_glPointParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glPointParameteriv(GLenum pname, const GLint * params) {
    glad_glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC) glad_gl_on_demand_loader("glPointParameteriv");
    glad_glPointParameteriv(pname, params);
}
PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv = glad_on_demand_impl_glPointParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glPointSize(GLfloat size) {
    glad_glPointSize = (PFNGLPOINTSIZEPROC) glad_gl_on_demand_loader("glPointSize");
    glad_glPointSize(size);
}
PFNGLPOINTSIZEPROC glad_glPointSize = glad_on_demand_impl_glPointSize;
static void GLAD_API_PTR glad_on_demand_impl_glPolygonMode(GLenum face, GLenum mode) {
    glad_glPolygonMode = (PFNGLPOLYGONMODEPROC) glad_gl_on_demand_loader("glPolygonMode");
    glad_glPolygonMode(face, mode);
}
PFNGLPOLYGONMODEPROC glad_glPolygonMode = glad_on_demand_impl_glPolygonMode;
static void GLAD_API_PTR glad_on_demand_impl_glPolygonOffset(GLfloat factor, GLfloat units) {
    glad_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC) glad_gl_on_demand_loader("glPolygonOffset");
    glad_glPolygonOffset(factor, units);
}
PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset = glad_on_demand_impl_glPolygonOffset;
static void GLAD_API_PTR glad_on_demand_impl_glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) {
    glad_glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC) glad_gl_on_demand_loader("glPolygonOffsetClamp");
    glad_glPolygonOffsetClamp(factor, units, clamp);
}
PFNGLPOLYGONOFFSETCLAMPPROC glad_glPolygonOffsetClamp = glad_on_demand_impl_glPolygonOffsetClamp;
static void GLAD_API_PTR glad_on_demand_impl_glPopDebugGroup(void) {
    glad_glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC) glad_gl_on_demand_loader("glPopDebugGroup");
    glad_glPopDebugGroup();
}
PFNGLPOPDEBUGGROUPPROC glad_glPopDebugGroup = glad_on_demand_impl_glPopDebugGroup;
static void GLAD_API_PTR glad_on_demand_impl_glPrimitiveRestartIndex(GLuint index) {
    glad_glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC) glad_gl_on_demand_loader("glPrimitiveRestartIndex");
    glad_glPrimitiveRestartIndex(index);
}
PFNGLPRIMITIVERESTARTINDEXPROC glad_glPrimitiveRestartIndex = glad_on_demand_impl_glPrimitiveRestartIndex;
static void GLAD_API_PTR glad_on_demand_impl_glProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length) {
    glad_glProgramBinary = (PFNGLPROGRAMBINARYPROC) glad_gl_on_demand_loader("glProgramBinary");
    glad_glProgramBinary(program, binaryFormat, binary, length);
}
PFNGLPROGRAMBINARYPROC glad_glProgramBinary = glad_on_demand_impl_glProgramBinary;
static void GLAD_API_PTR glad_on_demand_impl_glProgramParameteri(GLuint program, GLenum pname, GLint value) {
    glad_glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC) glad_gl_on_demand_loader("glProgramParameteri");
    glad_glProgramParameteri(program, pname, value);
}
PFNGLPROGRAMPARAMETERIPROC glad_glProgramParameteri = glad_on_demand_impl_glProgramParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform1d(GLuint program, GLint location, GLdouble v0) {
    glad_glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC) glad_gl_on_demand_loader("glProgramUniform1d");
    glad_glProgramUniform1d(program, location, v0);
}
PFNGLPROGRAMUNIFORM1DPROC glad_glProgramUniform1d = glad_on_demand_impl_glProgramUniform1d;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble * value) {
    glad_glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC) glad_gl_on_demand_loader("glProgramUniform1dv");
    glad_glProgramUniform1dv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1DVPROC glad_glProgramUniform1dv = glad_on_demand_impl_glProgramUniform1dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
    glad_glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC) glad_gl_on_demand_loader("glProgramUniform1f");
    glad_glProgramUniform1f(program, location, v0);
}
PFNGLPROGRAMUNIFORM1FPROC glad_glProgramUniform1f = glad_on_demand_impl_glProgramUniform1f;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat * value) {
    glad_glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC) glad_gl_on_demand_loader("glProgramUniform1fv");
    glad_glProgramUniform1fv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1FVPROC glad_glProgramUniform1fv = glad_on_demand_impl_glProgramUniform1fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform1i(GLuint program, GLint location, GLint v0) {
    glad_glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC) glad_gl_on_demand_loader("glProgramUniform1i");
    glad_glProgramUniform1i(program, location, v0);
}
PFNGLPROGRAMUNIFORM1IPROC glad_glProgramUniform1i = glad_on_demand_impl_glProgramUniform1i;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint * value) {
    glad_glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC) glad_gl_on_demand_loader("glProgramUniform1iv");
    glad_glProgramUniform1iv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1IVPROC glad_glProgramUniform1iv = glad_on_demand_impl_glProgramUniform1iv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform1ui(GLuint program, GLint location, GLuint v0) {
    glad_glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC) glad_gl_on_demand_loader("glProgramUniform1ui");
    glad_glProgramUniform1ui(program, location, v0);
}
PFNGLPROGRAMUNIFORM1UIPROC glad_glProgramUniform1ui = glad_on_demand_impl_glProgramUniform1ui;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint * value) {
    glad_glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC) glad_gl_on_demand_loader("glProgramUniform1uiv");
    glad_glProgramUniform1uiv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1UIVPROC glad_glProgramUniform1uiv = glad_on_demand_impl_glProgramUniform1uiv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) {
    glad_glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC) glad_gl_on_demand_loader("glProgramUniform2d");
    glad_glProgramUniform2d(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2DPROC glad_glProgramUniform2d = glad_on_demand_impl_glProgramUniform2d;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble * value) {
    glad_glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC) glad_gl_on_demand_loader("glProgramUniform2dv");
    glad_glProgramUniform2dv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2DVPROC glad_glProgramUniform2dv = glad_on_demand_impl_glProgramUniform2dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
    glad_glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC) glad_gl_on_demand_loader("glProgramUniform2f");
    glad_glProgramUniform2f(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2FPROC glad_glProgramUniform2f = glad_on_demand_impl_glProgramUniform2f;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat * value) {
    glad_glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC) glad_gl_on_demand_loader("glProgramUniform2fv");
    glad_glProgramUniform2fv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2FVPROC glad_glProgramUniform2fv = glad_on_demand_impl_glProgramUniform2fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {
    glad_glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC) glad_gl_on_demand_loader("glProgramUniform2i");
    glad_glProgramUniform2i(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2IPROC glad_glProgramUniform2i = glad_on_demand_impl_glProgramUniform2i;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint * value) {
    glad_glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC) glad_gl_on_demand_loader("glProgramUniform2iv");
    glad_glProgramUniform2iv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2IVPROC glad_glProgramUniform2iv = glad_on_demand_impl_glProgramUniform2iv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) {
    glad_glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC) glad_gl_on_demand_loader("glProgramUniform2ui");
    glad_glProgramUniform2ui(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2UIPROC glad_glProgramUniform2ui = glad_on_demand_impl_glProgramUniform2ui;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint * value) {
    glad_glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC) glad_gl_on_demand_loader("glProgramUniform2uiv");
    glad_glProgramUniform2uiv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2UIVPROC glad_glProgramUniform2uiv = glad_on_demand_impl_glProgramUniform2uiv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) {
    glad_glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC) glad_gl_on_demand_loader("glProgramUniform3d");
    glad_glProgramUniform3d(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3DPROC glad_glProgramUniform3d = glad_on_demand_impl_glProgramUniform3d;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble * value) {
    glad_glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC) glad_gl_on_demand_loader("glProgramUniform3dv");
    glad_glProgramUniform3dv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3DVPROC glad_glProgramUniform3dv = glad_on_demand_impl_glProgramUniform3dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    glad_glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC) glad_gl_on_demand_loader("glProgramUniform3f");
    glad_glProgramUniform3f(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3FPROC glad_glProgramUniform3f = glad_on_demand_impl_glProgramUniform3f;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat * value) {
    glad_glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC) glad_gl_on_demand_loader("glProgramUniform3fv");
    glad_glProgramUniform3fv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3FVPROC glad_glProgramUniform3fv = glad_on_demand_impl_glProgramUniform3fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
    glad_glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC) glad_gl_on_demand_loader("glProgramUniform3i");
    glad_glProgramUniform3i(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3IPROC glad_glProgramUniform3i = glad_on_demand_impl_glProgramUniform3i;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint * value) {
    glad_glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC) glad_gl_on_demand_loader("glProgramUniform3iv");
    glad_glProgramUniform3iv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3IVPROC glad_glProgramUniform3iv = glad_on_demand_impl_glProgramUniform3iv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
    glad_glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC) glad_gl_on_demand_loader("glProgramUniform3ui");
    glad_glProgramUniform3ui(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3UIPROC glad_glProgramUniform3ui = glad_on_demand_impl_glProgramUniform3ui;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint * value) {
    glad_glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC) glad_gl_on_demand_loader("glProgramUniform3uiv");
    glad_glProgramUniform3uiv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3UIVPROC glad_glProgramUniform3uiv = glad_on_demand_impl_glProgramUniform3uiv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) {
    glad_glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC) glad_gl_on_demand_loader("glProgramUniform4d");
    glad_glProgramUniform4d(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4DPROC glad_glProgramUniform4d = glad_on_demand_impl_glProgramUniform4d;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble * value) {
    glad_glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC) glad_gl_on_demand_loader("glProgramUniform4dv");
    glad_glProgramUniform4dv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4DVPROC glad_glProgramUniform4dv = glad_on_demand_impl_glProgramUniform4dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    glad_glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC) glad_gl_on_demand_loader("glProgramUniform4f");
    glad_glProgramUniform4f(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4FPROC glad_glProgramUniform4f = glad_on_demand_impl_glProgramUniform4f;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat * value) {
    glad_glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC) glad_gl_on_demand_loader("glProgramUniform4fv");
    glad_glProgramUniform4fv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4FVPROC glad_glProgramUniform4fv = glad_on_demand_impl_glProgramUniform4fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    glad_glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC) glad_gl_on_demand_loader("glProgramUniform4i");
    glad_glProgramUniform4i(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4IPROC glad_glProgramUniform4i = glad_on_demand_impl_glProgramUniform4i;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint * value) {
    glad_glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC) glad_gl_on_demand_loader("glProgramUniform4iv");
    glad_glProgramUniform4iv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4IVPROC glad_glProgramUniform4iv = glad_on_demand_impl_glProgramUniform4iv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    glad_glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC) glad_gl_on_demand_loader("glProgramUniform4ui");
    glad_glProgramUniform4ui(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4UIPROC glad_glProgramUniform4ui = glad_on_demand_impl_glProgramUniform4ui;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint * value) {
    glad_glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC) glad_gl_on_demand_loader("glProgramUniform4uiv");
    glad_glProgramUniform4uiv(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4UIVPROC glad_glProgramUniform4uiv = glad_on_demand_impl_glProgramUniform4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix2dv");
    glad_glProgramUniformMatrix2dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2DVPROC glad_glProgramUniformMatrix2dv = glad_on_demand_impl_glProgramUniformMatrix2dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix2fv");
    glad_glProgramUniformMatrix2fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glad_glProgramUniformMatrix2fv = glad_on_demand_impl_glProgramUniformMatrix2fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix2x3dv");
    glad_glProgramUniformMatrix2x3dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glad_glProgramUniformMatrix2x3dv = glad_on_demand_impl_glProgramUniformMatrix2x3dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix2x3fv");
    glad_glProgramUniformMatrix2x3fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glad_glProgramUniformMatrix2x3fv = glad_on_demand_impl_glProgramUniformMatrix2x3fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix2x4dv");
    glad_glProgramUniformMatrix2x4dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glad_glProgramUniformMatrix2x4dv = glad_on_demand_impl_glProgramUniformMatrix2x4dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix2x4fv");
    glad_glProgramUniformMatrix2x4fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glad_glProgramUniformMatrix2x4fv = glad_on_demand_impl_glProgramUniformMatrix2x4fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix3dv");
    glad_glProgramUniformMatrix3dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3DVPROC glad_glProgramUniformMatrix3dv = glad_on_demand_impl_glProgramUniformMatrix3dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix3fv");
    glad_glProgramUniformMatrix3fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glad_glProgramUniformMatrix3fv = glad_on_demand_impl_glProgramUniformMatrix3fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix3x2dv");
    glad_glProgramUniformMatrix3x2dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glad_glProgramUniformMatrix3x2dv = glad_on_demand_impl_glProgramUniformMatrix3x2dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix3x2fv");
    glad_glProgramUniformMatrix3x2fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glad_glProgramUniformMatrix3x2fv = glad_on_demand_impl_glProgramUniformMatrix3x2fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix3x4dv");
    glad_glProgramUniformMatrix3x4dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glad_glProgramUniformMatrix3x4dv = glad_on_demand_impl_glProgramUniformMatrix3x4dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix3x4fv");
    glad_glProgramUniformMatrix3x4fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glad_glProgramUniformMatrix3x4fv = glad_on_demand_impl_glProgramUniformMatrix3x4fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix4dv");
    glad_glProgramUniformMatrix4dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4DVPROC glad_glProgramUniformMatrix4dv = glad_on_demand_impl_glProgramUniformMatrix4dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix4fv");
    glad_glProgramUniformMatrix4fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glad_glProgramUniformMatrix4fv = glad_on_demand_impl_glProgramUniformMatrix4fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix4x2dv");
    glad_glProgramUniformMatrix4x2dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glad_glProgramUniformMatrix4x2dv = glad_on_demand_impl_glProgramUniformMatrix4x2dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix4x2fv");
    glad_glProgramUniformMatrix4x2fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glad_glProgramUniformMatrix4x2fv = glad_on_demand_impl_glProgramUniformMatrix4x2fv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix4x3dv");
    glad_glProgramUniformMatrix4x3dv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glad_glProgramUniformMatrix4x3dv = glad_on_demand_impl_glProgramUniformMatrix4x3dv;
static void GLAD_API_PTR glad_on_demand_impl_glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) glad_gl_on_demand_loader("glProgramUniformMatrix4x3fv");
    glad_glProgramUniformMatrix4x3fv(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glad_glProgramUniformMatrix4x3fv = glad_on_demand_impl_glProgramUniformMatrix4x3fv;
static void GLAD_API_PTR glad_on_demand_impl_glProvokingVertex(GLenum mode) {
    glad_glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC) glad_gl_on_demand_loader("glProvokingVertex");
    glad_glProvokingVertex(mode);
}
PFNGLPROVOKINGVERTEXPROC glad_glProvokingVertex = glad_on_demand_impl_glProvokingVertex;
static void GLAD_API_PTR glad_on_demand_impl_glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message) {
    glad_glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC) glad_gl_on_demand_loader("glPushDebugGroup");
    glad_glPushDebugGroup(source, id, length, message);
}
PFNGLPUSHDEBUGGROUPPROC glad_glPushDebugGroup = glad_on_demand_impl_glPushDebugGroup;
static void GLAD_API_PTR glad_on_demand_impl_glQueryCounter(GLuint id, GLenum target) {
    glad_glQueryCounter = (PFNGLQUERYCOUNTERPROC) glad_gl_on_demand_loader("glQueryCounter");
    glad_glQueryCounter(id, target);
}
PFNGLQUERYCOUNTERPROC glad_glQueryCounter = glad_on_demand_impl_glQueryCounter;
static void GLAD_API_PTR glad_on_demand_impl_glReadBuffer(GLenum src) {
    glad_glReadBuffer = (PFNGLREADBUFFERPROC) glad_gl_on_demand_loader("glReadBuffer");
    glad_glReadBuffer(src);
}
PFNGLREADBUFFERPROC glad_glReadBuffer = glad_on_demand_impl_glReadBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) {
    glad_glReadPixels = (PFNGLREADPIXELSPROC) glad_gl_on_demand_loader("glReadPixels");
    glad_glReadPixels(x, y, width, height, format, type, pixels);
}
PFNGLREADPIXELSPROC glad_glReadPixels = glad_on_demand_impl_glReadPixels;
static void GLAD_API_PTR glad_on_demand_impl_glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data) {
    glad_glReadnPixels = (PFNGLREADNPIXELSPROC) glad_gl_on_demand_loader("glReadnPixels");
    glad_glReadnPixels(x, y, width, height, format, type, bufSize, data);
}
PFNGLREADNPIXELSPROC glad_glReadnPixels = glad_on_demand_impl_glReadnPixels;
static void GLAD_API_PTR glad_on_demand_impl_glReleaseShaderCompiler(void) {
    glad_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC) glad_gl_on_demand_loader("glReleaseShaderCompiler");
    glad_glReleaseShaderCompiler();
}
PFNGLRELEASESHADERCOMPILERPROC glad_glReleaseShaderCompiler = glad_on_demand_impl_glReleaseShaderCompiler;
static void GLAD_API_PTR glad_on_demand_impl_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    glad_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC) glad_gl_on_demand_loader("glRenderbufferStorage");
    glad_glRenderbufferStorage(target, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage = glad_on_demand_impl_glRenderbufferStorage;
static void GLAD_API_PTR glad_on_demand_impl_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    glad_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) glad_gl_on_demand_loader("glRenderbufferStorageMultisample");
    glad_glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glRenderbufferStorageMultisample = glad_on_demand_impl_glRenderbufferStorageMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glResumeTransformFeedback(void) {
    glad_glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glResumeTransformFeedback");
    glad_glResumeTransformFeedback();
}
PFNGLRESUMETRANSFORMFEEDBACKPROC glad_glResumeTransformFeedback = glad_on_demand_impl_glResumeTransformFeedback;
static void GLAD_API_PTR glad_on_demand_impl_glSampleCoverage(GLfloat value, GLboolean invert) {
    glad_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC) glad_gl_on_demand_loader("glSampleCoverage");
    glad_glSampleCoverage(value, invert);
}
PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage = glad_on_demand_impl_glSampleCoverage;
static void GLAD_API_PTR glad_on_demand_impl_glSampleMaski(GLuint maskNumber, GLbitfield mask) {
    glad_glSampleMaski = (PFNGLSAMPLEMASKIPROC) glad_gl_on_demand_loader("glSampleMaski");
    glad_glSampleMaski(maskNumber, mask);
}
PFNGLSAMPLEMASKIPROC glad_glSampleMaski = glad_on_demand_impl_glSampleMaski;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint * param) {
    glad_glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC) glad_gl_on_demand_loader("glSamplerParameterIiv");
    glad_glSamplerParameterIiv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIIVPROC glad_glSamplerParameterIiv = glad_on_demand_impl_glSamplerParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint * param) {
    glad_glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC) glad_gl_on_demand_loader("glSamplerParameterIuiv");
    glad_glSamplerParameterIuiv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIUIVPROC glad_glSamplerParameterIuiv = glad_on_demand_impl_glSamplerParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
    glad_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC) glad_gl_on_demand_loader("glSamplerParameterf");
    glad_glSamplerParameterf(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFPROC glad_glSamplerParameterf = glad_on_demand_impl_glSamplerParameterf;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * param) {
    glad_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC) glad_gl_on_demand_loader("glSamplerParameterfv");
    glad_glSamplerParameterfv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFVPROC glad_glSamplerParameterfv = glad_on_demand_impl_glSamplerParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
    glad_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC) glad_gl_on_demand_loader("glSamplerParameteri");
    glad_glSamplerParameteri(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIPROC glad_glSamplerParameteri = glad_on_demand_impl_glSamplerParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * param) {
    glad_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC) glad_gl_on_demand_loader("glSamplerParameteriv");
    glad_glSamplerParameteriv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIVPROC glad_glSamplerParameteriv = glad_on_demand_impl_glSamplerParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glScissor = (PFNGLSCISSORPROC) glad_gl_on_demand_loader("glScissor");
    glad_glScissor(x, y, width, height);
}
PFNGLSCISSORPROC glad_glScissor = glad_on_demand_impl_glScissor;
static void GLAD_API_PTR glad_on_demand_impl_glScissorArrayv(GLuint first, GLsizei count, const GLint * v) {
    glad_glScissorArrayv = (PFNGLSCISSORARRAYVPROC) glad_gl_on_demand_loader("glScissorArrayv");
    glad_glScissorArrayv(first, count, v);
}
PFNGLSCISSORARRAYVPROC glad_glScissorArrayv = glad_on_demand_impl_glScissorArrayv;
static void GLAD_API_PTR glad_on_demand_impl_glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
    glad_glScissorIndexed = (PFNGLSCISSORINDEXEDPROC) glad_gl_on_demand_loader("glScissorIndexed");
    glad_glScissorIndexed(index, left, bottom, width, height);
}
PFNGLSCISSORINDEXEDPROC glad_glScissorIndexed = glad_on_demand_impl_glScissorIndexed;
static void GLAD_API_PTR glad_on_demand_impl_glScissorIndexedv(GLuint index, const GLint * v) {
    glad_glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC) glad_gl_on_demand_loader("glScissorIndexedv");
    glad_glScissorIndexedv(index, v);
}
PFNGLSCISSORINDEXEDVPROC glad_glScissorIndexedv = glad_on_demand_impl_glScissorIndexedv;
static void GLAD_API_PTR glad_on_demand_impl_glShaderBinary(GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length) {
    glad_glShaderBinary = (PFNGLSHADERBINARYPROC) glad_gl_on_demand_loader("glShaderBinary");
    glad_glShaderBinary(count, shaders, binaryFormat, binary, length);
}
PFNGLSHADERBINARYPROC glad_glShaderBinary = glad_on_demand_impl_glShaderBinary;
static void GLAD_API_PTR glad_on_demand_impl_glShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length) {
    glad_glShaderSource = (PFNGLSHADERSOURCEPROC) glad_gl_on_demand_loader("glShaderSource");
    glad_glShaderSource(shader, count, string, length);
}
PFNGLSHADERSOURCEPROC glad_glShaderSource = glad_on_demand_impl_glShaderSource;
static void GLAD_API_PTR glad_on_demand_impl_glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) {
    glad_glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC) glad_gl_on_demand_loader("glShaderStorageBlockBinding");
    glad_glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
}
PFNGLSHADERSTORAGEBLOCKBINDINGPROC glad_glShaderStorageBlockBinding = glad_on_demand_impl_glShaderStorageBlockBinding;
static void GLAD_API_PTR glad_on_demand_impl_glSpecializeShader(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue) {
    glad_glSpecializeShader = (PFNGLSPECIALIZESHADERPROC) glad_gl_on_demand_loader("glSpecializeShader");
    glad_glSpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}
PFNGLSPECIALIZESHADERPROC glad_glSpecializeShader = glad_on_demand_impl_glSpecializeShader;
static void GLAD_API_PTR glad_on_demand_impl_glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    glad_glStencilFunc = (PFNGLSTENCILFUNCPROC) glad_gl_on_demand_loader("glStencilFunc");
    glad_glStencilFunc(func, ref, mask);
}
PFNGLSTENCILFUNCPROC glad_glStencilFunc = glad_on_demand_impl_glStencilFunc;
static void GLAD_API_PTR glad_on_demand_impl_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    glad_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) glad_gl_on_demand_loader("glStencilFuncSeparate");
    glad_glStencilFuncSeparate(face, func, ref, mask);
}
PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate = glad_on_demand_impl_glStencilFuncSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glStencilMask(GLuint mask) {
    glad_glStencilMask = (PFNGLSTENCILMASKPROC) glad_gl_on_demand_loader("glStencilMask");
    glad_glStencilMask(mask);
}
PFNGLSTENCILMASKPROC glad_glStencilMask = glad_on_demand_impl_glStencilMask;
static void GLAD_API_PTR glad_on_demand_impl_glStencilMaskSeparate(GLenum face, GLuint mask) {
    glad_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC) glad_gl_on_demand_loader("glStencilMaskSeparate");
    glad_glStencilMaskSeparate(face, mask);
}
PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate = glad_on_demand_impl_glStencilMaskSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    glad_glStencilOp = (PFNGLSTENCILOPPROC) glad_gl_on_demand_loader("glStencilOp");
    glad_glStencilOp(fail, zfail, zpass);
}
PFNGLSTENCILOPPROC glad_glStencilOp = glad_on_demand_impl_glStencilOp;
static void GLAD_API_PTR glad_on_demand_impl_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    glad_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) glad_gl_on_demand_loader("glStencilOpSeparate");
    glad_glStencilOpSeparate(face, sfail, dpfail, dppass);
}
PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate = glad_on_demand_impl_glStencilOpSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {
    glad_glTexBuffer = (PFNGLTEXBUFFERPROC) glad_gl_on_demand_loader("glTexBuffer");
    glad_glTexBuffer(target, internalformat, buffer);
}
PFNGLTEXBUFFERPROC glad_glTexBuffer = glad_on_demand_impl_glTexBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    glad_glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC) glad_gl_on_demand_loader("glTexBufferRange");
    glad_glTexBufferRange(target, internalformat, buffer, offset, size);
}
PFNGLTEXBUFFERRANGEPROC glad_glTexBufferRange = glad_on_demand_impl_glTexBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) {
    glad_glTexImage1D = (PFNGLTEXIMAGE1DPROC) glad_gl_on_demand_loader("glTexImage1D");
    glad_glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}
PFNGLTEXIMAGE1DPROC glad_glTexImage1D = glad_on_demand_impl_glTexImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
    glad_glTexImage2D = (PFNGLTEXIMAGE2DPROC) glad_gl_on_demand_loader("glTexImage2D");
    glad_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLTEXIMAGE2DPROC glad_glTexImage2D = glad_on_demand_impl_glTexImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    glad_glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC) glad_gl_on_demand_loader("glTexImage2DMultisample");
    glad_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample = glad_on_demand_impl_glTexImage2DMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
    glad_glTexImage3D = (PFNGLTEXIMAGE3DPROC) glad_gl_on_demand_loader("glTexImage3D");
    glad_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
PFNGLTEXIMAGE3DPROC glad_glTexImage3D = glad_on_demand_impl_glTexImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    glad_glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC) glad_gl_on_demand_loader("glTexImage3DMultisample");
    glad_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLTEXIMAGE3DMULTISAMPLEPROC glad_glTexImage3DMultisample = glad_on_demand_impl_glTexImage3DMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameterIiv(GLenum target, GLenum pname, const GLint * params) {
    glad_glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC) glad_gl_on_demand_loader("glTexParameterIiv");
    glad_glTexParameterIiv(target, pname, params);
}
PFNGLTEXPARAMETERIIVPROC glad_glTexParameterIiv = glad_on_demand_impl_glTexParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params) {
    glad_glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC) glad_gl_on_demand_loader("glTexParameterIuiv");
    glad_glTexParameterIuiv(target, pname, params);
}
PFNGLTEXPARAMETERIUIVPROC glad_glTexParameterIuiv = glad_on_demand_impl_glTexParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    glad_glTexParameterf = (PFNGLTEXPARAMETERFPROC) glad_gl_on_demand_loader("glTexParameterf");
    glad_glTexParameterf(target, pname, param);
}
PFNGLTEXPARAMETERFPROC glad_glTexParameterf = glad_on_demand_impl_glTexParameterf;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glad_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC) glad_gl_on_demand_loader("glTexParameterfv");
    glad_glTexParameterfv(target, pname, params);
}
PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv = glad_on_demand_impl_glTexParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    glad_glTexParameteri = (PFNGLTEXPARAMETERIPROC) glad_gl_on_demand_loader("glTexParameteri");
    glad_glTexParameteri(target, pname, param);
}
PFNGLTEXPARAMETERIPROC glad_glTexParameteri = glad_on_demand_impl_glTexParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glad_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC) glad_gl_on_demand_loader("glTexParameteriv");
    glad_glTexParameteriv(target, pname, params);
}
PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv = glad_on_demand_impl_glTexParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
    glad_glTexStorage1D = (PFNGLTEXSTORAGE1DPROC) glad_gl_on_demand_loader("glTexStorage1D");
    glad_glTexStorage1D(target, levels, internalformat, width);
}
PFNGLTEXSTORAGE1DPROC glad_glTexStorage1D = glad_on_demand_impl_glTexStorage1D;
static void GLAD_API_PTR glad_on_demand_impl_glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
    glad_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC) glad_gl_on_demand_loader("glTexStorage2D");
    glad_glTexStorage2D(target, levels, internalformat, width, height);
}
PFNGLTEXSTORAGE2DPROC glad_glTexStorage2D = glad_on_demand_impl_glTexStorage2D;
static void GLAD_API_PTR glad_on_demand_impl_glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    glad_glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC) glad_gl_on_demand_loader("glTexStorage2DMultisample");
    glad_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glad_glTexStorage2DMultisample = glad_on_demand_impl_glTexStorage2DMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
    glad_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC) glad_gl_on_demand_loader("glTexStorage3D");
    glad_glTexStorage3D(target, levels, internalformat, width, height, depth);
}
PFNGLTEXSTORAGE3DPROC glad_glTexStorage3D = glad_on_demand_impl_glTexStorage3D;
static void GLAD_API_PTR glad_on_demand_impl_glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    glad_glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC) glad_gl_on_demand_loader("glTexStorage3DMultisample");
    glad_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glad_glTexStorage3DMultisample = glad_on_demand_impl_glTexStorage3DMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
    glad_glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC) glad_gl_on_demand_loader("glTexSubImage1D");
    glad_glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
}
PFNGLTEXSUBIMAGE1DPROC glad_glTexSubImage1D = glad_on_demand_impl_glTexSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
    glad_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC) glad_gl_on_demand_loader("glTexSubImage2D");
    glad_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D = glad_on_demand_impl_glTexSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
    glad_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC) glad_gl_on_demand_loader("glTexSubImage3D");
    glad_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D = glad_on_demand_impl_glTexSubImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glTextureBarrier(void) {
    glad_glTextureBarrier = (PFNGLTEXTUREBARRIERPROC) glad_gl_on_demand_loader("glTextureBarrier");
    glad_glTextureBarrier();
}
PFNGLTEXTUREBARRIERPROC glad_glTextureBarrier = glad_on_demand_impl_glTextureBarrier;
static void GLAD_API_PTR glad_on_demand_impl_glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) {
    glad_glTextureBuffer = (PFNGLTEXTUREBUFFERPROC) glad_gl_on_demand_loader("glTextureBuffer");
    glad_glTextureBuffer(texture, internalformat, buffer);
}
PFNGLTEXTUREBUFFERPROC glad_glTextureBuffer = glad_on_demand_impl_glTextureBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    glad_glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC) glad_gl_on_demand_loader("glTextureBufferRange");
    glad_glTextureBufferRange(texture, internalformat, buffer, offset, size);
}
PFNGLTEXTUREBUFFERRANGEPROC glad_glTextureBufferRange = glad_on_demand_impl_glTextureBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glTextureParameterIiv(GLuint texture, GLenum pname, const GLint * params) {
    glad_glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC) glad_gl_on_demand_loader("glTextureParameterIiv");
    glad_glTextureParameterIiv(texture, pname, params);
}
PFNGLTEXTUREPARAMETERIIVPROC glad_glTextureParameterIiv = glad_on_demand_impl_glTextureParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint * params) {
    glad_glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC) glad_gl_on_demand_loader("glTextureParameterIuiv");
    glad_glTextureParameterIuiv(texture, pname, params);
}
PFNGLTEXTUREPARAMETERIUIVPROC glad_glTextureParameterIuiv = glad_on_demand_impl_glTextureParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) {
    glad_glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC) glad_gl_on_demand_loader("glTextureParameterf");
    glad_glTextureParameterf(texture, pname, param);
}
PFNGLTEXTUREPARAMETERFPROC glad_glTextureParameterf = glad_on_demand_impl_glTextureParameterf;
static void GLAD_API_PTR glad_on_demand_impl_glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat * param) {
    glad_glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC) glad_gl_on_demand_loader("glTextureParameterfv");
    glad_glTextureParameterfv(texture, pname, param);
}
PFNGLTEXTUREPARAMETERFVPROC glad_glTextureParameterfv = glad_on_demand_impl_glTextureParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glTextureParameteri(GLuint texture, GLenum pname, GLint param) {
    glad_glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC) glad_gl_on_demand_loader("glTextureParameteri");
    glad_glTextureParameteri(texture, pname, param);
}
PFNGLTEXTUREPARAMETERIPROC glad_glTextureParameteri = glad_on_demand_impl_glTextureParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glTextureParameteriv(GLuint texture, GLenum pname, const GLint * param) {
    glad_glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC) glad_gl_on_demand_loader("glTextureParameteriv");
    glad_glTextureParameteriv(texture, pname, param);
}
PFNGLTEXTUREPARAMETERIVPROC glad_glTextureParameteriv = glad_on_demand_impl_glTextureParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) {
    glad_glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC) glad_gl_on_demand_loader("glTextureStorage1D");
    glad_glTextureStorage1D(texture, levels, internalformat, width);
}
PFNGLTEXTURESTORAGE1DPROC glad_glTextureStorage1D = glad_on_demand_impl_glTextureStorage1D;
static void GLAD_API_PTR glad_on_demand_impl_glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
    glad_glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC) glad_gl_on_demand_loader("glTextureStorage2D");
    glad_glTextureStorage2D(texture, levels, internalformat, width, height);
}
PFNGLTEXTURESTORAGE2DPROC glad_glTextureStorage2D = glad_on_demand_impl_glTextureStorage2D;
static void GLAD_API_PTR glad_on_demand_impl_glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    glad_glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) glad_gl_on_demand_loader("glTextureStorage2DMultisample");
    glad_glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glad_glTextureStorage2DMultisample = glad_on_demand_impl_glTextureStorage2DMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
    glad_glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC) glad_gl_on_demand_loader("glTextureStorage3D");
    glad_glTextureStorage3D(texture, levels, internalformat, width, height, depth);
}
PFNGLTEXTURESTORAGE3DPROC glad_glTextureStorage3D = glad_on_demand_impl_glTextureStorage3D;
static void GLAD_API_PTR glad_on_demand_impl_glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    glad_glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) glad_gl_on_demand_loader("glTextureStorage3DMultisample");
    glad_glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glad_glTextureStorage3DMultisample = glad_on_demand_impl_glTextureStorage3DMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
    glad_glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC) glad_gl_on_demand_loader("glTextureSubImage1D");
    glad_glTextureSubImage1D(texture, level, xoffset, width, format, type, pixels);
}
PFNGLTEXTURESUBIMAGE1DPROC glad_glTextureSubImage1D = glad_on_demand_impl_glTextureSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
    glad_glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC) glad_gl_on_demand_loader("glTextureSubImage2D");
    glad_glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXTURESUBIMAGE2DPROC glad_glTextureSubImage2D = glad_on_demand_impl_glTextureSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
    glad_glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC) glad_gl_on_demand_loader("glTextureSubImage3D");
    glad_glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLTEXTURESUBIMAGE3DPROC glad_glTextureSubImage3D = glad_on_demand_impl_glTextureSubImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
    glad_glTextureView = (PFNGLTEXTUREVIEWPROC) glad_gl_on_demand_loader("glTextureView");
    glad_glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}
PFNGLTEXTUREVIEWPROC glad_glTextureView = glad_on_demand_impl_glTextureView;
static void GLAD_API_PTR glad_on_demand_impl_glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) {
    glad_glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) glad_gl_on_demand_loader("glTransformFeedbackBufferBase");
    glad_glTransformFeedbackBufferBase(xfb, index, buffer);
}
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glad_glTransformFeedbackBufferBase = glad_on_demand_impl_glTransformFeedbackBufferBase;
static void GLAD_API_PTR glad_on_demand_impl_glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    glad_glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) glad_gl_on_demand_loader("glTransformFeedbackBufferRange");
    glad_glTransformFeedbackBufferRange(xfb, index, buffer, offset, size);
}
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glad_glTransformFeedbackBufferRange = glad_on_demand_impl_glTransformFeedbackBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode) {
    glad_glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC) glad_gl_on_demand_loader("glTransformFeedbackVaryings");
    glad_glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_glTransformFeedbackVaryings = glad_on_demand_impl_glTransformFeedbackVaryings;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1d(GLint location, GLdouble x) {
    glad_glUniform1d = (PFNGLUNIFORM1DPROC) glad_gl_on_demand_loader("glUniform1d");
    glad_glUniform1d(location, x);
}
PFNGLUNIFORM1DPROC glad_glUniform1d = glad_on_demand_impl_glUniform1d;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1dv(GLint location, GLsizei count, const GLdouble * value) {
    glad_glUniform1dv = (PFNGLUNIFORM1DVPROC) glad_gl_on_demand_loader("glUniform1dv");
    glad_glUniform1dv(location, count, value);
}
PFNGLUNIFORM1DVPROC glad_glUniform1dv = glad_on_demand_impl_glUniform1dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1f(GLint location, GLfloat v0) {
    glad_glUniform1f = (PFNGLUNIFORM1FPROC) glad_gl_on_demand_loader("glUniform1f");
    glad_glUniform1f(location, v0);
}
PFNGLUNIFORM1FPROC glad_glUniform1f = glad_on_demand_impl_glUniform1f;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    glad_glUniform1fv = (PFNGLUNIFORM1FVPROC) glad_gl_on_demand_loader("glUniform1fv");
    glad_glUniform1fv(location, count, value);
}
PFNGLUNIFORM1FVPROC glad_glUniform1fv = glad_on_demand_impl_glUniform1fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1i(GLint location, GLint v0) {
    glad_glUniform1i = (PFNGLUNIFORM1IPROC) glad_gl_on_demand_loader("glUniform1i");
    glad_glUniform1i(location, v0);
}
PFNGLUNIFORM1IPROC glad_glUniform1i = glad_on_demand_impl_glUniform1i;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    glad_glUniform1iv = (PFNGLUNIFORM1IVPROC) glad_gl_on_demand_loader("glUniform1iv");
    glad_glUniform1iv(location, count, value);
}
PFNGLUNIFORM1IVPROC glad_glUniform1iv = glad_on_demand_impl_glUniform1iv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1ui(GLint location, GLuint v0) {
    glad_glUniform1ui = (PFNGLUNIFORM1UIPROC) glad_gl_on_demand_loader("glUniform1ui");
    glad_glUniform1ui(location, v0);
}
PFNGLUNIFORM1UIPROC glad_glUniform1ui = glad_on_demand_impl_glUniform1ui;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1uiv(GLint location, GLsizei count, const GLuint * value) {
    glad_glUniform1uiv = (PFNGLUNIFORM1UIVPROC) glad_gl_on_demand_loader("glUniform1uiv");
    glad_glUniform1uiv(location, count, value);
}
PFNGLUNIFORM1UIVPROC glad_glUniform1uiv = glad_on_demand_impl_glUniform1uiv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2d(GLint location, GLdouble x, GLdouble y) {
    glad_glUniform2d = (PFNGLUNIFORM2DPROC) glad_gl_on_demand_loader("glUniform2d");
    glad_glUniform2d(location, x, y);
}
PFNGLUNIFORM2DPROC glad_glUniform2d = glad_on_demand_impl_glUniform2d;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2dv(GLint location, GLsizei count, const GLdouble * value) {
    glad_glUniform2dv = (PFNGLUNIFORM2DVPROC) glad_gl_on_demand_loader("glUniform2dv");
    glad_glUniform2dv(location, count, value);
}
PFNGLUNIFORM2DVPROC glad_glUniform2dv = glad_on_demand_impl_glUniform2dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    glad_glUniform2f = (PFNGLUNIFORM2FPROC) glad_gl_on_demand_loader("glUniform2f");
    glad_glUniform2f(location, v0, v1);
}
PFNGLUNIFORM2FPROC glad_glUniform2f = glad_on_demand_impl_glUniform2f;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    glad_glUniform2fv = (PFNGLUNIFORM2FVPROC) glad_gl_on_demand_loader("glUniform2fv");
    glad_glUniform2fv(location, count, value);
}
PFNGLUNIFORM2FVPROC glad_glUniform2fv = glad_on_demand_impl_glUniform2fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2i(GLint location, GLint v0, GLint v1) {
    glad_glUniform2i = (PFNGLUNIFORM2IPROC) glad_gl_on_demand_loader("glUniform2i");
    glad_glUniform2i(location, v0, v1);
}
PFNGLUNIFORM2IPROC glad_glUniform2i = glad_on_demand_impl_glUniform2i;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    glad_glUniform2iv = (PFNGLUNIFORM2IVPROC) glad_gl_on_demand_loader("glUniform2iv");
    glad_glUniform2iv(location, count, value);
}
PFNGLUNIFORM2IVPROC glad_glUniform2iv = glad_on_demand_impl_glUniform2iv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2ui(GLint location, GLuint v0, GLuint v1) {
    glad_glUniform2ui = (PFNGLUNIFORM2UIPROC) glad_gl_on_demand_loader("glUniform2ui");
    glad_glUniform2ui(location, v0, v1);
}
PFNGLUNIFORM2UIPROC glad_glUniform2ui = glad_on_demand_impl_glUniform2ui;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2uiv(GLint location, GLsizei count, const GLuint * value) {
    glad_glUniform2uiv = (PFNGLUNIFORM2UIVPROC) glad_gl_on_demand_loader("glUniform2uiv");
    glad_glUniform2uiv(location, count, value);
}
PFNGLUNIFORM2UIVPROC glad_glUniform2uiv = glad_on_demand_impl_glUniform2uiv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) {
    glad_glUniform3d = (PFNGLUNIFORM3DPROC) glad_gl_on_demand_loader("glUniform3d");
    glad_glUniform3d(location, x, y, z);
}
PFNGLUNIFORM3DPROC glad_glUniform3d = glad_on_demand_impl_glUniform3d;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3dv(GLint location, GLsizei count, const GLdouble * value) {
    glad_glUniform3dv = (PFNGLUNIFORM3DVPROC) glad_gl_on_demand_loader("glUniform3dv");
    glad_glUniform3dv(location, count, value);
}
PFNGLUNIFORM3DVPROC glad_glUniform3dv = glad_on_demand_impl_glUniform3dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    glad_glUniform3f = (PFNGLUNIFORM3FPROC) glad_gl_on_demand_loader("glUniform3f");
    glad_glUniform3f(location, v0, v1, v2);
}
PFNGLUNIFORM3FPROC glad_glUniform3f = glad_on_demand_impl_glUniform3f;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    glad_glUniform3fv = (PFNGLUNIFORM3FVPROC) glad_gl_on_demand_loader("glUniform3fv");
    glad_glUniform3fv(location, count, value);
}
PFNGLUNIFORM3FVPROC glad_glUniform3fv = glad_on_demand_impl_glUniform3fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    glad_glUniform3i = (PFNGLUNIFORM3IPROC) glad_gl_on_demand_loader("glUniform3i");
    glad_glUniform3i(location, v0, v1, v2);
}
PFNGLUNIFORM3IPROC glad_glUniform3i = glad_on_demand_impl_glUniform3i;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    glad_glUniform3iv = (PFNGLUNIFORM3IVPROC) glad_gl_on_demand_loader("glUniform3iv");
    glad_glUniform3iv(location, count, value);
}
PFNGLUNIFORM3IVPROC glad_glUniform3iv = glad_on_demand_impl_glUniform3iv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
    glad_glUniform3ui = (PFNGLUNIFORM3UIPROC) glad_gl_on_demand_loader("glUniform3ui");
    glad_glUniform3ui(location, v0, v1, v2);
}
PFNGLUNIFORM3UIPROC glad_glUniform3ui = glad_on_demand_impl_glUniform3ui;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3uiv(GLint location, GLsizei count, const GLuint * value) {
    glad_glUniform3uiv = (PFNGLUNIFORM3UIVPROC) glad_gl_on_demand_loader("glUniform3uiv");
    glad_glUniform3uiv(location, count, value);
}
PFNGLUNIFORM3UIVPROC glad_glUniform3uiv = glad_on_demand_impl_glUniform3uiv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glad_glUniform4d = (PFNGLUNIFORM4DPROC) glad_gl_on_demand_loader("glUniform4d");
    glad_glUniform4d(location, x, y, z, w);
}
PFNGLUNIFORM4DPROC glad_glUniform4d = glad_on_demand_impl_glUniform4d;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4dv(GLint location, GLsizei count, const GLdouble * value) {
    glad_glUniform4dv = (PFNGLUNIFORM4DVPROC) glad_gl_on_demand_loader("glUniform4dv");
    glad_glUniform4dv(location, count, value);
}
PFNGLUNIFORM4DVPROC glad_glUniform4dv = glad_on_demand_impl_glUniform4dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    glad_glUniform4f = (PFNGLUNIFORM4FPROC) glad_gl_on_demand_loader("glUniform4f");
    glad_glUniform4f(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4FPROC glad_glUniform4f = glad_on_demand_impl_glUniform4f;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    glad_glUniform4fv = (PFNGLUNIFORM4FVPROC) glad_gl_on_demand_loader("glUniform4fv");
    glad_glUniform4fv(location, count, value);
}
PFNGLUNIFORM4FVPROC glad_glUniform4fv = glad_on_demand_impl_glUniform4fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    glad_glUniform4i = (PFNGLUNIFORM4IPROC) glad_gl_on_demand_loader("glUniform4i");
    glad_glUniform4i(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4IPROC glad_glUniform4i = glad_on_demand_impl_glUniform4i;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    glad_glUniform4iv = (PFNGLUNIFORM4IVPROC) glad_gl_on_demand_loader("glUniform4iv");
    glad_glUniform4iv(location, count, value);
}
PFNGLUNIFORM4IVPROC glad_glUniform4iv = glad_on_demand_impl_glUniform4iv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    glad_glUniform4ui = (PFNGLUNIFORM4UIPROC) glad_gl_on_demand_loader("glUniform4ui");
    glad_glUniform4ui(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4UIPROC glad_glUniform4ui = glad_on_demand_impl_glUniform4ui;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4uiv(GLint location, GLsizei count, const GLuint * value) {
    glad_glUniform4uiv = (PFNGLUNIFORM4UIVPROC) glad_gl_on_demand_loader("glUniform4uiv");
    glad_glUniform4uiv(location, count, value);
}
PFNGLUNIFORM4UIVPROC glad_glUniform4uiv = glad_on_demand_impl_glUniform4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
    glad_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC) glad_gl_on_demand_loader("glUniformBlockBinding");
    glad_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}
PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding = glad_on_demand_impl_glUniformBlockBinding;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC) glad_gl_on_demand_loader("glUniformMatrix2dv");
    glad_glUniformMatrix2dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2DVPROC glad_glUniformMatrix2dv = glad_on_demand_impl_glUniformMatrix2dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) glad_gl_on_demand_loader("glUniformMatrix2fv");
    glad_glUniformMatrix2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv = glad_on_demand_impl_glUniformMatrix2fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC) glad_gl_on_demand_loader("glUniformMatrix2x3dv");
    glad_glUniformMatrix2x3dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X3DVPROC glad_glUniformMatrix2x3dv = glad_on_demand_impl_glUniformMatrix2x3dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) glad_gl_on_demand_loader("glUniformMatrix2x3fv");
    glad_glUniformMatrix2x3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv = glad_on_demand_impl_glUniformMatrix2x3fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC) glad_gl_on_demand_loader("glUniformMatrix2x4dv");
    glad_glUniformMatrix2x4dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X4DVPROC glad_glUniformMatrix2x4dv = glad_on_demand_impl_glUniformMatrix2x4dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) glad_gl_on_demand_loader("glUniformMatrix2x4fv");
    glad_glUniformMatrix2x4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv = glad_on_demand_impl_glUniformMatrix2x4fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC) glad_gl_on_demand_loader("glUniformMatrix3dv");
    glad_glUniformMatrix3dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3DVPROC glad_glUniformMatrix3dv = glad_on_demand_impl_glUniformMatrix3dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) glad_gl_on_demand_loader("glUniformMatrix3fv");
    glad_glUniformMatrix3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv = glad_on_demand_impl_glUniformMatrix3fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC) glad_gl_on_demand_loader("glUniformMatrix3x2dv");
    glad_glUniformMatrix3x2dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X2DVPROC glad_glUniformMatrix3x2dv = glad_on_demand_impl_glUniformMatrix3x2dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) glad_gl_on_demand_loader("glUniformMatrix3x2fv");
    glad_glUniformMatrix3x2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv = glad_on_demand_impl_glUniformMatrix3x2fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC) glad_gl_on_demand_loader("glUniformMatrix3x4dv");
    glad_glUniformMatrix3x4dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X4DVPROC glad_glUniformMatrix3x4dv = glad_on_demand_impl_glUniformMatrix3x4dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) glad_gl_on_demand_loader("glUniformMatrix3x4fv");
    glad_glUniformMatrix3x4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv = glad_on_demand_impl_glUniformMatrix3x4fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC) glad_gl_on_demand_loader("glUniformMatrix4dv");
    glad_glUniformMatrix4dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4DVPROC glad_glUniformMatrix4dv = glad_on_demand_impl_glUniformMatrix4dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) glad_gl_on_demand_loader("glUniformMatrix4fv");
    glad_glUniformMatrix4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv = glad_on_demand_impl_glUniformMatrix4fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC) glad_gl_on_demand_loader("glUniformMatrix4x2dv");
    glad_glUniformMatrix4x2dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X2DVPROC glad_glUniformMatrix4x2dv = glad_on_demand_impl_glUniformMatrix4x2dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) glad_gl_on_demand_loader("glUniformMatrix4x2fv");
    glad_glUniformMatrix4x2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv = glad_on_demand_impl_glUniformMatrix4x2fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    glad_glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC) glad_gl_on_demand_loader("glUniformMatrix4x3dv");
    glad_glUniformMatrix4x3dv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X3DVPROC glad_glUniformMatrix4x3dv = glad_on_demand_impl_glUniformMatrix4x3dv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) glad_gl_on_demand_loader("glUniformMatrix4x3fv");
    glad_glUniformMatrix4x3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv = glad_on_demand_impl_glUniformMatrix4x3fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint * indices) {
    glad_glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC) glad_gl_on_demand_loader("glUniformSubroutinesuiv");
    glad_glUniformSubroutinesuiv(shadertype, count, indices);
}
PFNGLUNIFORMSUBROUTINESUIVPROC glad_glUniformSubroutinesuiv = glad_on_demand_impl_glUniformSubroutinesuiv;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glUnmapBuffer(GLenum target) {
    glad_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC) glad_gl_on_demand_loader("glUnmapBuffer");
    return glad_glUnmapBuffer(target);
}
PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer = glad_on_demand_impl_glUnmapBuffer;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glUnmapNamedBuffer(GLuint buffer) {
    glad_glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC) glad_gl_on_demand_loader("glUnmapNamedBuffer");
    return glad_glUnmapNamedBuffer(buffer);
}
PFNGLUNMAPNAMEDBUFFERPROC glad_glUnmapNamedBuffer = glad_on_demand_impl_glUnmapNamedBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glUseProgram(GLuint program) {
    glad_glUseProgram = (PFNGLUSEPROGRAMPROC) glad_gl_on_demand_loader("glUseProgram");
    glad_glUseProgram(program);
}
PFNGLUSEPROGRAMPROC glad_glUseProgram = glad_on_demand_impl_glUseProgram;
static void GLAD_API_PTR glad_on_demand_impl_glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) {
    glad_glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC) glad_gl_on_demand_loader("glUseProgramStages");
    glad_glUseProgramStages(pipeline, stages, program);
}
PFNGLUSEPROGRAMSTAGESPROC glad_glUseProgramStages = glad_on_demand_impl_glUseProgramStages;
static void GLAD_API_PTR glad_on_demand_impl_glValidateProgram(GLuint program) {
    glad_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC) glad_gl_on_demand_loader("glValidateProgram");
    glad_glValidateProgram(program);
}
PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram = glad_on_demand_impl_glValidateProgram;
static void GLAD_API_PTR glad_on_demand_impl_glValidateProgramPipeline(GLuint pipeline) {
    glad_glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC) glad_gl_on_demand_loader("glValidateProgramPipeline");
    glad_glValidateProgramPipeline(pipeline);
}
PFNGLVALIDATEPROGRAMPIPELINEPROC glad_glValidateProgramPipeline = glad_on_demand_impl_glValidateProgramPipeline;
static void GLAD_API_PTR glad_on_demand_impl_glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
    glad_glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC) glad_gl_on_demand_loader("glVertexArrayAttribBinding");
    glad_glVertexArrayAttribBinding(vaobj, attribindex, bindingindex);
}
PFNGLVERTEXARRAYATTRIBBINDINGPROC glad_glVertexArrayAttribBinding = glad_on_demand_impl_glVertexArrayAttribBinding;
static void GLAD_API_PTR glad_on_demand_impl_glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
    glad_glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC) glad_gl_on_demand_loader("glVertexArrayAttribFormat");
    glad_glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset);
}
PFNGLVERTEXARRAYATTRIBFORMATPROC glad_glVertexArrayAttribFormat = glad_on_demand_impl_glVertexArrayAttribFormat;
static void GLAD_API_PTR glad_on_demand_impl_glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    glad_glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC) glad_gl_on_demand_loader("glVertexArrayAttribIFormat");
    glad_glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset);
}
PFNGLVERTEXARRAYATTRIBIFORMATPROC glad_glVertexArrayAttribIFormat = glad_on_demand_impl_glVertexArrayAttribIFormat;
static void GLAD_API_PTR glad_on_demand_impl_glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    glad_glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC) glad_gl_on_demand_loader("glVertexArrayAttribLFormat");
    glad_glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset);
}
PFNGLVERTEXARRAYATTRIBLFORMATPROC glad_glVertexArrayAttribLFormat = glad_on_demand_impl_glVertexArrayAttribLFormat;
static void GLAD_API_PTR glad_on_demand_impl_glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) {
    glad_glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC) glad_gl_on_demand_loader("glVertexArrayBindingDivisor");
    glad_glVertexArrayBindingDivisor(vaobj, bindingindex, divisor);
}
PFNGLVERTEXARRAYBINDINGDIVISORPROC glad_glVertexArrayBindingDivisor = glad_on_demand_impl_glVertexArrayBindingDivisor;
static void GLAD_API_PTR glad_on_demand_impl_glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) {
    glad_glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC) glad_gl_on_demand_loader("glVertexArrayElementBuffer");
    glad_glVertexArrayElementBuffer(vaobj, buffer);
}
PFNGLVERTEXARRAYELEMENTBUFFERPROC glad_glVertexArrayElementBuffer = glad_on_demand_impl_glVertexArrayElementBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
    glad_glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC) glad_gl_on_demand_loader("glVertexArrayVertexBuffer");
    glad_glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride);
}
PFNGLVERTEXARRAYVERTEXBUFFERPROC glad_glVertexArrayVertexBuffer = glad_on_demand_impl_glVertexArrayVertexBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides) {
    glad_glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC) glad_gl_on_demand_loader("glVertexArrayVertexBuffers");
    glad_glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides);
}
PFNGLVERTEXARRAYVERTEXBUFFERSPROC glad_glVertexArrayVertexBuffers = glad_on_demand_impl_glVertexArrayVertexBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1d(GLuint index, GLdouble x) {
    glad_glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC) glad_gl_on_demand_loader("glVertexAttrib1d");
    glad_glVertexAttrib1d(index, x);
}
PFNGLVERTEXATTRIB1DPROC glad_glVertexAttrib1d = glad_on_demand_impl_glVertexAttrib1d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC) glad_gl_on_demand_loader("glVertexAttrib1dv");
    glad_glVertexAttrib1dv(index, v);
}
PFNGLVERTEXATTRIB1DVPROC glad_glVertexAttrib1dv = glad_on_demand_impl_glVertexAttrib1dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1f(GLuint index, GLfloat x) {
    glad_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC) glad_gl_on_demand_loader("glVertexAttrib1f");
    glad_glVertexAttrib1f(index, x);
}
PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f = glad_on_demand_impl_glVertexAttrib1f;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    glad_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC) glad_gl_on_demand_loader("glVertexAttrib1fv");
    glad_glVertexAttrib1fv(index, v);
}
PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv = glad_on_demand_impl_glVertexAttrib1fv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1s(GLuint index, GLshort x) {
    glad_glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC) glad_gl_on_demand_loader("glVertexAttrib1s");
    glad_glVertexAttrib1s(index, x);
}
PFNGLVERTEXATTRIB1SPROC glad_glVertexAttrib1s = glad_on_demand_impl_glVertexAttrib1s;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1sv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC) glad_gl_on_demand_loader("glVertexAttrib1sv");
    glad_glVertexAttrib1sv(index, v);
}
PFNGLVERTEXATTRIB1SVPROC glad_glVertexAttrib1sv = glad_on_demand_impl_glVertexAttrib1sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
    glad_glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC) glad_gl_on_demand_loader("glVertexAttrib2d");
    glad_glVertexAttrib2d(index, x, y);
}
PFNGLVERTEXATTRIB2DPROC glad_glVertexAttrib2d = glad_on_demand_impl_glVertexAttrib2d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC) glad_gl_on_demand_loader("glVertexAttrib2dv");
    glad_glVertexAttrib2dv(index, v);
}
PFNGLVERTEXATTRIB2DVPROC glad_glVertexAttrib2dv = glad_on_demand_impl_glVertexAttrib2dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    glad_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC) glad_gl_on_demand_loader("glVertexAttrib2f");
    glad_glVertexAttrib2f(index, x, y);
}
PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f = glad_on_demand_impl_glVertexAttrib2f;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    glad_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC) glad_gl_on_demand_loader("glVertexAttrib2fv");
    glad_glVertexAttrib2fv(index, v);
}
PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv = glad_on_demand_impl_glVertexAttrib2fv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
    glad_glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC) glad_gl_on_demand_loader("glVertexAttrib2s");
    glad_glVertexAttrib2s(index, x, y);
}
PFNGLVERTEXATTRIB2SPROC glad_glVertexAttrib2s = glad_on_demand_impl_glVertexAttrib2s;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2sv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC) glad_gl_on_demand_loader("glVertexAttrib2sv");
    glad_glVertexAttrib2sv(index, v);
}
PFNGLVERTEXATTRIB2SVPROC glad_glVertexAttrib2sv = glad_on_demand_impl_glVertexAttrib2sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    glad_glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC) glad_gl_on_demand_loader("glVertexAttrib3d");
    glad_glVertexAttrib3d(index, x, y, z);
}
PFNGLVERTEXATTRIB3DPROC glad_glVertexAttrib3d = glad_on_demand_impl_glVertexAttrib3d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC) glad_gl_on_demand_loader("glVertexAttrib3dv");
    glad_glVertexAttrib3dv(index, v);
}
PFNGLVERTEXATTRIB3DVPROC glad_glVertexAttrib3dv = glad_on_demand_impl_glVertexAttrib3dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    glad_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC) glad_gl_on_demand_loader("glVertexAttrib3f");
    glad_glVertexAttrib3f(index, x, y, z);
}
PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f = glad_on_demand_impl_glVertexAttrib3f;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    glad_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC) glad_gl_on_demand_loader("glVertexAttrib3fv");
    glad_glVertexAttrib3fv(index, v);
}
PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv = glad_on_demand_impl_glVertexAttrib3fv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
    glad_glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC) glad_gl_on_demand_loader("glVertexAttrib3s");
    glad_glVertexAttrib3s(index, x, y, z);
}
PFNGLVERTEXATTRIB3SPROC glad_glVertexAttrib3s = glad_on_demand_impl_glVertexAttrib3s;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3sv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC) glad_gl_on_demand_loader("glVertexAttrib3sv");
    glad_glVertexAttrib3sv(index, v);
}
PFNGLVERTEXATTRIB3SVPROC glad_glVertexAttrib3sv = glad_on_demand_impl_glVertexAttrib3sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nbv(GLuint index, const GLbyte * v) {
    glad_glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nbv");
    glad_glVertexAttrib4Nbv(index, v);
}
PFNGLVERTEXATTRIB4NBVPROC glad_glVertexAttrib4Nbv = glad_on_demand_impl_glVertexAttrib4Nbv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Niv(GLuint index, const GLint * v) {
    glad_glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC) glad_gl_on_demand_loader("glVertexAttrib4Niv");
    glad_glVertexAttrib4Niv(index, v);
}
PFNGLVERTEXATTRIB4NIVPROC glad_glVertexAttrib4Niv = glad_on_demand_impl_glVertexAttrib4Niv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nsv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nsv");
    glad_glVertexAttrib4Nsv(index, v);
}
PFNGLVERTEXATTRIB4NSVPROC glad_glVertexAttrib4Nsv = glad_on_demand_impl_glVertexAttrib4Nsv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    glad_glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC) glad_gl_on_demand_loader("glVertexAttrib4Nub");
    glad_glVertexAttrib4Nub(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4NUBPROC glad_glVertexAttrib4Nub = glad_on_demand_impl_glVertexAttrib4Nub;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nubv(GLuint index, const GLubyte * v) {
    glad_glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nubv");
    glad_glVertexAttrib4Nubv(index, v);
}
PFNGLVERTEXATTRIB4NUBVPROC glad_glVertexAttrib4Nubv = glad_on_demand_impl_glVertexAttrib4Nubv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nuiv(GLuint index, const GLuint * v) {
    glad_glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nuiv");
    glad_glVertexAttrib4Nuiv(index, v);
}
PFNGLVERTEXATTRIB4NUIVPROC glad_glVertexAttrib4Nuiv = glad_on_demand_impl_glVertexAttrib4Nuiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nusv(GLuint index, const GLushort * v) {
    glad_glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nusv");
    glad_glVertexAttrib4Nusv(index, v);
}
PFNGLVERTEXATTRIB4NUSVPROC glad_glVertexAttrib4Nusv = glad_on_demand_impl_glVertexAttrib4Nusv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4bv(GLuint index, const GLbyte * v) {
    glad_glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC) glad_gl_on_demand_loader("glVertexAttrib4bv");
    glad_glVertexAttrib4bv(index, v);
}
PFNGLVERTEXATTRIB4BVPROC glad_glVertexAttrib4bv = glad_on_demand_impl_glVertexAttrib4bv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glad_glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC) glad_gl_on_demand_loader("glVertexAttrib4d");
    glad_glVertexAttrib4d(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4DPROC glad_glVertexAttrib4d = glad_on_demand_impl_glVertexAttrib4d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC) glad_gl_on_demand_loader("glVertexAttrib4dv");
    glad_glVertexAttrib4dv(index, v);
}
PFNGLVERTEXATTRIB4DVPROC glad_glVertexAttrib4dv = glad_on_demand_impl_glVertexAttrib4dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glad_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC) glad_gl_on_demand_loader("glVertexAttrib4f");
    glad_glVertexAttrib4f(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f = glad_on_demand_impl_glVertexAttrib4f;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    glad_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC) glad_gl_on_demand_loader("glVertexAttrib4fv");
    glad_glVertexAttrib4fv(index, v);
}
PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv = glad_on_demand_impl_glVertexAttrib4fv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4iv(GLuint index, const GLint * v) {
    glad_glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC) glad_gl_on_demand_loader("glVertexAttrib4iv");
    glad_glVertexAttrib4iv(index, v);
}
PFNGLVERTEXATTRIB4IVPROC glad_glVertexAttrib4iv = glad_on_demand_impl_glVertexAttrib4iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    glad_glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC) glad_gl_on_demand_loader("glVertexAttrib4s");
    glad_glVertexAttrib4s(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4SPROC glad_glVertexAttrib4s = glad_on_demand_impl_glVertexAttrib4s;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4sv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC) glad_gl_on_demand_loader("glVertexAttrib4sv");
    glad_glVertexAttrib4sv(index, v);
}
PFNGLVERTEXATTRIB4SVPROC glad_glVertexAttrib4sv = glad_on_demand_impl_glVertexAttrib4sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4ubv(GLuint index, const GLubyte * v) {
    glad_glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC) glad_gl_on_demand_loader("glVertexAttrib4ubv");
    glad_glVertexAttrib4ubv(index, v);
}
PFNGLVERTEXATTRIB4UBVPROC glad_glVertexAttrib4ubv = glad_on_demand_impl_glVertexAttrib4ubv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC) glad_gl_on_demand_loader("glVertexAttrib4uiv");
    glad_glVertexAttrib4uiv(index, v);
}
PFNGLVERTEXATTRIB4UIVPROC glad_glVertexAttrib4uiv = glad_on_demand_impl_glVertexAttrib4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4usv(GLuint index, const GLushort * v) {
    glad_glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC) glad_gl_on_demand_loader("glVertexAttrib4usv");
    glad_glVertexAttrib4usv(index, v);
}
PFNGLVERTEXATTRIB4USVPROC glad_glVertexAttrib4usv = glad_on_demand_impl_glVertexAttrib4usv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) {
    glad_glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC) glad_gl_on_demand_loader("glVertexAttribBinding");
    glad_glVertexAttribBinding(attribindex, bindingindex);
}
PFNGLVERTEXATTRIBBINDINGPROC glad_glVertexAttribBinding = glad_on_demand_impl_glVertexAttribBinding;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribDivisor(GLuint index, GLuint divisor) {
    glad_glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC) glad_gl_on_demand_loader("glVertexAttribDivisor");
    glad_glVertexAttribDivisor(index, divisor);
}
PFNGLVERTEXATTRIBDIVISORPROC glad_glVertexAttribDivisor = glad_on_demand_impl_glVertexAttribDivisor;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
    glad_glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC) glad_gl_on_demand_loader("glVertexAttribFormat");
    glad_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
}
PFNGLVERTEXATTRIBFORMATPROC glad_glVertexAttribFormat = glad_on_demand_impl_glVertexAttribFormat;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI1i(GLuint index, GLint x) {
    glad_glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC) glad_gl_on_demand_loader("glVertexAttribI1i");
    glad_glVertexAttribI1i(index, x);
}
PFNGLVERTEXATTRIBI1IPROC glad_glVertexAttribI1i = glad_on_demand_impl_glVertexAttribI1i;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI1iv(GLuint index, const GLint * v) {
    glad_glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC) glad_gl_on_demand_loader("glVertexAttribI1iv");
    glad_glVertexAttribI1iv(index, v);
}
PFNGLVERTEXATTRIBI1IVPROC glad_glVertexAttribI1iv = glad_on_demand_impl_glVertexAttribI1iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI1ui(GLuint index, GLuint x) {
    glad_glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC) glad_gl_on_demand_loader("glVertexAttribI1ui");
    glad_glVertexAttribI1ui(index, x);
}
PFNGLVERTEXATTRIBI1UIPROC glad_glVertexAttribI1ui = glad_on_demand_impl_glVertexAttribI1ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI1uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC) glad_gl_on_demand_loader("glVertexAttribI1uiv");
    glad_glVertexAttribI1uiv(index, v);
}
PFNGLVERTEXATTRIBI1UIVPROC glad_glVertexAttribI1uiv = glad_on_demand_impl_glVertexAttribI1uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI2i(GLuint index, GLint x, GLint y) {
    glad_glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC) glad_gl_on_demand_loader("glVertexAttribI2i");
    glad_glVertexAttribI2i(index, x, y);
}
PFNGLVERTEXATTRIBI2IPROC glad_glVertexAttribI2i = glad_on_demand_impl_glVertexAttribI2i;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI2iv(GLuint index, const GLint * v) {
    glad_glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC) glad_gl_on_demand_loader("glVertexAttribI2iv");
    glad_glVertexAttribI2iv(index, v);
}
PFNGLVERTEXATTRIBI2IVPROC glad_glVertexAttribI2iv = glad_on_demand_impl_glVertexAttribI2iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
    glad_glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC) glad_gl_on_demand_loader("glVertexAttribI2ui");
    glad_glVertexAttribI2ui(index, x, y);
}
PFNGLVERTEXATTRIBI2UIPROC glad_glVertexAttribI2ui = glad_on_demand_impl_glVertexAttribI2ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI2uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC) glad_gl_on_demand_loader("glVertexAttribI2uiv");
    glad_glVertexAttribI2uiv(index, v);
}
PFNGLVERTEXATTRIBI2UIVPROC glad_glVertexAttribI2uiv = glad_on_demand_impl_glVertexAttribI2uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
    glad_glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC) glad_gl_on_demand_loader("glVertexAttribI3i");
    glad_glVertexAttribI3i(index, x, y, z);
}
PFNGLVERTEXATTRIBI3IPROC glad_glVertexAttribI3i = glad_on_demand_impl_glVertexAttribI3i;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI3iv(GLuint index, const GLint * v) {
    glad_glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC) glad_gl_on_demand_loader("glVertexAttribI3iv");
    glad_glVertexAttribI3iv(index, v);
}
PFNGLVERTEXATTRIBI3IVPROC glad_glVertexAttribI3iv = glad_on_demand_impl_glVertexAttribI3iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
    glad_glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC) glad_gl_on_demand_loader("glVertexAttribI3ui");
    glad_glVertexAttribI3ui(index, x, y, z);
}
PFNGLVERTEXATTRIBI3UIPROC glad_glVertexAttribI3ui = glad_on_demand_impl_glVertexAttribI3ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI3uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC) glad_gl_on_demand_loader("glVertexAttribI3uiv");
    glad_glVertexAttribI3uiv(index, v);
}
PFNGLVERTEXATTRIBI3UIVPROC glad_glVertexAttribI3uiv = glad_on_demand_impl_glVertexAttribI3uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4bv(GLuint index, const GLbyte * v) {
    glad_glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC) glad_gl_on_demand_loader("glVertexAttribI4bv");
    glad_glVertexAttribI4bv(index, v);
}
PFNGLVERTEXATTRIBI4BVPROC glad_glVertexAttribI4bv = glad_on_demand_impl_glVertexAttribI4bv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
    glad_glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC) glad_gl_on_demand_loader("glVertexAttribI4i");
    glad_glVertexAttribI4i(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI4IPROC glad_glVertexAttribI4i = glad_on_demand_impl_glVertexAttribI4i;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4iv(GLuint index, const GLint * v) {
    glad_glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC) glad_gl_on_demand_loader("glVertexAttribI4iv");
    glad_glVertexAttribI4iv(index, v);
}
PFNGLVERTEXATTRIBI4IVPROC glad_glVertexAttribI4iv = glad_on_demand_impl_glVertexAttribI4iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4sv(GLuint index, const GLshort * v) {
    glad_glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC) glad_gl_on_demand_loader("glVertexAttribI4sv");
    glad_glVertexAttribI4sv(index, v);
}
PFNGLVERTEXATTRIBI4SVPROC glad_glVertexAttribI4sv = glad_on_demand_impl_glVertexAttribI4sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4ubv(GLuint index, const GLubyte * v) {
    glad_glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC) glad_gl_on_demand_loader("glVertexAttribI4ubv");
    glad_glVertexAttribI4ubv(index, v);
}
PFNGLVERTEXATTRIBI4UBVPROC glad_glVertexAttribI4ubv = glad_on_demand_impl_glVertexAttribI4ubv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    glad_glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC) glad_gl_on_demand_loader("glVertexAttribI4ui");
    glad_glVertexAttribI4ui(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI4UIPROC glad_glVertexAttribI4ui = glad_on_demand_impl_glVertexAttribI4ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC) glad_gl_on_demand_loader("glVertexAttribI4uiv");
    glad_glVertexAttribI4uiv(index, v);
}
PFNGLVERTEXATTRIBI4UIVPROC glad_glVertexAttribI4uiv = glad_on_demand_impl_glVertexAttribI4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4usv(GLuint index, const GLushort * v) {
    glad_glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC) glad_gl_on_demand_loader("glVertexAttribI4usv");
    glad_glVertexAttribI4usv(index, v);
}
PFNGLVERTEXATTRIBI4USVPROC glad_glVertexAttribI4usv = glad_on_demand_impl_glVertexAttribI4usv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    glad_glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC) glad_gl_on_demand_loader("glVertexAttribIFormat");
    glad_glVertexAttribIFormat(attribindex, size, type, relativeoffset);
}
PFNGLVERTEXATTRIBIFORMATPROC glad_glVertexAttribIFormat = glad_on_demand_impl_glVertexAttribIFormat;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
    glad_glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC) glad_gl_on_demand_loader("glVertexAttribIPointer");
    glad_glVertexAttribIPointer(index, size, type, stride, pointer);
}
PFNGLVERTEXATTRIBIPOINTERPROC glad_glVertexAttribIPointer = glad_on_demand_impl_glVertexAttribIPointer;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribL1d(GLuint index, GLdouble x) {
    glad_glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC) glad_gl_on_demand_loader("glVertexAttribL1d");
    glad_glVertexAttribL1d(index, x);
}
PFNGLVERTEXATTRIBL1DPROC glad_glVertexAttribL1d = glad_on_demand_impl_glVertexAttribL1d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribL1dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC) glad_gl_on_demand_loader("glVertexAttribL1dv");
    glad_glVertexAttribL1dv(index, v);
}
PFNGLVERTEXATTRIBL1DVPROC glad_glVertexAttribL1dv = glad_on_demand_impl_glVertexAttribL1dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) {
    glad_glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC) glad_gl_on_demand_loader("glVertexAttribL2d");
    glad_glVertexAttribL2d(index, x, y);
}
PFNGLVERTEXATTRIBL2DPROC glad_glVertexAttribL2d = glad_on_demand_impl_glVertexAttribL2d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribL2dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC) glad_gl_on_demand_loader("glVertexAttribL2dv");
    glad_glVertexAttribL2dv(index, v);
}
PFNGLVERTEXATTRIBL2DVPROC glad_glVertexAttribL2dv = glad_on_demand_impl_glVertexAttribL2dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    glad_glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC) glad_gl_on_demand_loader("glVertexAttribL3d");
    glad_glVertexAttribL3d(index, x, y, z);
}
PFNGLVERTEXATTRIBL3DPROC glad_glVertexAttribL3d = glad_on_demand_impl_glVertexAttribL3d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribL3dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC) glad_gl_on_demand_loader("glVertexAttribL3dv");
    glad_glVertexAttribL3dv(index, v);
}
PFNGLVERTEXATTRIBL3DVPROC glad_glVertexAttribL3dv = glad_on_demand_impl_glVertexAttribL3dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glad_glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC) glad_gl_on_demand_loader("glVertexAttribL4d");
    glad_glVertexAttribL4d(index, x, y, z, w);
}
PFNGLVERTEXATTRIBL4DPROC glad_glVertexAttribL4d = glad_on_demand_impl_glVertexAttribL4d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribL4dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC) glad_gl_on_demand_loader("glVertexAttribL4dv");
    glad_glVertexAttribL4dv(index, v);
}
PFNGLVERTEXATTRIBL4DVPROC glad_glVertexAttribL4dv = glad_on_demand_impl_glVertexAttribL4dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    glad_glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC) glad_gl_on_demand_loader("glVertexAttribLFormat");
    glad_glVertexAttribLFormat(attribindex, size, type, relativeoffset);
}
PFNGLVERTEXATTRIBLFORMATPROC glad_glVertexAttribLFormat = glad_on_demand_impl_glVertexAttribLFormat;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
    glad_glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC) glad_gl_on_demand_loader("glVertexAttribLPointer");
    glad_glVertexAttribLPointer(index, size, type, stride, pointer);
}
PFNGLVERTEXATTRIBLPOINTERPROC glad_glVertexAttribLPointer = glad_on_demand_impl_glVertexAttribLPointer;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    glad_glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC) glad_gl_on_demand_loader("glVertexAttribP1ui");
    glad_glVertexAttribP1ui(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP1UIPROC glad_glVertexAttribP1ui = glad_on_demand_impl_glVertexAttribP1ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    glad_glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC) glad_gl_on_demand_loader("glVertexAttribP1uiv");
    glad_glVertexAttribP1uiv(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP1UIVPROC glad_glVertexAttribP1uiv = glad_on_demand_impl_glVertexAttribP1uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    glad_glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC) glad_gl_on_demand_loader("glVertexAttribP2ui");
    glad_glVertexAttribP2ui(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP2UIPROC glad_glVertexAttribP2ui = glad_on_demand_impl_glVertexAttribP2ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    glad_glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC) glad_gl_on_demand_loader("glVertexAttribP2uiv");
    glad_glVertexAttribP2uiv(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP2UIVPROC glad_glVertexAttribP2uiv = glad_on_demand_impl_glVertexAttribP2uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    glad_glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC) glad_gl_on_demand_loader("glVertexAttribP3ui");
    glad_glVertexAttribP3ui(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP3UIPROC glad_glVertexAttribP3ui = glad_on_demand_impl_glVertexAttribP3ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    glad_glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC) glad_gl_on_demand_loader("glVertexAttribP3uiv");
    glad_glVertexAttribP3uiv(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP3UIVPROC glad_glVertexAttribP3uiv = glad_on_demand_impl_glVertexAttribP3uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    glad_glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC) glad_gl_on_demand_loader("glVertexAttribP4ui");
    glad_glVertexAttribP4ui(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP4UIPROC glad_glVertexAttribP4ui = glad_on_demand_impl_glVertexAttribP4ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    glad_glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC) glad_gl_on_demand_loader("glVertexAttribP4uiv");
    glad_glVertexAttribP4uiv(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP4UIVPROC glad_glVertexAttribP4uiv = glad_on_demand_impl_glVertexAttribP4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
    glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) glad_gl_on_demand_loader("glVertexAttribPointer");
    glad_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer = glad_on_demand_impl_glVertexAttribPointer;
static void GLAD_API_PTR glad_on_demand_impl_glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) {
    glad_glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC) glad_gl_on_demand_loader("glVertexBindingDivisor");
    glad_glVertexBindingDivisor(bindingindex, divisor);
}
PFNGLVERTEXBINDINGDIVISORPROC glad_glVertexBindingDivisor = glad_on_demand_impl_glVertexBindingDivisor;
static void GLAD_API_PTR glad_on_demand_impl_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glViewport = (PFNGLVIEWPORTPROC) glad_gl_on_demand_loader("glViewport");
    glad_glViewport(x, y, width, height);
}
PFNGLVIEWPORTPROC glad_glViewport = glad_on_demand_impl_glViewport;
static void GLAD_API_PTR glad_on_demand_impl_glViewportArrayv(GLuint first, GLsizei count, const GLfloat * v) {
    glad_glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC) glad_gl_on_demand_loader("glViewportArrayv");
    glad_glViewportArrayv(first, count, v);
}
PFNGLVIEWPORTARRAYVPROC glad_glViewportArrayv = glad_on_demand_impl_glViewportArrayv;
static void GLAD_API_PTR glad_on_demand_impl_glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
    glad_glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC) glad_gl_on_demand_loader("glViewportIndexedf");
    glad_glViewportIndexedf(index, x, y, w, h);
}
PFNGLVIEWPORTINDEXEDFPROC glad_glViewportIndexedf = glad_on_demand_impl_glViewportIndexedf;
static void GLAD_API_PTR glad_on_demand_impl_glViewportIndexedfv(GLuint index, const GLfloat * v) {
    glad_glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC) glad_gl_on_demand_loader("glViewportIndexedfv");
    glad_glViewportIndexedfv(index, v);
}
PFNGLVIEWPORTINDEXEDFVPROC glad_glViewportIndexedfv = glad_on_demand_impl_glViewportIndexedfv;
static void GLAD_API_PTR glad_on_demand_impl_glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    glad_glWaitSync = (PFNGLWAITSYNCPROC) glad_gl_on_demand_loader("glWaitSync");
    glad_glWaitSync(sync, flags, timeout);
}
PFNGLWAITSYNCPROC glad_glWaitSync = glad_on_demand_impl_glWaitSync;


 

#ifdef GLAD_GL

#ifndef GLAD_LOADER_LIBRARY_C_
#define GLAD_LOADER_LIBRARY_C_

#include <stddef.h>
#include <stdlib.h>

#if GLAD_PLATFORM_WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif


static void* glad_get_dlopen_handle(const char *lib_names[], int length) {
    void *handle = NULL;
    int i;

    for (i = 0; i < length; ++i) {
#if GLAD_PLATFORM_WIN32
  #if GLAD_PLATFORM_UWP
        size_t buffer_size = (strlen(lib_names[i]) + 1) * sizeof(WCHAR);
        LPWSTR buffer = (LPWSTR) malloc(buffer_size);
        if (buffer != NULL) {
            int ret = MultiByteToWideChar(CP_ACP, 0, lib_names[i], -1, buffer, buffer_size);
            if (ret != 0) {
                handle = (void*) LoadPackagedLibrary(buffer, 0);
            }
            free((void*) buffer);
        }
  #else
        handle = (void*) LoadLibraryA(lib_names[i]);
  #endif
#else
        handle = dlopen(lib_names[i], RTLD_LAZY | RTLD_LOCAL);
#endif
        if (handle != NULL) {
            return handle;
        }
    }

    return NULL;
}

static void glad_close_dlopen_handle(void* handle) {
    if (handle != NULL) {
#if GLAD_PLATFORM_WIN32
        FreeLibrary((HMODULE) handle);
#else
        dlclose(handle);
#endif
    }
}

static GLADapiproc glad_dlsym_handle(void* handle, const char *name) {
    if (handle == NULL) {
        return NULL;
    }

#if GLAD_PLATFORM_WIN32
    return (GLADapiproc) GetProcAddress((HMODULE) handle, name);
#else
    return GLAD_GNUC_EXTENSION (GLADapiproc) dlsym(handle, name);
#endif
}

#endif /* GLAD_LOADER_LIBRARY_C_ */

typedef void* (GLAD_API_PTR *GLADglprocaddrfunc)(const char*);
struct _glad_gl_userptr {
    void *handle;
    GLADglprocaddrfunc gl_get_proc_address_ptr;
};

static GLADapiproc glad_gl_get_proc(void *vuserptr, const char *name) {
    struct _glad_gl_userptr userptr = *(struct _glad_gl_userptr*) vuserptr;
    GLADapiproc result = NULL;

    if(userptr.gl_get_proc_address_ptr != NULL) {
        result = GLAD_GNUC_EXTENSION (GLADapiproc) userptr.gl_get_proc_address_ptr(name);
    }
    if(result == NULL) {
        result = glad_dlsym_handle(userptr.handle, name);
    }

    return result;
}

static void* _glad_GL_loader_handle = NULL;

static void* glad_gl_dlopen_handle(void) {
#if GLAD_PLATFORM_APPLE
    static const char *NAMES[] = {
        "../Frameworks/OpenGL.framework/OpenGL",
        "/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
    };
#elif GLAD_PLATFORM_WIN32
    static const char *NAMES[] = {"opengl32.dll"};
#else
    static const char *NAMES[] = {
  #if defined(__CYGWIN__)
        "libGL-1.so",
  #endif
        "libGL.so.1",
        "libGL.so"
    };
#endif

    if (_glad_GL_loader_handle == NULL) {
        _glad_GL_loader_handle = glad_get_dlopen_handle(NAMES, sizeof(NAMES) / sizeof(NAMES[0]));
    }

    return _glad_GL_loader_handle;
}

static struct _glad_gl_userptr glad_gl_build_userptr(void *handle) {
    struct _glad_gl_userptr userptr;

    userptr.handle = handle;
#if GLAD_PLATFORM_APPLE || defined(__HAIKU__)
    userptr.gl_get_proc_address_ptr = NULL;
#elif GLAD_PLATFORM_WIN32
    userptr.gl_get_proc_address_ptr =
        (GLADglprocaddrfunc) glad_dlsym_handle(handle, "wglGetProcAddress");
#else
    userptr.gl_get_proc_address_ptr =
        (GLADglprocaddrfunc) glad_dlsym_handle(handle, "glXGetProcAddressARB");
#endif

    return userptr;
}


#ifdef __cplusplus
static struct _glad_gl_userptr glad_gl_internal_loader_global_userptr = {};
#else
static struct _glad_gl_userptr glad_gl_internal_loader_global_userptr = { 0 };
#endif
static GLADapiproc glad_gl_internal_loader_get_proc(const char *name) {
    if (glad_gl_internal_loader_global_userptr.handle == NULL) {
        glad_gl_internal_loader_global_userptr = glad_gl_build_userptr(glad_gl_dlopen_handle());
    }

    return glad_gl_get_proc((void *) &glad_gl_internal_loader_global_userptr, name);
}


void gladLoaderUnloadGL(void) {
    if (_glad_GL_loader_handle != NULL) {
        glad_close_dlopen_handle(_glad_GL_loader_handle);
        _glad_GL_loader_handle = NULL;
        glad_gl_internal_loader_global_userptr.handle = NULL;
    }
}

#endif /* GLAD_GL */

#ifdef __cplusplus
}
#endif
