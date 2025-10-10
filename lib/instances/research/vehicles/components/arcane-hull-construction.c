//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Hull Construction");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft hulls reinforced with magical runes "
        "and rare materials for enhanced durability and mystical protection.");
    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addPrerequisite("carpentry", (["type":"skill", "value" : 6]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 4]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 8]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/components/reinforced-hull-construction.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting structure", 12);
    addSpecification("bonus crafting protection", 6);
}
