import QtQuick 2.4
import QtQuick.Controls 2.12

Page {
    id: page
    width: 400
    height: 600

    Rectangle {
        id: rectangle
        width: 400
        color: "#d0d0d0"
        anchors.fill: parent

        transformOrigin: Item.Center

        Text {
            id: text1
            x: 128
            y: 14
            text: qsTr("Login")
            font.pixelSize: 48
        }

        TextField {
            id: textField
            x: 86
            y: 213
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: textField1
            x: 85
            y: 338
            placeholderText: qsTr("Text Field")
        }

        Label {
            id: label
            x: 111
            y: 165
            width: 179
            height: 42
            text: qsTr("Username")
            font.pointSize: 24
        }

        Label {
            id: label1
            x: 111
            y: 290
            width: 179
            height: 42
            text: qsTr("Password")
            font.pointSize: 24
        }

        Button {
            id: button
            x: 140
            y: 497
            width: 124
            height: 55
            visible: true
            text: qsTr("Button")
            display: AbstractButton.IconOnly

            Image {
                id: quit_button
                anchors.fill: parent
                source: "quit_button.png"
                anchors.bottomMargin: 0
                fillMode: Image.PreserveAspectFit
            }
        }

        Button {
            id: button1
            x: 138
            y: 424
            width: 124
            height: 55
            visible: true
            text: qsTr("Button")
            display: AbstractButton.IconOnly

            Image {
                id: sign_in_button
                x: 0
                y: 0
                width: 124
                height: 55
                source: "sign_in_button.png"
                fillMode: Image.PreserveAspectFit
            }
        }
    }
}
