//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nuath Dravn");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively hew with the edge of a sword "
        "from below the foe.");
    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 9 ]));

    addPrerequisite("guilds/aegis-guard/forms/sword-attacks/dravnu.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Dravo": 15
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus short sword", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus hand and a half sword", 1);
    addSpecification("bonus two-handed sword", 1);
    addSpecification("bonus damage", 2);
    addSpecification("equivalence", "under hew");
}
