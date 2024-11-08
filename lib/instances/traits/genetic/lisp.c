//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "lisp");
    addSpecification("description", "You have a lithp and thith maykth it thumwhat difficult "
        "to underthtand you. (and yes, your ability to speak in game will reflect this.)");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -10);
    addSpecification("penalty to charisma", 1);
    addSpecification("penalty to persuasion", 3);
    addSpecification("cost", -1);
}
