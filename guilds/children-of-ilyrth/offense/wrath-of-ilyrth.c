//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wrath of Ilyrth");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wrath of Ilyrth spell. The caster becomes a direct "
        "conduit for the goddess's fury, devastating enemies with waves of "
        "divine power that crash upon them repeatedly.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 45 ]));

    addPrerequisite("/guilds/children-of-ilyrth/offense/divine-inundation.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 270);
    addSpecification("repeat effect", 3);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 100,
            "range": 150
        ]),
        ([
            "probability": 15,
            "base damage": 150,
            "range": 175
        ]),
        ([
            "probability": 5,
            "base damage": 200,
            "range": 275
        ])
    }));
    addSpecification("damage type", "good");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/holy-deluge.c",
            "name": "Holy Deluge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/sacred-flood.c",
            "name": "Sacred Flood",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/divine-retribution.c",
            "name": "Divine Retribution",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/divine-inundation.c",
            "name": "Divine Inundation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/apocalyptic-tide.c",
            "name": "Apocalyptic Tide",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "divine essence",
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
            "name": "elemental water",
            "formula": "logarithmic",
            "rate": 1.15
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

    addSpecification("cooldown", 120);
    addSpecification("event handler", "wrathOfIlyrthEvent");
    addSpecification("command template", "wrath of ilyrth");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::become## a conduit for Ilyrth's divine fury as "
        "radiant waters crash down upon all enemies, searing them with "
        "the goddess's righteous wrath.");
}
