/***********************************************************************************
  Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.

  (c) Copyright 1996 - 2002  Gary Henderson (gary.henderson@ntlworld.com),
                             Jerremy Koot (jkoot@snes9x.com)

  (c) Copyright 2002 - 2004  Matthew Kendora

  (c) Copyright 2002 - 2005  Peter Bortas (peter@bortas.org)

  (c) Copyright 2004 - 2005  Joel Yliluoma (http://iki.fi/bisqwit/)

  (c) Copyright 2001 - 2006  John Weidman (jweidman@slip.net)

  (c) Copyright 2002 - 2006  funkyass (funkyass@spam.shaw.ca),
                             Kris Bleakley (codeviolation@hotmail.com)

  (c) Copyright 2002 - 2010  Brad Jorsch (anomie@users.sourceforge.net),
                             Nach (n-a-c-h@users.sourceforge.net),
                             zones (kasumitokoduck@yahoo.com)

  (c) Copyright 2006 - 2007  nitsuja

  (c) Copyright 2009 - 2010  BearOso,
                             OV2


  BS-X C emulator code
  (c) Copyright 2005 - 2006  Dreamer Nom,
                             zones

  C4 x86 assembler and some C emulation code
  (c) Copyright 2000 - 2003  _Demo_ (_demo_@zsnes.com),
                             Nach,
                             zsKnight (zsknight@zsnes.com)

  C4 C++ code
  (c) Copyright 2003 - 2006  Brad Jorsch,
                             Nach

  DSP-1 emulator code
  (c) Copyright 1998 - 2006  _Demo_,
                             Andreas Naive (andreasnaive@gmail.com),
                             Gary Henderson,
                             Ivar (ivar@snes9x.com),
                             John Weidman,
                             Kris Bleakley,
                             Matthew Kendora,
                             Nach,
                             neviksti (neviksti@hotmail.com)

  DSP-2 emulator code
  (c) Copyright 2003         John Weidman,
                             Kris Bleakley,
                             Lord Nightmare (lord_nightmare@users.sourceforge.net),
                             Matthew Kendora,
                             neviksti

  DSP-3 emulator code
  (c) Copyright 2003 - 2006  John Weidman,
                             Kris Bleakley,
                             Lancer,
                             z80 gaiden

  DSP-4 emulator code
  (c) Copyright 2004 - 2006  Dreamer Nom,
                             John Weidman,
                             Kris Bleakley,
                             Nach,
                             z80 gaiden

  OBC1 emulator code
  (c) Copyright 2001 - 2004  zsKnight,
                             pagefault (pagefault@zsnes.com),
                             Kris Bleakley
                             Ported from x86 assembler to C by sanmaiwashi

  SPC7110 and RTC C++ emulator code used in 1.39-1.51
  (c) Copyright 2002         Matthew Kendora with research by
                             zsKnight,
                             John Weidman,
                             Dark Force

  SPC7110 and RTC C++ emulator code used in 1.52+
  (c) Copyright 2009         byuu,
                             neviksti

  S-DD1 C emulator code
  (c) Copyright 2003         Brad Jorsch with research by
                             Andreas Naive,
                             John Weidman

  S-RTC C emulator code
  (c) Copyright 2001 - 2006  byuu,
                             John Weidman

  ST010 C++ emulator code
  (c) Copyright 2003         Feather,
                             John Weidman,
                             Kris Bleakley,
                             Matthew Kendora

  Super FX x86 assembler emulator code
  (c) Copyright 1998 - 2003  _Demo_,
                             pagefault,
                             zsKnight

  Super FX C emulator code
  (c) Copyright 1997 - 1999  Ivar,
                             Gary Henderson,
                             John Weidman

  Sound emulator code used in 1.5-1.51
  (c) Copyright 1998 - 2003  Brad Martin
  (c) Copyright 1998 - 2006  Charles Bilyue'

  Sound emulator code used in 1.52+
  (c) Copyright 2004 - 2007  Shay Green (gblargg@gmail.com)

  SH assembler code partly based on x86 assembler code
  (c) Copyright 2002 - 2004  Marcus Comstedt (marcus@mc.pp.se)

  2xSaI filter
  (c) Copyright 1999 - 2001  Derek Liauw Kie Fa

  HQ2x, HQ3x, HQ4x filters
  (c) Copyright 2003         Maxim Stepin (maxim@hiend3d.com)

  NTSC filter
  (c) Copyright 2006 - 2007  Shay Green

  GTK+ GUI code
  (c) Copyright 2004 - 2010  BearOso

  Win32 GUI code
  (c) Copyright 2003 - 2006  blip,
                             funkyass,
                             Matthew Kendora,
                             Nach,
                             nitsuja
  (c) Copyright 2009 - 2010  OV2

  Mac OS GUI code
  (c) Copyright 1998 - 2001  John Stiles
  (c) Copyright 2001 - 2010  zones


  Specific ports contains the works of other authors. See headers in
  individual files.


  Snes9x homepage: http://www.snes9x.com/

  Permission to use, copy, modify and/or distribute Snes9x in both binary
  and source form, for non-commercial purposes, is hereby granted without
  fee, providing that this license information and copyright notice appear
  with all copies and any derived work.

  This software is provided 'as-is', without any express or implied
  warranty. In no event shall the authors be held liable for any damages
  arising from the use of this software or it's derivatives.

  Snes9x is freeware for PERSONAL USE only. Commercial users should
  seek permission of the copyright holders first. Commercial use includes,
  but is not limited to, charging money for Snes9x or software derived from
  Snes9x, including Snes9x or derivatives in commercial game bundles, and/or
  using Snes9x as a promotion for your commercial product.

  The copyright holders request that bug fixes and improvements to the code
  should be forwarded to them so everyone can benefit from the modifications
  in future versions.

  Super NES and Super Nintendo Entertainment System are trademarks of
  Nintendo Co., Limited and its subsidiary companies.
 ***********************************************************************************/

