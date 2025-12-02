//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hidden in Plain Sight");
    addSpecification("source", "background");
    addSpecification("description",
        "You can blend into any crowd and avoid unwanted attention.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus disguise", 1);
    addSpecification("bonus etiquette", 1);
    addSpecification("bonus wisdom", 1);
}
