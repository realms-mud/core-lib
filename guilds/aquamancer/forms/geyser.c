//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Geyser Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that erupt as a violent geyser of water "
        "beneath the target.");

    addPrerequisite("/guilds/aquamancer/forms/orb.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 15
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 34,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 20);
    addSpecification("additional spell point cost", 35);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::erupt## a geyser of ##Function## beneath ##TargetName##.");
}
