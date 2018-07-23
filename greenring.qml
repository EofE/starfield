import QtQuick 2.0

Rectangle {
    id:root
    color: 'transparent'
    Image {
        id: image
        source: "greenring.png"
        width: parent.width
        height: parent.height
    }

    NumberAnimation {
        running: true
        loops: Animation.Infinite
        target: image
        from: 0
        to: 360
        property: "rotation"
        duration: 3000
    }
}
