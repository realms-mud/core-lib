//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mend");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mend spell. The geomancer draws upon the regenerative "
        "power of the earth to surround an ally with restorative mineral essence, "
        "gradually mending wounds and fortifying the body. The earthy energy "
        "seems almost alive, seeking out injuries and strengthening them.");

    addPrerequisite("/guilds/geomancer/earth/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 3
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus defense", 2);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "elemental earth",
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

    addSpecification("cooldown", 60);
    addSpecification("event handler", "mendEvent");
    addSpecification("command template", "mend [at ##Target##]");
    addSpecification("use ability message", "Earthy mineral essence swirls "
        "around ##TargetName##, mending ##TargetPossessive## wounds.");
}
