//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lance Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a massive lance of pressurized "
        "water capable of devastating penetration.");

    addPrerequisite("/guilds/aquamancer/forms/spear.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 13
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 32,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 18);
    addSpecification("additional spell point cost", 30);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::drive## a lance of ##Function## through ##TargetName##.");
}
