//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Planar Rudder");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft rudders that allow vessels to shift "
        "between planes of existence, enabling interdimensional travel.");
    addSpecification("research type", "points");
    addSpecification("research cost", 15);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 22]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 18]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 12]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("/lib/instances/research/vehicles/components/teleportation-rune.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship" })]));
    addSpecification("bonus crafting vehicle speed", 20);
    addSpecification("bonus crafting vehicle structure", 15);
    addSpecification("bonus crafting vehicle protection", 10);
}
