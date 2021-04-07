//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addPrerequisite("long sword", (["type":"skill", "value" : 10]));
    addSpecification("name", "Points research");
    addSpecification("description", "This is a description");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus strength", 2);
    addSpecification("bonus long sword", 5);
    addSpecification("bonus fire attack", 15);
    addSpecification("bonus weapon attack", 1);
}
