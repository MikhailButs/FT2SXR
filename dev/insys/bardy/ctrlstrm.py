"""
****************** File CtrlStrm.h *************************
*
*  Definitions of user application interface
*	structures and constants
*	for BRD_ctrl : STREAM section
*
* (C) Instrumental Systems
*
* Created: by Ekkore Feb, 2003
* Modified:
* 19.09.2005 - added ATTACH/DETACH, waiting & special command (Ekkore & Dorokhin A.)
*
************************************************************
"""

from .ctrl import *

#=********************************************************
#
# Command Codes
#
#=********************************************************

brdStreamCode = \
    {
        'BRDctrl_STREAM_CBUF_ALLOC'        : brdBaseCode['BRDctrl_STREAM'] + 0,    # Alloc CBuf if EXCLUSIVE CaptMode (struct)
        'BRDctrl_STREAM_CBUF_REALLOC'      : brdBaseCode['BRDctrl_STREAM'] + 1,    # Realloc CBuf if EXCLUSIVE CaptMode (struct)
        'BRDctrl_STREAM_CBUF_FREE'         : brdBaseCode['BRDctrl_STREAM'] + 2,    # Free CBuf if EXCLUSIVE CaptMode (NULL)
        'BRDctrl_STREAM_CBUF_START'        : brdBaseCode['BRDctrl_STREAM'] + 3,    # Start Stream (U32)
        'BRDctrl_STREAM_CBUF_STOP'         : brdBaseCode['BRDctrl_STREAM'] + 4,    # Stop Stream (NULL)
        'BRDctrl_STREAM_CBUF_STATE'        : brdBaseCode['BRDctrl_STREAM'] + 5,    # Get State Stream (struct)
        
        'BRDctrl_STREAM_CBUF_ATTACH'       : brdBaseCode['BRDctrl_STREAM'] + 6,    # Attach CBuf if SPY CaptMode (struct)
        'BRDctrl_STREAM_CBUF_DETACH'       : brdBaseCode['BRDctrl_STREAM'] + 7,    # Detach CBuf if SPY CaptMode (NULL)
        'BRDctrl_STREAM_CBUF_WAITBLOCK'    : brdBaseCode['BRDctrl_STREAM'] + 8,    # Wait End of Current Block Transfer (U32)
        'BRDctrl_STREAM_CBUF_WAITBUF'      : brdBaseCode['BRDctrl_STREAM'] + 9,    # Wait End of CBuf Transfer if CyckleMode:0 (U32)
        
        'BRDctrl_STREAM_SETDIR'            : brdBaseCode['BRDctrl_STREAM'] +10,    # Set direction of data transfer (U32)
        'BRDctrl_STREAM_SETSRC'            : brdBaseCode['BRDctrl_STREAM'] +11,    # Set source (tetrad number) of data transfer (U32)
        'BRDctrl_STREAM_SETDRQ'            : brdBaseCode['BRDctrl_STREAM'] +12,    # Set flag for DMA request (U32)
        'BRDctrl_STREAM_RESETFIFO'         : brdBaseCode['BRDctrl_STREAM'] +13,    # Reset Stream FIFO (NULL)
        'BRDctrl_STREAM_CBUF_ADJUST'       : brdBaseCode['BRDctrl_STREAM'] +14,    # Select Adjusted or Unadjusted mode (S32)
        'BRDctrl_STREAM_CBUF_DONE'         : brdBaseCode['BRDctrl_STREAM'] +15,    # Send the Number of Processed Block to Stream (S32)
        'BRDctrl_STREAM_GETDIR'            : brdBaseCode['BRDctrl_STREAM'] +16,    # Get direction of data transfer (U32)
        'BRDctrl_STREAM_VERSION'           : brdBaseCode['BRDctrl_STREAM'] +17,    # Get Stream Version (S32,S32)
        
        'BRDctrl_STREAM_CBUF_WAITBLOCKEX'  : brdBaseCode['BRDctrl_STREAM'] + 18,    # Wait End of Current Block Transfer (PBRD_WaitEvent)
        'BRDctrl_STREAM_CBUF_WAITBUFEX'    : brdBaseCode['BRDctrl_STREAM'] + 19,    # Wait End of CBuf Transfer if CyckleMode:0 (PBRD_WaitEvent)
        
        'BRDctrl_STREAM_SETIRQMODE'        : brdBaseCode['BRDctrl_STREAM'] +20,    # Set interrupt mode (PBRDctrl_StreamSetIrqMode)
    }

