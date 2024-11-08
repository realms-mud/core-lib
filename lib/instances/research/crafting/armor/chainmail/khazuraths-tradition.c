//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Khazurath's Tradition");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "techniques mastered by the great smiths of Khazurath.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/chainmail/maeliths-legacy.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 37]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 30]));

    addSpecification("limited by", (["crafting type":"chainmail"]));

    addSpecification("bonus crafting value multiplier", 30);
    addSpecification("bonus crafting encumberance reduction", 10);
    addSpecification("bonus crafting armor class", 1);
    addSpecification("bonus blacksmithing", 3);
    addSpecification("bonus metal crafting", 3);
    addSpecification("bonus armorer", 3);
}
