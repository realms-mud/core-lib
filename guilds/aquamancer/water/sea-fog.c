//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sea Fog");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the sea fog spell. The aquamancer conjures a thick, "
        "rolling fog reminiscent of coastal mornings that blankets a target. "
        "The dense moisture clings to everything, severely hampering vision "
        "and making precise movements difficult.");

    addPrerequisite("/guilds/aquamancer/water/obscuring-spray.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);

    addSpecification("penalty to attack", 8);
    addSpecification("penalty to defense", 5);
    addSpecification("penalty to dexterity", 2);
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

    addSpecification("cooldown", 45);
    addSpecification("event handler", "seaFogEvent");
    addSpecification("command template", "sea fog [at ##Target##]");
    addSpecification("use ability message", "A thick, rolling sea fog "
        "engulfs ##TargetName##, obscuring ##TargetPossessive## senses.");
}
