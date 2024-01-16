# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: sxr_protocol.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x12sxr_protocol.proto\x12\x0csxr_protocol\"]\n\nMainPacket\x12\x0f\n\x07\x61\x64\x64ress\x18\x01 \x02(\x07\x12\x0e\n\x06sender\x18\x02 \x02(\x07\x12\x0f\n\x07\x63ommand\x18\x03 \x02(\x07\x12\x0c\n\x04\x64\x61ta\x18\x04 \x01(\x0c\x12\x0f\n\x07version\x18\x05 \x01(\t\"\x93\n\n\tAdcStatus\x12\x0c\n\x04name\x18\x01 \x01(\t\x12\x16\n\x07\x65nabled\x18\x02 \x01(\x08:\x05\x66\x61lse\x12\x18\n\tconnected\x18\x03 \x01(\x08:\x05\x66\x61lse\x12\x15\n\rsampling_rate\x18\x04 \x01(\x07\x12\x1b\n\x13inter_channel_delay\x18) \x01(\x02\x12\x1a\n\x12inter_sample_delay\x18* \x01(\x02\x12\x0f\n\x07samples\x18\x05 \x01(\x07\x12\x41\n\x05start\x18\x06 \x01(\x0e\x32\'.sxr_protocol.AdcStatus.EnumStartSource:\tSOFTSTART\x12\x17\n\x0fstart_threshold\x18= \x01(\x02\x12\x17\n\x0fstart_inversion\x18> \x01(\x08\x12\x12\n\nstart_mode\x18? \x01(\x0c\x12\x16\n\x0eis_in_periodic\x18\x0b \x01(\x08\x12@\n\x04stop\x18\x07 \x01(\x0e\x32\'.sxr_protocol.AdcStatus.EnumStartSource:\tSOFTSTART\x12\x16\n\x0estop_threshold\x18G \x01(\x02\x12\x16\n\x0estop_inversion\x18H \x01(\x08\x12\x11\n\tstop_mode\x18I \x01(\x0c\x12G\n\x0c\x63lock_source\x18\x08 \x01(\x0e\x32\'.sxr_protocol.AdcStatus.EnumClockSource:\x08\x43LOCKINT\x12\x37\n\x0bmemory_type\x18\t \x01(\x0e\x32\".sxr_protocol.AdcStatus.EnumMemory\x12\x39\n\x0c\x62oard_status\x18\n \x03(\x0b\x32#.sxr_protocol.AdcStatus.BoardStatus\x1a\x98\x02\n\x0b\x42oardStatus\x12\x0c\n\x04name\x18\x01 \x01(\t\x12\x0f\n\x07\x65nabled\x18\x02 \x01(\x08\x12\x14\n\x0c\x63hannel_mask\x18\x03 \x01(\x0c\x12\x1b\n\x13hidden_channel_mask\x18\x05 \x01(\x0c\x12I\n\x0e\x63hannel_status\x18\x04 \x03(\x0b\x32\x31.sxr_protocol.AdcStatus.BoardStatus.ChannelStatus\x1al\n\rChannelStatus\x12\x0c\n\x04name\x18\x01 \x01(\t\x12\x16\n\x07\x65nabled\x18\x02 \x01(\x08:\x05\x66\x61lse\x12\x13\n\x04void\x18\x05 \x01(\x08:\x05\x66\x61lse\x12\x0f\n\x04gain\x18\x03 \x01(\x02:\x01\x31\x12\x0f\n\x04\x62ias\x18\x04 \x01(\x02:\x01\x30\"W\n\x0f\x45numStartSource\x12\r\n\tSOFTSTART\x10\x00\x12\x0c\n\x08INTSTART\x10\x00\x12\x0c\n\x08\x45XTSTART\x10\x01\x12\x07\n\x03IN0\x10\x02\x12\x0c\n\x08STARTTHR\x10\x02\x1a\x02\x10\x01\";\n\x0f\x45numClockSource\x12\x0c\n\x08\x43LOCKOFF\x10\x00\x12\x0c\n\x08\x43LOCKINT\x10\x01\x12\x0c\n\x08\x43LOCKEXT\x10\x02\"2\n\nEnumMemory\x12\x0b\n\x07MEMHOST\x10\x00\x12\n\n\x06MEMINT\x10\x01\x12\x0b\n\x07MEMFIFO\x10\x03\"\x9c\x01\n\x0c\x43onnectorsIn\x12\x0c\n\x08\x43ON_CH_1\x10\x01\x12\x0c\n\x08\x43ON_CH_2\x10\x02\x12\x0c\n\x08\x43ON_CH_3\x10\x03\x12\x0c\n\x08\x43ON_CH_4\x10\x04\x12\x0c\n\x08\x43ON_CH_5\x10\x05\x12\x0c\n\x08\x43ON_CH_6\x10\x06\x12\x0c\n\x08\x43ON_CH_7\x10\x07\x12\x0c\n\x08\x43ON_CH_8\x10\x08\x12\r\n\tCON_START\x10\t\x12\r\n\tCON_CLOCK\x10\n\"\x89\x01\n\tAmpStatus\x12\x10\n\x05gainA\x18\x01 \x02(\x02:\x01\x30\x12\x10\n\x05gainB\x18\x02 \x02(\x02:\x01\x30\x12\x0f\n\x04tail\x18\x03 \x02(\r:\x01\x36\"\x1a\n\x0c\x43onnectorsIn\x12\n\n\x06\x43ON_IN\x10\x00\"+\n\rConnectorsOut\x12\x0c\n\x08\x43ON_CH_A\x10\x01\x12\x0c\n\x08\x43ON_CH_B\x10\x02\"\x86\x01\n\x0eHardwareStatus\x12\x10\n\x05\x61ngle\x18\x01 \x02(\x02:\x01\x30\x12\x11\n\x06vknife\x18\x02 \x02(\x02:\x01\x30\x12\x11\n\x06hknife\x18\x03 \x02(\x02:\x01\x30\x12\x0f\n\x04\x66oil\x18\x04 \x02(\t:\x01?\x12\x14\n\tdiaphragm\x18\x05 \x02(\t:\x01?\x12\x15\n\x06shiber\x18\x06 \x01(\x08:\x05\x66\x61lse\"\xb1\x01\n\rJournalStatus\x12\x12\n\x07SXRshot\x18\x01 \x02(\r:\x01\x30\x12\x16\n\x0bTOKAMAKshot\x18\x02 \x01(\r:\x01\x30\x12\x1d\n\x08\x66ilename\x18\x03 \x02(\t:\x0bSXRspectrum\x12\x11\n\x07\x63omment\x18\x04 \x01(\t:\x00\x12\x14\n\ndaycomment\x18\x05 \x01(\t:\x00\x12\x17\n\rsignal_source\x18\x06 \x01(\t:\x00\x12\x13\n\twork_type\x18\x07 \x01(\t:\x00\"\xb4\x01\n\rTokamakStatus\x12\x12\n\x07\x64\x65nsity\x18\x01 \x01(\x02:\x01\x30\x12\x12\n\x07\x63urrent\x18\x02 \x01(\r:\x01\x30\x12:\n\x08shotType\x18\x03 \x01(\x0e\x32$.sxr_protocol.TokamakStatus.EnumShot:\x02OH\x12\x10\n\x05power\x18\x04 \x01(\r:\x01\x30\"-\n\x08\x45numShot\x12\x06\n\x02OH\x10\x00\x12\x06\n\x02RF\x10\x01\x12\x08\n\x04GLOW\x10\x02\x12\x07\n\x03OFF\x10\x03\"K\n\tGsaStatus\x12\x14\n\tamplitude\x18\x01 \x01(\x02:\x01\x30\x12\x10\n\x04\x65\x64ge\x18\x02 \x01(\x02:\x02\x32\x34\x12\x16\n\tfrequency\x18\x03 \x01(\x02:\x03\x36\x32\x36\"\xfc\x04\n\x0cSystemStatus\x12\x39\n\x05state\x18\x01 \x02(\x0e\x32$.sxr_protocol.SystemStatus.EnumState:\x04IDLE\x12\x30\n\x04\x64\x65vs\x18\x02 \x03(\x0e\x32\".sxr_protocol.SystemStatus.EnumDev\x12!\n\x05\x62inds\x18\x03 \x03(\x0b\x32\x12.sxr_protocol.Bind\"G\n\tEnumState\x12\x08\n\x04IDLE\x10\x00\x12\x0f\n\x0bMEASUREMENT\x10\x01\x12\x0f\n\x0b\x43\x41LIBRATION\x10\x02\x12\x0e\n\nBACKGROUND\x10\x03\"\xad\x01\n\x07\x45numDev\x12\x0b\n\x07UNKNOWN\x10\x00\x12\x07\n\x03\x41NY\x10\x00\x12\x07\n\x03SXR\x10\x01\x12\x07\n\x03\x41\x44\x43\x10\x02\x12\x07\n\x03PX5\x10\x03\x12\x07\n\x03\x41MP\x10\x04\x12\x07\n\x03GSA\x10\x05\x12\n\n\x06MINIX2\x10\x06\x12\x08\n\x04XRAY\x10\x06\x12\n\n\x06SOURCE\x10\x06\x12\x08\n\x04\x46\x45\x35\x35\x10\x07\x12\x07\n\x03SDD\x10\x08\x12\x0b\n\x07TOKAMAK\x10\t\x12\x0b\n\x07JOURNAL\x10\n\x12\x0c\n\x08HARDWARE\x10\x0b\x1a\x02\x10\x01\"8\n\rConnectorsOut\x12\x0b\n\x07\x43ON_OUT\x10\x00\x12\x0c\n\x08\x43ON_CON1\x10\x01\x12\x0c\n\x08\x43ON_CON2\x10\x02\"\xa8\x01\n\x0c\x43onnectorsIn\x12\n\n\x06\x43ON_IN\x10\x00\x12\x0c\n\x08\x43ON_CH_1\x10\x01\x12\x0c\n\x08\x43ON_CH_2\x10\x02\x12\x0c\n\x08\x43ON_CH_3\x10\x03\x12\x0c\n\x08\x43ON_CH_4\x10\x04\x12\x0c\n\x08\x43ON_CH_5\x10\x05\x12\x0c\n\x08\x43ON_CH_6\x10\x06\x12\x0c\n\x08\x43ON_CH_7\x10\x07\x12\x0c\n\x08\x43ON_CH_8\x10\x08\x12\r\n\tCON_START\x10\t\x12\r\n\tCON_CLOCK\x10\n\"v\n\x06Source\x12/\n\x03\x64\x65v\x18\x01 \x02(\x0e\x32\".sxr_protocol.SystemStatus.EnumDev\x12;\n\tconnector\x18\x02 \x02(\x0e\x32(.sxr_protocol.SystemStatus.ConnectorsOut\"x\n\x08Receiver\x12/\n\x03\x64\x65v\x18\x01 \x02(\x0e\x32\".sxr_protocol.SystemStatus.EnumDev\x12;\n\tconnector\x18\x02 \x02(\x0e\x32(.sxr_protocol.SystemStatus.ConnectorsOut\"W\n\x04\x42ind\x12$\n\x06source\x18\x01 \x02(\x0b\x32\x14.sxr_protocol.Source\x12)\n\treceivers\x18\x02 \x03(\x0b\x32\x16.sxr_protocol.Receiver*\xca\x01\n\x08\x43ommands\x12\x08\n\x04INFO\x10\x00\x12\n\n\x06STATUS\x10\x01\x12\x0e\n\nGET_STATUS\x10\x01\x12\x07\n\x03GET\x10\x02\x12\x10\n\x0cGET_SETTINGS\x10\x02\x12\x07\n\x03SET\x10\x03\x12\x0e\n\nSET_STATUS\x10\x03\x12\x0c\n\x08SETTINGS\x10\x03\x12\t\n\x05START\x10\x04\x12\x08\n\x04STOP\x10\x05\x12\n\n\x06REBOOT\x10\x06\x12\x0b\n\x07\x43ONNECT\x10\x07\x12\x0c\n\x08SNAPSHOT\x10\x08\x12\x0c\n\x08SHUTDOWN\x10\t\x12\x08\n\x04\x44ONE\x10\n\x1a\x02\x10\x01')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'sxr_protocol_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _COMMANDS._options = None
  _COMMANDS._serialized_options = b'\020\001'
  _ADCSTATUS_ENUMSTARTSOURCE._options = None
  _ADCSTATUS_ENUMSTARTSOURCE._serialized_options = b'\020\001'
  _SYSTEMSTATUS_ENUMDEV._options = None
  _SYSTEMSTATUS_ENUMDEV._serialized_options = b'\020\001'
  _COMMANDS._serialized_start=3121
  _COMMANDS._serialized_end=3323
  _MAINPACKET._serialized_start=36
  _MAINPACKET._serialized_end=129
  _ADCSTATUS._serialized_start=132
  _ADCSTATUS._serialized_end=1431
  _ADCSTATUS_BOARDSTATUS._serialized_start=790
  _ADCSTATUS_BOARDSTATUS._serialized_end=1070
  _ADCSTATUS_BOARDSTATUS_CHANNELSTATUS._serialized_start=962
  _ADCSTATUS_BOARDSTATUS_CHANNELSTATUS._serialized_end=1070
  _ADCSTATUS_ENUMSTARTSOURCE._serialized_start=1072
  _ADCSTATUS_ENUMSTARTSOURCE._serialized_end=1159
  _ADCSTATUS_ENUMCLOCKSOURCE._serialized_start=1161
  _ADCSTATUS_ENUMCLOCKSOURCE._serialized_end=1220
  _ADCSTATUS_ENUMMEMORY._serialized_start=1222
  _ADCSTATUS_ENUMMEMORY._serialized_end=1272
  _ADCSTATUS_CONNECTORSIN._serialized_start=1275
  _ADCSTATUS_CONNECTORSIN._serialized_end=1431
  _AMPSTATUS._serialized_start=1434
  _AMPSTATUS._serialized_end=1571
  _AMPSTATUS_CONNECTORSIN._serialized_start=1500
  _AMPSTATUS_CONNECTORSIN._serialized_end=1526
  _AMPSTATUS_CONNECTORSOUT._serialized_start=1528
  _AMPSTATUS_CONNECTORSOUT._serialized_end=1571
  _HARDWARESTATUS._serialized_start=1574
  _HARDWARESTATUS._serialized_end=1708
  _JOURNALSTATUS._serialized_start=1711
  _JOURNALSTATUS._serialized_end=1888
  _TOKAMAKSTATUS._serialized_start=1891
  _TOKAMAKSTATUS._serialized_end=2071
  _TOKAMAKSTATUS_ENUMSHOT._serialized_start=2026
  _TOKAMAKSTATUS_ENUMSHOT._serialized_end=2071
  _GSASTATUS._serialized_start=2073
  _GSASTATUS._serialized_end=2148
  _SYSTEMSTATUS._serialized_start=2151
  _SYSTEMSTATUS._serialized_end=2787
  _SYSTEMSTATUS_ENUMSTATE._serialized_start=2311
  _SYSTEMSTATUS_ENUMSTATE._serialized_end=2382
  _SYSTEMSTATUS_ENUMDEV._serialized_start=2385
  _SYSTEMSTATUS_ENUMDEV._serialized_end=2558
  _SYSTEMSTATUS_CONNECTORSOUT._serialized_start=2560
  _SYSTEMSTATUS_CONNECTORSOUT._serialized_end=2616
  _SYSTEMSTATUS_CONNECTORSIN._serialized_start=2619
  _SYSTEMSTATUS_CONNECTORSIN._serialized_end=2787
  _SOURCE._serialized_start=2789
  _SOURCE._serialized_end=2907
  _RECEIVER._serialized_start=2909
  _RECEIVER._serialized_end=3029
  _BIND._serialized_start=3031
  _BIND._serialized_end=3118
# @@protoc_insertion_point(module_scope)
