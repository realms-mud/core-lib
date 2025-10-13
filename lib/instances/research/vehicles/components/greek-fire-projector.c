//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Greek Fire Projectors");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft systems for projecting burning liquid "
        "fire at enemy vessels, a fearsome naval weapon.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("engineering", (["type":"skill", "value" : 5]));
    addPrerequisite("alchemy", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/oil-dispenser.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 6);
}
