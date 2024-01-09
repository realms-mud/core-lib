//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lanna Dravn");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master hew - the thwart hew. This is a high "
        "horizontal hew with the backhand edge from the right and then the "
        "main edge from the left. This breaks the from-the-roof guard.");

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 17 ]));

    addPrerequisite("/guilds/aegis-guard/forms/sword-attacks/thar-dravn.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Dravo": 15,
        "Naetho": 15
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
    addSpecification("bonus attack", 2);
    addSpecification("equivalence", "thwart hew");
}
