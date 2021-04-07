//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "determined");
    addSpecification("description", "You have a strong resolve to achieve "
        "and succeed.");
    addSpecification("root", "self-motivated");
    addSpecification("opposing root", "lazy");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
}
