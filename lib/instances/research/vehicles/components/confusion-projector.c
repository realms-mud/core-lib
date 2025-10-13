//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Confusion Projectors");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft magical devices that cause confusion "
        "and fear in enemies, disrupting their coordination and morale.");
    addSpecification("research type", "points");
    addSpecification("research cost", 6);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 12]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/vehicles/components/sonic-disruptor.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 5);
    addSpecification("bonus crafting vehicle protection", 2);
}
