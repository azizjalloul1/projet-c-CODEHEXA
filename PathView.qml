// PathView.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 6.7
import QtPositioning 6.7

ApplicationWindow {
    width: 900
    height: 600
    visible: true
    title: "Itinéraire vers l'établissement"

    property var fromCoord
    property var toCoord

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    RouteQuery {
        id: routeQuery
    }

    RouteModel {
        id: routeModel
        plugin: mapPlugin
        query: routeQuery
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        zoomLevel: 13
        center: fromCoord

        MapQuickItem {
            coordinate: fromCoord
            sourceItem: Rectangle {
                width: 16; height: 16; radius: 8
                color: "blue"
                border.color: "black"
            }
        }

        MapQuickItem {
            coordinate: toCoord
            sourceItem: Rectangle {
                width: 16; height: 16; radius: 8
                color: "red"
                border.color: "black"
            }
        }

        MapRoute {
            route: routeModel.get(0)
            line.color: "green"
            line.width: 4
            visible: routeModel.count > 0
        }
    }

    Component.onCompleted: {
        routeQuery.clearWaypoints()
        routeQuery.addWaypoint(fromCoord)
        routeQuery.addWaypoint(toCoord)
    }
}
