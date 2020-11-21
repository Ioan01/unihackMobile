import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: window
    width: 400
    height: 900

    visible: true
    title: qsTr("Stack")

    header: ToolBar {
        id:toolBar
        contentHeight: toolButton.implicitHeight
        visible: stackView.depth >2 ? 1 : 0 // + sa verifice si pentru sign in
        ToolButton {
            id: toolButton
            text: "Menu"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if(stackView.top==="RegisterScreenForm.ui.qml")
                    stackView.pop()
                else
                    drawer.open()

            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Profile")
                width: parent.width
                height:100
                onClicked: {
                    stackView.pop()
                    stackView.push("ProfileForm.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Lectures")
                width: parent.width
                height:100
                onClicked: {
                    stackView.pop()
                    stackView.push("Lectures.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Practice")
                width: parent.width
                height:100
                onClicked: {
                    stackView.pop()
                    stackView.push("Page2Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Your progress")
                width: parent.width
                height:100
                onClicked: {
                    stackView.pop()
                    stackView.push("Page2Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Settings")
                width: parent.width
                height:100
                onClicked: {
                    stackView.pop()
                    stackView.push("Page2Form.ui.qml")
                    drawer.close()
                }
            }
       }
    }

    StackView {
        id: stackView
        initialItem: "LoginScreenForm.ui.qml"
        anchors.fill: parent
    }


}
