import QtQuick 2.4
import QtQuick.Controls 2.15

Page {
    width: 400
    height: 400

    TextField {
        id: textField
        x: 94
        y: 86
        placeholderText: qsTr("Enter your username here")
    }

    Label {
        id: label
        x: 154
        y: 30
        width: 80
        height: 25
        text: qsTr("Register")
        font.pointSize: 15
    }

    TextField {
        id: textField1
        x: 94
        y: 154
        placeholderText: qsTr("Enter your password here")
    }

    Label {
        id: label1
        x: 94
        y: 67
        text: qsTr("Username:")
        font.pointSize: 10
    }

    Label {
        id: label2
        x: 94
        y: 132
        text: qsTr("Password:")
        font.pointSize: 10
    }

    TextField {
        id: textField2
        x: 94
        y: 222
        placeholderText: qsTr("Confirm your password")
    }

    Label {
        id: label3
        x: 94
        y: 200
        text: qsTr("Confirm Password:")
        font.pointSize: 10
    }

    Button {
        id: button
        x: 144
        y: 276
        width: 100
        height: 36
        text: qsTr("Register")
        checked: false
        display: AbstractButton.TextBesideIcon
    }
}