"""
print('BRDctrl_STREAM = \\')
print('{')
for key in brdStreamCode:
    if brdStreamCode[key] is not None:
        print(f"    0x{brdStreamCode[key]:04X}: '{key}',")
print('}')
"""

BRDctrl_STREAM = \
    {
        0x0E00: 'BRDctrl_STREAM_CBUF_ALLOC',
        0x0E01: 'BRDctrl_STREAM_CBUF_REALLOC',
        0x0E02: 'BRDctrl_STREAM_CBUF_FREE',
        0x0E03: 'BRDctrl_STREAM_CBUF_START',
        0x0E04: 'BRDctrl_STREAM_CBUF_STOP',
        0x0E05: 'BRDctrl_STREAM_CBUF_STATE',
        0x0E06: 'BRDctrl_STREAM_CBUF_ATTACH',
        0x0E07: 'BRDctrl_STREAM_CBUF_DETACH',
        0x0E08: 'BRDctrl_STREAM_CBUF_WAITBLOCK',
        0x0E09: 'BRDctrl_STREAM_CBUF_WAITBUF',
        0x0E0A: 'BRDctrl_STREAM_SETDIR',
        0x0E0B: 'BRDctrl_STREAM_SETSRC',
        0x0E0C: 'BRDctrl_STREAM_SETDRQ',
        0x0E0D: 'BRDctrl_STREAM_RESETFIFO',
        0x0E0E: 'BRDctrl_STREAM_CBUF_ADJUST',
        0x0E0F: 'BRDctrl_STREAM_CBUF_DONE',
        0x0E10: 'BRDctrl_STREAM_GETDIR',
        0x0E11: 'BRDctrl_STREAM_VERSION',
        0x0E12: 'BRDctrl_STREAM_CBUF_WAITBLOCKEX',
        0x0E13: 'BRDctrl_STREAM_CBUF_WAITBUFEX',
        0x0E14: 'BRDctrl_STREAM_SETIRQMODE',
    }
