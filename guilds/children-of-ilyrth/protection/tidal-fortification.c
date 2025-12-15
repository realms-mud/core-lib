//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Fortification");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to fortify their body and spirit with tidal energy. "
        "The caster becomes incredibly resilient against all attacks.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/sea-hardened.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 30);
    addSpecification("bonus resist physical", 5);
    addSpecification("bonus resist magical", 5);

    addSpecification("affected research", ([
        "Shell of the Deep": 25,
        "Maelstrom Barrier": 25,
        "Ilyryth's Aegis": 25,
        "Sanctuary of Waves": 20
    ]));
    addSpecification("affected research type", "percentage");
}
