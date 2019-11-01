#pragma once

class CShowPixelsParams {
public:
    unsigned int m_srcTexName;
    int m_width;
    int m_height;
    bool m_vsyncEnable;
    bool m_fsEnable; // want receiving view to be full screen.  for now, just target the main screen.  extend later.
    bool m_useBlit; // use FBO blit - sending context says it is available.
    bool m_noBlit; // the back buffer has already been populated by the caller (perhaps via direct MSAA resolve from multisampled RT tex)
    bool m_onlySyncView; // react to full/windowed state change only, do not present bits
};