//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "master stonemason");
    addSpecification("description", "You are a master stonemason");
    addSpecification("root", "stonemason");
    addSpecification("opinion", 5);
    addSpecification("bonus stonemasonry", 25);
    addSpecification("bonus engineering", 5);
}
