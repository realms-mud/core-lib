//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    addSpecification("type", "personality");
    addSpecification("name", "thespian");
    addSpecification("description", "");
    addSpecification("root", "archetype");

    "baseTrait"::reset(arg);
}

