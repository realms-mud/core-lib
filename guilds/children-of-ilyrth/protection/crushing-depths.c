//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crushing Depths");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "power of the crushing ocean depths. Attackers feel the immense "
        "pressure when striking the caster's barriers.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 17 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/depths-embrace.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 3);
    addSpecification("bonus defense", 2);

    addSpecification("affected research", ([
        "Maelstrom Barrier": 20,
        "Sanctuary of Waves": 20,
        "Divine Bulwark": 15
    ]));
    addSpecification("affected research type", "percentage");
}
