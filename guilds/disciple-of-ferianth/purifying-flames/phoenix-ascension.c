//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Phoenix Ascension");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling the phoenix's ascension, providing "
        "powerful healing and temporary protection.");
    addSpecification("usage summary", "Major heal with strong protection");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/divine-absolution.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 55
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("spell point cost", 150);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 130,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 230,
            "range": 100
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 45,
            "range": 35
        ]),
        ([
            "probability": 20,
            "base damage": 80,
            "range": 35
        ])
    }));

    addSpecification("bonus defense", 15);
    addSpecification("bonus resist physical", 10);
    addSpecification("bonus resist magical", 10);
    addSpecification("duration", 30);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c",
            "name": "Divine Healing Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/restorative-focus.c",
            "name": "Restorative Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/empowered-restoration.c",
            "name": "Empowered Restoration",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/divine-restoration.c",
            "name": "Divine Restoration",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/master-healer.c",
            "name": "Master Healer",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.40
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.40
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.18
        ])
    }));

    addSpecification("cooldown", 240);
    addSpecification("event handler", "phoenixAscensionEvent");
    addSpecification("command template", "phoenix ascension [on ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## the phoenix ascension upon ##TargetName##! "
        "##TargetSubjective## ##TargetAuxVerb::be## engulfed in divine fire, "
        "rising renewed and protected.");
}
