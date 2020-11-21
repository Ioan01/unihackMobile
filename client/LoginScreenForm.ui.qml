import QtQuick 2.4
import QtQuick.Controls 2.12

Page {
    id: page
    width: 400
    height: 900

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

        TextField {
            id: textField
            x: 101
            y: 209
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: textField1
            x: 101
            y: 359
            placeholderText: qsTr("Text Field")
        }

        Label {
            id: label
            x: 130
            y: 140
            width: 141
            height: 42
            text: qsTr("Username")
            font.pointSize: 24
        }

        Label {
            id: label1
            x: 134
            y: 293
            width: 132
            height: 42
            text: qsTr("Password")
            font.pointSize: 24
        }

        Button {
            id: button1
            x: 138
            y: 564
            width: 124
            height: 55
            visible: true
            text: qsTr("Button")
            display: AbstractButton.IconOnly

            Image {
                id: sign_in_button
                x: -11
                y: -5
                width: 146
                height: 66
                source: "sign_in_button.png"
                fillMode: Image.PreserveAspectFit
            }
        }

        Button {
            id: button2
            x: 150
            y: 445
            text: qsTr("")

            Image {
                id: login_button
                x: -56
                y: -21
                width: 213
                height: 81
                source: "login_button.png"
                fillMode: Image.PreserveAspectFit
            }
        }
    }
    Connections {
        target: button1
        onClicked: stackView.push("RegisterScreenForm.ui.qml")
    }

    Connections {
        target: button2
        onClicked: {
            stackView.push("Page1Form.ui.qml")
            stackView.push(
                        "Page1Form.ui.qml") //this pushes twice so that I can keep the toolbar hidden before logging in
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
