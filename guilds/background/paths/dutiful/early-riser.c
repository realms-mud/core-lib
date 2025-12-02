//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Early Riser");
    addSpecification("source", "background");
    addSpecification("description",
        "You are always ready to start the day and meet your obligations.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stamina points", 2);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus heal stamina rate", 1);
}
