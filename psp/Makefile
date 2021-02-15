#S9XZSNESFX=1
#S9XZSNESC4=1
#S9XDEBUGGER=1
#S9XNETPLAY=1
#S9XZIP=1
S9XJMA=1

#USB_GDB=1

# Fairly good and special-char-safe descriptor of the os being built on.
OS         = `uname -s -r -m|sed \"s/ /-/g\"|tr \"[A-Z]\" \"[a-z]\"|tr \"/()\" \"___\"`
BUILDDIR   = .

ALL_SRCS = ../apu/SNES_SPC.cpp ../apu/SNES_SPC_misc.cpp ../apu/SNES_SPC_state.cpp ../apu/SPC_DSP.cpp ../apu/SPC_Filter.cpp ../apu/apu.cpp ../bsx.cpp ../c4.cpp ../c4emu.cpp ../cheats.cpp ../cheats2.cpp ../clip.cpp ../conffile.cpp ../controls.cpp ../cpu.cpp ../cpuexec.cpp ../cpuops.cpp ../crosshairs.cpp ../debug.cpp ../dma.cpp ../dsp.cpp ../dsp1.cpp ../dsp2.cpp ../dsp3.cpp ../dsp4.cpp ../filter/2xsai.cpp ../filter/blit.cpp ../filter/epx.cpp ../filter/hq2x.cpp ../filter/snes_ntsc.c ../fxdbg.cpp ../fxemu.cpp ../fxinst.cpp ../gfx.cpp ../globals.cpp ../jma/7zlzma.cpp ../jma/crc32.cpp ../jma/iiostrm.cpp ../jma/inbyte.cpp ../jma/jma.cpp ../jma/lzma.cpp ../jma/lzmadec.cpp ../jma/s9x-jma.cpp ../jma/winout.cpp ../loadzip.cpp ../logger.cpp ../memmap.cpp ../movie.cpp ../netplay.cpp ../obc1.cpp ../ppu.cpp ../psp/psp.cpp ../psp/sub.cpp ../reader.cpp ../sa1.cpp ../sa1cpu.cpp ../screenshot.cpp ../sdd1.cpp ../sdd1emu.cpp ../server.cpp ../seta.cpp ../seta010.cpp ../seta011.cpp ../seta018.cpp ../snapshot.cpp ../snes9x.cpp ../spc7110.cpp ../spc7110dec.cpp ../spc7110emu.cpp ../srtc.cpp ../srtcemu.cpp ../tile.cpp ../unzip/ioapi.c ../unzip/iowin32.c ../unzip/miniunz.c ../unzip/minizip.c ../unzip/mztools.c ../unzip/unzip.c ../unzip/zip.c 

OBJECTS    = ../apu/apu.o ../apu/SNES_SPC.o ../apu/SNES_SPC_misc.o ../apu/SNES_SPC_state.o ../apu/SPC_DSP.o ../apu/SPC_Filter.o ../bsx.o ../cheats.o ../cheats2.o ../clip.o ../conffile.o ../controls.o ../cpu.o ../cpuexec.o ../cpuops.o ../crosshairs.o ../dma.o ../dsp.o ../dsp1.o ../dsp2.o ../dsp3.o ../dsp4.o ../gfx.o ../globals.o ../logger.o ../memmap.o ../movie.o ../obc1.o ../ppu.o ../reader.o ../sa1.o ../sa1cpu.o ../screenshot.o ../sdd1.o ../sdd1emu.o ../seta.o ../seta010.o ../seta011.o ../seta018.o ../snapshot.o ../snes9x.o ../spc7110.o ../srtc.o ../tile.o ../filter/2xsai.o ../filter/blit.o ../filter/epx.o ../filter/hq2x.o ../filter/snes_ntsc.o psp.o sub.o
DEFS       = -DCPU_SHUTDOWN -DSPC700_SHUTDOWN -DCORRECT_VRAM_READS -D__PSP__ -DNOSOUND

ifdef S9XZSNESFX
OBJECTS   += ../i386/fxemu2.o ../i386/fxemu2b.o ../i386/fxemu2c.o ../i386/fxtable.o ../i386/sfxproc.o ../i386/zsnes.o
else
OBJECTS   += ../fxinst.o ../fxemu.o
ifdef S9XDEBUGGER
OBJECTS   += ../fxdbg.o
endif
endif

