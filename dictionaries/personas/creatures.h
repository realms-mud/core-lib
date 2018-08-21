//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping creatureBlueprints = ([
    "basilisk":([
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
