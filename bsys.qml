import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    id: root
    color: 'transparent'

    ParticleSystem {
        id: particles
        anchors.fill: parent
        ImageParticle {
            id: flame
            anchors.fill: parent
            system: particles
            groups: ["C", "D"]
            source: "qrc:///particleresources/glowdot.png"
            colorVariation: 0.1
            color: "#00ff400f"
        }

        Emitter {
            id: fire
            system: particles
            group: "C"

            y: parent.height
            width: parent.width

            emitRate: 50
            lifeSpan: 6000
            lifeSpanVariation:3000
            velocity: AngleDirection {
                angle: 0
                angleVariation: 60
                magnitude: 200
                magnitudeVariation: 100
            }

            size: 24
            sizeVariation: 8
            endSize: 4
        }
    }
}
