//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wave Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that send a sweeping wave of water to strike foes.");

    addPrerequisite("/guilds/aquamancer/forms/mist.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 9
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 23,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 12);
    addSpecification("additional spell point cost", 20);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::send## a wave of ##Function## crashing into ##TargetName##.");
}
