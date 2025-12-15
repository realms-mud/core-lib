//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wrath of the Deep");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wrath of the deep spell. The caster summons the "
        "crushing pressure of the ocean depths to devastate an enemy.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 19 ]));

    addPrerequisite("/guilds/children-of-ilyrth/offense/ocean-fury.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 40,
            "range": 80
        ]),
        ([
            "probability": 10,
            "base damage": 80,
            "range": 160
        ])
    }));
    addSpecification("damage type", "water");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/tidal-surge.c",
            "name": "Tidal Surge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/riptide.c",
            "name": "Riptide",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/crushing-depths.c",
            "name": "Crushing Depths",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/abyssal-pressure.c",
            "name": "Abyssal Pressure",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/oceans-wrath.c",
            "name": "Ocean's Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/cataclysmic-deluge.c",
            "name": "Cataclysmic Deluge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "divine essence",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
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
        ])
    }));

    addSpecification("cooldown", 18);
    addSpecification("event handler", "wrathOfTheDeepEvent");
    addSpecification("command template", "wrath of the deep [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::summon## the crushing pressure of the ocean depths "
        "as ##TargetName## ##TargetSubjective::is## crushed by an "
        "overwhelming force of water.");
}
