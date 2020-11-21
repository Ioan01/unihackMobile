import QtQuick 2.4
import QtQuick.Controls 2.5

Page {
    width: 400
    height:600
    title: qsTr("Home page")

    TextField {
        id: searchBar
        x: 100
        y: 31
        placeholderText: qsTr("Search")
    }
    ListModel {
        id: newLecturesModel

        ListElement {
            category: "First new lecture:"
            //value://to be set after server initialization
        }
        ListElement {
            category: "Second new lecture:"
            //value://to be set after server initialization
        }
        ListElement {
            category: "Third new lecture:"
            //value: //to be set after server initialization
        }

        ListElement {
            category: "Fourth new lecture:"
            //value: //to be set after server initialization
        }

        ListElement {
            category: "Fifth new lecture:"
            //value: //to be set after server initialization
        }
        ListElement {
            category: "Sixth new lecture:"
            //value: //to be set after server initialization
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        anchors.leftMargin: 100
        anchors.topMargin: 98
        anchors.rightMargin: 100
        anchors.bottomMargin: 22
        model: newLecturesModel

        delegate: ItemDelegate {

            spacing: 10
            text: category
            width: searchBar.width
            highlighted: ListView.currentItem
            //to be set after server initialization
        }
    }



}