ifdef S9XZSNESC4
OBJECTS   += ../i386/c4.o ../i386/zsnesc4.o ../c4.o
else
OBJECTS   += ../c4.o ../c4emu.o
endif

ifdef S9XDEBUGGER
OBJECTS   += ../debug.o
endif

ifdef S9XNETPLAY
OBJECTS   += ../netplay.o ../server.o
endif

ifdef S9XZIP
OBJECTS   += ../loadzip.o ../unzip/ioapi.o ../unzip/unzip.o
endif

ifdef S9XJMA
OBJECTS   += ../jma/7zlzma.o ../jma/crc32.o ../jma/iiostrm.o ../jma/inbyte.o ../jma/jma.o ../jma/lzma.o ../jma/lzmadec.o ../jma/s9x-jma.o ../jma/winout.o
endif

INCLUDES   = -I. -I.. -I../apu/ -I../unzip/ -I../jma/ -I../filter/

CCFLAGS    = -G0 -O3 -fomit-frame-pointer -fno-exceptions -fno-rtti -Wall -W -Wno-unused-parameter -DJMA_SUPPORT -DHAVE_MKSTEMP -DHAVE_SYS_IOCTL_H -DHAVE_STDINT_H -DRIGHTSHIFT_IS_SAR $(DEFS)
ifdef USE_GDB
CCFLAGS += -g
endif
CFLAGS     = $(CCFLAGS)


.SUFFIXES: .o .cpp .c .cc .h .m .i .s .asm .obj

OBJS = $(OBJECTS)
LIBS = -lpspgu -lpsppower -lc

TARGET = snes9x15281
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = snes9x/1.52.81
BUILD_PRX = 1

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

CCC = $(CXX)
CC = $(CXX)
INCLUDES += $(addprefix -I,$(INCDIR))

../jma/s9x-jma.o: ../jma/s9x-jma.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@
../jma/7zlzma.o: ../jma/7zlzma.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@
../jma/crc32.o: ../jma/crc32.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@
../jma/iiostrm.o: ../jma/iiostrm.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@
../jma/inbyte.o: ../jma/inbyte.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@
../jma/jma.o: ../jma/jma.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@
../jma/lzma.o: ../jma/lzma.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@
../jma/lzmadec.o: ../jma/lzmadec.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@
../jma/winout.o: ../jma/winout.cpp
	$(CCC) $(INCLUDES) -c $(CCFLAGS) -fexceptions $*.cpp -o $@

.cpp.o:
	$(CCC) $(INCLUDES) -c $(CCFLAGS) $*.cpp -o $@

.c.o:
	$(CC) $(INCLUDES) -c $(CCFLAGS) $*.c -o $@

.cpp.S:
	$(GASM) $(INCLUDES) -S $(CCFLAGS) $*.cpp -o $@

.cpp.i:
	$(GASM) $(INCLUDES) -E $(CCFLAGS) $*.cpp -o $@

.S.o:
	$(GASM) $(INCLUDES) -c $(CCFLAGS) $*.S -o $@

.S.i:
	$(GASM) $(INCLUDES) -c -E $(CCFLAGS) $*.S -o $@

.s.o:
	@echo Compiling $*.s
	sh-elf-as -little $*.s -o $@

.obj.o:
	cp $*.obj $*.o

depend:
	makedepend -Y -- $(CCFLAGS) -- $(ALL_SRCS)
# DO NOT DELETE

