//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "ambitious");
    addSpecification("description", "You have a strong desire to achieve and succeed.");
    addSpecification("root", "self-motivated");
    addSpecification("opposing root", "lazy");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
}
