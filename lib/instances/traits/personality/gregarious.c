//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "gregarious");
    addSpecification("description", "People like you. You are congenial "
        "and everyone tends to gravitate toward you and your incredible "
        "charisma.");
    addSpecification("bonus charisma", 1);
    addSpecification("root", "extravert");
    addSpecification("opposing root", "introvert");
    addSpecification("opinion", 1);
    addSpecification("opposing opinion", -1);
    addSpecification("bonus persuasion", 2);
}
