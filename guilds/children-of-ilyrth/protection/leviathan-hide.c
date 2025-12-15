//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Leviathan Hide");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with hide "
        "as tough as the legendary leviathans of the deep. The caster's "
        "body becomes nearly impervious to physical harm.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 41 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/trench-armor.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 6);
    addSpecification("bonus soak", 8);
    addSpecification("bonus resist physical", 8);

    addSpecification("affected research", ([
        "Aquatic Shield": 25,
        "Tidal Barrier": 25,
        "Tsunami Shield": 25,
        "Ilyryth's Sanctuary": 20
    ]));
    addSpecification("affected research type", "percentage");
}
