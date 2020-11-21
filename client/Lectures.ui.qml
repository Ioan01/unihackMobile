import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 400
    height: 900

    title: qsTr("Lectures")

    Rectangle {
        id: rectangle
        x: 22
        y: 95
        width: 357
        height: 760
        color: "#bebdbd"
        border.color: "#000000"

        Column {
            id: column
            x: 8
            y: 29
            width: 200
            height: 400

            Label {
                id: label1
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24

            }
            Label {
                id: label2
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24

            }
            Label {
                id: label3
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24

            }
            Label {
                id: label4
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24

            }
            Label {
                id: label5
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24
            }
            Label {
                id: label6
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24
            }
            Label {
                id: label7
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24
            }
            Label {
                id: label8
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24
            }
            Label {
                id: label9
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24
            }
            Label {
                id: label10
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24
            }
            Label {
                id: label11
                text: qsTr("Label")
                wrapMode: Text.WordWrap
                font.pointSize: 24
            }
        }
    }

    Label {
        id: label
        x: 22
        y: 12
        text: qsTr("Lectures")
        font.pointSize: 48
    }
}
