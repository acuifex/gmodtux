#pragma once

class CShowPixelsParams;

typedef void* PseudoGLContextPtr;

class ILauncherMgr {
public:
    void PumpWindowsMessageLoop() {
        typedef void (* oPumpWindowsMessageLoop)(void*);
        return getvfunc<oPumpWindowsMessageLoop>(this, 15)(this);
    }

    PseudoGLContextPtr GetMainContext() {
        typedef PseudoGLContextPtr (* oGetMainContext)(void*);
        return getvfunc<oGetMainContext>(this, 22)(this);
    }

    PseudoGLContextPtr CreateExtraContext() {
        typedef PseudoGLContextPtr (* oCreateExtraContext)(void*);
        return getvfunc<oCreateExtraContext>(this, 24)(this);
    }

    void DeleteContext(PseudoGLContextPtr context) {
        typedef void (* oDeleteContext)(void*, PseudoGLContextPtr);
        return getvfunc<oDeleteContext>(this, 25)(this, context);
    }

    bool MakeContextCurrent(PseudoGLContextPtr context) {
        typedef bool (* oMakeContextCurrent)(void*, PseudoGLContextPtr);
        return getvfunc<oMakeContextCurrent>(this, 26)(this, context);
    }

    void ShowPixels(CShowPixelsParams* params) {
        typedef void (* oPumpWindowsMessageLoop)(void*, CShowPixelsParams*);
        return getvfunc<oPumpWindowsMessageLoop>(this, 29)(this, params);
    }

    void* GetWindowRef() {
        typedef void* (* oGetWindowRef)(void*);
        return getvfunc<oGetWindowRef>(this, 32)(this);
    }
};

extern ILauncherMgr* launchermgr;