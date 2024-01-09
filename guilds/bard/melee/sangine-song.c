//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sanguine Song");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a song that sends out a sonic blast from their "
        "weapon that causes damage to a targeted enemy.");

    addPrerequisite("/guilds/bard/melee/melees-melody.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "long sword",
        "hand and a half sword", "two-handed sword", "axe",
        "dagger", "short sword", "hammer", "mace", "flail",
        "staff", "pole arm" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 13
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 25,
            "range": 50
        ]),
        ([
            "probability": 10,
            "base damage": 50,
            "range": 100
        ])
    }));

    addSpecification("damage type", "sonic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/melee-march.c",
            "name": "Melee March",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/soldiers-song.c",
            "name": "Soldier's Song",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/serenade-of-the-soldier.c",
            "name": "Serenade of the Soldier",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/arms-lament.c",
            "name": "Arm's Lament",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/footmans-ballad.c",
            "name": "Footman's Ballad",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/weapon-masters-tale.c",
            "name": "Weapon Master's Tale",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/lay-of-the-armsmaster.c",
            "name": "Lay of the Armsmaster",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name" : "sword",
            "types" : ({ "long sword", "hand and a half sword", 
                "two-handed sword", "axe", "dagger", "short sword", 
                "hammer", "mace", "flail", "staff", "pole arm" }),
            "formula" : "additive",
            "rate" : 0.5
        ]),
        ([
            "type":"highest skill",
            "name" : "sword skills",
            "skills": ({ "long sword", "hand and a half sword", 
                "two-handed sword", "axe", "dagger", "short sword", 
                "hammer", "mace", "flail", "staff", "pole arm" }),
            "formula" : "additive",
            "rate" : 0.5
        ]), 
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "mathematics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 120);
    addSpecification("spell point cost modifiers", ([
        "/guilds/bard/melee/rhythmic-riposte.c": 10,
        "/guilds/bard/melee/armsmans-form.c": 10,
        "/guilds/bard/melee/armsmans-breath.c": 10,
        "/guilds/bard/melee/minstrels-melee.c": 10
    ]));

    addSpecification("stamina point cost", 90);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/bard/melee/rhythmic-riposte.c":10,
        "/guilds/bard/melee/armsmans-form.c": 10,
        "/guilds/bard/melee/armsmans-breath.c": 10,
        "/guilds/bard/melee/minstrels-melee.c": 10
    ]));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/bard/melee/footmans-tune.c": 10,
        "/guilds/bard/melee/song-of-the-strong.c": 10,
        "/guilds/bard/melee/requiem-of-attack.c": 10,
        "/guilds/bard/melee/armsmasters-tale.c": 10,
    ]));

    addSpecification("event handler", "sanguineSongEvent");
    addSpecification("command template", "sanguine song [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::point## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## and ##Infinitive::sing##, "
        "`Blood. Blood and death. Tis thy time to face it...'");
}