../apu/SNES_SPC.o: ../apu/SNES_SPC.h ../apu/SPC_DSP.h ../apu/blargg_common.h
../apu/SNES_SPC.o: ../apu/blargg_config.h ../apu/blargg_endian.h
../apu/SNES_SPC.o: ../apu/blargg_source.h ../apu/SPC_CPU.h
../apu/SNES_SPC_misc.o: ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../apu/SNES_SPC_misc.o: ../apu/blargg_common.h ../apu/blargg_config.h
../apu/SNES_SPC_misc.o: ../apu/blargg_endian.h ../apu/blargg_source.h
../apu/SNES_SPC_state.o: ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../apu/SNES_SPC_state.o: ../apu/blargg_common.h ../apu/blargg_config.h
../apu/SNES_SPC_state.o: ../apu/blargg_endian.h ../apu/blargg_source.h
../apu/SPC_DSP.o: ../apu/SPC_DSP.h ../apu/blargg_common.h
../apu/SPC_DSP.o: ../apu/blargg_config.h ../apu/blargg_endian.h
../apu/SPC_DSP.o: ../apu/blargg_source.h
../apu/SPC_Filter.o: ../apu/SPC_Filter.h ../apu/blargg_common.h
../apu/SPC_Filter.o: ../apu/blargg_config.h ../apu/blargg_source.h
../apu/apu.o: ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../apu/apu.o: ../apu/blargg_common.h ../apu/blargg_config.h
../apu/apu.o: ../apu/blargg_endian.h ../apu/linear_resampler.h
../apu/apu.o: ../apu/resampler.h ../apu/ring_buffer.h
../apu/apu.o: ../apu/hermite_resampler.h
../bsx.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../bsx.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../bsx.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../bsx.o: ../display.h
../c4.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../c4.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../c4.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../c4emu.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../c4emu.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../c4emu.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../c4emu.o: ../sar.h
../cheats.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../cheats.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../cheats.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../cheats.o: ../cheats.h
../cheats2.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../cheats2.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../cheats2.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../cheats2.o: ../cheats.h
../clip.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../clip.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../clip.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../conffile.o: ../conffile.h ../snes9x.h ../port.h ../pixform.h ../65c816.h
../conffile.o: ../messages.h ../reader.h
../controls.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../controls.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h
../controls.o: ../dsp.h ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h
../controls.o: ../bsx.h ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../controls.o: ../apu/blargg_common.h ../apu/blargg_config.h
../controls.o: ../apu/blargg_endian.h ../snapshot.h ../controls.h
../controls.o: ../crosshairs.h ../movie.h ../display.h
../cpu.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../cpu.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../cpu.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h ../dma.h
../cpu.o: ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../cpu.o: ../apu/blargg_common.h ../apu/blargg_config.h
../cpu.o: ../apu/blargg_endian.h ../fxemu.h ../sdd1.h ../srtc.h ../snapshot.h
../cpu.o: ../cheats.h ../logger.h
../cpuexec.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../cpuexec.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../cpuexec.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../cpuexec.o: ../cpuops.h ../dma.h ../apu/apu.h ../apu/SNES_SPC.h
../cpuexec.o: ../apu/SPC_DSP.h ../apu/blargg_common.h ../apu/blargg_config.h
../cpuexec.o: ../apu/blargg_endian.h ../fxemu.h ../snapshot.h
../cpuops.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../cpuops.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../cpuops.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../cpuops.o: ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../cpuops.o: ../apu/blargg_common.h ../apu/blargg_config.h
../cpuops.o: ../apu/blargg_endian.h ../cpuaddr.h ../cpuops.h ../cpumacro.h
../crosshairs.o: ../port.h ../pixform.h ../crosshairs.h
../dma.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../dma.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../dma.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h ../dma.h
../dma.o: ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../dma.o: ../apu/blargg_common.h ../apu/blargg_config.h
../dma.o: ../apu/blargg_endian.h ../sdd1emu.h ../spc7110emu.h ../spc7110dec.h
../dsp.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../dsp.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../dsp.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../dsp1.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../dsp1.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../dsp1.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../dsp2.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../dsp2.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../dsp2.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../dsp3.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../dsp3.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../dsp3.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../dsp4.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../dsp4.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../dsp4.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../filter/2xsai.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h
../filter/2xsai.o: ../messages.h ../filter/2xsai.h
../filter/blit.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h
../filter/blit.o: ../messages.h ../filter/blit.h ../filter/2xsai.h
../filter/blit.o: ../filter/epx.h ../filter/hq2x.h ../filter/snes_ntsc.h
../filter/blit.o: ../filter/snes_ntsc_config.h
../filter/epx.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../filter/epx.o: ../filter/epx.h
../filter/hq2x.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h
../filter/hq2x.o: ../messages.h ../gfx.h ../filter/hq2x.h
../filter/snes_ntsc.o: ../filter/snes_ntsc.h ../filter/snes_ntsc_config.h
../filter/snes_ntsc.o: ../filter/snes_ntsc_impl.h
../fxemu.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../fxemu.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../fxemu.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../fxemu.o: ../fxinst.h ../fxemu.h
../fxinst.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../fxinst.o: ../fxinst.h ../fxemu.h
../gfx.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../gfx.o: ../ppu.h ../gfx.h ../memmap.h ../getset.h ../cpuexec.h ../dsp.h
../gfx.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../gfx.o: ../tile.h ../controls.h ../crosshairs.h ../cheats.h ../movie.h
../gfx.o: ../screenshot.h ../font.h ../display.h
../globals.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../globals.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../globals.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../globals.o: ../dma.h ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../globals.o: ../apu/blargg_common.h ../apu/blargg_config.h
../globals.o: ../apu/blargg_endian.h ../fxinst.h ../fxemu.h ../srtc.h
../globals.o: ../cheats.h
../jma/7zlzma.o: ../jma/7z.h ../jma/iiostrm.h ../jma/portable.h
../jma/7zlzma.o: ../jma/lzmadec.h ../jma/winout.h ../jma/lzma.h
../jma/7zlzma.o: ../jma/lencoder.h ../jma/btreecd.h ../jma/aribitcd.h
../jma/7zlzma.o: ../jma/rngcoder.h ../jma/inbyte.h ../jma/rcdefs.h
../jma/7zlzma.o: ../jma/ariconst.h ../jma/litcoder.h
../jma/crc32.o: ../jma/crc32.h
../jma/iiostrm.o: ../jma/portable.h ../jma/iiostrm.h ../jma/crc32.h
../jma/inbyte.o: ../jma/inbyte.h ../jma/iiostrm.h ../jma/portable.h
../jma/jma.o: ../jma/jma.h ../jma/portable.h ../jma/7z.h ../jma/iiostrm.h
../jma/jma.o: ../jma/crc32.h
../jma/lzma.o: ../jma/lzma.h ../jma/lencoder.h ../jma/btreecd.h
../jma/lzma.o: ../jma/aribitcd.h ../jma/rngcoder.h ../jma/inbyte.h
../jma/lzma.o: ../jma/iiostrm.h ../jma/portable.h ../jma/rcdefs.h
../jma/lzma.o: ../jma/ariconst.h
../jma/lzmadec.o: ../jma/portable.h ../jma/lzmadec.h ../jma/winout.h
../jma/lzmadec.o: ../jma/iiostrm.h ../jma/lzma.h ../jma/lencoder.h
../jma/lzmadec.o: ../jma/btreecd.h ../jma/aribitcd.h ../jma/rngcoder.h
../jma/lzmadec.o: ../jma/inbyte.h ../jma/rcdefs.h ../jma/ariconst.h
../jma/lzmadec.o: ../jma/litcoder.h
../jma/s9x-jma.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h
../jma/s9x-jma.o: ../messages.h ../memmap.h ../getset.h ../cpuexec.h ../ppu.h
../jma/s9x-jma.o: ../gfx.h ../dsp.h ../sa1.h ../spc7110.h ../c4.h ../obc1.h
../jma/s9x-jma.o: ../seta.h ../bsx.h ../jma/s9x-jma.h ../jma/jma.h
../jma/winout.o: ../jma/winout.h ../jma/iiostrm.h ../jma/portable.h
../logger.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../logger.o: ../movie.h ../logger.h
../memmap.o: ../jma/s9x-jma.h ../snes9x.h ../port.h ../pixform.h ../65c816.h
../memmap.o: ../messages.h ../memmap.h ../getset.h ../cpuexec.h ../ppu.h
../memmap.o: ../gfx.h ../dsp.h ../sa1.h ../spc7110.h ../c4.h ../obc1.h
../memmap.o: ../seta.h ../bsx.h ../apu/apu.h ../apu/SNES_SPC.h
../memmap.o: ../apu/SPC_DSP.h ../apu/blargg_common.h ../apu/blargg_config.h
../memmap.o: ../apu/blargg_endian.h ../fxemu.h ../sdd1.h ../srtc.h
../memmap.o: ../controls.h ../cheats.h ../movie.h ../reader.h ../display.h
../movie.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../movie.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../movie.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../movie.o: ../controls.h ../snapshot.h ../movie.h ../language.h
../obc1.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../obc1.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../obc1.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../ppu.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../ppu.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../ppu.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h ../dma.h
../ppu.o: ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../ppu.o: ../apu/blargg_common.h ../apu/blargg_config.h
../ppu.o: ../apu/blargg_endian.h ../fxemu.h ../sdd1.h ../srtc.h ../controls.h
../ppu.o: ../movie.h ../display.h
../psp/psp.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../psp/psp.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../psp/psp.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../psp/psp.o: ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../psp/psp.o: ../apu/blargg_common.h ../apu/blargg_config.h
../psp/psp.o: ../apu/blargg_endian.h ../snapshot.h ../controls.h ../cheats.h
../psp/psp.o: ../movie.h ../logger.h ../display.h ../conffile.h ../reader.h
../psp/sub.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../psp/sub.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../psp/sub.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../psp/sub.o: ../controls.h ../movie.h ../logger.h ../conffile.h ../reader.h
../psp/sub.o: ../filter/blit.h ../filter/2xsai.h ../filter/epx.h
../psp/sub.o: ../filter/hq2x.h ../filter/snes_ntsc.h
../psp/sub.o: ../filter/snes_ntsc_config.h ../display.h
../reader.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../reader.o: ../reader.h
../sa1.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../sa1.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../sa1.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../sa1cpu.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../sa1cpu.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../sa1cpu.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../sa1cpu.o: ../cpuops.cpp ../apu/apu.h ../apu/SNES_SPC.h ../apu/SPC_DSP.h
../sa1cpu.o: ../apu/blargg_common.h ../apu/blargg_config.h
../sa1cpu.o: ../apu/blargg_endian.h ../cpuaddr.h ../cpuops.h ../cpumacro.h
../screenshot.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../screenshot.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h
../screenshot.o: ../dsp.h ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h
../screenshot.o: ../bsx.h ../display.h ../screenshot.h
../sdd1.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../sdd1.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../sdd1.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../sdd1.o: ../sdd1.h ../display.h
../sdd1emu.o: ../port.h ../pixform.h ../sdd1emu.h
../seta.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../seta.o: ../seta.h
../seta010.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../seta010.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../seta010.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../seta011.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../seta011.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../seta011.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../seta018.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../seta018.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../seta018.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../snapshot.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../snapshot.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h
../snapshot.o: ../dsp.h ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h
../snapshot.o: ../bsx.h ../dma.h ../apu/apu.h ../apu/SNES_SPC.h
../snapshot.o: ../apu/SPC_DSP.h ../apu/blargg_common.h ../apu/blargg_config.h
../snapshot.o: ../apu/blargg_endian.h ../fxinst.h ../fxemu.h ../sdd1.h
../snapshot.o: ../srtc.h ../snapshot.h ../controls.h ../movie.h ../display.h
../snapshot.o: ../language.h
../snes9x.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../snes9x.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../snes9x.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../snes9x.o: ../controls.h ../crosshairs.h ../cheats.h ../display.h
../snes9x.o: ../conffile.h ../reader.h
../spc7110.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../spc7110.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../spc7110.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../spc7110.o: ../srtc.h ../display.h ../spc7110emu.h ../spc7110dec.h
../spc7110.o: ../spc7110emu.cpp ../spc7110dec.cpp
../spc7110emu.o: ../spc7110dec.cpp
../srtc.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../srtc.o: ../memmap.h ../getset.h ../cpuexec.h ../ppu.h ../gfx.h ../dsp.h
../srtc.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../srtc.o: ../srtc.h ../display.h ../srtcemu.h ../srtcemu.cpp
../tile.o: ../snes9x.h ../port.h ../pixform.h ../65c816.h ../messages.h
../tile.o: ../ppu.h ../gfx.h ../memmap.h ../getset.h ../cpuexec.h ../dsp.h
../tile.o: ../sa1.h ../spc7110.h ../c4.h ../obc1.h ../seta.h ../bsx.h
../tile.o: ../tile.h ../tile.cpp
../unzip/ioapi.o: ../unzip/ioapi.h
../unzip/iowin32.o: ../unzip/ioapi.h ../unzip/iowin32.h
../unzip/miniunz.o: ../unzip/unzip.h ../unzip/ioapi.h
../unzip/minizip.o: ../unzip/zip.h ../unzip/ioapi.h
../unzip/mztools.o: ../unzip/unzip.h ../unzip/ioapi.h
../unzip/unzip.o: ../unzip/unzip.h ../unzip/ioapi.h ../unzip/crypt.h
../unzip/zip.o: ../unzip/zip.h ../unzip/ioapi.h ../unzip/crypt.h
