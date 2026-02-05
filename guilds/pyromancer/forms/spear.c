//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spear Form");
    addSpecification("source", "pyromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form spears of fire.");

    addPrerequisite("/guilds/pyromancer/forms/blade.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "pyromancer",
            "value": 7
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 22,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 10);
    addSpecification("additional spell point cost", 18);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::impale## ##TargetName## with a spear of ##Function##.");
}
