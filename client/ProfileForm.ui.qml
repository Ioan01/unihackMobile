import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Controls.Imagine 2.3

Page {
    width: 400
    height: 900

    RoundButton {
        id: roundButton
        x: 237
        y: 132
        width: 141
        height: 138
        text: "Upload an image"
        highlighted: true
        autoRepeat: false
        checkable: false
        checked: false
        font.bold: false
        font.pointSize: 14
    }

    TextField {
        id: textField
        x: 37
        y: 276
        placeholderText: "Your name here"
    }

    RadioButton {
        id: radioButton
        x: 37
        y: 322
        text: qsTr("Lecturer")
    }

    RadioButton {
        id: radioButton1
        x: 37
        y: 360
        text: qsTr("Student")
    }

    Text {
        id: text1
        x: 37
        y: 160
        width: 133
        height: 56
        text: qsTr("Profile")
        font.pixelSize: 48
    }

    Label {
        id: label
        x: 37
        y: 434
        width: 200
        height: 80
        text: qsTr("Member since 22/11/2020")
        wrapMode: Text.WordWrap
        font.pointSize: 18
    }

    Label {
        id: label1
        x: 37
        y: 508
        width: 133
        height: 34
        text: qsTr("Rating: 0")
        wrapMode: Text.WordWrap
        font.pointSize: 18
    }

    Label {
        id: label2
        x: 37
        y: 563
        width: 133
        height: 34
        text: qsTr("Lectures:")
        wrapMode: Text.WordWrap
        font.pointSize: 18
    }

    Row {
        id: row
        x: 37
        y: 603
        width: 200
        height: 215
    }
}

/*##^##
Designer {
    D{i:1}D{i:9;annotation:"1 //;;// Lectures //;;//  //;;// <!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html> //;;// 1605984281";customId:""}
}
##^##*/
