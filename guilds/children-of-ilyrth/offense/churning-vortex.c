//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Churning Vortex");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the churning vortex spell. The caster creates a devastating "
        "whirlpool of sacred water that tears apart all enemies in the area.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/offense/crushing-depths.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 45,
            "range": 90
        ]),
        ([
            "probability": 10,
            "base damage": 90,
            "range": 180
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

    addSpecification("cooldown", 75);
    addSpecification("event handler", "churningVortexEvent");
    addSpecification("command template", "churning vortex");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## a devastating vortex of sacred water that "
        "tears through the area, dragging all enemies into its churning depths.");
}
