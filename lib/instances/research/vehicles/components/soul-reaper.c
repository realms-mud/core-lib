//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul Reapers");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft dark magical devices that drain life "
        "force from enemies, a forbidden art of necromantic warfare.");
    addSpecification("research type", "points");
    addSpecification("research cost", 10);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 16]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/lightning-cannon.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting weapon class", 12);
    addSpecification("bonus crafting structure", 6);
    addSpecification("bonus crafting protection", 4);
}
