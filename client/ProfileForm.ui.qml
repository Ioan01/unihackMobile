import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    font.family: "Arial"

    title: qsTr("Profile")

    ListModel {
        id: detailsModel

        ListElement {
            category: "Username:"
            //value://to be set after server initialization
        }
        ListElement {
            category: "First name:"
            //value://to be set after server initialization
        }
        ListElement {
            category: "Last name:"
            //value: //to be set after server initialization
        }
        ListElement {
            category: "General mean:"
            //value: //to be set after server initialization
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        anchors.rightMargin: 301
        anchors.bottomMargin: 14
        model: detailsModel
        delegate: Row {

            spacing: 10
            Text {
                font.pixelSize: 15
                text: category /*+value*/
            } //to be set after server initialization
        }
    }

    Button {
        id: logOutButton
        x: 280
        y: 13
        width: 91
        height: 34
        text: qsTr("Log Out")
        display: AbstractButton.TextBesideIcon
        font.pointSize: 13
    }
    Connections {
        target: logOutButton
        onClicked: {
            stackView.push("LoginScreenForm.ui.qml")
            stackView.push("LoginScreenForm.ui.qml")
        }
    }
}
