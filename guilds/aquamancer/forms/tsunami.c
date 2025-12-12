//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tsunami Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that unleash a massive tsunami of "
        "overwhelming water energy.");

    addPrerequisite("/guilds/aquamancer/forms/strike.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 21
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 44,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 30);
    addSpecification("additional spell point cost", 50);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::unleash## a massive tsunami of "
        "##Function## upon ##TargetName##.");
}
