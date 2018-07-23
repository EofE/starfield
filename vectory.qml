import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    id: root;
    color: 'transparent'
    ParticleSystem {
        id: particles
    }

    Emitter {
        id: emitter
        enabled:true
        anchors.centerIn : parent
        width: 1
        height: 1
        system: particles
        emitRate: 100
        lifeSpan: 10000
        lifeSpanVariation: 5000
        size: 16
        endSize: 32
        velocity: AngleDirection {
            angle: 0
            angleVariation: 360
            magnitude: 200
            magnitudeVariation: 100
        }

    }

    ItemParticle {
        system: particles
        delegate: Rectangle {
            id: rect
            width: 3
            height: 3
            color: "red"
            radius: 10
        }
    }
}
