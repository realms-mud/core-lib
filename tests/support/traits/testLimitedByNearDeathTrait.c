//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    addSpecification("type", "role");
    addSpecification("name", "Sword Boy");
    addSpecification("description", "blah blah blah");
    addSpecification("bonus strength", 2);
    addSpecification("bonus long sword", 1);
    addSpecification("limited by", (["near death":20]));
    addSpecification("bonus weapon attack", 1);
    addSpecification("root", "jock");
    addSpecification("opposing root", "nerd");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    addSpecification("cost", 8);
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}

