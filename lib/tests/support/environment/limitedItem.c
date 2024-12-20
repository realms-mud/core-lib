//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("limited item");
    addDescriptionTemplate("a limited item");
    addItemTemplate("a nifty limited item");
    limitDisplayByResearchThatIsActive(
        "/lib/tests/support/research/testSustainedTraitResearch.c");
    limitDisplayBySkill("spot", 5);
    limitDisplayByEquipment("axe");
    limitDisplayBySeason("autumn");

    harvestableResource("mana", 5, "/lib/instances/items/potions/mana.c",
        "blah blah blah");

    addBonus("strength", 4);
}
