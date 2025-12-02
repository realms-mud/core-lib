//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Squinting Hew");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master hew - the squinting hew. This is a high "
        "horizontal hew dealt from the from-the-roof guard that ends in "
        "an upper hanger on the opposite side, typically targetting the "
        "head or right shoulder. This breaks the plough and the langort "
        "guards and is also a very effective counter to the over-hew.");
    
    addSpecification("limited by", (["equipment":({ "axe" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 20 ]));

    addPrerequisite("/guilds/scion/paths/axe/forms/striking.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/axe/forms/langort.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/axe/forms/over-hew.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/axe/forms/the-plough.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus axe", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus defense", 2);
}
