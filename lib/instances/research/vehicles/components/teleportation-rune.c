//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Teleportation Rune");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft runes that allow vehicles to teleport "
        "short distances through dimensional magic.");
    addSpecification("research type", "points");
    addSpecification("research cost", 10);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 18]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 12]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("/lib/instances/research/vehicles/components/levitation-matrix.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting speed", 12);
    addSpecification("bonus crafting structure", 8);
}
