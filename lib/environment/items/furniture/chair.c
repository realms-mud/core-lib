//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("chair");
    addAlias("seat");
    addAlias("stool");
    addAlias("wooden chair");

    addAdjectives(({ "simple", "wooden", "sturdy", "plain", "carved",
        "old", "creaky", "straight-backed", "worn", "functional" }));

    addDescriptionTemplate("a ##Adjective## chair set near the table");

    addItemTemplate("This chair is constructed from sturdy wood, its straight back and "
        "simple design suggesting it was made for everyday use. The seat is slightly "
        "worn from years of service, and faint carvings decorate the legs and backrest.");

    addSomeLightDescriptionTemplate("a wooden chair stands by the table, its surface "
        "showing the marks of long use");

    addDimLightDescriptionTemplate("a sturdy chair is visible in the gloom, its outline "
        "plain but serviceable");

    addLowLightDescriptionTemplate("a faint shape of a chair can be made out near the "
        "table, little more than a shadow");

    addNearDarkDescriptionTemplate("a vague shadow suggests a chair is present, but "
        "details are lost in the darkness");
}
