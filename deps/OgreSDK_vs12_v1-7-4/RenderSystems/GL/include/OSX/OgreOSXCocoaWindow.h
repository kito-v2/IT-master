/*
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org

Copyright (c) 2000-2011 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#ifndef __OSXCocoaWindow_H__
#define __OSXCocoaWindow_H__

#include "OgreOSXWindow.h"
#include "OgreOSXCocoaContext.h"

#include <Cocoa/Cocoa.h>
#include "OgreOSXCocoaView.h"
#include "OgreOSXCGLContext.h"
#include "OgreOSXCocoaWindowDelegate.h"

@class OSXCocoaWindowDelegate;

namespace Ogre {
    class _OgreGLExport OSXCocoaWindow : public OSXWindow
    {
    private:
        NSWindow *mWindow;
        NSView *mView;
        NSOpenGLContext *mGLContext;
        NSOpenGLPixelFormat *mGLPixelFormat;
        OSXCGLContext* mCGLContext;
        OSXCocoaWindowDelegate *mWindowDelegate;

        bool mActive;
        bool mClosed;
		bool mHasResized;
        bool mIsExternal;
        String mWindowTitle;
        bool mUseNSView;

    public:
        OSXCocoaWindow();
        ~OSXCocoaWindow();
		
		NSView* ogreView() const { return mView; };
		NSWindow* ogreWindow() const { return mWindow; };
		NSOpenGLContext* nsopenGLContext() const { return mGLContext; };
		void createWithView(OgreView *view);

		void create(const String& name, unsigned int width, unsigned int height,
	            bool fullScreen, const NameValuePairList *miscParams);
        /** Overridden - see RenderWindow */
        void destroy(void);
        /** Overridden - see RenderWindow */
        bool isActive(void) const;
        /** Overridden - see RenderWindow */
        bool isClosed(void) const;
        /** Overridden - see RenderWindow */
        void reposition(int left, int top);
        /** Overridden - see RenderWindow */
        void resize(unsigned int width, unsigned int height);
        /** Overridden - see RenderWindow */
        void swapBuffers(bool waitForVSync);
        /** Overridden - see RenderWindow */
        virtual void setFullscreen(bool fullScreen, unsigned int width, unsigned int height);
        /** Overridden - see RenderWindow */
		void windowMovedOrResized(void);
		void windowResized(void);
		void windowHasResized(void);
		void createNewWindow(unsigned int width, unsigned int height, String title);
        void createWindowFromExternal(NSView *viewRef);

		bool requiresTextureFlipping() const { return false; }		
		void getCustomAttribute( const String& name, void* pData );
    };
}

#endif

