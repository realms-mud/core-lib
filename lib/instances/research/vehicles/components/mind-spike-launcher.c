//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind Spike Launchers");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical devices that launch spikes "
        "infused with psychic energy, disrupting mental focus and causing "
        "disorientation in enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 7);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 14]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 6]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("/lib/instances/research/vehicles/components/confusion-projector.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting weapon class", 7);
    addSpecification("bonus crafting structure", 3);
}
