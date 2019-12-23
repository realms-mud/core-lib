//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "clubfooted");
        addSpecification("description", "You have lost part of your foot through a rather unfortunate accident.");
        addSpecification("root", "maimed");
        addSpecification("opposing root", "hale");
        addSpecification("opinion", -10);
        addSpecification("penalty to dexterity", 3);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}

