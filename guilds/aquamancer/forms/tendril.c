//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tendril Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form grasping tendrils of water "
        "to ensnare and damage foes.");

    addPrerequisite("/guilds/aquamancer/forms/droplet.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 5
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 14,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 6);
    addSpecification("additional spell point cost", 10);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::lash## ##TargetName## with tendrils of ##Function##.");
}