/*
  SNES9X/1.52.81 for PSP (c) Copyright hissorii
  This file is based on snes9x-1.52-src.tar.bz2 (unix/x11.cpp)
 */

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspgu.h>

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#include <sys/stat.h>
#include <sys/ioctl.h>

#include "snes9x.h"
#include "memmap.h"
#include "ppu.h"
#include "controls.h"
#include "movie.h"
#include "logger.h"
#include "conffile.h"
#include "blit.h"
#include "display.h"

typedef	std::pair<std::string, std::string>	strpair_t;
extern	std::vector<strpair_t>				keymaps;

typedef	void (* Blitter) (uint8 *, int, uint8 *, int, int, int);

#ifdef __linux
// Select seems to be broken in 2.x.x kernels - if a signal interrupts a
// select system call with a zero timeout, the select call is restarted but
// with an infinite timeout! The call will block until data arrives on the
// selected fd(s).
//
// The workaround is to stop the X library calling select in the first
// place! Replace XPending - which polls for data from the X server using
// select - with an ioctl call to poll for data and then only call the blocking
// XNextEvent if data is waiting.
#define SELECT_BROKEN_FOR_SIGNALS
#endif

enum
{
	VIDEOMODE_BLOCKY = 1,
	VIDEOMODE_TV,
	VIDEOMODE_SMOOTH,
	VIDEOMODE_SUPEREAGLE,
	VIDEOMODE_2XSAI,
	VIDEOMODE_SUPER2XSAI,
	VIDEOMODE_EPX,
	VIDEOMODE_HQ2X
};

static void SetupImage (void);
static void TakedownImage (void);

void S9xExtraDisplayUsage (void)
{
	/*                               12345678901234567890123456789012345678901234567890123456789012345678901234567890 */

	S9xMessage(S9X_INFO, S9X_USAGE, "-setrepeat                      Allow altering keyboard auto-repeat");
	S9xMessage(S9X_INFO, S9X_USAGE, "");
	S9xMessage(S9X_INFO, S9X_USAGE, "-v1                             Video mode: Blocky (default)");
	S9xMessage(S9X_INFO, S9X_USAGE, "-v2                             Video mode: TV");
	S9xMessage(S9X_INFO, S9X_USAGE, "-v3                             Video mode: Smooth");
	S9xMessage(S9X_INFO, S9X_USAGE, "-v4                             Video mode: SuperEagle");
	S9xMessage(S9X_INFO, S9X_USAGE, "-v5                             Video mode: 2xSaI");
	S9xMessage(S9X_INFO, S9X_USAGE, "-v6                             Video mode: Super2xSaI");
	S9xMessage(S9X_INFO, S9X_USAGE, "-v7                             Video mode: EPX");
	S9xMessage(S9X_INFO, S9X_USAGE, "-v8                             Video mode: hq2x");
	S9xMessage(S9X_INFO, S9X_USAGE, "");
}

