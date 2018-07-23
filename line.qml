import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    id: root;
    width:100; height: 100
    color: 'transparent'
    ParticleSystem {
        id: particles
    }

    Emitter {
        id: emitter
        enabled:true
        anchors.centerIn : parent
        width: 1; height: 1
        system: particles
        emitRate: 10
        lifeSpan: 1000
        lifeSpanVariation: 500
        size: 16
        endSize: 32
        velocity: AngleDirection {
            angle: 0
            angleVariation: 360
            magnitude: 100
            magnitudeVariation: 50
        }

    }

    ItemParticle {
        system: particles
        delegate: Rectangle {
            id: rect
            width: 5
            height: 5
            color: "red"
            radius: 10
        }
    }
}
