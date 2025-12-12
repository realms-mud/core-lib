//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maelstrom Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a churning maelstrom of "
        "devastating water energy.");

    addPrerequisite("/guilds/aquamancer/forms/whirlpool.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 19
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 42,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 28);
    addSpecification("additional spell point cost", 46);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::summon## a maelstrom of ##Function## that devastates ##TargetName##.");
}