void S9xParseDisplayArg (char **argv, int &i, int argc)
{
  // xxxxx noting to do
}

const char * S9xParseDisplayConfig (ConfigFile &conf, int pass)
{
	if (pass != 1)
		return ("Unix/X11");

	if (!conf.GetBool("Unix::ClearAllControls", false))
	{
		keymaps.push_back(strpair_t("K00:k",            "Joypad1 Right"));
		keymaps.push_back(strpair_t("K00:Right",        "Joypad1 Right"));
		keymaps.push_back(strpair_t("K00:h",            "Joypad1 Left"));
		keymaps.push_back(strpair_t("K00:Left",         "Joypad1 Left"));
		keymaps.push_back(strpair_t("K00:j",            "Joypad1 Down"));
		keymaps.push_back(strpair_t("K00:n",            "Joypad1 Down"));
		keymaps.push_back(strpair_t("K00:Down",         "Joypad1 Down"));
		keymaps.push_back(strpair_t("K00:u",            "Joypad1 Up"));
		keymaps.push_back(strpair_t("K00:Up",           "Joypad1 Up"));
		keymaps.push_back(strpair_t("K00:Return",       "Joypad1 Start"));
		keymaps.push_back(strpair_t("K00:space",        "Joypad1 Select"));
		keymaps.push_back(strpair_t("K00:S+d",          "Joypad1 ToggleTurbo A"));
		keymaps.push_back(strpair_t("K00:C+d",          "Joypad1 ToggleSticky A"));
		keymaps.push_back(strpair_t("K00:d",            "Joypad1 A"));
		keymaps.push_back(strpair_t("K00:S+c",          "Joypad1 ToggleTurbo B"));
		keymaps.push_back(strpair_t("K00:C+c",          "Joypad1 ToggleSticky B"));
		keymaps.push_back(strpair_t("K00:c",            "Joypad1 B"));
		keymaps.push_back(strpair_t("K00:S+s",          "Joypad1 ToggleTurbo X"));
		keymaps.push_back(strpair_t("K00:C+s",          "Joypad1 ToggleSticky X"));
		keymaps.push_back(strpair_t("K00:s",            "Joypad1 X"));
		keymaps.push_back(strpair_t("K00:S+x",          "Joypad1 ToggleTurbo Y"));
		keymaps.push_back(strpair_t("K00:C+x",          "Joypad1 ToggleSticky Y"));
		keymaps.push_back(strpair_t("K00:x",            "Joypad1 Y"));
		keymaps.push_back(strpair_t("K00:S+a",          "Joypad1 ToggleTurbo L"));
		keymaps.push_back(strpair_t("K00:S+v",          "Joypad1 ToggleTurbo L"));
		keymaps.push_back(strpair_t("K00:C+a",          "Joypad1 ToggleSticky L"));
		keymaps.push_back(strpair_t("K00:C+v",          "Joypad1 ToggleSticky L"));
		keymaps.push_back(strpair_t("K00:a",            "Joypad1 L"));
		keymaps.push_back(strpair_t("K00:v",            "Joypad1 L"));
		keymaps.push_back(strpair_t("K00:S+z",          "Joypad1 ToggleTurbo R"));
		keymaps.push_back(strpair_t("K00:C+z",          "Joypad1 ToggleSticky R"));
		keymaps.push_back(strpair_t("K00:z",            "Joypad1 R"));

		keymaps.push_back(strpair_t("K00:KP_Left",      "Joypad2 Left"));
		keymaps.push_back(strpair_t("K00:KP_Right",     "Joypad2 Right"));
		keymaps.push_back(strpair_t("K00:KP_Up",        "Joypad2 Up"));
		keymaps.push_back(strpair_t("K00:KP_Down",      "Joypad2 Down"));
		keymaps.push_back(strpair_t("K00:KP_Enter",     "Joypad2 Start"));
		keymaps.push_back(strpair_t("K00:KP_Add",       "Joypad2 Select"));
		keymaps.push_back(strpair_t("K00:Prior",        "Joypad2 A"));
		keymaps.push_back(strpair_t("K00:Next",         "Joypad2 B"));
		keymaps.push_back(strpair_t("K00:Home",         "Joypad2 X"));
		keymaps.push_back(strpair_t("K00:End",          "Joypad2 Y"));
		keymaps.push_back(strpair_t("K00:Insert",       "Joypad2 L"));
		keymaps.push_back(strpair_t("K00:Delete",       "Joypad2 R"));

		keymaps.push_back(strpair_t("K00:A+F4",         "SoundChannel0"));
		keymaps.push_back(strpair_t("K00:C+F4",         "SoundChannel0"));
		keymaps.push_back(strpair_t("K00:A+F5",         "SoundChannel1"));
		keymaps.push_back(strpair_t("K00:C+F5",         "SoundChannel1"));
		keymaps.push_back(strpair_t("K00:A+F6",         "SoundChannel2"));
		keymaps.push_back(strpair_t("K00:C+F6",         "SoundChannel2"));
		keymaps.push_back(strpair_t("K00:A+F7",         "SoundChannel3"));
		keymaps.push_back(strpair_t("K00:C+F7",         "SoundChannel3"));
		keymaps.push_back(strpair_t("K00:A+F8",         "SoundChannel4"));
		keymaps.push_back(strpair_t("K00:C+F8",         "SoundChannel4"));
		keymaps.push_back(strpair_t("K00:A+F9",         "SoundChannel5"));
		keymaps.push_back(strpair_t("K00:C+F9",         "SoundChannel5"));
		keymaps.push_back(strpair_t("K00:A+F10",        "SoundChannel6"));
		keymaps.push_back(strpair_t("K00:C+F10",        "SoundChannel6"));
		keymaps.push_back(strpair_t("K00:A+F11",        "SoundChannel7"));
		keymaps.push_back(strpair_t("K00:C+F11",        "SoundChannel7"));
		keymaps.push_back(strpair_t("K00:A+F12",        "SoundChannelsOn"));
		keymaps.push_back(strpair_t("K00:C+F12",        "SoundChannelsOn"));

		keymaps.push_back(strpair_t("K00:S+1",          "BeginRecordingMovie"));
		keymaps.push_back(strpair_t("K00:S+2",          "EndRecordingMovie"));
		keymaps.push_back(strpair_t("K00:S+3",          "LoadMovie"));
		keymaps.push_back(strpair_t("K00:A+F1",         "SaveSPC"));
		keymaps.push_back(strpair_t("K00:C+F1",         "SaveSPC"));
		keymaps.push_back(strpair_t("K00:F10",          "LoadOopsFile"));
		keymaps.push_back(strpair_t("K00:A+F2",         "LoadFreezeFile"));
		keymaps.push_back(strpair_t("K00:C+F2",         "LoadFreezeFile"));
		keymaps.push_back(strpair_t("K00:F11",          "LoadFreezeFile"));
		keymaps.push_back(strpair_t("K00:A+F3",         "SaveFreezeFile"));
		keymaps.push_back(strpair_t("K00:C+F3",         "SaveFreezeFile"));
		keymaps.push_back(strpair_t("K00:F12",          "SaveFreezeFile"));
		keymaps.push_back(strpair_t("K00:F1",           "QuickLoad000"));
		keymaps.push_back(strpair_t("K00:F2",           "QuickLoad001"));
		keymaps.push_back(strpair_t("K00:F3",           "QuickLoad002"));
		keymaps.push_back(strpair_t("K00:F4",           "QuickLoad003"));
		keymaps.push_back(strpair_t("K00:F5",           "QuickLoad004"));
		keymaps.push_back(strpair_t("K00:F6",           "QuickLoad005"));
		keymaps.push_back(strpair_t("K00:F7",           "QuickLoad006"));
		keymaps.push_back(strpair_t("K00:F8",           "QuickLoad007"));
		keymaps.push_back(strpair_t("K00:F9",           "QuickLoad008"));
		keymaps.push_back(strpair_t("K00:S+F1",         "QuickSave000"));
		keymaps.push_back(strpair_t("K00:S+F2",         "QuickSave001"));
		keymaps.push_back(strpair_t("K00:S+F3",         "QuickSave002"));
		keymaps.push_back(strpair_t("K00:S+F4",         "QuickSave003"));
		keymaps.push_back(strpair_t("K00:S+F5",         "QuickSave004"));
		keymaps.push_back(strpair_t("K00:S+F6",         "QuickSave005"));
		keymaps.push_back(strpair_t("K00:S+F7",         "QuickSave006"));
		keymaps.push_back(strpair_t("K00:S+F8",         "QuickSave007"));
		keymaps.push_back(strpair_t("K00:S+F9",         "QuickSave008"));

		keymaps.push_back(strpair_t("K00:Scroll_Lock",  "Pause"));
		keymaps.push_back(strpair_t("K00:CS+Escape",    "Reset"));
		keymaps.push_back(strpair_t("K00:S+Escape",     "SoftReset"));
		keymaps.push_back(strpair_t("K00:Escape",       "ExitEmu"));
		keymaps.push_back(strpair_t("K00:Tab",          "EmuTurbo"));
		keymaps.push_back(strpair_t("K00:S+Tab",        "ToggleEmuTurbo"));
		keymaps.push_back(strpair_t("K00:A+equal",      "IncEmuTurbo"));
		keymaps.push_back(strpair_t("K00:A+minus",      "DecEmuTurbo"));
		keymaps.push_back(strpair_t("K00:C+equal",      "IncTurboSpeed"));
		keymaps.push_back(strpair_t("K00:C+minus",      "DecTurboSpeed"));
		keymaps.push_back(strpair_t("K00:equal",        "IncFrameRate"));
		keymaps.push_back(strpair_t("K00:minus",        "DecFrameRate"));
		keymaps.push_back(strpair_t("K00:S+equal",      "IncFrameTime"));
		keymaps.push_back(strpair_t("K00:S+minus",      "DecFrameTime"));
		keymaps.push_back(strpair_t("K00:6",            "SwapJoypads"));
		keymaps.push_back(strpair_t("K00:Print",        "Screenshot"));

		keymaps.push_back(strpair_t("K00:1",            "ToggleBG0"));
		keymaps.push_back(strpair_t("K00:2",            "ToggleBG1"));
		keymaps.push_back(strpair_t("K00:3",            "ToggleBG2"));
		keymaps.push_back(strpair_t("K00:4",            "ToggleBG3"));
		keymaps.push_back(strpair_t("K00:5",            "ToggleSprites"));
		keymaps.push_back(strpair_t("K00:0",            "ToggleHDMA"));
		keymaps.push_back(strpair_t("K00:9",            "ToggleTransparency"));
		keymaps.push_back(strpair_t("K00:BackSpace",    "ClipWindows"));
		keymaps.push_back(strpair_t("K00:A+Escape",     "Debugger"));

		keymaps.push_back(strpair_t("M00:B0",           "{Mouse1 L,Superscope Fire,Justifier1 Trigger}"));
		keymaps.push_back(strpair_t("M00:B1",           "{Justifier1 AimOffscreen Trigger,Superscope AimOffscreen}"));
		keymaps.push_back(strpair_t("M00:B2",           "{Mouse1 R,Superscope Cursor,Justifier1 Start}"));
		keymaps.push_back(strpair_t("M00:Pointer",      "Pointer Mouse1+Superscope+Justifier1"));
		keymaps.push_back(strpair_t("K00:grave",        "Superscope ToggleTurbo"));
		keymaps.push_back(strpair_t("K00:slash",        "Superscope Pause"));
	}

	return ("Unix/X11");
}

