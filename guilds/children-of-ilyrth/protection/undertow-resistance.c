//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Undertow Resistance");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to resist being moved or controlled. Like the undertow "
        "that cannot be pushed back, the caster becomes immovable.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 11 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/pressure-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist physical", 3);
    addSpecification("bonus resist magical", 3);

    addSpecification("affected research", ([
        "Tidal Barrier": 15,
        "Shell of the Deep": 15,
        "Maelstrom Barrier": 20
    ]));
    addSpecification("affected research type", "percentage");
}
