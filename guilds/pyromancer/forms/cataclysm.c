//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cataclysm Form");
    addSpecification("source", "pyromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that unleash cataclysms of fire.");

    addPrerequisite("/guilds/pyromancer/forms/strike.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "pyromancer",
            "value": 21
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 46,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 22);
    addSpecification("additional spell point cost", 44);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::unleash## a cataclysm of ##Function## upon ##TargetName##.");
}