static void FatalError (const char *str)
{
	fprintf(stderr, "%s\n", str);
	S9xExit();
}

static unsigned int __attribute__((aligned(16))) list[262144];

#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)

void *fbp0, *fbp1, *zbp;

/*
          <----- 512byte ------>
0x04000000+--------------------+
          |                    |A
          | draw/disp 0 buffer ||272*2byte (16bit color)
          |                    |V
0x04044000+--------------------+
          |                    |A
          | draw/disp 1 buffer ||272*2byte
          |                    |V
0x04088000+--------------------+
          |                    |A
          | z bufer            ||272*2byte
          |                    |V
0x040cc000+--------------------+
          |                    |A
          | GFX.Screen         ||512*2byte (snes max screen size: 512x478)
          |                    |V
0x0414c000+--------------------+
          |                    |
          | Virtexes           |
          |                    |
          +--------------------+
 */

struct Vertexes {
	unsigned short u, v;
	unsigned short color;
	short x, y, z;
	unsigned short u2, v2;
	unsigned short color2;
	short x2, y2, z2;
};

struct Vertexes *vtx = (struct Vertexes *)0x414c000;

void S9xInitDisplay (int argc, char **argv)
{
	fbp0 = 0; // offset 0
	fbp1 = (void *)((unsigned int)fbp0 + BUF_WIDTH * SCR_HEIGHT * 2);
	zbp = (void *)((unsigned int)fbp1 + BUF_WIDTH * SCR_HEIGHT * 2);

	sceGuInit();

	sceGuStart(GU_DIRECT,list);
	sceGuDrawBuffer(GU_PSM_5650,fbp0,BUF_WIDTH);
	sceGuDispBuffer(SCR_WIDTH,SCR_HEIGHT,fbp1,BUF_WIDTH);
	sceGuDepthBuffer(zbp,BUF_WIDTH);
	sceGuOffset(2048 - (SCR_WIDTH/2),2048 - (SCR_HEIGHT/2));
	sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);
	sceGuDepthRange(65535,0);
	sceGuScissor(0,0,SCR_WIDTH,SCR_HEIGHT);
	sceGuEnable(GU_SCISSOR_TEST);
	sceGuFrontFace(GU_CW);
	sceGuEnable(GU_TEXTURE_2D);
	sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);
	sceGuFinish();
	sceGuSync(0,0);

	sceDisplayWaitVblankStart();
	sceGuDisplay(GU_TRUE);

	S9xSetRenderPixelFormat(RGB565);
	S9xBlitFilterInit();
	S9xBlit2xSaIFilterInit();
	S9xBlitHQ2xFilterInit();

	SetupImage();
}

