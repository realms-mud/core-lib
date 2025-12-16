//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soothing Touch");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the soothing touch spell. By calling upon Ilyrth's "
        "grace, the caster channels healing waters through their hands to "
        "mend minor wounds.");

    addPrerequisite("/guilds/children-of-ilyrth/healing/root.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 10,
            "range": 10
        ]),
        ([
            "probability": 20,
            "base damage": 20,
            "range": 10
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/waters-embrace.c",
            "name": "Waters Embrace",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/mending-waters.c",
            "name": "Mending Waters",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/restorative-torrent.c",
            "name": "Restorative Torrent",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/ocean-surge.c",
            "name": "Ocean Surge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/tidal-mastery.c",
            "name": "Tidal Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/divine-waters.c",
            "name": "Divine Waters",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/healing-maelstrom.c",
            "name": "Healing Maelstrom",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/oceans-heart.c",
            "name": "Oceans Heart",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/healing/divine-tides.c",
            "name": "Divine Tides",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]), 
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.025
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 4);
    addSpecification("event handler", "soothingTouchEvent");
    addSpecification("command template", "soothing touch [at ##Target##]");
    addSpecification("use ability message", "Gentle blue light flows from "
        "##InitiatorPossessive::Name## hands as ##InitiatorSubjective## "
        "##Infinitive::channel## Ilyrth's healing waters into ##TargetName##.");
}
