//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "disloyal");
    addSpecification("description", "You show a decided lack of devotion "
        "to others.");
    addSpecification("root", "disloyal");
    addSpecification("opposing root", "loyal");
    addSpecification("opinion", -15);
    addSpecification("opposing opinion", -15);
}
