//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Natures Renewal");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of nature's eternal cycle of renewal. Through Ilyrth's "
        "wisdom, the caster understands how water sustains all life.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 17 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/deep-restoration.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus healing", 3);
    addSpecification("bonus divine essence", 3);
    addSpecification("bonus heal hit points", 2);
    addSpecification("bonus heal spell points", 1);

    addSpecification("affected research", ([
        "Ocean Balm": 20,
        "Lifegiving Waters": 20,
        "Wellspring of Life": 20,
        "Ilyriths Blessing": 15
    ]));
    addSpecification("affected research type", "percentage");
}
