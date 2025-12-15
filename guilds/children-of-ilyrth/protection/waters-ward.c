//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Waters Ward");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to strengthen their protective barriers. The ward of "
        "Ilyrth's waters becomes more resilient against attacks.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 3 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/aquatic-shield.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus elemental water", 2);

    addSpecification("affected research", ([
        "Aquatic Shield": 15
    ]));
    addSpecification("affected research type", "percentage");
}
