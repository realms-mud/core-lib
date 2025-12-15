//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Reef Armor");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to harden their protective barriers like coral reef. "
        "The caster's shields become more resistant to physical damage.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 7 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/tidal-barrier.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 2);
    addSpecification("bonus defense", 2);

    addSpecification("affected research", ([
        "Aquatic Shield": 15,
        "Tidal Barrier": 15,
        "Shell of the Deep": 15
    ]));
    addSpecification("affected research type", "percentage");
}
