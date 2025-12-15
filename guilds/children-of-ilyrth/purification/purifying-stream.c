//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Purifying Stream");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "power of the purifying stream. The caster's cleansing abilities "
        "flow with greater strength and efficiency.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 13 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/tidal-cleansing.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist poison", 5);
    addSpecification("bonus resist disease", 5);

    addSpecification("affected research", ([
        "Cleansing Waters": 20,
        "Cure Poison": 20,
        "Cure Disease": 15
    ]));
    addSpecification("affected research type", "percentage");
}
