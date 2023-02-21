//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Kheled's Fury");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "amazing techniques mastered by the great dwarven smith Kheled.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/chainmail/kheleds-legacy.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 35]));

    addSpecification("limited by", (["crafting type":"chainmail"]));

    addSpecification("bonus crafting value multiplier", 30);
    addSpecification("bonus crafting armor class", 1);
}
