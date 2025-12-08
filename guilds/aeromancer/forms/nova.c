//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nova Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that release an explosive burst of energy "
        "radiating outward from the caster in all directions.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 38,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 26);
    addSpecification("additional spell point cost", 45);

    addSpecification("use combination message", 
        "##Infinitive::explode## with a nova of ##Function## that engulfs ##TargetName##");
}
