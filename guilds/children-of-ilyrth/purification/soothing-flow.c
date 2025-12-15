//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soothing Flow");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of water's soothing flow. The caster's purification "
        "spells become more gentle yet effective.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 9 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/waters-purity.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist disease", 3);
    addSpecification("bonus heal hit points rate", 1);

    addSpecification("affected research", ([
        "Cleansing Waters": 15,
        "Cure Poison": 15
    ]));
    addSpecification("affected research type", "percentage");
}
