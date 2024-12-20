//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "gluttonous");
    addSpecification("description", "Oh, how you love partaking in the "
        "good things in life - to gross excess.");
    addSpecification("root", "crude");
    addSpecification("opposing root", "refined");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
}
