# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'GSAUIDesign.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_GSAWidgetDesign(object):
    def setupUi(self, GSAWidgetDesign):
        GSAWidgetDesign.setObjectName("GSAWidgetDesign")
        GSAWidgetDesign.resize(300, 153)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(GSAWidgetDesign.sizePolicy().hasHeightForWidth())
        GSAWidgetDesign.setSizePolicy(sizePolicy)
        GSAWidgetDesign.setMinimumSize(QtCore.QSize(250, 70))
        self.verticalLayout = QtWidgets.QVBoxLayout(GSAWidgetDesign)
        self.verticalLayout.setSizeConstraint(QtWidgets.QLayout.SetMaximumSize)
        self.verticalLayout.setObjectName("verticalLayout")
        self.groupBox = QtWidgets.QGroupBox(GSAWidgetDesign)
        self.groupBox.setObjectName("groupBox")
        self.gridLayout = QtWidgets.QGridLayout(self.groupBox)
        self.gridLayout.setObjectName("gridLayout")
        self.amplitude_label = QtWidgets.QLabel(self.groupBox)
        self.amplitude_label.setObjectName("amplitude_label")
        self.gridLayout.addWidget(self.amplitude_label, 0, 0, 1, 1)
        self.amp_comboBox = QtWidgets.QComboBox(self.groupBox)
        self.amp_comboBox.setObjectName("amp_comboBox")
        self.gridLayout.addWidget(self.amp_comboBox, 0, 1, 1, 1)
        self.amp_type_label = QtWidgets.QLabel(self.groupBox)
        self.amp_type_label.setObjectName("amp_type_label")
        self.gridLayout.addWidget(self.amp_type_label, 0, 2, 1, 1)
        self.edge_label = QtWidgets.QLabel(self.groupBox)
        self.edge_label.setObjectName("edge_label")
        self.gridLayout.addWidget(self.edge_label, 1, 0, 1, 1)
        self.edge_val_label = QtWidgets.QLabel(self.groupBox)
        self.edge_val_label.setObjectName("edge_val_label")
        self.gridLayout.addWidget(self.edge_val_label, 1, 1, 1, 1)
        self.edge_type_label = QtWidgets.QLabel(self.groupBox)
        self.edge_type_label.setObjectName("edge_type_label")
        self.gridLayout.addWidget(self.edge_type_label, 1, 2, 1, 1)
        self.freq_label = QtWidgets.QLabel(self.groupBox)
        self.freq_label.setObjectName("freq_label")
        self.gridLayout.addWidget(self.freq_label, 2, 0, 1, 1)
        self.freq_val_label = QtWidgets.QLabel(self.groupBox)
        self.freq_val_label.setObjectName("freq_val_label")
        self.gridLayout.addWidget(self.freq_val_label, 2, 1, 1, 1)
        self.freq_type_label = QtWidgets.QLabel(self.groupBox)
        self.freq_type_label.setObjectName("freq_type_label")
        self.gridLayout.addWidget(self.freq_type_label, 2, 2, 1, 1)
        self.verticalLayout.addWidget(self.groupBox)

        self.retranslateUi(GSAWidgetDesign)
        QtCore.QMetaObject.connectSlotsByName(GSAWidgetDesign)

    def retranslateUi(self, GSAWidgetDesign):
        _translate = QtCore.QCoreApplication.translate
        GSAWidgetDesign.setWindowTitle(_translate("GSAWidgetDesign", "GSA"))
        self.groupBox.setTitle(_translate("GSAWidgetDesign", "ГСА"))
        self.amplitude_label.setText(_translate("GSAWidgetDesign", "Амплитуда импульса"))
        self.amp_type_label.setText(_translate("GSAWidgetDesign", "mV"))
        self.edge_label.setText(_translate("GSAWidgetDesign", "Фронт"))
        self.edge_val_label.setText(_translate("GSAWidgetDesign", "0"))
        self.edge_type_label.setText(_translate("GSAWidgetDesign", "ns"))
        self.freq_label.setText(_translate("GSAWidgetDesign", "Частота"))
        self.freq_val_label.setText(_translate("GSAWidgetDesign", "0"))
        self.freq_type_label.setText(_translate("GSAWidgetDesign", "Hz"))
