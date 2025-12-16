//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sacred Cleansing");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of sacred cleansing. The caster's purification magic "
        "is blessed by Ilyrth herself.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 17 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/purifying-stream.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus magical essence", 4);
    addSpecification("bonus elemental water", 3);

    addSpecification("affected research", ([
        "Cleansing Waters": 25,
        "Cure Poison": 20,
        "Cure Disease": 20,
        "Remove Paralysis": 15
    ]));
    addSpecification("affected research type", "percentage");
}
