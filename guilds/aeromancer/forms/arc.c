//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arc Form");
    addSpecification("source", "aeromancer"); 

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that send an arc of "
        "energy toward a foe.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 15,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 10);
    addSpecification("additional spell point cost", 15);

    addSpecification("use combination message", "##Infinitive::wave## "
        "##InitiatorPossessive## ##InitiatorWeapon## and magical energy arcs "
        "toward ##TargetName##");
}
