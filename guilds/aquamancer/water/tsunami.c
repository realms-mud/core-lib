//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tsunami");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the tsunami spell. The aquamancer gathers an enormous "
        "volume of superheated water and releases it as a devastating wave "
        "that crashes over all enemies. The scalding water burns and batters "
        "everything in its path.");

    addPrerequisite("/guilds/aquamancer/water/boiling-focus.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 15
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 85);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 30,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 80
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/boiling-focus.c",
            "name": "Boiling Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/steamweaving.c",
            "name": "Steamweaving",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/boiling-convergence.c",
            "name": "Boiling Convergence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name": "staff",
            "types": ({ "staff" }),
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
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
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 35);
    addSpecification("event handler", "tsunamiEvent");
    addSpecification("command template", "tsunami");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a massive wave of scalding water that "
        "crashes over all nearby enemies.");
}
