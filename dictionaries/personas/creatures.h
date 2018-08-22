//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping creatureBlueprints = ([
    "basilisk":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "fangs": 15,
        ]),
        "special attacks": ([
            "poison": 25,
            "paralysis": 10,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "bat":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "bear":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "fangs": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "boar":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "tusk": 10,
            "fangs": 5,
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "cat":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "panther":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 6,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "fangs": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "mountain lion":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 6,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "fangs": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "chimera":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 25,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "breath weapons": ([
            "fire": 25,
            "electricity": 25,
            "acid": 25,
            "cold": 25,
        ]),
        "base hit points": 250,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "cockatrice":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "beak": 15,
        ]),
        "special attacks": ([
            "paralysis": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "dog":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "attacks": ([
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "eagle":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 3,
        "attacks": ([
            "talon": 5,
            "beak": 10,
        ]),
        "base hit points": 20,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "raven":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 2,
        "attacks": ([
            "talon": 3,
            "beak": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "gargoyle":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "talon": 10,
            "talon": 10,
            "fangs": 15,
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "ghoul":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "lib/modules/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 10,
            "undead": 10,
        ]),
        "special attacks": ([
            "paralysis": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "ghast":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 8,
        "attacks": ([
            "claw": 10,
            "undead": 15,
        ]),
        "special attacks": ([
            "disease": 25,
        ]),
        "base hit points": 35,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "gorgon":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
            "fire": 20
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "fire elemental":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "fire": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "air elemental":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "electricity": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "earth elemental":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "earth": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "water elemental":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "water": 10,
            "cold": 5,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "chaos wisp":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "chaos": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "ice wisp":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "cold": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "will-o-wisp":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "energy": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "aura wisp":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "magical": 10,
        ]),
        "base hit points": 40,
        "base spell points" : 40,
        "base stamina points" : 50
    ]),
    "griffon":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "beak": 15,
            "wing": 10,
        ]),
        "base hit points": 175,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "harpy":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "wing": 10,
        ]),
        "base hit points": 125,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "hell hound":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 7,
        "attacks": ([
            "claw": 5,
            "fangs": 5,
            "fire": 5,
        ]),
        "base hit points": 100,
        "base spell points" : 50,
        "base stamina points" : 100
    ]),
    "homunculus":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "fangs": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "hydra":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "fangs": 10,
            "fangs" : 10,
            "fangs" : 10,
        ]),
        "base hit points": 250,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "kraken":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "tentacle": 10,
            "tentacle": 10,
            "fangs": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "lich":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor", "staff" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "staffs" }),
            "armor/accessories": ({ "ring", "bracers" })
        ]),
        "minimum level": 25,
        "attacks": ([
            "undead": 25,
            "undead": 25,
            "cold": 35,
        ]),
        "base hit points": 150,
        "base spell points" : 250,
        "base stamina points" : 100
    ]),
    "manticore":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 12,
        "attacks": ([
            "claw": 10,
            "fangs": 10,
            "wing" : 10,
            "tail" : 10,
        ]),
        "base hit points": 150,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "air mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "air": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "earth mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "earth": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "chaos mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "chaos": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "ice mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "cold": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "storm mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "electricity": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "blast mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "energy": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "flame mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "fire": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "aether mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "magical": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "psy mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "psionic": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "sonic mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "sonic": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "water mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "water": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "sear mephit":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 5,
            "acid": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 20,
        "base stamina points" : 20
    ]),
    "mohrg":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "undead": 20,
        ]),
        "special attacks": ([
            "paralysis": 5,
        ]),
        "base hit points": 50,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "mummy":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 12,
        "attacks": ([
            "undead": 15,
            "undead": 15,
        ]),
        "special attacks": ([
            "disease": 35,
        ]),
        "base hit points": 100,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "naga":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 15,
            "claw": 15,
        ]),
        "special attacks": ([
            "poison": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "night hag":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "special attacks": ([
            "disease": 15,
        ]),
        "base hit points": 100,
        "base spell points" : 50,
        "base stamina points" : 100
    ]),
    "marsh hag":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "special attacks": ([
            "enfeebled": 15,
        ]),
        "base hit points": 100,
        "base spell points" : 50,
        "base stamina points" : 100
    ]),
    "sea hag":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "special attacks": ([
            "slow": 15,
        ]),
        "base hit points": 100,
        "base spell points" : 50,
        "base stamina points" : 100
    ]),
    "horse":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "hoof": 10,
        ]),
        "base hit points": 50,
        "base spell points" : 0,
        "base stamina points" : 150
    ]),
    "nightmare":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 8,
        "attacks": ([
            "hoof": 10,
            "fire": 10,
        ]),
        "base hit points": 60,
        "base spell points" : 0,
        "base stamina points" : 150
    ]),
    "owlbear":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "beak": 20,
        ]),
        "base hit points": 175,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "pegasus":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "hoof": 10,
            "wing": 10,
            "magical": 10
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "phoenix":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "beak": 10,
            "claw": 10,
            "fire": 10,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "rat":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "attacks": ([
            "claw": 2,
            "claw": 2,
            "fangs": 2,
        ]),
        "special attacks": ([
            "disease": 1,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "sea serpent":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "fangs": 25,
            "tail" : 10,
        ]),
        "base hit points": 250,
        "base spell points" : 100,
        "base stamina points" : 100
    ]),
    "shadow":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "lib/modules/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "undead": 10,
            "undead": 10,
        ]),
        "special attacks": ([
            "enfeebled": 1,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "skeleton":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor", "axe", "mace", "hammer", "flail", "staff",
            "pole arm", "archer" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces", "hammers",
                "flails", "bows", "daggers", "staffs",
                "pole-arms" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "minimum level": 3,
        "attacks": ([
            "undead": 5,
        ]),
        "base hit points": 25,
        "base spell points" : 0,
        "base stamina points" : 25
    ]),
    "spectre":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "lib/modules/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "undead": 10,
            "undead": 10,
        ]),
        "base hit points": 35,
        "base spell points" : 0,
        "base stamina points" : 35
    ]),
    "giant spider":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "claw": 10,
            "fangs": 25,
        ]),
        "special attacks": ([
            "poison": 20,
        ]),
        "base hit points": 100,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "tarrasque":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "claw": 10,
            "claw": 10,
            "fangs": 25,
            "tail": 15,
        ]),
        "base hit points": 250,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "terlang":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "chainmail", "scalemail", 
            "hard leather", "soft leather", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "light-armor", "medium-armor" }),
        ]),
        "minimum level": 5,
        "attacks": ([
            "talon": 10,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "treant":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 20,
        "attacks": ([
            "unarmed": 35,
            "unarmed": 35,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "troglodyte":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 10,
        "attacks": ([
            "unarmed": 15,
            "unarmed": 15,
        ]),
        "base hit points": 70,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
    "unicorn":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 15,
        "attacks": ([
            "hoof": 10,
            "horn": 20,
            "magical": 15,
        ]),
        "base hit points": 150,
        "base spell points" : 200,
        "base stamina points" : 100
    ]),
    "wolf":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 3,
        "attacks": ([
            "claw": 6,
            "fangs": 10,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "wolverine":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 2,
        "attacks": ([
            "claw": 5,
            "claw": 5,
            "fangs": 7,
        ]),
        "base hit points": 20,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "weasel":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 1,
        "attacks": ([
            "claw": 3,
            "claw": 3,
            "fangs": 5,
        ]),
        "base hit points": 10,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "warg":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "minimum level": 5,
        "attacks": ([
            "claw": 10,
            "fangs": 15,
        ]),
        "base hit points": 30,
        "base spell points" : 0,
        "base stamina points" : 50
    ]),
    "vampire":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "swords" }),
        ]),
        "minimum level": 15,
        "attacks": ([
            "undead": 10,
            "undead": 10,
            "cold": 10,
        ]),
        "base hit points": 150,
        "base spell points" : 250,
        "base stamina points" : 100
    ]),
    "wight":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "lib/modules/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 6,
        "attacks": ([
            "claw": 10,
            "undead": 12,
        ]),
        "special attacks": ([
            "paralysis": 5,
        ]),
        "base hit points": 35,
        "base spell points" : 35,
        "base stamina points" : 35
    ]),
    "zombie":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor", "axe", "mace", "hammer", "flail", "staff",
            "pole arm", "archer" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({}),
        "potential traits" : ({}),
        "equipment": ([ 
            "weapons":({ "swords", "axes", "maces", "hammers",
                "flails", "bows", "daggers", "staffs",
                "pole-arms" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "minimum level": 3,
        "attacks": ([
            "undead": 5,
        ]),
        "base hit points": 25,
        "base spell points" : 0,
        "base stamina points" : 25
    ]),
    "wraith":([
        "category": "creatures",
        "primary skills":({ "parry", "dodge", "no armor" }),
        "secondary skills" : ({ "perception", "listen", "spot" }),
        "traits" : ({ "lib/modules/traits/effects/ethereal" }),
        "potential traits" : ({}),
        "minimum level": 12,
        "attacks": ([
            "claw": 10,
            "undead": 15,
            "undead": 15,
        ]),
        "special attacks": ([
            "paralysis": 5,
        ]),
        "base hit points": 150,
        "base spell points" : 0,
        "base stamina points" : 100
    ]),
]);
