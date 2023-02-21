//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "introvert");
    addSpecification("description", "You prefer to concern yourself "
        "with your own thoughts and feelings over gaining external "
        "stimuli from others.");
    addSpecification("root", "introvert");
    addSpecification("opposing root", "extravert");
    addSpecification("opinion", 1);
    addSpecification("opposing opinion", -1);
}
