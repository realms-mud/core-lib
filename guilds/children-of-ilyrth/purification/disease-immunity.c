//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Disease Immunity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with near "
        "immunity to disease. The caster's body is so thoroughly blessed "
        "that illness cannot take hold.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 21 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/cure-disease.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist disease", 15);

    addSpecification("affected research", ([
        "Cure Disease": 25,
        "Remove Paralysis": 20
    ]));
    addSpecification("affected research type", "percentage");
}
