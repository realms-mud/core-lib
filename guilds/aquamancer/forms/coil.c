//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Coil Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form constricting coils of water "
        "that crush and drown foes.");

    addPrerequisite("/guilds/aquamancer/forms/cage.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 17
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 35,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 20);
    addSpecification("additional spell point cost", 36);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::constrict## ##TargetName## with coils of ##Function##.");
}
