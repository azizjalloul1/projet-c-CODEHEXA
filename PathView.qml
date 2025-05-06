import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    width: 1000
    height: 700
    property var etabModel: []
    QtObject {
        id: controller

        function updateRoute(fromLat, fromLon, toLat, toLon) {
            redRoute.path = [
                QtPositioning.coordinate(fromLat, fromLon),
                QtPositioning.coordinate(toLat, toLon)
            ]
            mapView.center = QtPositioning.coordinate(fromLat, fromLon)
            mapView.zoomLevel = 13
        }
    }
    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        zoomLevel: 10
        center: fromCoord  // ✅ centré sur Esprit Ariana

        // Trait rouge simple
        MapPolyline {
            line.width: 4
            line.color: "red"
            path: [
                fromCoord,
                toCoord
            ]
        }

        // Position utilisateur (Esprit Ariana)
        MapQuickItem {
            coordinate: fromCoord
            anchorPoint.x: 12
            anchorPoint.y: 12
            sourceItem: Rectangle {
                width: 24; height: 24
                color: "green"
                radius: 12
            }
        }

        // Établissement sélectionné
        MapQuickItem {
            coordinate: toCoord
            anchorPoint.x: 12
            anchorPoint.y: 12
            sourceItem: Rectangle {
                width: 24; height: 24
                color: "blue"
                radius: 12
            }
        }
    }
    PinchArea {
        anchors.fill: parent
        pinch.target: mapView
        onPinchUpdated: mapView.zoomLevel += Math.log(pinch.scale) / Math.log(2)

        MouseArea {
            anchors.fill: parent
            drag.target: draggable

            property int lastX: 0
            property int lastY: 0

            onPressed: {
                lastX = mouse.x
                lastY = mouse.y
            }

            onPositionChanged: {
                if (pressed) {
                    var dx = mouse.x - lastX
                    var dy = mouse.y - lastY
                    mapView.pan(-dx, -dy)
                    lastX = mouse.x
                    lastY = mouse.y
                }
            }

            Item { id: draggable }
        }
    }

    Button {
        id: zoomInButton
        text: "+"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10
        width: 40
        height: 40
        onClicked: mapView.zoomLevel += 1
    }

    Button {
        id: zoomOutButton
        text: "-"
        anchors.right: parent.right
        anchors.top: zoomInButton.bottom
        anchors.margins: 10
        width: 40
        height: 40
        onClicked: mapView.zoomLevel -= 1
    }
}
