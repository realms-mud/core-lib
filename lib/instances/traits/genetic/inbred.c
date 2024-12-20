//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "inbred");
    addSpecification("description", "Your family tree is more of a pole. Through "
        "lack of diversity, your a bit sickly, lack intelligence, and are rather "
        "unattractive.");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -10);
    addSpecification("penalty to intelligence", 2);
    addSpecification("penalty to constitution", 2);
    addSpecification("penalty to charisma", 2);
    addSpecification("penalty to persuasion", 5);
    addSpecification("cost", -2);
}
