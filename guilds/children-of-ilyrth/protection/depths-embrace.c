//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Depths Embrace");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "embrace of the ocean depths. The caster becomes comfortable in the "
        "crushing pressure, granting enhanced protection.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 13 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/wave-wall.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 3);
    addSpecification("bonus resist physical", 3);

    addSpecification("affected research", ([
        "Tidal Barrier": 20,
        "Maelstrom Barrier": 20,
        "Sanctuary of Waves": 15
    ]));
    addSpecification("affected research type", "percentage");
}   
