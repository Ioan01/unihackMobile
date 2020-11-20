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

        TextField {
            id: textField
            x: 91
            y: 155
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: textField1
            x: 90
            y: 280
            placeholderText: qsTr("Text Field")
        }

        Label {
            id: label
            x: 116
            y: 107
            width: 179
            height: 42
            text: qsTr("Username")
            font.pointSize: 24
        }

        Label {
            id: label1
            x: 116
            y: 232
            width: 179
            height: 42
            text: qsTr("Password")
            font.pointSize: 24
        }

        Image {
            id: sign_in_button
            x: 129
            y: 452
            width: 124
            height: 55
            source: "sign_in_button.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: quit_button
            x: 140
            y: 497
            anchors.fill: parent
            source: "quit_button.png"
            anchors.rightMargin: 147
            anchors.leftMargin: 128
            anchors.topMargin: 513
            anchors.bottomMargin: 8
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: login_button
            x: 75
            y: 361
            width: 233
            height: 69
            source: "login_button.png"
            fillMode: Image.PreserveAspectFit
        }
    }
    Connections{
        target: sign_in_button
        onClicked: stackView.push("RegisterScreenForm.ui.qml")
    }
    /*Connections{
        target:login_button
        onClicked:stackView.push("HomeForm.ui.qml")
    }*/

}
