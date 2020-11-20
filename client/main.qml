import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Stack")

    header: ToolBar {
        id:toolBar
        contentHeight: toolButton.implicitHeight
        visible: stackView.depth >2 ? 1 : 0 // + sa verifice si pentru sign in
        ToolButton {
            id: toolButton
            text: "\u2630"
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
                onClicked: {
                    stackView.pop()
                    stackView.push("ProfileForm.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Lectures")
                width: parent.width
                onClicked: {
                    stackView.pop()
                    stackView.push("LecturesForm.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Exams")
                width: parent.width
                onClicked: {
                    stackView.pop()
                    stackView.push("ExamsForm.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Grades")
                width: parent.width
                onClicked: {
                    stackView.pop()
                    stackView.push("GradesForm.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Settings")
                width: parent.width
                onClicked: {
                    stackView.pop()
                    stackView.push("SettingsForm.ui.qml")
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
