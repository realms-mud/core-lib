//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Refined Conduit");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of refining psychic conduits, improving delivery and "
        "connection-based projection methods.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 14 ]));

    addPrerequisite("/guilds/oneiromancer/projection-methods/enhanced-projection.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Empathic Bridge": 20,
        "Memory Anchor": 20,
        "Dream Thread": 15,
        "Gestured Sending": 15
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 2);
    addSpecification("bonus spellcraft", 1);
}