void S9xDeinitDisplay (void)
{
	TakedownImage();
	S9xBlitFilterDeinit();
	S9xBlit2xSaIFilterDeinit();
	S9xBlitHQ2xFilterDeinit();
}

static void TakedownImage (void)
{
	S9xGraphicsDeinit();
}

static void SetupImage (void)
{
	TakedownImage();

	GFX.Pitch = BUF_WIDTH * 2;
	GFX.Screen = (uint16 *)0x040cc000;

	S9xGraphicsInit();
}

#define isInterlace(y) (y >= 448 ? 1 : 0)

void S9xPutImage (int width, int height)
{
	float ratio;
	int scr_width;

	ratio = (float)SCR_HEIGHT / (float)height;
	scr_width = (isInterlace(height)? 512 : 256) * ratio;

	//	fprintf(stderr, "width: %d height: %d\n", width, height);

	// とりあえず高さを画面いっぱいにする
	vtx->u = 0;
	vtx->v = 0;
	vtx->color = 0;
	vtx->x = (SCR_WIDTH - scr_width) / 2;
	vtx->y = 0;
	vtx->z = 0;
	vtx->u2 = width;
	vtx->v2 = height;
	vtx->color2 = 0;
	vtx->x2 = vtx->x + scr_width;
	vtx->y2 = SCR_HEIGHT;
	vtx->z2 = 0;

	sceGuStart(GU_DIRECT, list);
	sceGuTexMode(GU_PSM_5650, 0, 0, 0);
	sceGuTexImage(0, 512, 512, 512, GFX.Screen);
	sceGuTexFunc(GU_TFX_REPLACE, GU_TCC_RGB);
	sceGuTexFilter(GU_NEAREST, GU_NEAREST);

	sceGuDrawArray(GU_SPRITES, GU_TEXTURE_16BIT|GU_COLOR_5650|GU_VERTEX_16BIT|GU_TRANSFORM_2D, 2, 0, vtx);

	sceGuFinish();
	sceGuSync(0, 0);

	sceGuSwapBuffers();
}

