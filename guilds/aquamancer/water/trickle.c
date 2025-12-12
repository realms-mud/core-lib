//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Trickle");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the trickle spell. The aquamancer summons a gentle flow "
        "of restorative water that surrounds an ally, gradually mending wounds "
        "and refreshing the spirit. The water seems almost alive, seeking out "
        "injuries and soothing them with its cool touch.");

    addPrerequisite("/guilds/aquamancer/water/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
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

    addSpecification("cooldown", 60);
    addSpecification("event handler", "trickleEvent");
    addSpecification("command template", "trickle [at ##Target##]");
    addSpecification("use ability message", "A gentle stream of water swirls "
        "around ##TargetName##, soothing ##TargetPossessive## wounds.");
}
