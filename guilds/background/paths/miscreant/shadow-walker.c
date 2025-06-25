//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Walker");
    addSpecification("source", "background");
    addSpecification("description",
        "You move quietly and blend into the shadows with ease.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stealth", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus heal stamina rate", 1);
}
