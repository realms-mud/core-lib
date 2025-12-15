//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oceanic Immortality");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "immortal resilience of the ocean itself. Like the sea that cannot "
        "be destroyed, the caster becomes nearly unkillable.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 51 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/leviathan-hide.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 50);
    addSpecification("bonus defense", 8);
    addSpecification("bonus soak", 10);

    addSpecification("affected research", ([
        "Shell of the Deep": 25,
        "Tsunami Shield": 25,
        "Ilyryth's Sanctuary": 25,
        "Mantle of Ilyrth": 20
    ]));
    addSpecification("affected research type", "percentage");
}
