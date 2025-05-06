import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 6.7
import QtPositioning 6.7

Rectangle {
    width: 800
    height: 600

    Plugin {
        id: mapPlugin
        name: "osm"

        PluginParameter { name: "osm.mapping.provider"; value: "custom" }
        PluginParameter { name: "osm.mapping.custom.enabled"; value: true }
        PluginParameter {
            name: "osm.mapping.custom.host"
            value: "https://basemaps.cartocdn.com/light_all/${z}/${x}/${y}.png"
        }
        PluginParameter { name: "osm.mapping.cache.directory"; value: "carto_cache" }
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(36.850, 10.150)
        zoomLevel: 15
        copyrightsVisible: false

        MapQuickItem {
            id: pinMarker
            anchorPoint.x: markerImage.width / 2
            anchorPoint.y: markerImage.height
            coordinate: QtPositioning.coordinate(0, 0)
            visible: false  // Hide by default
            sourceItem: Image {
                id: markerImage
                source: "marker.png"  // Make sure marker.png is in same folder as the QML file
                width: 32
                height: 32
            }
        }
    }

    PinchArea {
        anchors.fill: parent
        pinch.target: mapView
        onPinchUpdated: {
            mapView.zoomLevel += Math.log(pinch.scale) / Math.log(2)
        }

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

    Text {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 10
        text: "© OpenStreetMap contributors, © CARTO"
        color: "black"
        font.pixelSize: 12
        z: 1

        Rectangle {
            anchors.fill: parent
            anchors.margins: -3
            color: "white"
            opacity: 0.7
            z: -1
        }
    }

    // ✅ Set and show the marker
    function setPinLocation(lat, lon) {
        var coord = QtPositioning.coordinate(lat, lon)
        mapView.center = coord
        pinMarker.coordinate = coord
        pinMarker.visible = true
        mapView.zoomLevel = 16
    }
}
