//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Vehicle Combat");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to integrate magical combat techniques with "
        "vehicle warfare, including spell targeting and arcane defenses.");
    addSpecification("research type", "points");
    addSpecification("research cost", 5);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 8]));
    addPrerequisite("tactics", (["type":"skill", "value" : 6]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/combat/basic-vehicle-tactics.c", 
        (["type":"research"]));

    addSpecification("bonus magical enchantment", 3);
    addSpecification("bonus resist magical", 2);
    addSpecification("bonus spellcraft", 2);
}
