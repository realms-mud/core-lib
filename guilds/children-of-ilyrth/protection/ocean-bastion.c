//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ocean Bastion");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to become a bastion of oceanic power. The caster's "
        "protective abilities reach new heights of strength.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/abyssal-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 4);
    addSpecification("bonus soak", 5);
    addSpecification("bonus elemental water", 4);

    addSpecification("affected research", ([
        "Aquatic Shield": 25,
        "Tidal Barrier": 25,
        "Maelstrom Barrier": 25,
        "Ilyryth's Aegis": 25,
        "Sanctuary of Waves": 20
    ]));
    addSpecification("affected research type", "percentage");
}
