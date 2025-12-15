//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Paralysis Ward");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "protection against paralysis. The flowing nature of water resists "
        "all attempts to freeze or bind the caster's movements.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 17 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/cure-disease.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist paralysis", 8);
    addSpecification("bonus resist disease", 3);

    addSpecification("affected research", ([
        "Cure Disease": 20,
        "Remove Paralysis": 15
    ]));
    addSpecification("affected research type", "percentage");
}
