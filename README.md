# FT2SXR
The code to work with soft x-ray sprctral diagnostic on FT-2 tokamak in Ioffe Institute

!!! in the pipeline !!!

> This code is being developed by AVSidorov & MikhailButs for Kantor's Lab in Ioffe Institute to study spectrum of X-ray emition of FT-2 tokamak's thermonuclear plasma in Ioffe Institute St.Petersburg

Original repositories: https://github.com/AVSidorov/FT2SXR and https://github.com/AVSidorov/exam_adc

File to start programm: app4test.py
Google buffers must be installed to launch the programm

Current functions :
- control of fast ADC 250MHz, 14b by InSys with one-board computer inside
- control of PX-5 multi-channel analyser and Fast SSD X-ray detector by AMPTEK
- storage of HDF5 files with measured data and metadata
- ploting measured data
- shaped amplifier control
- control of ADC mezzanine module using InSys program with our modifications