void S9xProcessEvents (bool8 block)
{
	// xxxxx noting to do
}

const char * S9xSelectFilename (const char *def, const char *dir1, const char *ext1, const char *title)
{
	static char	s[PATH_MAX + 1];
	char		buffer[PATH_MAX + 1];

	printf("\n%s (default: %s): ", title, def);
	fflush(stdout);

	if (fgets(buffer, PATH_MAX + 1, stdin))
	{
		char	drive[_MAX_DRIVE + 1], dir[_MAX_DIR + 1], fname[_MAX_FNAME + 1], ext[_MAX_EXT + 1];

		char	*p = buffer;
		while (isspace(*p))
			p++;
		if (!*p)
		{
			strncpy(buffer, def, PATH_MAX + 1);
			buffer[PATH_MAX] = 0;
			p = buffer;
		}

		char	*q = strrchr(p, '\n');
		if (q)
			*q = 0;

		_splitpath(p, drive, dir, fname, ext);
		_makepath(s, drive, *dir ? dir : dir1, fname, *ext ? ext : ext1);

		return (s);
	}

	return (NULL);
}

void S9xMessage (int type, int number, const char *message)
{
	const int	max = 36 * 3;
	static char	buffer[max + 1];

	fprintf(stdout, "%s\n", message);
	strncpy(buffer, message, max + 1);
	buffer[max] = 0;
	S9xSetInfoString(buffer);
}

