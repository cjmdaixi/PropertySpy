import QtQuick 2.6
import QtQuick.Controls 1.5
import PropertySpy 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    PropertySpy{
        id: propSpy
    }

    Rectangle{
        id: rect
        anchors.centerIn: parent
        color: "red"
        width: 100
        height: 50
        radius: 8

        MouseArea{
            anchors.fill: parent
            id: mouseArea

            Component.onCompleted: propSpy.spy(mouseArea)
        }
    }
}