# #=********************************************************
# #
# # Structure Declarations
# #
# #=********************************************************
# 
# #pragma pack(push, 1) 
# 
# #
# # Stub Structure
# #
# typedef struct
# {
#     S32		lastBlock;				# Number of Block which was filled last Time
# U32		totalCounter;			# Total Counter of all filled Block
# U32		offset;					# First Unfilled Byte
# U32		state;					# CBUF local state
# } BRDstrm_Stub, *PBRDstrm_Stub, BRDctrl_StreamStub, *PBRDctrl_StreamStub;
# 
# #
# # For BRDctrl_STREAM_CBUF_ALLOC
# # For BRDctrl_STREAM_CBUF_REALLOC
# #
# typedef struct
# {
#     U32				dir;		# IN, Stream Direction (1-to Host, 2-from Host)
# U32				isCont;		# IN, Allocation Method: 0-FileMapping, 1-System Pool (Ring 0)
# U32				blkNum;		# IN, Number of Blocks
# U32				blkSize;	# IN, Size of Blocks (bytes)
# void**			ppBlk;		# OUT,Block Pointers
# BRDstrm_Stub*	pStub;		# OUT,Stub Pointer
# } BRDctrl_StreamCBufAlloc,   *PBRDctrl_StreamCBufAlloc,
# BRDctrl_StreamCBufRealloc, *PBRDctrl_StreamCBufRealloc;
# 
# #
# # For BRDctrl_STREAM_CBUF_START
# #
# typedef struct
# {
#     U32		isCycle;			# IN,  Cycle Mode (1-on, 0-off)
# } BRDctrl_StreamCBufStart, *PBRDctrl_StreamCBufStart;
# 
# #
# # For BRDctrl_STREAM_CBUF_STOP
# #
# typedef struct
# {
#     U32		dummy;				# Not used
# } BRDctrl_StreamCBufStop, *PBRDctrl_StreamCBufStop;
# 
# #
# # For BRDctrl_STREAM_CBUF_STATE
# #
# typedef struct
# {
#     S32		blkNum;			# OUT, Last Filled Block Number
# U32		blkNumTotal;	# OUT, Total Filled Block Counter
# U32		offset;			# OUT, First Unfilled Byte
# U32		state;			# OUT, State of CBuf (1-start, 2-stop, 3-destroied)
# U32		timeout;		# IN,  Timeout (msec) (0xFFFFFFFFL - INFINITE)
# } BRDctrl_StreamCBufState, *PBRDctrl_StreamCBufState;
# 
# #
# # For BRDctrl_STREAM_CBUF_ATTACH
# #
# typedef struct
# {
#     U32				dir;		# OUT, Stream Direction (1-to Host, 2-from Host)
# U32				isCont;		#      Reserved
# U32				blkNum;		# I/O, Size of ppBlk[], Number of Blocks
# U32				blkSize;	# OUT, Size of Blocks (bytes)
# void**			ppBlk;		# OUT, Block Pointers
# BRDstrm_Stub*	pStub;		# OUT, Stub Pointer
# } BRDctrl_StreamCBufAttach, *PBRDctrl_StreamCBufAttach;
# 
# #
# # For BRDctrl_STREAM_CBUF_WAITBLOCK
# #
# typedef struct
# {
#     U32		timeout;		# IN,  Timeout (msec) (0xFFFFFFFFL - INFINITE)
# } BRDctrl_StreamCBufWaitBlock, *PBRDctrl_StreamCBufWaitBlock;
# 
# 
# #
# # For BRDctrl_STREAM_CBUF_WAITBUF
# #
# typedef struct
# {
#     U32		timeout;		# IN,  Timeout (msec) (0xFFFFFFFFL - INFINITE)
# } BRDctrl_StreamCBufWaitBuf, *PBRDctrl_StreamCBufWaitBuf;
# 
# #
# # For BRDctrl_STREAM_SETDIR, BRDctrl_STREAM_GETDIR
# #
# typedef struct
# {
#     U32		dir;			# IN, Stream Direction (1-to Host, 2-from Host)
# } BRDctrl_StreamSetDir, *PBRDctrl_StreamSetDir,
# BRDctrl_StreamGetDir, *PBRDctrl_StreamGetDir;
# 
# #
# # For BRDctrl_STREAM_SETSRC
# #
# typedef struct
# {
#     U32		src;			# IN
# } BRDctrl_StreamSetSrc, *PBRDctrl_StreamSetSrc;
# 
# #
# # For BRDctrl_STREAM_SETDRQ
# #
# typedef struct
# {
#     U32		drq;			# IN, Flag for DMA request
# } BRDctrl_StreamSetDrq, *PBRDctrl_StreamSetDrq;
# 
# #
# # For BRDctrl_STREAM_RESETFIFO
# #
# typedef struct
# {
#     U32		dummy;			# Not used
# } BRDctrl_StreamResetFifo, *PBRDctrl_StreamResetFifo;
# 
# #
# # For BRDctrl_STREAM_CBUF_ADJUST
# #
# typedef struct
# {
#     S32		isAdjust;			# IN, Select mode: 1-adjusted, 0-unadjusted
# } BRDctrl_StreamCBufAdjust, *PBRDctrl_StreamCBufAdjust;
# 
# #
# # For BRDctrl_STREAM_CBUF_DONE
# #
# typedef struct
# {
#     S32		blkNo;			# IN,  Number of processed Block
# } BRDctrl_StreamCBufDone, *PBRDctrl_StreamCBufDone;
# 
# #
# # For BRDctrl_STREAM_VERSION
# #
# typedef struct
# {
#     S32		major;			# OUT,  Major Number of Version
# S32		minor;			# OUT,  Minor Number of Version
# } BRDctrl_StreamVersion, *PBRDctrl_StreamVersion;
# 
# #
# # For BRDctrl_STREAM_SETIRQMODE
# #
# typedef struct
# {
#     U32		mode;		# IN, Interrupts mode: 0-use host interrupts, 1-use table
# U32		irqNum;		# IN, Number of Address (entry of table)
# U32*	pIrqTable;	# IN,IRQ Addresses Table
# } BRDctrl_StreamSetIrqMode,   *PBRDctrl_StreamSetIrqMode;
# 
# #pragma pack(pop)    

#=********************************************************
#
# Constants
#
#=********************************************************

#
# Constants: State of CBUF
#

# enum
# {
#     BRDstrm_STAT_RUN = 1,
#                        BRDstrm_STAT_STOP = 2,
#                                            BRDstrm_STAT_DESTROY = 3,
#                                                                   BRDstrm_STAT_BREAK = 4
# };
# 
# #
# # Constants: Direction of CBUF
# #
# 
# enum
# {
#     BRDstrm_DIR_IN = 0x1,				# To HOST
# BRDstrm_DIR_OUT = 0x2,				# From HOST
# BRDstrm_DIR_INOUT = 0x3				# Both Directions
# };
# 
# #
# # Constants: flag for BRDctrl_STREAM_SETDRQ
#     #
# 
# enum
# {
#     BRDstrm_DRQ_ALMOST	= 0x0,			# Almost empty = 1 for input FIFO, Almost full = 1 for output FIFO
# BRDstrm_DRQ_READY	= 0x1,			# Ready = 1
# BRDstrm_DRQ_HALF	= 0x2			# Half full = 0 for input FIFO, Half full = 1 for output FIFO
# };

