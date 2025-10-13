//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Acid Sprayers");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical devices that spray corrosive "
        "acid at targets, dissolving armor and flesh alike.");
    addSpecification("research type", "points");
    addSpecification("research cost", 5);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 11]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("alchemy", (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-wagon-frame.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 5);
    addSpecification("bonus crafting vehicle structure", 2);
}
