//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cage Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a constricting cage of water "
        "around a foe.");

    addPrerequisite("/guilds/aquamancer/forms/ring.c",
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
        "Constructed Spell Multiplier": 28,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 15);
    addSpecification("additional spell point cost", 26);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::trap## ##TargetName## in a cage of ##Function##.");
}
