//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sonic Disruptors");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical devices that produce devastating "
        "sound waves, shattering structures and disorienting enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 6);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 13]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("/lib/instances/research/vehicles/components/arcane-cannon.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 6);
    addSpecification("bonus crafting vehicle structure", 3);
}