const char * S9xStringInput (const char *message)
{
	static char	buffer[256];

	printf("%s: ", message);
	fflush(stdout);

	if (fgets(buffer, sizeof(buffer) - 2, stdin))
		return (buffer);

	return (NULL);
}

void S9xSetTitle (const char *string)
{
  // xxxxx nothing to do
}

s9xcommand_t S9xGetDisplayCommandT (const char *n)
{
	s9xcommand_t	cmd;

	cmd.type         = S9xBadMapping;
	cmd.multi_press  = 0;
	cmd.button_norpt = 0;
	cmd.port[0]      = 0xff;
	cmd.port[1]      = 0;
	cmd.port[2]      = 0;
	cmd.port[3]      = 0;

	return (cmd);
}

char * S9xGetDisplayCommandName (s9xcommand_t cmd)
{
	return (strdup("None"));
}

void S9xHandleDisplayCommand (s9xcommand_t cmd, int16 data1, int16 data2)
{
	return;
}

bool8 S9xMapDisplayInput (const char *n, s9xcommand_t *cmd)
{
#if 0 // xxxxx
	int	i, d;

	if (!isdigit(n[1]) || !isdigit(n[2]) || n[3] != ':')
		goto unrecog;

	d = ((n[1] - '0') * 10 + (n[2] - '0')) << 24;

	switch (n[0])
	{
		case 'K':
		{
			KeyCode	kc;
			KeySym	ks;

			d |= 0x00000000;

			for (i = 4; n[i] != '\0' && n[i] != '+'; i++) ;

			if (n[i] == '\0' || i == 4)
				i = 4;
			else
			{
				for (i = 4; n[i] != '+'; i++)
				{
					switch (n[i])
					{
						case 'S': d |= ShiftMask   << 8; break;
						case 'C': d |= ControlMask << 8; break;
						case 'A': d |= Mod1Mask    << 8; break;
						case 'M': d |= Mod4Mask    << 8; break;
						default:  goto unrecog;
					}
				}

				i++;
			}

			if ((ks = XStringToKeysym(n + i)) == NoSymbol)
				goto unrecog;
			if ((kc = XKeysymToKeycode(GUI.display, ks)) == 0)
				goto unrecog;

			d |= kc & 0xff;

			return (S9xMapButton(d, *cmd, false));
		}

		case 'M':
		{
			char	*c;
			int		j;

			d |= 0x40000000;

			if (!strncmp(n + 4, "Pointer", 7))
			{
				d |= 0x8000;

				if (n[11] == '\0')
					return (S9xMapPointer(d, *cmd, true));

				i = 11;
			}
			else
			if (n[4] == 'B')
				i = 5;
			else
				goto unrecog;

			d |= j = strtol(n + i, &c, 10);

			if ((c != NULL && *c != '\0') || j > 0x7fff)
				goto unrecog;

			if (d & 0x8000)
				return (S9xMapPointer(d, *cmd, true));

			return (S9xMapButton(d, *cmd, false));
		}

		default:
			break;
	}

unrecog:
	char	*err = new char[strlen(n) + 34];

	sprintf(err, "Unrecognized input device name '%s'", n);
	perror(err);
	delete [] err;
#endif
	return (false);
}

bool S9xDisplayPollButton (uint32 id, bool *pressed)
{
	return (false);
}

bool S9xDisplayPollAxis (uint32 id, int16 *value)
{
	return (false);
}

bool S9xDisplayPollPointer (uint32 id, int16 *x, int16 *y)
{
#if 0 // xxxxx
	if ((id & 0xc0008000) != 0x40008000)
		return (false);

	int	d = (id >> 24) & 0x3f,
		n = id & 0x7fff;

	if (d != 0 || n != 0)
		return (false);

	*x = GUI.mouse_x;
	*y = GUI.mouse_y;

	return (true);
#endif
}

void S9xSetPalette (void)
{
	return;
}