"""
#=********************************************************
#
# Error Codes
#
#=********************************************************
"""

brdStreamErrCode = \
    {
        #
        #	BRDerr_STREAM_WARNING
        #
        #  Stream Warning
        #
        'BRDerr_STREAM_WARNING' : 0x40000E00,
        
        #
        #	BRDerr_STREAM_SUSPENDED
        #
        #  Stream has beeb suspended
        #
        'BRDerr_STREAM_SUSPENDED' : 0x40000E01,
        
        #
        #	BRDerr_STREAM_ERROR
        #
        #  Undefined Stream Error
        #
        'BRDerr_STREAM_ERROR' : 0xC0000E00,
        
        #
        #	BRDerr_STREAM_ALREADY_ALLOCATED
        #
        #  If you try to Allocate Stream in EXCLUSIVE Mode,
        #  but Stream has already been allocated
        #
        'BRDerr_STREAM_ALREADY_ALLOCATED' : 0xC0000E01,
        
        #
        #	BRDerr_STREAM_NOT_ALLOCATED_YET
        #
        #  If you try to Allocate Stream in SPY Mode,
        #  but Stream hasn't been allocated yet
        #
        'BRDerr_STREAM_NOT_ALLOCATED_YET' : 0xC0000E02,
        
        #
        #	BRDerr_STREAM_CONTINUOUS
        #
        #  If you try to Allocate Stream in SPY Mode,
        #  but Stream has been allocated as Continuous
        #
        'BRDerr_STREAM_CONTINUOUS' : 0xC0000E03,
        
        #
        #	BRDerr_STREAM_ALREADY_DESTROYED
        #
        #  1. If you try to Allocate Stream in SPY Mode,
        #  2. If you try to get state of Stream in SPY Mode,
        #
        #  but Stream has already been destroyed
        #
        'BRDerr_STREAM_ALREADY_DESTROYED' : 0xC0000E04,
        
        #
        #	BRDerr_STREAM_UNLOCKED
        #
        #  Can't Probe and Lock Blocks
        #
        'BRDerr_STREAM_UNLOCKED' : 0xC0000E05,
        
        #
        #	BRDerr_STREAM_ALREADY_STARTED
        #
        #  If you try to Start Stream in EXCLUSIVE Mode,
        #  but Stream has already been allocated
        #
        'BRDerr_STREAM_ALREADY_STARTED' : 0xC0000E06,
        
        #
        #	BRDerr_STREAM_NOT_STARTED_YET
        #
        #  If you try to Stop Stream in EXCLUSIVE Mode
        #  or to get state of Stream,
        #  but Stream hasn't been started yet
        #
        'BRDerr_STREAM_NOT_STARTED_YET' : 0xC0000E07,
        
        #
        #	BRDerr_STREAM_NOT_STOPPED_YET
        #
        #  If you try to Free Stream in EXCLUSIVE Mode,
        #  but Stream hasn't been stopped yet
        #
        'BRDerr_STREAM_NOT_STOPPED_YET' : 0xC0000E08
    }

"""print('BRDerr_STREAM = \\')
print('{')
for key in brdStreamErrCode:
    if brdStreamErrCode[key] is not None:
        print(f"    0x{brdStreamErrCode[key]:04X}: '{key}',")
print('}')
"""

BRDerr_STREAM = \
    {
        0x40000E00: 'BRDerr_STREAM_WARNING',
        0x40000E01: 'BRDerr_STREAM_SUSPENDED',
        0xC0000E00: 'BRDerr_STREAM_ERROR',
        0xC0000E01: 'BRDerr_STREAM_ALREADY_ALLOCATED',
        0xC0000E02: 'BRDerr_STREAM_NOT_ALLOCATED_YET',
        0xC0000E03: 'BRDerr_STREAM_CONTINUOUS',
        0xC0000E04: 'BRDerr_STREAM_ALREADY_DESTROYED',
        0xC0000E05: 'BRDerr_STREAM_UNLOCKED',
        0xC0000E06: 'BRDerr_STREAM_ALREADY_STARTED',
        0xC0000E07: 'BRDerr_STREAM_NOT_STARTED_YET',
        0xC0000E08: 'BRDerr_STREAM_NOT_STOPPED_YET',
    }

