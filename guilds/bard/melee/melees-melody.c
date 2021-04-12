//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Melee's Melody");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a song that sends out a sonic wave from their "
        "weapon that causes damage to a targeted enemy.");

    addPrerequisite("/guilds/bard/melee/root.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "long sword",
        "hand and a half sword", "two-handed sword", "axe",
        "dagger", "short sword", "hammer", "mace", "flail",
        "staff", "pole arm" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 1
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 5,
            "range": 10
        ]),
        ([
            "probability": 10,
            "base damage": 15,
            "range": 30
        ])
    }));

    addSpecification("damage type", "sonic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/melee-march.c",
            "name": "melee-march",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/soldiers-song.c",
            "name": "soldiers-song",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/serenade-of-the-soldier.c",
            "name": "serenade-of-the-soldier",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/arms-lament.c",
            "name": "arms-lament",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/footmans-ballad.c",
            "name": "footmans-ballad",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/weapon-masters-tale.c",
            "name": "weapon-masters-tale",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/melee/lay-of-the-armsmaster.c",
            "name": "lay-of-the-armsmaster",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "weapon damage",
            "name" : "weapon",
            "types" : ({ "long sword", "hand and a half sword", 
                "two-handed sword", "axe", "dagger", "short sword", 
                "hammer", "mace", "flail", "staff", "pole arm" }),
            "formula" : "additive",
            "rate" : 0.5
        ]),
        ([
            "type":"highest skill",
            "name" : "weapon skills",
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

    addSpecification("spell point cost", 15);
    addSpecification("spell point cost modifiers", ([
        "/guilds/bard/melee/rhythmic-riposte.c": 2,
        "/guilds/bard/melee/armsmans-form.c": 2,
        "/guilds/bard/melee/armsmans-breath.c": 3,
        "/guilds/bard/melee/minstrels-melee.c": 3
    ]));

    addSpecification("stamina point cost", 25);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/bard/melee/rhythmic-riposte.c": 5,
        "/guilds/bard/melee/armsmans-form.c": 5,
        "/guilds/bard/melee/armsmans-breath.c": 5,
        "/guilds/bard/melee/minstrels-melee.c": 5
    ]));

    addSpecification("cooldown", 30);
    addSpecification("cooldown modifiers", ([
        "/guilds/bard/melee/footmans-tune.c": 5,
        "/guilds/bard/melee/song-of-the-strong.c": 5,
        "/guilds/bard/melee/requiem-of-attack.c": 5,
        "/guilds/bard/melee/armsmasters-tale.c": 5,
    ]));

    addSpecification("event handler", "meleesMelodyEvent");
    addSpecification("command template", "melee's melody [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::point## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## and ##Infinitive::sing##, "
        "`Tis thy time, oh stranger... Tis thy time to die.'");
}
