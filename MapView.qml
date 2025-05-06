import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 6.7
import QtPositioning 6.7

Rectangle {
    width: 800
    height: 600

<<<<<<< HEAD
=======
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

>>>>>>> origin/gestionetablissement
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

<<<<<<< HEAD
=======
    // Route Query et Model
    RouteQuery {
        id: routeQuery
    }

    RouteModel {
        id: routeModel
        plugin: mapPlugin
        query: routeQuery
    }
    MapPolyline {
        id: redRoute
        line.width: 5
        line.color: "red"
        path: []
        visible: path.length > 1
    }

>>>>>>> origin/gestionetablissement
    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
<<<<<<< HEAD
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
=======
        center: QtPositioning.coordinate(36.8065, 10.1815)
        zoomLevel: 10
        copyrightsVisible: false

        // Affichage des établissements
        Repeater {
            model: etabModel

            MapQuickItem {
                coordinate: QtPositioning.coordinate(modelData.latitude, modelData.longitude)
                anchorPoint.x: 15
                anchorPoint.y: 45

                sourceItem: Column {
                    spacing: 2
                    anchors.centerIn: parent

                    Image {
                        source: "qrc:/marker.png"
                        width: 30
                        height: 30
                    }

                    Text {
                        text: modelData.nom
                        font.pixelSize: 12
                        color: "black"
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }
        }

        // Affichage de la route
        MapRoute {
            id: routeItem
            route: routeModel.get(0)
            line.width: 5
            line.color: "blue"
            visible: routeModel.count > 0  // ✅ important pour affichage conditionnel
        }

    }

    // Marqueur position actuelle
    MapQuickItem {
        id: userLocationMarker
        objectName: "userLocationMarker"
        coordinate: QtPositioning.coordinate(36.899, 10.19)
        anchorPoint.x: 12
        anchorPoint.y: 24

        sourceItem: Column {
            spacing: 2
            Image {
                source: "qrc:/user.png"
                width: 30
                height: 30
            }
            Text {
                text: "Vous"
                color: "blue"
                font.pixelSize: 10
                horizontalAlignment: Text.AlignHCenter
>>>>>>> origin/gestionetablissement
            }
        }
    }

<<<<<<< HEAD
    PinchArea {
        anchors.fill: parent
        pinch.target: mapView
        onPinchUpdated: {
            mapView.zoomLevel += Math.log(pinch.scale) / Math.log(2)
        }
=======
    // Zoom / Drag
    PinchArea {
        anchors.fill: parent
        pinch.target: mapView
        onPinchUpdated: mapView.zoomLevel += Math.log(pinch.scale) / Math.log(2)
>>>>>>> origin/gestionetablissement

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

<<<<<<< HEAD
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
=======
    function setPinLocation(latitude, longitude) {
        mapView.center = QtPositioning.coordinate(latitude, longitude)
        mapView.zoomLevel = 15
    }

    function addSingleMarker(latitude, longitude, nom) {
        for (let i = mapView.children.length - 1; i >= 0; i--) {
            let child = mapView.children[i]
            if (child.objectName === "dynamicMarker") {
                mapView.removeMapItem(child)
            }
        }

        let marker = Qt.createQmlObject(`
            import QtQuick 2.15
            import QtLocation 5.15
            import QtPositioning 5.15

            MapQuickItem {
                objectName: "dynamicMarker"
                coordinate: QtPositioning.coordinate(${latitude}, ${longitude})
                anchorPoint.x: 12
                anchorPoint.y: 24

                sourceItem: Column {
                    spacing: 2
                    Image {
                        source: "qrc:/marker.png"
                        width: 30
                        height: 30
                    }
                    Text {
                        text: "${nom}"
                        color: "black"
                        font.pixelSize: 10
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }
        `, mapView)

        mapView.addMapItem(marker)
        mapView.center = QtPositioning.coordinate(latitude, longitude)
        mapView.zoomLevel = 15
    }
    function setRoute(coordList) {
        if (coordList.length < 2)
            return;

        var from = QtPositioning.coordinate(coordList[0].latitude, coordList[0].longitude)
        var to = QtPositioning.coordinate(coordList[1].latitude, coordList[1].longitude)

        // Ligne rouge droite
        redRoute.path = [from, to]

        // Route calculée (sans travelMode)
        routeQuery.clearWaypoints()
        routeQuery.addWaypoint(from)
        routeQuery.addWaypoint(to)

        routeModel.update() // fonctionne sans travelMode

        // Centrer entre les 2
        var midLat = (from.latitude + to.latitude) / 2
        var midLon = (from.longitude + to.longitude) / 2
        mapView.center = QtPositioning.coordinate(midLat, midLon)
        mapView.zoomLevel = 13
    }




>>>>>>> origin/gestionetablissement
}
