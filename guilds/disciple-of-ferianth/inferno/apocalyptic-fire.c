//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Apocalyptic Fire");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "ultimate knowledge of Ferianth's inferno - the ability to unleash "
        "apocalyptic fire that burns with the intensity of a dying sun. "
        "This cataclysmic conflagration annihilates all enemies, scorching "
        "their bodies, minds, and souls while leaving the faithful standing "
        "in triumphant glory.");
    addSpecification("usage summary", "The ultimate apocalyptic conflagration");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/wrath-of-ferianth.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 67
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 400);

    addSpecification("damage hit points", ({ ([
            "probability": 25,
            "base damage": 500,
            "range": 650
        ]),
        ([
            "probability": 45,
            "base damage": 700,
            "range": 900
        ]),
        ([
            "probability": 30,
            "base damage": 950,
            "range": 1200
        ])
    }));

    addSpecification("damage spell points", ({ ([
            "probability": 100,
            "base damage": 100,
            "range": 150
        ])
    }));

    addSpecification("damage stamina points", ({ ([
            "probability": 100,
            "base damage": 80,
            "range": 120
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("penalty to resist fire", 50);
    addSpecification("penalty to resist magical", 35);
    addSpecification("penalty to resist physical", 25);
    addSpecification("penalty to attack", 15);
    addSpecification("penalty to defense", 15);
    addSpecification("penalty to strength", 6);
    addSpecification("penalty to constitution", 6);
    addSpecification("penalty to dexterity", 6);
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("duration", 90);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/fire-mastery.c",
            "name": "Fire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/inferno-potency.c",
            "name": "Inferno Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/divine-fire-potency.c",
            "name": "Divine Fire Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/pyromaniacs-focus.c",
            "name": "Pyromaniac's Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/righteous-fury.c",
            "name": "Righteous Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/flames-of-judgment.c",
            "name": "Flames of Judgment",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/sacred-champion.c",
            "name": "Sacred Champion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/sacred-immolation.c",
            "name": "Sacred Immolation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/blinding-glory.c",
            "name": "Blinding Glory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/essence-of-the-sun.c",
            "name": "Essence of the Sun",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/divine-judgment.c",
            "name": "Divine Judgment",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/avatar-of-flame.c",
            "name": "Avatar of Flame",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/harbinger-of-annihilation.c",
            "name": "Harbinger of Annihilation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.75
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.55
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 1.25
        ])
    }));

    addSpecification("cooldown", 300);
    addSpecification("event handler", "apocalypticFireEvent");
    addSpecification("command template", "apocalyptic fire");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## both hands to the heavens and "
        "##Infinitive::invoke## the apocalyptic fire of Ferianth! "
        "The sky tears asunder as flames with the intensity of a dying sun "
        "cascade down, consuming all enemies in a cataclysmic conflagration "
        "of divine wrath! The very air ignites as ##InitiatorName## "
        "##Infinitive::stand## triumphant amidst the inferno!");
}
