//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Engine");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical engines powered by bound "
        "elementals, providing tremendous propulsive force.");
    addSpecification("research type", "points");
    addSpecification("research cost", 12);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 20]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 15]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("engineering", (["type":"skill", "value" : 8]));
    addPrerequisite("/lib/instances/research/vehicles/components/elemental-binding.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle speed", 15);
    addSpecification("bonus crafting vehicle structure", 10);
}
