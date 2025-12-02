//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Cannons");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft powerful magical artillery pieces "
        "that fire concentrated bolts of arcane energy.");
    addSpecification("research type", "points");
    addSpecification("research cost", 6);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 12]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("engineering", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/magic-missile-launcher.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 8);
    addSpecification("bonus crafting vehicle structure", 4);
}
