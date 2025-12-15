//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilryth's Embrace");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of Ilyrth's embrace - the ultimate healing spell. The "
        "goddess herself reaches out to embrace all wounded allies, "
        "restoring them completely with her divine love.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 67 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/divine-tides.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 400);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 175,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 275,
            "range": 100
        ])
    }));

    addSpecification("increase spell points", ({ ([
            "probability": 80,
            "base damage": 80,
            "range": 60
        ]),
        ([
            "probability": 20,
            "base damage": 140,
            "range": 60
        ])
    }));

    addSpecification("increase stamina points", ({ ([
            "probability": 80,
            "base damage": 65,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 115,
            "range": 50
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.50
        ]),
        ([
            "type": "skill",
            "name": "divine essence",
            "formula": "logarithmic",
            "rate": 1.60
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.25
        ])
    }));

    addSpecification("cooldown", 300);
    addSpecification("event handler", "Ilryth'sEmbraceEvent");
    addSpecification("command template", "Ilryth's embrace");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon the goddess Ilyrth herself as a "
        "shimmering manifestation of the sea goddess appears, her ethereal "
        "arms reaching out to embrace all nearby in waves of pure divine "
        "healing light.");
}
