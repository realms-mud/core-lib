//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Efficient Worker");
    addSpecification("source", "background");
    addSpecification("description",
        "You complete tasks quickly and with minimal wasted effort.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stamina points", 2);
    addSpecification("bonus heal stamina rate", 1);
    addSpecification("bonus to intoxicated", 5);
}
