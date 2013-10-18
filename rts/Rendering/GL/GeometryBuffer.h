/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef GEOMETRYBUFFER_H
#define GEOMETRYBUFFER_H

#include "Rendering/GL/FBO.h"
#include "System/type2.h"

namespace GL {
	struct GeometryBuffer {
	public:
		enum {
			ATTACHMENT_NORMTEX = 0, // shading (not geometric) normals
			ATTACHMENT_DIFFTEX = 1, // diffuse texture fragments
			ATTACHMENT_SPECTEX = 2, // specular texture fragments
			ATTACHMENT_ZVALTEX = 3, // depth-values
			ATTACHMENT_COUNT   = 4,
		};

		GeometryBuffer() { Init(); }

		void Init();
		void Kill();
		void DrawDebug(unsigned int texID);

		bool Valid() const { return (buffer.IsValid()); }
		bool Create(const int2 size, const char* name);
		bool Update(const bool init, const char* name);

		GLuint GetBufferTexture(unsigned int idx) const { return bufferTextureIDs[idx]; }
		GLuint GetBufferAttachment(unsigned int idx) const { return bufferAttachments[idx]; }

		const FBO& GetObject() const { return buffer; }
		      FBO& GetObject()       { return buffer; }

		void Bind() { buffer.Bind(); }
		void UnBind() { buffer.Unbind(); }

		int2 GetCurrSize() const { return currBufferSize; }
		int2 GetPrevSize() const { return prevBufferSize; }

		int2 GetWantedSize(bool allowed) const;

	private:
		FBO buffer;

		GLuint bufferTextureIDs[ATTACHMENT_COUNT];
		GLenum bufferAttachments[ATTACHMENT_COUNT];

		int2 prevBufferSize;
		int2 currBufferSize;
	};
};

#endif

