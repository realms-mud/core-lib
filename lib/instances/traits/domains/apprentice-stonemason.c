//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "apprentice stonemason");
    addSpecification("description", "You have just begun learning about stonemasonry");
    addSpecification("root", "stonemason");
    addSpecification("opinion", 1);
    addSpecification("bonus stonemasonry", 2);
}
