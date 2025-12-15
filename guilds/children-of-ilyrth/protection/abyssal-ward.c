//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Abyssal Ward");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to draw protection from the deepest abyss. The caster's "
        "shields become infused with the power of the ocean's darkest depths.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 21 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/tidal-resilience.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 3);
    addSpecification("bonus soak", 4);
    addSpecification("bonus resist magical", 3);

    addSpecification("affected research", ([
        "Aquatic Shield": 25,
        "Maelstrom Barrier": 25,
        "Ilyryth's Aegis": 20,
        "Sanctuary of Waves": 15
    ]));
    addSpecification("affected research type", "percentage");
}
