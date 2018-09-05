//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping dragonBlueprints = ([
    "white dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "ice breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "red dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "fire breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "blue dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental air" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "lightning breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "black dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "acid breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "gray dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental earth" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "tempest breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "brown dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental earth" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "shard breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "green dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "destruction", "plant" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "fire breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "purple dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "mind" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "destruction", "spirit" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "psionic blast": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "gold dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "magical essence", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "fire breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "silver dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental air" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "magical essence", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "lightning breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "bronze dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "magical essence", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "ice breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "crimson dragon":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "blood" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 35,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 25,
        ]),
        "research": ([
            "enervation breath": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "fire drake":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 15,
        ]),
        "research": ([
            "fire breath": 20,
        ]),
        "base hit points": 200,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "ice drake":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental water" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 15,
        ]),
        "research": ([
            "ice breath": 20,
        ]),
        "base hit points": 200,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "storm drake":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental air" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "wing": 10,
            "tail": 10,
            "fangs": 15,
        ]),
        "research": ([
            "lightning breath": 20,
        ]),
        "base hit points": 200,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "fire wyrm":([
        "category": "dragons",
        "primary skills":({ "parry", "dodge", "no armor", "elemental fire" }),
        "secondary skills" : ({ "perception", "listen", "spot",
            "destruction", "evocation" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "tail": 10,
            "fangs": 15,
        ]),
        "research": ([
            "fire breath": 20,
        ]),
        "base hit points": 200,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
]);
