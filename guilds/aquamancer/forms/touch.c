//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Touch Form");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that target a foe by touch.");

    addPrerequisite("/guilds/aquamancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 5,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 2);
    addSpecification("additional spell point cost", 5);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::touch## ##TargetName## with ##Function##.");
}
