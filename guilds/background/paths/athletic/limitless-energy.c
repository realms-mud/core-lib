//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Limitless Energy");
    addSpecification("source", "background");
    addSpecification("description",
        "You seem to possess boundless reserves of energy, rarely tiring no "
        "matter how long the challenge.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stamina points", 5);
    addSpecification("bonus heal stamina rate", 1);
    addSpecification("bonus constitution", 1);
}
