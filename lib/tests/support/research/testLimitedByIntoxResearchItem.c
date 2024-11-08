//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "intox research");
    addSpecification("description", "This is a description");
    addSpecification("source", "mage guild");
    addSpecification("scope", "self");
    addSpecification("research type", "granted");
    addSpecification("limited by", (["intoxicated":1]));
    addSpecification("bonus strength", 2);
    addSpecification("penalty to long sword", 2);
    addSpecification("bonus fire attack", 15);
    addSpecification("bonus weapon attack", 2);
}
