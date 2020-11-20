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
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        transformOrigin: Item.Center

        Text {
            id: text1
            x: 118
            y: 20
            text: qsTr("Sign Up")
            font.pixelSize: 48
        }

        TextField {
            id: textField
            x: 102
            y: 132
            placeholderText: qsTr("Enter your username")
        }

        TextField {
            id: textField1
            x: 102
            y: 221
            placeholderText: qsTr("Enter your password")
        }

        Label {
            id: usernameLabel
            x: 126
            y: 84
            width: 149
            height: 42
            text: qsTr("Username")
            font.pointSize: 24
        }

        Label {
            id: registerLabel
            x: 134
            y: 173
            width: 132
            height: 42
            text: qsTr("Password")
            font.pointSize: 24
        }

        Button {
            id: button1
            x: 138
            y: 394
            width: 124
            height: 55
            visible: true
            text: qsTr("Button")
            display: AbstractButton.IconOnly

            Image {
                id: sign_in_button
                x: -12
                y: -6
                width: 148
                height: 65
                source: "sign_in_button.png"
                fillMode: Image.PreserveAspectFit
            }
        }

        Button {
            id: backbutton
            x: 151
            y: 480
            text: qsTr("")

            Image {
                id: back_button
                x: -31
                y: -8
                width: 163
                height: 57
                source: "back_button.png"
                fillMode: Image.PreserveAspectFit
            }
        }
    }

    TextField {
        id: textField2
        x: 100
        y: 311
        placeholderText: qsTr("Confirm your password")
    }

    Label {
        id: registerLabel1
        x: 73
        y: 263
        width: 254
        height: 42
        text: qsTr("Confirm password")
        font.pointSize: 24
    }
    Connections {
        target: backbutton
        onClicked: stackView.pop()
    }
    Connections {
        target: button1
<<<<<<< HEAD
        onClicked: {stackView.push("HomeForm.ui.qml")
            stackView.push("HomeForm.ui.qmll") //this pushes twice so that I can keep the toolbar hidden before logging in
=======
        onClicked: {stackView.push("ProfileForm.ui.qml")
            stackView.push("ProfileForm.ui.qml") //this pushes twice so that I can keep the toolbar hidden before logging in
>>>>>>> ACW--main

        }
    }
}
