//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "content");
    addSpecification("description", "You are truly satisfied with your "
        "lot in life.");
    addSpecification("root", "content");
    addSpecification("opposing root", "ambitious");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
}
