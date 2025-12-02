//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("source", "mage guild");
    addSpecification("description", "This is a description");
    addSpecification("name", "turnip seclusion");
    addSpecification("scope", "self");
    addSpecification("research type", "timed");
    addSpecification("research cost", 20);
    addSpecification("bonus long sword", 2);
}
