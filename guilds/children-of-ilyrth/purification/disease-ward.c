//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Disease Ward");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "protection against disease. The caster's body becomes resistant "
        "to illness and infection.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 11 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/cure-poison.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist disease", 8);
    addSpecification("bonus resist poison", 3);

    addSpecification("affected research", ([
        "Cure Poison": 15,
        "Cure Disease": 15
    ]));
    addSpecification("affected research type", "percentage");
}
