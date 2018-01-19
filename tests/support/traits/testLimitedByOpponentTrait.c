//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "role");
        addSpecification("name", "Weasel");
        addSpecification("description", "blah blah blah");
        addSpecification("bonus long sword", 1);
        addSpecification("bonus strength", 2);
        addSpecification("bonus weapon attack", 1);
        addSpecification("limited by", (["opponent race":"dwarf"]));
        addSpecification("root", "nerd");
        addSpecification("opposing root", "jock");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -5);
        addSpecification("cost", 8);
        "baseTrait"::reset(arg);
    }
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}

